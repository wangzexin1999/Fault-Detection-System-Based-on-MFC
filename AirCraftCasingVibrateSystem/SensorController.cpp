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


Result SensorController::SaveCollectionData(int viewId, int sensorId){
	///�˴�Ӧ����
	ThreadSafeQueue<AcquiredSignal> collectionData;
	for (int i = 0; i < theApp.m_isignalsStoreCount; i++){
		shared_ptr<AcquiredSignal>	acquireSignal = theApp.m_collectData[viewId].wait_and_pop();
		collectionData.push(*acquireSignal);
	}
	///�˴�Ӧ����
	Result res = m_sensorService.AddCollectData(theApp.m_currentProject, sensorId, collectionData);
	return res;
}

Result SensorController::FindAllSensorByTestingDeviceId(int testingDeviceId, vector<TbSensor> & sensorVector){
	sensorVector.clear();
	bool isSuccess = m_sensorService.GetAllSensorByTestingDeviceId(testingDeviceId, sensorVector);
	if (isSuccess){
		return Result(true,"���ش��������ݳɹ�");
	}
	return Result(false, "���ش���������ʧ��");
}