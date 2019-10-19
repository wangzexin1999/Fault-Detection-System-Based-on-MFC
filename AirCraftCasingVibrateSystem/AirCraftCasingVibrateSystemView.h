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

// AirCraftCasingVibrateSystemView.h : CAirCraftCasingVibrateSystemView 类的接口
//

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
#include "SensorController.h"

#include "TbSensor.h"
#include "SmartFFTWComplexArray.h"
#include "SmartArray.h"
#include "AirCraftCasingVibrateSystemDoc.h"
#include "EchoSignal.h"
#include "redisUtil.h"
#include "RealTimeSignal.h"

class CAirCraftCasingVibrateSystemView : public CFormView
{
protected: // 仅从序列化创建
	CAirCraftCasingVibrateSystemView();
	DECLARE_DYNCREATE(CAirCraftCasingVibrateSystemView)
private:

	CDuChartCtrl m_chart; // 画图控件
	CChartLineSerieDu *m_pLineSerie; // 线
	int m_flag = false;  // 调整控件大小标志
	
	CSignalSelectView  m_signalSelectView;   //信号选择界面

	SensorController m_sensorController; ///传感器控制类

	ThreadSafeQueue<EchoSignal>  m_echoSignalQueue; // 回显信号队列
	int m_icurrentWindowNumber;  // 窗口
	ThreadSafeQueue<AcquiredSignal> m_collectionDataQueue;  //采集队列
	int m_iSampleDataEchoTimerNum;  //采样数据回显窗口
	static int m_iwindowCount;//窗口数量
	int m_realTimeSignalCaptureflag = true; // 采集实时数据时，第一次是push，接下来是赋值
	int m_icountNumsReadDraw = 0; //采样数据截取时的索引
	
public:
	ThreadSafeQueue<RealTimeSignal> m_realTimeSignal;  // 实时数据队列
	vector<AcquiredSignal> m_sampleFromFileDataQueue;  // 采样队列从文件中获得
public:
	enum{ IDD = IDD_AIRCRAFTCASINGVIBRATESYSTEM_FORM };

	////多文档框架对应的文档类
	CAirCraftCasingVibrateSystemDoc* GetDocument() const;

// 操作
public:

	 double m_readFromCSVFile[100][1000];//文件的测试数据数组，测试用

	
	/**********************************************************************
	功能描述： 刷新图表控件
	输入参数： 
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void RefershChartCtrlData();
	/**********************************************************************
	功能描述： 刷新窗口
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void RefershView();
	
	/**********************************************************************
	功能描述： 终止刷新窗口
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void StopRefershView();

	
	/**********************************************************************
	功能描述： 保存采集数据
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void SaveCollectionData(ThreadSafeQueue<AcquiredSignal> acquireSignalQueue);
	
	/**********************************************************************
	功能描述： 得到view中的ChartCtrl控件
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	CDuChartCtrl & GetChartCtrl();

	/**********************************************************************
	功能描述： 设置当前窗口的序号
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void SetViewNumber(int windowNumber);

	/**********************************************************************
	功能描述： 重置窗口
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void ResetView();
	/**********************************************************************
	 功能描述：刷新图形属性 
	 输入参数：
	 输出参数： 
	 返 回 值： 
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void RefreshGraphAttri();
	/**********************************************************************
	 功能描述： 采样数据回显
	 输入参数：
	 输出参数： 
	 返 回 值： 
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void SampleDataEcho();
	/**********************************************************************
	 功能描述： 设置回显数据的定时器
	 输入参数：
	 输出参数： 
	 返 回 值： 
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void SetSampleDataEchoTimerNum(int nSampleDataEchoTimerNums);
	/**********************************************************************
	 功能描述： 获得回显数据的定时器
	 输入参数：
	 输出参数： 
	 返 回 值： 
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	int SetSampleDataEchoTimerNum();
	/**********************************************************************
	 功能描述： 开始回显
	 输入参数：
	 输出参数： 
	 返 回 值： 
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void StartSampleEncho();
	/**********************************************************************
	 功能描述： 停止采样回放
	 输入参数：
	 输出参数： 
	 返 回 值： 
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void StopSampleEncho();
	/**********************************************************************
	 功能描述： 采样数据的截取
	 输入参数：dXData--x数据；dYData--y数据；nNums--截取的个数
	 输出参数： 
	 返 回 值： 
	 其它说明：从文件中读取采样数据后，放到vector里面，回显时从vector截取一部分回显
	 修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void SplitVector(SmartArray<double> &dXData, SmartArray<double> &dYData,int nNums);
	/**********************************************************************
	功能描述：设置采集窗口的传感器
	输入参数：
	输出参数：
	返 回 值：
	其它说明：设置采集窗口的传感器
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void SetSensor(TbSensor sensor);
	/**********************************************************************
	功能描述：添加数据到回显队列
	输入参数：
	输出参数：
	返 回 值：
	其它说明：设置采集窗口的传感器
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void AddData2EchoSignalQueue(EchoSignal sensor);

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

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
	afx_msg void OnButtonSignalSelect();
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
};

#ifndef _DEBUG  // AirCraftCasingVibrateSystemView.cpp 中的调试版本
inline CAirCraftCasingVibrateSystemDoc* CAirCraftCasingVibrateSystemView::GetDocument() const
   { return reinterpret_cast<CAirCraftCasingVibrateSystemDoc*>(m_pDocument); }
#endif

