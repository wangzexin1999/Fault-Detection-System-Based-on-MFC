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
#include <queue>
using namespace std;


// CAirCraftCasingVibrateSystemApp:
// 有关此类的实现，请参阅 AirCraftCasingVibrateSystem.cpp
//
class CAirCraftCasingVibrateSystemApp : public CWinAppEx
{
public:
	CAirCraftCasingVibrateSystemApp();

	unsigned int m_count;
	unsigned int m_count2;
	const size_t m_c_arrayLength = 2096;

	double m_readX[102400];//读取
	double m_readY[102400];

	double m_readDrawX[2096];//读取画
	double m_readDrawY[2096];

	double m_dSaveX[102400];// 存储
	double m_dSaveY[102400];

	CNetConService  m_con;  // 网络通信连接
	bool m_bcon = false;  // 判断网络通信是否连接成功

	int countNums = 0;
	int countNumsReadDraw = 0;
	// 多个传感器
	vector<CSensorService>  m_vSersor;
	bool m_bThreadActive = true; // 采集数据线程控制标准
	bool m_bShowInfThreadActive = true;
	/// 用户
	TbProject m_currentProject;
	int m_chartCtrlIndex = 10000;/*画图控件ID*/

	vector<queue<CSignal>> m_sampleData;
	 
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
