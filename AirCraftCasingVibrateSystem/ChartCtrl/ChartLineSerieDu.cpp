
#include "stdafx.h"
#include "ChartLineSerieDu.h"
#include "ChartCtrl.h"

#include "Math.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CChartLineSerieDu::CChartLineSerieDu(CChartCtrl* pParent) : CChartLineSerie(pParent)
{
	// m_nSerieType = SERIE_LINESERIEDU;

	//////////////////////////////////////////////////////////////////////////
}

CChartLineSerieDu::~CChartLineSerieDu()
{

}

void CChartLineSerieDu::AddPoints(double* pX, double* pY, unsigned Count)
{
	if (Count <= 0 || pX == NULL || pY == NULL)
	{
		ASSERT(FALSE);
		return;
	}
	
	// 拷贝基类的
	SChartXYPoint* pPoints = new SChartXYPoint[Count];

	for (unsigned i=0; i<Count; i++)
	{
		pPoints[i].X = pX[i];
		pPoints[i].Y = pY[i];
	}
	m_vPoints.AddPoints(pPoints, Count);
	RefreshAutoAxes(false);
	delete pPoints;

	// 自己添加的
	int nStart = GetPointsCount() - Count;
	for (unsigned i=0; i<Count; i++)
	{
		if (m_dMaxData < pY[i])
		{
			m_nMaxPositionIndexInData = nStart + i;
			m_dMaxData = pY[i];
		}
		if (m_dMinData > pY[i])
		{
			m_nMinPositionIndexInData = nStart + i;
			m_dMinData = pY[i];
		}
	}

	// 计算统计值
	if (m_bNeedCalStatValue)
		CalSamplingStatValue(pY, Count);

	CDC* pDC = m_pParentCtrl->GetDC();
	Draw(pDC);
	m_pParentCtrl->Invalidate();
}

void CChartLineSerieDu::SetPoints(double* pX, double* pY, unsigned Count)
{
	if (Count <= 0 || pX == NULL || pY == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	// 拷贝基类的
	SChartXYPoint* pPoints = new SChartXYPoint[Count];
	for (unsigned i=0; i<Count; i++)
	{
		pPoints[i].X = pX[i];
		pPoints[i].Y = pY[i];
	}
	m_vPoints.SetPoints(pPoints, Count);
	RefreshAutoAxes(true);
	delete pPoints;

	// 自己添加的
	m_nMaxPositionIndexInData = 0;
	m_nMinPositionIndexInData = 0;
	m_dMaxData = pY[m_nMaxPositionIndexInData];
	m_dMinData = pY[m_nMinPositionIndexInData];

	for (unsigned i=0; i<Count; i++)
	{
		if (m_dMaxData < pY[i])
		{
			m_nMaxPositionIndexInData = i;
			m_dMaxData = pY[m_nMaxPositionIndexInData];
		}
		if (m_dMinData > pY[i])
		{
			m_nMinPositionIndexInData = i;
			m_dMinData = pY[m_nMinPositionIndexInData];
		}
	}

	// 计算统计值
	if (m_bNeedCalStatValue)
		CalSamplingStatValue(pY, Count);
}

void CChartLineSerieDu::CalSamplingStatValue(double* pY, unsigned Count)
{
	if (pY == NULL || Count == 0)
	{
		ASSERT(FALSE);
		return;
	}

	m_dStatMaxValue = pY[0];
	m_dStatMinValue = pY[0];
	double dSum = 0;
	for (unsigned i=0; i<Count; i++)
	{
		if (m_dStatMaxValue < pY[i]) m_dStatMaxValue = pY[i];
		if (m_dStatMinValue > pY[i]) m_dStatMinValue = pY[i];
		dSum += pY[i];
	}
	m_dStatAveValue = dSum / Count;
	m_dStatPeakValue = m_dStatMaxValue - m_dStatMinValue;

	// 标准差
	dSum = 0;
	for (unsigned i=0; i<Count; i++)
		dSum += (pY[i] - m_dStatAveValue) * (pY[i] - m_dStatAveValue);
	m_dStatStdValue = sqrt(dSum / Count);

	// 有效值
	dSum = 0;
	for (unsigned i=0; i<Count; i++)
		dSum += (pY[i] * pY[i]);
	m_dStatRmsValue = sqrt(dSum / Count);
}

void CChartLineSerieDu::DrawAll(CDC *pDC)
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

	CPen NewPen;
	CPen ShadowPen;
	if (m_iPenStyle != PS_SOLID)
	{
		LOGBRUSH lb;
		lb.lbStyle = BS_SOLID;
		lb.lbColor = m_SerieColor;
		NewPen.CreatePen(PS_GEOMETRIC | m_iPenStyle, m_iLineWidth, &lb);
		lb.lbColor = m_ShadowColor;
		ShadowPen.CreatePen(PS_GEOMETRIC | m_iPenStyle, m_iLineWidth, &lb);
	}
	else
	{
		NewPen.CreatePen(m_iPenStyle, m_iLineWidth, m_SerieColor);
		ShadowPen.CreatePen(m_iPenStyle, m_iLineWidth, m_ShadowColor);
	}
	CPen* pOldPen;

	pDC->SetBkMode(TRANSPARENT);
	//To have lines limited in the drawing rectangle :
	pDC->IntersectClipRect(m_PlottingRect);
	pOldPen = pDC->SelectObject(&NewPen);

	{	
		if (uLast-uFirst >= 1)
		{
			CPoint* pPoints = new CPoint[uLast-uFirst+1];
			CPoint* pShadow = NULL;
			if (m_bShadow)
				pShadow = new CPoint[uLast-uFirst+1];

			unsigned long pointsCount = 0;
			CPoint LastScreenPoint;
			for (m_uLastDrawnPoint=uFirst;m_uLastDrawnPoint<=uLast;m_uLastDrawnPoint++)
			{
				//We don't draw a line between the origin and the first point -> we must have
				// a least 2 points before begining drawing
				SChartXYPoint Point = GetPoint(m_uLastDrawnPoint);
				CPoint ScreenPoint;
				ValueToScreen(Point.X, Point.Y, ScreenPoint);

				if(LastScreenPoint != ScreenPoint)
				{
					//Only collate the unique points 
					pPoints[pointsCount] = ScreenPoint;
					LastScreenPoint = ScreenPoint;

					if (m_bShadow) 
					{
						ScreenPoint.Offset(m_iShadowDepth,m_iShadowDepth);
						pShadow[pointsCount] = ScreenPoint;
					}
					pointsCount++;
				}
			}

			// We have to do that in order for the Draw function to work properly.
			m_uLastDrawnPoint--;

			pDC->SelectObject(&NewPen);
			pDC->Polyline(pPoints, pointsCount);

			delete[] pPoints;
			delete[] pShadow;
		}
	}

	pDC->SelectClipRgn(NULL);
	pDC->SelectObject(pOldPen);
	NewPen.DeleteObject();
	ShadowPen.DeleteObject();
}