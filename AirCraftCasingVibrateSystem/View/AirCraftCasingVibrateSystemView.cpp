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

// AirCraftCasingVibrateSystemView.cpp : CAirCraftCasingVibrateSystemView 类的实现

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	//ON_COMMAND(ID_BUTTON_SIGNAL_SELECT, &CAirCraftCasingVibrateSystemView::OnButtonSignalSelect)
	ON_WM_TIMER()

	ON_MESSAGE(WM_USER_REFRESH_CHART, &CAirCraftCasingVibrateSystemView::OnRefreshChart)

END_MESSAGE_MAP()

// CAirCraftCasingVibrateSystemView 构造/析构

int CAirCraftCasingVibrateSystemView::m_iwindowCount = 0;

CAirCraftCasingVibrateSystemView::CAirCraftCasingVibrateSystemView()
	: CFormView(CAirCraftCasingVibrateSystemView::IDD)
{
      m_icurrentWindowNumber = m_iwindowCount++; ///当前窗口号
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
	//  CREATESTRUCT cs 来修改窗口类或样式
	return CFormView::PreCreateWindow(cs);
}

void CAirCraftCasingVibrateSystemView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	ResizeParentToFit();
	//调整控件大小
	CRect rc;
	GetClientRect(rc);
	rc.DeflateRect(10, 10);
	m_chart.Create(this, rc, theApp.m_chartCtrlIndex);
	rc.left = rc.left + 80;
	m_chart.CheckAutoCenter();
	m_chart.ShowWindow(SW_SHOWNORMAL);
	CDuChartCtrl * pDuChartCtrl = &m_chart;
	pDuChartCtrl->EnableRefresh(false);
	// 显示光标值、统计值
	int nSelectChannelCount = 1;
	int nXAxisType = CDuChartCtrlShuxing::typeAxisLine;
	int nYAxisType = CDuChartCtrlShuxing::typeAxisLine;
	int nSerieType = CDuChartCtrlShuxing::typeSerieLine;
	// 清空所有
	CDuChartCtrlStaticFunction::RemoveAll(pDuChartCtrl);
	// 构造坐标轴
	CChartStandardAxisDu* axisDu = m_chart.CreateStandardAxisDu(CChartCtrl::BottomAxis, 0);
	axisDu->SetTickIncrement(true, 100);
	axisDu = m_chart.CreateStandardAxisDu(CChartCtrl::LeftAxis, 0);
	axisDu->SetTickIncrement(true, 1);
	SetChartXYCoordinateLen(0, 500, -15, 15);
	// 构造曲线
	CDuChartCtrlStaticFunction::CreateSeries(pDuChartCtrl, nSelectChannelCount, nSerieType);
	// 构造光标
	CDuChartCtrlStaticFunction::SetCursorNone(pDuChartCtrl);
	// 坐标轴
	for (int i = 0; i < nSelectChannelCount; i++)
	{
		CChartAxis * pChartAxisBottomAxis = pDuChartCtrl->GetAxisDu(CChartCtrl::BottomAxis, i);
		if (pChartAxisBottomAxis != NULL)
			pChartAxisBottomAxis->GetLabel()->SetText(" ");
		CChartAxis * pChartAxisLeftAxis = pDuChartCtrl->GetAxisDu(CChartCtrl::LeftAxis, i);
		if (pChartAxisLeftAxis != NULL)
			pChartAxisLeftAxis->GetLabel()->SetText("  ");
	}
	// 曲线
	for (int i = 0; i < nSelectChannelCount; i++)
	{
		CChartLineSerieDu * pSerie = (CChartLineSerieDu*)pDuChartCtrl->GetSerieFromIndexDu(i);
		m_pLineSerie = pSerie;
		pSerie->SetName("曲线");
		//pSerie->SetNeedCalStatValue(true);
	}
	pDuChartCtrl->m_shuxing.m_bDrawStatValue = TRUE;
	//pDuChartCtrl->SetPanEnabled(false);/*设置控件右键不可拖动*/
	pDuChartCtrl->EnableRefresh(true);
	m_flag = true;
	RefreshGraphAttri(); //加载图形属性
}

//void CAirCraftCasingVibrateSystemView::OnTimer(UINT_PTR nIDEvent){
//	if (m_iSampleDataEchoTimerNum == nIDEvent)
//	{
//		SampleDataEcho();  //采样数据回显
//	}
//}

void CAirCraftCasingVibrateSystemView::SetChartXYCoordinateLen(double xmin, double xmax, double ymin, double ymax){
	///坐标值存在默认参数-1，如果使用默认参数的话，默认的设置为采集窗口绑定的传感器的参数取值
	Value temp;
	Result res;
	if (xmax == -1){
		///xmax如果使用默认参数,那么就将x的最大值设置为采集频率
		xmax = 0;
		if (theApp.m_currentProject.GetCollectionparas().GetLine() > 0)
		{
			xmax = theApp.m_currentProject.GetCollectionparas().GetLine();
		}
	}
	if (ymax==-1||ymin==-1){
		///量程的最大和最小值默认设置为当前采集窗口绑定的传感器的量程
		ymin = -100;
		ymax = 100;
	}
	///设置x坐标的长度
	CChartAxis * pxAxis = m_chart.GetAxisDu(CChartCtrl::BottomAxis, 0);
	pxAxis->SetMinMax(xmin, xmax);

	///设置y坐标的长度
	CChartAxis * pyAxis = m_chart.GetAxisDu(CChartCtrl::LeftAxis, 0);
	pyAxis->SetMinMax(ymin, ymax);

	//CChartStandardAxisDu* pBottomAxis;
	//pBottomAxis = m_chart.CreateStandardAxisDu(CChartCtrl::BottomAxis, 0);

	//pBottomAxis->SetMinMax(xmin, xmax);//设置下刻度
	//pBottomAxis->SetTickIncrement(true, 100);

	///设置y坐标的长度
	/*CChartStandardAxisDu* pLeftAxis = m_chart.CreateStandardAxisDu(CChartCtrl::LeftAxis, 0);
	pLeftAxis->SetMinMax(ymin, ymax);
	pLeftAxis->SetTickIncrement(true, 3);*/
}

void CAirCraftCasingVibrateSystemView::openThread2RefershView(){
	thread t(&CAirCraftCasingVibrateSystemView::RefershView, this);
	t.detach();
}

void CAirCraftCasingVibrateSystemView::openTimer2RefershView(){
	SetTimer(88, 1, NULL);
}

void CAirCraftCasingVibrateSystemView::killTimer2RefershView(){
	KillTimer(88);
}

void CAirCraftCasingVibrateSystemView::RefershView(){
	while (theApp.m_icollectionState){
		if (theApp.m_icollectionState == 2){
			//暂停状态就卡在这
			Sleep(10);
			continue;
		}
		while (m_echoSignalQueue.size() > 0){
			TRACE("\n发送消息：队列长度:%d\n", m_echoSignalQueue.size());
			SendMessage(WM_USER_REFRESH_CHART);
			Sleep(100);
		}
	}
	//点完停止采集之后，还有数据需要保存！！！
	while (m_echoSignalQueue.size() > 0){
		SendMessage(WM_USER_REFRESH_CHART);
	}
}

void CAirCraftCasingVibrateSystemView::OnTimer(UINT_PTR nIDEvent)
{
	switch (nIDEvent){
		case 88:{
			OnRefreshChart(NULL,NULL);
			//SendMessage(WM_USER_REFRESH_CHART);
			break;
		}
		default:
			break;
	}
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
	//theApp.GetContextMenuManager()->ShowPopupMenu(IDR_MENU_RIGHT_KEY, point.x, point.y, this, TRUE);
#endif
}


// CAirCraftCasingVibrateSystemView 诊断

#ifdef _DEBUG
void CAirCraftCasingVibrateSystemView::AssertValid() const
{
	CFormView::AssertValid();
}

void CAirCraftCasingVibrateSystemView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CAirCraftCasingVibrateSystemDoc* CAirCraftCasingVibrateSystemView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAirCraftCasingVibrateSystemDoc)));
	return (CAirCraftCasingVibrateSystemDoc*)m_pDocument;
}
#endif //_DEBUG


// CAirCraftCasingVibrateSystemView 消息处理程序


void CAirCraftCasingVibrateSystemView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// 不为绘图消息调用 CFormView::OnPaint()
	CRect rc;
	GetClientRect(rc);
	rc.DeflateRect(10, 10);
	//rc.left = rc.left + 80;

	m_chart.MoveWindow(rc);
	m_chart.ShowWindow(SW_SHOWNORMAL);
}

// 信号选择
//void CAirCraftCasingVibrateSystemView::OnButtonSignalSelect()
//{
//	//m_signalSelectView.DoModal();
//}

// 横向放大
void CAirCraftCasingVibrateSystemView::OnBtnTransverseAmplification()
{
	// 当前窗口的图表横向放大
	CDuChartCtrlStaticFunction::HengxiangFangda(&this->m_chart);
}

// 横向缩小
void CAirCraftCasingVibrateSystemView::OnBtnHorizontalReduction()
{
	// 当前窗口的图标横向缩小
	CDuChartCtrlStaticFunction::HengxiangSuoxiao(&this->m_chart);

}

// 纵向缩小
void CAirCraftCasingVibrateSystemView::OnBtnVerticalReduction()
{
	//当前窗口的图标纵向缩小
	CDuChartCtrlStaticFunction::ZongxiangSuoxiao(&this->m_chart);
}

//纵向放大
void CAirCraftCasingVibrateSystemView::OnBtnVerticalAmplification()
{
	// 横向放大
	//CAirCraftCasingVibrateSystemView *view;
	//view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	CDuChartCtrlStaticFunction::ZongxiangFangda(&this->m_chart);
}

//单光标
void CAirCraftCasingVibrateSystemView::OnBtnSingleCursor()
{
	// 单光标
	//CAirCraftCasingVibrateSystemView *view;
	//view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	CDuChartCtrlStaticFunction::SetCursorSingle(&this->m_chart);
}

//峰值
void CAirCraftCasingVibrateSystemView::OnBtnPeakValue()
{
	// 峰值
	//CAirCraftCasingVibrateSystemView *view;
	//view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	CDuChartCtrlStaticFunction::SetCursorPeak(&this->m_chart);
}


// 自动刻度
void CAirCraftCasingVibrateSystemView::OnBtnAutoScale()
{
	CDuChartCtrlStaticFunction::AutoXScale(&this->m_chart,FALSE);
	CDuChartCtrlStaticFunction::AutoYScale(&this->m_chart, FALSE);
}

// 默认刻度
void CAirCraftCasingVibrateSystemView::OnBtnSelfScale()
{
	CChartStandardAxisDu * leftAxis = (CChartStandardAxisDu*)this->m_chart.GetAxisDu(CChartCtrl::LeftAxis, 0);
	CChartStandardAxisDu * bottomAxis = (CChartStandardAxisDu*)this->m_chart.GetAxisDu(CChartCtrl::BottomAxis, 0);
	bottomAxis->SetMinMax(-500, 500);//设置下刻度
	bottomAxis->SetTickIncrement(false, 100);

	leftAxis->SetMinMax(-0.1, 0.1);
	leftAxis->SetTickIncrement(false, 0.05);
}

// 无光标
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
	/*颜色*/
	// 窗口背景
	m_chart.SetBackColor(graphAttributeView.m_colorView.m_colBKColor);
	//图形区域背景
	m_chart.m_GraphBKColor = graphAttributeView.m_colorView.m_colGBKColor;
	// 信息区域背景
	m_chart.m_shuxing.m_colTBKColor = graphAttributeView.m_colorView.m_colTBKColor;
	//光标颜色
	m_chart.m_shuxing.m_colCursorColor1 = graphAttributeView.m_colorView.m_colCursor1;
	// 曲线颜色
	m_chart.GetSerieFromIndexDu(0)->SetColor(graphAttributeView.m_colorView.m_colSerie[0]);
	//网格颜色
	m_chart.GetAxisDu(CChartCtrl::BottomAxis, 0)->GetGrid()->SetColor(graphAttributeView.m_colorView.m_colGridLineColor);
	m_chart.GetAxisDu(CChartCtrl::LeftAxis, 0)->GetGrid()->SetColor(graphAttributeView.m_colorView.m_colGridLineColor);
	// 坐标轴颜色
	m_chart.GetAxisDu(CChartCtrl::BottomAxis, 0)->SetAxisColor(graphAttributeView.m_colorView.m_colXCoor);
	m_chart.GetAxisDu(CChartCtrl::LeftAxis, 0)->SetAxisColor(graphAttributeView.m_colorView.m_colYCoor);
	// 刻度颜色
	m_chart.GetAxisDu(CChartCtrl::BottomAxis, 0)->SetTextColor(graphAttributeView.m_colorView.m_colScale);
	m_chart.GetAxisDu(CChartCtrl::LeftAxis, 0)->SetTextColor(graphAttributeView.m_colorView.m_colScale);
	// 标注颜色
	m_chart.GetAxisDu(CChartCtrl::BottomAxis, 0)->GetLabel()->SetColor(graphAttributeView.m_colorView.m_colScale);
	m_chart.GetAxisDu(CChartCtrl::LeftAxis, 0)->GetLabel()->SetColor(graphAttributeView.m_colorView.m_colScale);

	/*字体*/
	// 坐标轴
	m_chart.GetAxisDu(CChartCtrl::BottomAxis, 0)->SetFont(
		graphAttributeView.m_fontView.m_lFontXCoor.m_lFontSize, graphAttributeView.m_fontView.m_lFontXCoor.m_lFont.lfFaceName);
	m_chart.GetAxisDu(CChartCtrl::LeftAxis, 0)->SetFont(
		graphAttributeView.m_fontView.m_lFontYCoor.m_lFontSize, graphAttributeView.m_fontView.m_lFontYCoor.m_lFont.lfFaceName);

	// 坐标单位
	m_chart.GetAxisDu(CChartCtrl::BottomAxis, 0)->GetLabel()->SetFont(
		graphAttributeView.m_fontView.m_lFontXUnit.m_lFontSize, graphAttributeView.m_fontView.m_lFontXUnit.m_lFont.lfFaceName);

	m_chart.GetAxisDu(CChartCtrl::LeftAxis, 0)->GetLabel()->SetFont(
		graphAttributeView.m_fontView.m_lFontYUnit.m_lFontSize, graphAttributeView.m_fontView.m_lFontYUnit.m_lFont.lfFaceName);
	//光标读数

	// 光标标注
	// 统计信息
	// 文本注释
	//工程信息
	/*选项*/
	//统计信息
	m_chart.m_shuxing.m_bDrawStatValue = graphAttributeView.m_selectView.m_bStaValue;
	// 最大值
	m_chart.m_shuxing.m_bDrawStatMax = graphAttributeView.m_selectView.m_bMax;
	// 最小值
	m_chart.m_shuxing.m_bDrawStatMin = graphAttributeView.m_selectView.m_bMin;
	//平均值
	m_chart.m_shuxing.m_bDrawStatAve = graphAttributeView.m_selectView.m_bAve;
	// 峰值
	m_chart.m_shuxing.m_bDrawStatPeak = graphAttributeView.m_selectView.m_bPeak;
	// 有效值
	m_chart.m_shuxing.m_bDrawStatRms = graphAttributeView.m_selectView.m_bEffectiveValue;
	//刷新
	m_chart.RefreshCtrl();
}

void CAirCraftCasingVibrateSystemView::SampleDataEcho()
{

	m_pLineSerie->ClearSerie();
	SmartArray<double> dXData, dYData;
	m_pLineSerie->SetNeedCalStatValue(TRUE);
	
	int iPointNums = 1000;
	// 截取一部分
	SplitVector(dXData, dYData, iPointNums);
	SmartFFTWComplexArray fftwInput; ///傅里叶变换初始的输入
	for (int i = 0; i < iPointNums; i++)
	{
		fftw_complex fftw;
		fftw[0] = dYData.GetSmartArray()[i];
		fftwInput.push_back(fftw);
	}
	SmartFFTWComplexArray fftwOutput(fftwInput.size());
	FFTWUtil::FastFourierTransformation(fftwInput.size(), fftwInput.GeFFTWComplexArray(),
		fftwOutput.GeFFTWComplexArray());
	/////将处理之后的傅里叶变换转换成XY坐标
	SmartArray<double> yData(dXData.size()); ///y坐标
	FFTWUtil::FFTDataToXY(fftwOutput, yData, dXData.size());
	m_pLineSerie->AddPoints(dXData.GetSmartArray(), yData.GetSmartArray(), dXData.size() / 2);
}

void CAirCraftCasingVibrateSystemView::SetSampleDataEchoTimerNum(int nSampleDataEchoTimerNums)
{
	m_iSampleDataEchoTimerNum = nSampleDataEchoTimerNums;

}

int CAirCraftCasingVibrateSystemView::GetSampleDataEchoTimerNum()
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
		//AfxMessageBox("回显队列没有元素");
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

///设置窗口对应的通道对象
void  CAirCraftCasingVibrateSystemView::SetChannel(TbChannel channel){
	///设置通道参数
	m_dhtestHardWareController.SetChannelParam(theApp.m_pHardWare, theApp.m_vecHardChannel, channel);
	m_signalSelectView.SetChannel(channel); ///取消设置通道参数
	GetDocument()->SetTitle(channel.GetChannelDesc());
	SetChartXYCoordinateLen(0, theApp.m_currentProject.GetCollectionparas().GetSampleFrequency().second / theApp.FFTRATE);
}
void  CAirCraftCasingVibrateSystemView::GetChannel(TbChannel & channel){
	m_signalSelectView.GetChannel(channel);
}

void  CAirCraftCasingVibrateSystemView::SetEchoSignalData(EchoSignal &echoSignal){
	m_echoSignalQueue.push(echoSignal);
	TRACE("\n队列长度:%d，生成一次数据耗时:%d\n", m_echoSignalQueue.size(), GetTickCount() - echoStartTime);
	echoStartTime = GetTickCount();
}

LRESULT CAirCraftCasingVibrateSystemView::OnRefreshChart(WPARAM wParam, LPARAM lParam){
	int ltime = GetTickCount();

	if (m_echoSignalQueue.empty()){
		return 0;
	}
	m_pLineSerie->ClearSerie();
	m_pLineSerie->SetNeedCalStatValue(TRUE);
	EchoSignal echoSignal = *m_echoSignalQueue.wait_and_pop();
	
	m_pLineSerie->AddPoints(echoSignal.GetXData().GetSmartArray(), echoSignal.GetYData().GetSmartArray(), echoSignal.GetYData().size());

	//if (theApp.m_isAlarm == 1){
	//	if (m_pLineSerie->GetMax() >= theApp.m_alarmLimit)
	//	{
	//		COLORREF colorrrefRGB = RGB(120, 250, 110);
	//		m_chart.GetSerieFromIndexDu(0)->SetColor(colorrrefRGB);
	//	}
	//	else
	//	{
	//		CGraphAttributeView graphAttributeView;
	//		//graphAttributeView.m_fontView.InitAttri();
	//		graphAttributeView.m_colorView.InitAttri();
	//		//graphAttributeView.m_selectView.InitAttri2();
	//		m_chart.GetSerieFromIndexDu(0)->SetColor(graphAttributeView.m_colorView.m_colSerie[0]);
	//	}
	//}
	//CDuChartCtrlStaticFunction::AutoYScale(&m_chart, FALSE);
	//this->m_chart.SetCursorPeak(TRUE);

	SetPeak(m_pLineSerie->GetMax());
	SetGross(m_pLineSerie->GetSum());
	m_pLineSerie->DrawDu();
	//UpdateWindow();
	TRACE("\n显示一次需要耗时：%d\n", GetTickCount() - showStartTime);
	TRACE("\n刷新一次页面需要耗时：%d\n", GetTickCount() - ltime);
	
	showStartTime = GetTickCount();
	return 0;
}
double CAirCraftCasingVibrateSystemView::GetPeak()
{
	return m_peak;
}
void CAirCraftCasingVibrateSystemView::SetPeak(double peak)
{
	this->m_peak = peak;
}
double CAirCraftCasingVibrateSystemView::GetGross()
{
	return m_gross;
}
void CAirCraftCasingVibrateSystemView::SetGross(double gross)
{
	this->m_gross = gross;
}