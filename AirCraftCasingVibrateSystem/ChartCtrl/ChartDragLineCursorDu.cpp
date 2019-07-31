
#include "stdafx.h"
#include "ChartDragLineCursorDu.h"
#include "ChartCtrl.h"
#include "ChartXYSerie.h"
#include "ChartLineSerie.h"

CChartDragLineCursorDu::CChartDragLineCursorDu(CChartCtrl* pParent,
										   CChartAxis* pRelatedAxis,  
										   CChartAxis* pRelatedYAxis)
 : CChartDragLineCursor(pParent, pRelatedAxis)
{
	m_pRelatedYAxis = pRelatedYAxis;

	m_lPositionIndexInData = 0;

	m_nPenStyle = PS_SOLID;
	m_nWidth = 1;
}

CChartDragLineCursorDu::~CChartDragLineCursorDu()
{
}

void CChartDragLineCursorDu::Draw(CDC* pDC)
{
	CDuChartCtrl * pDuChartCtrl = (CDuChartCtrl*)m_pParentCtrl;

	// ���߸���
	int nSerieCount = m_pParentCtrl->GetSeriesCount();
	if (nSerieCount <= 0)
	{
		return;
	}

	// ���ݵ���
	CChartSerieBase<SChartXYPoint> * pActiveSeries = (CChartSerieBase<SChartXYPoint>*)m_pParentCtrl->GetActiveSerieDu();
	ASSERT(pActiveSeries != NULL);
	int nPointCount = pActiveSeries->GetPointsCount();
	if (nPointCount <= 0)
		return;

	// �������λ��
	ProtectCursorPositionIndexInData();

	// ������ڻ���ߵ�ֵ
	const SChartXYPoint & xyPoint = pActiveSeries->GetPoint(m_lPositionIndexInData);

	// ����
	CPen NewPen(m_nPenStyle, m_nWidth, m_colCursor);
	CPen* pOldPen = pDC->SelectObject(&NewPen);

	// ͼ�θ���
	int nPlottingGraphCount = m_pParentCtrl->GetPlottingGraphCount();

	for (int i=0; i<nPlottingGraphCount; i++)
	{
 		// ͼ������
 		CRect plottingRect = m_pParentCtrl->GetPlottingRectFromSerieIndexDu(i);

 		// ���������õ�����
 		m_lPosition = GetXScreenPixelFromSerieIndexAndXPosition(i, m_lPositionIndexInData);
 
 		// �����
 		pDC->MoveTo(m_lPosition, plottingRect.top);
 		pDC->LineTo(m_lPosition, plottingRect.bottom);

		// ������
		int nMargin = 4;
		int nYPosition = GetYScreenPixelFromSerieIndexAndXPosition(i, m_lPositionIndexInData);
		CRect crectFocus;
		crectFocus.left = m_lPosition - nMargin;
		crectFocus.top = nYPosition - nMargin;
		crectFocus.right = m_lPosition + nMargin + 1;
		crectFocus.bottom = nYPosition + nMargin + 1;
		pDC->Rectangle(crectFocus);

		// ��
		CRect crectFocusTop = crectFocus;
		crectFocusTop.top = plottingRect.top - nMargin;
		crectFocusTop.bottom = plottingRect.top + nMargin + 1;
		pDC->Rectangle(crectFocusTop);

		// ��
		CRect crectFocusBot = crectFocus;
		crectFocusBot.top = plottingRect.bottom - nMargin;
		crectFocusBot.bottom = plottingRect.bottom + nMargin + 1;
		pDC->Rectangle(crectFocusBot);

		// ����
		if (m_pParentCtrl->GetActiveCursorDu() == this)
		{
			CRect crectFocusActive = crectFocus;
			crectFocusActive.DeflateRect(2, 2);
			pDC->FillSolidRect(crectFocusActive, m_colCursor);

			crectFocusTop.DeflateRect(2, 2);
			pDC->FillSolidRect(crectFocusTop, m_colCursor);
			crectFocusBot.DeflateRect(2, 2);
			pDC->FillSolidRect(crectFocusBot, m_colCursor);
		}
	}

	pDC->SelectObject(pOldPen);
	NewPen.DeleteObject();
}

void CChartDragLineCursorDu::OnMouseMove(CPoint mousePoint)
{
	if (m_bDragged)
	{
		int nPlottingGraphIndex = m_pParentCtrl->GetPlottingGraphIndexFromPoint(mousePoint);
		if (nPlottingGraphIndex < 0)
			return;

		m_lPositionIndexInData = GetXPositionFromSerieIndexAndXScreenPixel(nPlottingGraphIndex, mousePoint.x);
		ProtectCursorPositionIndexInData();
	}
}

void CChartDragLineCursorDu::OnMouseButtonDown(CPoint mousePoint)
{
	if (m_pParentCtrl->GetZoomEnabled())
		return;

	int nPlottingGraphIndex = m_pParentCtrl->GetPlottingGraphIndexFromPoint(mousePoint);
	if (nPlottingGraphIndex < 0)
		return;

	m_lPositionIndexInData = GetXPositionFromSerieIndexAndXScreenPixel(nPlottingGraphIndex, mousePoint.x);
	m_bDragged = true;
}

void CChartDragLineCursorDu::OnMouseButtonUp(CPoint mousePoint)
{
	m_bDragged = false;
}

int CChartDragLineCursorDu::GetXScreenPixelFromSerieIndexAndXPosition(int nSerieIndex, int nIndex)
{
	// ���߸���
	int nSerieCount = m_pParentCtrl->GetSeriesCount();
	if (nSerieCount < 0)
		return 0;

	// ���ݵ���
	CChartSerieBase<SChartXYPoint> * pActiveSeries = (CChartSerieBase<SChartXYPoint>*)m_pParentCtrl->GetActiveSerieDu();
	int nPointCount = pActiveSeries->GetPointsCount();
	if (nPointCount < 0)
		return 0;

	// ���������õ�ֵ
	const SChartXYPoint & xyPoint = pActiveSeries->GetPoint(nIndex);

	// ��Ӧ�ĺ���
	CChartAxis * pMapAxis = m_pParentCtrl->GetAxisDu(CChartCtrl::BottomAxis, nSerieIndex);

	// ����ֵ�õ�����
	int nPosition = pMapAxis->ValueToScreen(xyPoint.X);
	return nPosition;
}

int CChartDragLineCursorDu::GetXPositionFromSerieIndexAndXScreenPixel(int nSerieIndex, int nXScreenPixel)
{
	// ���߸���
	int nSerieCount = m_pParentCtrl->GetSeriesCount();
	if (nSerieCount < 0)
		return 0;

	// ���ݵ���
	CChartLineSerie * pActiveSeries = (CChartLineSerie*)m_pParentCtrl->GetActiveSerieDu();
	if (pActiveSeries == NULL)
		return 0;
	int nPointCount = pActiveSeries->GetPointsCount();
	if (nPointCount < 0)
		return 0;

	// ��Ӧ��������
	CChartAxis * pMapAxis = m_pParentCtrl->GetAxisDu(CChartCtrl::BottomAxis, nSerieIndex);

	// ���ض�Ӧ��Xֵ
	double dValue = pMapAxis->ScreenToValue(nXScreenPixel);

	// �����������ֵ����Сֵ
	double Minimum = 0, Maximum = 0;
	pActiveSeries->GetSerieXMinMax(Minimum, Maximum);

	// ����������������
	unsigned uFirst = 0, uLast = pActiveSeries->GetPointsCount() - 1;
	// pActiveSeries->GetVisiblePoints(uFirst, uLast);

	int nIndex = static_cast<int>(0.5f + uFirst + 1.f * (uLast - uFirst) * (dValue - Minimum) / (Maximum - Minimum));

	return nIndex;
}

int CChartDragLineCursorDu::GetYScreenPixelFromSerieIndexAndXPosition(int nSerieIndex, int nPositionIndexInData)
{
	// ���߸���
	int nSerieCount = m_pParentCtrl->GetSeriesCount();
	if (nSerieCount < 0)
		return 0;

	// ���ݵ���
	CChartSerieBase<SChartXYPoint> * pMapSerie = (CChartSerieBase<SChartXYPoint> *)m_pParentCtrl->GetSerieFromIndexDu(nSerieIndex);
	int nPointCount = pMapSerie->GetPointsCount();
	if (nPointCount < 0)
		return 0;

	// ��Ӧ��������
	CChartAxis * pMapAxis = m_pParentCtrl->GetAxisDu(CChartCtrl::LeftAxis, nSerieIndex);

	// ���������õ�ֵ
	const SChartXYPoint & xyPoint = pMapSerie->GetPoint(nPositionIndexInData);
	// ����ֵ�õ�����
	int nPosition = pMapAxis->ValueToScreen(xyPoint.Y);
	return nPosition;
}

void CChartDragLineCursorDu::ProtectCursorPositionIndexInData()
{
	// ���ݵ���
	CChartSerieBase<SChartXYPoint> * pActiveSeries = (CChartSerieBase<SChartXYPoint>*)m_pParentCtrl->GetActiveSerieDu();
	if (pActiveSeries == NULL)
		return;

	int nPointCount = pActiveSeries->GetPointsCount();
	if (nPointCount < 0)
		return;

	if (m_lPositionIndexInData < 0)
		m_lPositionIndexInData = 0;
	if (m_lPositionIndexInData > nPointCount - 1)
		m_lPositionIndexInData = nPointCount - 1;
}

void CChartDragLineCursorDu::KeyLeft()
{
	m_lPositionIndexInData--;
	ProtectCursorPositionIndexInData();
}

void CChartDragLineCursorDu::KeyRight()
{
	m_lPositionIndexInData++;
	ProtectCursorPositionIndexInData();
}