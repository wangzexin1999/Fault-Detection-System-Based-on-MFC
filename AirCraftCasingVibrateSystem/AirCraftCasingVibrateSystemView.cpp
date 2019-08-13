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
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CAirCraftCasingVibrateSystemView 构造/析构

CAirCraftCasingVibrateSystemView::CAirCraftCasingVibrateSystemView()
	: CFormView(CAirCraftCasingVibrateSystemView::IDD)
{
	// TODO:  在此处添加构造代码

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
	// TODO:  在此处通过修改
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
	m_pBottomAxis22->SetMinMax(0, 1000);//设置下刻度
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
	// TODO:  在此处添加消息处理程序代码
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
	// TODO:  在此添加命令处理程序代码
	m_signalSelectView.DoModal();
}

// 新建项目
void CAirCraftCasingVibrateSystemView::OnButtonNewProject()
{
	//打开窗口
	m_newProjectView.DoModal();

}

// 保存项目
void CAirCraftCasingVibrateSystemView::OnButton2SaveProject()
{
	// TODO:  在此添加命令处理程序代码
}

// 项目管理
void CAirCraftCasingVibrateSystemView::OnButtonProjectManage()
{
	// TODO:  在此添加命令处理程序代码
	CProjectManageView projectView;
	int  i = projectView.DoModal();
}

// 打开数据文件
void CAirCraftCasingVibrateSystemView::OnButtonOpenDataFile()
{
	// TODO:  在此添加命令处理程序代码
	int projectId = theApp.m_currentProject.GetProjectId();
	if (projectId <= 0){
		AfxMessageBox("请先打开或者新建项目");
		return;
	}
	CSignalDataView signalDataView;
	signalDataView.DoModal();
}

// 导出通道参数
void CAirCraftCasingVibrateSystemView::OnButtonExportChannelPara()
{
	// TODO:  在此添加命令处理程序代码
}

//导入通道参数
void CAirCraftCasingVibrateSystemView::OnButtonImportChannelPara()
{
	// TODO:  在此添加命令处理程序代码
}

// 导出系统参数
void CAirCraftCasingVibrateSystemView::OnButtonExportSysPara()
{
	// TODO:  在此添加命令处理程序代码
}

// 导入系统参数
void CAirCraftCasingVibrateSystemView::OnButtonImportSysPara()
{
	// TODO:  在此添加命令处理程序代码
}


//暂停采集
void CAirCraftCasingVibrateSystemView::OnButtonSuspendCapture()
{
	// TODO:  在此添加命令处理程序代码
}

//开始采集
void CAirCraftCasingVibrateSystemView::OnButtonStartCapture()
{
	// TODO:  在此添加命令处理程序代码
	
	// 设置底部坐标轴为自动
	//m_pBottomAxis->SetAutomatic(true);
	int projectId = theApp.m_currentProject.GetProjectId();
	if (projectId <= 0){
		AfxMessageBox("请先打开或者新建项目");
		return;
	}
	if (!theApp.m_bThreadActive){
		///////若此时没有开始采集
		// 初始化View
		InitializeView();
		// 清空线
		//m_pLineSerie->ClearSerie();
		// 计算通道个数
		CalculateChannelNum(m_nChannelNums);
		///清空采集数据vector
		theApp.m_collectData.clear();
		///初始化通道数据
		for (int i = 0; i < m_nChannelNums;i++){
			ThreadSafeQueue<AcquiredSignal> acquiredSignalQueue;
			theApp.m_collectData.push_back(acquiredSignalQueue);
		}
		//读取数据
		m_signalMainController.StartCaptureData(m_nChannelNums);
		
		m_signalMainController.StartAutoSaveCollectionData();
		//存储数据
		// view显示数据
		ShowDataToView(m_nChannelNums);
		// 设置读取线程标志
		theApp.m_bThreadActive = true;
		// 设置显示信息线程标志
		theApp.m_bShowInfThreadActive = true;
	}
}

// 停止采集
void CAirCraftCasingVibrateSystemView::OnBtnStopCapture()
{
	// TODO:  在此添加命令处理程序代码
	for (int i = 11; i < m_nChannelNums + 11; i++)
	{
		KillTimer(i);
	}
	theApp.m_bThreadActive = false;
	theApp.m_bShowInfThreadActive = false;
}

// 停止回放
void CAirCraftCasingVibrateSystemView::OnBtnStopPlayback()
{
	// TODO:  在此添加命令处理程序代码
}

//开始回放
void CAirCraftCasingVibrateSystemView::OnBtnStartPlayback()
{
	// TODO:  在此添加命令处理程序代码
}

// 关闭所有窗口
void CAirCraftCasingVibrateSystemView::OnBtnCloseAllWindow()
{
	// TODO:  在此添加命令处理程序代码
}

// 横向放大
void CAirCraftCasingVibrateSystemView::OnBtnTransverseAmplification()
{
	// TODO:  在此添加命令处理程序代码
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	CDuChartCtrlStaticFunction::HengxiangFangda(&view->m_chart);
}

// 横向缩小
void CAirCraftCasingVibrateSystemView::OnBtnHorizontalReduction()
{
	// TODO:  在此添加命令处理程序代码
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	CDuChartCtrlStaticFunction::HengxiangSuoxiao(&view->m_chart);

}

// 纵向缩小
void CAirCraftCasingVibrateSystemView::OnBtnVerticalReduction()
{
	// TODO:  在此添加命令处理程序代码
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	CDuChartCtrlStaticFunction::ZongxiangSuoxiao(&view->m_chart);
}

//纵向放大
void CAirCraftCasingVibrateSystemView::OnBtnVerticalAmplification()
{
	// TODO:  在此添加命令处理程序代码
	// TODO:  在此添加命令处理程序代码
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	CDuChartCtrlStaticFunction::ZongxiangFangda(&view->m_chart);
}

//单光标
void CAirCraftCasingVibrateSystemView::OnBtnSingleCursor()
{
	// TODO:  在此添加命令处理程序代码
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	CDuChartCtrlStaticFunction::SetCursorSingle(&view->m_chart);
}

//峰值
void CAirCraftCasingVibrateSystemView::OnBtnPeakValue()
{
	// TODO:  在此添加命令处理程序代码
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	
	CDuChartCtrlStaticFunction::SetCursorPeak(&view->m_chart);
}


// 自动刻度
void CAirCraftCasingVibrateSystemView::OnBtnAutoScale()
{
	// TODO:  在此添加命令处理程序代码
	// TODO:  在此添加命令处理程序代码
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();

	CDuChartCtrlStaticFunction::AutoXScale(&view->m_chart,FALSE);
	//CDuChartCtrlStaticFunction::AutoYScale(&view->m_chart, FALSE);
	
}

// 默认刻度
void CAirCraftCasingVibrateSystemView::OnBtnSelfScale()
{
	// TODO:  在此添加命令处理程序代码
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	//CDuChartCtrlStaticFunction::SetCursorNone(&view->m_chart);
	CChartStandardAxisDu * leftAxis = (CChartStandardAxisDu*)view->m_chart.GetAxisDu(CChartCtrl::LeftAxis, 0);
	CChartStandardAxisDu * bottomAxis = (CChartStandardAxisDu*)view->m_chart.GetAxisDu(CChartCtrl::BottomAxis, 0);
	bottomAxis->SetMinMax(0, 1000);//设置下刻度
	bottomAxis->SetTickIncrement(false, 100);

	leftAxis->SetMinMax(-0.1, 0.1);
	leftAxis->SetTickIncrement(false, 0.05);
}

// 无光标
void CAirCraftCasingVibrateSystemView::OnBtnNoCorror()
{
	// TODO:  在此添加命令处理程序代码
	CAirCraftCasingVibrateSystemView *view;
	view = (CAirCraftCasingVibrateSystemView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveFrame()->GetActiveView();
	CDuChartCtrlStaticFunction::SetCursorNone(&view->m_chart);
}

//开始采样
void CAirCraftCasingVibrateSystemView::OnBtnStartSmaple()
{
	int projectId = theApp.m_currentProject.GetProjectId();
	if (projectId <= 0){
		AfxMessageBox("请先打开或者新建项目");
		return;
	}
	theApp.m_bIsSample = true;
}

// 停止采样
void CAirCraftCasingVibrateSystemView::OnBtnStopSample()
{
	// TODO:  在此添加命令处理程序代码
	//////开线程去保存！！！！！！！！！！！！！！
	//m_fileUtile.SaveSampleData(theApp.m_sampleData);

	
}

//工程单位
void CAirCraftCasingVibrateSystemView::OnBtnProjectUnit()
{
	// TODO:  在此添加命令处理程序代码
	CEngineerUnitView engineerUnitView;
	engineerUnitView.DoModal();
}

// 报警设置
void CAirCraftCasingVibrateSystemView::OnBtnAlarmSet()
{
	// TODO:  在此添加命令处理程序代码
	CAlarmParaSetView alarmView;
	alarmView.DoModal();
	
}

// 图像属性
void CAirCraftCasingVibrateSystemView::OnBtnGraphAttr()
{
	// TODO:  在此添加命令处理程序代码
	m_graphAttributeView.DoModal();
}

/*定时器*/
void CAirCraftCasingVibrateSystemView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	/*11-26是采集*/
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
	/*27 开始采样*/
	if (27 == nIDEvent)
	{
		/*定时采样*/
		StartSampleChannelDatat();
	}
	CFormView::OnTimer(nIDEvent);
}

/*线束画图*/
bool CAirCraftCasingVibrateSystemView::DrawLining(int nViewIndex)
{
	m_dview[nViewIndex]->m_pLineSerie->ClearSerie();
	m_dview[nViewIndex]->m_pLineSerie->SetNeedCalStatValue(TRUE);
	if (!theApp.m_echoData[nViewIndex].empty()){ 
		////回显对列中有数据，则去刷新数据
		shared_ptr<EchoSignal>  echoSignal = theApp.m_echoData[nViewIndex].wait_and_pop();
		double *x = echoSignal->GetXArray();
		double *y = echoSignal->GetYArray();
		int size = 1000;
		/*for (int i = 0; i < 5; i++){
			TRACE("\n窗口：%d x=%f,y=%f\n",nViewIndex, x[i], y[i]);
			}*/
		if (echoSignal->GetXLength() != 0 && echoSignal->GetYLength() != 0){
			TRACE("\n刷新%d窗口.......................................................\n",nViewIndex);
			////当队列不是空时，刷新图表的显示
			m_dview[nViewIndex]->m_pLineSerie->AddPoints(echoSignal->GetXArray(), echoSignal->GetYArray(), echoSignal->GetYLength()/2);
		}
	}
	return true;
}

// 计算当前开的窗口个数->通道数
bool CAirCraftCasingVibrateSystemView::CalculateChannelNum(int &nChannelNums)
{
	// 显示
	POSITION curTemplatePos = theApp.GetFirstDocTemplatePosition();
	CDocTemplate *m_doc = theApp.GetNextDocTemplate(curTemplatePos);
	/////CDocTemplate *m_doc1 = theApp.GetNextDocTemplate(curTemplatePos);//文档模板
	//获得文档:
	nChannelNums = 0;
	curTemplatePos = m_doc->GetFirstDocPosition();
	while (curTemplatePos != NULL)
	{
		(CAirCraftCasingVibrateSystemDoc*)m_doc->GetNextDoc(curTemplatePos);
		nChannelNums++;
	}
	return 0;


}

//初始化View
bool CAirCraftCasingVibrateSystemView::InitializeView()
{
	// 显示
	POSITION curTemplatePos = theApp.GetFirstDocTemplatePosition();
	CDocTemplate *m_doc = theApp.GetNextDocTemplate(curTemplatePos);
	/////CDocTemplate *m_doc1 = theApp.GetNextDocTemplate(curTemplatePos);//文档模板
	//获得文档:
	CAirCraftCasingVibrateSystemDoc * pdoc[20];
	int i = 0;
	curTemplatePos = m_doc->GetFirstDocPosition();
	while (curTemplatePos != NULL)
	{
		pdoc[i] = (CAirCraftCasingVibrateSystemDoc*)m_doc->GetNextDoc(curTemplatePos);
		//获得视图:
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


/*检测设备管理*/
void CAirCraftCasingVibrateSystemView::OnButtonDetectDevice()
{
	// TODO:  在此添加命令处理程序代码
	CDetectDeviceManageView detectDeviceManageView;
	detectDeviceManageView.DoModal();
}

/*被检测设备管理*/
void CAirCraftCasingVibrateSystemView::OnButtonDetectedDevice()
{
	// TODO:  在此添加命令处理程序代码
	CDetectedDeviceManageView detectedDeviceManegeView;
	detectedDeviceManegeView.DoModal();
}


/*定时采样*/
void CAirCraftCasingVibrateSystemView::StartSampleChannelDatat()
{
	int nchannelNums;
	CalculateChannelNum(nchannelNums);
	for (int i = 0; i < nchannelNums; i++)
	{
		/*theApp.m_sampleData[i].push(theApp.m_vSersor[i].popSampleSignalQuene());*/
	}

}

// 开启定时器开始采集
bool CAirCraftCasingVibrateSystemView::ShowDataToView(int nChannelNum)
{
	for (int i = 11; i < 11 + nChannelNum; i++)
	{
		SetTimer(i, 100, NULL);
	}
	return true;
}