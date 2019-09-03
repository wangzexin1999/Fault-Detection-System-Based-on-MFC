// ��� MFC ʾ��Դ������ʾ���ʹ�� MFC Microsoft Office Fluent �û����� 
// (��Fluent UI��)����ʾ�������ο���
// ���Բ��䡶Microsoft ������ο����� 
// MFC C++ ������渽����ص����ĵ���  
// ���ơ�ʹ�û�ַ� Fluent UI ����������ǵ����ṩ�ġ�  
// ��Ҫ�˽��й� Fluent UI ��ɼƻ�����ϸ��Ϣ�������  
// http://go.microsoft.com/fwlink/?LinkId=238214��
//
// ��Ȩ����(C) Microsoft Corporation
// ��������Ȩ����

// MainFrm.cpp : CMainFrame ���ʵ��

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "NewProjectView.h"
#include "MainFrm.h"
#include "ProjectManageView.h"
#include "SignalDataView.h"
#include "EngineerUnitView.h"
#include "DetectDeviceManageView.h"
#include "ProductManageView.h"
#include "AlarmParaSetView.h"
#include "ChartCtrl/DuChartCtrlStaticFunction.h"
#include "FileUtil.h"

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
	ON_COMMAND(ID_CHECK2, &CMainFrame::OnViewChannelPara)
	ON_UPDATE_COMMAND_UI(ID_CHECK2, &CMainFrame::OnUpdateViewChannelPara)
	ON_COMMAND(ID_CHECK3, &CMainFrame::OnViewSystemPara)
	ON_UPDATE_COMMAND_UI(ID_CHECK3, &CMainFrame::OnUpdateViewSystemPara)
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
	ON_COMMAND(ID_BUTTON_DETECT_DEVICE, &CMainFrame::OnButtonDetectDevice)
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
END_MESSAGE_MAP()

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO:  �ڴ���ӳ�Ա��ʼ������
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
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	// ����Ĭ����ʾ�����
	m_wndRibbonBar.SetActiveCategory(m_wndRibbonBar.GetCategory(3));
	CString strTitlePane1;
	CString strTitlePane2;
	bNameValid = strTitlePane1.LoadString(IDS_STATUS_PANE1);
	ASSERT(bNameValid);
	bNameValid = strTitlePane2.LoadString(IDS_STATUS_PANE2);
	ASSERT(bNameValid);
	m_wndStatusBar.AddElement(new CMFCRibbonStatusBarPane(ID_STATUSBAR_PANE1, strTitlePane1, TRUE), strTitlePane1);
	m_wndStatusBar.AddExtendedElement(new CMFCRibbonStatusBarPane(ID_STATUSBAR_PANE2, strTitlePane2, TRUE), strTitlePane2);


	if (!m_systemPara.Create(_T("ϵͳ����"), this, CRect(0, 0, 200, 100), TRUE, 10000,
		WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS |
		WS_CLIPCHILDREN | CBRS_LEFT | CBRS_FLOAT_MULTI))
	{
		return FALSE;
	}
	if (!m_channelPara.Create(_T("ͨ������"), this, CRect(0, 0, 200, 100), TRUE, 10033,
		WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS |
		WS_CLIPCHILDREN | CBRS_BOTTOM | CBRS_FLOAT_MULTI))
	{
		return FALSE;
	}
	m_systemPara.EnableDocking(CBRS_ALIGN_ANY);
	m_channelPara.EnableDocking(CBRS_ALIGN_ANY);
	DockPane(&m_channelPara);// BOTTOM
	DockPane(&m_systemPara);// LEFT
	// ���� Visual Studio 2005 ��ʽͣ��������Ϊ
	CDockingManager::SetDockingMode(DT_SMART);
	// ���� Visual Studio 2005 ��ʽͣ�������Զ�������Ϊ
	EnableAutoHidePanes(CBRS_ALIGN_ANY);

	// ����������: 
	if (!CreateCaptionBar())
	{
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}
	// ���ڳ־�ֵ�����Ӿ�����������ʽ
	OnApplicationLook(theApp.m_nAppLook);

	// ������ǿ�Ĵ��ڹ���Ի���
	EnableWindowsDialog(ID_WINDOW_MANAGER, ID_WINDOW_MANAGER, TRUE);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWndEx::PreCreateWindow(cs) )
		return FALSE;
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	return TRUE;
}

BOOL CMainFrame::CreateCaptionBar()
{
	if (!m_wndCaptionBar.Create(WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS, this, ID_VIEW_CAPTION_BAR, -1, TRUE))
	{
		TRACE0("δ�ܴ���������\n");
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

// CMainFrame ���

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


// CMainFrame ��Ϣ�������

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


////��ʼ���ɼ�����vector
void CMainFrame::InitializeCaptureView(){
	// ��ʾ
	POSITION curTemplatePos = theApp.GetFirstDocTemplatePosition();
	CDocTemplate *m_doc = theApp.GetNextDocTemplate(curTemplatePos);
	//����ĵ�:
	curTemplatePos = m_doc->GetFirstDocPosition();
	int viewNumber = 0;
	while(curTemplatePos != NULL){
		CAirCraftCasingVibrateSystemDoc * pdoc = (CAirCraftCasingVibrateSystemDoc*)m_doc->GetNextDoc(curTemplatePos);
		//�����ͼ:
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

void CMainFrame::OnViewChannelPara()
{
	if (m_channelPara.IsVisible())
	{
		m_channelPara.ShowPane(FALSE, FALSE, FALSE);
	}
	else
	{
		m_channelPara.RefreshView();
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


// �½���Ŀ
void CMainFrame::OnButtonNewProject()
{
	//�򿪴���
	CNewProjectView newProjectView;
	newProjectView.DoModal();

}

// ��Ŀ����
void CMainFrame::OnButtonProjectManage()
{
	CProjectManageView projectView;
	int  i = projectView.DoModal();
	///����ˢ�������ڱ������Ϣ
	SendMessage(WM_SETTEXT);
}

// �������ļ�
void CMainFrame::OnButtonOpenDataFile()
{
	// TODO:  �ڴ���������������
	CSignalDataView signalDataView;
	signalDataView.DoModal();
}


// ����ͨ������
void CMainFrame::OnButtonExportChannelPara()
{
	// TODO:  �ڴ���������������
}

//����ͨ������
void CMainFrame::OnButtonImportChannelPara()
{
	// TODO:  �ڴ���������������
}

// ����ϵͳ����
void CMainFrame::OnButtonExportSysPara()
{
	// TODO:  �ڴ���������������
}

// ����ϵͳ����
void CMainFrame::OnButtonImportSysPara()
{
	// TODO:  �ڴ���������������
}


//��ͣ�ɼ�
void CMainFrame::OnButtonSuspendCapture()
{
	theApp.m_icollectionStatus = 2;
}


//��ʼ�ɼ�
void CMainFrame::OnButtonStartCapture()
{
	// ���õײ�������Ϊ�Զ�
	int projectId = theApp.m_currentProject.GetProjectId();
	if (projectId <= 0){
		AfxMessageBox("���ȴ򿪻����½���Ŀ");
		return;
	}
	////m_icollectionStatus == 0 ��δ�ɼ�
	if (!theApp.m_icollectionStatus){
		//// ��ʼ���ɼ�����View
		InitializeCaptureView();
		//// �����źŲɼ�״̬Ϊ1
		theApp.m_icollectionStatus = 1;

		//// ������ʾ��Ϣ�̱߳�־
		//theApp.m_bShowInfThreadActive = true;

		//// ����ͨ������
		//CalculateChannelNum(m_nChannelNums);

		///// ��ʼ���źŲɼ�View

		for (int i = 0; i < m_vsignalCaptureView.size(); i++){
			///������ݶ��е��ɼ����ݶ��м���
			////�����������ݸ�ֵ
				for (int m = 0; m < 100; m++)
				{
					for (int n = 0; n < 1000; n++)
					{
						m_vsignalCaptureView[i]->m_readFromCSVFile[m][n] = theApp.tempRead[m][n];
					}
				}
		}
		/////����ɼ�������Ϣ
		CollectionDataInfoDlg m_collectionDataInfoDlg;
		m_collectionDataInfoDlg.DoModal();
		
		if (theApp.m_collectionRotatingSpeed == ""){ theApp.m_icollectionStatus = 0; return; }

		////�������д��ڵĲɼ��߳�
		for (int i = 0; i < m_vsignalCaptureView.size(); i++){
			m_vsignalCaptureView[i]->OpenThread2CaptureData();
		}
	}
	SetTimer(99, 1000, NULL);
}

// ֹͣ�ɼ�
void CMainFrame::OnBtnStopCapture()
{
	theApp.m_icollectionStatus = 0;
	KillTimer(99);
}

// ֹͣ�ط�
void CMainFrame::OnBtnStopPlayback()
{
	// TODO:  �ڴ���������������
}

//��ʼ�ط�
void CMainFrame::OnBtnStartPlayback()
{
	// TODO:  �ڴ���������������
}

// �ر����д���
void CMainFrame::OnBtnCloseAllWindow()
{
	// TODO:  �ڴ���������������
}

/*����豸����*/
void CMainFrame::OnButtonDetectDevice()
{
	// TODO:  �ڴ���������������
	CDetectDeviceManageView detectDeviceManageView;
	detectDeviceManageView.DoModal();
}

/*��Ʒ����*/
void CMainFrame::OnButtonProduct()
{
	// TODO:  �ڴ���������������
	CProductManageView productManegeView;
	productManegeView.DoModal();
}

//��ʼ����
void CMainFrame::OnBtnStartSmaple()
{
	int projectId = theApp.m_currentProject.GetProjectId();
	if (projectId <= 0){
		AfxMessageBox("���ȴ򿪻����½���Ŀ");
		return;
	}
	theApp.m_bIsSample = true;
}

// ֹͣ����
void CMainFrame::OnBtnStopSample()
{
	theApp.m_bIsSample = false;
	//�������вɼ�����ȥ�����������
	for (int i = 0; i < m_vsignalCaptureView.size(); i++){
		m_vsignalCaptureView[i]->OpenThread2SaveSampleData();
	}

}

//���̵�λ
void CMainFrame::OnBtnEngineeringUnit()
{
	// TODO:  �ڴ���������������
	CEngineerUnitView engineerUnitView;
	engineerUnitView.DoModal();
}

// ��������
void CMainFrame::OnBtnAlarmSet()
{
	// TODO:  �ڴ���������������
	CAlarmParaSetView alarmView;
	alarmView.DoModal();

}

// ����Ŵ�
void CMainFrame::OnBtnTransverseAmplification()
{
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	CDuChartCtrlStaticFunction::HengxiangFangda(&view->GetChartCtrl());
}

// ������С
void CMainFrame::OnBtnHorizontalReduction()
{
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	CDuChartCtrlStaticFunction::HengxiangSuoxiao(&view->GetChartCtrl());

}

// ������С
void CMainFrame::OnBtnVerticalReduction()
{
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	CDuChartCtrlStaticFunction::ZongxiangSuoxiao(&view->GetChartCtrl());
}

//����Ŵ�
void CMainFrame::OnBtnVerticalAmplification()
{
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	CDuChartCtrlStaticFunction::ZongxiangFangda(&view->GetChartCtrl());
}

//�����
void CMainFrame::OnBtnSingleCursor()
{
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	CDuChartCtrlStaticFunction::SetCursorSingle(&view->GetChartCtrl());
}

//��ֵ
void CMainFrame::OnBtnPeakValue()
{
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	CDuChartCtrlStaticFunction::SetCursorPeak(&view->GetChartCtrl());
}


// �Զ��̶�
void CMainFrame::OnBtnAutoScale()
{
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	CDuChartCtrlStaticFunction::AutoXScale(&view->GetChartCtrl(), FALSE);
	//CDuChartCtrlStaticFunction::AutoYScale(&view->GetChartCtrl(), FALSE);

}

// Ĭ�Ͽ̶�
void CMainFrame::OnBtnDefaultScale()
{
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	//CDuChartCtrlStaticFunction::SetCursorNone(&view->GetChartCtrl());
	CChartStandardAxisDu * leftAxis = (CChartStandardAxisDu*)view->GetChartCtrl().GetAxisDu(CChartCtrl::LeftAxis, 0);
	CChartStandardAxisDu * bottomAxis = (CChartStandardAxisDu*)view->GetChartCtrl().GetAxisDu(CChartCtrl::BottomAxis, 0);
	bottomAxis->SetMinMax(0, 1000);//�����¿̶�
	bottomAxis->SetTickIncrement(false, 100);

	leftAxis->SetMinMax(-0.1, 0.1);
	leftAxis->SetTickIncrement(false, 0.05);
}

// �޹��
void CMainFrame::OnBtnNoCorror()
{
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	CDuChartCtrlStaticFunction::SetCursorNone(&view->GetChartCtrl());
}

void CMainFrame::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	// ʵʱ����
	if (nIDEvent == 99)
	{
		RealTimeSignal2Server();
	}
	CMDIFrameWndEx::OnTimer(nIDEvent);
}

void CMainFrame::RealTimeSignal2Server()
{
	vector<CString> jsonStr;
	CString str2JSON = "";
	CString separator = "";////���ŷָ���
	// ת���ַ���
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
	//����
	//theApp.m_redisCon->SetValue("11", str2JSON.GetBuffer());

}


///�������޸ĵ���Ӧ�¼�
LRESULT CMainFrame::OnSetText(WPARAM wParam, LPARAM lParam)
{
	CString title;
	CString product = "δ֪��Ʒ";
	CString project = "δ֪��Ŀ";
	CString rotatingSpeed ="δ֪ת��";
	CString tester = "δ֪��";
	CString sensor = "δ֪������";

	if (theApp.m_currentProject.GetProduct().GetProductType() != "") product = theApp.m_currentProject.GetProduct().GetProductType();
	if (theApp.m_currentProject.GetProjectName() != "") project = theApp.m_currentProject.GetProjectName();
	if (theApp.m_currentProject.GetTester().GetTesterName() != "") tester = theApp.m_currentProject.GetTester().GetTesterName();
	if (theApp.m_collectionRotatingSpeed != "") rotatingSpeed = theApp.m_collectionRotatingSpeed;
	
	CAirCraftCasingVibrateSystemView *selectedView;
	selectedView = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	if (selectedView != NULL) sensor = selectedView->GetDocument()->GetTitle();
	title = product + "-" + project + "-" + rotatingSpeed + "-" + tester + "-" + "(" + sensor + ")";

	lParam = (LPARAM)title.GetBuffer();
	DefWindowProc(WM_SETTEXT, wParam, lParam);
	Invalidate();
	return 0;
}
