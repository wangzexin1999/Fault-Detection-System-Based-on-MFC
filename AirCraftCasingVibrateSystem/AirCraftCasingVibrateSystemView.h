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
#include "GraphAttributeView.h"
#include "TbSensor.h"
#include "SmartFFTWComplexArray.h"
#include "SmartArray.h"
#include "AirCraftCasingVibrateSystemDoc.h"
#include "EchoSignal.h"
class CAirCraftCasingVibrateSystemView : public CFormView
{
protected: // 仅从序列化创建
	CAirCraftCasingVibrateSystemView();
	DECLARE_DYNCREATE(CAirCraftCasingVibrateSystemView)

private:
	CDuChartCtrl m_chart;
	CChartLineSerieDu *m_pLineSerie;
	int m_flag = false;  // 调整控件大小标志
	CSignalSelectView  m_signalSelectView;   //信号选择界面
	CGraphAttributeView m_graphAttributeView; // 图形属性界面
	TbSensor m_sensor;////传感器对象
	SensorController m_sensorController; ///传感器控制类

	/*SmartArray<double> m_xData; ///x坐标
	SmartArray<double> m_yData; ///y坐标

	SmartFFTWComplexArray m_fftwInput; ///傅里叶变换初始的输入
	SmartFFTWComplexArray m_fftwOutput;///傅里叶变换之后的输出 */

	ThreadSafeQueue<EchoSignal>  m_echoSignalQueue;

	int m_icurrentWindowNumber;


	static int m_iwindowCount;//窗口数量

public:
	enum{ IDD = IDD_AIRCRAFTCASINGVIBRATESYSTEM_FORM };

	////多文档框架对应的文档类
	CAirCraftCasingVibrateSystemDoc* GetDocument() const;

// 操作
public:

	 double m_readFromCSVFile[100][1000];//文件的测试数据数组，测试用

	 /**********************************************************************
	 功能描述： 采集&采样数据
	 输入参数：
	 输出参数：
	 返 回 值：
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	 ----------------------------------------------------------------------
	 ***********************************************************************/
	 void  CaptureData();
	/**********************************************************************
	功能描述： 开启线程采集数据
	输入参数：  
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void OpenThread2CaptureData();
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
	功能描述： 自动保存文件的线程函数
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void AutoSaveCollectionData();

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
	afx_msg void OnBtnGraphAttr();
	
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

