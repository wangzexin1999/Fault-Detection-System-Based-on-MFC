// 这段 MFC 示例源代码演示如何使用 MFC Microsoft Office Fluent 用户界面 
// (“Fluent UI”)。该示例仅供参考，
// 用以补充《Microsoft 基础类参考》和 
// MFC C++ 库软件随附的相关电子文档。  
// 复制、使用或分发 Fluent UI 的许可条款是单独提供的。  
// 若要了解有关 Fluent UI 许可计划的详细信息，请访问  
// http://go.microsoft.com/fwlink/?LinkId=238214。
//
// 版权所有(C) Microsoft Corporation
// 保留所有权利。

// AirCraftCasingVibrateSystem.h : AirCraftCasingVibrateSystem 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#define SERSOR_NUM  4         //传感器个数
#include "resource.h"       // 主符号

#include "NetConService.h"
#include "SensorService.h"
#include <vector>
#include "PDSQL.h"
#include "TbProject.h"
#include "ThreadSafeQueue.h"////线程安全锁。 
#include "AcquiredSignal.h"
using namespace std;


// CAirCraftCasingVibrateSystemApp:
// 有关此类的实现，请参阅 AirCraftCasingVibrateSystem.cpp
//

class CAirCraftCasingVibrateSystemApp : public CWinAppEx
{
public:
	CAirCraftCasingVibrateSystemApp();

	CNetConService  m_con;  // 网络通信连接
	bool m_bcon = false;  // 判断网络通信是否连接成功

	// 多个传感器
	//vector<CSensorService>  m_vSersor;
	bool m_bThreadActive = false; // 采集数据线程控制标准
	bool m_bShowInfThreadActive = true;
	/// 用户
	TbProject m_currentProject;
	int m_chartCtrlIndex = 10000;/*画图控件ID*/

	//vector<queue<EchoSignal>> m_sampleData;

	int m_iSignalsStoreCount = 100000; ///信号的存储数量。 

	bool m_bIsSample = false;//是否进行采样

	int m_signalEchoCount = 2000; //信号回显数量

	bool m_bIsAutoSaveSamplingData = true; ///是否自动保存采样数据
	bool m_bIsAutoSaveCollectionData = true; ///是否自动保存采集数据

	vector<ThreadSafeQueue<AcquiredSignal>> m_sampleData; ///采样数据
	vector<ThreadSafeQueue<AcquiredSignal>> m_collectData; ///采集数据

	vector<ThreadSafeQueue<EchoSignal>> m_echoData; ///回显数据


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	PDSQL PDsql;
// 实现
	UINT  m_nAppLook;
	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CAirCraftCasingVibrateSystemApp theApp;
