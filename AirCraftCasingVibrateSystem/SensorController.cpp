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

Result SensorController::SaveCollectionData(int viewId, int sensorId){
	WaitForSingleObject(m_popCollectDataQueueMutex, INFINITE);
	ThreadSafeQueue<AcquiredSignal> collectionData;
	int saveCount = theApp.m_icollectSignalsStoreCount;
	///如果数据队列已经没有数据了，那么释放线程锁，然后退出线程。
	if (theApp.m_collectData[viewId].size() == 0) { ReleaseMutex(m_popCollectDataQueueMutex); return Result(true,"数据为空，退出保存线程"); }
	///如果已经没有m_icollectSignalsStoreCount条数据了，那么就保存仅剩的数据
	else if (theApp.m_collectData[viewId].size() < saveCount){ saveCount = theApp.m_collectData[viewId].size(); }
	for (int i = 0; i < saveCount; i++){
		shared_ptr<AcquiredSignal>	acquireSignal = theApp.m_collectData[viewId].wait_and_pop();
		collectionData.push(*acquireSignal);
	}
	ReleaseMutex(m_popCollectDataQueueMutex);
	
	Result res = m_sensorService.AddCollectData(theApp.m_currentProject, sensorId, collectionData);
	return res;
}

Result SensorController::SaveSampleData(int viewId, int sensorId){
	WaitForSingleObject(m_popCollectDataQueueMutex, INFINITE);
	ThreadSafeQueue<AcquiredSignal> collectionData;
	int saveCount = theApp.m_isampleSignalsStoreCount;
	///如果数据队列已经没有数据了，那么释放线程锁，然后退出线程。
	if (theApp.m_sampleData[viewId].size() == 0) { ReleaseMutex(m_popCollectDataQueueMutex); return Result(true, "数据为空，退出保存线程"); }
	///如果已经没有m_isampleSignalsStoreCount条数据了，那么就保存仅剩的数据
	 else if (theApp.m_sampleData[viewId].size() < saveCount){ saveCount = theApp.m_sampleData[viewId].size(); }
	for (int i = 0; i < saveCount; i++){
		shared_ptr<AcquiredSignal>	acquireSignal = theApp.m_sampleData[viewId].wait_and_pop();
		collectionData.push(*acquireSignal);
	}
	ReleaseMutex(m_popCollectDataQueueMutex);
	Result res = m_sensorService.AddSampleData(theApp.m_currentProject, sensorId, collectionData);
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