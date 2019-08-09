#include "stdafx.h"
#include "SensorController.h"
#include "AirCraftCasingVibrateSystem.h"
#include <mutex>
#include "AcquiredSignal.h"

HANDLE SensorController::m_hMutex;

SensorController::SensorController(void)
{
	m_hMutex = ::CreateMutex(NULL, FALSE, NULL);
}


SensorController::~SensorController()
{
	CloseHandle(m_hMutex);
}

// 读取传感器线程 想用传参的方式，for循环开线程
UINT  SensorController::ReadDataThreadProcing(void * pParam)
{
	int pthis = (int)pParam;
	while (theApp.m_bThreadActive)
	{
		WaitForSingleObject(m_hMutex, INFINITE);
		theApp.m_vSersor[pthis].ReadData(pthis);
		//Sleep(DELAY_TIME);
		ReleaseMutex(m_hMutex);
	}
	return 1;
}

// 开始采集开启多个线程读取数据
int SensorController::StartCaptureData(int nChannelNum)
{
	for (int i = 0; i < nChannelNum; i++){
		 ///// 开启传感器读取数据的线性
		 m_pReadDataThread[i] = (HANDLE)_beginthreadex(NULL, 0, ReadDataThreadProcing, (void *)i, 0, NULL);
	}
	return 0;
}
UINT SensorController::AutoSaveCollectionData(void * pParam){
	vector<queue<AcquiredSignal>> &collectData = theApp.m_collectData;  ///创建全局对象的引用
	CSensorService m_seneorService;
	while (true){
		if (theApp.m_bIsAutoSaveSamplingData); {
			///设置自动保存
			int count = 0;///当前队列满足信号保存数量的个数
			for (int i = 0; i < collectData.size();i++){
				if (collectData[i].size() >= theApp.m_iSignalsStoreCount){ count++; }
			}
			if (count == collectData.size()){
				////当集合中的所有队列元素个数都到达了可以保存的条件时,调用服务去保存采集数据
				WaitForSingleObject(m_hMutex, INFINITE);
				m_seneorService.SaveCollectData(theApp.m_currentProject,collectData, theApp.m_iSignalsStoreCount);
				ReleaseMutex(m_hMutex);
			}
		}
	}
	return 1;
}

////开启自动保存采样数据
int SensorController::StartAutoSaveCollectionData(){
	(HANDLE)_beginthreadex(NULL, 0, AutoSaveCollectionData, (void *)NULL, 0, NULL);
	return 0;
}
