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

// 读取传感器线程 想用传参的方式，for循环开线程
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

// 开始采集开启多个线程读取数据
int SensorController::StartCaptureData(int nChannelNum)
{
	////依次创建线程，使线程进入挂起状态
	for (int i = 0; i < nChannelNum; i++){
		 ///// 开启传感器读取数据的线程
		 m_pReadDataThread[i] = (HANDLE)_beginthreadex(NULL, 0, ReadDataThreadProcing, (void *)i, 0, NULL);
	}

	for (int i = 0; i < nChannelNum; i++){
		///// 开启传感器读取数据的线程
		ResumeThread(m_pReadDataThread[i]);
	}
	
	return 0;
}

UINT SensorController::AutoSaveCollectionData(void * pParam){
	CSensorService m_seneorService;
	while (true){
		if (theApp.m_bIsAutoSaveSamplingData); {
			///设置自动保存
			int count = 0;///当前队列满足信号保存数量的个数
			int size = theApp.m_vSignalAcquisitionService.size();
			for (int i = 0; i < size; i++){
				if (theApp.m_vSignalAcquisitionService[i].GetCollectDataSize() >= theApp.m_iSignalsStoreCount){ count++; }
			}
			if (count == size){
				////当集合中的所有队列元素个数都到达了可以保存的条件时,调用服务去保存采集数据
				TRACE("\n保存数据。。。。。。。。。。。。。。。。。。。。。。。\n");
				m_seneorService.SaveCollectData(theApp.m_currentProject, theApp.m_iSignalsStoreCount);
			}
		}
	}
	return 1;
}

////开启自动保存采样数据
int SensorController::StartAutoSaveCollectionData(){
	/*HANDLE ht =  (HANDLE)_beginthreadex(NULL, 0, AutoSaveCollectionData, (void *)NULL, 0, NULL);
	ResumeThread(ht);*/
	return 0;
}
