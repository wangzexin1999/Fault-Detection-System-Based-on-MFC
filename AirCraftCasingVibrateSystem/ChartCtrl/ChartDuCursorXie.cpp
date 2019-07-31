
#include "stdafx.h"
#include "ChartDuCursorXie.h"
#include "ChartCtrl.h"
#include "ChartXYSerie.h"
#include "ChartLineSerie.h"
#include "DuChartCtrl.h"

CChartDuCursorXie::CChartDuCursorXie(CChartCtrl* pParent,
										   CChartAxis* pRelatedAxis,  
										   CChartAxis* pRelatedYAxis)
 : CChartDragLineCursorDu(pParent, pRelatedAxis, pRelatedYAxis)
{

}

CChartDuCursorXie::~CChartDuCursorXie()
{
}

void CChartDuCursorXie::Draw(CDC* pDC)
{
	__super::Draw(pDC);

	// 曲线个数
	int nSerieCount = m_pParentCtrl->GetSeriesCount();
	if (nSerieCount <= 0)
		return;

	// 数据点数
	CChartSerieBase<SChartXYPoint> * pActiveSeries = (CChartSerieBase<SChartXYPoint>*)m_pParentCtrl->GetActiveSerieDu();
	int nPointCount = pActiveSeries->GetPointsCount();
	if (nPointCount <= 0)
		return;

	// 画笔
	CPen NewPen(m_nPenStyle, m_nWidth, m_colCursor);
	CPen* pOldPen = pDC->SelectObject(&NewPen);

	CDuChartCtrl * pDuChartCtrl = (CDuChartCtrl*)m_pParentCtrl;

	for (int i=0; i<pDuChartCtrl->m_shuxing.m_nXieMaxCount; i++)
	{
		int nPositionIndexInData = (i + 1) * m_lPositionIndexInData;
		if (nPositionIndexInData > nPointCount - 1)
			break;

		// 光标所在活动曲线的值
		const SChartXYPoint & xyPoint = pActiveSeries->GetPoint(nPositionIndexInData);

		// 根据索引得到像素
		m_lPosition = GetXScreenPixelFromSerieIndexAndXPosition(0, nPositionIndexInData);

		// 画焦点
		int nMargin = 4;
		int nYPosition = GetYScreenPixelFromSerieIndexAndXPosition(0, nPositionIndexInData);
		CRect crectFocus;
		crectFocus.left = m_lPosition - nMargin;
		crectFocus.top = nYPosition - nMargin;
		crectFocus.right = m_lPosition + nMargin + 1;
		crectFocus.bottom = nYPosition + nMargin + 1;
		pDC->Rectangle(crectFocus);

		// 内部焦点
		CRect crectFocusActive = crectFocus;
		crectFocusActive.DeflateRect(2, 2);
		pDC->FillSolidRect(crectFocusActive, m_colCursor);
	}

	pDC->SelectObject(pOldPen);
	NewPen.DeleteObject();
}