#include "stdafx.h"
#include "CheckTaskController.h"
#include "AirCraftCasingVibrateSystem.h"
#include <mutex>

HANDLE CCheckTaskController::m_hMutex;

CCheckTaskController::CCheckTaskController(void)
{
	m_hMutex = ::CreateMutex(NULL, FALSE, NULL);
}


CCheckTaskController::~CCheckTaskController()
{
//::CloseHandle(m_hMutex);
}




// ��ȡ�������߳� ���ô��εķ�ʽ��forѭ�����߳�
UINT  CCheckTaskController::ReadDataThreadProcing(void * pParam)
{
	int pthis = (int)pParam;
	while (theApp.m_bThreadActive)
	{

		WaitForSingleObject(m_hMutex, INFINITE);
		theApp.m_vSersor[pthis].ReadData();
		SignalService signalProcessService;
		signalProcessService.FastFourierTransformation(1000,
			theApp.m_vSersor[pthis].m_signalService.din, theApp.m_vSersor[pthis].m_signalService.out);
		theApp.m_vSersor[pthis].FFTDataToXY(theApp.m_vSersor[pthis].m_signalService.out);
		Sleep(DELAY_TIME);
		ReleaseMutex(m_hMutex);


	}
	return 1;
}


// ��ʼ�ɼ������̶߳�ȡ����
int CCheckTaskController::StartCaptureData(int nChannelNum)
{
	//nChannelNum = 2;
	for (int i = 0; i < nChannelNum; i++)
	{
		m_pReadDataThread[i] = (HANDLE)_beginthreadex(NULL, 0, ReadDataThreadProcing, (void *)i, 0, NULL);
	}
	//m_pReadDataThread[0] = (HANDLE)_beginthreadex(NULL, 0, ReadDataThreadProcing, (void *)nChannelNum, 0, NULL);


	return 0;
}

