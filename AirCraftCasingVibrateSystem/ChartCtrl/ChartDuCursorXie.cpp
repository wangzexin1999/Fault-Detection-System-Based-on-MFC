
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

	// ���߸���
	int nSerieCount = m_pParentCtrl->GetSeriesCount();
	if (nSerieCount <= 0)
		return;

	// ���ݵ���
	CChartSerieBase<SChartXYPoint> * pActiveSeries = (CChartSerieBase<SChartXYPoint>*)m_pParentCtrl->GetActiveSerieDu();
	int nPointCount = pActiveSeries->GetPointsCount();
	if (nPointCount <= 0)
		return;

	// ����
	CPen NewPen(m_nPenStyle, m_nWidth, m_colCursor);
	CPen* pOldPen = pDC->SelectObject(&NewPen);

	CDuChartCtrl * pDuChartCtrl = (CDuChartCtrl*)m_pParentCtrl;

	for (int i=0; i<pDuChartCtrl->m_shuxing.m_nXieMaxCount; i++)
	{
		int nPositionIndexInData = (i + 1) * m_lPositionIndexInData;
		if (nPositionIndexInData > nPointCount - 1)
			break;

		// ������ڻ���ߵ�ֵ
		const SChartXYPoint & xyPoint = pActiveSeries->GetPoint(nPositionIndexInData);

		// ���������õ�����
		m_lPosition = GetXScreenPixelFromSerieIndexAndXPosition(0, nPositionIndexInData);

		// ������
		int nMargin = 4;
		int nYPosition = GetYScreenPixelFromSerieIndexAndXPosition(0, nPositionIndexInData);
		CRect crectFocus;
		crectFocus.left = m_lPosition - nMargin;
		crectFocus.top = nYPosition - nMargin;
		crectFocus.right = m_lPosition + nMargin + 1;
		crectFocus.bottom = nYPosition + nMargin + 1;
		pDC->Rectangle(crectFocus);

		// �ڲ�����
		CRect crectFocusActive = crectFocus;
		crectFocusActive.DeflateRect(2, 2);
		pDC->FillSolidRect(crectFocusActive, m_colCursor);
	}

	pDC->SelectObject(pOldPen);
	NewPen.DeleteObject();
}