#pragma once
#include "DuExport.h"
#include "DuChartCtrlShuxing.h"
class  CDuChartCtrlStaticFunction
{
public:
	CDuChartCtrlStaticFunction(void);
	virtual ~CDuChartCtrlStaticFunction(void);

public:
	// 清空所有
	static void RemoveAll(class CDuChartCtrl * pDuChartCtrl);

    // 设置合并显示或分开显示
    static void SetHebingOrFenkai(class CDuChartCtrl * pDuChartCtrl, int n) {}

	// 构造坐标轴
	static void CreateAxis(class CDuChartCtrl * pDuChartCtrl, int nSerieCount, 
		int nXAxisType = CDuChartCtrlShuxing::typeAxisLine, 
		int nYAxisType = CDuChartCtrlShuxing::typeAxisLine);

	// 构造曲线
	static void CreateSeries(class CDuChartCtrl * pDuChartCtrl, int nSerieCount, int nSerieType);

	// 无光标
	static void SetCursorNone(class CDuChartCtrl * pDuChartCtrl, BOOL bRefresh = FALSE);
	// 单光标
	static void SetCursorSingle(class CDuChartCtrl * pDuChartCtrl, BOOL bRefresh = FALSE);
	// 双光标
	static void SetCursorTwo(class CDuChartCtrl * pDuChartCtrl, BOOL bRefresh = FALSE);
	// 峰光标
	static void SetCursorPeak(class CDuChartCtrl * pDuChartCtrl, BOOL bRefresh = FALSE);
	// 谷光标
	static void SetCursorTrough(class CDuChartCtrl * pDuChartCtrl, BOOL bRefresh = FALSE);
	// 谐光标
	static void SetCursorXie(class CDuChartCtrl * pDuChartCtrl, BOOL bRefresh = FALSE);

	// 上移
	static void KeyUp(class CDuChartCtrl * pDuChartCtrl);
	// 下移
	static void KeyDown(class CDuChartCtrl * pDuChartCtrl);
	// 左移
	static void KeyLeft(class CDuChartCtrl * pDuChartCtrl);
	// 右移
	static void KeyRight(class CDuChartCtrl * pDuChartCtrl);

	// 自动刻度
	static void AutoXScale(class CDuChartCtrl * pDuChartCtrl, BOOL bRefresh);
	static void AutoYScale(class CDuChartCtrl * pDuChartCtrl, BOOL bRefresh);

	// 横向放大
	static void HengxiangFangda(class CDuChartCtrl * pDuChartCtrl);
	static void HengxiangSuoxiao(class CDuChartCtrl * pDuChartCtrl);
	static void ZongxiangFangda(class CDuChartCtrl * pDuChartCtrl);
	static void ZongxiangSuoxiao(class CDuChartCtrl * pDuChartCtrl);
	
};

