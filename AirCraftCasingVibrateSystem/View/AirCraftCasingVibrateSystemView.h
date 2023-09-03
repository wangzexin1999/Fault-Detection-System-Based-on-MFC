
#pragma once
#include "ChartCtrl/ChartCtrl.h"
#include "ChartCtrl/ChartAxis.h"
#include "ChartCtrl/ChartAxisLabel.h"
#include "ChartCtrl/ChartDragLineCursorDu.h"
#include "ChartCtrl/DuChartCtrl.h"
#include "ChartCtrl/ChartStandardAxisDu.h"
#include "ChartCtrl/DuChartCtrlStaticFunction.h"
#include "ChartCtrl/ChartLineSerieDu.h"
#include "resource.h"
#include "SignalSelectView.h"
#include "ChannelController.h"
#include "TbChannel.h"
#include "SmartFFTWComplexArray.h"
#include "SmartArray.h"
#include "AirCraftCasingVibrateSystemDoc.h"
#include "EchoSignal.h"
#include "redisUtil.h"
#include "RealTimeSignal.h"
#include "JsonUtil.h"
#include "DictionaryController.h"
#include "SignalTestRecordController.h"
#include "TbSignalTestRecord.h"
#include "DHTestHardWareController.h"
#define WM_USER_REFRESH_CHART WM_USER + 1024

class CAirCraftCasingVibrateSystemView : public CFormView
{
public:
	CAirCraftCasingVibrateSystemView();
protected: // 仅从序列化创建
	//CAirCraftCasingVibrateSystemView();
	DECLARE_DYNCREATE(CAirCraftCasingVibrateSystemView)
private:
	DHTestHardWareController m_dhtestHardWareController;
	CDuChartCtrl m_chart; // 画图控件
	CChartLineSerieDu *m_pLineSerie; // 线
	int m_flag = false;  // 调整控件大小标志

	CSignalSelectView  m_signalSelectView;   //信号选择界面

	ChannelController m_channelController; ///传感器控制类

	ThreadSafeQueue<double *>  m_echoSignalQueue; // 回显信号队列

	EchoSignal m_echoSignal;

	int m_icurrentWindowNumber;  // 窗口

	int m_iSampleDataEchoTimerNum;  //采样数据回显窗口

	static int m_iwindowCount;//窗口数量
	int m_realTimeSignalCaptureflag = true; // 采集实时数据时，第一次是push，接下来是赋值
	int m_icountNumsReadDraw = 0; //采样数据截取时的索引
	//Value m_analysisFrequency;
	SignalTestRecordController m_signalTestRecordController;
	TbSignalTestRecord m_signalTestRecord;
	double m_peak;
	double m_gross;
	TbChannel m_currentChannel;
public:
	ThreadSafeQueue<RealTimeSignal> m_realTimeSignal;  // 实时数据队列
	vector<AcquiredSignal> m_sampleFromFileDataQueue;  // 采样队列从文件中获得

	double GetPeak();
	void SetPeak(double peak);
	double GetGross();
	void SetGross(double gross);

	bool b_mutation = true;								//是否使用突变
	double mutationValue = 100;								//突变值

public:
	enum{ IDD = IDD_AIRCRAFTCASINGVIBRATESYSTEM_FORM };

	////多文档框架对应的文档类
	CAirCraftCasingVibrateSystemDoc* GetDocument() const;

// 操作
public:

	/**********************************************************************
	功能描述： 开启线程刷新窗口
	***********************************************************************/
	void openThread2RefershView();

	/**********************************************************************
	功能描述： 开启线程刷新窗口
	***********************************************************************/
	void openTimer2RefershView();

	/**********************************************************************
	功能描述： 开启线程刷新窗口
	***********************************************************************/
	void killTimer2RefershView();

	/**********************************************************************
	功能描述： 刷新窗口的线程函数
	***********************************************************************/
	void RefershView();
	
	/**********************************************************************
	功能描述： 得到view中的ChartCtrl控件
	***********************************************************************/
	CDuChartCtrl & GetChartCtrl();



	/**********************************************************************
	功能描述： 设置当前窗口的序号
	***********************************************************************/
	void SetViewNumber(int windowNumber);



	/**********************************************************************
	功能描述： 重置窗口
	***********************************************************************/
	void ResetView();




	/**********************************************************************
	 功能描述：刷新图形属性 
	***********************************************************************/
	void RefreshGraphAttri();




	/**********************************************************************
	 功能描述： 采样数据回显
	***********************************************************************/
	void SampleDataEcho();





	/**********************************************************************
	 功能描述： 设置回显数据的定时器
	***********************************************************************/
	void SetSampleDataEchoTimerNum(int nSampleDataEchoTimerNums);





	/**********************************************************************
	 功能描述： 获得回显数据的定时器
	***********************************************************************/
	int GetSampleDataEchoTimerNum();
	/**********************************************************************
	 功能描述： 开始回显
	***********************************************************************/
	void StartSampleEncho();
	/**********************************************************************
	 功能描述： 停止采样回放
	***********************************************************************/
	void StopSampleEncho();
	/**********************************************************************
	 功能描述： 采样数据的截取
	 输入参数：dXData--x数据；dYData--y数据；nNums--截取的个数
	 其它说明：从文件中读取采样数据后，放到vector里面，回显时从vector截取一部分回显
	***********************************************************************/
	void SplitVector(SmartArray<double> &dXData, SmartArray<double> &dYData,int nNums);
	/**********************************************************************
	功能描述：设置采集窗口的通道
	其它说明：设置采集窗口的传感器
	***********************************************************************/
	void SetChannel(TbChannel channel);
	/**********************************************************************
	功能描述：得到采集窗口对应的通道
	其它说明：设置采集窗口的传感器
	----------------------------------------------------------------------
	***********************************************************************/
	void GetChannel(TbChannel &channel);
	/**********************************************************************
	功能描述：添加回显数据
	其它说明：设置采集窗口的传感器
	***********************************************************************/
	void PushEchoSignal(double* chartPoints);
	/**********************************************************************
	功能描述：添加回显数据
	其它说明：设置采集窗口的传感器
	***********************************************************************/
	void clearEchoSignal();

	/**********************************************************************
	功能描述：添加回显数据
	其它说明：设置采集窗口的传感器
	***********************************************************************/
	void SetEchoSignal(double* chartPoints);

	int echoStartTime = 0;
	/**********************************************************************
	功能描述：刷新图标的响应事件
	***********************************************************************/
	afx_msg LRESULT OnRefreshChart(WPARAM wParam, LPARAM lParam);


// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
	DictionaryController m_dictionaryController;
// 实现
public:
	virtual ~CAirCraftCasingVibrateSystemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	//afx_msg void OnButtonSignalSelect();
	void OnBtnTransverseAmplification();
	void OnBtnHorizontalReduction();
	void OnBtnVerticalReduction();
	void OnBtnVerticalAmplification();
	void OnBtnSingleCursor();
	void OnBtnPeakValue();
	void OnBtnAutoScale();
	void OnBtnSelfScale();
	void OnBtnNoCorror();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	int a = 1;

	/**********************************************************************
	功能描述：设置xy坐标的最小值和最大值
	输入参数：xmin,xmax,ymin,ymax
	其它说明：坐标值存在默认参数-1，如果使用默认参数的话，默认的设置为采集窗口绑定的传感器的参数取值
	***********************************************************************/
	void SetChartXYCoordinateLen(double xmin = -1, double xmax = -1, double ymin = -1, double ymax = -1);
	


};

#ifndef _DEBUG  // AirCraftCasingVibrateSystemView.cpp 中的调试版本
inline CAirCraftCasingVibrateSystemDoc* CAirCraftCasingVibrateSystemView::GetDocument() const
   { return reinterpret_cast<CAirCraftCasingVibrateSystemDoc*>(m_pDocument); }
#endif

