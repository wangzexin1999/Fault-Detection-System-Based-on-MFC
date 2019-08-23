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
	///������ݶ����Ѿ�û�������ˣ���ô�ͷ��߳�����Ȼ���˳��̡߳�
	if (theApp.m_collectData[viewId].size() == 0) { ReleaseMutex(m_popCollectDataQueueMutex); return Result(true,"����Ϊ�գ��˳������߳�"); }
	///����Ѿ�û��m_icollectSignalsStoreCount�������ˣ���ô�ͱ����ʣ������
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
	///������ݶ����Ѿ�û�������ˣ���ô�ͷ��߳�����Ȼ���˳��̡߳�
	if (theApp.m_sampleData[viewId].size() == 0) { ReleaseMutex(m_popCollectDataQueueMutex); return Result(true, "����Ϊ�գ��˳������߳�"); }
	///����Ѿ�û��m_isampleSignalsStoreCount�������ˣ���ô�ͱ����ʣ������
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
		return Result(true,"���ش��������ݳɹ�");
	}
	return Result(false, "���ش���������ʧ��");
}