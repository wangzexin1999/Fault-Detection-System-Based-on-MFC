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

// MainFrm.h : CMainFrame 类的接口
//

#pragma once
#include "SystemParaView.h"
#include "ChannelParaView.h"
#include "AirCraftCasingVibrateSystemView.h"
#include <vector>
#include "GraphAttributeView.h"
#include "StateSetDockPanelView.h"
#include "SignalController.h"
#include "CollectionPlanManageView.h"
#include "ProjectSetView.h"
#include "ProjectController.h"
#include "SmartArray.h"
#include "AdvantechDaqController.h"
#include <map>
/////////////////////////////////////
#include "include/Inc/bdaqctrl.h"
#include "include/Inc/compatibility.h"

using namespace Automation::BDaq;
using namespace std;
/////////////////////////////////////

///刷新页面的自定义消息映射
#define  WM_REFRESHVIEW_BY_PROJECT (WM_USER+100)

class CMainFrame : public CMDIFrameWndEx
{
	DECLARE_DYNAMIC(CMainFrame)
public:
	CMainFrame();

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CMFCRibbonBar     m_wndRibbonBar;
	CMFCRibbonApplicationButton m_MainButton;
	CMFCToolBarImages m_PanelImages;
	CMFCRibbonStatusBar  m_wndStatusBar;
	CMFCCaptionBar    m_wndCaptionBar;
	CMFCToolBar       m_wndContrlBar;

	vector<WaveformAiCtrl *> m_vwfAiCtrl;
	CGraphAttributeView m_graphAttributeView; // 图形属性界面
	SignalController m_signalController;
	ProjectController m_projectController;
	CSystemParaView    m_systemParaView;
	CChannelParaView    m_channelParaView;
	CStateSetDockPanelView m_stateSetDockPanelView;
	CDockablePane m_Panes[5];  
	vector<CString> m_vchannelIds; 
	map<CString, CAirCraftCasingVibrateSystemView*> m_mpsignalCollectionView;
	map<CString, ThreadSafeQueue<double>> m_mpcolllectioinDataQueue; ///采集的数据
	map<int, DOUBLE *> m_mpcolllectioinData;
	map<int, DevConfParam> m_vdevConfParams;
	ICollection<DeviceTreeNode>* m_devices;
	AdvantechDaqController m_advantechDaqController;
public:
	/**********************************************************************
	功能描述： 初始化采集窗口，将所有窗口存到vector中
	输入参数：nWindowInitial--窗口初始数
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void InitCaptureViewVector();
	/**********************************************************************
	 功能描述： 初始化采样数据回显View
	 输入参数：nWindowInitial--窗口初始数
	 输出参数： 
	 返 回 值： 
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void InitializeSampleDataEchoView(int nWindowInitial);
	/**********************************************************************
	 功能描述： 实时信号传输
	 输入参数：
	 输出参数：
	 返 回 值：
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void CMainFrame::RealTimeSignal2Server();
	/**********************************************************************
	 功能描述：新建文档
	 输入参数：nwinNums--新建文档的数目
	 输出参数： 
	 返 回 值： 
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void NewDoc(int nwinNums);//

	/**********************************************************************
	功能描述：创建采集窗口
	输入参数：传感器集合
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void CreateCaptureWindow(vector<TbSensor> vsensor);
	/**********************************************************************
	 功能描述： 窗口纵向平铺
	 输入参数：
	 输出参数： 
	 返 回 值： 
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void WindowsVertical();
	/**********************************************************************
	 功能描述： 窗口横向平铺
	 输入参数：
	 输出参数： 
	 返 回 值： 
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void WindowsHorizontal();
	/**********************************************************************
	 功能描述： 关闭所有窗口
	 输入参数：
	 输出参数： 
	 返 回 值： 
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void CloseAllWindows();
	/**********************************************************************
	功能描述： 自定义的 根据项目刷新视图的事件
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg LRESULT OnRefreshViewByProject(WPARAM wParam, LPARAM lParam);

	/**********************************************************************
	功能描述： 自定义的 数据准备好的响应事件
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	static void BDAQCALL OnDataReadyEvent(void * sender, BfdAiEventArgs * args, void *userParam);


	/**********************************************************************
	功能描述： 检查采集卡的错误信息
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void CheckError(ErrorCode error);
	/**********************************************************************
	功能描述： 开启线程自动保存采集数据的线程函数
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void OpenThread2SaveCollectionData();

	/**********************************************************************
	功能描述： 自动保存采集数据的线程函数
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void AutoSaveCollectionData();
	/**********************************************************************
	功能描述： 保存采集数据
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void SaveCollectionData(map<CString, ThreadSafeQueue<double>> & acquireSignal);

	/**********************************************************************
	功能描述： 保存采集数据
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void GetInstalledDevices(ICollection<DeviceTreeNode> *& devices);
	/**********************************************************************
	功能描述： 得到所有通道
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void GetChannels(vector<CString> & channels);


	afx_msg LRESULT OnStatusInf(WPARAM wParam, LPARAM lParam); // 自定义状态信息改变消息
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnWindowManager();
	afx_msg void OnApplicationLook(UINT id);
	afx_msg void OnUpdateApplicationLook(CCmdUI* pCmdUI);
	afx_msg void OnViewCaptionBar();
	afx_msg void OnUpdateViewCaptionBar(CCmdUI* pCmdUI);
	afx_msg void OnOptions();
	afx_msg void OnButtonNewProject(); ///新建项目
	afx_msg void OnButtonProjectManage(); ///项目管理
	afx_msg void OnButtonOpenDataFile();///打开数据文件

	afx_msg void OnButtonExportChannelPara(); ///导出通道参数
	afx_msg void OnButtonImportChannelPara(); ///导入通道参数
	afx_msg void OnButtonExportSysPara(); ///导出系统参数
	afx_msg void OnButtonImportSysPara(); ///导入系统参数
	afx_msg void OnButtonSuspendCapture();///暂停采集
	afx_msg void OnButtonStartCapture();///开始采集
	afx_msg void OnBtnStopCapture(); ///停止采集
	afx_msg void OnBtnStartPlayback();///开始回放 
	afx_msg void OnBtnStopPlayback(); ///停止回放
	afx_msg void OnBtnCloseAllWindow();///关闭所有窗口

	afx_msg void OnBtnStartSmaple();///开始采样 
	afx_msg void OnBtnStopSample();///停止采样
	afx_msg void OnBtnEngineeringUnit();///工程单位
	afx_msg void OnBtnAlarmSet();///报警设置
	afx_msg void OnButtonProduct();///产品

	afx_msg void OnBtnTransverseAmplification();
	afx_msg void OnBtnHorizontalReduction(); ///横向缩小
	afx_msg void OnBtnVerticalReduction();///竖向缩小 
	afx_msg void OnBtnVerticalAmplification();///竖向扩大
	afx_msg void OnBtnSingleCursor();///单光标
	afx_msg void OnBtnPeakValue();///峰值
	afx_msg void OnBtnAutoScale();///自动刻度 
	afx_msg void OnBtnDefaultScale();///默认刻度
	afx_msg void OnBtnNoCorror();///无光标
	afx_msg LRESULT OnSetText(WPARAM wParam, LPARAM lParam);///修改程序标题的响应事件

	DECLARE_MESSAGE_MAP()
	BOOL CreateCaptionBar();
public:
	// 通道参数的隐藏或显示
	afx_msg void OnViewChannelPara();
	afx_msg void OnUpdateViewChannelPara(CCmdUI* pCmdUI);
	// 系统参数隐藏或显示
	afx_msg void OnViewSystemPara();
	afx_msg void OnUpdateViewSystemPara(CCmdUI* pCmdUI);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBtnGraphAttribute();//图形属性
	afx_msg void OnButton9();
	afx_msg void OnCheckStaSet();
	afx_msg void OnUpdateCheckStaSet(CCmdUI *pCmdUI);
	afx_msg void OnClose();

	/**********************************************************************
	功能描述： 打开采集计划管理窗口的按钮
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期    版本号 修改人 修改内容
	2019-10-07  1.0   马善涛  新创建
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnButtonOpenCollectionPlanManage();
	afx_msg void OnButtonOpenProjectView();
	afx_msg void OnButtonOpenProjectSetView();
};


