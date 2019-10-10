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

#include "include/rapidjson/document.h"
#include "include/rapidjson/writer.h"
#include "include/rapidjson/stringbuffer.h"
#include "ProjectController.h"
using namespace std;
using namespace rapidjson;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWndEx)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWndEx)
	ON_WM_CREATE()
	ON_MESSAGE(WM_SETTEXT, &CMainFrame::OnSetText)
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
	ON_COMMAND(ID_BTN_CLOSE_ALL_WINDOW, &CMainFrame::OnBtnCloseAllWindow)

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
	ON_COMMAND(ID_BUTTON9, &CMainFrame::OnButton9)
	ON_COMMAND(ID_CHECK_STA_SET, &CMainFrame::OnCheckStaSet)
	ON_UPDATE_COMMAND_UI(ID_CHECK_STA_SET, &CMainFrame::OnUpdateCheckStaSet)
	ON_WM_CLOSE()
	ON_MESSAGE(StatusInfMessage, OnStatusInf)
	ON_COMMAND(ID_BUTTON_OPENCOLLECTIONPLANMANAGE, &CMainFrame::OnButtonOpenCollectionPlanManage)
	ON_COMMAND(ID_BUTTON_OPENPROJECTVIEW, &CMainFrame::OnButtonOpenProjectView)
	ON_COMMAND(ID_BUTTON_OPEN_PROJECTSET_VIEW, &CMainFrame::OnButtonOpenProjectSetView)
END_MESSAGE_MAP()

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO:  在此添加成员初始化代码
	theApp.m_nAppLook = theApp.GetInt(_T("ApplicationLook"), ID_VIEW_APPLOOK_WINDOWS_7);
}

CMainFrame::~CMainFrame(){

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
	CMFCRibbonPanel *pPanel = pCategory->GetPanel(6);
	/*显示当前用的传感器*/
	vector<TbSensor> vSensor = theApp.m_currentProject.GetSensorVector();
	for (int i = 0; i < vSensor.size(); i++)
	{
		pPanel->Add(new CMFCRibbonButton(i+10000, _T(vSensor[i].GetSensorDesc()), 3, -1));
	}


	if (!m_systemPara.Create(_T("系统参数"), this, CRect(0, 0, 200, 100), TRUE, 10000,
		WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS |
		WS_CLIPCHILDREN | CBRS_LEFT | CBRS_FLOAT_MULTI))
	{
		return FALSE;
	}

	if (!m_stateSet.Create(_T("状态设置"), this, CRect(0, 0, 200, 100), TRUE, 10034,
		WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS |
		WS_CLIPCHILDREN | CBRS_LEFT | CBRS_FLOAT_MULTI)) //CBRS_RIGHT
	{
		return FALSE;
	}


	if (!m_channelPara.Create(_T("通道参数"), this, CRect(0, 0, 200, 100), TRUE, 10033,
		WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS |
		WS_CLIPCHILDREN | CBRS_BOTTOM | CBRS_FLOAT_MULTI))
	{
		return FALSE;
	}
	
	m_systemPara.EnableDocking(CBRS_ALIGN_ANY);
	m_channelPara.EnableDocking(CBRS_ALIGN_ANY);
	m_stateSet.EnableDocking(CBRS_ALIGN_ANY);
	DockPane(&m_channelPara);// BOTTOM
	DockPane(&m_systemPara);// LEFT
	DockPane(&m_stateSet);// RIGHT
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
	m_wndStatusBar.AddElement(new CMFCRibbonStatusBarPane(10001, _T("版权所有 哈尔滨理工大学人工智能实验室"), hBmpAnimationList, clrTrnsp), _T("版权"));
	SendMessage(StatusInfMessage);
	/*状态栏显示时间*/
	SetTimer(66, 1000, NULL);//安装定时器，并将其时间间隔设为1000毫秒
	SendMessage(StatusInfMessage);
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWndEx::PreCreateWindow(cs) )
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
void CMainFrame::InitializeCaptureView(int nWindowInitial){
	// 显示
	POSITION curTemplatePos = theApp.GetFirstDocTemplatePosition();
	CDocTemplate *m_doc = theApp.GetNextDocTemplate(curTemplatePos);
	//获得文档:
	curTemplatePos = m_doc->GetFirstDocPosition();
	int viewNumber = nWindowInitial;
	while(curTemplatePos != NULL){
		CAirCraftCasingVibrateSystemDoc * pdoc = (CAirCraftCasingVibrateSystemDoc*)m_doc->GetNextDoc(curTemplatePos);
		//获得视图:
		POSITION curViewPos;
		curViewPos = pdoc->GetFirstViewPosition();
		while (curViewPos != NULL)
		{
			CAirCraftCasingVibrateSystemView* currentView = (CAirCraftCasingVibrateSystemView*)pdoc->GetNextView(curViewPos);
			currentView->SetViewNumber(viewNumber);
			currentView->ResetView();
			m_vsignalCaptureView.push_back(currentView);
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
			m_vsignalCaptureView.push_back(currentView);
		}
		viewNumber++;
	}
}

////通道參數
void CMainFrame::OnViewChannelPara()
{
	if (m_channelPara.IsVisible())
	{
		m_channelPara.ShowPane(FALSE, FALSE, FALSE);
	}
	else
	{
		m_channelPara.ShowPane(TRUE, TRUE, TRUE);
	}

	RecalcLayout(FALSE);
}

void CMainFrame::OnUpdateViewChannelPara(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_channelPara.IsVisible());
}


void CMainFrame::OnViewSystemPara()
{
	if (m_systemPara.IsVisible())
	{
		m_systemPara.ShowPane(FALSE, FALSE, FALSE);
	}
	else
	{
		m_systemPara.ShowPane(TRUE, TRUE, TRUE);
	}

	RecalcLayout(FALSE);
}

void CMainFrame::OnUpdateViewSystemPara(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_systemPara.IsVisible());
}

// 新建项目
void CMainFrame::OnButtonNewProject()
{
	//打开窗口
	CNewProjectView newProjectView;
	int res =  newProjectView.DoModal();
	if (res == IDOK){
		//根据选择的项目刷新窗口
		//1.生成指定数量的传感器采集窗口，并给每个传感器采集窗口设置传感器
		CloseAllWindows();
		CreateSensorWindow(theApp.m_currentProject.GetSensorVector());
		WindowsVertical();
		//2.刷新关于项目的显示
		////2.1 刷新项目标题的显示
		SendMessage(WM_SETTEXT);
		SendMessage(StatusInfMessage);
		////2.2 刷新采集参数的显示
		m_systemPara.RefreshView();
		////2.3 刷新通道参数的显示
		m_channelPara.RefreshView();
		////2.4 刷新采集状态窗口的显示
		m_stateSet.RefreshView();
	}
}

// 项目管理
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
		TbRecordSignal selectedSignal = sampleDataView.GetSelectedRecordSignal();
		Document doc;
		doc.Parse(selectedSignal.GetSensorInfo());
		if (doc.HasParseError()){ return; }
		///拿到通道个数
		int channelCount = doc["channelCount"].GetInt();
		///拿到通道的序列号
		const Value& channelsId = doc["channelsId"];
		///每个通道也许会对应多条采集数据
		vector<vector<TbSignal>> collectionData;
		for (int i = 0; i < channelCount;i++){
			////查询信号的对象
			TbSignal searchSignalEntity;
			searchSignalEntity.SetStartTime(selectedSignal.GetStartTime());
			searchSignalEntity.SetEndTime(selectedSignal.GetEndTime());
			searchSignalEntity.SetProductId(selectedSignal.GetProduct().GetProductId());
			searchSignalEntity.SetProjectId(selectedSignal.GetProject().GetProjectId());
			searchSignalEntity.SetTestingDeviceId(selectedSignal.GetTestingDevice().GetId());
			searchSignalEntity.SetCollectionStatus(selectedSignal.GetCollectionStatus());
			searchSignalEntity.SetSensorId(channelsId[i].GetString());
			vector<TbSignal> signalVec;
			m_signalController.FindAllSignalBySearchCondition(searchSignalEntity, signalVec);
			collectionData.push_back(signalVec);
		}
		// 如果可以连接服务器，根据条件查询服务器数据
		// 否则查询本体数据
		if (strcmp(theApp.PDsql.m_mysql.host, "127.0.0.1") == 0)/*连接本地*/
		{
			//查询传感器个数
			int nSersor = 4;
			CMainFrame*pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
			CloseAllWindows();
			// 打开窗口
			NewDoc(nSersor);
			// 初始化view
			InitializeSampleDataEchoView(16);
			bool bOpenDataFile;
			/*文件路径vector*/
			vector<CString> vFilePaths;
			// 根据传感器信息查找文件路径
			for (int i = 0; i < m_vsignalCaptureView.size(); i++)
			{
				/*汇总路径*/
				for (int j = 0; j < collectionData[i].size(); j++)
				{
					vFilePaths.push_back(collectionData[i][j].GetDataUrl());

				}
				//vFilePaths.push_back(collectionData[1][0].GetDataUrl());
				// 根据路径查找文件，放到各自的view采样队列里面
				bOpenDataFile = CFileUtil::ReadSampleDataByPaths(vFilePaths,
					m_vsignalCaptureView[i]->m_sampleFromFileDataQueue);
				vFilePaths.clear();
			}
			if (!bOpenDataFile)
			{
				AfxMessageBox("打开数据文件失败");
			}

			// 窗口水平平铺
			WindowsHorizontal();

		}
		else/*连接服务器*/
		{


		}

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


//暂停采集
void CMainFrame::OnButtonSuspendCapture()
{
	theApp.m_icollectionStatus = 2;
}


//开始采集
void CMainFrame::OnButtonStartCapture()
{
	// 设置底部坐标轴为自动
	int projectId = theApp.m_currentProject.GetProjectId();
	if (projectId <= 0){
		AfxMessageBox("请先打开或者新建项目");
		return;
	}
	////m_icollectionStatus == 0 是未采集
	if (!theApp.m_icollectionStatus){
		//// 初始化采集窗口View
		InitializeCaptureView(0);
		//// 设置信号采集状态为1
		theApp.m_icollectionStatus = 1;

		//// 设置显示信息线程标志
		//theApp.m_bShowInfThreadActive = true;

		//// 计算通道个数
		//CalculateChannelNum(m_nChannelNums);

		///// 初始化信号采集View

		for (int i = 0; i < m_vsignalCaptureView.size(); i++){
			///添加数据队列到采集数据队列集合
			////给传感器数据赋值
				for (int m = 0; m < 100; m++)
				{
					for (int n = 0; n < 1000; n++)
					{
						m_vsignalCaptureView[i]->m_readFromCSVFile[m][n] = theApp.tempRead[m][n];
					}
				}
		}
		/////输入采集数据信息
		/*CollectionDataInfoDlg m_collectionDataInfoDlg;
		m_collectionDataInfoDlg.DoModal();*/
		
		//if (theApp.m_collectionRotatingSpeed == ""){ theApp.m_icollectionStatus = 0; return; }

		////开启所有窗口的采集线程
		for (int i = 0; i < m_vsignalCaptureView.size(); i++){
			m_vsignalCaptureView[i]->OpenThread2CaptureData();
		}
	}
	///实时数据传输
	//SetTimer(99, 1000, NULL);
}

// 停止采集
void CMainFrame::OnBtnStopCapture()
{
	theApp.m_icollectionStatus = 0;
	KillTimer(99);
}

// 停止回放
void CMainFrame::OnBtnStopPlayback()
{
	// TODO:  在此添加命令处理程序代码
	for (int i = 0; i < m_vsignalCaptureView.size(); i++){
		m_vsignalCaptureView[i]->StopSampleEncho();
	}
}

//开始回放
void CMainFrame::OnBtnStartPlayback()
{
	// TODO:  在此添加命令处理程序代码
	////开启所有窗口的采样回放
	for (int i = 0; i < m_vsignalCaptureView.size(); i++){

		m_vsignalCaptureView[i]->StartSampleEncho();
	}
}

// 关闭所有窗口
void CMainFrame::OnBtnCloseAllWindow()
{
	// TODO:  在此添加命令处理程序代码
	// 关闭所有窗口
	CloseAllWindows();
}



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
	if (theApp.m_icollectionStatus ==0)
	{
		AfxMessageBox("当前没有采集状态");
		return;
	}
	/*开始采样，记录开始采集时间*/
	theApp.m_recordSignal.SetStartTime(DateUtil::GetCurrentCStringTime());
	theApp.m_recordSignal.SetProject(theApp.m_currentProject);
	theApp.m_recordSignal.SetProduct(theApp.m_currentProject.GetProduct());
	theApp.m_recordSignal.SetTesingDevice(theApp.m_currentProject.GetTestingDevice());
	theApp.m_recordSignal.SetCollectionStatus(theApp.m_jsonCollectionStatusPara);

}

// 停止采样
void CMainFrame::OnBtnStopSample()
{
	if (theApp.m_recordSignal.GetStartTime() == ""){
		AfxMessageBox("当前未在采集");
		return;
	}
	//////封装json格式的传感器数据。
	//Document doc;
	//Document::AllocatorType& allocator = doc.GetAllocator();
	//Value root(kObjectType);
	//Value channelCount(kNumberType);

	//////计算通道的个数
	//channelCount.SetInt(theApp.m_currentProject.GetSensorVector().size());

	CString sensorInfo = "{\"channelCount\":4,\"channelsId\" : [\"#012s-1\", \"#012s-2\",\"#012s-3\",\"#012s-4\"]}";
	theApp.m_recordSignal.SetSensorInfo(sensorInfo);
	theApp.m_recordSignal.SetEndTime(DateUtil::GetCurrentCStringTime());
	Result res = m_signalController.SaveSampleSignal(theApp.m_recordSignal);
	if (!res.GetIsSuccess()){
		AfxMessageBox("采样数据保存失败");
	}
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
	CDuChartCtrlStaticFunction::SetCursorPeak(&view->GetChartCtrl());
}


// 自动刻度
void CMainFrame::OnBtnAutoScale()
{
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	CDuChartCtrlStaticFunction::AutoXScale(&view->GetChartCtrl(), FALSE);
	//CDuChartCtrlStaticFunction::AutoYScale(&view->GetChartCtrl(), FALSE);

}

// 默认刻度
void CMainFrame::OnBtnDefaultScale()
{
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	//CDuChartCtrlStaticFunction::SetCursorNone(&view->GetChartCtrl());
	CChartStandardAxisDu * leftAxis = (CChartStandardAxisDu*)view->GetChartCtrl().GetAxisDu(CChartCtrl::LeftAxis, 0);
	CChartStandardAxisDu * bottomAxis = (CChartStandardAxisDu*)view->GetChartCtrl().GetAxisDu(CChartCtrl::BottomAxis, 0);
	bottomAxis->SetMinMax(0, 1000);//设置下刻度
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
		pElement->SetText("当前时间："+strTime);
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
	for (int i = 0; i < m_vsignalCaptureView.size(); i++)
	{
		CString tempStr;
		shared_ptr<RealTimeSignal >realTimeSignal = m_vsignalCaptureView[i]->m_realTimeSignal.wait_and_pop();
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
	CString rotatingSpeed ="未知转速";
	CString tester = "未知人";
	CString sensor = "未知传感器";

	if (theApp.m_currentProject.GetProduct().GetProductType() != "") product = theApp.m_currentProject.GetProduct().GetProductType();
	if (theApp.m_currentProject.GetProjectName() != "") project = theApp.m_currentProject.GetProjectName();
	if (theApp.m_currentProject.GetTester().GetTesterName() != "") tester = theApp.m_currentProject.GetTester().GetTesterName();
	if (theApp.m_collectionRotatingSpeed != "") rotatingSpeed = theApp.m_collectionRotatingSpeed;
	
	CAirCraftCasingVibrateSystemView *selectedView = NULL;
	///获取当前的激活窗口
	CWnd* activeWind = (AfxGetApp()->m_pMainWnd);
	if (activeWind != NULL){
		///如果窗口不为空的话
		selectedView = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	}
	if (selectedView != NULL) sensor = selectedView->GetDocument()->GetTitle();
	title = product + "-" + project + "-" + rotatingSpeed + "-" + tester + "-" + "(" + sensor + ")";
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
		InitializeCaptureView(0);
		for (int i = 0; i < m_vsignalCaptureView.size(); i++)
		{	
			m_graphAttributeView.Write2INIFile();
			/*颜色*/
			// 窗口背景
			m_vsignalCaptureView[i]->GetChartCtrl().SetBackColor(m_graphAttributeView.m_colorView.m_colBKColor);
			//图形区域背景
			m_vsignalCaptureView[i]->GetChartCtrl().m_GraphBKColor = m_graphAttributeView.m_colorView.m_colGBKColor;
			// 信息区域背景
			m_vsignalCaptureView[i]->GetChartCtrl().m_shuxing.m_colTBKColor = m_graphAttributeView.m_colorView.m_colTBKColor;
			//光标颜色
			m_vsignalCaptureView[i]->GetChartCtrl().m_shuxing.m_colCursorColor1 = m_graphAttributeView.m_colorView.m_colCursor1;
			// 曲线颜色
			m_vsignalCaptureView[i]->GetChartCtrl().GetSerieFromIndexDu(0)->SetColor(m_graphAttributeView.m_colorView.m_colSerie[0]);
			//网格颜色
			m_vsignalCaptureView[i]->GetChartCtrl().GetAxisDu(CChartCtrl::BottomAxis, 0)->GetGrid()->SetColor(m_graphAttributeView.m_colorView.m_colGridLineColor);
			m_vsignalCaptureView[i]->GetChartCtrl().GetAxisDu(CChartCtrl::LeftAxis, 0)->GetGrid()->SetColor(m_graphAttributeView.m_colorView.m_colGridLineColor);
			// 坐标轴颜色
			m_vsignalCaptureView[i]->GetChartCtrl().GetAxisDu(CChartCtrl::BottomAxis, 0)->SetAxisColor(m_graphAttributeView.m_colorView.m_colXCoor);
			m_vsignalCaptureView[i]->GetChartCtrl().GetAxisDu(CChartCtrl::LeftAxis, 0)->SetAxisColor(m_graphAttributeView.m_colorView.m_colYCoor);
			// 刻度颜色
			m_vsignalCaptureView[i]->GetChartCtrl().GetAxisDu(CChartCtrl::BottomAxis, 0)->SetTextColor(m_graphAttributeView.m_colorView.m_colScale);
			m_vsignalCaptureView[i]->GetChartCtrl().GetAxisDu(CChartCtrl::LeftAxis, 0)->SetTextColor(m_graphAttributeView.m_colorView.m_colScale);
			// 标注颜色
			m_vsignalCaptureView[i]->GetChartCtrl().GetAxisDu(CChartCtrl::BottomAxis, 0)->GetLabel()->SetColor(m_graphAttributeView.m_colorView.m_colScale);
			m_vsignalCaptureView[i]->GetChartCtrl().GetAxisDu(CChartCtrl::LeftAxis, 0)->GetLabel()->SetColor(m_graphAttributeView.m_colorView.m_colScale);

			/*字体*/
			// 坐标轴
			m_vsignalCaptureView[i]->GetChartCtrl().GetAxisDu(CChartCtrl::BottomAxis, 0)->SetFont(
				m_graphAttributeView.m_fontView.m_lFontXCoor.m_lFontSize, m_graphAttributeView.m_fontView.m_lFontXCoor.m_lFont.lfFaceName);
			m_vsignalCaptureView[i]->GetChartCtrl().GetAxisDu(CChartCtrl::LeftAxis, 0)->SetFont(
				m_graphAttributeView.m_fontView.m_lFontYCoor.m_lFontSize, m_graphAttributeView.m_fontView.m_lFontYCoor.m_lFont.lfFaceName);

			// 坐标单位
			m_vsignalCaptureView[i]->GetChartCtrl().GetAxisDu(CChartCtrl::BottomAxis, 0)->GetLabel()->SetFont(
				m_graphAttributeView.m_fontView.m_lFontXUnit.m_lFontSize, m_graphAttributeView.m_fontView.m_lFontXUnit.m_lFont.lfFaceName);

			m_vsignalCaptureView[i]->GetChartCtrl().GetAxisDu(CChartCtrl::LeftAxis, 0)->GetLabel()->SetFont(
				m_graphAttributeView.m_fontView.m_lFontYUnit.m_lFontSize, m_graphAttributeView.m_fontView.m_lFontYUnit.m_lFont.lfFaceName);
			//光标读数

			// 光标标注
			// 统计信息
			// 文本注释
			//工程信息
			/*选项*/
			//统计信息
			m_vsignalCaptureView[i]->GetChartCtrl().m_shuxing.m_bDrawStatValue = m_graphAttributeView.m_selectView.m_bStaValue;
			// 最大值
			m_vsignalCaptureView[i]->GetChartCtrl().m_shuxing.m_bDrawStatMax = m_graphAttributeView.m_selectView.m_bMax;
			// 最小值
			m_vsignalCaptureView[i]->GetChartCtrl().m_shuxing.m_bDrawStatMin = m_graphAttributeView.m_selectView.m_bMin;
			//平均值
			m_vsignalCaptureView[i]->GetChartCtrl().m_shuxing.m_bDrawStatAve = m_graphAttributeView.m_selectView.m_bAve;
			// 峰值
			m_vsignalCaptureView[i]->GetChartCtrl().m_shuxing.m_bDrawStatPeak = m_graphAttributeView.m_selectView.m_bPeak;
			// 有效值
			m_vsignalCaptureView[i]->GetChartCtrl().m_shuxing.m_bDrawStatRms = m_graphAttributeView.m_selectView.m_bEffectiveValue;
			//刷新
			m_vsignalCaptureView[i]->GetChartCtrl().RefreshCtrl();
		}
	}
}

void CMainFrame::CreateSensorWindow(vector<TbSensor> vsensor){

	for (int i = 0; i < vsensor.size(); i++)
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
			pdoc->SetTitle(vsensor[i].GetSensorDesc());
			while (pos != NULL){
				CAirCraftCasingVibrateSystemView* pView = (CAirCraftCasingVibrateSystemView*)pdoc->GetNextView(pos);
				/////设置传感器
				pView->SetSensor(vsensor[i]);
			}
		}
	}
}
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
	
	while ((pFrame->MDIGetActive())!=NULL)
	{
		this->GetActiveFrame()->SendMessage(WM_CLOSE);
	}	

}


// 程序测试
void CMainFrame::OnButton9()
{
	// TODO:  在此添加命令处理程序代码
	vector<CString> test;
	test.push_back("C:\\collectionData\\3-1-1-1-1566998168677.csv");
	test.push_back("C:\\collectionData\\3-1-1-1-1566998168677.csv");
	test.push_back("C:\\collectionData\\3-1-1-1-1566998168677.csv");
	test.push_back("C:\\collectionData\\3-1-1-1-1566998168677.csv");
	test.push_back("C:\\collectionData\\3-1-1-1-1566998168677.csv");
	vector<AcquiredSignal> sampleSignal;
	CFileUtil::ReadSampleDataByPaths(test, sampleSignal);
	
}





void CMainFrame::OnCheckStaSet()
{
	// TODO:  在此添加命令处理程序代码
	if (m_stateSet.IsVisible())
	{
		m_stateSet.ShowPane(FALSE, FALSE, FALSE);
	}
	else
	{
		m_stateSet.ShowPane(TRUE, TRUE, TRUE);
	}

	RecalcLayout(FALSE);
}


void CMainFrame::OnUpdateCheckStaSet(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_stateSet.IsVisible());

}


void CMainFrame::OnClose()
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	KillTimer(StatusBarTimer);
	CMDIFrameWndEx::OnClose();
}


LRESULT CMainFrame::OnStatusInf(WPARAM wParam, LPARAM lParam)
{
	//TODO: Add your message handle code
	CString title;
	CString product = "未知产品";
	CString project = "未知项目";
	CString rotatingSpeed = "未知转速";
	CString tester = "未知人";
	CString sensor = "未知传感器";

	if (theApp.m_currentProject.GetProduct().GetProductType() != "") product = theApp.m_currentProject.GetProduct().GetProductType();
	if (theApp.m_currentProject.GetProjectName() != "") project = theApp.m_currentProject.GetProjectName();
	if (theApp.m_currentProject.GetTester().GetTesterName() != "") tester = theApp.m_currentProject.GetTester().GetTesterName();
	if (theApp.m_collectionRotatingSpeed != "") rotatingSpeed = theApp.m_collectionRotatingSpeed;
	title = product + "-" + project + "-" + rotatingSpeed + "-" + tester;
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
	if (res==IDOK){
		///2.关闭当前显示的所有窗口，根据项目创建项目用到的窗口
		CloseAllWindows();
		CreateSensorWindow(theApp.m_currentProject.GetSensorVector());
		WindowsVertical();
		///3 确定打开项目之后，将此时打开的项目的更新时间设置为此时，保存到数据库
		theApp.m_currentProject.SetProjectUpdateTime(DateUtil::GetCurrentCStringTime());
		Result res = m_projectController.Update(theApp.m_currentProject);
		if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); }
		///发送刷新主窗口标题和状态栏显示的消息
		SendMessage(WM_SETTEXT);
		SendMessage(StatusInfMessage);
	}
}


void CMainFrame::OnButtonOpenProjectSetView()
{
	ProjectSetView projectSetView;
	int  i = projectSetView.DoModal();
}
