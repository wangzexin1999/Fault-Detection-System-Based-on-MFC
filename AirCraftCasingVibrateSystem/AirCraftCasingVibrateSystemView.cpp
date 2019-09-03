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

// CAirCraftCasingVibrateSystemView 构造/析构

int CAirCraftCasingVibrateSystemView::m_iwindowCount = 0;


CAirCraftCasingVibrateSystemView::CAirCraftCasingVibrateSystemView()
	: CFormView(CAirCraftCasingVibrateSystemView::IDD)
{
     // m_icurrentWindowNumber = m_iwindowCount++; ///当前窗口号
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
	//int nBeipcBarCount = m_nCalcFreCountK + 1;

	// 清空所有
	CDuChartCtrlStaticFunction::RemoveAll(pDuChartCtrl);
	// 构造坐标轴
	//CDuChartCtrlStaticFunction::CreateAxis(pDuChartCtrl, nSelectChannelCount, nXAxisType, nYAxisType);
	CChartStandardAxisDu* m_pBottomAxis22;
	m_pBottomAxis22 = m_chart.CreateStandardAxisDu(CChartCtrl::BottomAxis, 0);
	m_pBottomAxis22->SetMinMax(0, 500);//设置下刻度
	m_pBottomAxis22->SetTickIncrement(false, 100);
	CChartStandardAxisDu* pLeftAxis22 = m_chart.CreateStandardAxisDu(CChartCtrl::LeftAxis, 0);
	pLeftAxis22->SetMinMax(-0.1, 0.1);
	pLeftAxis22->SetTickIncrement(false, 0.05);
	// 构造曲线
	CDuChartCtrlStaticFunction::CreateSeries(pDuChartCtrl, nSelectChannelCount, nSerieType);
	// 构造光标
	CDuChartCtrlStaticFunction::SetCursorNone(pDuChartCtrl);


	// 坐标轴
	for (int i = 0; i < nSelectChannelCount; i++)
	{
		CChartAxis * pChartAxis = pDuChartCtrl->GetAxisDu(CChartCtrl::BottomAxis, i);
		if (pChartAxis != NULL)
			pChartAxis->GetLabel()->SetText("Fre[Hz]");
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

	//CDuChartCtrlStaticFunction::AutoXScale(pDuChartCtrl, FALSE);
	//CDuChartCtrlStaticFunction::AutoYScale(pDuChartCtrl, FALSE);
	//pDuChartCtrl->SetCursorSingle(FALSE);
	pDuChartCtrl->EnableRefresh(true);
	m_flag = true;
}

////采集数据
void CAirCraftCasingVibrateSystemView::CaptureData(){
	SmartArray<double> xData; ///x坐标
	SmartFFTWComplexArray fftwInput; ///傅里叶变换初始的输入
	while (theApp.m_icollectionStatus){
		int countN = rand() % 100;
		// 每次读取的数量按照用户在窗口的操作来选择
		if (theApp.m_icollectionStatus == 2){ KillTimer(m_icurrentWindowNumber); };
		vector<double> realTimeSignalData;
		vector<CString> realTimeSignalTime;
		for (int j = 0; j < theApp.m_signalEchoCount && theApp.m_icollectionStatus == 1; j++)
		{
			xData.push_back(j); ///X坐标

			///采集数据存入到队列中。
			AcquiredSignal acquiredSignal(m_readFromCSVFile[countN][j], DateUtil::GetCurrentCStringTime());
			m_collectionDataQueue.push(acquiredSignal);

			///采集数据存入到回显信号的输入数组
			fftw_complex fftw;
			fftw[0] = m_readFromCSVFile[countN][j];
			fftwInput.push_back(fftw);
			if (theApp.m_bIsSample){
				////如果此时正在采样，将采样的数据存入到采样队列中。
				m_sampleDataQueue.push(acquiredSignal);
			}
			// 传到服务器实时信号
			if (true/*判断是否需要实时传输*/)
			{
				
				realTimeSignalData.push_back(m_readFromCSVFile[countN][j]);
				realTimeSignalTime.push_back(DateUtil::GetCurrentCStringTime().GetBuffer());
			}
			
		}
		// 实时数据队列
		m_realTimeSignal.push(RealTimeSignal(realTimeSignalData, realTimeSignalTime));

		m_realTimeSignalCaptureflag = false;
		//
		/////将一次采集的数据进行傅里叶变换
		//////对传入的数据进行傅里叶变换处理
		SmartFFTWComplexArray fftwOutput(fftwInput.size());
		FFTWUtil::FastFourierTransformation(fftwInput.size(), fftwInput.GeFFTWComplexArray(),
				fftwOutput.GeFFTWComplexArray());
		/////将处理之后的傅里叶变换转换成XY坐标
		SmartArray<double> yData(xData.size()); ///y坐标
		FFTWUtil::FFTDataToXY(fftwOutput, yData, xData.size());
		/////添加到回显数据队列中
		m_echoSignalQueue.push(EchoSignal(xData, yData));
		/////清空用来做显示的缓冲区。
		fftwInput.clear();
		xData.clear();
		yData.clear();

		//清空实时信号
		//m_realTimeSignal.GetRealTimeSignalData().clear();
		//m_realTimeSignal.GetRealTimeSignalTime().clear();
	}
	KillTimer(m_icurrentWindowNumber);
}

///开启线程采集数据&设置定时器刷新数据
void CAirCraftCasingVibrateSystemView::OpenThread2CaptureData(){
	////如果当前未选择相应的传感器，则不能开线程采集数据
	if (!m_signalSelectView.GetSelectedSensor().GetSensorId()){
		AfxMessageBox("窗口"+CommonUtil::Int2CString(m_icurrentWindowNumber)+"还没有选择传感器");
		theApp.m_icollectionStatus = 0; ///一旦出现没有选择传感器的情况，将当前采集状态置为0 
		return;
	}
     thread t(&CAirCraftCasingVibrateSystemView::CaptureData,this);
	 t.detach();
	 ///开启定时器去刷新页面
	 SetTimer(m_icurrentWindowNumber, 10, NULL);
	 ///开启线程自动保存采集数据
	 OpenThread2SaveCollectionData();
}
void CAirCraftCasingVibrateSystemView::OnTimer(UINT_PTR nIDEvent){
	if (m_icurrentWindowNumber == nIDEvent){ RefershChartCtrlData(); }
}

////刷新图标控件的数据
void  CAirCraftCasingVibrateSystemView::RefershChartCtrlData(){
	m_pLineSerie->ClearSerie();
	m_pLineSerie->SetNeedCalStatValue(TRUE);
	//TRACE("\n刷新%d窗口.......................................................\n", m_icurrentWindowNumber);
	shared_ptr<EchoSignal> echoSignal = m_echoSignalQueue.wait_and_pop();
	SmartArray<double> xData = echoSignal->GetXData();
	SmartArray<double> yData = echoSignal->GetYData();
	m_pLineSerie->AddPoints(xData.GetSmartArray(),yData.GetSmartArray(),xData.size() / 2);
}

////保存采集数据的线程函数
void  CAirCraftCasingVibrateSystemView::AutoSaveCollectionData(){
	////调用传感器Controller类保存采集数据
	while (theApp.m_bIsAutoSaveCollectionData){
		ThreadSafeQueue<AcquiredSignal> acquireSignalThreadQueue;
		///如果当前结束采集了，并且缓冲区队列中的元素不够储存数目,开线程保存最后采集的数据
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

////保存采集数据
void CAirCraftCasingVibrateSystemView::SaveCollectionData(ThreadSafeQueue<AcquiredSignal> acquireSignalQueue){
	m_sensorController.SaveCollectionData(m_signalSelectView.GetSelectedSensor().GetSensorId(), acquireSignalQueue);
}

////开启线程自动保存线程函数
void CAirCraftCasingVibrateSystemView::OpenThread2SaveCollectionData(){
	thread t(&CAirCraftCasingVibrateSystemView::AutoSaveCollectionData, this);
	t.detach();
}
void  CAirCraftCasingVibrateSystemView::SaveSampleData(){
	////调用传感器Controller类保存采样数据
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
	rc.DeflateRect(20, 20);
	//rc.left = rc.left + 80;

	m_chart.MoveWindow(rc);
	m_chart.ShowWindow(SW_SHOWNORMAL);
}

// 信号选择
void CAirCraftCasingVibrateSystemView::OnButtonSignalSelect()
{
	m_signalSelectView.DoModal();
}

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
	//CAirCraftCasingVibrateSystemView *view;
	//view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();

	CDuChartCtrlStaticFunction::AutoXScale(&this->m_chart,FALSE);
	//CDuChartCtrlStaticFunction::AutoYScale(&view->m_chart, FALSE);
}

// 默认刻度
void CAirCraftCasingVibrateSystemView::OnBtnSelfScale()
{
	CChartStandardAxisDu * leftAxis = (CChartStandardAxisDu*)this->m_chart.GetAxisDu(CChartCtrl::LeftAxis, 0);
	CChartStandardAxisDu * bottomAxis = (CChartStandardAxisDu*)this->m_chart.GetAxisDu(CChartCtrl::BottomAxis, 0);
	bottomAxis->SetMinMax(0, 1000);//设置下刻度
	bottomAxis->SetTickIncrement(false, 100);

	leftAxis->SetMinMax(-0.1, 0.1);
	leftAxis->SetTickIncrement(false, 0.05);
}

// 无光标
void CAirCraftCasingVibrateSystemView::OnBtnNoCorror()
{
	CDuChartCtrlStaticFunction::SetCursorNone(&this->m_chart);
}

// 图像属性
void CAirCraftCasingVibrateSystemView::OnBtnGraphAttr()
{
	// TODO:  在此添加命令处理程序代码
	m_graphAttributeView.DoModal();
}
