/************************************************************************
Copyright (C), 2018-2020. 哈尔滨理工大学人工智能实验室
文件名称： GeneralParaView.h
内容摘要： 通用参数界面.主要实现通用参数显示和通用参数设置。对应的实现类文件为GeneralParaView.cpp。
其它说明：飞机机匣振动检测系统
当前版本： 1.0
作 者： 刘望
创建日期： 2019-05-24
完成日期:
History:
1. Date:    2018-05-24         Author:刘望
Modification:
修改记录 1： // 修改历史记录，包括修改日期、修改者及修改内容
修改日期：
版 本 号：
修 改 人：
修改内容：
************************************************************************/
#pragma once
#include "afxcmn.h"
#include "GridCtrl_src/GridCtrl.h"
#include "ChannelParaController.h"
#include "NewCellTypes/GridCellCheck.h"
#include "NewCellTypes/GridCellCombo.h"
#include "DictionaryController.h"
#include <vector>
#include "CDHTestHardWare.h"
#include "TbProject.h"
#include "TestController.h"
#include "SensorController.h"

using namespace  std;


// CGeneralParaView 对话框
// CMyDialog 对话框
//const int theApp.SHOW_CHANNEL_FULLVALUE_ = 5; 	/// 满度量程1
//const int theApp.SHOW_CHANNEL_SENSECOEF_ = 6; 	/// 传感器灵敏度1
//const int SHOW_CHANNEL_UPFREQ_ = 10; 	/// 上限频率1
//const int SHOW_CHANNEL_ACQ_INPUTMODE_ = 12; 	/// 输入方式1
class CGeneralParaView : public CDialogEx
{
	DECLARE_DYNAMIC(CGeneralParaView)

public:
	CGeneralParaView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CGeneralParaView();
	void GetParamSelectValue(string strMachineIP);
	CString m_strSenseCoef;
	int BreakString(const string& strSrc, list<string>& lstDest, const string& strSeprator);
	// 对话框数据
	enum { IDD = IDD_DIALOG_GENERAL_PARA };
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	CGridCtrl m_generalParaGridCtrl;

	DictionaryController m_dictionController;
	vector<TbDictionary> m_vwindowTypes;  // 窗类型
	vector<TbDictionary> m_vinputMethods; // 输入方式
	list<string> m_listFullValue;
	list<string> m_listUpFreq;
	list<string> m_elcpressure;
	list<string> m_listInputMode;
	DECLARE_MESSAGE_MAP()
	ChannelParaController m_channelParaController;
	TestController m_testController;
	SensorController m_sensorController;
	std::vector<TbTestlocation> m_testLocationVec;
	std::vector<TbSensor> m_sensorVec;

public:
	virtual BOOL OnInitDialog();
	/**********************************************************************
	功能描述：通道参数表格的双击事件，双击设置可修改信息
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnGridEndEdit(NMHDR *pNotifyStruct, LRESULT* pResult);
	void GridCtrlInit();
	void GeneralComboInit();
	afx_msg void OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult);

};
