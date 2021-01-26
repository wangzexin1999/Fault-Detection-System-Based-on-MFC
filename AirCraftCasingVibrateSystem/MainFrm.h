

// MainFrm.h : CMainFrame 类的接口
#pragma once
#include "SystemParaView.h"
#include "ChannelParaView.h"
#include "AirCraftCasingVibrateSystemView.h"
#include <vector>
#include "GraphAttributeView.h"
#include "StateSetDockPanelView.h"
#include "CollectionPlanManageView.h"
#include "ProjectSetView.h"
#include "ProjectController.h"
#include "SmartArray.h"
#include "SignalController.h"
#include <map>
#include "JsonUtil.h"
#include "TbRecordSignal.h"
#include "UUIDUtil.h"
#include "TbSumsignal.h"
#include "ChannelController.h"

#include "TbSumsignalLabel.h"
#include"SumsignalLabelController.h"
#include "AlarmparaController.h"
#include "TbAlarmpara.h"
/////////////////////////////////////
#include "include/Inc/bdaqctrl.h"
#include "include/Inc/compatibility.h"
#include "DlgCom.h"
//////////////////////////////
#include "Common.h"
#include "DHTestHardWareController.h"

using namespace Automation::BDaq;
using namespace std;
/////////////////////////////////////

///刷新页面的自定义消息映射
#define  WM_REFRESHVIEW_BY_PROJECT (WM_USER+100)
//const int SHOW_CHANNEL_MEASURETYPE = 4; /// 通道测量类型
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

private:
	
	class CDlgCom * m_pComDialog;

protected:  // 控件条嵌入成员
	list<string> m_listSampleFreq;
	list<string> m_listChannelMeasure;
	//stuSampleParam m_SampleParam;
	// 采样线程句柄
	CWinThread	*m_pGetDataThread;
	bool m_bThread;
	//初始化仪器控制接口
	long InitInterface();
	//是否连接上仪器
	long IsConnectMachine();
	//取数线程
	static UINT GetDataThread(LPVOID pParam);
	//单台仪器数据
	static UINT GetOneMacDataThread(LPVOID pParam);
	//显示数据
	void OnShowSampleData(WPARAM wParam, LPARAM lParam);
	//初始化通道测点类型
	void InitMeasureType(long GroupChannelID, LPCTSTR strMachineIP, long ChannelStyle, long ChannelID, long CellID);
	CMFCRibbonBar     m_wndRibbonBar;
	CMFCRibbonApplicationButton m_MainButton;
	CMFCToolBarImages m_PanelImages;
	CMFCRibbonStatusBar  m_wndStatusBar;
	CMFCCaptionBar    m_wndCaptionBar;
	CMFCToolBar       m_wndContrlBar;
	vector<WaveformAiCtrl *> m_vwfAiCtrl;
	CGraphAttributeView m_graphAttributeView; // 图形属性界面

	SignalController m_signalController;

	std::mutex saveSignalMutex;

	ProjectController m_projectController;
	CSystemParaView    m_systemParaView;
	CChannelParaView    m_channelParaView;
	CStateSetDockPanelView m_stateSetDockPanelView;
	CDockablePane m_Panes[5];

	DHTestHardWareController m_dhTestHardWareController;

	map<CString, CAirCraftCasingVibrateSystemView*> m_mpsignalCollectionView;


	map<CString, ThreadSafeQueue<double>> m_mpcolllectioinDataQueue; ///采集的数据


	map<int, DOUBLE *> m_mpcolllectioinData;
	ICollection<DeviceTreeNode>* m_devices;
	//Value m_sampleFrequency;
	double m_sampleFrequency;
	//Value m_analysisFrequency;
	double m_analysisFrequency;
	int m_icollectionPoints;
	JsonUtil m_jsonUtil;
	Value m_channelInfo;
	Value m_collectionStatus;
	Document m_doc;
	TbRecordSignal m_recordSignal; // 采样数据
	TbSumsignalLabel m_sumsignalLabel;
	SumsignalLabelController m_sumsignalLabelController;
	
	ifstream m_inputStream;
	vector<ofstream>v_outputStream;
	TbRecordSignal m_selectedRecordSignal;
	bool m_bIsAnalyseFreMin = false;
	bool m_bIsAnalyseFreMax = false;
	int m_iAnalyseFreMax;
	int m_iAnalyseFreMin;
	ChannelController m_ChannelController;

	SignalTestRecordController m_SignalTestRecordController;
	vector<TbSignalTestRecord> m_vSignalTestRecord;
	AlarmparaController m_AlarmparaController;
	vector<TbAlarmpara> m_vAlarmpara;

	vector<CString> m_vchannelCodes;

	/**********************************************************************
	功能描述： 设置通道信息的json值
	***********************************************************************/
	void SetChannelInfoJsonValue();
	/**********************************************************************
	功能描述： 设置采集状态信息的json值
	***********************************************************************/
	void SetCollectionStatusJsonValue();
public:
	//liuxiu
	struct ChannelParam
	{
		int ChannelStyle;
		int ChannelID;
		int CellID;
	};
	bool m_bOneMacBuffer;
	int m_nInterface;
	int m_nInstrumentType;
	
	//获得通道信息
	void GetChannelParam(int nID, ChannelParam &ChanParam);
	//清空所有仪器通道
	void ClearAllGroupChannel();
	//刷新所有参数
	void RefreshAllParam();
	//获得目的参数信息
	void GetParamSelectValue();
	string GetMachineIP(int nGroupID);
	int BreakString(const string& strSrc, list<string>& lstDest, const string& strSeprator);

	int m_isampleFrequency; ///采样频率

	/**********************************************************************
	功能描述： 初始化采集窗口，将所有窗口存到vector中
	输入参数：nWindowInitial--窗口初始数
	***********************************************************************/
	void InitCaptureViewVector();


	/**********************************************************************
	功能描述： 初始化采样数据回显View
	输入参数：nWindowInitial--窗口初始数
	***********************************************************************/
	void InitializeSampleDataEchoView(int nWindowInitial);



	/**********************************************************************
	功能描述： 实时信号传输
	***********************************************************************/
	void CMainFrame::RealTimeSignal2Server();



	/**********************************************************************
	功能描述：新建文档
	***********************************************************************/
	void NewDoc(int nwinNums);//



	/**********************************************************************
	功能描述：创建采集窗口
	输入参数：传感器集合
	***********************************************************************/
	void CreateCaptureWindow(vector<TbChannel> vchannel);



	/**********************************************************************
	功能描述： 窗口纵向平铺
	***********************************************************************/
	void WindowsVertical();



	/**********************************************************************
	功能描述： 窗口横向平铺
	***********************************************************************/
	void WindowsHorizontal();



	/**********************************************************************
	功能描述： 关闭所有窗口
	***********************************************************************/
	void CloseAllWindows();




	/**********************************************************************
	功能描述： 自定义的 根据项目刷新视图的事件
	***********************************************************************/
	afx_msg LRESULT OnRefreshViewByProject(WPARAM wParam, LPARAM lParam);


	/**********************************************************************
	功能描述： 检查采集卡的错误信息
	***********************************************************************/
	void CheckError(ErrorCode error);



	/**********************************************************************
	功能描述： 开启线程自动保存采集数据的线程函数
	***********************************************************************/
	void OpenThread2SaveCollectionData();


	/**********************************************************************
	功能描述： 开启线程自动保存采集数据的线程函数
	***********************************************************************/
	void SaveSumCollectionData();
	
	/**********************************************************************
	功能描述： 开启线程从本地读取数据
	***********************************************************************/
	void GetDataFromlocal();
	void Pre_GetDataFromlocal();

	/**********************************************************************
	功能描述： 保存采集数据
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void SaveCollectionData(CString signalCode, TbSignal signal);

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
	//afx_msg void OnBtnCloseAllWindow();///关闭所有窗口
	afx_msg void OnSlider1();
	afx_msg void OnUpdateSlider1(CCmdUI *pCmdUI);
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
	//afx_msg void OnButton9();
	afx_msg void OnCheckStaSet();
	afx_msg void OnUpdateCheckStaSet(CCmdUI *pCmdUI);
	afx_msg void OnClose();

	/**********************************************************************
	功能描述： 打开采集计划管理窗口的按钮
	***********************************************************************/
	afx_msg void OnButtonOpenCollectionPlanManage();
	afx_msg void OnButtonOpenProjectView();
	afx_msg void OnButtonOpenProjectSetView();
	afx_msg void OnUpdateEditAnalyseFreMin(CCmdUI *pCmdUI);
	afx_msg void OnEditAnalyseFreMin();
	afx_msg void OnEditAnalyseFreMax();
	afx_msg void OnUpdateEditAnalyseFreMax(CCmdUI *pCmdUI);
	afx_msg void OnUpdateIdrRibbonI(CCmdUI *pCmdUI);
};


