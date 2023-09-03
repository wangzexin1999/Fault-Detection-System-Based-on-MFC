
// AirCraftCasingVibrateSystem.h : AirCraftCasingVibrateSystem Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#define SERSOR_NUM  4         //����������
#include "resource.h"       // ������
#include <iostream>
#include "NetConService.h"
#include "ChannelService.h"
#include <vector>
#include "PDSQL.h"
#include "TbProject.h"
#include "ThreadSafeQueue.h"////�̰߳�ȫ���� 
#include "AcquiredSignal.h"
#include "SignalAcquisitionService.h"
#include "AirCraftCasingVibrateSystemView.h"
#include "redisUtil.h"
#include "httplib.h"
#include "Common.h"
#include <list>
#include "RedisDataProcess.h"
using namespace std;


// CAirCraftCasingVibrateSystemApp:
// �йش����ʵ�֣������ AirCraftCasingVibrateSystem.cpp
//

class CAirCraftCasingVibrateSystemApp : public CWinAppEx
{
public:
	CAirCraftCasingVibrateSystemApp();

	bool m_isAlarm;//�Ƿ񱨾�
	double m_alarmLimit;//��������
	const int SHOW_CHANNEL_USE = 3; 	/// ͨ��ʹ�ñ�־
	const int SHOW_CHANNEL_MEASURETYPE = 4; /// ͨ����������1
	const int SHOW_CHANNEL_FULLVALUE = 5; 	/// ��������1
	const int SHOW_CHANNEL_SENSECOEF = 6; 	/// ������������1
	const int SHOW_CHANNEL_UPFREQ = 10; 	/// ����Ƶ��1
	const int SHOW_CHANNEL_DOWNFREQ = 11; 	/// ����Ƶ��1
	const int SHOW_CHANNEL_ACQ_INPUTMODE = 12; 	/// ���뷽ʽ1
	const int SHOW_CHANNEL_ANTIFILTER = 14; 	/// �����˲���
	const int SHOW_ELC_PRESSURE = 90;        ///��ѹ������Χ1

	CNetConService  m_con;  // ����ͨ������
	bool m_bcon = false;  // �ж�����ͨ���Ƿ����ӳɹ�
	Redis *m_redisCon = new Redis();  
	bool m_bShowInfThreadActive = true;
	/// �û�
	TbProject m_currentProject;
	int m_chartCtrlIndex = 10000;/*��ͼ�ؼ�ID*/
	int m_icollectSignalsStoreCount = 20000; ///�ɼ��źŵĴ洢������ 

	int m_icollectState = 0; ////�ɼ�״̬ 0 ��ֹͣ�ɼ� 1����ʼ�ɼ� 2����ͣ�ɼ�  �Ժ���ö������

	vector<string> m_listFullValue;
	vector<string> m_listUpFreq;
	vector<string> m_elcpressure;
	vector<string> m_listInputMode;
	vector<string> m_listMessaueType;
	vector<int> m_listSampleFreq;
	//vector<int> m_vlines = { 50, 100, 200, 400, 800, 1600, 3200, 6400, 12800, 25600 };
	stuHardChannel m_curstuHardChannel;


	int m_isampleStatus = 0;////����״̬ 0 ��ֹͣ���� 1����ʼ����
	int m_signalEchoCount = 1000; //�źŻ�������
	volatile int m_iplaybackState = 0;//0 : ���ط� 1����ʼ�ط� 2��:��ͣ�ط�

	bool m_bisSave = false;//����״̬
	bool m_redisIsSave = false;//redis����״̬

	CString m_collectionRotatingSpeed = "";
	vector<SignalAcquisitionService> m_vSignalAcquisitionService; ////�źŲɼ�����
	
	double tempRead[100][1000]; ///ģ������
	httplib::Client m_cli; // http����
	bool m_newProjectStatus = false;

	std::vector<CAirCraftCasingVibrateSystemView *> m_vsignalCaptureView;///�ɼ����ڵļ���

	vector<stuHardChannel> m_vecHardChannel;			//ͨ����Ϣ

	vector<stuGroupChannel> m_vecGroupChannel;			//ͨ������Ϣ

	RedisDataProcess *m_redisConnect = new RedisDataProcess();

	redisContext* m_redisContext;
	redisReply* m_redisReply;


	bool deviceIsOnline = true;

	float FFTRATE = 2.56;
// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	PDSQL PDsql;
	PDSQL m_conPDLocalSql;
// ʵ��
	UINT  m_nAppLook;
	//virtual void PreLoadState();
	//virtual void LoadCustomState();
	//virtual void SaveCustomState();
	class CDHTestHardWare *m_pHardWare;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CAirCraftCasingVibrateSystemApp theApp;
