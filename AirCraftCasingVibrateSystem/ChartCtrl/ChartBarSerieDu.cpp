
#include "stdafx.h"
#include "ChartBarSerieDu.h"
#include "ChartCtrl.h"
#include <algorithm>
#include "DuChartCtrl.h"

CChartBarSerieDu::CChartBarSerieDu(CChartCtrl* pParent) 
 : CChartLineSerieDu(pParent)
{
}

CChartBarSerieDu::~CChartBarSerieDu()
{
}

void CChartBarSerieDu::DrawAll(CDC *pDC)
{
	if (!m_bIsVisible)
		return;
	if (!pDC->GetSafeHdc())
		return;

	unsigned uFirst=0, uLast=0;
	if (!GetVisiblePoints(uFirst,uLast))
		return;

	if (uFirst>0)
		uFirst--;
	if (uLast<GetPointsCount()-1)
		uLast++;
	if (uLast-uFirst < 1)
		return;

	pDC->SetBkMode(TRANSPARENT);
	pDC->IntersectClipRect(m_PlottingRect);

	CPen NewPen;
	NewPen.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	CPen* pOldPen = pDC->SelectObject(&NewPen);

	CBrush NewBrush;
	NewBrush.CreateSolidBrush(m_SerieColor);
	CBrush * pOldBrush = pDC->SelectObject(&NewBrush);

	{	
		if (uLast-uFirst >= 1)
		{
			CPoint* pPoints = new CPoint[uLast-uFirst+1];

			// unsigned long pointsCount = 0;
			CPoint LastScreenPoint;

			int pointsCount = uLast-uFirst+1;

			for (m_uLastDrawnPoint=uFirst;m_uLastDrawnPoint<=uLast;m_uLastDrawnPoint++)
			{
				//We don't draw a line between the origin and the first point -> we must have
				// a least 2 points before begining drawing
				SChartXYPoint Point = GetPoint(m_uLastDrawnPoint);
				CPoint ScreenPointQian;
				ValueToScreen(Point.X - 0.5, Point.Y, ScreenPointQian);
				CPoint ScreenPointHou;
				ValueToScreen(Point.X + 0.5, Point.Y, ScreenPointHou);

				//CRect crectFor(ScreenPointQian.x, ScreenPointQian.y, ScreenPointHou.x, m_PlottingRect.bottom);
				//pDC->Rectangle(crectFor);

				//pPoints[m_uLastDrawnPoint].x = Point.X;
				//pPoints[m_uLastDrawnPoint].y = Point.Y;
				ValueToScreen(Point.X, Point.Y, pPoints[m_uLastDrawnPoint]);
				pDC->Ellipse(pPoints[m_uLastDrawnPoint].x - 2, pPoints[m_uLastDrawnPoint].y - 2, pPoints[m_uLastDrawnPoint].x + 2, pPoints[m_uLastDrawnPoint].y + 2);
			}

			
			pDC->Polyline(pPoints, pointsCount);

			delete[] pPoints;
		}
	}

	CDuChartCtrl * pDuChartCtrl = (CDuChartCtrl*)m_pParentCtrl;
	if (pDuChartCtrl->m_bDrawHengxian)
	{
		if (pDuChartCtrl->m_nDrawHengxianCount >= 1)
		{
			CPoint* pPoints = new CPoint[pDuChartCtrl->m_nDrawHengxianCount];

			// unsigned long pointsCount = 0;
			//CPoint LastScreenPoint;

			//int pointsCount = uLast-uFirst+1;

			for (int i=0;i<pDuChartCtrl->m_nDrawHengxianCount;i++)
			{
				//We don't draw a line between the origin and the first point -> we must have
				// a least 2 points before begining drawing
				//SChartXYPoint Point = GetPoint(m_uLastDrawnPoint);
				CPoint ScreenPointQian;
				ValueToScreen(pDuChartCtrl->m_fHengxianValueX[i], pDuChartCtrl->m_fHengxianValueY[i], ScreenPointQian);
				//CPoint ScreenPointHou;
				//ValueToScreen(Point.X + 0.5, Point.Y, ScreenPointHou);

				//CRect crectFor(ScreenPointQian.x, ScreenPointQian.y, ScreenPointHou.x, m_PlottingRect.bottom);
				//pDC->Rectangle(crectFor);

				//pPoints[m_uLastDrawnPoint].x = Point.X;
				//pPoints[m_uLastDrawnPoint].y = Point.Y;
				//ValueToScreen(Point.X, Point.Y, pPoints[m_uLastDrawnPoint]);
				//pDC->Ellipse(pPoints[m_uLastDrawnPoint].x - 2, pPoints[m_uLastDrawnPoint].y - 2, pPoints[m_uLastDrawnPoint].x + 2, pPoints[m_uLastDrawnPoint].y + 2);

				pPoints[i] = ScreenPointQian;
			}
			pDC->Polyline(pPoints, pDuChartCtrl->m_nDrawHengxianCount);

			delete[] pPoints;
		}
	}

	pDC->SelectClipRgn(NULL);
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
	NewPen.DeleteObject();
	NewBrush.DeleteObject();
}