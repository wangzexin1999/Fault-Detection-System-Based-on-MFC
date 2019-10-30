#include "stdafx.h"
#include "SensorController.h"
#include "AirCraftCasingVibrateSystem.h"
#include "AcquiredSignal.h"

SensorController::SensorController(void)
{
}


SensorController::~SensorController()
{
	
}
HANDLE  SensorController::m_popCollectDataQueueMutex = CreateMutex(NULL, FALSE, NULL);

HANDLE  SensorController::m_popSampleDataQueueMutex = CreateMutex(NULL, FALSE, NULL);


Result SensorController::SaveCollectionData(CString sensorId, ThreadSafeQueue<AcquiredSignal> &collectionData) {
	TbSignal signal;
	signal.SetProjectId(theApp.m_currentProject.GetProjectId());
	signal.SetProductId(theApp.m_currentProject.GetProduct().GetProductId());
	signal.SetTestingDeviceId(theApp.m_currentProject.GetTestingDevice().GetId());
	//signal.SetChannels(sensorId);
	signal.SetCollectionStatus(theApp.m_jsonCollectionStatusPara);
	Result res = m_sensorService.AddCollectData(signal,collectionData);
	return res;
}

Result SensorController::FindAllSensorByTestingDeviceId(int testingDeviceId, vector<TbSensor> & sensorVector){
	sensorVector.clear();
	bool isSuccess = m_sensorService.GetAllSensorByTestingDeviceId(testingDeviceId, sensorVector);
	if (isSuccess){
		return Result(true,"加载传感器数据成功");
	}
	return Result(false, "加载传感器数据失败");
}
Result SensorController::UpdateSensor(TbSensor sensor){
	bool isSuccess = m_sensorService.Update(sensor);
	if (isSuccess){
		return Result(true, "添加成功");
	}
	return Result(false, "添加失败");
}