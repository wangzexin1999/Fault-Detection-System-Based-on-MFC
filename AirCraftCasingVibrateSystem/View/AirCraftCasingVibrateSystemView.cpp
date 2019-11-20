// ��� MFC ʾ��Դ������ʾ���ʹ�� MFC Microsoft Office Fluent �û����� 
// (��Fluent UI��)����ʾ�������ο���
// ���Բ��䡶Microsoft ������ο����� 
// MFC C++ �������渽����ص����ĵ���  
// ���ơ�ʹ�û�ַ� Fluent UI �����������ǵ����ṩ�ġ�  
// ��Ҫ�˽��й� Fluent UI ���ɼƻ�����ϸ��Ϣ�������  
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
#include "GraphAttributeView.h"
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
	ON_WM_TIMER()

	ON_MESSAGE(WM_USER_REFRESH_CHART, &CAirCraftCasingVibrateSystemView::OnRefreshChart)

END_MESSAGE_MAP()

// CAirCraftCasingVibrateSystemView ����/����

int CAirCraftCasingVibrateSystemView::m_iwindowCount = 0;

CAirCraftCasingVibrateSystemView::CAirCraftCasingVibrateSystemView()
	: CFormView(CAirCraftCasingVibrateSystemView::IDD)
{
      m_icurrentWindowNumber = m_iwindowCount++; ///��ǰ���ں�
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
	// �������
	CDuChartCtrlStaticFunction::RemoveAll(pDuChartCtrl);
	// ����������
	CChartStandardAxisDu* axisDu = m_chart.CreateStandardAxisDu(CChartCtrl::BottomAxis, 0);
	axisDu->SetTickIncrement(true, 100);
	axisDu = m_chart.CreateStandardAxisDu(CChartCtrl::LeftAxis, 0);
	axisDu->SetTickIncrement(true, 1);
	SetChartXYCoordinateLen(0, 500, -15, 15);
	// ��������
	CDuChartCtrlStaticFunction::CreateSeries(pDuChartCtrl, nSelectChannelCount, nSerieType);
	// ������
	CDuChartCtrlStaticFunction::SetCursorNone(pDuChartCtrl);
	// ������
	for (int i = 0; i < nSelectChannelCount; i++)
	{
		CChartAxis * pChartAxisBottomAxis = pDuChartCtrl->GetAxisDu(CChartCtrl::BottomAxis, i);
		if (pChartAxisBottomAxis != NULL)
			pChartAxisBottomAxis->GetLabel()->SetText("Fre[Hz]");
		CChartAxis * pChartAxisLeftAxis = pDuChartCtrl->GetAxisDu(CChartCtrl::LeftAxis, i);
		if (pChartAxisLeftAxis != NULL)
			pChartAxisLeftAxis->GetLabel()->SetText("MV");
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
	pDuChartCtrl->EnableRefresh(true);
	m_flag = true;
	RefreshGraphAttri(); //����ͼ������
}

void CAirCraftCasingVibrateSystemView::OnTimer(UINT_PTR nIDEvent){
	if (m_iSampleDataEchoTimerNum == nIDEvent)
	{
		SampleDataEcho();  //�������ݻ���
	}
}

void CAirCraftCasingVibrateSystemView::SetChartXYCoordinateLen(double xmin, double xmax, double ymin, double ymax){
	///����ֵ����Ĭ�ϲ���-1�����ʹ��Ĭ�ϲ����Ļ���Ĭ�ϵ�����Ϊ�ɼ����ڰ󶨵Ĵ������Ĳ���ȡֵ
	Value temp;
	Result res;
	if (xmax == -1){
		///xmax���ʹ��Ĭ�ϲ���,��ô�ͽ�x�����ֵ����Ϊ�ɼ�Ƶ��
		xmax = 0;
		res =   JsonUtil::GetValueFromJsonString(theApp.m_currentProject.GetTestingDevice().GetAnalysisFrequency().GetDictValue(), "content", temp);
		if (res.GetIsSuccess()){
			xmax = temp.GetFloat();
		}
	}
	if (ymax==-1||ymin==-1){
		///���̵�������СֵĬ������Ϊ��ǰ�ɼ����ڰ󶨵Ĵ�����������
		MathInterval yInterval;
		TbSensor currentSensor;
		m_signalSelectView.GetSensor(currentSensor);
		yInterval.Type = currentSensor.GetMileageRange();
		m_advantechDaqController.GetValueRangeInformationByVrgType(yInterval);
		ymin = yInterval.Min;
		ymax = yInterval.Max;
	}
	///����x����ĳ���
	CChartAxis * pxAxis = m_chart.GetAxisDu(CChartCtrl::BottomAxis, 0);
	pxAxis->SetMinMax(xmin, xmax);

	///����y����ĳ���
	CChartAxis * pyAxis = m_chart.GetAxisDu(CChartCtrl::LeftAxis, 0);
	pyAxis->SetMinMax(ymin, ymax);

	//CChartStandardAxisDu* pBottomAxis;
	//pBottomAxis = m_chart.CreateStandardAxisDu(CChartCtrl::BottomAxis, 0);

	//pBottomAxis->SetMinMax(xmin, xmax);//�����¿̶�
	//pBottomAxis->SetTickIncrement(true, 100);

	///����y����ĳ���
	/*CChartStandardAxisDu* pLeftAxis = m_chart.CreateStandardAxisDu(CChartCtrl::LeftAxis, 0);
	pLeftAxis->SetMinMax(ymin, ymax);
	pLeftAxis->SetTickIncrement(true, 3);*/
}

////����ɼ�����
void CAirCraftCasingVibrateSystemView::SaveCollectionData(ThreadSafeQueue<AcquiredSignal> acquireSignalQueue){
	m_sensorController.SaveCollectionData(m_signalSelectView.GetSelectedSensor().GetChannelId(), acquireSignalQueue);
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


// CAirCraftCasingVibrateSystemView ��Ϣ��������


void CAirCraftCasingVibrateSystemView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// ��Ϊ��ͼ��Ϣ���� CFormView::OnPaint()
	CRect rc;
	GetClientRect(rc);
	rc.DeflateRect(10, 10);
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
	// ��ǰ���ڵ�ͼ������Ŵ�
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



void CAirCraftCasingVibrateSystemView::RefreshGraphAttri()
{
	CGraphAttributeView graphAttributeView;
	graphAttributeView.m_fontView.InitAttri();
	graphAttributeView.m_colorView.InitAttri();
	graphAttributeView.m_selectView.InitAttri2();
	/*��ɫ*/
	// ���ڱ���
	m_chart.SetBackColor(graphAttributeView.m_colorView.m_colBKColor);
	//ͼ�����򱳾�
	m_chart.m_GraphBKColor = graphAttributeView.m_colorView.m_colGBKColor;
	// ��Ϣ���򱳾�
	m_chart.m_shuxing.m_colTBKColor = graphAttributeView.m_colorView.m_colTBKColor;
	//�����ɫ
	m_chart.m_shuxing.m_colCursorColor1 = graphAttributeView.m_colorView.m_colCursor1;
	// ������ɫ
	m_chart.GetSerieFromIndexDu(0)->SetColor(graphAttributeView.m_colorView.m_colSerie[0]);
	//������ɫ
	m_chart.GetAxisDu(CChartCtrl::BottomAxis, 0)->GetGrid()->SetColor(graphAttributeView.m_colorView.m_colGridLineColor);
	m_chart.GetAxisDu(CChartCtrl::LeftAxis, 0)->GetGrid()->SetColor(graphAttributeView.m_colorView.m_colGridLineColor);
	// ��������ɫ
	m_chart.GetAxisDu(CChartCtrl::BottomAxis, 0)->SetAxisColor(graphAttributeView.m_colorView.m_colXCoor);
	m_chart.GetAxisDu(CChartCtrl::LeftAxis, 0)->SetAxisColor(graphAttributeView.m_colorView.m_colYCoor);
	// �̶���ɫ
	m_chart.GetAxisDu(CChartCtrl::BottomAxis, 0)->SetTextColor(graphAttributeView.m_colorView.m_colScale);
	m_chart.GetAxisDu(CChartCtrl::LeftAxis, 0)->SetTextColor(graphAttributeView.m_colorView.m_colScale);
	// ��ע��ɫ
	m_chart.GetAxisDu(CChartCtrl::BottomAxis, 0)->GetLabel()->SetColor(graphAttributeView.m_colorView.m_colScale);
	m_chart.GetAxisDu(CChartCtrl::LeftAxis, 0)->GetLabel()->SetColor(graphAttributeView.m_colorView.m_colScale);

	/*����*/
	// ������
	m_chart.GetAxisDu(CChartCtrl::BottomAxis, 0)->SetFont(
		graphAttributeView.m_fontView.m_lFontXCoor.m_lFontSize, graphAttributeView.m_fontView.m_lFontXCoor.m_lFont.lfFaceName);
	m_chart.GetAxisDu(CChartCtrl::LeftAxis, 0)->SetFont(
		graphAttributeView.m_fontView.m_lFontYCoor.m_lFontSize, graphAttributeView.m_fontView.m_lFontYCoor.m_lFont.lfFaceName);

	// ���굥λ
	m_chart.GetAxisDu(CChartCtrl::BottomAxis, 0)->GetLabel()->SetFont(
		graphAttributeView.m_fontView.m_lFontXUnit.m_lFontSize, graphAttributeView.m_fontView.m_lFontXUnit.m_lFont.lfFaceName);

	m_chart.GetAxisDu(CChartCtrl::LeftAxis, 0)->GetLabel()->SetFont(
		graphAttributeView.m_fontView.m_lFontYUnit.m_lFontSize, graphAttributeView.m_fontView.m_lFontYUnit.m_lFont.lfFaceName);
	//������

	// ����ע
	// ͳ����Ϣ
	// �ı�ע��
	//������Ϣ
	/*ѡ��*/
	//ͳ����Ϣ
	m_chart.m_shuxing.m_bDrawStatValue = graphAttributeView.m_selectView.m_bStaValue;
	// ���ֵ
	m_chart.m_shuxing.m_bDrawStatMax = graphAttributeView.m_selectView.m_bMax;
	// ��Сֵ
	m_chart.m_shuxing.m_bDrawStatMin = graphAttributeView.m_selectView.m_bMin;
	//ƽ��ֵ
	m_chart.m_shuxing.m_bDrawStatAve = graphAttributeView.m_selectView.m_bAve;
	// ��ֵ
	m_chart.m_shuxing.m_bDrawStatPeak = graphAttributeView.m_selectView.m_bPeak;
	// ��Чֵ
	m_chart.m_shuxing.m_bDrawStatRms = graphAttributeView.m_selectView.m_bEffectiveValue;
	//ˢ��
	m_chart.RefreshCtrl();


}


void CAirCraftCasingVibrateSystemView::SampleDataEcho()
{

	m_pLineSerie->ClearSerie();
	SmartArray<double> dXData, dYData;
	m_pLineSerie->SetNeedCalStatValue(TRUE);
	
	int iPointNums = 1000;
	// ��ȡһ����
	SplitVector(dXData, dYData, iPointNums);
	SmartFFTWComplexArray fftwInput; ///����Ҷ�任��ʼ������
	for (int i = 0; i < iPointNums; i++)
	{
		fftw_complex fftw;
		fftw[0] = dYData.GetSmartArray()[i];
		fftwInput.push_back(fftw);
	}
	SmartFFTWComplexArray fftwOutput(fftwInput.size());
	FFTWUtil::FastFourierTransformation(fftwInput.size(), fftwInput.GeFFTWComplexArray(),
		fftwOutput.GeFFTWComplexArray());
	/////������֮��ĸ���Ҷ�任ת����XY����
	SmartArray<double> yData(dXData.size()); ///y����
	FFTWUtil::FFTDataToXY(fftwOutput, yData, dXData.size());
	m_pLineSerie->AddPoints(dXData.GetSmartArray(), yData.GetSmartArray(), dXData.size() / 2);
}


void CAirCraftCasingVibrateSystemView::SetSampleDataEchoTimerNum(int nSampleDataEchoTimerNums)
{
	m_iSampleDataEchoTimerNum = nSampleDataEchoTimerNums;

}

int CAirCraftCasingVibrateSystemView::SetSampleDataEchoTimerNum()
{
	return m_iSampleDataEchoTimerNum;
}

void CAirCraftCasingVibrateSystemView::StartSampleEncho()
{

	SetTimer(m_iSampleDataEchoTimerNum, 100, 0);
}

void CAirCraftCasingVibrateSystemView::StopSampleEncho()
{
	KillTimer(m_iSampleDataEchoTimerNum);
}

void CAirCraftCasingVibrateSystemView::SplitVector(SmartArray<double> &dXData, SmartArray<double> &dYData, int nNums)
{
	if (m_sampleFromFileDataQueue.size() == 0)
	{
		//AfxMessageBox("���Զ���û��Ԫ��");
		return;
	}
	int iSampleQueueSize = m_sampleFromFileDataQueue.size();
	for (int i = 0; i < nNums; i++)
	{
		if (m_icountNumsReadDraw < iSampleQueueSize-10)
		{
			double yTemp = m_sampleFromFileDataQueue[m_icountNumsReadDraw].GetSignalData();
			double xTemp;
			xTemp = i*1.0;
			dYData.push_back(yTemp);
			dXData.push_back(xTemp);
			m_icountNumsReadDraw++;
		}
		else
		{
			m_icountNumsReadDraw = 0;
			KillTimer(m_iSampleDataEchoTimerNum);
		}
	}
}

void  CAirCraftCasingVibrateSystemView::SetSensor(TbSensor sensor){
	m_signalSelectView.SetSensor(sensor);
	GetDocument()->SetTitle(sensor.GetSensorDesc());
	SetChartXYCoordinateLen();
}
void  CAirCraftCasingVibrateSystemView::GetSensor(TbSensor & sensor){
	 m_signalSelectView.GetSensor(sensor);
}

void  CAirCraftCasingVibrateSystemView::SetEchoSignalData(EchoSignal &echoSignal){
	m_echoSignal = echoSignal;
	SendMessage(WM_USER_REFRESH_CHART);
}

LRESULT CAirCraftCasingVibrateSystemView::OnRefreshChart(WPARAM wParam, LPARAM lParam)
{
	m_pLineSerie->ClearSerie();
	m_pLineSerie->SetNeedCalStatValue(TRUE);
	SmartArray<double> xData = m_echoSignal.GetXData();
	SmartArray<double> yData = m_echoSignal.GetYData();
	TRACE("\nˢ�����ݡ�������\n");
	
	m_pLineSerie->AddPoints(xData.GetSmartArray(), yData.GetSmartArray(), xData.size() / 2);
	return 0;
}