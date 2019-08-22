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
//
//// ��ȡ�������߳� ���ô��εķ�ʽ��forѭ�����߳�
//UINT  SensorController::ReadDataThreadProcing(void * pParam)
//{
//	int pthis = (int)pParam;
//	while (theApp.m_bThreadActive)
//	{
//		theApp.m_vSignalAcquisitionService[pthis].ReadData();	
//	}
//	return 1;
//}
//
//// ��ʼ�ɼ���������̶߳�ȡ����
//int SensorController::StartCaptureData(int nChannelNum)
//{
//	////���δ����̣߳�ʹ�߳̽������״̬
//	for (int i = 0; i < nChannelNum; i++){
//		 ///// ������������ȡ���ݵ��߳�
//		 m_pReadDataThread[i] = (HANDLE)_beginthreadex(NULL, 0, ReadDataThreadProcing, (void *)i, 0, NULL);
//	}
//
//	for (int i = 0; i < nChannelNum; i++){
//		///// ������������ȡ���ݵ��߳�
//		ResumeThread(m_pReadDataThread[i]);
//	}
//	
//	return 0;
//}
//
//UINT SensorController::AutoSaveCollectionData(void * pParam){
//	CSensorService m_seneorService;
//	while (true){
//		if (theApp.m_bIsAutoSaveSamplingData); {
//			///�����Զ�����
//			int count = 0;///��ǰ���������źű��������ĸ���
//			int size = theApp.m_vSignalAcquisitionService.size();
//			for (int i = 0; i < size; i++){
//				if (theApp.m_vSignalAcquisitionService[i].GetCollectDataSize() >= theApp.m_iSignalsStoreCount){ count++; }
//			}
//			if (count == size){
//				////�������е����ж���Ԫ�ظ����������˿��Ա��������ʱ,���÷���ȥ����ɼ�����
//				TRACE("\n�ٿ��߳�ȥ��������\n");
//				m_seneorService.SaveCollectData(theApp.m_currentProject, theApp.m_iSignalsStoreCount);
//			}
//		}
//	}
//	return 1;
//}
//
//////�����Զ������������
//int SensorController::StartAutoSaveCollectionData(){
//	HANDLE ht =  (HANDLE)_beginthreadex(NULL, 0, AutoSaveCollectionData, (void *)NULL, 0, NULL);
//	ResumeThread(ht);
//	return 0;
//}

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