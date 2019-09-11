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

Result CSensorService::AddCollectData(TbProject project, int sensorId, ThreadSafeQueue<AcquiredSignal> &collectionData){
	///1.ƴװ����·��
	CString path = "C:\\collectionData\\";
	//2.ƴװ�ļ��� ��Ŀid_�����豸id_������id_��Ʒid_ʱ���
	CString fileName = CommonUtil::Int2CString(project.GetProjectId()) + "-"
		+ CommonUtil::Int2CString(project.GetTestingDevicePara().GetTestingdevice().GetTestingdeviceId())
		+ "-" + CommonUtil::Int2CString(sensorId) + "-" + CommonUtil::Int2CString(project.GetProduct().GetProductId())
		+ "-" + DateUtil::GetTimeStampCString()
		+ ".csv";

	CString startCollectTime = collectionData.front().GetAcquireTime();
	
	Result res;
	//3.����FileUtil�����ļ�������ɹ����زɼ��Ľ���ʱ��
	/*Result res = CFileUtil::SaveCollectionData(path, fileName, collectionData);
	if (res.GetIsSuccess()){
		///4.�ļ�����ɹ�������¼���浽���ݿ�
		TbSignal signal;
		signal.SetDataUrl(path + fileName);
		signal.SetProject (project);
		signal.SetProduct(project.GetProduct());
		signal.SetStartTime(startCollectTime);
		signal.SetEndTime(res.GetMessages());
		signal.GetSensor().SetSensorId(sensorId);
		signal.GetTestingDevice().SetTestingdeviceId(project.GetTestingDevicePara().GetTestingdevice().GetTestingdeviceId());
		m_signalDao.SetTableFieldValues(signal);
		m_signalDao.Insert(false);
	}*/


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
	{ "projectID", CommonUtil::Int2CString(project.GetProduct().GetProductId()).GetBuffer(), "", "" },
	{ "checkDeviceID", CommonUtil::Int2CString(project.GetTestingDevicePara().GetTestingdevice().GetTestingdeviceId()).GetBuffer(), "", "" },
	{ "sensorID", CommonUtil::Int2CString(sensorId).GetBuffer(), "", "" },
	{ "startTime", startCollectTime.GetBuffer(), "", "" },
	{ "endTime", endTime.GetBuffer(), "", "" },
	{ "productID", CommonUtil::Int2CString(project.GetProduct().GetProductId()).GetBuffer(), "", "" },
	};
	auto result = theApp.m_cli.Post("/collection", items);
	if (!result)//���û�з��ͳɹ��������·���
	{
		httplib::Client cli(_T(ServerHttpAddress), ServerHttpPort);
		theApp.m_cli = cli;
		auto result = theApp.m_cli.Post("/collection", items);
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

Result CSensorService::AddSampleData(TbProject project, int sensorId, ThreadSafeQueue<AcquiredSignal> &collectionData){
	///1.ƴװ����·��
	CString path = "I:\\SampleData\\";
	//2.ƴװ�ļ��� ��Ŀid_�����豸id_������id_��Ʒid_ʱ���
	CString fileName = CommonUtil::Int2CString(project.GetProjectId()) + "-"
		+ CommonUtil::Int2CString(project.GetTestingDevicePara().GetTestingdevice().GetTestingdeviceId())
		+ "-" + CommonUtil::Int2CString(sensorId) + "-" + CommonUtil::Int2CString(project.GetProduct().GetProductId())
		+ "-" + DateUtil::GetTimeStampCString()
		+ ".csv";

	CString startCollectTime = collectionData.front().GetAcquireTime();
	//3.����FileUtil�����ļ�������ɹ����زɼ��Ľ���ʱ��
	Result res = CFileUtil::SaveCollectionData(path, fileName, collectionData);
	if (res.GetIsSuccess()){
		///4.�ļ�����ɹ�������¼���浽���ݿ�
		TbSignal signal;
		signal.SetDataUrl(path + fileName);
		signal.SetProject(project );
		signal.SetProduct(project.GetProduct());
		signal.SetStartTime(startCollectTime);
		signal.SetEndTime(res.GetMessages());
		signal.GetSensor().SetSensorId(sensorId);
		signal.GetTestingDevice().SetTestingdeviceId(project.GetTestingDevicePara().GetTestingdevice().GetTestingdeviceId());
		m_recordSignalDao.SetTableFieldValues(signal);
		m_recordSignalDao.Insert(false);
	}
	return res;
}