#pragma once
#include "ChartFont.h"
#include "DuExport.h"
#include <vector>
class  CDuChartCtrlShuxing
{
public:
	friend class CDuChartCtrl;

public:
	CDuChartCtrlShuxing(void);
	virtual ~CDuChartCtrlShuxing(void);

public:
	enum
	{
		CHARTCTRL_MAX_SERIE_COUNT = 16,		// 最大曲线个数
	};

	enum ESerieType
	{
		typeSerieError = -1,
		typeSerieLine = 0,
		typeSerieBeipc,
	};

	enum EHebingOrFengkai
	{
		typeHebingOrFengkaiError = -1,
		typeHebing = 0,		// 合并显示
		typeFengkai,		// 分开显示
		typeGongyongXZhou,	// 公用X轴
	};

	enum ECursorType
	{
		typeCursorError = -1,
		typeCursorNone = 0,	// 无光标
		typeCursorSingle,	// 单光标
		typeCursorTwo,		// 双光标
		typeCursorPeak,		// 峰光标
		typeCursorTrough,	// 谷光标
		typeCursorXie,		// 谐光标
		typeEnd,
	};

	enum EAxisType
	{
		typeAxisError = -1,
		typeAxisLine = 0,	// 线形坐标
		typeAxisLog,		// 对数坐标
		typeAxisBar,		// 棒图坐标
	};

	enum EXAxisZoomType
	{
		typeXZoomError = -1,
		typeXZoomCenter = 0,	// 缩放时中间固定
		typeXZoomLeft,			// 缩放时左边固定
	};

	enum EYAxisZoomType
	{
		typeYZoomError = -1,
		typeYZoomCenter = 0,	// 缩放时中间固定
		typeYZoomBottom ,		// 缩放时下边固定
		typeYZoomZero ,			// 缩放时零值固定
	};
	
public:
	int m_nSerieType;					// 图形类型
	int m_nHebingOrFengkai;				// 合并或者分开
	int m_nFengkaiColumnCount;			// 分开列数
	int m_nCursorType;					// 光标类型

public:
	COLORREF m_colTBKColor;				// 信息区域背景颜色
	CChartFont m_chartFontTBKValue;		// 信息区域字体

	COLORREF m_colCursorColor1;			// 光标1颜色
	COLORREF m_colCursorColor2;			// 光标2颜色

	BOOL m_bDrawCursorValue;			// 是否画光标值
	BOOL m_bDrawLegend;					// 是否画图例
	BOOL m_bDrawStatValue;				// 是否画统计值
	int m_nXieMaxCount;					// 谐光标最大个数
	BOOL m_bDrawStatMax;				// 是否显示最大值
	BOOL m_bDrawStatMin;				// 是否显示最小值
	BOOL m_bDrawStatAve;				// 是否显示平均值
	BOOL m_bDrawStatPeak;				// 是否显示峰峰值
	BOOL m_bDrawStatStd;				// 是否显示标准差
	BOOL m_bDrawStatRms;				// 是否显示有效值
	BOOL m_bDrawStatSum;                // 是否显示总值

	CRectTracker m_rectCursorValue;		// 光标值区域
	CRectTracker m_rectLegend;			// 图例区域
	CRectTracker m_rectStatValue;		// 统计值区域

	// 曲线颜色
	COLORREF m_colorSerie[CHARTCTRL_MAX_SERIE_COUNT];

	int m_nXZoomType;					// X轴缩放类型
	int m_nYZoomType;					// Y轴缩放类型

public:
	//! 画图

	void DrawCursorValue(CDC * pDC);		// 画光标值
	void DrawLegend(CDC * pDC);				// 画图例
	void DrawStatValue(CDC * pDC);			// 画统计值
	void ClipCursorValueArea(CDC * pDC);	// 计算光标值区域
	void ClipCursorValueAreaOne(CDC * pDC);	// 计算光标值区域 - 单光标
	void ClipCursorValueAreaTwo(CDC * pDC);	// 计算光标值区域 - 双光标
	void ClipCursorValueAreaXie(CDC * pDC);	// 计算光标值区域 - 谐光标
	void ClipLegendArea(CDC * pDC);			// 计算图例区域
	void ClipStatValueArea(CDC * pDC);		// 计算统计值区域
	void ProtectTrackerRect(CRectTracker * pTrackerRect, CRect * pRect);
	void DrawTrackerValue(CDC* pDC, CRectTracker * pTracker);
	void DrawLegendTrackerValue(CDC* pDC, CRectTracker * pTracker);

protected:
	class CChartCtrl * m_pParentCtrl;

	// 信息
	int m_nTrackerValueRowCount;			// 行数
	int m_nTrackerValueColumnCount;			// 列数
	int m_nTrackerValueColumnWidth[3];		// 宽度
	CString m_strTrackerValue[3][22];		// 字符串
	COLORREF m_colorTrackerValue[3][22];	// 颜色

public:
	std::vector<CString> m_addDrawString;
};

