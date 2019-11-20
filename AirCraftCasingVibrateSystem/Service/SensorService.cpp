#include "stdafx.h"
#include "SensorService.h"
#include "FileUtil.h"
#include "CommonUtil.h"
#include "DateUtil.h"
#include "AirCraftCasingVibrateSystem.h"
#include "Constant.h"
CSensorService::CSensorService()
{
	//m_signalBuff.CreateBuffer(102400);
}

CSensorService::CSensorService(int nsignalBuff)
{
	//m_signalBuff.CreateBuffer(nsignalBuff);
}


CSensorService::~CSensorService()
{

}

HANDLE CSensorService::m_hMsqlMutex = CreateMutex(NULL, FALSE, NULL);

/*�������*/
void CSensorService::RandArray(double* ptr, size_t length)
{
	for (size_t i = 0; i<length; ++i)
	{
		ptr[i] = randf(-1, 1);
	}
}
/*���*/
double CSensorService::randf(double min, double max)
{
	int minInteger = (int)(min * 10000);
	int maxInteger = (int)(max * 10000);
	int randInteger = rand()*rand();
	int diffInteger = maxInteger - minInteger;
	int resultInteger = randInteger % diffInteger + minInteger;
	return resultInteger / 10000.0;
}

Result CSensorService::AddCollectData(TbSignal &signal, ThreadSafeQueue<AcquiredSignal> &collectionData){
	///1.ƴװ����·��
	CString path = "C:/collectionData/";
	//CString escapePath = "C:\\\\collectionData\\\\";

	//2.ƴװ�ļ��� ��Ŀid_�����豸id_������id_��Ʒid_ʱ���
	CString fileName = CommonUtil::Int2CString(signal.GetProjectId()) + "-"
		+ CommonUtil::Int2CString(signal.GetTestingDeviceId())
		//+ "-" + signal.GetChannels() + "-" + CommonUtil::Int2CString(signal.GetProductId())
		+ "-" + DateUtil::GetTimeStampCString()
		+ ".csv";

	CString startCollectTime = collectionData.front().GetAcquireTime();
	
	Result res;
	/*����������ӵ�Զ�̷������������ݵ�Զ�̣����򱣴浽����*/
	if ((strcmp(theApp.PDsql.m_mysql.host, "127.0.0.1") == 0) || (strcmp(theApp.PDsql.m_mysql.host, "localhost") == 0))
	{
		//����FileUtil�����ļ�������ɹ����زɼ��Ľ���ʱ��
		res = CFileUtil::SaveCollectionData(path, fileName, collectionData);

		if (res.GetIsSuccess()){
		///�ļ�����ɹ�������¼���浽���ݿ�
		signal.SetDataUrl(path + fileName);
		/*signal.SetStartTime(startCollectTime);
		signal.SetEndTime(res.GetMessages());*/
		signal.SetSaveTime(startCollectTime);

		//signal.GetTestingDevice().SetTestingdeviceId(project.GetTestingDevicePara().GetTestingdevice().GetId());
		m_signalDao.SetTableFieldValues(signal);

		/*�������ݿ�������ֹ���߳�*/
		WaitForSingleObject(m_hMsqlMutex, INFINITE);
		m_signalDao.Insert(false);
		ReleaseMutex(m_hMsqlMutex);
		}
	}
	else
	{
		CString separator = ",";////���ŷָ���
		CString endTime;
		CString allData = "";
		int saveCount = collectionData.size();
		for (int i = 0; i < saveCount; i++){
			////ѭ���ɼ����ݵĶ���ȥ��������
			CString data = "";
			shared_ptr<AcquiredSignal>	acquireSignal = collectionData.wait_and_pop();
			data += acquireSignal->GetAcquireTime() + separator;
			data += CommonUtil::DoubleOrFloat2CString(acquireSignal->GetSignalData()) + "\n";
			if (i == saveCount - 1) endTime = acquireSignal->GetAcquireTime();
			allData = allData + data;
		}

		// ������������Ϸ�������������
		httplib::MultipartFormDataItems items = {
			{ "data", allData.GetBuffer(), "1.txt", "text/plain" },//����
			{ "projectID", CommonUtil::Int2CString(signal.GetProductId()).GetBuffer(), "", "" },
			//{ "checkDeviceID", CommonUtil::Int2CString(project.GetTestingDevicePara().GetTestingdevice().GetId()).GetBuffer(), "", "" },
			//{ "sensorID", signal.GetChannels().GetBuffer(), "", "" },
			{ "startTime", startCollectTime.GetBuffer(), "", "" },
			{ "endTime", endTime.GetBuffer(), "", "" },
			{ "productID", CommonUtil::Int2CString(signal.GetProductId()).GetBuffer(), "", "" },
		};
		auto result = theApp.m_cli.Post("/collection", items);
		if (!result)//���û�з��ͳɹ��������·���
		{
			httplib::Client cli(_T(ServerHttpAddress), ServerHttpPort);
			theApp.m_cli = cli;
			auto result = theApp.m_cli.Post("/collection", items);
		}
	}
	return res;
}

bool  CSensorService::GetAllSensorByTestingDeviceId(int testingDeviceId, vector<TbSensor>& sensorVector){
	vector<TbSensorDao> sensorDaoVec;
	bool isSuccess = m_sensorDao.SelectObjectsByCondition(sensorDaoVec, "testingdevice_id='" + CommonUtil::Int2CString(testingDeviceId) + "'");
	if (isSuccess){
		///��ѯ�ɹ�֮��
		for (auto sensorDao : sensorDaoVec){
			TbSensor tbSensor;
			sensorDao.GetTableFieldValues(tbSensor);
			sensorVector.push_back(tbSensor);
		}
	}
	return isSuccess;
}



////������Ŀid�õ����еĴ���������
bool CSensorService::GetALLSensorByTestingdeviceId(int testingdeviceId, std::vector<TbSensor> &vsensorPara){
	m_sensorDao.m_testingdeviceId.SetValue(testingdeviceId);
	vector<TbSensorDao> selectedValueVector;
	m_sensorDao.SelectObjectsByCondition(selectedValueVector, "testingdevice_id='" + CommonUtil::Int2CString(testingdeviceId) + "'");
	if (!selectedValueVector.empty()){
		////������������Ϊ��ʱ
		for (auto tbsenorParaDao : selectedValueVector){
			////���ݲ�ѯ���Ĵ�����������װTbSensor����
			TbSensor sensorPara;
			tbsenorParaDao.GetTableFieldValues(sensorPara);
			////���ݴ��������������idȥ���ֵ����Ӧ���ֵ�ֵ

			TbDictionaryDao  dictionaryDao;
			dictionaryDao.SelectByObject(sensorPara.GetWindowType());
			dictionaryDao.SelectByObject(sensorPara.GetTriggerPolarity());
			dictionaryDao.SelectByObject(sensorPara.GetCoordinateSystem());
			dictionaryDao.SelectByObject(sensorPara.GetCoordinateSystemDirection());
			dictionaryDao.SelectByObject(sensorPara.GetEngineeringUnits());
			dictionaryDao.SelectByObject(sensorPara.GetIntegralType());
			dictionaryDao.SelectByObject(sensorPara.GetIntegralUnits());
			dictionaryDao.SelectByObject(sensorPara.GetInputMethod());
			dictionaryDao.SelectByObject(sensorPara.GetSensorStatus());
			dictionaryDao.SelectByObject(sensorPara.GetSensorStatus());
			dictionaryDao.SelectByObject(sensorPara.GetMessureType());

			////���뵽��������������
			vsensorPara.push_back(sensorPara);
		}
	}
	return true;
}

////���Ӵ�����
bool CSensorService::AddSensor(TbSensor &sensor){
	m_sensorDao.SetTableFieldValues(sensor);
	bool isSuccess =  m_sensorDao.Insert(false);
	m_sensorDao.GetTableFieldValues(sensor);
	return isSuccess;
}
bool CSensorService::Delete(TbSensor sensor){
	CString strSqlWhere = "1 = 1 ";
	if (sensor.GetId() != 0)
		strSqlWhere += " and id ='" + CommonUtil::Int2CString(sensor.GetId()) + "'";
	if (sensor.GetChannelId() != "")
		strSqlWhere += " and sensor_id ='" + sensor.GetChannelId() + "'";
	if (sensor.GetTestingdeviceId() != 0)
		strSqlWhere += " and testingdevice_id ='" + CommonUtil::Int2CString(sensor.GetTestingdeviceId()) + "'";
	return m_sensorDao.DeleteByCondition(strSqlWhere);
}
bool CSensorService::Update(TbSensor sensor){
	m_sensorDao.SetTableFieldValues(sensor);
	bool isSuccess = m_sensorDao.UpdateByKey();
	return isSuccess;
}