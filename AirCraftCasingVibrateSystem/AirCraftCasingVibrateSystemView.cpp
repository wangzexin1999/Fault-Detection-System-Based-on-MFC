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

// AirCraftCasingVibrateSystemView.cpp : CAirCraftCasingVibrateSystemView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "AirCraftCasingVibrateSystem.h"
#endif

#include "AirCraftCasingVibrateSystemDoc.h"
#include "AirCraftCasingVibrateSystemView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAirCraftCasingVibrateSystemView

IMPLEMENT_DYNCREATE(CAirCraftCasingVibrateSystemView, CFormView)

BEGIN_MESSAGE_MAP(CAirCraftCasingVibrateSystemView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_PAINT()
	ON_COMMAND(ID_BUTTON_SIGNAL_SELECT, &CAirCraftCasingVibrateSystemView::OnButtonSignalSelect)
	ON_COMMAND(ID_BUTTON_NEW_PROJECT, &CAirCraftCasingVibrateSystemView::OnButtonNewProject)
	ON_COMMAND(ID_BUTTON2_SAVE_PROJECT, &CAirCraftCasingVibrateSystemView::OnButton2SaveProject)
	ON_COMMAND(ID_BUTTON_PROJECT_MANAGE, &CAirCraftCasingVibrateSystemView::OnButtonProjectManage)
	ON_COMMAND(ID_BUTTON_OPEN_DATA_FILE, &CAirCraftCasingVibrateSystemView::OnButtonOpenDataFile)
	ON_COMMAND(ID_BUTTON_EXPORT_CHANNEL_PARA, &CAirCraftCasingVibrateSystemView::OnButtonExportChannelPara)
	ON_COMMAND(ID_BUTTON_IMPORT_CHANNEL_PARA, &CAirCraftCasingVibrateSystemView::OnButtonImportChannelPara)
	ON_COMMAND(ID_BUTTON_EXPORT_SYS_PARA, &CAirCraftCasingVibrateSystemView::OnButtonExportSysPara)
	ON_COMMAND(ID_BUTTON_IMPORT_SYS_PARA, &CAirCraftCasingVibrateSystemView::OnButtonImportSysPara)
	ON_COMMAND(ID_BUTTON_SUSPEND_CAPTURE, &CAirCraftCasingVibrateSystemView::OnButtonSuspendCapture)
	ON_COMMAND(ID_BUTTON_START_CAPTURE, &CAirCraftCasingVibrateSystemView::OnButtonStartCapture)
	ON_COMMAND(ID_BTN_STOP_CAPTURE, &CAirCraftCasingVibrateSystemView::OnBtnStopCapture)
	ON_COMMAND(ID_BTN_STOP_PLAYBACK, &CAirCraftCasingVibrateSystemView::OnBtnStopPlayback)
	ON_COMMAND(ID_BTN_START_PLAYBACK, &CAirCraftCasingVibrateSystemView::OnBtnStartPlayback)
	ON_COMMAND(ID_BTN_CLOSE_ALL_WINDOW, &CAirCraftCasingVibrateSystemView::OnBtnCloseAllWindow)
	ON_COMMAND(ID_BTN_TRANSVERSE_AMPLIFICATION, &CAirCraftCasingVibrateSystemView::OnBtnTransverseAmplification)
	ON_COMMAND(ID_BTN_HORIZONTAL_REDUCTION, &CAirCraftCasingVibrateSystemView::OnBtnHorizontalReduction)
	ON_COMMAND(ID_BTN_VERTICAL_REDUCTION, &CAirCraftCasingVibrateSystemView::OnBtnVerticalReduction)
	ON_COMMAND(ID_BTN_VERTICAL_AMPLIFICATION, &CAirCraftCasingVibrateSystemView::OnBtnVerticalAmplification)
	ON_COMMAND(ID_BTN_SINGLE_CURSOR, &CAirCraftCasingVibrateSystemView::OnBtnSingleCursor)
	ON_COMMAND(ID_BTN_PEAK_VALUE, &CAirCraftCasingVibrateSystemView::OnBtnPeakValue)
	ON_COMMAND(ID_BTN_AUTO_SCALE, &CAirCraftCasingVibrateSystemView::OnBtnAutoScale)
	ON_COMMAND(ID_BTN_SELF_SCALE, &CAirCraftCasingVibrateSystemView::OnBtnSelfScale)
	ON_COMMAND(ID_BTN_NO_CORROR, &CAirCraftCasingVibrateSystemView::OnBtnNoCorror)
	ON_COMMAND(ID_BTN_START_SMAPLE, &CAirCraftCasingVibrateSystemView::OnBtnStartSmaple)
	ON_COMMAND(ID_BTN_STOP_SAMPLE, &CAirCraftCasingVibrateSystemView::OnBtnStopSample)
	ON_COMMAND(ID_BTN_PROJECT_UNIT, &CAirCraftCasingVibrateSystemView::OnBtnProjectUnit)
	ON_COMMAND(ID_BTN_ALARM_SET, &CAirCraftCasingVibrateSystemView::OnBtnAlarmSet)
	ON_COMMAND(ID_BTN_GRAPH_ATTR, &CAirCraftCasingVibrateSystemView::OnBtnGraphAttr)
	ON_WM_TIMER()
	ON_COMMAND(ID_BUTTON_DETECT_DEVICE, &CAirCraftCasingVibrateSystemView::OnButtonDetectDevice)
	ON_COMMAND(ID_BUTTON_DETECTED_DEVICE, &CAirCraftCasingVibrateSystemView::OnButtonDetectedDevice)
END_MESSAGE_MAP()

// CAirCraftCasingVibrateSystemView ����/����

CAirCraftCasingVibrateSystemView::CAirCraftCasingVibrateSystemView()
	: CFormView(CAirCraftCasingVibrateSystemView::IDD)
{
	// TODO:  �ڴ˴���ӹ������

}

CAirCraftCasingVibrateSystemView::~CAirCraftCasingVibrateSystemView()
{
}

void CAirCraftCasingVibrateSystemView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CAirCraftCasingVibrateSystemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CFormView::PreCreateWindow(cs);
}

void CAirCraftCasingVibrateSystemView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	ResizeParentToFit();
	//�����ؼ���С
	CRect rc;
	GetClientRect(rc);
	rc.DeflateRect(10, 10);
	m_chart.Create(this, rc, theApp.m_chartCtrlIndex);
	rc.left = rc.left + 80;
	m_chart.CheckAutoCenter();
	m_chart.ShowWindow(SW_SHOWNORMAL);
	CDuChartCtrl * pDuChartCtrl = &m_chart;
	pDuChartCtrl->EnableRefresh(false);
	// ��ʾ���ֵ��ͳ��ֵ

	int nSelectChannelCount = 1;
	int nXAxisType = CDuChartCtrlShuxing::typeAxisLine;
	int nYAxisType = CDuChartCtrlShuxing::typeAxisLine;
	int nSerieType = CDuChartCtrlShuxing::typeSerieLine;
	//int nBeipcBarCount = m_nCalcFreCountK + 1;

	// �������
	CDuChartCtrlStaticFunction::RemoveAll(pDuChartCtrl);
	// ����������
	//CDuChartCtrlStaticFunction::CreateAxis(pDuChartCtrl, nSelectChannelCount, nXAxisType, nYAxisType);
	CChartStandardAxisDu* m_pBottomAxis22;
	m_pBottomAxis22 = m_chart.CreateStandardAxisDu(CChartCtrl::BottomAxis, 0);
	m_pBottomAxis22->SetMinMax(0, 1000);//�����¿̶�
	m_pBottomAxis22->SetTickIncrement(false, 100);
	CChartStandardAxisDu* pLeftAxis22 = m_chart.CreateStandardAxisDu(CChartCtrl::LeftAxis, 0);
	pLeftAxis22->SetMinMax(-0.1, 0.1);
	pLeftAxis22->SetTickIncrement(false, 0.05);
	// ��������
	CDuChartCtrlStaticFunction::CreateSeries(pDuChartCtrl, nSelectChannelCount, nSerieType);
	// ������
	CDuChartCtrlStaticFunction::SetCursorNone(pDuChartCtrl);


	// ������
	for (int i = 0; i < nSelectChannelCount; i++)
	{
		CChartAxis * pChartAxis = pDuChartCtrl->GetAxisDu(CChartCtrl::BottomAxis, i);
		if (pChartAxis != NULL)
			pChartAxis->GetLabel()->SetText("Fre[Hz]");
	}

	// ����
	for (int i = 0; i < nSelectChannelCount; i++)
	{
		CChartLineSerieDu * pSerie = (CChartLineSerieDu*)pDuChartCtrl->GetSerieFromIndexDu(i);
		m_pLineSerie = pSerie;
		pSerie->SetName("����");
		//pSerie->SetNeedCalStatValue(true);
	}

	pDuChartCtrl->m_shuxing.m_bDrawStatValue = TRUE;

	//CDuChartCtrlStaticFunction::AutoXScale(pDuChartCtrl, FALSE);
	//CDuChartCtrlStaticFunction::AutoYScale(pDuChartCtrl, FALSE);
	//pDuChartCtrl->SetCursorSingle(FALSE);
	pDuChartCtrl->EnableRefresh(true);
	m_flag = true;
}

void CAirCraftCasingVibrateSystemView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CAirCraftCasingVibrateSystemView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	/*theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
	IDR_MENU_RIGHT_KEY*/
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_MENU_RIGHT_KEY, point.x, point.y, this, TRUE);
#endif
}


// CAirCraftCasingVibrateSystemView ���

#ifdef _DEBUG
void CAirCraftCasingVibrateSystemView::AssertValid() const
{
	CFormView::AssertValid();
}

void CAirCraftCasingVibrateSystemView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CAirCraftCasingVibrateSystemDoc* CAirCraftCasingVibrateSystemView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAirCraftCasingVibrateSystemDoc)));
	return (CAirCraftCasingVibrateSystemDoc*)m_pDocument;
}
#endif //_DEBUG


// CAirCraftCasingVibrateSystemView ��Ϣ�������


void CAirCraftCasingVibrateSystemView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CFormView::OnPaint()
	CRect rc;
	GetClientRect(rc);
	rc.DeflateRect(20, 20);
	//rc.left = rc.left + 80;

	m_chart.MoveWindow(rc);
	m_chart.ShowWindow(SW_SHOWNORMAL);
}

// �ź�ѡ��
void CAirCraftCasingVibrateSystemView::OnButtonSignalSelect()
{
	// TODO:  �ڴ���������������
	m_signalSelectView.DoModal();
}

// �½���Ŀ
void CAirCraftCasingVibrateSystemView::OnButtonNewProject()
{
	//�򿪴���
	m_newProjectView.DoModal();

}

// ������Ŀ
void CAirCraftCasingVibrateSystemView::OnButton2SaveProject()
{
	// TODO:  �ڴ���������������
}

// ��Ŀ����
void CAirCraftCasingVibrateSystemView::OnButtonProjectManage()
{
	// TODO:  �ڴ���������������
	CProjectManageView projectView;
	int  i = projectView.DoModal();
}

// �������ļ�
void CAirCraftCasingVibrateSystemView::OnButtonOpenDataFile()
{
	// TODO:  �ڴ���������������
	int projectId = theApp.m_currentProject.GetProjectId();
	if (projectId <= 0){
		AfxMessageBox("���ȴ򿪻����½���Ŀ");
		return;
	}
	CSignalDataView signalDataView;
	signalDataView.DoModal();
}

// ����ͨ������
void CAirCraftCasingVibrateSystemView::OnButtonExportChannelPara()
{
	// TODO:  �ڴ���������������
}

//����ͨ������
void CAirCraftCasingVibrateSystemView::OnButtonImportChannelPara()
{
	// TODO:  �ڴ���������������
}

// ����ϵͳ����
void CAirCraftCasingVibrateSystemView::OnButtonExportSysPara()
{
	// TODO:  �ڴ���������������
}

// ����ϵͳ����
void CAirCraftCasingVibrateSystemView::OnButtonImportSysPara()
{
	// TODO:  �ڴ���������������
}


//��ͣ�ɼ�
void CAirCraftCasingVibrateSystemView::OnButtonSuspendCapture()
{
	// TODO:  �ڴ���������������
}

//��ʼ�ɼ�
void CAirCraftCasingVibrateSystemView::OnButtonStartCapture()
{
	// TODO:  �ڴ���������������
	
	// ���õײ�������Ϊ�Զ�
	//m_pBottomAxis->SetAutomatic(true);
	int projectId = theApp.m_currentProject.GetProjectId();
	if (projectId <= 0){
		AfxMessageBox("���ȴ򿪻����½���Ŀ");
		return;
	}
	if (!theApp.m_bThreadActive){
		///////����ʱû�п�ʼ�ɼ�
		// ��ʼ��View
		InitializeView();
		// �����
		//m_pLineSerie->ClearSerie();
		// ����ͨ������
		CalculateChannelNum(m_nChannelNums);
		///��ղɼ�����vector
		theApp.m_collectData.clear();
		///��ʼ��ͨ������
		for (int i = 0; i < m_nChannelNums;i++){
			ThreadSafeQueue<AcquiredSignal> acquiredSignalQueue;
			theApp.m_collectData.push_back(acquiredSignalQueue);
		}
		//��ȡ����
		m_signalMainController.StartCaptureData(m_nChannelNums);
		
		m_signalMainController.StartAutoSaveCollectionData();
		//�洢����
		// view��ʾ����
		ShowDataToView(m_nChannelNums);
		// ���ö�ȡ�̱߳�־
		theApp.m_bThreadActive = true;
		// ������ʾ��Ϣ�̱߳�־
		theApp.m_bShowInfThreadActive = true;
	}
}

// ֹͣ�ɼ�
void CAirCraftCasingVibrateSystemView::OnBtnStopCapture()
{
	// TODO:  �ڴ���������������
	for (int i = 11; i < m_nChannelNums + 11; i++)
	{
		KillTimer(i);
	}
	theApp.m_bThreadActive = false;
	theApp.m_bShowInfThreadActive = false;
}

// ֹͣ�ط�
void CAirCraftCasingVibrateSystemView::OnBtnStopPlayback()
{
	// TODO:  �ڴ���������������
}

//��ʼ�ط�
void CAirCraftCasingVibrateSystemView::OnBtnStartPlayback()
{
	// TODO:  �ڴ���������������
}

// �ر����д���
void CAirCraftCasingVibrateSystemView::OnBtnCloseAllWindow()
{
	// TODO:  �ڴ���������������
}

// ����Ŵ�
void CAirCraftCasingVibrateSystemView::OnBtnTransverseAmplification()
{
	// TODO:  �ڴ���������������
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	CDuChartCtrlStaticFunction::HengxiangFangda(&view->m_chart);
}

// ������С
void CAirCraftCasingVibrateSystemView::OnBtnHorizontalReduction()
{
	// TODO:  �ڴ���������������
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	CDuChartCtrlStaticFunction::HengxiangSuoxiao(&view->m_chart);

}

// ������С
void CAirCraftCasingVibrateSystemView::OnBtnVerticalReduction()
{
	// TODO:  �ڴ���������������
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	CDuChartCtrlStaticFunction::ZongxiangSuoxiao(&view->m_chart);
}

//����Ŵ�
void CAirCraftCasingVibrateSystemView::OnBtnVerticalAmplification()
{
	// TODO:  �ڴ���������������
	// TODO:  �ڴ���������������
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	CDuChartCtrlStaticFunction::ZongxiangFangda(&view->m_chart);
}

//�����
void CAirCraftCasingVibrateSystemView::OnBtnSingleCursor()
{
	// TODO:  �ڴ���������������
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	CDuChartCtrlStaticFunction::SetCursorSingle(&view->m_chart);
}

//��ֵ
void CAirCraftCasingVibrateSystemView::OnBtnPeakValue()
{
	// TODO:  �ڴ���������������
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	
	CDuChartCtrlStaticFunction::SetCursorPeak(&view->m_chart);
}


// �Զ��̶�
void CAirCraftCasingVibrateSystemView::OnBtnAutoScale()
{
	// TODO:  �ڴ���������������
	// TODO:  �ڴ���������������
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();

	CDuChartCtrlStaticFunction::AutoXScale(&view->m_chart,FALSE);
	//CDuChartCtrlStaticFunction::AutoYScale(&view->m_chart, FALSE);
	
}

// Ĭ�Ͽ̶�
void CAirCraftCasingVibrateSystemView::OnBtnSelfScale()
{
	// TODO:  �ڴ���������������
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	//CDuChartCtrlStaticFunction::SetCursorNone(&view->m_chart);
	CChartStandardAxisDu * leftAxis = (CChartStandardAxisDu*)view->m_chart.GetAxisDu(CChartCtrl::LeftAxis, 0);
	CChartStandardAxisDu * bottomAxis = (CChartStandardAxisDu*)view->m_chart.GetAxisDu(CChartCtrl::BottomAxis, 0);
	bottomAxis->SetMinMax(0, 1000);//�����¿̶�
	bottomAxis->SetTickIncrement(false, 100);

	leftAxis->SetMinMax(-0.1, 0.1);
	leftAxis->SetTickIncrement(false, 0.05);
}

// �޹��
void CAirCraftCasingVibrateSystemView::OnBtnNoCorror()
{
	// TODO:  �ڴ���������������
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	CDuChartCtrlStaticFunction::SetCursorNone(&view->m_chart);
}

//��ʼ����
void CAirCraftCasingVibrateSystemView::OnBtnStartSmaple()
{
	int projectId = theApp.m_currentProject.GetProjectId();
	if (projectId <= 0){
		AfxMessageBox("���ȴ򿪻����½���Ŀ");
		return;
	}
	theApp.m_bIsSample = true;
}

// ֹͣ����
void CAirCraftCasingVibrateSystemView::OnBtnStopSample()
{
	// TODO:  �ڴ���������������
	//////���߳�ȥ���棡��������������������������
	//m_fileUtile.SaveSampleData(theApp.m_sampleData);

	
}

//���̵�λ
void CAirCraftCasingVibrateSystemView::OnBtnProjectUnit()
{
	// TODO:  �ڴ���������������
	CEngineerUnitView engineerUnitView;
	engineerUnitView.DoModal();
}

// ��������
void CAirCraftCasingVibrateSystemView::OnBtnAlarmSet()
{
	// TODO:  �ڴ���������������
	CAlarmParaSetView alarmView;
	alarmView.DoModal();
	
}

// ͼ������
void CAirCraftCasingVibrateSystemView::OnBtnGraphAttr()
{
	// TODO:  �ڴ���������������
	m_graphAttributeView.DoModal();
}

/*��ʱ��*/
void CAirCraftCasingVibrateSystemView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	/*11-26�ǲɼ�*/
	if (11 == nIDEvent)
	{
		DrawLining (0);
	}
	if (12 == nIDEvent)
	{
		DrawLining(1);
	}
	if (13 == nIDEvent)
	{
		DrawLining(2);
	}
	if (14 == nIDEvent)
	{
		DrawLining(3);
	}
	if (15 == nIDEvent)
	{
		DrawLining(4);
	}
	if (16 == nIDEvent)
	{
		DrawLining(5);
	}
	if (17 == nIDEvent)
	{
		DrawLining(6);
	}
	if (18 == nIDEvent)
	{
		DrawLining(7);
	}
	if (19 == nIDEvent)
	{
		DrawLining(8);
	}
	if (20 == nIDEvent)
	{
		DrawLining(9);
	}
	if (21 == nIDEvent)
	{
		DrawLining(10);
	}
	if (22 == nIDEvent)
	{
		DrawLining(11);
	}
	if (23 == nIDEvent)
	{
		DrawLining(12);
	}
	if (24 == nIDEvent)
	{
		DrawLining(13);
	}
	if (25 == nIDEvent)
	{
		DrawLining(14);
	}
	if (26 == nIDEvent)
	{
		DrawLining(15);
	}
	/*27 ��ʼ����*/
	if (27 == nIDEvent)
	{
		/*��ʱ����*/
		StartSampleChannelDatat();
	}
	CFormView::OnTimer(nIDEvent);
}

/*������ͼ*/
bool CAirCraftCasingVibrateSystemView::DrawLining(int nViewIndex)
{
	m_dview[nViewIndex]->m_pLineSerie->ClearSerie();
	m_dview[nViewIndex]->m_pLineSerie->SetNeedCalStatValue(TRUE);
	if (!theApp.m_echoData[nViewIndex].empty()){ 
		////���Զ����������ݣ���ȥˢ������
		shared_ptr<EchoSignal>  echoSignal = theApp.m_echoData[nViewIndex].wait_and_pop();
		double *x = echoSignal->GetXArray();
		double *y = echoSignal->GetYArray();
		int size = 1000;
		/*for (int i = 0; i < 5; i++){
			TRACE("\n���ڣ�%d x=%f,y=%f\n",nViewIndex, x[i], y[i]);
			}*/
		if (echoSignal->GetXLength() != 0 && echoSignal->GetYLength() != 0){
			TRACE("\nˢ��%d����.......................................................\n",nViewIndex);
			////�����в��ǿ�ʱ��ˢ��ͼ�����ʾ
			m_dview[nViewIndex]->m_pLineSerie->AddPoints(echoSignal->GetXArray(), echoSignal->GetYArray(), echoSignal->GetYLength()/2);
		}
	}
	return true;
}

// ���㵱ǰ���Ĵ��ڸ���->ͨ����
bool CAirCraftCasingVibrateSystemView::CalculateChannelNum(int &nChannelNums)
{
	// ��ʾ
	POSITION curTemplatePos = theApp.GetFirstDocTemplatePosition();
	CDocTemplate *m_doc = theApp.GetNextDocTemplate(curTemplatePos);
	/////CDocTemplate *m_doc1 = theApp.GetNextDocTemplate(curTemplatePos);//�ĵ�ģ��
	//����ĵ�:
	nChannelNums = 0;
	curTemplatePos = m_doc->GetFirstDocPosition();
	while (curTemplatePos != NULL)
	{
		(CAirCraftCasingVibrateSystemDoc*)m_doc->GetNextDoc(curTemplatePos);
		nChannelNums++;
	}
	return 0;


}

//��ʼ��View
bool CAirCraftCasingVibrateSystemView::InitializeView()
{
	// ��ʾ
	POSITION curTemplatePos = theApp.GetFirstDocTemplatePosition();
	CDocTemplate *m_doc = theApp.GetNextDocTemplate(curTemplatePos);
	/////CDocTemplate *m_doc1 = theApp.GetNextDocTemplate(curTemplatePos);//�ĵ�ģ��
	//����ĵ�:
	CAirCraftCasingVibrateSystemDoc * pdoc[20];
	int i = 0;
	curTemplatePos = m_doc->GetFirstDocPosition();
	while (curTemplatePos != NULL)
	{
		pdoc[i] = (CAirCraftCasingVibrateSystemDoc*)m_doc->GetNextDoc(curTemplatePos);
		//�����ͼ:
		POSITION curViewPos;
		curViewPos = pdoc[i]->GetFirstViewPosition();
		while (curViewPos != NULL)
		{
			m_dview[i] = (CAirCraftCasingVibrateSystemView*)pdoc[i]->GetNextView(curViewPos);
		}
		i++;
	}
	return true;

}


/*����豸����*/
void CAirCraftCasingVibrateSystemView::OnButtonDetectDevice()
{
	// TODO:  �ڴ���������������
	CDetectDeviceManageView detectDeviceManageView;
	detectDeviceManageView.DoModal();
}

/*������豸����*/
void CAirCraftCasingVibrateSystemView::OnButtonDetectedDevice()
{
	// TODO:  �ڴ���������������
	CDetectedDeviceManageView detectedDeviceManegeView;
	detectedDeviceManegeView.DoModal();
}


/*��ʱ����*/
void CAirCraftCasingVibrateSystemView::StartSampleChannelDatat()
{
	int nchannelNums;
	CalculateChannelNum(nchannelNums);
	for (int i = 0; i < nchannelNums; i++)
	{
		/*theApp.m_sampleData[i].push(theApp.m_vSersor[i].popSampleSignalQuene());*/
	}

}

// ������ʱ����ʼ�ɼ�
bool CAirCraftCasingVibrateSystemView::ShowDataToView(int nChannelNum)
{
	for (int i = 11; i < 11 + nChannelNum; i++)
	{
		SetTimer(i, 100, NULL);
	}
	return true;
}