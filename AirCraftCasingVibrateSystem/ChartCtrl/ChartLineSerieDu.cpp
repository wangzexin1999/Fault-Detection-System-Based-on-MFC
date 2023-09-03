
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

void CChartLineSerieDu::AddPoints(SChartXYPoint* pPoints, unsigned Count)
{
	if (pPoints == nullptr || Count == 0) return;

	// 自己添加的
	int nStart = GetPointsCount() - Count;
	for (unsigned i = 0; i < Count; i++)
	{
		if (m_dMaxData < pPoints[i].Y)
		{
			m_nMaxPositionIndexInData = nStart + i;
			m_dMaxData = pPoints[i].Y;
		}
		if (m_dMinData > pPoints[i].Y)
		{
			m_nMinPositionIndexInData = nStart + i;
			m_dMinData = pPoints[i].Y;
		}
	}

	// 计算统计值
	if (m_bNeedCalStatValue)
		CalSamplingStatValue(pPoints, Count);

	m_vPoints.AddPoints(pPoints, Count);
	RefreshAutoAxes(false);
	delete pPoints;
	pPoints = nullptr;
	//CDC* pDC = m_pParentCtrl->GetDC();
	//Draw(pDC);
	//m_pParentCtrl->Invalidate();
}
void CChartLineSerieDu::DrawDu()
{
	CDC* pDC = m_pParentCtrl->GetDC();
	Draw(pDC);
	m_pParentCtrl->Invalidate();
}

void CChartLineSerieDu::SetPoints(SChartXYPoint* pPoints, unsigned Count)
{
	if (Count <= 0 || pPoints == NULL)
	{
		ASSERT(FALSE);
		return;
	}
	m_vPoints.SetPoints(pPoints, Count);
	RefreshAutoAxes(true);
	delete pPoints;

	// 自己添加的
	m_nMaxPositionIndexInData = 0;
	m_nMinPositionIndexInData = 0;
	m_dMaxData = pPoints[m_nMaxPositionIndexInData].Y;
	m_dMinData = pPoints[m_nMaxPositionIndexInData].Y;

	for (unsigned i=0; i<Count; i++)
	{
		if (m_dMaxData <  pPoints[i].Y)
		{
			m_nMaxPositionIndexInData = i;
			m_dMaxData = pPoints[m_nMaxPositionIndexInData].Y;
		}
		if (m_dMinData >  pPoints[i].Y)
		{
			m_nMinPositionIndexInData = i;
			m_dMinData = pPoints[m_nMaxPositionIndexInData].Y;
		}
	}

	// 计算统计值
	if (m_bNeedCalStatValue)
		CalSamplingStatValue(pPoints, Count);
}

void CChartLineSerieDu::CalSamplingStatValue(SChartXYPoint* pPoints, unsigned Count)
{
	if (pPoints == NULL || Count == 0)
	{
		ASSERT(FALSE);
		return;
	}

	m_dStatMaxValue = pPoints[0].Y;
	m_dStatMinValue = pPoints[0].Y;
	double dSum = 0;
	for (unsigned i=0; i<Count; i++)
	{
		if (m_dStatMaxValue < pPoints[i].Y) m_dStatMaxValue = pPoints[i].Y;
		if (m_dStatMinValue >  pPoints[i].Y) m_dStatMinValue = pPoints[i].Y;
		dSum += pPoints[i].Y;
	}
	m_dStatSumValue = dSum;

	//均值
	m_dStatAveValue = dSum / Count;
	m_dStatPeakValue = m_dStatMaxValue - m_dStatMinValue;

	// 方差
	dSum = 0;
	for (unsigned i=0; i<Count; i++)
		dSum += ( pPoints[i].Y - m_dStatAveValue) * ( pPoints[i].Y - m_dStatAveValue);
	//m_dStatStdValue = sqrt(dSum / Count);//标准差
	m_dStatStdValue = dSum / Count;

	// 有效值
	dSum = 0;
	for (unsigned i=0; i<Count; i++)
		dSum += ( pPoints[i].Y *  pPoints[i].Y);
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
double CChartLineSerieDu::GetMax()
{
	return m_dStatMaxValue;
}
double CChartLineSerieDu::GetSum()
{
	return m_dStatSumValue;
}