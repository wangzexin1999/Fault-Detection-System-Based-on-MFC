#include "stdafx.h"
#include "SensorController.h"
#include "AirCraftCasingVibrateSystem.h"
#include <mutex>
#include "AcquiredSignal.h"

//HANDLE SensorController::m_hMutex;

SensorController::SensorController(void)
{
	//m_hMutex = ::CreateMutex(NULL, FALSE, NULL);
}


SensorController::~SensorController()
{
	//CloseHandle(m_hMutex);
}

// ��ȡ�������߳� ���ô��εķ�ʽ��forѭ�����߳�
UINT  SensorController::ReadDataThreadProcing(void * pParam)
{
	int pthis = (int)pParam;
	while (theApp.m_bThreadActive)
	{
		//WaitForSingleObject(m_hMutex, INFINITE);
		theApp.m_vSignalAcquisitionService[pthis].ReadData();
		//ReleaseMutex(m_hMutex);
	}
	return 1;
}

// ��ʼ�ɼ���������̶߳�ȡ����
int SensorController::StartCaptureData(int nChannelNum)
{
	////���δ����̣߳�ʹ�߳̽������״̬
	for (int i = 0; i < nChannelNum; i++){
		 ///// ������������ȡ���ݵ��߳�
		 m_pReadDataThread[i] = (HANDLE)_beginthreadex(NULL, 0, ReadDataThreadProcing, (void *)i, 0, NULL);
	}

	for (int i = 0; i < nChannelNum; i++){
		///// ������������ȡ���ݵ��߳�
		ResumeThread(m_pReadDataThread[i]);
	}
	
	return 0;
}

UINT SensorController::AutoSaveCollectionData(void * pParam){
	CSensorService m_seneorService;
	while (true){
		if (theApp.m_bIsAutoSaveSamplingData); {
			///�����Զ�����
			int count = 0;///��ǰ���������źű��������ĸ���
			int size = theApp.m_vSignalAcquisitionService.size();
			for (int i = 0; i < size; i++){
				if (theApp.m_vSignalAcquisitionService[i].GetCollectDataSize() >= theApp.m_iSignalsStoreCount){ count++; }
			}
			if (count == size){
				////�������е����ж���Ԫ�ظ����������˿��Ա��������ʱ,���÷���ȥ����ɼ�����
				TRACE("\n�������ݡ���������������������������������������������\n");
				m_seneorService.SaveCollectData(theApp.m_currentProject, theApp.m_iSignalsStoreCount);
			}
		}
	}
	return 1;
}

////�����Զ������������
int SensorController::StartAutoSaveCollectionData(){
	/*HANDLE ht =  (HANDLE)_beginthreadex(NULL, 0, AutoSaveCollectionData, (void *)NULL, 0, NULL);
	ResumeThread(ht);*/
	return 0;
}
