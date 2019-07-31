
#include "stdafx.h"
#include "DuChartCtrl.h"
#include "afxcontrolbarutil.h"

#include "ChartSerie.h"
#include "ChartGradient.h"
#include "ChartStandardAxis.h"
#include "ChartDateTimeAxis.h"
#include "ChartLogarithmicAxis.h"
#include "ChartCrossHairCursor.h"
#include "ChartDragLineCursor.h"

#include "ChartPointsSerie.h"
#include "ChartLineSerie.h"
#include "ChartSurfaceSerie.h"
#include "ChartBarSerie.h"
#include "ChartCandlestickSerie.h"
#include "ChartGanttSerie.h"
#if _MFC_VER > 0x0600
#include "atlImage.h"
#endif
#include "ChartDragLineCursorDu.h"
#include "ChartDuCursorXie.h"
#include "ChartLineSerieDu.h"
#include "ChartDuCursorPeak.h"
#include "ChartDuCursorTrough.h"
#include "ChartStandardAxisDu.h"
#include "ChartLogarithmicAxisDu.h"
#include "ChartBarAxisDu.h"
#include "ChartBarSerieDu.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define CHARTCTRL_CLASSNAME    _T("DuChartCtrl")  // Window class name

#define CHART_MARGIN 2

/////////////////////////////////////////////////////////////////////////////
// CDuChartCtrl

BEGIN_MESSAGE_MAP(CDuChartCtrl, CChartCtrl)
	//{{AFX_MSG_MAP(CDuChartCtrl)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CDuChartCtrl::CDuChartCtrl()
{
	RegisterWindowClass();

	m_bZoomEnabled = false;

	m_BackColor = RGB(255, 255, 255);
	m_GraphBKColor = GetSysColor(COLOR_BTNFACE);

	//////////////////////////////////////////////////////////////////////////

	m_uActiveSerieID = 0;
	m_uActiveSerieIndex = 0;
	m_uActiveCursorID = 0;

	m_shuxing.m_pParentCtrl = this;

	m_bDrawHengxian = FALSE;
	m_nDrawHengxianCount = 0;
	memset(m_fHengxianValueX, 0, sizeof(m_fHengxianValueX));
	memset(m_fHengxianValueY, 0, sizeof(m_fHengxianValueY));
}

CDuChartCtrl::~CDuChartCtrl()
{
	
}

/////////////////////////////////////////////////////////////////////////////
// CDuChartCtrl message handlers

bool CDuChartCtrl::RegisterWindowClass()
{
	WNDCLASS wndcls;
	HINSTANCE hInst = AfxGetInstanceHandle();

	if (!(::GetClassInfo(hInst, CHARTCTRL_CLASSNAME, &wndcls)))
	{
		memset(&wndcls, 0, sizeof(WNDCLASS));   

		wndcls.hInstance		= hInst;
		wndcls.lpfnWndProc		= ::DefWindowProc;
		wndcls.hCursor			= NULL; //LoadCursor(NULL, IDC_ARROW);
		wndcls.hIcon			= 0;
		wndcls.lpszMenuName		= NULL;
		wndcls.hbrBackground	= (HBRUSH) ::GetStockObject(WHITE_BRUSH);
		wndcls.style			= CS_DBLCLKS; 
		wndcls.cbClsExtra		= 0;
		wndcls.cbWndExtra		= 0;
		wndcls.lpszClassName    = CHARTCTRL_CLASSNAME;

		if (!RegisterClass(&wndcls))
		{
			//  AfxThrowResourceException();
			return false;
		}
	}

	return true;

}

CChartSerie * CDuChartCtrl::GetActiveSerieDu()
{
	return GetSerie(m_uActiveSerieID);

}

CChartCursor * CDuChartCtrl::GetActiveCursorDu()
{
	return GetCursorDu(m_uActiveCursorID);
}

void CDuChartCtrl::SetActiveSerieIndexDu(int nIndex)
{
	int nSerieCount = GetSeriesCount();
	ASSERT(nIndex >= 0 && nIndex < nSerieCount);
	TSeriesMap::iterator iter = m_mapSeries.begin();
	for (int i=0; i<nIndex; i++)
		iter++;

	CChartSerie * pChartSerie = iter->second;
	m_uActiveSerieID = pChartSerie->GetSerieId();
	m_uActiveSerieIndex = nIndex;
}

CChartSerie * CDuChartCtrl::GetSerieFromIndexDu(int nIndex)
{
	int nSerieCount = GetSeriesCount();
	ASSERT(nIndex >= 0 && nIndex < nSerieCount);
	TSeriesMap::iterator iter = m_mapSeries.begin();
	for (int i=0; i<nIndex; i++)
		iter++;
	return iter->second;
}

void CDuChartCtrl::SetActiveCursorIndexDu(int nIndex)
{
	int nCursorCount = GetCursorCountDu();
	ASSERT(nIndex >= 0 && nIndex < nCursorCount);

	TCursorMap::iterator iter = m_mapCursors.begin();
	for (int i=0; i<nIndex; i++)
		iter++;

	CChartCursor * pChartCursor = iter->second;
	m_uActiveCursorID = pChartCursor->GetCursorId();
}

void CDuChartCtrl::RemoveAllAxisDu()
{
	for (int i=0; i<4 ;i++)
	{
		if (m_pAxes[i])
			delete m_pAxes[i];
		m_pAxes[i] = NULL;
	}
	RefreshCtrl();
}

CChartStandardAxisDu * CDuChartCtrl::CreateStandardAxisDu(EAxisPos axisPos, int nIndex)
{
	CChartStandardAxisDu * pAxis = new CChartStandardAxisDu();
	AttachCustomAxisDu(pAxis, axisPos, nIndex);
	return pAxis;
}

CChartLogarithmicAxisDu * CDuChartCtrl::CreateLogarithmicAxisDu(EAxisPos axisPos, int nIndex)
{
	CChartLogarithmicAxisDu * pAxis = new CChartLogarithmicAxisDu();
	AttachCustomAxisDu(pAxis, axisPos, nIndex);
	return pAxis;
}

CChartBarAxisDu* CDuChartCtrl::CreateBarAxisDu(EAxisPos axisPos, int nIndex)
{
	CChartBarAxisDu * pAxis = new CChartBarAxisDu();
	AttachCustomAxisDu(pAxis, axisPos, nIndex);
	return pAxis;
}

void CDuChartCtrl::RemoveAllCursorDu()
{
	TCursorMap::iterator iter = m_mapCursors.begin();
	while (iter != m_mapCursors.end())
	{
		delete iter->second;
		iter++;
	}
	m_mapCursors.clear();
	RefreshCtrl();
}

size_t CDuChartCtrl::GetCursorCountDu()
{
	return m_mapCursors.size();
}

bool CDuChartCtrl::MouseMoveRectTracker(CPoint & point)
{
	if (m_shuxing.m_rectCursorValue.m_rect.PtInRect(point) && m_shuxing.m_bDrawCursorValue)
		return true;
	if (m_shuxing.m_rectLegend.m_rect.PtInRect(point) && m_shuxing.m_bDrawLegend)
		return true;
	return false;
}

void CDuChartCtrl::OnMouseMove(UINT nFlags, CPoint point)
{
	// 自己写的，信息区域
	if (MouseMoveRectTracker(point))
	{
		Invalidate(FALSE);
		CWnd::OnMouseMove(nFlags, point);
		return;
	}

	// 单击鼠标右键，移动横轴
	if (m_bRMouseDown && m_bPanEnabled)
	{
		if (point != m_PanAnchor)
		{
			EnableRefresh(false);
			if (m_pAxes[LeftAxis])
				m_pAxes[LeftAxis]->PanAxis(m_PanAnchor.y,point.y);
			if (m_pAxes[RightAxis])
				m_pAxes[RightAxis]->PanAxis(m_PanAnchor.y,point.y);
			if (m_pAxes[BottomAxis])
				m_pAxes[BottomAxis]->PanAxis(m_PanAnchor.x,point.x);
			if (m_pAxes[TopAxis])
				m_pAxes[TopAxis]->PanAxis(m_PanAnchor.x,point.x);
			RefreshCtrl();
			EnableRefresh(true);
			// Force an immediate repaint of the window, so that the mouse messages
			// are by passed (this allows for a smooth pan)
			UpdateWindow();

			m_PanAnchor = point;
		}
	}

	// 单击鼠标左键截屏
	if (m_bLMouseDown && m_bZoomEnabled)
	{
		m_rectZoomArea.BottomRight() = point;
		Invalidate();
	}

	for (int i=0; i<4; i++)
	{
		if (m_pAxes[i])
			m_pAxes[i]->m_pScrollBar->OnMouseLeave();
	}
	CWnd* pWnd = ChildWindowFromPoint(point);
	if (pWnd != this)
	{
		CChartScrollBar* pScrollBar = dynamic_cast<CChartScrollBar*>(pWnd);
		if (pScrollBar)
			pScrollBar->OnMouseEnter();
	}

	// 继承基类
	if (m_PlottingRect.PtInRect(point))
	{
		TCursorMap::iterator iter = m_mapCursors.begin();
		for (iter; iter!=m_mapCursors.end(); iter++)
			iter->second->OnMouseMove(point);

		Invalidate();
	}

	if (!m_bMouseVisible && m_PlottingRect.PtInRect(point))
		SetCursor(NULL);
	else
		SetCursor(::LoadCursor(NULL,IDC_ARROW));

	SendMouseEvent(CChartMouseListener::MouseMove, point);
	CWnd::OnMouseMove(nFlags, point);
}

bool CDuChartCtrl::LButtonUpRectTracker(CPoint & point)
{
	if (m_shuxing.m_rectCursorValue.m_rect.PtInRect(point) && m_shuxing.m_bDrawCursorValue)
		return true;
	if (m_shuxing.m_rectLegend.m_rect.PtInRect(point) && m_shuxing.m_bDrawLegend)
		return true;
	return false;
}

void CDuChartCtrl::OnLButtonUp(UINT nFlags, CPoint point)
{
	// 自己写的，信息区域
	if (LButtonUpRectTracker(point))
	{
		Invalidate(FALSE);
		CWnd::OnLButtonUp(nFlags, point);
		return;
	}

	// 继承基类
 	ReleaseCapture();
 	m_bLMouseDown = false;
	if (m_bZoomEnabled)
	{
		if ( (m_rectZoomArea.left > m_rectZoomArea.right) ||
			(m_rectZoomArea.top > m_rectZoomArea.bottom))
		{
			UndoPanZoom();
		}
		else if ( (m_rectZoomArea.left!=m_rectZoomArea.right) &&
			(m_rectZoomArea.top!=m_rectZoomArea.bottom))
		{
			double MinVal = 0;			
			double MaxVal = 0;

			if (m_pAxes[BottomAxis])
			{
				if (m_pAxes[BottomAxis]->IsInverted())
				{
					MaxVal = m_pAxes[BottomAxis]->ScreenToValue(m_rectZoomArea.left);
					MinVal = m_pAxes[BottomAxis]->ScreenToValue(m_rectZoomArea.right);
				}
				else
				{
					MinVal = m_pAxes[BottomAxis]->ScreenToValue(m_rectZoomArea.left);
					MaxVal = m_pAxes[BottomAxis]->ScreenToValue(m_rectZoomArea.right);
				}
				m_pAxes[BottomAxis]->SetZoomMinMax(MinVal,MaxVal);
			}

			if (m_pAxes[LeftAxis])
			{
				if (m_pAxes[LeftAxis]->IsInverted())
				{
					MaxVal = m_pAxes[LeftAxis]->ScreenToValue(m_rectZoomArea.bottom);
					MinVal = m_pAxes[LeftAxis]->ScreenToValue(m_rectZoomArea.top);
				}
				else
				{
					MinVal = m_pAxes[LeftAxis]->ScreenToValue(m_rectZoomArea.bottom);
					MaxVal = m_pAxes[LeftAxis]->ScreenToValue(m_rectZoomArea.top);
				}
				m_pAxes[LeftAxis]->SetZoomMinMax(MinVal,MaxVal);
			}

			if (m_pAxes[TopAxis])
			{
				if (m_pAxes[TopAxis]->IsInverted())
				{
					MaxVal = m_pAxes[TopAxis]->ScreenToValue(m_rectZoomArea.left);
					MinVal = m_pAxes[TopAxis]->ScreenToValue(m_rectZoomArea.right);
				}
				else
				{
					MinVal = m_pAxes[TopAxis]->ScreenToValue(m_rectZoomArea.left);
					MaxVal = m_pAxes[TopAxis]->ScreenToValue(m_rectZoomArea.right);
				}
				m_pAxes[TopAxis]->SetZoomMinMax(MinVal,MaxVal);
			}

			if (m_pAxes[RightAxis])
			{
				if (m_pAxes[RightAxis]->IsInverted())
				{
					MaxVal = m_pAxes[RightAxis]->ScreenToValue(m_rectZoomArea.bottom);
					MinVal = m_pAxes[RightAxis]->ScreenToValue(m_rectZoomArea.top);
				}
				else
				{
					MinVal = m_pAxes[RightAxis]->ScreenToValue(m_rectZoomArea.bottom);
					MaxVal = m_pAxes[RightAxis]->ScreenToValue(m_rectZoomArea.top);
				}
				m_pAxes[RightAxis]->SetZoomMinMax(MinVal,MaxVal);
			}

			RefreshCtrl();
		}
	}

	if (m_PlottingRect.PtInRect(point))
	{
		TCursorMap::iterator iter = m_mapCursors.begin();
		for (iter; iter!=m_mapCursors.end(); iter++)
			iter->second->OnMouseButtonUp(point);

		Invalidate();
	}

 	SendMouseEvent(CChartMouseListener::LButtonUp, point);
	CWnd::OnLButtonUp(nFlags, point);
}

bool CDuChartCtrl::LButtonDownRectTracker(CPoint & point)
{
	if (m_shuxing.m_rectCursorValue.m_rect.PtInRect(point) && m_shuxing.m_bDrawCursorValue)
	{
		m_shuxing.m_rectCursorValue.Track(this, point, TRUE);
		return true;
	}
	if (m_shuxing.m_rectLegend.m_rect.PtInRect(point) && m_shuxing.m_bDrawLegend)
	{
		m_shuxing.m_rectLegend.Track(this, point, TRUE);
		return true;
	}
	if (m_shuxing.m_rectStatValue.m_rect.PtInRect(point) && m_shuxing.m_bDrawStatValue)
	{
		m_shuxing.m_rectStatValue.Track(this, point, TRUE);
		return true;
	}
	return false;
}

void CDuChartCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// 自己写的，单击信息区域
	if (LButtonDownRectTracker(point))
	{
		CWnd::OnLButtonDown(nFlags, point);
		return;
	}

	// 设置鼠标捕获
	SetCapture();

	// 继承基类，截屏
	if (m_bZoomEnabled)
	{
		m_bLMouseDown = true;
		m_rectZoomArea.TopLeft() = point;
		m_rectZoomArea.BottomRight() = point;
	}

	// 改写基类，移动光标
	if (m_PlottingRect.PtInRect(point))
	{
		// 基类是每个光标都单击
		if (FALSE)
		{
			TCursorMap::iterator iter = m_mapCursors.begin();
			for (iter; iter!=m_mapCursors.end(); iter++)
				iter->second->OnMouseButtonDown(point);
		}

		// 子类改写，是否激活光标，活动光标单击
		if (TRUE)
		{
			// 是否激活光标
			TCursorMap::iterator iter = m_mapCursors.begin();
			int nIndex = 0;
			for (iter = m_mapCursors.begin(); iter!=m_mapCursors.end(); iter++)
			{
				CChartDragLineCursor * pChartCursor = (CChartDragLineCursor*)iter->second;
				if (abs(pChartCursor->m_lPosition - point.x) <= 10)
				{
					SetActiveCursorIndexDu(nIndex);
					break;
				}
				nIndex++;
			}
			// 活动光标单击
			CChartCursor * pActiveCursor = GetActiveCursorDu();
			if (pActiveCursor != NULL)
				pActiveCursor->OnMouseButtonDown(point);
		}

		Invalidate();
	}

	SetFocus();
	SendMouseEvent(CChartMouseListener::LButtonDown, point);
	CWnd::OnLButtonDown(nFlags, point);
}

CChartCursor * CDuChartCtrl::GetCursorDu(unsigned uCursorId)
{
	CChartCursor * pToReturn = NULL;
	TCursorMap::const_iterator iter = m_mapCursors.find(uCursorId);
	if (iter != m_mapCursors.end())
	{
		pToReturn = iter->second;
	}

	return pToReturn;
}

CChartCursor * CDuChartCtrl::GetCursorFromIndexDu(int nIndex)
{
    int nSize = static_cast<int>(m_mapCursors.size());
    ASSERT(nIndex >= 0 && nIndex <= nSize - 1);
    if (nIndex < 0 || nIndex > nSize - 1)
        return NULL;
	CChartCursor * pToReturn = NULL;
	TCursorMap::iterator itBegin = m_mapCursors.begin();
	for (int i=0; i<nIndex; i++)
		itBegin++;
	pToReturn = itBegin->second;
	return pToReturn;
}

void CDuChartCtrl::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CRect rect;
	GetClientRect(&rect);
	if (rect.IsRectEmpty())
		return;

	CMemDC memDC(dc, rect);
	CDC * pDC = &memDC.GetDC();

	if (!m_bMemDCCreated)
	{
		RefreshCtrl();
		m_bMemDCCreated = true;
	}

	// Get Size of Display area
	pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &m_BackgroundDC, 0, 0, SRCCOPY) ;

	// Draw the zoom rectangle
	if (m_bZoomEnabled && m_bLMouseDown)
	{
		CPen NewPen(PS_SOLID,1,m_ZoomRectColor);
		CPen* pOldPen = dc.SelectObject(&NewPen);

		pDC->MoveTo(m_rectZoomArea.TopLeft());
		pDC->LineTo(m_rectZoomArea.right,m_rectZoomArea.top);
		pDC->LineTo(m_rectZoomArea.BottomRight());
		pDC->LineTo(m_rectZoomArea.left,m_rectZoomArea.bottom);
		pDC->LineTo(m_rectZoomArea.TopLeft());

		pDC->SelectObject(pOldPen);
		DeleteObject(NewPen);
	}

	// Draw the cursors. 
	TCursorMap::iterator iter = m_mapCursors.begin();
	for (iter; iter!=m_mapCursors.end(); iter++)
		iter->second->Draw(pDC);

	//////////////////////////////////////////////////////////////////////////

 	if (m_shuxing.m_bDrawCursorValue && m_shuxing.m_nCursorType != CDuChartCtrlShuxing::typeCursorNone)
 		m_shuxing.DrawCursorValue(pDC);
	if (m_shuxing.m_bDrawLegend)
		m_shuxing.DrawLegend(pDC);
	if (m_shuxing.m_bDrawStatValue)
		m_shuxing.DrawStatValue(pDC);
}

CChartDragLineCursorDu * CDuChartCtrl::CreateDragLineCursorDu()
{
	ASSERT(m_pAxes[BottomAxis] != NULL);
	ASSERT(m_pAxes[LeftAxis] != NULL);

	CChartDragLineCursorDu* pNewCursor = new CChartDragLineCursorDu(this, 
		m_pAxes[BottomAxis], m_pAxes[LeftAxis]);
	m_mapCursors[pNewCursor->GetCursorId()] = pNewCursor;
	return pNewCursor;
}

CChartDuCursorXie * CDuChartCtrl::CreateDuCursorXie()
{
	ASSERT(m_pAxes[BottomAxis] != NULL);
	ASSERT(m_pAxes[LeftAxis] != NULL);

	CChartDuCursorXie * pNewCursor = new CChartDuCursorXie(this, 
		m_pAxes[BottomAxis], m_pAxes[LeftAxis]);
	m_mapCursors[pNewCursor->GetCursorId()] = pNewCursor;
	return pNewCursor;
}

CChartDuCursorPeak * CDuChartCtrl::CreateDuCursorPeak()
{
	ASSERT(m_pAxes[BottomAxis] != NULL);
	ASSERT(m_pAxes[LeftAxis] != NULL);

	CChartDuCursorPeak * pNewCursor = new CChartDuCursorPeak(this, 
		m_pAxes[BottomAxis], m_pAxes[LeftAxis]);
	m_mapCursors[pNewCursor->GetCursorId()] = pNewCursor;
	return pNewCursor;
}

CChartDuCursorTrough * CDuChartCtrl::CreateDuCursorTrough()
{
	ASSERT(m_pAxes[BottomAxis] != NULL);
	ASSERT(m_pAxes[LeftAxis] != NULL);

	CChartDuCursorTrough * pNewCursor = new CChartDuCursorTrough(this, 
		m_pAxes[BottomAxis], m_pAxes[LeftAxis]);
	m_mapCursors[pNewCursor->GetCursorId()] = pNewCursor;
	return pNewCursor;
}

CChartLineSerieDu * CDuChartCtrl::CreateLineSerieDu(int nIndex, bool bSecondaryHorizAxis, bool bSecondaryVertAxis)
{
	CChartLineSerieDu * pNewSerie = new CChartLineSerieDu(this);
	AttachCustomSerieDu(pNewSerie, nIndex, bSecondaryHorizAxis, bSecondaryVertAxis);
	return pNewSerie;
}

CChartBarSerieDu * CDuChartCtrl::CreateBarSerieDu(int nIndex, bool bSecondaryHorizAxis, bool bSecondaryVertAxis)
{
	CChartBarSerieDu * pNewSerie = new CChartBarSerieDu(this);
	AttachCustomSerieDu(pNewSerie, nIndex, bSecondaryHorizAxis, bSecondaryVertAxis);
	return pNewSerie;
}

void CDuChartCtrl::AttachCustomSerieDu(CChartXYSerie * pNewSeries, int nSerieIndex, bool bSecondaryHorizAxis, bool bSecondaryVertAxis)
{
	size_t ColIndex = m_mapSeries.size() % 10;

	int nHorizAxisIndex = nSerieIndex;
	if (m_shuxing.m_nHebingOrFengkai == CDuChartCtrlShuxing::typeGongyongXZhou)
		nHorizAxisIndex = 0;

	CChartAxis* pHorizAxis = NULL;
	CChartAxis* pVertAxis = NULL;
	if (bSecondaryHorizAxis)
		pHorizAxis = m_pAxes[4 * nHorizAxisIndex + TopAxis];
	else
		pHorizAxis = m_pAxes[4 * nHorizAxisIndex + BottomAxis];
	if (bSecondaryVertAxis)
		pVertAxis = m_pAxes[4 * nSerieIndex + RightAxis];
	else
		pVertAxis = m_pAxes[4 * nSerieIndex + LeftAxis];

	ASSERT(pHorizAxis != NULL);
	ASSERT(pVertAxis != NULL);

	if (pNewSeries)
	{
		CRect PlottingRect = GetPlottingRectFromSerieIndexDu(nSerieIndex);
		pNewSeries->SetPlottingRect(PlottingRect);
		pNewSeries->m_pHorizontalAxis = pHorizAxis;
		pNewSeries->m_pVerticalAxis = pVertAxis;
		m_mapSeries[pNewSeries->GetSerieId()] = pNewSeries;

		pVertAxis->RegisterSeries(pNewSeries);
		pVertAxis->RefreshAutoAxis();
		pHorizAxis->RegisterSeries(pNewSeries);
		pHorizAxis->RefreshAutoAxis();
	}
}

void CDuChartCtrl::KeyUpOrDown(int nUpOrDown)
{
	size_t szSerieCount = GetSeriesCount();

	switch (nUpOrDown)
	{
	case 0:
		{
			if (m_uActiveSerieIndex == 0)
				return;
			m_uActiveSerieIndex--;
		}
		break;
	case 1:
		{
			if (m_uActiveSerieIndex == szSerieCount - 1)
				return;
			m_uActiveSerieIndex++;
		}
		break;
	default: {ASSERT(FALSE);}
	}

	SetActiveSerieIndexDu(m_uActiveSerieIndex);
	RefreshCtrl();
}

void CDuChartCtrl::KeyLeftOrRight(int nLeftOrRight)
{
	if (m_shuxing.m_nCursorType == CDuChartCtrlShuxing::typeCursorSingle ||
		m_shuxing.m_nCursorType == CDuChartCtrlShuxing::typeCursorTwo || 
		m_shuxing.m_nCursorType == CDuChartCtrlShuxing::typeCursorXie)
	{
		CChartDragLineCursorDu * pActiveCursor = (CChartDragLineCursorDu*)GetActiveCursorDu();
		if (pActiveCursor == NULL)
		{
			ASSERT(FALSE);
			return;
		}
		switch (nLeftOrRight)
		{
		case 0: pActiveCursor->KeyLeft(); break;
		case 1: pActiveCursor->KeyRight(); break;
		default: {ASSERT(FALSE);}
		}
	}
	RefreshCtrl();
}

void CDuChartCtrl::SetCursorNone(BOOL bRefresh)
{
	if (bRefresh)
		EnableRefresh(false);

	// 光标
	m_shuxing.m_nCursorType = CDuChartCtrlShuxing::typeCursorNone;
	RemoveAllCursorDu();

	if (bRefresh)
		EnableRefresh(true);
}

void CDuChartCtrl::SetCursorSingle(BOOL bRefresh)
{
	if (bRefresh)
		EnableRefresh(false);

	// 光标
	m_shuxing.m_nCursorType = CDuChartCtrlShuxing::typeCursorSingle;
	RemoveAllCursorDu();

	// 创光标
	CChartDragLineCursorDu * pCursor = CreateDragLineCursorDu();
	// 数据位置
	pCursor->SetPositionIndex(0);
	// 光标颜色
	pCursor->SetColor(m_shuxing.m_colCursorColor1);

	// 活动光标索引
	SetActiveCursorIndexDu(0);

	if (bRefresh)
		EnableRefresh(true);
}

void CDuChartCtrl::SetCursorTwo(BOOL bRefresh)
{
	if (bRefresh)
		EnableRefresh(false);

	// 光标
	m_shuxing.m_nCursorType = CDuChartCtrlShuxing::typeCursorTwo;
	RemoveAllCursorDu();

	// 创光标
	CChartDragLineCursorDu * pCursor1 = CreateDragLineCursorDu();
	// 数据位置
	pCursor1->SetPositionIndex(0);
	// 光标颜色
	pCursor1->SetColor(m_shuxing.m_colCursorColor1);
	// 创光标
	CChartDragLineCursorDu * pCursor2 = CreateDragLineCursorDu();
	// 数据位置
	pCursor2->SetPositionIndex(0);
	// 光标颜色
	pCursor2->SetColor(m_shuxing.m_colCursorColor2);

	// 活动光标索引
	SetActiveCursorIndexDu(0);

	if (bRefresh)
		EnableRefresh(true);
}

void CDuChartCtrl::SetCursorPeak(BOOL bRefresh)
{
	if (bRefresh)
		EnableRefresh(false);

	// 光标
	m_shuxing.m_nCursorType = CDuChartCtrlShuxing::typeCursorPeak;
	RemoveAllCursorDu();
	CChartDuCursorPeak * pCursor = CreateDuCursorPeak();
	pCursor->AutoDingweiCursorPositionIndexInData();
	pCursor->SetColor(m_shuxing.m_colCursorColor1);
	SetActiveCursorIndexDu(0);

	if (bRefresh)
		EnableRefresh(true);
}

void CDuChartCtrl::SetCursorTrough(BOOL bRefresh)
{
	if (bRefresh)
		EnableRefresh(false);

	// 光标
	m_shuxing.m_nCursorType = CDuChartCtrlShuxing::typeCursorTrough;
	RemoveAllCursorDu();
	CChartDuCursorTrough * pCursor = CreateDuCursorTrough();
	pCursor->AutoDingweiCursorPositionIndexInData();
	pCursor->SetColor(m_shuxing.m_colCursorColor1);
	SetActiveCursorIndexDu(0);

	if (bRefresh)
		EnableRefresh(true);
}

void CDuChartCtrl::SetCursorXie(BOOL bRefresh)
{
	if (bRefresh)
		EnableRefresh(false);

	// 光标
	m_shuxing.m_nCursorType = CDuChartCtrlShuxing::typeCursorXie;
	RemoveAllCursorDu();

	// 创光标
	CChartDuCursorXie * pCursor = CreateDuCursorXie();
	// 数据位置
	pCursor->SetPositionIndex(0);
	// 光标颜色
	pCursor->SetColor(m_shuxing.m_colCursorColor1);
	// 活动光标索引
	SetActiveCursorIndexDu(0);

	if (bRefresh)
		EnableRefresh(true);
}

void CDuChartCtrl::RefreshCtrl()
{
	// Window is not created yet, so skip the refresh.
	if (!GetSafeHwnd())
		return;
	if (m_iEnableRefresh < 1)
	{
		m_bPendingRefresh = true;
		return;
	}

	// Retrieve the client rect and initialize the
	// plotting rect
	CClientDC dc(this) ;  
	CRect ClientRect;
	GetClientRect(&ClientRect);
	m_PlottingRect = ClientRect;		

	// If the backgroundDC was not created yet, create it (it
	// is used to avoid flickering).
	if (!m_BackgroundDC.GetSafeHdc() )
	{
		CBitmap memBitmap;
		m_BackgroundDC.CreateCompatibleDC(&dc) ;
		memBitmap.CreateCompatibleBitmap(&dc, ClientRect.Width(),ClientRect.Height()) ;
		m_BackgroundDC.SelectObject(&memBitmap) ;
	}

	// Draw the chart background, which is not part of
	// the DrawChart function (to avoid a background when
	// printing).
	DrawBackground(&m_BackgroundDC, ClientRect);
	ClientRect.DeflateRect(3,3);
	DrawChart(&m_BackgroundDC,ClientRect);

	Invalidate();
}

void CDuChartCtrl::DrawChart(CDC* pDC, CRect ChartRect)
{
	// 画标题栏
	m_PlottingRect = ChartRect;
	CSize TitleSize = m_pTitles->GetSize(pDC);
	CRect rcTitle;
	rcTitle = ChartRect;
	rcTitle.bottom = TitleSize.cy;
	ChartRect.top += TitleSize.cy;
	m_pTitles->SetTitleRect(rcTitle);
	m_pTitles->Draw(pDC);

	// 计算图例区域
	m_pLegend->ClipArea(ChartRect,pDC);

	// 曲线个数
	size_t szSerieCount = GetSeriesCount();

	switch (m_shuxing.m_nHebingOrFengkai)
	{
	case CDuChartCtrlShuxing::typeHebing:
		{
			//Clip all the margins (axis) of the client rect
			for (int n=0;n<4;n++)
			{
				if (m_pAxes[n])
				{
					m_pAxes[n]->SetAxisSize(ChartRect,m_PlottingRect);
					m_pAxes[n]->Recalculate();
					m_pAxes[n]->ClipMargin(ChartRect,m_PlottingRect,pDC);
				}
			}
			for (int n=0;n<4;n++)
			{
				if (m_pAxes[n])
				{
					m_pAxes[n]->SetAxisSize(ChartRect,m_PlottingRect);
					m_pAxes[n]->Recalculate();
				}
			}

			// 图形区背景色
			pDC->FillSolidRect(m_PlottingRect, m_GraphBKColor);

			// 画图形框架
			CPen SolidPen(PS_SOLID,0,m_BorderColor);
			CPen* pOldPen = pDC->SelectObject(&SolidPen);
			pDC->MoveTo(m_PlottingRect.left,m_PlottingRect.top);
			pDC->LineTo(m_PlottingRect.right,m_PlottingRect.top);
			pDC->LineTo(m_PlottingRect.right,m_PlottingRect.bottom);
			pDC->LineTo(m_PlottingRect.left,m_PlottingRect.bottom);
			pDC->LineTo(m_PlottingRect.left,m_PlottingRect.top);
			pDC->SelectObject(pOldPen);
			DeleteObject(SolidPen);

			// 画坐标轴
			for (int n=0;n<4;n++)
			{
				if (m_pAxes[n])
				{
					m_pAxes[n]->Draw(pDC);
				}
			}
		}
		break;
	case CDuChartCtrlShuxing::typeFengkai:
		{
			int nPlottingRectLeft = ChartRect.left;
			int nPlottingRectRight = ChartRect.right;
			int nPlottingRectTop = ChartRect.top;
			int nPlottingRectBottom = ChartRect.bottom;
			int nPlottingRectWidth = ChartRect.Width();
			int nPlottingRectHeight = ChartRect.Height();
			int nFengkaiColumnCount = m_shuxing.m_nFengkaiColumnCount;
			int nFengkaiRowCount = (szSerieCount - 1) / nFengkaiColumnCount + 1;

			//Clip all the margins (axis) of the client rect
			CRect ChartRectFor[CDuChartCtrlShuxing::CHARTCTRL_MAX_SERIE_COUNT];
			for (size_t m = 0; m < szSerieCount; m++)
			{
				int nChu = m / nFengkaiColumnCount;
				int nYu = m % nFengkaiColumnCount;
				m_FengkaiPlottingRect[m].left = nPlottingRectLeft + nYu * nPlottingRectWidth / nFengkaiColumnCount;
				m_FengkaiPlottingRect[m].right = nPlottingRectLeft + (nYu + 1) * nPlottingRectWidth / nFengkaiColumnCount;
				m_FengkaiPlottingRect[m].top = nPlottingRectTop + nChu * nPlottingRectHeight / nFengkaiRowCount;
				m_FengkaiPlottingRect[m].bottom = nPlottingRectTop + (nChu + 1) * nPlottingRectHeight / nFengkaiRowCount;
				ChartRectFor[m] =  m_FengkaiPlottingRect[m];
				for (int n = 0; n < 4; n++)
				{
					int nIndex = m * 4 + n;
					if (m_pAxes[nIndex])
					{
						m_pAxes[nIndex]->SetAxisSize(ChartRectFor[m], m_FengkaiPlottingRect[m]);
						m_pAxes[nIndex]->Recalculate();
						m_pAxes[nIndex]->ClipMargin(ChartRectFor[m], m_FengkaiPlottingRect[m], pDC);
					}
				}
			}
			for (size_t m=0; m<szSerieCount; m++)
			{
				for (int n = 0; n < 4; n++)
				{
					int nIndex = m * 4 + n;
					if (m_pAxes[nIndex])
					{
						m_pAxes[nIndex]->SetAxisSize(ChartRectFor[m], m_FengkaiPlottingRect[m]);
						m_pAxes[nIndex]->Recalculate();
					}
				}
			}

			// 图形区背景色
			for (size_t n=0; n<szSerieCount; n++)
			{
				pDC->FillSolidRect(m_FengkaiPlottingRect[n], m_GraphBKColor);
			}

			// 画图形框架
			for (size_t n=0; n<szSerieCount; n++)
			{
				CPen SolidPen(PS_SOLID,0,m_BorderColor);
				CPen* pOldPen = pDC->SelectObject(&SolidPen);
				pDC->MoveTo(m_FengkaiPlottingRect[n].left,m_FengkaiPlottingRect[n].top);
				pDC->LineTo(m_FengkaiPlottingRect[n].right,m_FengkaiPlottingRect[n].top);
				pDC->LineTo(m_FengkaiPlottingRect[n].right,m_FengkaiPlottingRect[n].bottom);
				pDC->LineTo(m_FengkaiPlottingRect[n].left,m_FengkaiPlottingRect[n].bottom);
				pDC->LineTo(m_FengkaiPlottingRect[n].left,m_FengkaiPlottingRect[n].top);
				pDC->SelectObject(pOldPen);
				DeleteObject(SolidPen);
			}

			// 画坐标轴
			for (size_t m=0; m<szSerieCount; m++)
			{
				for (int n = 0; n < 4; n++)
				{
					int nIndex = m * 4 + n;
					if (m_pAxes[nIndex])
					{
						m_pAxes[nIndex]->Draw(pDC);
					}
				}
			}
		}
		break;
	case CDuChartCtrlShuxing::typeGongyongXZhou:
		{

		}
		break;
	default: {ASSERT(FALSE);}
	}

	// 画曲线
	TSeriesMap::iterator iter = m_mapSeries.begin();
	int i=0;
	for (iter; iter!=m_mapSeries.end(); iter++, i++)
	{
		CRect drawingRect = GetPlottingRectFromSerieIndexDu(i);
		drawingRect.bottom += 1;
		drawingRect.right += 1;
		iter->second->SetPlottingRect(drawingRect);
		iter->second->DrawAll(pDC);
	}

	// 画标签
	pDC->IntersectClipRect(m_PlottingRect);
	for (iter=m_mapSeries.begin(); iter!=m_mapSeries.end(); iter++)
		iter->second->DrawLabels(pDC);
	pDC->SelectClipRgn(NULL);

	// 画图例
	m_pLegend->Draw(pDC);
}

void CDuChartCtrl::AttachCustomAxisDu(CChartAxis* pAxis, EAxisPos axisPos, int nIndex)
{
	// The axis should not be already attached to another control
	ASSERT(pAxis->m_pParentCtrl == NULL);
	pAxis->SetParent(this);

	if ( (axisPos==RightAxis) || (axisPos==TopAxis) )
		pAxis->SetSecondary(true);
	if (  (axisPos==BottomAxis) || (axisPos==TopAxis) )
		pAxis->SetHorizontal(true);
	else
		pAxis->SetHorizontal(false);
	pAxis->CreateScrollBar();

	// Beofre storing the new axis, we should delete the previous one if any
	if (m_pAxes[4 * nIndex + axisPos])
		delete m_pAxes[4 * nIndex + axisPos];
	m_pAxes[4 * nIndex + axisPos] = pAxis;
}

CChartAxis * CDuChartCtrl::GetAxisDu(EAxisPos axisPos, int nIndex)
{
	switch (m_shuxing.m_nHebingOrFengkai)
	{
	case CDuChartCtrlShuxing::typeHebing:
		return m_pAxes[axisPos];
		break;
	case CDuChartCtrlShuxing::typeFengkai:
	case CDuChartCtrlShuxing::typeGongyongXZhou:
		return m_pAxes[4 * nIndex + axisPos];
		break;
	}
	return NULL;
}

int CDuChartCtrl::GetSerieIndexFromAxisPtrDu(CChartAxis * pAxis)
{
	for (int i=0; i<sizeof(m_pAxes)/sizeof(CChartAxis*); i++)
	{
		if (m_pAxes[i] == pAxis)
			return i / 4;
	}
	ASSERT(FALSE);
	return -1;
}

CRect CDuChartCtrl::GetPlottingRectFromSerieIndexDu(int nIndex)  const 
{
	CRect crect;
	switch (m_shuxing.m_nHebingOrFengkai)
	{
	case CDuChartCtrlShuxing::typeHebing:
		crect = m_PlottingRect;
		break;
	case CDuChartCtrlShuxing::typeFengkai:
	case CDuChartCtrlShuxing::typeGongyongXZhou:
		crect = m_FengkaiPlottingRect[nIndex];
		break;
	default: {ASSERT(FALSE);}
	}
	return crect;
}

int CDuChartCtrl::GetPlottingGraphCount()
{
	switch (m_shuxing.m_nHebingOrFengkai)
	{
	case CDuChartCtrlShuxing::typeHebing:
		return 1;
	case CDuChartCtrlShuxing::typeFengkai:
	case CDuChartCtrlShuxing::typeGongyongXZhou:
		return GetSeriesCount();
		break;
	default: {ASSERT(FALSE);}
	}
	return 0;
}

int CDuChartCtrl::GetPlottingGraphIndexFromPoint(CPoint pt)
{
	switch (m_shuxing.m_nHebingOrFengkai)
	{
	case CDuChartCtrlShuxing::typeHebing:
		{
			if (m_PlottingRect.PtInRect(pt))
				return 0;
		}
		break;
	case CDuChartCtrlShuxing::typeFengkai:
	case CDuChartCtrlShuxing::typeGongyongXZhou:
		{
			for (size_t i=0; i<GetSeriesCount(); i++)
			{
				if (m_FengkaiPlottingRect[i].PtInRect(pt))
					return i;
			}
		}
		break;
	default: {ASSERT(FALSE);}
	}
	return -1;
}

void CDuChartCtrl::CreateSeriesDu(int nSerieCount, int nSerieType)
{
    if (nSerieCount <= 0)
        return;

	m_shuxing.m_nSerieType = nSerieType;

	BOOL bHebing = FALSE;
	if (m_shuxing.m_nHebingOrFengkai == CDuChartCtrlShuxing::typeHebing) 
		bHebing = TRUE;

	for (int i=0; i<nSerieCount; i++)
	{
		CChartXYSerie * pSerie = NULL;

		switch (nSerieType)
		{
		case CDuChartCtrlShuxing::typeSerieLine:
			{
				if (bHebing) pSerie = CreateLineSerieDu(0);
				else pSerie = CreateLineSerieDu(i);
			}
			break;
		case CDuChartCtrlShuxing::typeSerieBeipc:
			{
				if (bHebing) pSerie = CreateBarSerieDu(0);
				else pSerie = CreateBarSerieDu(i);
			}
			break;
		default: {ASSERT(FALSE);}
		}

		pSerie->SetColor(m_shuxing.m_colorSerie[i]);
	}

	// 设置活动曲线
	SetActiveSerieIndexDu(0);
}

void CDuChartCtrl::CreateAxisDu()
{
	CreateStandardAxisDu(CChartCtrl::BottomAxis, 0);
	CreateStandardAxisDu(CChartCtrl::LeftAxis, 0);
}

void CDuChartCtrl::CreateAxisDu(int nSerieCount, int nXAxisType, int nYAxisType)
{
	switch (m_shuxing.m_nHebingOrFengkai)
	{
	case CDuChartCtrlShuxing::typeHebing:
		{
			switch (nXAxisType)
			{
			case CDuChartCtrlShuxing::typeAxisLine: 
				CreateStandardAxisDu(CChartCtrl::BottomAxis, 0);
				break;
			case CDuChartCtrlShuxing::typeAxisLog: 
				CreateLogarithmicAxisDu(CChartCtrl::BottomAxis, 0);
				break;
			case CDuChartCtrlShuxing::typeAxisBar: 
				CreateBarAxisDu(CChartCtrl::BottomAxis, 0);
				break;
			default: {ASSERT(FALSE);}
			}

			switch (nYAxisType)
			{
			case CDuChartCtrlShuxing::typeAxisLine: 
				CreateStandardAxisDu(CChartCtrl::LeftAxis, 0); 
				break;
			case CDuChartCtrlShuxing::typeAxisLog: 
				CreateLogarithmicAxisDu(CChartCtrl::LeftAxis, 0); 
				break;
			default: {ASSERT(FALSE);}
			}
		}
		break;
	case CDuChartCtrlShuxing::typeFengkai:
		{
			for (int i=0; i<nSerieCount; i++)
			{
				switch (nXAxisType)
				{
				case CDuChartCtrlShuxing::typeAxisLine: 
					CreateStandardAxisDu(CChartCtrl::BottomAxis, i);
					break;
				case CDuChartCtrlShuxing::typeAxisLog: 
					CreateLogarithmicAxisDu(CChartCtrl::BottomAxis, i);
					break;
				default: {ASSERT(FALSE);}
				}

				switch (nYAxisType)
				{
				case CDuChartCtrlShuxing::typeAxisLine: 
					CreateStandardAxisDu(CChartCtrl::LeftAxis, i); 
					break;
				case CDuChartCtrlShuxing::typeAxisLog: 
					CreateLogarithmicAxisDu(CChartCtrl::LeftAxis, i); 
					break;
				default: {ASSERT(FALSE);}
				}
			}
		}
		break;
	case CDuChartCtrlShuxing::typeGongyongXZhou:
		{
			switch (nXAxisType)
			{
			case CDuChartCtrlShuxing::typeAxisLine: 
				CreateStandardAxisDu(CChartCtrl::BottomAxis, 0);
				break;
			case CDuChartCtrlShuxing::typeAxisLog: 
				CreateLogarithmicAxisDu(CChartCtrl::BottomAxis, 0);
				break;
			default: {ASSERT(FALSE);}
			}

			for (int i=0; i<nSerieCount; i++)
			{
				switch (nYAxisType)
				{
				case CDuChartCtrlShuxing::typeAxisLine: 
					CreateStandardAxisDu(CChartCtrl::LeftAxis, i); 
					break;
				case CDuChartCtrlShuxing::typeAxisLog: 
					CreateLogarithmicAxisDu(CChartCtrl::LeftAxis, i); 
					break;
				default: {ASSERT(FALSE);}
				}
			}
		}
		break;
	default: {ASSERT(FALSE);}
	}
}

void CDuChartCtrl::AutoXScale(BOOL bRefresh)
{
	if (bRefresh)
		EnableRefresh(false);

	int nSerieCount = GetSeriesCount();
	CChartLineSerieDu * pSerie = (CChartLineSerieDu*)GetActiveSerieDu();
	double dMin = 0, dMax = 0;
	pSerie->GetSerieXMinMax(dMin, dMax);
    if (m_shuxing.m_nSerieType == CDuChartCtrlShuxing::typeSerieBeipc)
    {
        dMin -= 0.5;
        dMax += 0.5;
    }
	for (int i=0; i<nSerieCount; i++)
	{
		CChartAxis * pBottomAxis = GetAxisDu(CChartCtrl::BottomAxis, i);
		pBottomAxis->SetMinMax(dMin, dMax);
	}

	if (bRefresh)
		EnableRefresh(true);
}

void CDuChartCtrl::AutoYScale(BOOL bRefresh)
{
	if (bRefresh)
		EnableRefresh(false);

	int nHebingOrFengkai = m_shuxing.m_nHebingOrFengkai;
	int nSerieType = m_shuxing.m_nSerieType;
	int nSerieCount = GetSeriesCount();
	switch (nHebingOrFengkai)
	{
	case CDuChartCtrlShuxing::typeHebing:
		{
			double dAllSerieMinimum = 0, dAllSerieMaximum = 0;
			for (int i=0; i<nSerieCount; i++)
			{
				CChartXYSerieDu * pSerie = (CChartXYSerieDu*)GetSerieFromIndexDu(i);
				double dMinimum = 0, dMaximum = 0;
				pSerie->GetMinMax(dMinimum, dMaximum);
				if (0 == i)
				{
					dAllSerieMinimum = dMinimum;
					dAllSerieMaximum = dMaximum;
				}
				else
				{					
					if (dAllSerieMinimum > dMinimum) dAllSerieMinimum = dMinimum;
					if (dAllSerieMaximum < dMaximum) dAllSerieMaximum = dMaximum;
				}
			}
// 			//上下留白，0.618
// 			double dLeftDrawMin = dAllSerieMinimum-0.31*(dAllSerieMaximum-dAllSerieMinimum);
// 			double dLeftDrawMax = dAllSerieMaximum+0.31*(dAllSerieMaximum-dAllSerieMinimum);
			double dLeftDrawMin = dAllSerieMinimum;
			double dLeftDrawMax = dAllSerieMaximum;

			if (dLeftDrawMin == dLeftDrawMax)
            {
                dLeftDrawMin = 1;
                dLeftDrawMax = 1000;
            }

			CChartAxis * pLeftAxis = GetAxisDu(CChartCtrl::LeftAxis, 0);
			pLeftAxis->SetMinMax(dLeftDrawMin, dLeftDrawMax);
		}
		break;
	case CDuChartCtrlShuxing::typeFengkai:
		{
			for (int i=0; i<nSerieCount; i++)
			{
				CChartLineSerieDu * pSerie = (CChartLineSerieDu*)GetSerieFromIndexDu(i);
				double dMinimum = 0, dMaximum = 0;
				pSerie->GetMinMax(dMinimum, dMaximum);

				double dLeftDrawMin = dMinimum;
				double dLeftDrawMax = dMaximum;
				if (dLeftDrawMin == 0 && dLeftDrawMax == 0)
				{
					dLeftDrawMin = 0;
					dLeftDrawMax = 1000;
				}
				CChartAxis * pLeftAxis = GetAxisDu(CChartCtrl::LeftAxis, i);
				pLeftAxis->SetMinMax(dLeftDrawMin, dLeftDrawMax);
			}
		}
		break;
	default: {ASSERT(FALSE);}
	}

	if (bRefresh)
		EnableRefresh(true);
}

void CDuChartCtrl::HengxiangFangda()
{
	int nXZoomType = m_shuxing.m_nXZoomType;
	int nGraphCount = GetPlottingGraphCount();
	switch (nXZoomType)
	{
	case CDuChartCtrlShuxing::typeXZoomLeft:
		{
			for (int i=0; i<nGraphCount; i++)
			{
				CChartAxis * pAxis = GetAxisDu(CChartCtrl::BottomAxis, i);
				if (pAxis != NULL)
				{
					double Minimum = 0, Maximum = 0;
					pAxis->GetMinMax(Minimum, Maximum);
					double dNewMinimum = Minimum, dNewMaximum = Maximum;
					dNewMaximum = dNewMinimum + (Maximum - Minimum) / 2;
					pAxis->SetMinMax(dNewMinimum, dNewMaximum);
				}
			}
		}
		break;
	default: {ASSERT(FALSE);}
	}
}

void CDuChartCtrl::HengxiangSuoxiao()
{
	int nXZoomType = m_shuxing.m_nXZoomType;
	int nGraphCount = GetPlottingGraphCount();
	switch (nXZoomType)
	{
	case CDuChartCtrlShuxing::typeXZoomLeft:
		{
			for (int i=0; i<nGraphCount; i++)
			{
				CChartAxis * pAxis = GetAxisDu(CChartCtrl::BottomAxis, i);
				if (pAxis != NULL)
				{
					double Minimum = 0, Maximum = 0;
					pAxis->GetMinMax(Minimum, Maximum);
					double dNewMinimum = Minimum, dNewMaximum = Maximum;
					dNewMaximum = dNewMinimum + (Maximum - Minimum) * 2;
					pAxis->SetMinMax(dNewMinimum, dNewMaximum);
				}
			}
		}
		break;
	default: {ASSERT(FALSE);}
	}
}

void CDuChartCtrl::ZongxiangFangda()
{
	int nYZoomType = m_shuxing.m_nYZoomType;
	int nGraphCount = GetPlottingGraphCount();

	for (int i=0; i<nGraphCount; i++)
	{
		CChartAxis * pAxis = GetAxisDu(CChartCtrl::LeftAxis, i);
		if (pAxis != NULL)
		{
			double Minimum = 0, Maximum = 0;
			pAxis->GetMinMax(Minimum, Maximum);
			double dNewMinimum = Minimum, dNewMaximum = Maximum;

			switch (nYZoomType)
			{
			case CDuChartCtrlShuxing::typeYZoomBottom:
				{
					dNewMinimum = Minimum;
					dNewMaximum = dNewMinimum + (Maximum - Minimum) / 2;
				}
				break;
			case CDuChartCtrlShuxing::typeYZoomZero:
				{
					dNewMinimum /= 2;
					dNewMaximum /= 2;
				}
				break;
			default: {ASSERT(FALSE);}
			}
			
			pAxis->SetMinMax(dNewMinimum, dNewMaximum);
		}
	}
}

void CDuChartCtrl::ZongxiangSuoxiao()
{
	int nYZoomType = m_shuxing.m_nYZoomType;
	int nGraphCount = GetPlottingGraphCount();

	for (int i=0; i<nGraphCount; i++)
	{
		CChartAxis * pAxis = GetAxisDu(CChartCtrl::LeftAxis, i);
		if (pAxis != NULL)
		{
			double Minimum = 0, Maximum = 0;
			pAxis->GetMinMax(Minimum, Maximum);
			double dNewMinimum = Minimum, dNewMaximum = Maximum;
			
			switch (nYZoomType)
			{
			case CDuChartCtrlShuxing::typeYZoomBottom:
				{
					dNewMinimum = Minimum;
					dNewMaximum = dNewMinimum + (Maximum - Minimum) * 2;
				}
				break;
			case CDuChartCtrlShuxing::typeYZoomZero:
				{
					dNewMinimum *= 2;
					dNewMaximum *= 2;
				}
				break;
			default: {ASSERT(FALSE);}
			}

			pAxis->SetMinMax(dNewMinimum, dNewMaximum);
		}
	}
}

void CDuChartCtrl::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CChartDragLineCursorDu * pActiveCursor = (CChartDragLineCursorDu*)GetActiveCursorDu();
	if (nChar == VK_LEFT)
	{
		
		pActiveCursor->KeyLeft();
	}
	if (nChar == VK_RIGHT)
	{
		
		pActiveCursor->KeyRight();
	}
		Invalidate();
	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
	//RefreshCtrl();
}