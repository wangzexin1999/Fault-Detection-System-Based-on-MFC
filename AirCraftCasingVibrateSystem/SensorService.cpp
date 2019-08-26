#include "stdafx.h"
#include "SensorService.h"
#include "FileUtil.h"
#include "CommonUtil.h"
#include "DateUtil.h"


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

Result CSensorService::AddCollectData(TbProject project, int sensorId, ThreadSafeQueue<AcquiredSignal> &collectionData){
	///1.拼装保存路径
	CString path = "C:\\collectionData\\";
	//2.拼装文件名 项目id_测试设备id_传感器id_产品id_时间戳
	CString fileName = CommonUtil::Int2CString(project.GetProjectId()) + "-"
		+ CommonUtil::Int2CString(project.GetTestingDevicePara().GetTestingdevice().GetTestingdeviceId())
		+ "-" + CommonUtil::Int2CString(sensorId) + "-" + CommonUtil::Int2CString(project.GetDetectedDevice().GetDetecteddeviceId())
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
		signal.SetDetectedDevice(project.GetDetectedDevice());
		signal.SetStartTime(startCollectTime);
		signal.SetEndTime(res.GetMessages());
		signal.GetSensor().SetSensorId(sensorId);
		signal.GetTestingDevice().SetTestingdeviceId(project.GetTestingDevicePara().GetTestingdevice().GetTestingdeviceId());
		m_signalDao.SetTableFieldValues(signal);
		m_signalDao.Insert(false);
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
		+ CommonUtil::Int2CString(project.GetTestingDevicePara().GetTestingdevice().GetTestingdeviceId())
		+ "-" + CommonUtil::Int2CString(sensorId) + "-" + CommonUtil::Int2CString(project.GetDetectedDevice().GetDetecteddeviceId())
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
		signal.SetDetectedDevice(project.GetDetectedDevice());
		signal.SetStartTime(startCollectTime);
		signal.SetEndTime(res.GetMessages());
		signal.GetSensor().SetSensorId(sensorId);
		signal.GetTestingDevice().SetTestingdeviceId(project.GetTestingDevicePara().GetTestingdevice().GetTestingdeviceId());
		m_recordSignalDao.SetTableFieldValues(signal);
		m_recordSignalDao.Insert(false);
	}
	return res;
}