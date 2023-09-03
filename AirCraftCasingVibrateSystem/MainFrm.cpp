

// MainFrm.cpp : CMainFrame 类的实现

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "NewProjectView.h"
#include "MainFrm.h"
#include "OpenProjectView.h"
#include "SignalDataView.h"
#include "EngineerUnitView.h"
#include "DetectDeviceManageView.h"
#include "ProductManageView.h"
#include "AlarmParaSetView.h"
#include "ChartCtrl/DuChartCtrlStaticFunction.h"
#include "FileUtil.h"
#include "Constant.h"
#include "EchoSignal.h"
#include "ProjectController.h"
#include "FFTWUtil.h"
#include "ChildRibbonPanel.h"
#include "TbSumsignal.h"
#include "AirCraftCasingVibrateSystemView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#define M_PI       3.14159265358979323846   // pi
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWndEx)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWndEx)
	ON_WM_CREATE()
	ON_COMMAND(ID_WINDOW_MANAGER, &CMainFrame::OnWindowManager)
	ON_COMMAND_RANGE(ID_VIEW_APPLOOK_WIN_2000, ID_VIEW_APPLOOK_WINDOWS_7, &CMainFrame::OnApplicationLook)
	ON_UPDATE_COMMAND_UI_RANGE(ID_VIEW_APPLOOK_WIN_2000, ID_VIEW_APPLOOK_WINDOWS_7, &CMainFrame::OnUpdateApplicationLook)
	ON_COMMAND(ID_VIEW_CAPTION_BAR, &CMainFrame::OnViewCaptionBar)
	ON_UPDATE_COMMAND_UI(ID_VIEW_CAPTION_BAR, &CMainFrame::OnUpdateViewCaptionBar)
	ON_COMMAND(ID_TOOLS_OPTIONS, &CMainFrame::OnOptions)
	ON_COMMAND(ID_VIEW_CHANNELPARA_BAR, &CMainFrame::OnViewChannelPara)
	ON_UPDATE_COMMAND_UI(ID_VIEW_CHANNELPARA_BAR, &CMainFrame::OnUpdateViewChannelPara)
	ON_COMMAND(ID_VIEW_SYSTEMPARA_BAR, &CMainFrame::OnViewSystemPara)
	ON_UPDATE_COMMAND_UI(ID_VIEW_SYSTEMPARA_BAR, &CMainFrame::OnUpdateViewSystemPara)
	ON_COMMAND(ID_BUTTON_NEW_PROJECT, &CMainFrame::OnButtonNewProject)
	ON_COMMAND(ID_BUTTON_PROJECT_MANAGE, &CMainFrame::OnButtonProjectManage)
	ON_COMMAND(ID_BUTTON_OPEN_DATA_FILE, &CMainFrame::OnButtonOpenDataFile)

	ON_COMMAND(ID_BUTTON_EXPORT_CHANNEL_PARA, &CMainFrame::OnButtonExportChannelPara)
	ON_COMMAND(ID_BUTTON_IMPORT_CHANNEL_PARA, &CMainFrame::OnButtonImportChannelPara)
	ON_COMMAND(ID_BUTTON_EXPORT_SYS_PARA, &CMainFrame::OnButtonExportSysPara)
	ON_COMMAND(ID_BUTTON_IMPORT_SYS_PARA, &CMainFrame::OnButtonImportSysPara)
	ON_COMMAND(ID_BUTTON_SUSPEND_CAPTURE, &CMainFrame::OnButtonSuspendCapture)
	ON_COMMAND(ID_BUTTON_START_CAPTURE, &CMainFrame::OnButtonStartCapture)
	ON_COMMAND(ID_BTN_STOP_CAPTURE, &CMainFrame::OnBtnStopCapture)
	ON_COMMAND(ID_BTN_STOP_PLAYBACK, &CMainFrame::OnBtnStopPlayback)
	ON_COMMAND(ID_BTN_START_PLAYBACK, &CMainFrame::OnBtnStartPlayback)
	//ON_COMMAND(ID_SLIDER1, &CMainFrame::OnSlider1)
	ON_UPDATE_COMMAND_UI(ID_SLIDER1, &CMainFrame::OnUpdateSlider1)

	//ON_COMMAND(ID_BTN_CLOSE_ALL_WINDOW, &CMainFrame::OnBtnCloseAllWindow)

	ON_COMMAND(ID_BTN_START_SMAPLE, &CMainFrame::OnBtnStartSmaple)
	ON_COMMAND(ID_BTN_STOP_SAMPLE, &CMainFrame::OnBtnStopSample)
	ON_COMMAND(ID_BTN_PROJECT_UNIT, &CMainFrame::OnBtnEngineeringUnit)
	ON_COMMAND(ID_BTN_ALARM_SET, &CMainFrame::OnBtnAlarmSet)

	ON_COMMAND(ID_BUTTON_DETECTED_DEVICE, &CMainFrame::OnButtonProduct)

	ON_COMMAND(ID_BTN_TRANSVERSE_AMPLIFICATION, &CMainFrame::OnBtnTransverseAmplification)
	ON_COMMAND(ID_BTN_HORIZONTAL_REDUCTION, &CMainFrame::OnBtnHorizontalReduction)
	ON_COMMAND(ID_BTN_VERTICAL_REDUCTION, &CMainFrame::OnBtnVerticalReduction)
	ON_COMMAND(ID_BTN_VERTICAL_AMPLIFICATION, &CMainFrame::OnBtnVerticalAmplification)
	ON_COMMAND(ID_BTN_SINGLE_CURSOR, &CMainFrame::OnBtnSingleCursor)
	ON_COMMAND(ID_BTN_PEAK_VALUE, &CMainFrame::OnBtnPeakValue)
	ON_COMMAND(ID_BTN_AUTO_SCALE, &CMainFrame::OnBtnAutoScale)
	ON_COMMAND(ID_BTN_SELF_SCALE, &CMainFrame::OnBtnDefaultScale)
	ON_COMMAND(ID_BTN_NO_CORROR, &CMainFrame::OnBtnNoCorror)
	ON_WM_TIMER()
	ON_COMMAND(ID_BTN_GRAPH_ATTR, &CMainFrame::OnBtnGraphAttribute)
	//ON_COMMAND(ID_BUTTON9, &CMainFrame::OnButton9)
	ON_COMMAND(ID_CHECK_STA_SET, &CMainFrame::OnCheckStaSet)
	ON_UPDATE_COMMAND_UI(ID_CHECK_STA_SET, &CMainFrame::OnUpdateCheckStaSet)
	ON_WM_CLOSE()
	ON_COMMAND(ID_BUTTON_OPENCOLLECTIONPLANMANAGE, &CMainFrame::OnButtonOpenCollectionPlanManage)
	ON_COMMAND(ID_BUTTON_OPENPROJECTVIEW, &CMainFrame::OnButtonOpenProjectView)
	ON_COMMAND(ID_BUTTON_OPEN_PROJECTSET_VIEW, &CMainFrame::OnButtonOpenProjectSetView)
	///消息
	ON_MESSAGE(StatusInfMessage, OnStatusInf)
	ON_MESSAGE(WM_REFRESHVIEW_BY_PROJECT, &CMainFrame::OnRefreshViewByProject)
	ON_MESSAGE(WM_SETTEXT, &CMainFrame::OnSetText)
	//ON_UPDATE_COMMAND_UI(ID_EDIT_ANALYSE_FRE_MIN, &CMainFrame::OnUpdateEditAnalyseFreMin)
	ON_COMMAND(ID_EDIT_ANALYSE_FRE_MIN, &CMainFrame::OnEditAnalyseFreMin)
	ON_COMMAND(ID_EDIT_ANALYSE_FRE_MAX, &CMainFrame::OnEditAnalyseFreMax)
	//ON_UPDATE_COMMAND_UI(ID_EDIT_ANALYSE_FRE_MAX, &CMainFrame::OnUpdateEditAnalyseFreMax)
	ON_UPDATE_COMMAND_UI_RANGE(ID_BUTTON_START_CAPTURE, ID_BTN_STOP_SAMPLE, &CMainFrame::OnUpdateIdrRibbonI)
END_MESSAGE_MAP()

// CMainFrame 构造/析构

int tempCount = 0;
extern TCHAR const * WCHAR_TO_TCHAR(WCHAR const * in, TCHAR * out);
CMainFrame::CMainFrame()
{
	theApp.m_nAppLook = theApp.GetInt(_T("ApplicationLook"), ID_VIEW_APPLOOK_WINDOWS_7);
	this->m_bAutoMenuEnable = false;
	
	m_pComDialog = new CDlgCom();
	m_pComDialog->Create(IDD_DIALOG_COM, this);
	m_pComDialog->ShowWindow(SW_HIDE);

	theApp.m_pHardWare = &m_pComDialog->m_DHHardWare;

	long nResultValue = 0;

	theApp.m_pHardWare->PrepareInit(1);//设置3817J仪器类型 	
	m_bOneMacBuffer = false;
	if (!InitInterface())
	{
		AfxMessageBox(LPCTSTR("初始化接口失败!"));
	}

	//建立连接
	long lReturnValue;
	//初始化采集窗口
	//InitCaptureViewVector();//改正
	theApp.m_pHardWare->ReConnectAllMac(&lReturnValue);//连接在DeviceInfo.ini文件的IP的仪器。
	//liuxiu
	/*if (!IsConnectMachine())
	{
		AfxMessageBox(LPCTSTR("仪器未连接!无法打开程序"));
		theApp.deviceIsOnline = false;
	}*/

	m_dhTestHardWareController.GetAllGroupChannel(theApp.m_pHardWare, theApp.m_vecGroupChannel,theApp.m_vecHardChannel);
	m_dhTestHardWareController.GetAllInputMode(theApp.m_pHardWare, theApp.m_vecHardChannel, theApp.m_vecHardChannel[0].m_strMachineIP, theApp.m_listInputMode);
	m_dhTestHardWareController.GetAllElcPressure(theApp.m_pHardWare, theApp.m_vecHardChannel, theApp.m_vecHardChannel[0].m_strMachineIP, theApp.m_elcpressure);
	m_dhTestHardWareController.GetAllFullValue(theApp.m_pHardWare, theApp.m_vecHardChannel, theApp.m_vecHardChannel[0].m_strMachineIP, theApp.m_listFullValue);
	m_dhTestHardWareController.GetAllUpFreq(theApp.m_pHardWare, theApp.m_vecHardChannel, theApp.m_vecHardChannel[0].m_strMachineIP, theApp.m_listUpFreq);
	m_dhTestHardWareController.GetAllMessaueType(theApp.m_pHardWare, theApp.m_vecHardChannel, theApp.m_vecHardChannel[0].m_strMachineIP, theApp.m_listMessaueType);
	m_dhTestHardWareController.GetSampleFreqList(theApp.m_pHardWare, theApp.m_vecHardChannel,theApp.m_listSampleFreq);

	//AcquireResult();
	//InitSampleClock();//绑定时钟 1.内部时钟2.外部时钟
	//除通道信息外获取所有参数
	//RefreshAllParam();//<------------------
	/*for (int i = 0; i < theApp.m_vecGroupChannel.size(); i++)
	{
	CString cstr;
	cstr.Format("%d号机 ", theApp.m_vecGroupChannel[i].m_GroupID + 1);
	}*/
	//SetWindowText(str);
	//m_Btnjs.EnableWindow(FALSE);
	//m_Btnxh.EnableWindow(FALSE);
	//return ;  // 除非将焦点设置到控件，否则返回 TRUE
}

CMainFrame::~CMainFrame(){

}
//初始化仪器控制接口
long CMainFrame::InitInterface()
{

	TCHAR cPath[MAX_PATH];
	GetModuleFileName(NULL, cPath, MAX_PATH);
	CString  strPath = ".\\COM";
	//strPath = strPath.Left(strPath.ReverseFind('\\'));

	strPath += "\\Config\\";
	CString strCfgpath = strPath + "HardWareCfg.ini";

	m_nInterface = GetPrivateProfileInt("SystemParameter", "InterfaceType", 4, strCfgpath);
	m_nInstrumentType = GetPrivateProfileInt("SystemParameter", "InstrumentType", 27, strCfgpath);

	m_bOneMacBuffer = GetPrivateProfileInt("SystemParameter", "OneMacBuffer", 0, strCfgpath);
	long lReturnValue ;
	//初始化仪器控制接口
	theApp.m_pHardWare->Init(LPCTSTR(strPath), LPCTSTR("chinese"), &lReturnValue);
	//GetParamSelectValue();//获取通道测量类型
	RedisHandel();
	//InitRedisDatabase();
	return lReturnValue;
}
//检查仪器是否连接
long CMainFrame::IsConnectMachine()
{
	long lReturnValue;
	theApp.m_pHardWare->IsConnectMachine(&lReturnValue);
	return lReturnValue;
}

//释放内存
void CMainFrame::ClearAllGroupChannel()
{
	theApp.m_vecGroupChannel.clear();
	theApp.m_vecHardChannel.clear();
}

//除通道信息外获取所有参数
//void CMainFrame::RefreshAllParam(){
//	GetParamSelectValue();//获取通道测量类型
//	int nCurSel = 0;//m_ComboChannel.GetCurSel();//获取当前通道列表
//	if (nCurSel < 0)
//		return;
//
//	CString strText="1-3";
//	CString strGroupID = strText.Left(strText.ReverseFind('-'));
//	long lGroupID = atol(strGroupID);
//	lGroupID -= 1;
//	CString strChannelID = strText.Mid(strText.ReverseFind('-') + 1);
//	long lChannelID = atol(strChannelID);
//	lChannelID -= 1;
//
//	string strMachineIP = GetMachineIP(int(lGroupID));
//
//	ChannelParam ChanParam;
//	GetChannelParam(int(lChannelID), ChanParam);
//
//	InitMeasureType(lGroupID, strMachineIP.data(), ChanParam.ChannelStyle, ChanParam.ChannelID, ChanParam.CellID);
//}
//初始化通道测量类型
void CMainFrame::InitMeasureType(long GroupChannelID, LPCTSTR strMachineIP, long ChannelStyle, long ChannelID, long CellID)
{
	//m_ComboMeasureType.ResetContent();

	BSTR *strValue = new BSTR();
	//获取参数值
	theApp.m_pHardWare->GetParamValue(GroupChannelID, strMachineIP, ChannelStyle, ChannelID, CellID, theApp.SHOW_CHANNEL_MEASURETYPE, strValue);
	char *pTmpData = _com_util::ConvertBSTRToString(*strValue);
	string strCurValue = pTmpData;
	delete pTmpData;

	int nCount = 0;
	int nSel = -1;

	/*for (list<string>::iterator it = m_listChannelMeasure.begin(); it != m_listChannelMeasure.end(); it++)
	{
		string strText = *it;
		m_ComboMeasureType.AddString(strText.data());
		if (strcmp(strCurValue.data(), strText.data()) == 0)
		{
			nSel = nCount;
		}
		nCount++;
	}
	if (nSel >= 0)
	{
		m_ComboMeasureType.SetCurSel(nSel);
	}*/

	delete strValue;
}

//获取通道参数
//ChannelStyle1 –控制卡转速数据，4 – GPS数据||通道风格(模拟通道)
void CMainFrame::GetChannelParam(int nID, ChannelParam &ChanParam)
{
	for (int i = 0; i < theApp.m_vecHardChannel.size(); i++)
	{
		int nChannelID = theApp.m_vecHardChannel[i].m_nChannelID;
		if (nChannelID == nID)
		{
			ChanParam.ChannelStyle = theApp.m_vecHardChannel[i].m_nChannelStyle;
			ChanParam.ChannelID = nChannelID;
			ChanParam.CellID = theApp.m_vecHardChannel[i].m_nCellID;// CellID – 单元ID(一个通道分成多个单元)
		}
	}
}
//获取仪器ID
string CMainFrame::GetMachineIP(int nID)
{
	string strMachineIP;
	for (int i = 0; i < theApp.m_vecHardChannel.size(); i++)
	{
		int nGroupID = theApp.m_vecHardChannel[i].m_nChannelGroupID;
		if (nGroupID == nID)
		{
			strMachineIP = theApp.m_vecHardChannel[i].m_strMachineIP;
		}
	}
	return strMachineIP;
}
//初始化通道测量类型
void CMainFrame::GetParamSelectValue()
{
	CString strText;
	int nCurSel = 0;//m_ComboChannel.GetCurSel();
	if (nCurSel < 0)
		return;
	strText = "1-3";
	//m_ComboChannel.GetLBText(nCurSel, strText);
	CString strGroupID = strText.Left(strText.ReverseFind('-'));
	long lGroupID = atol(strGroupID);
	lGroupID -= 1;
	CString strChannelID = strText.Mid(strText.ReverseFind('-') + 1);
	long lChannelID = atol(strChannelID);
	lChannelID -= 1;

	string strMachineIP = GetMachineIP(int(lGroupID));

	ChannelParam ChanParam;
	GetChannelParam(int(lChannelID), ChanParam);

	BSTR *strSelectValue = new BSTR();

	//获取参数可选项列表
	theApp.m_pHardWare->GetParamSelectValue(lGroupID, strMachineIP.data(), ChanParam.ChannelStyle, ChanParam.ChannelID, ChanParam.CellID, theApp.SHOW_CHANNEL_MEASURETYPE, strSelectValue);
	char *pTempData = _com_util::ConvertBSTRToString(*strSelectValue);
	string strMeasureTypeSelect = pTempData;
	int nMeasureTypeCount = BreakString(strMeasureTypeSelect, m_listChannelMeasure, string("|"));
	delete pTempData;

	delete strSelectValue;
}
//将字符串进行分解。strSeprator中的任何一个字符都作为分隔符。返回分节得到的字符串数目
int CMainFrame::BreakString(const string& strSrc, list<string>& lstDest, const string& strSeprator)
{
	//清空列表
	lstDest.clear();
	//个数
	int iCount = 0;

	if (strSeprator.length() == 0)
	{
		lstDest.push_back(strSrc);
		iCount = 1;
		return iCount;
	}

	//查找的位置
	std::string::size_type iPos = 0;
	while (iPos < strSrc.length())
	{
		std::string::size_type iNewPos = strSrc.find_first_of(strSeprator, iPos);
		//当前字符即分隔符
		if (iNewPos == iPos)
		{
			iPos++;
		}
		//没找到分隔符
		else if (iNewPos == std::string::npos)
		{
			lstDest.push_back(strSrc.substr(iPos, strSrc.length() - iPos));
			iCount++;
			iPos = strSrc.length();
		}
		//其它
		else
		{
			lstDest.push_back(strSrc.substr(iPos, iNewPos - iPos));
			iCount++;
			iPos = iNewPos;
			iPos++;
		}
	}

	return iCount;
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWndEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	BOOL bNameValid;

	m_wndRibbonBar.Create(this);
	m_wndRibbonBar.LoadFromResource(IDR_RIBBON);

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	// 设置默认显示的类别
	m_wndRibbonBar.SetActiveCategory(m_wndRibbonBar.GetCategory(3));
	CString strTitlePane1;
	CString strTitlePane2;
	bNameValid = strTitlePane1.LoadString(IDS_STATUS_PANE1);
	ASSERT(bNameValid);
	bNameValid = strTitlePane2.LoadString(IDS_STATUS_PANE2);
	ASSERT(bNameValid);
	m_wndStatusBar.AddElement(new CMFCRibbonStatusBarPane(ID_STATUSBAR_PANE1, "目前状态", TRUE), "目前状态");
	m_wndStatusBar.AddExtendedElement(new CMFCRibbonStatusBarPane(ID_STATUSBAR_PANE2, "当前时间:00:00:00", TRUE), strTitlePane2);

	//测试加入按钮
	CMFCRibbonCategory *pCategory = m_wndRibbonBar.GetCategory(3);
	CMFCRibbonPanel *pPanel = pCategory->GetPanel(5);
	/*显示当前用的传感器*/
	vector<TbChannel> vChannel = theApp.m_currentProject.GetChannelVector();
	for (int i = 0; i < vChannel.size(); i++)
	{
		pPanel->Add(new CMFCRibbonButton(i + 10000, _T(vChannel[i].GetChannelDesc()), 3, -1));
	}



	if (!m_systemParaView.Create(_T("系统参数"), this, CRect(0, 0, 200, 100), TRUE, 10000,
		WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS |
		WS_CLIPCHILDREN | CBRS_LEFT | CBRS_FLOAT_MULTI))
	{
		return FALSE;
	}

	if (!m_stateSetDockPanelView.Create(_T("状态设置"), this, CRect(0, 0, 200, 100), TRUE, 10034,
		WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS |
		WS_CLIPCHILDREN | CBRS_LEFT | CBRS_FLOAT_MULTI)) //CBRS_RIGHT
	{
		return FALSE;
	}


	if (!m_channelParaView.Create(_T("通道参数"), this, CRect(0, 0, 200, 100), TRUE, 10033,
		WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS |
		WS_CLIPCHILDREN | CBRS_BOTTOM | CBRS_FLOAT_MULTI))
	{
		return FALSE;
	}

	m_systemParaView.EnableDocking(CBRS_ALIGN_ANY);
	m_channelParaView.EnableDocking(CBRS_ALIGN_ANY);
	m_stateSetDockPanelView.EnableDocking(CBRS_ALIGN_ANY);
	DockPane(&m_channelParaView);// BOTTOM
	DockPane(&m_systemParaView);// LEFT
	DockPane(&m_stateSetDockPanelView);// RIGHT
	// 启用 Visual Studio 2005 样式停靠窗口行为
	CDockingManager::SetDockingMode(DT_SMART);
	// 启用 Visual Studio 2005 样式停靠窗口自动隐藏行为
	EnableAutoHidePanes(CBRS_ALIGN_ANY);

	// 创建标题栏: 
	if (!CreateCaptionBar())
	{
		TRACE0("未能创建标题栏\n");
		return -1;      // 未能创建
	}
	// 基于持久值设置视觉管理器和样式
	OnApplicationLook(theApp.m_nAppLook);

	// 启用增强的窗口管理对话框
	EnableWindowsDialog(ID_WINDOW_MANAGER, ID_WINDOW_MANAGER, TRUE);
	SendMessage(WM_SETTEXT);

	HBITMAP hBmpAnimationList = NULL;
	COLORREF clrTrnsp = RGB(255, 0, 0);

	//设置状态栏的字体
	CFont* fontstatus = new CFont;
	fontstatus->CreateFont(15, 0, 0, 0, FW_BOLD, FALSE, FALSE, 0, GB2312_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_MODERN, _T("黑体"));
	m_wndStatusBar.SetFont(fontstatus);

	m_wndStatusBar.AddElement(new CMFCRibbonStatusBarPane(10000, _T(""), hBmpAnimationList, clrTrnsp), _T("参数状态"));
	SendMessage(StatusInfMessage);
	/*状态栏显示时间*/
	SetTimer(66, 1000, NULL);//安装定时器，并将其时间间隔设为1000毫秒
	//m_pMenu = GetMenu();
	//////将暂停采集、结束采集、结束采样、开始采样置灰
	//m_pMenu->EnableMenuItem(ID_BUTTON_SUSPEND_CAPTURE, MF_BYCOMMAND | MF_GRAYED);
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CMDIFrameWndEx::PreCreateWindow(cs))
		return FALSE;
	//  CREATESTRUCT cs 来修改窗口类或样式
	return TRUE;
}

BOOL CMainFrame::CreateCaptionBar()
{
	if (!m_wndCaptionBar.Create(WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS, this, ID_VIEW_CAPTION_BAR, -1, TRUE))
	{
		TRACE0("未能创建标题栏\n");
		return FALSE;
	}

	BOOL bNameValid;

	CString strTemp, strTemp2;
	bNameValid = strTemp.LoadString(IDS_CAPTION_BUTTON);
	ASSERT(bNameValid);
	m_wndCaptionBar.SetButton(strTemp, ID_TOOLS_OPTIONS, CMFCCaptionBar::ALIGN_LEFT, FALSE);
	bNameValid = strTemp.LoadString(IDS_CAPTION_BUTTON_TIP);
	ASSERT(bNameValid);
	m_wndCaptionBar.SetButtonToolTip(strTemp);

	bNameValid = strTemp.LoadString(IDS_CAPTION_TEXT);
	ASSERT(bNameValid);
	m_wndCaptionBar.SetText(strTemp, CMFCCaptionBar::ALIGN_LEFT);

	m_wndCaptionBar.SetBitmap(IDB_INFO, RGB(255, 255, 255), FALSE, CMFCCaptionBar::ALIGN_LEFT);
	bNameValid = strTemp.LoadString(IDS_CAPTION_IMAGE_TIP);
	ASSERT(bNameValid);
	bNameValid = strTemp2.LoadString(IDS_CAPTION_IMAGE_TEXT);
	ASSERT(bNameValid);
	m_wndCaptionBar.SetImageToolTip(strTemp, strTemp2);

	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWndEx::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWndEx::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序

void CMainFrame::OnWindowManager()
{
	ShowWindowsDialog();
}

void CMainFrame::OnApplicationLook(UINT id)
{
	CWaitCursor wait;

	theApp.m_nAppLook = id;

	switch (theApp.m_nAppLook)
	{
	case ID_VIEW_APPLOOK_WIN_2000:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManager));
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_OFF_XP:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOfficeXP));
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_WIN_XP:
		CMFCVisualManagerWindows::m_b3DTabsXPTheme = TRUE;
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_OFF_2003:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2003));
		CDockingManager::SetDockingMode(DT_SMART);
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_VS_2005:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2005));
		CDockingManager::SetDockingMode(DT_SMART);
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_VS_2008:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2008));
		CDockingManager::SetDockingMode(DT_SMART);
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_WINDOWS_7:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows7));
		CDockingManager::SetDockingMode(DT_SMART);
		m_wndRibbonBar.SetWindows7Look(TRUE);
		break;

	default:
		switch (theApp.m_nAppLook)
		{
		case ID_VIEW_APPLOOK_OFF_2007_BLUE:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_LunaBlue);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_BLACK:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_ObsidianBlack);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_SILVER:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_Silver);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_AQUA:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_Aqua);
			break;
		}

		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2007));
		CDockingManager::SetDockingMode(DT_SMART);
		m_wndRibbonBar.SetWindows7Look(FALSE);
	}

	RedrawWindow(NULL, NULL, RDW_ALLCHILDREN | RDW_INVALIDATE | RDW_UPDATENOW | RDW_FRAME | RDW_ERASE);

	theApp.WriteInt(_T("ApplicationLook"), theApp.m_nAppLook);
}

void CMainFrame::OnUpdateApplicationLook(CCmdUI* pCmdUI)
{
	pCmdUI->SetRadio(theApp.m_nAppLook == pCmdUI->m_nID);
}

void CMainFrame::OnViewCaptionBar()
{
	m_wndCaptionBar.ShowWindow(m_wndCaptionBar.IsVisible() ? SW_HIDE : SW_SHOW);
	RecalcLayout(FALSE);
}

void CMainFrame::OnUpdateViewCaptionBar(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_wndCaptionBar.IsVisible());
}

void CMainFrame::OnOptions()
{
	CMFCRibbonCustomizeDialog *pOptionsDlg = new CMFCRibbonCustomizeDialog(this, &m_wndRibbonBar);
	ASSERT(pOptionsDlg != NULL);

	pOptionsDlg->DoModal();
	delete pOptionsDlg;
}

////初始化采集窗口vector
void CMainFrame::InitCaptureViewVector(){
	///1.清空采集窗口的集合
	theApp.m_vsignalCaptureView.clear();
	///2.重新初始化采集窗口集合
	POSITION curTemplatePos = theApp.GetFirstDocTemplatePosition();
	CDocTemplate *m_doc = theApp.GetNextDocTemplate(curTemplatePos);
	//获得文档:
	curTemplatePos = m_doc->GetFirstDocPosition();
	int viewNumber = 0;
	TbChannel channel;
	while (curTemplatePos != NULL){
		CAirCraftCasingVibrateSystemDoc * pdoc = (CAirCraftCasingVibrateSystemDoc*)m_doc->GetNextDoc(curTemplatePos);
		//获得视图:
		POSITION curViewPos;
		curViewPos = pdoc->GetFirstViewPosition();
		while (curViewPos != NULL)
		{
			CAirCraftCasingVibrateSystemView* currentView = (CAirCraftCasingVibrateSystemView*)pdoc->GetNextView(curViewPos);
			currentView->SetViewNumber(viewNumber);
			currentView->ResetView();
			theApp.m_vsignalCaptureView.push_back(currentView);
			currentView->GetChannel(channel);
			m_mpsignalCollectionView[channel.GetChannelCode()] = currentView;//问题

		}
		viewNumber++;
	}
}

void CMainFrame::InitializeSampleDataEchoView(int nWindowInitial)
{
	// 显示
	POSITION curTemplatePos = theApp.GetFirstDocTemplatePosition();
	CDocTemplate *m_doc = theApp.GetNextDocTemplate(curTemplatePos);
	//获得文档:
	curTemplatePos = m_doc->GetFirstDocPosition();
	int viewNumber = nWindowInitial;
	while (curTemplatePos != NULL){
		CAirCraftCasingVibrateSystemDoc * pdoc = (CAirCraftCasingVibrateSystemDoc*)m_doc->GetNextDoc(curTemplatePos);
		//获得视图:
		POSITION curViewPos;
		curViewPos = pdoc->GetFirstViewPosition();
		while (curViewPos != NULL)
		{
			CAirCraftCasingVibrateSystemView* currentView = (CAirCraftCasingVibrateSystemView*)pdoc->GetNextView(curViewPos);
			currentView->SetSampleDataEchoTimerNum(viewNumber);
			currentView->ResetView();
			theApp.m_vsignalCaptureView.push_back(currentView);
		}
		viewNumber++;
	}
}

////通道参数
void CMainFrame::OnViewChannelPara()
{
	if (m_channelParaView.IsVisible())
	{
		m_channelParaView.ShowPane(FALSE, FALSE, FALSE);
	}
	else
	{
		m_channelParaView.ShowPane(TRUE, TRUE, TRUE);
	}

	RecalcLayout(FALSE);
}

void CMainFrame::OnUpdateViewChannelPara(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_channelParaView.IsVisible());
}


void CMainFrame::OnViewSystemPara()
{
	if (m_systemParaView.IsVisible())
	{
		m_systemParaView.ShowPane(FALSE, FALSE, FALSE);
	}
	else
	{
		m_systemParaView.ShowPane(TRUE, TRUE, TRUE);
	}

	RecalcLayout(FALSE);
}

void CMainFrame::OnUpdateViewSystemPara(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_systemParaView.IsVisible());
}

// 新建项目
void CMainFrame::OnButtonNewProject()
{
	//打开窗口
	CNewProjectView newProjectView;
	int res = newProjectView.DoModal();
	if (res == IDOK){
		SendMessage(WM_REFRESHVIEW_BY_PROJECT);
	}
}

 //项目管理
void CMainFrame::OnButtonProjectManage()
{

}

// 打开数据文件
void CMainFrame::OnButtonOpenDataFile()
{
	// TODO:  在此添加命令处理程序代码
	CSignalDataView sampleDataView;

	if (sampleDataView.DoModal() == IDOK)
	{
		//去查询采集数据
		///得到选中的采样信号
		m_selectedSumSignal = sampleDataView.GetSelectedSumSignal();
		m_selectedSumSignal.GetAllSignal().clear();
		///拿到所有的信号
		m_signalController.GetSignalsBySumSignalId(m_selectedSumSignal.GetSumsignalId(),m_selectedSumSignal.GetAllSignal());
		///拿到所有通道便于回显
		//liuxiutheApp.m_currentProject
		//TbChannel channel = m_project.GetChannelVector()[0];
		
		///创建缺少的窗口数theApp.m_currentProject.GetChannelVector().size() m_selectedSumSignal.GetAllSignal().size()
		for (int i = 0; i < m_selectedSumSignal.GetAllSignal().size() - theApp.m_currentProject.GetChannelVector().size(); i++){
			TbChannel channel;
			theApp.m_currentProject.GetChannelVector().push_back(channel);
		}
		SendMessage(WM_REFRESHVIEW_BY_PROJECT);
		//OnBtnStartPlayback();
		CString path = m_selectedSumSignal.GetAllSignal()[0].GetDataUrl();
		ifstream inputStream = CFileUtil::GetIfstreamByFileName(path);
		if (inputStream.good()){
			/// 本地文件存在
			m_blocalSignalExist = true;
			thread t(&CMainFrame::Pre_GetDataFromlocal, this);
			t.detach();
		}
		else{
			///本地文件不存在，从服务器读取文件。 
			AfxMessageBox("bucunzai---");
			m_blocalSignalExist = false;
		}

		// 如果可以连接服务器，根据条件查询服务器数据
		// 否则查询本体数据
		//if (strcmp(theApp.PDsql.m_mysql.host, "127.0.0.1") == 0)/*连接本地*/
		//{
		//	//查询传感器个数
		//	int nSersor = 4;
		//	CMainFrame*pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
		//	CloseAllWindows();
		//	// 打开窗口
		//	NewDoc(nSersor);
		//	// 初始化view
		//	InitializeSampleDataEchoView(16);
		//	bool bOpenDataFile;
		//	/*文件路径vector*/
		//	vector<CString> vFilePaths;
		//	// 根据传感器信息查找文件路径
		//	for (int i = 0; i < theApp.m_vsignalCaptureView.size(); i++)
		//	{
		//		/*汇总路径*/
		//		for (int j = 0; j < collectionData[i].size(); j++)
		//		{
		//			vFilePaths.push_back(collectionData[i][j].GetDataUrl());

		//		}
		//		//vFilePaths.push_back(collectionData[1][0].GetDataUrl());
		//		// 根据路径查找文件，放到各自的view采样队列里面
		//		bOpenDataFile = CFileUtil::ReadSampleDataByPaths(vFilePaths,
		//			theApp.m_vsignalCaptureView[i]->m_sampleFromFileDataQueue);
		//		vFilePaths.clear();
		//	}
		//	if (!bOpenDataFile)
		//	{
		//		AfxMessageBox("打开数据文件失败");
		//	}

		//	// 窗口水平平铺
		//	WindowsHorizontal();

		//}
		//else/*连接服务器*/
		//{
		//}

	}

}


// 导出通道参数
void CMainFrame::OnButtonExportChannelPara()
{
	// TODO:  在此添加命令处理程序代码
}

//导入通道参数
void CMainFrame::OnButtonImportChannelPara()
{
	// TODO:  在此添加命令处理程序代码
}

// 导出系统参数
void CMainFrame::OnButtonExportSysPara()
{
	// TODO:  在此添加命令处理程序代码
}

// 导入系统参数
void CMainFrame::OnButtonImportSysPara()
{
	// TODO:  在此添加命令处理程序代码
}


//开始采集
void CMainFrame::OnButtonStartCapture()
{
	long lIsSampling;
	//是否正在采集数据
	theApp.m_pHardWare->IsSampling(&lIsSampling);
	if (lIsSampling){
		AfxMessageBox(LPCTSTR("仪器采样中，请先停止采样!"));
		return;
	}
	int oldcollectState = theApp.m_icollectState;
	
	///如果当前状态为正在采集
	if (theApp.m_icollectState == 1) return;
	///设置当前状态为正在采集状态
	theApp.m_icollectState = 1;
	long lReturnValue;
	// 设置采样频率
	//设置取数块大小 小于等于500Hz按采样频率，1000Hz往上1024的整数倍；
	float fltSampleFrequency = theApp.m_currentProject.GetCollectionparas().GetSampleFrequency().second;
	theApp.m_pHardWare->SetSampleFreq(fltSampleFrequency, &lReturnValue);
	//防止内存不够取不到数
	//int dataCount = theApp.m_currentProject.GetCollectionparas().GetLine() * theApp.FFTRATE;
	//int dataCount = theApp.m_currentProject.GetCollectionparas().GetLine() * 2;
	int dataCount = 15624;
	theApp.m_pHardWare->SetGetDataCountEveryTime(dataCount, &lReturnValue);

	//启动采样 1024
	theApp.m_pHardWare->StartSample(LPCTSTR("DH3817F"), 0, dataCount, &lReturnValue);

	//如果当前状态是暂停采集，那么就直接开始采集
	if (oldcollectState == 2){
		return;
	}

	//// 初始化采集窗口集合
	InitCaptureViewVector();
	for (int i = 0; i < theApp.m_vsignalCaptureView.size(); i++){//
		theApp.m_vsignalCaptureView[i]->openTimer2RefershView();
	}
	//// 初始化采集队列
	for (int i = 0; i < m_vchannelCodes.size(); i++){
		m_mpcolllectioinDataQueue.insert(std::pair<CString, ThreadSafeQueue<double>>(m_vchannelCodes[i], ThreadSafeQueue<double>()));
		m_redisCollectionDataQueue.insert(std::pair<CString, ThreadSafeQueue<double>>(m_vchannelCodes[i], ThreadSafeQueue<double>()));
		m_modelPredictResult.insert(std::pair<CString, ThreadSafeQueue<CString>>(m_vchannelCodes[i], ThreadSafeQueue<CString>()));
	}

	//启动取数线程
	//当HardWareCfg.ini中配置了 OneMacBuffer = 1 时，只能使用 GetOneMacChnDataEx或GetOneMacChnData。
	m_bThread = true;

	if (m_bOneMacBuffer){
		m_pGetDataThread = AfxBeginThread(GetOneMacDataThread, this, THREAD_PRIORITY_NORMAL);
	}
	else{
		m_pGetDataThread = AfxBeginThread(GetDataThread, this, THREAD_PRIORITY_NORMAL);
	}
	
	OpenThread2SaveCollectionData();
	OpenThread2RedisSaveData();
	//AfxBeginThread(GetResultFromRedisThread, this, THREAD_PRIORITY_NORMAL);
	// OpenThreadReadPredictResult();
	//AcquireResult();
	//实时数据传输
	//SetTimer(99, 1000, NULL);
}

// 取数线程
/*接口说明：获取采样数据（数据类型float）
参数说明：
nBufferSize – bufferPoint对应内存的字节大小
bufferPoint –存储通道数据的内存地址
输出：
bufferPoint –仪器采集到的数据
nTotalDataPos –单个通道已采集的总数据量（不含本次接收数据量）
nReceiveCount–每通道数据量
nChnCount – 通道数
returnValue –返回值 - 1 –内存地址不足, 0 –未获取到数据, 1 –获取到数据
获取的数据的排列如下：
1号机							2号机
000………..000111…………111…………000……..…000111…………..111
1通道所有数  2通道所有数			1通道所有数  2通道所有数
获取的数据按机号从小到大排列*/
UINT CMainFrame::GetDataThread(LPVOID pParam)
{
	CMainFrame *curFrame = (CMainFrame *)pParam;
	CString strChannel;
	int nSelGroupID, nSelChanID;
	long nBufferSize = 1024 * 1024;		// 1Mb内存 防止内存不够获取不到数据
	float *BufferPoint = new float[nBufferSize];
	long nTotalDataPos, nReceiveCount, nChnCount, lReturnValue;
	nChnCount = 4;
	nReceiveCount = 15624;
	int groupId = 0;
	int channelId = 0;
	long lTime = GetTickCount();
	float r = 0;
	while (curFrame->m_bThread)
	{
		//theApp.m_pHardWare->GetAllChnData(nBufferSize, (long)BufferPoint, &nTotalDataPos, &nReceiveCount, &nChnCount, &lReturnValue);
		if (nReceiveCount <= 0||theApp.m_icollectState==2){
			Sleep(10);
			continue;
		}
		//TRACE("pos:%d\n", nTotalDataPos);
		/*TRACE("Get%d:%d\n", nReceiveCount,GetTickCount() - lTime);*/
		lTime = GetTickCount();
		float *pValue = (float*)BufferPoint;
		for (int i = 0; i < theApp.m_vecGroupChannel.size(); i++)
		{
			// theApp.m_vecGroupChannel[i].m_nChannelNumber   .m_nChannelFirst +4
			int a = theApp.m_vecGroupChannel[i].m_nChannelNumber;
			for (int j = theApp.m_vecGroupChannel[i].m_nChannelFirst; j < theApp.m_vecGroupChannel[i].m_nChannelNumber; j++){
				//获取当前通道pos
				long nSeekPos;
				//SChartXYPoint* pPoints = new SChartXYPoint[int(nReceiveCount / 2)];
				double * fftwInputArray = new double[nReceiveCount];//傅里叶输入
				float pfltData;
				CString channelCode = CommonUtil::Int2CString(theApp.m_vecGroupChannel[i].m_GroupID) + "-" + CommonUtil::Int2CString(j);
				theApp.m_pHardWare->GetDataIndex(theApp.m_vecGroupChannel[i].m_GroupID, theApp.m_vecGroupChannel[i].m_strMachineIP.c_str(), j, &nSeekPos, &lReturnValue);
				for (int k = 0,index = 0; k < nReceiveCount; k++){
					
					//构造频点
					float s1 = cos(50 * r *M_PI * 100);
					float s2 = cos(5 * M_PI * 100 * r);
					float s3 = sin(200 * M_PI * 100 * r);
					float s4 = sin(5 * M_PI * 10 * r);
					float sumsignal = s1 + s2 + s3 + s4;

					pfltData = pValue[nSeekPos*nReceiveCount + k];//采集数据

					curFrame->m_mpcolllectioinDataQueue[channelCode].push(sumsignal);//pfltData
					curFrame->m_redisCollectionDataQueue[channelCode].push(sumsignal); //redis取数队列   pfltData
					fftwInputArray[k] = sumsignal;//pfltData
					r += 0.01;

					
					//curFrame->RedisSetCollectionData(pfltData);
					//theApp.m_redisConnect->redisSetCollectionData("CollectionData",pfltData);
				}
				curFrame->m_mpsignalCollectionView[channelCode]->SetEchoSignal(fftwInputArray);
				//theApp.m_redisConnect->redisGetCollectionData("CollectionData");
			}
		}
		//TRACE("\nCal:%d\n", GetTickCount() - lTime);
		Sleep(10);
		
	}
	delete[] BufferPoint;
	return 0;
}
//结果线程
UINT CMainFrame::GetResultFromRedisThread(LPVOID pParam){

	CMainFrame *curFrame_redis = (CMainFrame *)pParam;
	redisReply *reply;
	while (curFrame_redis->m_bThread){
	
		for (int i = 0; i < 4; i++){
			CString channelCode = "0-" + CommonUtil::Int2CString(i);
			reply = (redisReply*)redisCommand(theApp.m_redisContext, "LPOP predictResult-%s", channelCode);
			string redisResult = reply->str;
			CString redisResult_c = redisResult.c_str();
			curFrame_redis->m_modelPredictResult[channelCode].push(redisResult_c);

		}
	
	
	}
	freeReplyObject(reply);


	return 0;

}
void CMainFrame::OnShowSampleData(WPARAM wParam, LPARAM lParam){
	//int nDataCount = (int)wParam;
	//float *pfltData = (float *)lParam;
	////Double strData ;
	//SmartArray<double> xData; ///x坐标
	//fftw_complex fftw;///单次傅立叶变换的输入
	//int channel = 0;
	//vector<SmartArray<double>> fftwInputArray(1);//channelCount

	//for (int i = 0; i < nDataCount; i++)
	//{
	//	//strData.Format("%.3f   ", pfltData[i]);
	//	fftwInputArray[0].push_back(pfltData[i]);
	//	//channel++;
	//}
	//tempCount += nDataCount;
	
	//
	////设置x坐标
	//for (int i = 0; i < nDataCount / theApp.FFTRATE; i++){
	//	xData.push_back(i);
	//}
	////for (int channel = 0; channel < 4; channel++){
	//	SmartArray<double> yData; ///y坐标
	//	//对传入的数据进行傅里叶变换处理
	//	SmartFFTWComplexArray fftwOutput(fftwInputArray[0].size());
	//	FFTWUtil::FastFourierTransformation(fftwInputArray[0].size(), fftwInputArray[0].GetSmartArray(),
	//		fftwOutput.GeFFTWComplexArray());
	//	//将处理之后的傅里叶变换转换成XY坐标
	//	int a = fftwInputArray[0].size();
	//	FFTWUtil::FFTDataToXY(fftwOutput, yData, fftwInputArray[0].size());
	//	//
	//	theApp.m_vsignalCaptureView[0]->SetEchoSignalData(EchoSignal(xData, yData));

	////}
}

UINT CMainFrame::GetOneMacDataThread(LPVOID pParam)
{
	CMainFrame *curFrame = (CMainFrame *)pParam;
	CString strChannel;
	int nSelGroupID, nSelChanID;
	tempCount = 0;
	long nBufferSize = 1024 * 1024;	// 1Mb内存 防止内存不够获取不到数据
	float *BufferPoint = new float[nBufferSize];

	if (curFrame->m_bThread)
		//curFrame->m_ComboChannel.GetLBText(curFrame->m_ComboChannel.GetCurSel(), strChannel);
	    strChannel = "1-3";
	nSelGroupID = atoi(strChannel.Left(strChannel.ReverseFind('-'))) - 1;
	nSelChanID = atoi(strChannel.Mid(strChannel.ReverseFind('-') + 1)) - 1;
	int nIndex = -1;
	for (int i = 0; i < theApp.m_vecGroupChannel.size(); i++)
	{
		if (theApp.m_vecGroupChannel[i].m_GroupID == nSelGroupID)
		{
			nIndex = i;
		}
	}
	if (nIndex == -1)
	{
		//curFrame->m_List.AddString("仪器不存在！");
		return 0;
	}

	while (curFrame->m_bThread)
	{
		long nTotalDataPos, nReceiveCount, nChnCount, lReturnValue;
		//theApp.m_pHardWare->GetOneMacChnDataEx(nSelGroupID, nBufferSize, (long)BufferPoint, &nTotalDataPos, &nReceiveCount, &nChnCount, &lReturnValue);
		if (nReceiveCount <= 0)
		{
			Sleep(10);
			continue;
		}

		float *pfltData = new float[nReceiveCount];
		float *pValue = (float*)BufferPoint;

		stuGroupChannel GroupChannel = theApp.m_vecGroupChannel[nIndex];
		long bOnLine = 0;
		theApp.m_pHardWare->IsChannelOnLine(GroupChannel.m_GroupID, GroupChannel.m_strMachineIP.c_str(), nSelChanID, &bOnLine);
		if (bOnLine)
		{
			//获取当前通道pos
			//11112222333
			for (int k = 0; k < nReceiveCount; k++)
			{
				pfltData[k] = pValue[nSelChanID*nReceiveCount + k];
			}

			if (curFrame->m_hWnd != NULL)
				curFrame->OnShowSampleData((WPARAM)nReceiveCount, (LPARAM)pfltData);
		}
		else
			//curFrame->m_List.AddString("通道不在线");

		delete[] pfltData;
		Sleep(10);
	}
	delete[] BufferPoint;
	return 0;
}


void CMainFrame::SetChannelInfoJsonValue(){
	m_channelInfo.SetObject();
	m_channelInfo.RemoveAllMembers();
	Value channelCount;
	channelCount.SetInt(theApp.m_currentProject.GetChannelVector().size());
	m_channelInfo.AddMember("channelCount", channelCount, m_doc.GetAllocator());

	Value startChannel;
	startChannel.SetString(theApp.m_currentProject.GetChannelVector()[0].GetChannelCode(), m_doc.GetAllocator());
	m_channelInfo.AddMember("startChannel", startChannel, m_doc.GetAllocator());

	Value endChannel;
	endChannel.SetString(theApp.m_currentProject.GetChannelVector()[theApp.m_currentProject.GetChannelVector().size() - 1].GetChannelCode(), m_doc.GetAllocator());
	m_channelInfo.AddMember("endChannel", endChannel, m_doc.GetAllocator());

	Value channels(kArrayType);
	for (int i = 0; i < theApp.m_currentProject.GetChannelVector().size(); i++){
		Value channel(kObjectType);
		JsonUtil::ConvertChannel2Value(theApp.m_currentProject.GetChannelVector()[i], channel);
		channels.PushBack(channel, m_doc.GetAllocator());
	}
	m_channelInfo.AddMember("channels", channels, m_doc.GetAllocator());
}

void CMainFrame::SetCollectionStatusJsonValue(){
	m_collectionStatus.SetObject();
	m_collectionStatus.RemoveAllMembers();
	///解析原有的项目里面保存的采集状态
	//m_doc.Parse(theApp.m_currentProject.GetCollectionStatus());
	m_collectionStatus.CopyFrom(m_doc, m_doc.GetAllocator());
	///再加入采集参数的一些东西。
	Value collectionparas(kObjectType);
	JsonUtil::ConvertCollectionparas2Value(theApp.m_currentProject.GetCollectionparas(), collectionparas);
	m_collectionStatus.AddMember("collectionparas", collectionparas, m_doc.GetAllocator());
}

//暂停采集
void CMainFrame::OnButtonSuspendCapture()
{
	/*for (int i = 0; i < m_vwfAiCtrl.size(); i++){
		ErrorCode err = Success;
		err = m_vwfAiCtrl[i]->Stop();
		if (err != Success)
		{
			m_advantechDaqController.CheckError(err);
			return;
		}
	}*/
	long lIsSampling;
	//是否正在采集数据
	theApp.m_pHardWare->IsSampling(&lIsSampling);
	if (lIsSampling)
	{
		theApp.m_icollectState = 2;
		////停止采样
		theApp.m_pHardWare->StopSample(&lIsSampling);
	}
}

// 停止采集
void CMainFrame::OnBtnStopCapture()
{
	KillTimer(99);
	long lIsSampling;
	//是否正在采集数据
	theApp.m_pHardWare->IsSampling(&lIsSampling);
	if (lIsSampling)
	{
		
		// 停止采样线程
		m_bThread = false;
		MSG msg;
		DWORD dwRet = 0;
		while (TRUE)
		{
			//使得主线程可以处理消息（包括界面消息、线程发送的消息）
			dwRet = MsgWaitForMultipleObjects(1, &(m_pGetDataThread->m_hThread), FALSE, 10, QS_ALLINPUT);
			switch (dwRet)
			{
			case WAIT_OBJECT_0:
				break;
			case WAIT_OBJECT_0 + 1://响应mainframe中的数据处理消息
				PeekMessage(&msg, NULL, 0, 0, PM_REMOVE);
				DispatchMessage(&msg);
				continue;
			case WAIT_TIMEOUT:
				PeekMessage(&msg, NULL, 0, 0, PM_REMOVE);
				DispatchMessage(&msg);
				continue;
			default:
				break;
			}
			break;
		}

		long lStopSample;
		////停止采样
		theApp.m_pHardWare->StopSample(&lStopSample);
		
	}
    theApp.m_icollectState = 0;
	for (int i = 0; i < theApp.m_vsignalCaptureView.size(); i++){
		theApp.m_vsignalCaptureView[i]->killTimer2RefershView();
		theApp.m_vsignalCaptureView[i]->clearEchoSignal();
	}
	//for (int channel = 0; channel < m_vchannelCodes.size(); channel++)
	//{
	//	m_vSignalTestRecord[channel].SetPeakValue(theApp.m_vsignalCaptureView[channel]->GetPeak());
	//	m_vSignalTestRecord[channel].SetGrossValue(theApp.m_vsignalCaptureView[channel]->GetGross());
	//	m_SignalTestRecordController.AddSignalTestRecord(m_vSignalTestRecord[channel]);
	//}
	////theApp.m_vsignalCaptureView[0]->GetPeak();

	//if (theApp.m_isAlarm == 1 )
	//{
	//	for (int channel = 0; channel < m_vchannelCodes.size(); channel++)
	//	{
	//		if (theApp.m_alarmLimit < theApp.m_vsignalCaptureView[channel]->GetPeak()){
	//			m_vAlarmpara[channel].SetPeakValue(theApp.m_vsignalCaptureView[channel]->GetPeak());
	//			m_vAlarmpara[channel].SetGrossValue(theApp.m_vsignalCaptureView[channel]->GetGross());
	//			m_AlarmparaController.AddAlarmpara(m_vAlarmpara[channel]);
	//		}
	//	}
	//}


	//for (int i = 0; i < m_vwfAiCtrl.size(); i++){
	//	ErrorCode err = Success;
	//	err = m_vwfAiCtrl[i]->Stop();
	//	if (err != Success)
	//	{
	//		m_advantechDaqController.CheckError(err);
	//		return;
	//	}
	//}
}

// 停止回放
void CMainFrame::OnBtnStopPlayback()
{
	theApp.m_iplaybackState = 0;
	for (int i = 0; i < theApp.m_vsignalCaptureView.size(); i++){
		theApp.m_vsignalCaptureView[i]->killTimer2RefershView();
		theApp.m_vsignalCaptureView[i]->clearEchoSignal();
	}

}


//开始回放
void CMainFrame::OnBtnStartPlayback()
{
	//如果现在正在回放，那么就暂停回放
	//if (theApp.m_iplaybackState == 1){
	//	theApp.m_iplaybackState = 2;
	//	return;
	//}
	////如果现在暂停回放，那么就启动回放
	//if (theApp.m_iplaybackState == 2){
	//	theApp.m_iplaybackState = 1;
	//	return;
	//}
	if (m_blocalSignalExist){
		//设置视图的刷新状态
		theApp.m_iplaybackState = 1;
		vector<thread> threadVector;
		for (int i = 0; i < theApp.m_vsignalCaptureView.size(); i++){
			theApp.m_vsignalCaptureView[i]->openTimer2RefershView();
			threadVector.push_back(thread(&CMainFrame::GetDataFromlocal, this, m_selectedSumSignal.GetAllSignal()[i], theApp.m_vsignalCaptureView[i]));
		}
		for (int i = 0; i < threadVector.size(); i++){
			threadVector[i].detach();
		}
		//所有线程都完事了，执行保存操作
		//theApp.m_iplaybackState = 0;
	}
}

// 关闭所有窗口
//void CMainFrame::OnBtnCloseAllWindow()
//{
//	// TODO:  在此添加命令处理程序代码
//	// 关闭所有窗口
//	CloseAllWindows();
//}



/*产品管理*/
void CMainFrame::OnButtonProduct()
{
	// TODO:  在此添加命令处理程序代码
	CProductManageView productManegeView;
	productManegeView.DoModal();
}

//开始采样
void CMainFrame::OnBtnStartSmaple()
{
	int projectId = theApp.m_currentProject.GetProjectId();
	if (projectId <= 0){
		AfxMessageBox("请先打开或者新建项目");
		return;
	}
	if (theApp.m_icollectState == 0){
		AfxMessageBox("当前没有采集状态");
		return;
	}
	/*开始采样，封装采样信号的对象*/
	//m_recordSignal.SetStartTime(DateUtil::GetCurrentCStringTime());
	//m_recordSignal.SetProject(theApp.m_currentProject);
	//m_recordSignal.SetProduct(theApp.m_currentProject.GetProduct());
	//m_recordSignal.SetCollectionparas(theApp.m_currentProject.GetCollectionparas());
	//m_recordSignal.SetCollectionStatus(theApp.m_currentProject.GetCollectionStatus());
	//m_recordSignal.SetStartPos(m_outputStream.tellp());
	theApp.m_isampleStatus = 1;
	m_sumsignalLabel.SetLabel(1);
	m_sumsignalLabel.SetStartTime(DateUtil::GetCurrentCStringTime());
	m_sumsignalLabel.SetSumsignalId(m_sumSignal.GetSumsignalId());
}

// 停止采样
void CMainFrame::OnBtnStopSample()
{
	//if (m_recordSignal.GetStartTime() == ""){
	//	AfxMessageBox("当前未在采集");
	//	return;
	//}

	if (m_sumsignalLabel.GetStartTime() == ""){
		AfxMessageBox("当前未在采集");
		return;
	}
	m_sumsignalLabel.SetEndTime(DateUtil::GetCurrentCStringTime());
	Result res = m_sumsignalLabelController.AddSumsignalLabel(m_sumsignalLabel);
	if (!res.GetIsSuccess()){
		AfxMessageBox("采样数据保存失败");
	}
	theApp.m_isampleStatus = 0;
}

//工程单位
void CMainFrame::OnBtnEngineeringUnit()
{
	// TODO:  在此添加命令处理程序代码
	CEngineerUnitView engineerUnitView;
	engineerUnitView.DoModal();
}

// 报警设置
void CMainFrame::OnBtnAlarmSet()
{
	// TODO:  在此添加命令处理程序代码
	CAlarmParaSetView alarmView;
	if (alarmView.DoModal() == IDOK)
	{
		PTSTR lpPath = new char[MAX_PATH];

		strcpy(lpPath, "..//IniAlarmSet.ini");
		// 颜色
		WritePrivateProfileString(alarmView.m_strAlarm, "channelAlarm", CommonUtil::Int2CString(alarmView.m_bChannelAlarm), lpPath);
		WritePrivateProfileString(alarmView.m_strAlarm, "alarmLog", CommonUtil::Int2CString(alarmView.m_bAlarmLog), lpPath);
		WritePrivateProfileString(alarmView.m_strAlarm, "soundAlarm", CommonUtil::Int2CString(alarmView.m_bSoundAlarm), lpPath);
		WritePrivateProfileString(alarmView.m_strAlarm, "alarmLimit", CommonUtil::Int2CString(alarmView.m_iAlarmLimit), lpPath);
		delete[] lpPath;
		theApp.m_isAlarm = alarmView.m_bChannelAlarm;
		theApp.m_alarmLimit = alarmView.m_iAlarmLimit;
	}
}

// 横向放大
void CMainFrame::OnBtnTransverseAmplification()
{
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	CDuChartCtrlStaticFunction::HengxiangFangda(&view->GetChartCtrl());
}

// 横向缩小
void CMainFrame::OnBtnHorizontalReduction()
{
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	CDuChartCtrlStaticFunction::HengxiangSuoxiao(&view->GetChartCtrl());

}

// 纵向缩小
void CMainFrame::OnBtnVerticalReduction()
{
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	CDuChartCtrlStaticFunction::ZongxiangSuoxiao(&view->GetChartCtrl());
}

//纵向放大
void CMainFrame::OnBtnVerticalAmplification()
{
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	CDuChartCtrlStaticFunction::ZongxiangFangda(&view->GetChartCtrl());
}

//单光标
void CMainFrame::OnBtnSingleCursor()
{
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	CDuChartCtrlStaticFunction::SetCursorSingle(&view->GetChartCtrl());
}

//峰值
void CMainFrame::OnBtnPeakValue()
{
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	view->GetChartCtrl().SetCursorPeak(TRUE);
	//CDuChartCtrlStaticFunction::SetCursorPeak(&view->GetChartCtrl());
}

// 自动刻度
void CMainFrame::OnBtnAutoScale()
{
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	CDuChartCtrlStaticFunction::AutoXScale(&view->GetChartCtrl(), FALSE);
	CDuChartCtrlStaticFunction::AutoYScale(&view->GetChartCtrl(), FALSE);
}

// 默认刻度
void CMainFrame::OnBtnDefaultScale()
{
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	//CDuChartCtrlStaticFunction::SetCursorNone(&view->GetChartCtrl());
	CChartStandardAxisDu * leftAxis = (CChartStandardAxisDu*)view->GetChartCtrl().GetAxisDu(CChartCtrl::LeftAxis, 0);
	CChartStandardAxisDu * bottomAxis = (CChartStandardAxisDu*)view->GetChartCtrl().GetAxisDu(CChartCtrl::BottomAxis, 0);
	bottomAxis->SetMinMax(0, 500);//设置下刻度
	bottomAxis->SetTickIncrement(false, 100);

	leftAxis->SetMinMax(-0.1, 0.1);
	leftAxis->SetTickIncrement(false, 0.05);
}

// 无光标
void CMainFrame::OnBtnNoCorror()
{
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	CDuChartCtrlStaticFunction::SetCursorNone(&view->GetChartCtrl());
}

void CMainFrame::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	// 实时传输
	if (nIDEvent == 99)
	{
		//RealTimeSignal2Server();
	}
	if (nIDEvent == StatusBarTimer)/**/
	{
		CTime time;
		time = CTime::GetCurrentTime();//得到当前时间
		CString strTime = time.Format("%H:%M:%S");//转换时间格式
		CMFCRibbonBaseElement *pElement = m_wndStatusBar.FindElement(ID_STATUSBAR_PANE2);
		pElement->SetText("当前时间：" + strTime);
		pElement->Redraw();
	}
	CMDIFrameWndEx::OnTimer(nIDEvent);
}

void CMainFrame::RealTimeSignal2Server()
{
	vector<CString> jsonStr;
	CString str2JSON = "";
	CString separator = "";////逗号分隔符
	// 转成字符串
	for (int i = 0; i < theApp.m_vsignalCaptureView.size(); i++)
	{
		CString tempStr;
		shared_ptr<RealTimeSignal >realTimeSignal = theApp.m_vsignalCaptureView[i]->m_realTimeSignal.wait_and_pop();
		vector<double> realSignalData = realTimeSignal->GetRealTimeSignalData();
		vector<CString> realSignalTime = realTimeSignal->GetRealTimeSignalTime();

		CFileUtil::RealTimeSignal2JSON(realSignalData, realSignalTime, realSignalData.size(), i, tempStr);
		str2JSON = str2JSON + separator + tempStr;
		separator = ",";
	}
	str2JSON = "{" + str2JSON + "}";
	//发送
	//theApp.m_redisCon->SetValue("11", str2JSON.GetBuffer());

}

///标题栏修改的响应事件
LRESULT CMainFrame::OnSetText(WPARAM wParam, LPARAM lParam)
{
	CString title;
	CString product = "未知产品";
	CString project = "未知项目";
	CString user = "未知人";
	CString sensor = "未知传感器";

	if (theApp.m_currentProject.GetProduct().GetProductType().GetId() !=0) product = theApp.m_currentProject.GetProduct().GetProductType().GetTypeName();
	if (theApp.m_currentProject.GetProjectName() != "") project = theApp.m_currentProject.GetProjectName();
	if (theApp.m_currentProject.GetUser().GetName() != "") user = theApp.m_currentProject.GetUser().GetName();

	CAirCraftCasingVibrateSystemView *selectedView = NULL;
	///获取当前的激活窗口
	CWnd* activeWind = (AfxGetApp()->m_pMainWnd);
	if (activeWind != NULL){
		///如果窗口不为空的话
		selectedView = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	}
	if (selectedView != NULL) sensor = selectedView->GetDocument()->GetTitle();
	title = product + "-" + project + "-" + "-" + user + "-" + "(" + sensor + ")";
	lParam = (LPARAM)title.GetBuffer();
	DefWindowProc(WM_SETTEXT, wParam, lParam);
	Invalidate();
	return 0;
}

// 图形属性
void CMainFrame::OnBtnGraphAttribute()
{

	// TODO:  在此添加命令处理程序代码
	if (m_graphAttributeView.DoModal() == IDOK)
	{
		InitCaptureViewVector();
		for (int i = 0; i < theApp.m_vsignalCaptureView.size(); i++)
		{
			m_graphAttributeView.Write2INIFile();
			/*颜色*/
			// 窗口背景
			theApp.m_vsignalCaptureView[i]->GetChartCtrl().SetBackColor(m_graphAttributeView.m_colorView.m_colBKColor);
			//图形区域背景
			theApp.m_vsignalCaptureView[i]->GetChartCtrl().m_GraphBKColor = m_graphAttributeView.m_colorView.m_colGBKColor;
			// 信息区域背景
			theApp.m_vsignalCaptureView[i]->GetChartCtrl().m_shuxing.m_colTBKColor = m_graphAttributeView.m_colorView.m_colTBKColor;
			//光标颜色
			theApp.m_vsignalCaptureView[i]->GetChartCtrl().m_shuxing.m_colCursorColor1 = m_graphAttributeView.m_colorView.m_colCursor1;
			// 曲线颜色
			theApp.m_vsignalCaptureView[i]->GetChartCtrl().GetSerieFromIndexDu(0)->SetColor(m_graphAttributeView.m_colorView.m_colSerie[0]);
			//网格颜色
			theApp.m_vsignalCaptureView[i]->GetChartCtrl().GetAxisDu(CChartCtrl::BottomAxis, 0)->GetGrid()->SetColor(m_graphAttributeView.m_colorView.m_colGridLineColor);
			theApp.m_vsignalCaptureView[i]->GetChartCtrl().GetAxisDu(CChartCtrl::LeftAxis, 0)->GetGrid()->SetColor(m_graphAttributeView.m_colorView.m_colGridLineColor);
			// 坐标轴颜色
			theApp.m_vsignalCaptureView[i]->GetChartCtrl().GetAxisDu(CChartCtrl::BottomAxis, 0)->SetAxisColor(m_graphAttributeView.m_colorView.m_colXCoor);
			theApp.m_vsignalCaptureView[i]->GetChartCtrl().GetAxisDu(CChartCtrl::LeftAxis, 0)->SetAxisColor(m_graphAttributeView.m_colorView.m_colYCoor);
			// 刻度颜色
			theApp.m_vsignalCaptureView[i]->GetChartCtrl().GetAxisDu(CChartCtrl::BottomAxis, 0)->SetTextColor(m_graphAttributeView.m_colorView.m_colScale);
			theApp.m_vsignalCaptureView[i]->GetChartCtrl().GetAxisDu(CChartCtrl::LeftAxis, 0)->SetTextColor(m_graphAttributeView.m_colorView.m_colScale);
			// 标注颜色
			theApp.m_vsignalCaptureView[i]->GetChartCtrl().GetAxisDu(CChartCtrl::BottomAxis, 0)->GetLabel()->SetColor(m_graphAttributeView.m_colorView.m_colScale);
			theApp.m_vsignalCaptureView[i]->GetChartCtrl().GetAxisDu(CChartCtrl::LeftAxis, 0)->GetLabel()->SetColor(m_graphAttributeView.m_colorView.m_colScale);

			/*字体*/
			// 坐标轴
			theApp.m_vsignalCaptureView[i]->GetChartCtrl().GetAxisDu(CChartCtrl::BottomAxis, 0)->SetFont(
				m_graphAttributeView.m_fontView.m_lFontXCoor.m_lFontSize, m_graphAttributeView.m_fontView.m_lFontXCoor.m_lFont.lfFaceName);
			theApp.m_vsignalCaptureView[i]->GetChartCtrl().GetAxisDu(CChartCtrl::LeftAxis, 0)->SetFont(
				m_graphAttributeView.m_fontView.m_lFontYCoor.m_lFontSize, m_graphAttributeView.m_fontView.m_lFontYCoor.m_lFont.lfFaceName);

			// 坐标单位
			theApp.m_vsignalCaptureView[i]->GetChartCtrl().GetAxisDu(CChartCtrl::BottomAxis, 0)->GetLabel()->SetFont(
				m_graphAttributeView.m_fontView.m_lFontXUnit.m_lFontSize, m_graphAttributeView.m_fontView.m_lFontXUnit.m_lFont.lfFaceName);

			theApp.m_vsignalCaptureView[i]->GetChartCtrl().GetAxisDu(CChartCtrl::LeftAxis, 0)->GetLabel()->SetFont(
				m_graphAttributeView.m_fontView.m_lFontYUnit.m_lFontSize, m_graphAttributeView.m_fontView.m_lFontYUnit.m_lFont.lfFaceName);
			//光标读数

			// 光标标注
			// 统计信息
			// 文本注释
			//工程信息
			/*选项*/
			//统计信息
			theApp.m_vsignalCaptureView[i]->GetChartCtrl().m_shuxing.m_bDrawStatValue = m_graphAttributeView.m_selectView.m_bStaValue;
			// 最大值
			theApp.m_vsignalCaptureView[i]->GetChartCtrl().m_shuxing.m_bDrawStatMax = m_graphAttributeView.m_selectView.m_bMax;
			// 最小值
			theApp.m_vsignalCaptureView[i]->GetChartCtrl().m_shuxing.m_bDrawStatMin = m_graphAttributeView.m_selectView.m_bMin;
			//平均值
			theApp.m_vsignalCaptureView[i]->GetChartCtrl().m_shuxing.m_bDrawStatAve = m_graphAttributeView.m_selectView.m_bAve;
			// 峰值
			theApp.m_vsignalCaptureView[i]->GetChartCtrl().m_shuxing.m_bDrawStatPeak = m_graphAttributeView.m_selectView.m_bPeak;
			// 有效值
			theApp.m_vsignalCaptureView[i]->GetChartCtrl().m_shuxing.m_bDrawStatRms = m_graphAttributeView.m_selectView.m_bEffectiveValue;
			//刷新
			theApp.m_vsignalCaptureView[i]->GetChartCtrl().RefreshCtrl();
		}
	}
}

void CMainFrame::CreateCaptureWindow(vector<TbChannel> & vchannel){
	m_vchannelCodes.clear();
	m_mpcolllectioinDataQueue.clear();
	m_redisCollectionDataQueue.clear();
	m_modelPredictResult.clear();
	m_mpsignalCollectionView.clear();
	theApp.m_vsignalCaptureView.clear();
	for (int i = 0; i < vchannel.size(); i++)
	{
		// 新建文档
		CWinApp* pApp = AfxGetApp();
		POSITION curTemplatePos = pApp->GetFirstDocTemplatePosition();
		if (curTemplatePos != NULL)
		{
			CDocTemplate* curTemplate = pApp->GetNextDocTemplate(curTemplatePos);
			CDocument * pdoc = curTemplate->OpenDocumentFile(NULL);
			////获得新建的文档的view类
			POSITION pos = pdoc->GetFirstViewPosition();
			while (pos != NULL){
				CAirCraftCasingVibrateSystemView* currentView = (CAirCraftCasingVibrateSystemView*)pdoc->GetNextView(pos);
				/////设置传感器
				currentView->SetChannel(vchannel[i]);
				theApp.m_vsignalCaptureView.push_back(currentView);
				m_vchannelCodes.push_back(vchannel[i].GetChannelCode());
				m_mpsignalCollectionView[vchannel[i].GetChannelCode()] = currentView;
				m_mpcolllectioinDataQueue.insert(std::pair<CString, ThreadSafeQueue<double>>(vchannel[i].GetChannelCode(), ThreadSafeQueue<double>()));
				m_redisCollectionDataQueue.insert(std::pair<CString, ThreadSafeQueue<double>>(vchannel[i].GetChannelCode(), ThreadSafeQueue<double>()));
				m_modelPredictResult.insert(std::pair<CString, ThreadSafeQueue<CString>>(m_vchannelCodes[i], ThreadSafeQueue<CString>()));
			}
		}
	}
}

// 你盯着看内存情况！！！！！
// 卧槽，看样子好像是刚才那个,盯着看吧，半小时起步的看，这电脑内存还不错，3200hz的
 //新建窗口 
void CMainFrame::NewDoc(int nWinNums)
{
	for (int i = 0; i < nWinNums; i++)
	{
		// 新建文档
		CWinApp* pApp = AfxGetApp();
		POSITION curTemplatePos = pApp->GetFirstDocTemplatePosition();
		if (curTemplatePos != NULL)
		{
			CDocTemplate* curTemplate = pApp->GetNextDocTemplate(curTemplatePos);
			curTemplate->OpenDocumentFile(NULL);
		}
	}
}

void CMainFrame::WindowsVertical()
{
	CMainFrame*pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->MDITile(MDITILE_VERTICAL);//纵向平铺

}

void CMainFrame::WindowsHorizontal()
{

	CMainFrame*pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->MDITile(MDITILE_HORIZONTAL);//横向平铺

}


void CMainFrame::CloseAllWindows()
{
	CMDIFrameWnd* pFrame = (CMDIFrameWnd*)AfxGetMainWnd();

	while ((pFrame->MDIGetActive()) != NULL)
	{
		this->GetActiveFrame()->SendMessage(WM_CLOSE);

	}
	theApp.m_newProjectStatus = false;
}


 //程序测试
//void CMainFrame::OnButton9()
//{
//	// TODO:  在此添加命令处理程序代码
//	vector<CString> test;
//	test.push_back("C:\\collectionData\\3-1-3-1-3566998168677.csv");
//	test.push_back("C:\\collectionData\\3-1-3-1-3566998168677.csv");
//	test.push_back("C:\\collectionData\\3-1-3-1-3566998168677.csv");
//	test.push_back("C:\\collectionData\\3-1-3-1-3566998168677.csv");
//	test.push_back("C:\\collectionData\\3-1-3-1-3566998168677.csv");
//	vector<AcquiredSignal> sampleSignal;
//	CFileUtil::ReadSampleDataByPaths(test, sampleSignal);
//}


void CMainFrame::OnCheckStaSet()
{
	// TODO:  在此添加命令处理程序代码
	if (m_stateSetDockPanelView.IsVisible())
	{
		m_stateSetDockPanelView.ShowPane(FALSE, FALSE, FALSE);
	}
	else
	{
		m_stateSetDockPanelView.ShowPane(TRUE, TRUE, TRUE);
	}

	RecalcLayout(FALSE);
}


void CMainFrame::OnUpdateCheckStaSet(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_stateSetDockPanelView.IsVisible());
}


void CMainFrame::OnClose()
{
	if (theApp.m_icollectState != 0){
		AfxMessageBox("正在采集数据，不能关闭程序");
		return;
	}
	if (theApp.m_bisSave) {
		AfxMessageBox("数据保存过程中不能关闭程序");
		return;
	}
	KillTimer(StatusBarTimer);
	CMDIFrameWndEx::OnClose();
}

LRESULT CMainFrame::OnRefreshViewByProject(WPARAM wParam, LPARAM lParam){
	theApp.m_newProjectStatus = true;
	///1.关闭所有已经打开采集的窗口
	CloseAllWindows();
	///2.根据项目的传感器重新创建相对应的窗口
	CreateCaptureWindow(theApp.m_currentProject.GetChannelVector());
	WindowsVertical();
	////2.1初始化采集窗口队列
	InitCaptureViewVector();
	///3刷新状态栏
	SendMessage(StatusInfMessage);
	///4.刷新标题栏（目前改功能失效了）
	SendMessage(WM_SETTEXT);
	///5.刷新系统参数左边窗口
	m_systemParaView.RefreshView();
	///6.刷新采集状态窗口
	m_stateSetDockPanelView.RefreshView();
	/////7.刷新通道参数窗口
	//m_channelParaView.RefreshView();
	return 0;
}

LRESULT CMainFrame::OnStatusInf(WPARAM wParam, LPARAM lParam)
{
	//TODO: Add your message handle code
	CString title;
	CString product = "未知产品";
	CString project = "未知项目";
	CString user = "未知人";
	CString sensor = "未知传感器";

	if (theApp.m_currentProject.GetProduct().GetProductType() .GetId()!= 0) product = theApp.m_currentProject.GetProduct().GetProductType().GetTypeName();
	if (theApp.m_currentProject.GetProjectName() != "") project = theApp.m_currentProject.GetProjectName();
	if (theApp.m_currentProject.GetUser().GetName() != "") user = theApp.m_currentProject.GetUser().GetName();
	title = product + "-" + project + "-" + "-" + user;
	CMFCRibbonBaseElement *pElement = m_wndStatusBar.FindElement(10000);
	pElement->SetText(title);
	pElement->Redraw();
	return 0;
}

void CMainFrame::OnButtonOpenCollectionPlanManage()
{
	CollectionPlanManageView collectionPlanManagerView;
	collectionPlanManagerView.DoModal();
}

void CMainFrame::OnButtonOpenProjectView()
{
	///1.弹出打开项目的窗口
	COpenProjectView projectView;
	int  res = projectView.DoModal();
	if (res == IDOK){
		///3 确定打开项目之后，将此时打开的项目的更新时间设置为此时，保存到数据库
		theApp.m_currentProject.SetProjectUpdateTime(DateUtil::GetCurrentCStringTime());
		Result res = m_projectController.Update(theApp.m_currentProject);
		if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); }
		SendMessage(WM_REFRESHVIEW_BY_PROJECT);
	}
}

///项目设置
void CMainFrame::OnButtonOpenProjectSetView()
{
	ProjectSetView projectSetView;
	int  i = projectSetView.DoModal();
	if (i == IDOK){
		SendMessage(WM_REFRESHVIEW_BY_PROJECT);
	}
}

////开启线程自动保存线程函数
void CMainFrame::OpenThread2SaveCollectionData(){
	thread t(&CMainFrame::SaveSumCollectionData, this);
	t.detach();
}
//wzx
void CMainFrame::SaveSumCollectionData(){
	
	theApp.m_bisSave = true;
	CString uuid;
	UUIDUtil::GetUUID(uuid);
	m_sumSignal.SetSumsignalId(uuid);
	m_sumSignal.SetProductId(theApp.m_currentProject.GetProduct().GetProductId());
	m_sumSignal.SetStartTime(DateUtil::GetCurrentCStringTime());
	Result res = m_signalController.saveSumSignal(m_sumSignal);
	if (!res.GetIsSuccess()){
		AfxMessageBox(res.GetMessages());
	}
	//vector<TbSignal> signalVector;
	// 咋囧事？？？？？当新建项目时候选一个通道不选四个通道时报错
	map<CString, ThreadSafeQueue<double>>::iterator iter = this->m_mpcolllectioinDataQueue.begin();
	vector<thread> threadVector;//size = 4
	while (iter != this->m_mpcolllectioinDataQueue.end()){
		TbSignal signal;
		signal.SetSumSignalId(uuid);                                                        
		m_mpsignalCollectionView[iter->first]->GetChannel(signal.GetChannel());
		threadVector.push_back(thread(&CMainFrame::SaveCollectionData, this, iter->first, signal));
		iter++;
	}
	for (int i = 0; i < threadVector.size();i++){
		threadVector[i].join();
	}
	//所有线程都完事了，执行保存操作
	m_sumSignal.SetEndTime(DateUtil::GetCurrentCStringTime());
	res = m_signalController.updateSumSignal(m_sumSignal);
	if (!res.GetIsSuccess()){
		AfxMessageBox(res.GetMessages());
	}
	theApp.m_bisSave = false;
}

void CMainFrame::SaveCollectionData(CString signalCode,TbSignal signal){
	///1、保存信号 封裝文件名：项目id_测试设备id_产品id_时间戳
	CString filName;
	UUIDUtil::GetUUID(filName);
	CString filePath = "D:/NewCollectionData/"+filName+"-"+signalCode  + ".sin";
	signal.SetDataUrl(filePath);
	CString signalId;
	UUIDUtil::GetUUID(signalId);
	signal.SetSignalId(signalId);
	saveSignalMutex.lock();
	m_signalController.saveSignal(signal);
	saveSignalMutex.unlock();
	ThreadSafeQueue<double> saveData;
	/////封装二进制信号文件头
	SignalFileHeader signalFileHeader;
	strcpy_s(signalFileHeader.m_signalId, signal.GetSignalId());
	strcpy_s(signalFileHeader.m_cChannelCode, signal.GetChannel().GetChannelCode());
	strcpy_s(signalFileHeader.m_cmessureType, "电压测量");
	strcpy_s(signalFileHeader.m_cupFreq, signal.GetChannel().GetUpFreq().second);
	signalFileHeader.m_isensorId = signal.GetChannel().GetSensor().GetSensorId();
	signalFileHeader.m_iChannelId = signal.GetChannel().GetId();
	signalFileHeader.m_ifullvalue = CommonUtil::CString2Int(signal.GetChannel().GetFullValue().second);
	signalFileHeader.m_ielcpressure = CommonUtil::CString2Int(signal.GetChannel().GetElcPressure().second);
	strcpy_s(signalFileHeader.m_cinputMode, signal.GetChannel().GetInputMode().second);
	signalFileHeader.m_fsensitivity = signal.GetChannel().GetSensitivity();
	signalFileHeader.m_iSampleFre =theApp.m_currentProject.GetCollectionparas().GetSampleFrequency().second;
	m_signalController.SaveSignalFileHeader(filePath, signalFileHeader);

	ofstream outputStream = CFileUtil::GetOfstreamByFileName(filePath);
	while (theApp.m_icollectState){
		if (theApp.m_icollectState == 2){
			 //暂停状态就卡在这
			Sleep(10);
			continue;
		}
		while (m_mpcolllectioinDataQueue[signalCode].size() > 0){
			//TRACE("\n队列长度%d\n", m_mpcolllectioinDataQueue[signalCode].size());
			saveData.push(*m_mpcolllectioinDataQueue[signalCode].wait_and_pop());
			if (saveData.size() == theApp.m_icollectSignalsStoreCount){
				m_signalController.SaveCollectionData2Binary(outputStream, move(saveData));
			}
		}
	}
	//点完停止采集之后，还有数据需要保存！！！
	while (m_mpcolllectioinDataQueue[signalCode].size() > 0){
		saveData.push(*m_mpcolllectioinDataQueue[signalCode].wait_and_pop());
		m_signalController.SaveCollectionData2Binary(outputStream, move(saveData));
	}
	outputStream.close();
}

void CMainFrame::GetInstalledDevices(ICollection<DeviceTreeNode> *& devices){
	DeviceCtrl *devicectrl;
	devices = devicectrl->getInstalledDevices();
}

void  CMainFrame::GetChannels(vector<CString> & channels){
	ICollection<DeviceTreeNode> * devices;
	GetInstalledDevices(devices);
	for (int i = 0; i < devices->getCount(); i++){
		int deviceNum = devices->getItem(i).DeviceNumber;
		WaveformAiCtrl   *wfAiCtrl = WaveformAiCtrl::Create();
		wfAiCtrl->setSelectedDevice(DeviceInformation(deviceNum));
		int channelCount = wfAiCtrl->getChannelCount();
		for (int j = 1; j <= channelCount; j++){
			channels.push_back(CommonUtil::Int2CString(deviceNum) + "-" + CommonUtil::Int2CString(j));
		}
	}
}

void CMainFrame::OnUpdateEditAnalyseFreMin(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	if (m_bIsAnalyseFreMin)
	{
		CString strAnalyseFreMin;
		pCmdUI->Enable(TRUE);
		CMFCRibbonCategory* pRibbonUICategory = m_wndRibbonBar.GetCategory(3);  //获得主页，主页的id是1
		if (pRibbonUICategory != NULL)
		{
			CMFCRibbonPanel* pPanel = pRibbonUICategory->GetPanel(2); //获得第3个面板，从左到右是0,1,2,..
			if (pPanel != NULL)
			{
				CMFCRibbonEdit* pElem = (CMFCRibbonEdit*)pPanel->FindByID(ID_EDIT_ANALYSE_FRE_MIN); //获得第2个元素,即编辑框的值（也从0开始）
				//(pElem->GetText());         //获得控件的名字，而不是编辑框的值
				strAnalyseFreMin = pElem->GetEditText();        //获得编辑框的值
				m_bIsAnalyseFreMin = false;
				m_iAnalyseFreMin = CommonUtil::CString2Int(strAnalyseFreMin);
				if (m_iAnalyseFreMin >= 0)
				{
					CAirCraftCasingVibrateSystemView *view;
					view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
					//view->SetChartXYCoordinateLen(m_iAnalyseFreMin);
				}
			}
		}
	}
}

void CMainFrame::OnEditAnalyseFreMin()
{
	m_bIsAnalyseFreMin = true;
}

void CMainFrame::OnEditAnalyseFreMax()
{
	m_bIsAnalyseFreMax = true;
}

void CMainFrame::OnUpdateEditAnalyseFreMax(CCmdUI *pCmdUI)
{
	if (m_bIsAnalyseFreMax)
	{
		CString strAnalyseFreMax;
		pCmdUI->Enable(TRUE);
		CMFCRibbonCategory* pRibbonUICategory = m_wndRibbonBar.GetCategory(3);  //获得主页，主页的id是1
		if (pRibbonUICategory != NULL)
		{
			CMFCRibbonPanel* pPanel = pRibbonUICategory->GetPanel(2); //获得第3个面板，从左到右是0,1,2,..
			if (pPanel != NULL)
			{
				CMFCRibbonEdit* pElem = (CMFCRibbonEdit*)pPanel->FindByID(ID_EDIT_ANALYSE_FRE_MAX); //获得第2个元素,即编辑框的值（也从0开始）
				//(pElem->GetText());         //获得控件的名字，而不是编辑框的值
				strAnalyseFreMax = pElem->GetEditText();        //获得编辑框的值
				m_bIsAnalyseFreMax = false;
				m_iAnalyseFreMax = CommonUtil::CString2Int(strAnalyseFreMax);
				if ((m_iAnalyseFreMax >= 0) && (m_iAnalyseFreMin >= 0))
				{
					CAirCraftCasingVibrateSystemView *view;
					view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
					//view->SetChartXYCoordinateLen(m_iAnalyseFreMin, m_iAnalyseFreMax);
				}
			}
		}
	}
}

void CMainFrame::OnUpdateIdrRibbonI(CCmdUI *pCmdUI)
{
	//BOOL enableTag = (BOOL)czDevs->czSelSect.size();
	//pCmdUI->Enable(theApp.m_icollectState == 1); //还能设置SetChecked等功能呢

	//TRACE("\n当前采集状态：%d\n", theApp.m_icollectState);
	if (pCmdUI->m_nID == ID_BUTTON_START_CAPTURE){
		///1.如果当前控件是开始采集，如果此时不是正在采集，那么将按钮启用
		pCmdUI->Enable(theApp.m_icollectState != 1);
	}

	if (pCmdUI->m_nID == ID_BUTTON_SUSPEND_CAPTURE){
		///2.如果当前控件是暂停采集，如果此时是正在采集，那么将按钮启用
		pCmdUI->Enable(theApp.m_icollectState == 1);
	}
	if (pCmdUI->m_nID == ID_BTN_STOP_CAPTURE){
		///3.如果当前控件是停止采集，如果此时是正在采集，那么将按钮启用
		pCmdUI->Enable(theApp.m_icollectState == 1);
	}

	if (pCmdUI->m_nID == ID_BTN_START_SMAPLE){
		///4.如果当前控件是开始采样，如果此时是正在采集，那么将按钮启用
		if (theApp.m_icollectState == 1 && theApp.m_isampleStatus != 1)
			pCmdUI->Enable(true);
		else
			pCmdUI->Enable(false);

	}
	if (pCmdUI->m_nID == ID_BTN_STOP_SAMPLE){
		///5.如果当前控件是停止采样，如果此时是正在采样，那么将按钮启用
		//pCmdUI->Enable(theApp.m_icollectState == 1);
		if (theApp.m_icollectState == 1 && theApp.m_isampleStatus == 1)
			pCmdUI->Enable(true);
		else
			pCmdUI->Enable(false);
	}
}

//打开进行回放的线程函数
void CMainFrame::GetDataFromlocal(TbSignal &signal, CAirCraftCasingVibrateSystemView *view){
	SignalFileHeader signalFileHeader;
	//1、跳过文件头
	CString fileName = signal.GetDataUrl();
	ifstream inputStream = CFileUtil::GetIfstreamByFileName(fileName);
	inputStream.seekg(sizeof(SignalFileHeader), ios_base::beg);
	int collectionPoints = 20000;
	double interval = (double)theApp.m_currentProject.GetCollectionparas().GetSampleFrequency().second / (theApp.FFTRATE * theApp.m_currentProject.GetCollectionparas().GetLine());
	SmartArray<double> xData; ///x坐标
	SChartXYPoint* pPoints = new SChartXYPoint[theApp.m_currentProject.GetCollectionparas().GetLine()];
	for (int i = 0; i < theApp.m_currentProject.GetCollectionparas().GetLine(); i++){
		pPoints[i].X = i * interval;
	}
	//2、循环读取数据
	long long fileSize = CFileUtil::GetFileSize(fileName);
	while (!inputStream.eof()&&theApp.m_iplaybackState){
		if (theApp.m_icollectState == 2){
			Sleep(20);
			continue;
		}
		///从文件中拿到collectionPoints条数据
		double * fftwInputArray;//傅里叶输入
		m_signalController.GetCollectionData(inputStream, fileSize, collectionPoints, fftwInputArray);
		int pointsCount = _msize(fftwInputArray) / sizeof(*fftwInputArray);
		if (pointsCount == 0){
			break;
		}


		//int pointCount = _msize(fftinput) / sizeof(*fftinput);
		//int line = pointCount / 2;
		//double interval = (double)theApp.m_currentProject.GetCollectionparas().GetSampleFrequency().second / (line * 2);
		//SChartXYPoint * pPoints = new SChartXYPoint[line];
		////对传入的数据进行傅里叶变换处理
		//SmartFFTWComplexArray fftwOutput(pointCount);
		//FFTWUtil::FastFourierTransformation(pointCount, fftinput, fftwOutput.GeFFTWComplexArray());
		////将处理之后的傅里叶变换转换成XY坐标
		//float yMax = 0;
		//fftw_complex * out = fftwOutput.GeFFTWComplexArray();
		//pPoints[0].Y = 0;
		//for (int i = 1; i < line; i++)
		//{
		//	int j = 2 * sqrt(out[i][0] * out[i][0] + out[i][1] * out[i][1]);
		//	pPoints[i].X = i * interval;
		//	pPoints[i].Y = 2 * sqrt(out[i][0] * out[i][0] + out[i][1] * out[i][1]);
		//	yMax = max(yMax, pPoints[i].Y);
		//}

		view->PushEchoSignal(fftwInputArray);
		Sleep(600);
		//SmartFFTWComplexArray fftwOutput(pointsCount);
		////对传入的数据进行傅里叶变换处理
		//
		//FFTWUtil::FastFourierTransformation(pointsCount, fftwInputArray,fftwOutput.GeFFTWComplexArray());
		////将处理之后的傅里叶变换转换成XY坐标
		//SmartArray<double> yData; ///y坐标

		//FFTWUtil::FFTDataToXY(fftwOutput, pPoints, fftwInputArray.size());
		
	}
	inputStream.close();
}
void CMainFrame::Pre_GetDataFromlocal(){
	///本地文件存在，直接读取本地文件
	/////文件指针定位到开始采集的文件位置
	SignalFileHeader signalFileHeader;
	SmartArray<double> xData; ///x坐标
	fftw_complex fftw;///单次傅立叶变换的输入
	///当前状态是正在回放或者暂停回放，且循环读取数据以显示
	//while (theApp.m_iplaybackState != 0 && m_inputStream.tellg() < m_recordSignal.GetEndPos()){
	int collectionPoints = 20000;
	//m_recordSignal.SetEndPos(m_icollectionPoints);theApp.m_currentProject.GetCollectionparas().GetLine()*2
	int channelCount = m_selectedSumSignal.GetAllSignal().size();
	for (int i = 0; i < channelCount; i++){
		SmartArray<double> yData; ///y坐标
		vector<double> data;
		CString fileName = m_selectedSumSignal.GetAllSignal()[i].GetDataUrl();
		ifstream inputStream = CFileUtil::GetIfstreamByFileName(fileName);
		inputStream.seekg(sizeof(SignalFileHeader), ios_base::beg);
		///从文件中拿到collectionPoints条数据
		double * fftwInputArray;//傅里叶输入
		m_signalController.GetCollectionData(inputStream, CFileUtil::GetFileSize(fileName), collectionPoints, fftwInputArray);
		//SmartFFTWComplexArray fftwOutput(fftwInputArray.size());
		////对传入的数据进行傅里叶变换处理
		//FFTWUtil::FastFourierTransformation(fftwInputArray.size(), fftwInputArray.GetSmartArray(),
		//	fftwOutput.GeFFTWComplexArray());
		////将处理之后的傅里叶变换转换成XY坐标
		//FFTWUtil::FFTDataToXY(fftwOutput, pPoints, fftwInputArray.size());
		theApp.m_vsignalCaptureView[i]->SetEchoSignal(fftwInputArray);
		inputStream.close();
	}

}
void CMainFrame::OnUpdateSlider1(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码  
	pCmdUI->Enable(TRUE); //即激活滑动条。  
}
void CMainFrame::OnSlider1()
{
	// TODO: 在此添加命令处理程序代码  
	CMFCRibbonSlider* pSlider = DYNAMIC_DOWNCAST(CMFCRibbonSlider, m_wndRibbonBar.FindByID(ID_SLIDER1));
	int pos = pSlider->GetPos();//将此时滑动条所在位置的值赋给pos。  
}

void CMainFrame::RedisHandel(){
	theApp.m_redisContext = theApp.m_redisConnect->connectToRedis();
}


void CMainFrame::RedisSetCollectionData(CString channelCode, CString jsonData){

	redisReply *reply;
	reply = (redisReply *)redisCommand(theApp.m_redisContext, "LPUSH redisCollectionData-%s %s", channelCode, jsonData);
	freeReplyObject(reply);

}
CString CMainFrame::RedisGetPredictedResult(CString channelCode){
	redisReply *reply;
	reply = (redisReply*)redisCommand(theApp.m_redisContext, "LPOP predictResult-%s", channelCode);
	string redisResult = reply->str;
	CString redisResult_c = redisResult.c_str();
	freeReplyObject(reply);
	return redisResult_c;
	
}

void CMainFrame::OpenThread2RedisSaveData(){
	thread t(&CMainFrame::SaveRedisSumCollectionData, this);
	t.detach();
}

void CMainFrame::SaveRedisSumCollectionData(){

	theApp.m_redisIsSave = true;
	map<CString, ThreadSafeQueue<double>>::iterator iter = this->m_redisCollectionDataQueue.begin();
	vector<thread> threadVector;//size = 4
	while (iter != this->m_redisCollectionDataQueue.end()){
		
		threadVector.push_back(thread(&CMainFrame::SaveRedisCollectionData, this, iter->first));
		iter++;
	}
	for (int i = 0; i < threadVector.size(); i++){
		threadVector[i].join();
	}
	//所有线程都完事了，执行保存操作
	theApp.m_redisIsSave = false;

}

void CMainFrame::SaveRedisCollectionData(CString signalCode){

	CString code = signalCode;
	ThreadSafeQueue<double> saveData;
	while (theApp.m_icollectState){
		if (theApp.m_icollectState == 2){
			//暂停状态就卡在这
			Sleep(10);
			continue;
		}
		while (m_redisCollectionDataQueue[signalCode].size() > 0){
			//TRACE("\n队列长度%d\n", m_mpcolllectioinDataQueue[signalCode].size());
			saveData.push(*m_redisCollectionDataQueue[signalCode].wait_and_pop());
			/*CString predictRe = this->RedisGetPredictedResult(signalCode);
			this->m_modelPredictResult[signalCode].push(predictRe);*/
			if (saveData.size() == theApp.m_icollectSignalsStoreCount){
				//ThreadSafeQueue<double> acquireSignal = move(saveData);
				CString jsonStr = m_jsonUtil->DataSerialize(saveData);
				this->RedisSetCollectionData(signalCode,jsonStr);
				}
			
			}
		}
	
	//点完停止采集之后，还有数据需要保存！！！
	while (m_redisCollectionDataQueue[signalCode].size() > 0){
		saveData.push(*m_redisCollectionDataQueue[signalCode].wait_and_pop());
		//ThreadSafeQueue<double> acquireSignal = move(saveData);
		CString jsonStr = m_jsonUtil->DataSerialize(saveData);
		this->RedisSetCollectionData(signalCode, jsonStr);
	}

}

void CMainFrame::OpenThreadReadPredictResult(){
	thread t(&CMainFrame::ReadPredictResult, this);
	t.detach();
}

void CMainFrame::ReadPredictResult(){

	map<CString, ThreadSafeQueue<CString>>::iterator iter = this->m_modelPredictResult.begin();
	vector<thread> threadVector;//size = 4
	while (iter != this->m_modelPredictResult.end()){
		threadVector.push_back(thread(&CMainFrame::ReadEveryPredictResult, this, iter->first));
		iter++;
	}
	for (int i = 0; i < threadVector.size(); i++){
		threadVector[i].join();
	}
}

void CMainFrame::ReadEveryPredictResult(CString signalCode){

	redisReply *reply;
	redisReply *reply_len;
	reply_len = (redisReply*)redisCommand(theApp.m_redisContext, "LLEN predictResult-%s", signalCode);
	CString code = signalCode;
	while (theApp.m_icollectState){
		if (theApp.m_icollectState == 2){
			//暂停状态就卡在这
			Sleep(10);
			continue;
		}
		reply = (redisReply*)redisCommand(theApp.m_redisContext, "LPOP predictResult-%s", signalCode);
		string redisResult = reply->str;
		CString redisResult_c = redisResult.c_str();
		this->m_modelPredictResult[signalCode].push(redisResult_c);	
			
	}
	freeReplyObject(reply);
	freeReplyObject(reply_len);
}


void CMainFrame::AcquireResult(){

	redisReply *reply;
	while (true){
		for (int i = 0; i < 4; i++){
			
			CString str;
			str.Format("%d", i);
			CString signalCode = "0-" + str;
			reply = (redisReply*)redisCommand(theApp.m_redisContext, "LPOP predictResult-%s", signalCode);
			CString redisResult = reply->str;
			this->m_modelPredictResult[signalCode].push(redisResult);


		}
	}
	
	freeReplyObject(reply);


}



void CMainFrame::InitRedisDatabase(){

	redisReply *reply;
	reply = (redisReply*)redisCommand(theApp.m_redisContext, "DEL predictResult-0-0");
	reply = (redisReply*)redisCommand(theApp.m_redisContext, "DEL predictResult-0-1");
	reply = (redisReply*)redisCommand(theApp.m_redisContext, "DEL predictResult-0-2");
	reply = (redisReply*)redisCommand(theApp.m_redisContext, "DEL predictResult-0-3");
	reply = (redisReply*)redisCommand(theApp.m_redisContext, "DEL redisCollectionData-0-0");
	reply = (redisReply*)redisCommand(theApp.m_redisContext, "DEL redisCollectionData-0-1");
	reply = (redisReply*)redisCommand(theApp.m_redisContext, "DEL redisCollectionData-0-2");
	reply = (redisReply*)redisCommand(theApp.m_redisContext, "DEL redisCollectionData-0-3");
	freeReplyObject(reply);
	
}