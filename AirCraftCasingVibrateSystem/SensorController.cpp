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

Result SensorController::SaveCollectionData(int sensorId, ThreadSafeQueue<AcquiredSignal> &collectionData) {
	Result res = m_sensorService.AddCollectData(theApp.m_currentProject, sensorId, collectionData);
	return res;
}

//Result SensorController::SaveSampleData(int viewId, int sensorId){
//	/*Result res = m_sensorService.AddSampleData(theApp.m_currentProject, sensorId, collectionData);
//	return res;*/
//	
//}

Result SensorController::FindAllSensorByTestingDeviceId(int testingDeviceId, vector<TbSensor> & sensorVector){
	sensorVector.clear();
	bool isSuccess = m_sensorService.GetAllSensorByTestingDeviceId(testingDeviceId, sensorVector);
	if (isSuccess){
		return Result(true,"加载传感器数据成功");
	}
	return Result(false, "加载传感器数据失败");
}