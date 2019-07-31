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
#include "CheckTaskController.h"
#include "GraphAttributeView.h"
#include "AlarmParaSetView.h"
#include "NewProjectView.h"
#include "EngineerUnitView.h"
#include "ProjectManageView.h"
#include "SignalDataView.h"
#include "DetectDeviceManageView.h"
#include "DetectedDeviceManageView.h"
#include "FileUtil.h"
class CAirCraftCasingVibrateSystemView : public CFormView
{
protected: // 仅从序列化创建
	CAirCraftCasingVibrateSystemView();
	DECLARE_DYNCREATE(CAirCraftCasingVibrateSystemView)

public:
	enum{ IDD = IDD_AIRCRAFTCASINGVIBRATESYSTEM_FORM };

// 特性
public:
	CAirCraftCasingVibrateSystemDoc* GetDocument() const;

// 操作
public:
	CDuChartCtrl m_chart;
	CChartLineSerieDu *m_pLineSerie;
	int m_flag = false;  // 调整控件大小标志
	int m_nChannelNums = 0; // 通道个数
	CAirCraftCasingVibrateSystemView * m_dview[20]; //视图
	CCheckTaskController  m_signalMainController;// 信号的业务逻辑
	CSignalSelectView  m_signalSelectView;   //信号选择界面
	CGraphAttributeView m_graphAttributeView; // 图形属性界面
	CNewProjectView m_newProjectView;    // 项目管理界面
	CFileUtil  m_fileUtile;
	/**********************************************************************
	功能描述： 读取数据显示
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void drawMoving2();
	/**********************************************************************
	功能描述： 数组左移动
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void LeftMoveArray(double* ptr, size_t length, double data);

	/**********************************************************************
	功能描述： 计算有多少个通道
	输入参数：nChannelNums -- 通道个数
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	bool CalculateChannelNum(int &nChannelNums);
	/**********************************************************************
	功能描述： 开始采集画图
	输入参数：nViewIndex--画多少个
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	bool DrawLining(int nViewIndex);
	/**********************************************************************
	功能描述： 转换成JSON格式
	输入参数：nXvalue -- X值； nYValue--Y值
	输出参数：strData -- 输出的JSON字符串
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	bool  ConvertJSON(double dXvalue[], double dYValue[], CString &strData);
	/**********************************************************************
	功能描述： 设置颜色,
	输入参数：nR--red,nG--green,nB--blue
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	COLORREF SetColor(int nR, int nG, int nB);
	/**********************************************************************
	功能描述： 开始采样，拼接数组,
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	bool SplitData();
	/**********************************************************************
	功能描述： // 得到部分数组,
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	bool GetPartArray();
	/**********************************************************************
	功能描述：显示信息,
	输入参数：nType 1--采集显示 2--回放显示
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	bool DisplayInf(int nType);
	/**********************************************************************
	功能描述：初始化view
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	bool InitializeView();
	/**********************************************************************
	功能描述：显示数据
	输入参数：nChannelNum--通道个数
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	bool ShowDataToView(int nChannelNum);
	/**********************************************************************
	 功能描述： 开始采集通道数据
	 输入参数： 
	 输出参数： 
	 返 回 值： 
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	 ----------------------------------------------------------------------
	 ***********************************************************************/
	void StartSampleChannelDatat();
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
	afx_msg void OnButtonNewProject();
	afx_msg void OnButton2SaveProject();
	afx_msg void OnButtonProjectManage();
	afx_msg void OnButtonOpenDataFile();
	afx_msg void OnButtonExportChannelPara();
	afx_msg void OnButtonImportChannelPara();
	afx_msg void OnButtonExportSysPara();
	afx_msg void OnButtonImportSysPara();
	afx_msg void OnButtonSuspendCapture();
	afx_msg void OnButtonStartCapture();
	afx_msg void OnBtnStopCapture();
	afx_msg void OnBtnStopPlayback();
	afx_msg void OnBtnStartPlayback();
	afx_msg void OnBtnCloseAllWindow();
	afx_msg void OnBtnTransverseAmplification();
	afx_msg void OnBtnHorizontalReduction();
	afx_msg void OnBtnVerticalReduction();
	afx_msg void OnBtnVerticalAmplification();
	afx_msg void OnBtnSingleCursor();
	afx_msg void OnBtnPeakValue();
	afx_msg void OnBtnAutoScale();
	afx_msg void OnBtnSelfScale();
	afx_msg void OnBtnNoCorror();
	afx_msg void OnBtnStartSmaple();
	afx_msg void OnBtnStopSample();
	afx_msg void OnBtnProjectUnit();
	afx_msg void OnBtnAlarmSet();
	afx_msg void OnBtnGraphAttr();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnButtonDetectDevice();
	afx_msg void OnButtonDetectedDevice();
};

#ifndef _DEBUG  // AirCraftCasingVibrateSystemView.cpp 中的调试版本
inline CAirCraftCasingVibrateSystemDoc* CAirCraftCasingVibrateSystemView::GetDocument() const
   { return reinterpret_cast<CAirCraftCasingVibrateSystemDoc*>(m_pDocument); }
#endif

