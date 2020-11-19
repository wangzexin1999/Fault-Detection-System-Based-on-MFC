
// AirCraftCasingVibrateSystem.h : AirCraftCasingVibrateSystem 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#define SERSOR_NUM  4         //传感器个数
#include "resource.h"       // 主符号

#include "NetConService.h"
#include "ChannelService.h"
#include <vector>
#include "PDSQL.h"
#include "TbProject.h"
#include "ThreadSafeQueue.h"////线程安全锁。 
#include "AcquiredSignal.h"
#include "SignalAcquisitionService.h"
#include "AirCraftCasingVibrateSystemView.h"
#include "redisUtil.h"
#include "httplib.h"
using namespace std;


// CAirCraftCasingVibrateSystemApp:
// 有关此类的实现，请参阅 AirCraftCasingVibrateSystem.cpp
//

class CAirCraftCasingVibrateSystemApp : public CWinAppEx
{
public:
	CAirCraftCasingVibrateSystemApp();

	bool m_isAlarm;//是否报警
	double m_alarmLimit;//报警上限


	CNetConService  m_con;  // 网络通信连接
	bool m_bcon = false;  // 判断网络通信是否连接成功
	Redis *m_redisCon = new Redis();  
	bool m_bShowInfThreadActive = true;
	/// 用户
	TbProject m_currentProject;
	int m_chartCtrlIndex = 10000;/*画图控件ID*/
	int m_icollectSignalsStoreCount = 100000; ///采集信号的存储数量。 
	int m_icollectionStatus = 0; ////采集状态 0 ：停止采集 1：开始采集 2：暂停采集 
	int m_isampleStatus = 0;////采样状态 0 ：停止采样 1：开始采样
	int m_signalEchoCount = 1000; //信号回显数量
	int m_iplaybackStatus = 0;//0 : 不回放 1：开始回放 2：:暂停回放

	bool m_bisSave = false;//保存状态
	CString m_collectionRotatingSpeed = "";
	vector<SignalAcquisitionService> m_vSignalAcquisitionService; ////信号采集服务
	
	double tempRead[100][1000]; ///模拟数据
	httplib::Client m_cli; // http连接
	bool m_newProjectStatus = false;

	std::vector<CAirCraftCasingVibrateSystemView *> m_vsignalCaptureView;///采集窗口的集合

// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	PDSQL PDsql;
	PDSQL m_conPDLocalSql;
// 实现
	UINT  m_nAppLook;
	//virtual void PreLoadState();
	//virtual void LoadCustomState();
	//virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CAirCraftCasingVibrateSystemApp theApp;
