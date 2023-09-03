#include "StdAfx.h"
#include "DuChartCtrlShuxing.h"
#include "ChartCtrl.h"
#include "ChartSerieBase.h"
#include "ChartLineSerie.h"
#include "ChartDragLineCursorDu.h"
#include "ChartLineSerieDu.h"
#include "ChartStandardAxisDu.h"
#include "ChartBarAxisDu.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define CHART_MARGIN 2
#define CHART_LEGEND_BIANCHANG 16

CDuChartCtrlShuxing::CDuChartCtrlShuxing(void)
	: m_pParentCtrl(NULL)
{
	m_nSerieType = typeSerieError;
	m_nHebingOrFengkai = typeHebing;
	m_nFengkaiColumnCount = 1;
	m_nCursorType = typeCursorSingle;

	m_colTBKColor = RGB(192, 192, 192);

	m_colCursorColor1 = RGB(0, 0, 255);
	m_colCursorColor2 = RGB(255, 0, 0);

	m_bDrawCursorValue = TRUE;
	m_bDrawLegend = TRUE;
	m_bDrawStatValue = FALSE;
	m_nXieMaxCount = 20;
	m_bDrawStatMax = TRUE;
	m_bDrawStatMin = TRUE;
	m_bDrawStatAve = TRUE;
	m_bDrawStatPeak = TRUE;
	m_bDrawStatStd = TRUE;
	m_bDrawStatRms = TRUE;

	m_nTrackerValueRowCount = 0;
	m_nTrackerValueColumnCount = 0;

	m_colorSerie[0] = RGB(255, 0, 0);
	m_colorSerie[1] = RGB(0, 150, 0);
	m_colorSerie[2] = RGB(0, 0, 255);
	m_colorSerie[3] = RGB(255, 128, 0);
	m_colorSerie[4] = RGB(128, 0, 128);
	m_colorSerie[5] = RGB(128, 128, 0);
	m_colorSerie[6] = RGB(255, 0, 255);
	m_colorSerie[7] = RGB(64, 128, 128);
	m_colorSerie[8] = RGB(255, 0, 0);
	m_colorSerie[9] = RGB(0, 150, 0);
	m_colorSerie[10] = RGB(0, 0, 255);
	m_colorSerie[11] = RGB(255, 128, 0);
	m_colorSerie[12] = RGB(128, 0, 128);
	m_colorSerie[13] = RGB(128, 128, 0);
	m_colorSerie[14] = RGB(255, 0, 255);
	m_colorSerie[15] = RGB(64, 128, 128);

	m_nXZoomType = typeXZoomLeft;
	m_nYZoomType = typeYZoomZero;

	m_addDrawString.clear();
	//m_addDrawString.push_back("123");
	//m_addDrawString.push_back("456");
}

CDuChartCtrlShuxing::~CDuChartCtrlShuxing(void)
{
}

void CDuChartCtrlShuxing::DrawLegend(CDC * pDC)
{
	if (!m_bDrawLegend)
		return;

	// 字体
	m_chartFontTBKValue.SelectFont(pDC);

	// 图例
	ClipLegendArea(pDC);
	DrawLegendTrackerValue(pDC, &m_rectLegend);

	// 资源
	m_chartFontTBKValue.UnselectFont(pDC);
}

void CDuChartCtrlShuxing::DrawCursorValue(CDC * pDC)
{
	if (!m_bDrawCursorValue)
		return;
	if (m_nCursorType == CDuChartCtrlShuxing::typeCursorNone)
		return;

	// 字体
	m_chartFontTBKValue.SelectFont(pDC);

	// 光标值
	ClipCursorValueArea(pDC);
	DrawTrackerValue(pDC, &m_rectCursorValue);

	// 资源
	m_chartFontTBKValue.UnselectFont(pDC);
}

void CDuChartCtrlShuxing::ClipCursorValueArea(CDC * pDC)
{
	m_nTrackerValueRowCount = 0;
	m_nTrackerValueColumnCount = 0;
	memset(m_nTrackerValueColumnWidth, 0, sizeof(m_nTrackerValueColumnWidth));

	// 不显示光标值
	if (!m_bDrawCursorValue)
		return;

	// 无光标
	if (m_nCursorType == CDuChartCtrlShuxing::typeCursorNone)
		return;

	// 曲线个数
	int nLineCount = m_pParentCtrl->GetSeriesCount();
	if (nLineCount <= 0)
		return;

	// 光标个数
	int nCursorCount = m_pParentCtrl->GetCursorCountDu();
	if (nCursorCount <= 0)
		return;

	switch (m_nCursorType)
	{
	case CDuChartCtrlShuxing::typeCursorSingle:
	case CDuChartCtrlShuxing::typeCursorPeak:
	case CDuChartCtrlShuxing::typeCursorTrough:
		ClipCursorValueAreaOne(pDC);
		break;
	case CDuChartCtrlShuxing::typeCursorTwo:
		ClipCursorValueAreaTwo(pDC);
		break;
	case CDuChartCtrlShuxing::typeCursorXie:
		ClipCursorValueAreaXie(pDC);
		break;
	default: {ASSERT(FALSE);}
	}
}

void CDuChartCtrlShuxing::ClipLegendArea(CDC * pDC)
{
	m_nTrackerValueRowCount = 0;
	m_nTrackerValueColumnCount = 0;
	memset(m_nTrackerValueColumnWidth, 0, sizeof(m_nTrackerValueColumnWidth));

	// 曲线个数
	int nSerieCount = m_pParentCtrl->GetSeriesCount();
	if (nSerieCount <= 1)
		return;

	m_nTrackerValueColumnWidth[0] = 0;
	CSize szTextSize;
	for (int i=0; i<nSerieCount; i++)
	{
		CChartLineSerie * pChartLineSerieFor = (CChartLineSerie*)m_pParentCtrl->GetSerieFromIndexDu(i);
		m_strTrackerValue[0][i] = pChartLineSerieFor->GetName().c_str();
		m_colorTrackerValue[0][i] = pChartLineSerieFor->GetColor();

		szTextSize = pDC->GetTextExtent(m_strTrackerValue[0][i]);
		if (m_nTrackerValueColumnWidth[0] < szTextSize.cx)
			m_nTrackerValueColumnWidth[0] = szTextSize.cx;
	}
	m_nTrackerValueRowCount = nSerieCount;
	m_nTrackerValueColumnCount = 1;

	int nRectWidth = CHART_MARGIN + m_nTrackerValueColumnWidth[0] + CHART_MARGIN + CHART_LEGEND_BIANCHANG;
	int nRectHeight = szTextSize.cy * m_nTrackerValueRowCount;
    if (nRectHeight == 0)
        nRectHeight = (CHART_MARGIN + CHART_MARGIN + CHART_LEGEND_BIANCHANG) * m_nTrackerValueRowCount;

	// 光标值区域保护，不能离开屏幕
	CRect crectCursor = m_rectLegend.m_rect;
	crectCursor.right = crectCursor.left + nRectWidth;
	crectCursor.bottom = crectCursor.top + nRectHeight;
	ProtectTrackerRect(&m_rectLegend, &crectCursor);
}

void CDuChartCtrlShuxing::ClipCursorValueAreaOne(CDC * pDC)
{
	m_nTrackerValueRowCount = 0;
	m_nTrackerValueColumnCount = 0;
	memset(m_nTrackerValueColumnWidth, 0, sizeof(m_nTrackerValueColumnWidth));

	// 曲线个数
	int nSerieCount = m_pParentCtrl->GetSeriesCount();
	// 	活动曲线
	CChartLineSerie * pChartLineSerie = (CChartLineSerie*)m_pParentCtrl->GetActiveSerieDu();
	// 数据点数
	int nCurrentPointsCount = pChartLineSerie->GetPointsCount();
	if (nCurrentPointsCount <= 0)
		return;

	// 光标在数据当中的索引
	CChartDragLineCursorDu * pChartCursor1 = (CChartDragLineCursorDu*)m_pParentCtrl->GetCursorFromIndexDu(0);
	int nPositionIndexInData1 = pChartCursor1->m_lPositionIndexInData;

	// 横轴
	CChartAxisDu * pStdAxisH = (CChartAxisDu*)m_pParentCtrl->GetAxis(CChartCtrl::BottomAxis);
	// 纵轴
	CChartAxisDu * pStdAxisV = (CChartAxisDu*)m_pParentCtrl->GetAxis(CChartCtrl::LeftAxis);
	TCHAR tchFormatH[128] = {0};
	TCHAR tchFormatV[128] = {0};
	_stprintf_s(tchFormatH, TEXT("%%.%df"), pStdAxisH->m_nDigits);
	_stprintf_s(tchFormatV, TEXT("%%.%df"), pStdAxisV->m_nDigits);
	TCHAR tchValue[128] = {0};
	CString strFormatH = tchFormatH;
	CSize szTextSize;

	// 标题
	switch (m_nCursorType)
	{
	case typeCursorSingle:
		_stprintf_s(tchValue, TEXT("单光标"));
		break;
	case typeCursorPeak:
		_stprintf_s(tchValue, TEXT("峰光标"));
		break;
	case typeCursorTrough:
		_stprintf_s(tchValue, TEXT("谷光标"));
		break;
	default: {ASSERT(FALSE);}
	}
	m_strTrackerValue[0][0] = tchValue;
	m_colorTrackerValue[0][0] = 0;
	szTextSize = pDC->GetTextExtent(tchValue);
	if (m_nTrackerValueColumnWidth[0] < szTextSize.cx)
		m_nTrackerValueColumnWidth[0] = szTextSize.cx;

	// 横轴值
	double dbXValue1 = pChartLineSerie->GetXPointValue(nPositionIndexInData1);
	_stprintf_s(tchValue, TEXT("X: ") + strFormatH, dbXValue1);
	if (m_nSerieType == CDuChartCtrlShuxing::typeSerieBeipc)
	{
		CChartBarAxisDu * pAxis = (CChartBarAxisDu*)m_pParentCtrl->GetBottomAxis();
		double dMin = 0, dMax = 0;
		pAxis->GetMinMax(dMin, dMax);
		_stprintf_s(tchValue, TEXT("X: %s"), pAxis->GetTickLabel(nPositionIndexInData1 + dMin + 0.5).c_str());
	}
	m_strTrackerValue[0][1] = tchValue;
	m_colorTrackerValue[0][1] = 0;
	szTextSize = pDC->GetTextExtent(tchValue);
	if (m_nTrackerValueColumnWidth[0] < szTextSize.cx)
		m_nTrackerValueColumnWidth[0] = szTextSize.cx;

	// 纵轴值
	for (int i=0; i<nSerieCount; i++)
	{
		CChartLineSerie * pChartLineSerieFor = (CChartLineSerie*)m_pParentCtrl->GetSerieFromIndexDu(i);
		double d = pChartLineSerieFor->GetYPointValue(nPositionIndexInData1);
		_stprintf_s(tchValue, TEXT("Y%02d: ") + strFormatH, i + 1, d);
		m_strTrackerValue[0][2+i] = tchValue;
		m_colorTrackerValue[0][2+i] = pChartLineSerieFor->GetColor();
		szTextSize = pDC->GetTextExtent(tchValue);
		if (m_nTrackerValueColumnWidth[0] < szTextSize.cx)
			m_nTrackerValueColumnWidth[0] = szTextSize.cx;
	}

	m_nTrackerValueRowCount = 2 + nSerieCount;
	m_nTrackerValueColumnCount = 1;

	int nRectWidth = (CHART_MARGIN + m_nTrackerValueColumnWidth[0] + CHART_MARGIN) * 2;
	int nRectHeight = szTextSize.cy * m_nTrackerValueRowCount;

	// add
	for (int i=0; i < m_addDrawString.size(); i++)
	{
		m_strTrackerValue[0][m_nTrackerValueRowCount + i] = m_addDrawString[i];
	}
	nRectHeight += szTextSize.cy * m_addDrawString.size();
	m_nTrackerValueRowCount += m_addDrawString.size();
	
	// 光标值区域保护，不能离开屏幕
	CRect crectCursor = m_rectCursorValue.m_rect;
	crectCursor.right = crectCursor.left + nRectWidth;
	crectCursor.bottom = crectCursor.top + nRectHeight;
	ProtectTrackerRect(&m_rectCursorValue, &crectCursor);
}

void CDuChartCtrlShuxing::ClipCursorValueAreaXie(CDC * pDC)
{
	m_nTrackerValueRowCount = 0;
	m_nTrackerValueColumnCount = 0;
	memset(m_nTrackerValueColumnWidth, 0, sizeof(m_nTrackerValueColumnWidth));

	// 曲线个数
	int nSerieCount = m_pParentCtrl->GetSeriesCount();
	// 	活动曲线
	CChartLineSerie * pChartLineSerie = (CChartLineSerie*)m_pParentCtrl->GetActiveSerieDu();
	// 数据点数
	int nCurrentPointsCount = pChartLineSerie->GetPointsCount();
	if (nCurrentPointsCount <= 0)
		return;

	// 光标在数据当中的索引
	CChartDragLineCursorDu * pChartCursor1 = (CChartDragLineCursorDu*)m_pParentCtrl->GetCursorFromIndexDu(0);
	int nPositionIndexInData1 = pChartCursor1->m_lPositionIndexInData;

	// 横轴
	CChartAxisDu * pStdAxisH = (CChartAxisDu*)m_pParentCtrl->GetAxis(CChartCtrl::BottomAxis);
	// 纵轴
	CChartAxisDu * pStdAxisV = (CChartAxisDu*)m_pParentCtrl->GetAxis(CChartCtrl::LeftAxis);
	TCHAR tchFormatH[128] = {0};
	TCHAR tchFormatV[128] = {0};
	_stprintf_s(tchFormatH, TEXT("%%.%df"), pStdAxisH->m_nDigits);
	_stprintf_s(tchFormatV, TEXT("%%.%df"), pStdAxisV->m_nDigits);
	TCHAR tchValue[128] = {0};
	CString strFormatH = tchFormatH;
	CSize szTextSize;

	// 标题
	_stprintf_s(tchValue, TEXT("谐光标"));
	m_strTrackerValue[0][0] = tchValue;
	m_colorTrackerValue[0][0] = 0;
	szTextSize = pDC->GetTextExtent(tchValue);
	if (m_nTrackerValueColumnWidth[0] < szTextSize.cx)
		m_nTrackerValueColumnWidth[0] = szTextSize.cx;

	int nValidXieCount = 0;
	for (int i=0; i<m_nXieMaxCount; i++)
	{
		int nnPositionIndexInData1For = (i + 1) * nPositionIndexInData1;
		if (nnPositionIndexInData1For > nCurrentPointsCount - 1)
			break;

		// 横轴值
		double dbXValue1 = pChartLineSerie->GetXPointValue(nnPositionIndexInData1For);
		_stprintf_s(tchValue, TEXT("X%02d: ") + strFormatH, i+1, dbXValue1);
		m_strTrackerValue[0][1+i] = tchValue;
		m_colorTrackerValue[0][1+i] = 0;
		szTextSize = pDC->GetTextExtent(tchValue);
		if (m_nTrackerValueColumnWidth[0] < szTextSize.cx)
			m_nTrackerValueColumnWidth[0] = szTextSize.cx;

		// 纵轴值
		double d = pChartLineSerie->GetYPointValue(nnPositionIndexInData1For);
		_stprintf_s(tchValue, TEXT("Y%02d: ") + strFormatH, i + 1, d);
		m_strTrackerValue[1][1+i] = tchValue;
		m_colorTrackerValue[1][1+i] = pChartLineSerie->GetColor();
		szTextSize = pDC->GetTextExtent(tchValue);
		if (m_nTrackerValueColumnWidth[0] < szTextSize.cx)
			m_nTrackerValueColumnWidth[0] = szTextSize.cx;

		nValidXieCount++;
	}

	m_nTrackerValueRowCount = 1 + nValidXieCount;
	m_nTrackerValueColumnCount = 2;

	int nRectWidth = CHART_MARGIN + m_nTrackerValueColumnWidth[0] + CHART_MARGIN + 
		CHART_MARGIN + m_nTrackerValueColumnWidth[0] + CHART_MARGIN;
	int nRectHeight = szTextSize.cy * m_nTrackerValueRowCount;

	// 光标值区域保护，不能离开屏幕
	CRect crectCursor = m_rectCursorValue.m_rect;
	crectCursor.right = crectCursor.left + nRectWidth;
	crectCursor.bottom = crectCursor.top + nRectHeight;
	ProtectTrackerRect(&m_rectCursorValue, &crectCursor);
}

void CDuChartCtrlShuxing::ClipCursorValueAreaTwo(CDC * pDC)
{
	m_nTrackerValueRowCount = 0;
	m_nTrackerValueColumnCount = 0;
	memset(m_nTrackerValueColumnWidth, 0, sizeof(m_nTrackerValueColumnWidth));

	// 曲线个数
	int nSerieCount = m_pParentCtrl->GetSeriesCount();
	// 	活动曲线
	CChartLineSerie * pChartLineSerie = (CChartLineSerie*)m_pParentCtrl->GetActiveSerieDu();
	// 数据点数
	int nCurrentPointsCount = pChartLineSerie->GetPointsCount();
	if (nCurrentPointsCount <= 0)
		return;

	// 光标在数据当中的索引
	CChartDragLineCursorDu * pChartCursor1 = (CChartDragLineCursorDu*)m_pParentCtrl->GetCursorFromIndexDu(0);
	int nPositionIndexInData1 = pChartCursor1->m_lPositionIndexInData;
	CChartDragLineCursorDu * pChartCursor2 = (CChartDragLineCursorDu*)m_pParentCtrl->GetCursorFromIndexDu(1);
	int nPositionIndexInData2 = pChartCursor2->m_lPositionIndexInData;

	// 横轴
	CChartStandardAxis * pStdAxisH = (CChartStandardAxis*)m_pParentCtrl->GetAxis(CChartCtrl::BottomAxis);
	// 纵轴
	CChartStandardAxis * pStdAxisV = (CChartStandardAxis*)m_pParentCtrl->GetAxis(CChartCtrl::LeftAxis);
	TCHAR tchFormatH[128] = {0};
	TCHAR tchFormatV[128] = {0};
	_stprintf_s(tchFormatH, TEXT("%%.%df"), pStdAxisH->m_nDigits);
	_stprintf_s(tchFormatV, TEXT("%%.%df"), pStdAxisV->m_nDigits);
	TCHAR tchValue[128] = {0};
	CString strFormatH = tchFormatH;
	CSize szTextSize;

	//////////////////////////////////////////////////////////////////////////
	// 第一列
	// 标题
	_stprintf_s(tchValue, TEXT("双光标"));
	m_strTrackerValue[0][0] = tchValue;
	m_colorTrackerValue[0][0] = 0;
	szTextSize = pDC->GetTextExtent(tchValue);
	if (m_nTrackerValueColumnWidth[0] < szTextSize.cx)
		m_nTrackerValueColumnWidth[0] = szTextSize.cx;

	// 横轴值
	double dbXValue1 = pChartLineSerie->GetXPointValue(nPositionIndexInData1);
	_stprintf_s(tchValue, TEXT("X1: ") + strFormatH, dbXValue1);
	m_strTrackerValue[0][1] = tchValue;
	m_colorTrackerValue[0][1] = 0;
	szTextSize = pDC->GetTextExtent(tchValue);
	if (m_nTrackerValueColumnWidth[0] < szTextSize.cx)
		m_nTrackerValueColumnWidth[0] = szTextSize.cx;

	// 纵轴值
	for (int i=0; i<nSerieCount; i++)
	{
		CChartLineSerie * pChartLineSerieFor = (CChartLineSerie*)m_pParentCtrl->GetSerieFromIndexDu(i);
		double d = pChartLineSerieFor->GetYPointValue(nPositionIndexInData1);
		_stprintf_s(tchValue, TEXT("Y%02d: ") + strFormatH, i + 1, d);
		m_strTrackerValue[0][2+i] = tchValue;
		m_colorTrackerValue[0][2+i] = pChartLineSerieFor->GetColor();
		szTextSize = pDC->GetTextExtent(tchValue);
		if (m_nTrackerValueColumnWidth[0] < szTextSize.cx)
			m_nTrackerValueColumnWidth[0] = szTextSize.cx;
	}

	//////////////////////////////////////////////////////////////////////////
	// 第二列
	// 标题
	_stprintf_s(tchValue, TEXT(""));
	m_strTrackerValue[1][0] = tchValue;
	m_colorTrackerValue[1][0] = 0;
	szTextSize = pDC->GetTextExtent(tchValue);
	if (m_nTrackerValueColumnWidth[1] < szTextSize.cx)
		m_nTrackerValueColumnWidth[1] = szTextSize.cx;

	// 横轴值
	double dbXValue2 = pChartLineSerie->GetXPointValue(nPositionIndexInData2);
	_stprintf_s(tchValue, TEXT("X2: ") + strFormatH, dbXValue2);
	m_strTrackerValue[1][1] = tchValue;
	m_colorTrackerValue[1][1] = 0;
	szTextSize = pDC->GetTextExtent(tchValue);
	if (m_nTrackerValueColumnWidth[1] < szTextSize.cx)
		m_nTrackerValueColumnWidth[1] = szTextSize.cx;

	// 纵轴值
	for (int i=0; i<nSerieCount; i++)
	{
		CChartLineSerie * pChartLineSerieFor = (CChartLineSerie*)m_pParentCtrl->GetSerieFromIndexDu(i);
		double d = pChartLineSerieFor->GetYPointValue(nPositionIndexInData2);
		_stprintf_s(tchValue, TEXT("Y%02d: ") + strFormatH, i + 1, d);
		m_strTrackerValue[1][2+i] = tchValue;
		m_colorTrackerValue[1][2+i] = pChartLineSerieFor->GetColor();
		szTextSize = pDC->GetTextExtent(tchValue);
		if (m_nTrackerValueColumnWidth[1] < szTextSize.cx)
			m_nTrackerValueColumnWidth[1] = szTextSize.cx;
	}

	//////////////////////////////////////////////////////////////////////////
	// 第三列
	// 标题
	_stprintf_s(tchValue, TEXT(""));
	m_strTrackerValue[2][0] = tchValue;
	m_colorTrackerValue[2][0] = 0;
	szTextSize = pDC->GetTextExtent(tchValue);
	if (m_nTrackerValueColumnWidth[2] < szTextSize.cx)
		m_nTrackerValueColumnWidth[2] = szTextSize.cx;

	// 横轴值
	_stprintf_s(tchValue, TEXT("ΔX: ") + strFormatH, dbXValue2 - dbXValue1);
	m_strTrackerValue[2][1] = tchValue;
	m_colorTrackerValue[2][1] = 0;
	szTextSize = pDC->GetTextExtent(tchValue);
	if (m_nTrackerValueColumnWidth[2] < szTextSize.cx)
		m_nTrackerValueColumnWidth[2] = szTextSize.cx;

	// 纵轴值
	for (int i=0; i<nSerieCount; i++)
	{
		CChartLineSerie * pChartLineSerieFor = (CChartLineSerie*)m_pParentCtrl->GetSerieFromIndexDu(i);
		double d1 = pChartLineSerieFor->GetYPointValue(nPositionIndexInData1);
		double d2 = pChartLineSerieFor->GetYPointValue(nPositionIndexInData2);
		_stprintf_s(tchValue, TEXT("ΔY%02d: ") + strFormatH, i + 1, d2 - d1);
		m_strTrackerValue[2][2+i] = tchValue;
		m_colorTrackerValue[2][2+i] = pChartLineSerieFor->GetColor();
		szTextSize = pDC->GetTextExtent(tchValue);
		if (m_nTrackerValueColumnWidth[2] < szTextSize.cx)
			m_nTrackerValueColumnWidth[2] = szTextSize.cx;
	}

	// 行数
	m_nTrackerValueRowCount = nSerieCount + 2;
	// 列数
	m_nTrackerValueColumnCount = 3;
	int nRectWidth = 0;
	for (int i=0; i<m_nTrackerValueColumnCount; i++)
		nRectWidth += CHART_MARGIN + m_nTrackerValueColumnWidth[i] + CHART_MARGIN;
	int nRectHeight = szTextSize.cy * m_nTrackerValueRowCount;

	// 光标值区域保护，不能离开屏幕
	CRect crectCursor = m_rectCursorValue.m_rect;
	crectCursor.right = crectCursor.left + nRectWidth;
	crectCursor.bottom = crectCursor.top + nRectHeight;
	ProtectTrackerRect(&m_rectCursorValue, &crectCursor);
}

void CDuChartCtrlShuxing::ProtectTrackerRect(CRectTracker * pTrackerRect, CRect * pRect)
{
	CRect rect;
	m_pParentCtrl->GetClientRect(&rect);

	int nWidth = pRect->Width();
	int nHeight = pRect->Height();
	if (pRect->left < 1) pRect->left = 1;
	if (pRect->right >= rect.right) pRect->left = rect.right - nWidth - 1;
	if (pRect->top < 1) pRect->top = 1;
	if (pRect->bottom >= rect.bottom) pRect->top = rect.bottom - nHeight - 1;
	pRect->right = pRect->left + nWidth;
	pRect->bottom = pRect->top + nHeight;
	pTrackerRect->m_rect = *pRect;
}

void CDuChartCtrlShuxing::DrawLegendTrackerValue(CDC* pDC, CRectTracker * pTracker)
{
	// 没有内容
	if (m_nTrackerValueRowCount <= 0 || m_nTrackerValueColumnCount <= 0)
		return;

	DrawTrackerValue(pDC, pTracker);

	// 区域
	CRect crectTracker = pTracker->m_rect;

	int nRowPixSize = crectTracker.Height() / m_nTrackerValueRowCount;

	int nBianchang = 3 * CHART_LEGEND_BIANCHANG / 4;
	for (int i=0; i<m_nTrackerValueRowCount; i++)
	{
		CPen pen(PS_SOLID, 1, m_colorTrackerValue[0][i]);
		CPen * pOldPen = pDC->SelectObject(&pen);

		int nLeft = crectTracker.right - 1 - CHART_LEGEND_BIANCHANG / 2 - nBianchang / 2;
		int nRight = crectTracker.right - 1 - CHART_LEGEND_BIANCHANG / 2 + nBianchang / 2;
		int nTop = crectTracker.top + nRowPixSize * i + nRowPixSize / 2 - nBianchang / 2;
		int nBottom = crectTracker.top + nRowPixSize * i + nRowPixSize / 2 + nBianchang / 2;
		CRect crect1(nLeft, nTop, nRight, nBottom);
		pDC->Rectangle(crect1);

		if (m_pParentCtrl->GetActiveSerieDu() == m_pParentCtrl->GetSerieFromIndexDu(i))
		{
			CRect crect2 = crect1;
			crect2.DeflateRect(2, 2);
			pDC->FillSolidRect(crect2, m_colorTrackerValue[0][i]);
		}

		pDC->SelectObject(pOldPen);
		pen.DeleteObject();
	}
}

void CDuChartCtrlShuxing::DrawTrackerValue(CDC* pDC, CRectTracker * pTracker)
{
	// 没有内容
	if (m_nTrackerValueRowCount <= 0 || m_nTrackerValueColumnCount <= 0)
		return;

	// 区域
	CRect crectTracker = pTracker->m_rect;

	// 画刷
	CBrush NewBrush(m_colTBKColor);
	CBrush * pOldBrush = pDC->SelectObject(&NewBrush);

	// 背景模式
	int nOldBkMode = pDC->SetBkMode(TRANSPARENT);

	// 字体颜色
	int nTextColor = pDC->GetTextColor();

	// 画背景
	pDC->Rectangle(crectTracker);

	int nRowPixSize = crectTracker.Height() / m_nTrackerValueRowCount;

	for (int i=0; i<m_nTrackerValueColumnCount; i++)
	{
		for (int j=0; j<m_nTrackerValueRowCount; j++)
		{
			pDC->SetTextColor(m_colorTrackerValue[i][j]);
			int nTextoutX = crectTracker.left;
			for (int k=0; k<i; k++)
				nTextoutX += CHART_MARGIN + m_nTrackerValueColumnWidth[k] + CHART_MARGIN;
			pDC->TextOut(nTextoutX + CHART_MARGIN, crectTracker.top + nRowPixSize * j, m_strTrackerValue[i][j]);
		}
	}

	pDC->SetBkMode(nOldBkMode);
	pDC->SelectObject(pOldBrush);
	NewBrush.DeleteObject();

	pTracker->Draw(pDC);
}

void CDuChartCtrlShuxing::DrawStatValue(CDC * pDC)
{
	if (!m_bDrawStatValue)
		return;

	// 字体
	m_chartFontTBKValue.SelectFont(pDC);

	// 图例
	ClipStatValueArea(pDC);
	DrawTrackerValue(pDC, &m_rectStatValue);

	// 资源
	m_chartFontTBKValue.UnselectFont(pDC);
}

void CDuChartCtrlShuxing::ClipStatValueArea(CDC * pDC)
{
	m_nTrackerValueRowCount = 0;
	m_nTrackerValueColumnCount = 0;
	memset(m_nTrackerValueColumnWidth, 0, sizeof(m_nTrackerValueColumnWidth));

	m_nTrackerValueColumnWidth[0] = 0;

	// 	活动曲线
	CChartLineSerieDu * pChartLineSerie = (CChartLineSerieDu*)m_pParentCtrl->GetActiveSerieDu();
	if (pChartLineSerie == NULL)
		return;

	// 数据点数
	int nCurrentPointsCount = pChartLineSerie->GetPointsCount();
	if (nCurrentPointsCount <= 0)
		return;

	// 没有显示任何一个统计值
	if (!m_bDrawStatMax && !m_bDrawStatMin && !m_bDrawStatAve && 
		!m_bDrawStatPeak && !m_bDrawStatStd && !m_bDrawStatRms)
		return;

	// 纵轴
	CChartAxis * pAxis = m_pParentCtrl->GetAxis(CChartCtrl::LeftAxis);
// 	if (pAxis->m_nAxisType != CChartAxis::AXIS_CCHARTSTANDARDDU)
// 		return;

	CChartStandardAxisDu * pStdAxisV = (CChartStandardAxisDu*)pAxis;
	TCHAR tchFormatV[128] = {0};
	_stprintf_s(tchFormatV, TEXT("%%.%df"), pStdAxisV->m_nDigits);

	// 标题
	CString strSerieName = pChartLineSerie->GetName().c_str();
	TCHAR tchValue[128] = {0};
	if (strSerieName.IsEmpty())
		_stprintf_s(tchValue, TEXT("统计值"));
	else
		_stprintf_s(tchValue, TEXT("[%s]统计值"), strSerieName);
	m_strTrackerValue[0][0] = tchValue;
	m_colorTrackerValue[0][0] = 0;
	CSize szTextSize = pDC->GetTextExtent(tchValue);
	if (m_nTrackerValueColumnWidth[0] < szTextSize.cx)
		m_nTrackerValueColumnWidth[0] = szTextSize.cx;
	m_nTrackerValueRowCount++;

	BOOL b[] = {m_bDrawStatMax, m_bDrawStatMin, m_bDrawStatAve, 
		m_bDrawStatPeak, m_bDrawStatStd, m_bDrawStatRms,m_bDrawStatSum};
	double d[] = {pChartLineSerie->m_dStatMaxValue, 
		pChartLineSerie->m_dStatMinValue, 
		pChartLineSerie->m_dStatAveValue, 
		pChartLineSerie->m_dStatPeakValue, 
		pChartLineSerie->m_dStatStdValue, 
		pChartLineSerie->m_dStatRmsValue,
		pChartLineSerie->m_dStatSumValue,
	};
	LPCTSTR lpsz[] = {"最大值:%%.%df", "最小值:%%.%df", 
		"平均值:%%.%df", "峰峰值:%%.%df", 
		"方差:%%.%df", "有效值:%%.%df", "总值:%%.%df" };
	for (int i=0; i<sizeof(b)/sizeof(BOOL); i++)
	{
		_stprintf_s(tchFormatV, lpsz[i], pStdAxisV->m_nDigits);
		_stprintf_s(tchValue, tchFormatV, d[i]);
		m_strTrackerValue[0][m_nTrackerValueRowCount] = tchValue;
		m_colorTrackerValue[0][m_nTrackerValueRowCount] = pChartLineSerie->GetColor();
		m_nTrackerValueRowCount++;

		szTextSize = pDC->GetTextExtent(tchValue);
		if (m_nTrackerValueColumnWidth[0] < szTextSize.cx)
			m_nTrackerValueColumnWidth[0] = szTextSize.cx;
	}
	m_nTrackerValueColumnCount = 1;

	int nRectWidth = CHART_MARGIN + m_nTrackerValueColumnWidth[0] + CHART_MARGIN;
	int nRectHeight = szTextSize.cy * m_nTrackerValueRowCount;

	// 光标值区域保护，不能离开屏幕
	CRect crectStat = m_rectStatValue.m_rect;
	crectStat.right = crectStat.left + nRectWidth;
	crectStat.bottom = crectStat.top + nRectHeight;
	ProtectTrackerRect(&m_rectStatValue, &crectStat);
}