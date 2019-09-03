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

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "AirCraftCasingVibrateSystem.h"
#endif

#include "AirCraftCasingVibrateSystemDoc.h"
#include "AirCraftCasingVibrateSystemView.h"
#include "DateUtil.h"
#include "FFTWUtil.h"
#include <thread>
#include "fftw3.h"
#include "CommonUtil.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;

IMPLEMENT_DYNCREATE(CAirCraftCasingVibrateSystemView, CFormView)

BEGIN_MESSAGE_MAP(CAirCraftCasingVibrateSystemView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_PAINT()
	ON_COMMAND(ID_BUTTON_SIGNAL_SELECT, &CAirCraftCasingVibrateSystemView::OnButtonSignalSelect)
	ON_COMMAND(ID_BTN_GRAPH_ATTR, &CAirCraftCasingVibrateSystemView::OnBtnGraphAttr)
	ON_WM_TIMER()

END_MESSAGE_MAP()

// CAirCraftCasingVibrateSystemView ����/����

int CAirCraftCasingVibrateSystemView::m_iwindowCount = 0;


CAirCraftCasingVibrateSystemView::CAirCraftCasingVibrateSystemView()
	: CFormView(CAirCraftCasingVibrateSystemView::IDD)
{
     // m_icurrentWindowNumber = m_iwindowCount++; ///��ǰ���ں�
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
	m_pBottomAxis22->SetMinMax(0, 500);//�����¿̶�
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

////�ɼ�����
void CAirCraftCasingVibrateSystemView::CaptureData(){
	SmartArray<double> xData; ///x����
	SmartFFTWComplexArray fftwInput; ///����Ҷ�任��ʼ������
	while (theApp.m_icollectionStatus){
		int countN = rand() % 100;
		// ÿ�ζ�ȡ�����������û��ڴ��ڵĲ�����ѡ��
		if (theApp.m_icollectionStatus == 2){ KillTimer(m_icurrentWindowNumber); };
		vector<double> realTimeSignalData;
		vector<CString> realTimeSignalTime;
		for (int j = 0; j < theApp.m_signalEchoCount && theApp.m_icollectionStatus == 1; j++)
		{
			xData.push_back(j); ///X����

			///�ɼ����ݴ��뵽�����С�
			AcquiredSignal acquiredSignal(m_readFromCSVFile[countN][j], DateUtil::GetCurrentCStringTime());
			m_collectionDataQueue.push(acquiredSignal);

			///�ɼ����ݴ��뵽�����źŵ���������
			fftw_complex fftw;
			fftw[0] = m_readFromCSVFile[countN][j];
			fftwInput.push_back(fftw);
			if (theApp.m_bIsSample){
				////�����ʱ���ڲ����������������ݴ��뵽���������С�
				m_sampleDataQueue.push(acquiredSignal);
			}
			// ����������ʵʱ�ź�
			if (true/*�ж��Ƿ���Ҫʵʱ����*/)
			{
				
				realTimeSignalData.push_back(m_readFromCSVFile[countN][j]);
				realTimeSignalTime.push_back(DateUtil::GetCurrentCStringTime().GetBuffer());
			}
			
		}
		// ʵʱ���ݶ���
		m_realTimeSignal.push(RealTimeSignal(realTimeSignalData, realTimeSignalTime));

		m_realTimeSignalCaptureflag = false;
		//
		/////��һ�βɼ������ݽ��и���Ҷ�任
		//////�Դ�������ݽ��и���Ҷ�任����
		SmartFFTWComplexArray fftwOutput(fftwInput.size());
		FFTWUtil::FastFourierTransformation(fftwInput.size(), fftwInput.GeFFTWComplexArray(),
				fftwOutput.GeFFTWComplexArray());
		/////������֮��ĸ���Ҷ�任ת����XY����
		SmartArray<double> yData(xData.size()); ///y����
		FFTWUtil::FFTDataToXY(fftwOutput, yData, xData.size());
		/////��ӵ��������ݶ�����
		m_echoSignalQueue.push(EchoSignal(xData, yData));
		/////�����������ʾ�Ļ�������
		fftwInput.clear();
		xData.clear();
		yData.clear();

		//���ʵʱ�ź�
		//m_realTimeSignal.GetRealTimeSignalData().clear();
		//m_realTimeSignal.GetRealTimeSignalTime().clear();
	}
	KillTimer(m_icurrentWindowNumber);
}

///�����̲߳ɼ�����&���ö�ʱ��ˢ������
void CAirCraftCasingVibrateSystemView::OpenThread2CaptureData(){
	////�����ǰδѡ����Ӧ�Ĵ����������ܿ��̲߳ɼ�����
	if (!m_signalSelectView.GetSelectedSensor().GetSensorId()){
		AfxMessageBox("����"+CommonUtil::Int2CString(m_icurrentWindowNumber)+"��û��ѡ�񴫸���");
		theApp.m_icollectionStatus = 0; ///һ������û��ѡ�񴫸��������������ǰ�ɼ�״̬��Ϊ0 
		return;
	}
     thread t(&CAirCraftCasingVibrateSystemView::CaptureData,this);
	 t.detach();
	 ///������ʱ��ȥˢ��ҳ��
	 SetTimer(m_icurrentWindowNumber, 10, NULL);
	 ///�����߳��Զ�����ɼ�����
	 OpenThread2SaveCollectionData();
}
void CAirCraftCasingVibrateSystemView::OnTimer(UINT_PTR nIDEvent){
	if (m_icurrentWindowNumber == nIDEvent){ RefershChartCtrlData(); }
}

////ˢ��ͼ��ؼ�������
void  CAirCraftCasingVibrateSystemView::RefershChartCtrlData(){
	m_pLineSerie->ClearSerie();
	m_pLineSerie->SetNeedCalStatValue(TRUE);
	//TRACE("\nˢ��%d����.......................................................\n", m_icurrentWindowNumber);
	shared_ptr<EchoSignal> echoSignal = m_echoSignalQueue.wait_and_pop();
	SmartArray<double> xData = echoSignal->GetXData();
	SmartArray<double> yData = echoSignal->GetYData();
	m_pLineSerie->AddPoints(xData.GetSmartArray(),yData.GetSmartArray(),xData.size() / 2);
}

////����ɼ����ݵ��̺߳���
void  CAirCraftCasingVibrateSystemView::AutoSaveCollectionData(){
	////���ô�����Controller�ౣ��ɼ�����
	while (theApp.m_bIsAutoSaveCollectionData){
		ThreadSafeQueue<AcquiredSignal> acquireSignalThreadQueue;
		///�����ǰ�����ɼ��ˣ����һ����������е�Ԫ�ز���������Ŀ,���̱߳������ɼ�������
		if (theApp.m_icollectionStatus == 0 && 
				m_collectionDataQueue.size()<theApp.m_icollectSignalsStoreCount){
			theApp.m_bIsAutoSaveCollectionData = false;
			thread t(&CAirCraftCasingVibrateSystemView::SaveCollectionData, this, m_collectionDataQueue);
			t.detach();
			break;
		}

		while (acquireSignalThreadQueue.size() <= theApp.m_icollectSignalsStoreCount){
			m_collectionDataQueue;
			shared_ptr<AcquiredSignal> acquiredSignal = m_collectionDataQueue.wait_and_pop();
			acquireSignalThreadQueue.push(*acquiredSignal);
		}

		acquireSignalThreadQueue.size();

		thread t(&CAirCraftCasingVibrateSystemView::SaveCollectionData, this, acquireSignalThreadQueue);
		t.detach();
	}
}

////����ɼ�����
void CAirCraftCasingVibrateSystemView::SaveCollectionData(ThreadSafeQueue<AcquiredSignal> acquireSignalQueue){
	m_sensorController.SaveCollectionData(m_signalSelectView.GetSelectedSensor().GetSensorId(), acquireSignalQueue);
}

////�����߳��Զ������̺߳���
void CAirCraftCasingVibrateSystemView::OpenThread2SaveCollectionData(){
	thread t(&CAirCraftCasingVibrateSystemView::AutoSaveCollectionData, this);
	t.detach();
}
void  CAirCraftCasingVibrateSystemView::SaveSampleData(){
	////���ô�����Controller�ౣ���������
	Result res = m_sensorController.SaveSampleData(m_signalSelectView.GetSelectedSensor().GetSensorId(),m_sampleDataQueue);
	if (!res.GetIsSuccess()){
		AfxMessageBox(res.GetMessages());
	}
}
void  CAirCraftCasingVibrateSystemView::OpenThread2SaveSampleData(){
	thread t(&CAirCraftCasingVibrateSystemView::SaveSampleData, this);
	t.detach();
}

CDuChartCtrl & CAirCraftCasingVibrateSystemView::GetChartCtrl(){
	return m_chart;
}

void CAirCraftCasingVibrateSystemView::SetViewNumber(int windowNumber){
	this->m_icurrentWindowNumber = windowNumber;
}

void CAirCraftCasingVibrateSystemView::ResetView(){
	m_pLineSerie->ClearSerie();
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
	m_signalSelectView.DoModal();
}

// ����Ŵ�
void CAirCraftCasingVibrateSystemView::OnBtnTransverseAmplification()
{
	// ��ǰ���ڵ�ͼ�����Ŵ�
	CDuChartCtrlStaticFunction::HengxiangFangda(&this->m_chart);
}

// ������С
void CAirCraftCasingVibrateSystemView::OnBtnHorizontalReduction()
{
	// ��ǰ���ڵ�ͼ�������С
	CDuChartCtrlStaticFunction::HengxiangSuoxiao(&this->m_chart);

}

// ������С
void CAirCraftCasingVibrateSystemView::OnBtnVerticalReduction()
{
	//��ǰ���ڵ�ͼ��������С
	CDuChartCtrlStaticFunction::ZongxiangSuoxiao(&this->m_chart);
}

//����Ŵ�
void CAirCraftCasingVibrateSystemView::OnBtnVerticalAmplification()
{
	// ����Ŵ�
	//CAirCraftCasingVibrateSystemView *view;
	//view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	CDuChartCtrlStaticFunction::ZongxiangFangda(&this->m_chart);
}

//�����
void CAirCraftCasingVibrateSystemView::OnBtnSingleCursor()
{
	// �����
	//CAirCraftCasingVibrateSystemView *view;
	//view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	CDuChartCtrlStaticFunction::SetCursorSingle(&this->m_chart);
}

//��ֵ
void CAirCraftCasingVibrateSystemView::OnBtnPeakValue()
{
	// ��ֵ
	//CAirCraftCasingVibrateSystemView *view;
	//view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	CDuChartCtrlStaticFunction::SetCursorPeak(&this->m_chart);
}


// �Զ��̶�
void CAirCraftCasingVibrateSystemView::OnBtnAutoScale()
{
	//CAirCraftCasingVibrateSystemView *view;
	//view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();

	CDuChartCtrlStaticFunction::AutoXScale(&this->m_chart,FALSE);
	//CDuChartCtrlStaticFunction::AutoYScale(&view->m_chart, FALSE);
}

// Ĭ�Ͽ̶�
void CAirCraftCasingVibrateSystemView::OnBtnSelfScale()
{
	CChartStandardAxisDu * leftAxis = (CChartStandardAxisDu*)this->m_chart.GetAxisDu(CChartCtrl::LeftAxis, 0);
	CChartStandardAxisDu * bottomAxis = (CChartStandardAxisDu*)this->m_chart.GetAxisDu(CChartCtrl::BottomAxis, 0);
	bottomAxis->SetMinMax(0, 1000);//�����¿̶�
	bottomAxis->SetTickIncrement(false, 100);

	leftAxis->SetMinMax(-0.1, 0.1);
	leftAxis->SetTickIncrement(false, 0.05);
}

// �޹��
void CAirCraftCasingVibrateSystemView::OnBtnNoCorror()
{
	CDuChartCtrlStaticFunction::SetCursorNone(&this->m_chart);
}

// ͼ������
void CAirCraftCasingVibrateSystemView::OnBtnGraphAttr()
{
	// TODO:  �ڴ���������������
	m_graphAttributeView.DoModal();
}
