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


/*随机数组*/
void CSensorService::RandArray(double* ptr, size_t length)
{
	for (size_t i = 0; i<length; ++i)
	{
		ptr[i] = randf(-1, 1);
	}
}
/*随机*/
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
	///1.拼装保存路径
	CString path = "C:\\collectionData\\";
	//2.拼装文件名 项目id_测试设备id_传感器id_产品id_时间戳
	CString fileName = CommonUtil::Int2CString(signal.GetProjectId()) + "-"
		+ CommonUtil::Int2CString(signal.GetTestingDeviceId())
		+ "-" + signal.GetSensorId() + "-" + CommonUtil::Int2CString(signal.GetProductId())
		+ "-" + DateUtil::GetTimeStampCString()
		+ ".csv";

	CString startCollectTime = collectionData.front().GetAcquireTime();
	
	Result res;
	/*如果可以连接到远程服务器则发送数据到远程，否则保存到本地*/
	if ((strcmp(theApp.PDsql.m_mysql.host, "127.0.0.1") == 0) || (strcmp(theApp.PDsql.m_mysql.host, "localhost") == 0))
	{
		//调用FileUtil保存文件，保存成功返回采集的结束时间
		res = CFileUtil::SaveCollectionData(path, fileName, collectionData);
		if (res.GetIsSuccess()){
		///文件保存成功，将记录保存到数据库
		signal.SetDataUrl(path + fileName);
		signal.SetStartTime(startCollectTime);
		signal.SetEndTime(res.GetMessages());
		//signal.GetTestingDevice().SetTestingdeviceId(project.GetTestingDevicePara().GetTestingdevice().GetId());
		m_signalDao.SetTableFieldValues(signal);
		m_signalDao.Insert(false);
		}
	}
	else
	{
		CString separator = ",";////逗号分隔符
		CString endTime;
		CString allData = "";
		int saveCount = collectionData.size();
		for (int i = 0; i < saveCount; i++){
			////循环采集数据的队列去保存数据
			CString data = "";
			shared_ptr<AcquiredSignal>	acquireSignal = collectionData.wait_and_pop();
			data += acquireSignal->GetAcquireTime() + separator;
			data += CommonUtil::DoubleOrFloat2CString(acquireSignal->GetSignalData()) + "\n";
			if (i == saveCount - 1) endTime = acquireSignal->GetAcquireTime();
			allData = allData + data;
		}

		// 如果可以连接上服务器，传数据
		httplib::MultipartFormDataItems items = {
			{ "data", allData.GetBuffer(), "1.txt", "text/plain" },//数据
			{ "projectID", CommonUtil::Int2CString(signal.GetProductId()).GetBuffer(), "", "" },
			//{ "checkDeviceID", CommonUtil::Int2CString(project.GetTestingDevicePara().GetTestingdevice().GetId()).GetBuffer(), "", "" },
			{ "sensorID", signal.GetSensorId().GetBuffer(), "", "" },
			{ "startTime", startCollectTime.GetBuffer(), "", "" },
			{ "endTime", endTime.GetBuffer(), "", "" },
			{ "productID", CommonUtil::Int2CString(signal.GetProductId()).GetBuffer(), "", "" },
		};
		auto result = theApp.m_cli.Post("/collection", items);
		if (!result)//如果没有发送成功，则重新发送
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
		///查询成功之后
		for (auto sensorDao : sensorDaoVec){
			TbSensor tbSensor;
			sensorDao.GetTableFieldValues(tbSensor);
			sensorVector.push_back(tbSensor);
		}
	}
	return isSuccess;
}

Result CSensorService::AddSampleData(TbProject project, int sensorId, ThreadSafeQueue<AcquiredSignal> &collectionData){
	///1.拼装保存路径
	CString path = "I:\\SampleData\\";
	//2.拼装文件名 项目id_测试设备id_传感器id_产品id_时间戳
	CString fileName = CommonUtil::Int2CString(project.GetProjectId()) + "-"
		+ CommonUtil::Int2CString(project.GetTestingDevice().GetId())
		+ "-" + CommonUtil::Int2CString(sensorId) + "-" + CommonUtil::Int2CString(project.GetProduct().GetProductId())
		+ "-" + DateUtil::GetTimeStampCString()
		+ ".csv";

	CString startCollectTime = collectionData.front().GetAcquireTime();
	//3.调用FileUtil保存文件，保存成功返回采集的结束时间
	Result res = CFileUtil::SaveCollectionData(path, fileName, collectionData);
	if (res.GetIsSuccess()){
		///4.文件保存成功，将记录保存到数据库
		TbSignal signal;
		signal.SetDataUrl(path + fileName);
		signal.SetProjectId(project.GetProjectId());
		signal.SetProductId(project.GetProduct().GetProductId());
		signal.SetStartTime(startCollectTime);
		signal.SetEndTime(res.GetMessages());
		/*signal.GetSensor().SetId(sensorId);
		signal.GetTestingDevice().SetId(project.GetTestingDevice().GetId());*/
		m_recordSignalDao.SetTableFieldValues(signal);
		m_recordSignalDao.Insert(false);
	}

	return res;
}



Result CSensorService::AddSampleData(TbProject project, int sensorId, TbRecordSignal recordSignal)
{
	recordSignal.SetProject(project);
	recordSignal.SetProduct(project.GetProduct());
	recordSignal.GetSensor().SetId(sensorId);
	recordSignal.GetTestingDevice().SetId(project.GetTestingDevice().GetId());
	//m_recordSignalDao.SetTableFieldValues(recordSignal);  这个地方改动
	bool bInsertRes = m_recordSignalDao.Insert(false);
	Result res = Result(bInsertRes, "");
	return res;

}
////根据项目id得到所有的传感器参数
bool CSensorService::GetALLSensorByProjectId(int projectId, std::vector<TbSensor> &vsensorPara){
	m_sensorDao.m_projectId.SetValue(projectId);
	vector<TbSensorDao> selectedValueVector;
	m_sensorDao.SelectObjectsByCondition(selectedValueVector, "project_id='" + CommonUtil::Int2CString(projectId) + "'");
	if (!selectedValueVector.empty()){
		////传感器参数不为空时
		for (auto tbsenorParaDao : selectedValueVector){
			////根据查询到的传感器参数封装TbSensor对象
			TbSensor sensorPara;
			tbsenorParaDao.GetTableFieldValues(sensorPara);
			////根据传感器各类参数的id去查字典表对应的字典值

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

			////存入到传感器参数集合
			vsensorPara.push_back(sensorPara);
		}
	}
	return true;
}

////添加传感器
bool CSensorService::AddSensor(TbSensor &sensor){
	m_sensorDao.SetTableFieldValues(sensor);
	bool isSuccess =  m_sensorDao.Insert(false);
	m_sensorDao.GetTableFieldValues(sensor);
	return isSuccess;
}