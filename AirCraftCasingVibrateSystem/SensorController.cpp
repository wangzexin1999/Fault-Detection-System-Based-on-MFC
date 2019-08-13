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
	CSensorService sensorService;
	while (theApp.m_bThreadActive)
	{
		//WaitForSingleObject(m_hMutex, INFINITE);
		sensorService.ReadData(pthis);
		//ReleaseMutex(m_hMutex);
		Sleep(50);
	}
	return 1;
}

// ��ʼ�ɼ���������̶߳�ȡ����
int SensorController::StartCaptureData(int nChannelNum)
{
	////���δ����̣߳�ʹ�߳̽������״̬
	for (int i = 0; i < nChannelNum; i++){
		 ///// ������������ȡ���ݵ�����
		 m_pReadDataThread[i] = (HANDLE)_beginthreadex(NULL, 0, ReadDataThreadProcing, (void *)i, 0, NULL);
		 ///// ����ָ�������Ŀռ�ȥ��Ż�������
		 ThreadSafeQueue<EchoSignal> echoSignalQueue;
		 theApp.m_echoData.push_back(echoSignalQueue);
	}
	////���ο����̣߳�ʹ�߳�����
	for (int i = 0; i < nChannelNum; i++)
	{
		ResumeThread(m_pReadDataThread[i]);
	}
	return 0;
}

UINT SensorController::AutoSaveCollectionData(void * pParam){
	vector<ThreadSafeQueue<AcquiredSignal>> &collectData = theApp.m_collectData;  ///����ȫ�ֶ��������
	CSensorService m_seneorService;
	while (true){
		if (theApp.m_bIsAutoSaveSamplingData); {
			///�����Զ�����
			int count = 0;///��ǰ���������źű��������ĸ���
			for (int i = 0; i < collectData.size();i++){
				if (collectData[i].size() >= theApp.m_iSignalsStoreCount){ count++; }
			}
			if (count == collectData.size()){
				////�������е����ж���Ԫ�ظ����������˿��Ա��������ʱ,���÷���ȥ����ɼ�����
				TRACE("\n�������ݡ�������������������������������\n");
				m_seneorService.SaveCollectData(theApp.m_currentProject,collectData, theApp.m_iSignalsStoreCount);
			}
		}
	}
	return 1;
}

////�����Զ������������
int SensorController::StartAutoSaveCollectionData(){
	(HANDLE)_beginthreadex(NULL, 0, AutoSaveCollectionData, (void *)NULL, 0, NULL);
	return 0;
}
