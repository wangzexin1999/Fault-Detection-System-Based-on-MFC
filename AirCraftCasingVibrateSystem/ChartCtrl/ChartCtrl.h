/*
 *
 *	ChartCtrl.h
 *
 *	Written by C閐ric Moonen (cedric_moonen@hotmail.com)
 *
 *
 *
 *	This code may be used for any non-commercial and commercial purposes in a compiled form.
 *	The code may be redistributed as long as it remains unmodified and providing that the 
 *	author name and this disclaimer remain intact. The sources can be modified WITH the author 
 *	consent only.
 *	
 *	This code is provided without any garanties. I cannot be held responsible for the damage or
 *	the loss of time it causes. Use it at your own risks
 *
 *	An e-mail to notify me that you are using this code is appreciated also.
 *
 *
 */


#pragma once

#include "ChartSerie.h"
#include "ChartAxis.h"
#include "ChartGrid.h"
#include "ChartLegend.h"
#include "ChartTitle.h"
#include "ChartGradient.h"
#include "ChartCursor.h"
#include "ChartMouseListener.h"
#include "ChartStandardAxis.h"
#include "ChartLogarithmicAxis.h"
#include "ChartDateTimeAxis.h"
#include "ChartCrossHairCursor.h"
#include "ChartDragLineCursor.h"
	
#include <map>
#include "DuExport.h"
#include "DuChartCtrlShuxing.h"


class CChartStandardAxis;
class CChartLogarithmicAxis;
class CChartDateTimeAxis;
class CChartLogarithmicAxisDu;
class CChartBarAxisDu;

class CChartCrossHairCursor;
class CChartDragLineCursor;
class CChartDragLineCursorDu;
class CChartDuCursorXie;
class CChartDuCursorPeak;
class CChartDuCursorTrough;

class CChartPointsSerie;
class CChartLineSerie;
class CChartSurfaceSerie;
class CChartBarSerie;
class CChartCandlestickSerie;
class CChartGanttSerie;
class CChartXYSerie;
class CChartLineSerieDu;
class CChartBarSerieDu;
class CChartXYSerieDu;

/////////////////////////////////////////////////////////////////////////////
// CChartCtrl window

//! The main chart control class.
/**

**/
class  CChartCtrl : public CWnd
{

public:
	//! Retrieves de device context.
	/**
		This function is used for internal purposes only.
	**/
	CDC* GetDC();
	//! Retrieves the plotting rectangle.
	CRect GetPlottingRect()  const { return m_PlottingRect; }
	//! 自己添加的
	virtual CRect GetPlottingRectFromSerieIndexDu(int nIndex)  const = 0;
	virtual	int GetPlottingGraphCount() = 0;
	virtual int GetPlottingGraphIndexFromPoint(CPoint pt) = 0;

	//! Returns a pointer to the legend object.
	CChartLegend* GetLegend() const  { return m_pLegend; }
	//! Returns a pointer to the title object.
	CChartTitle*  GetTitle()  const  { return m_pTitles; }

	//! An enumeration of the different axis positions.
	enum EAxisPos
	{
		LeftAxis = 0,
		BottomAxis,
		RightAxis,
		TopAxis
	};

	//! Create and attach a standard axis to the control.
	CChartStandardAxis* CreateStandardAxis(EAxisPos axisPos);
	//! Create and attach a logarithmic axis to the control.
	CChartLogarithmicAxis* CreateLogarithmicAxis(EAxisPos axisPos);
	//! Create and attach a date/time axis to the control.
	CChartDateTimeAxis* CreateDateTimeAxis(EAxisPos axisPos);
	//! Attach a custom axis to the control.
	void AttachCustomAxis(CChartAxis* pAxis, EAxisPos axisPos);
	//! 自己添加的
	virtual void RemoveAllAxisDu() = 0;
	virtual void CreateAxisDu() = 0;
	virtual CChartStandardAxisDu * CreateStandardAxisDu(EAxisPos axisPos, int nIndex) = 0;
	virtual CChartLogarithmicAxisDu* CreateLogarithmicAxisDu(EAxisPos axisPos, int nIndex) = 0;
	virtual CChartBarAxisDu* CreateBarAxisDu(EAxisPos axisPos, int nIndex) = 0;
	virtual void AttachCustomAxisDu(CChartAxis * pAxis, EAxisPos axisPos, int nIndex) = 0;
	virtual CChartAxis* GetAxisDu(EAxisPos axisPos, int nIndex) = 0;
	virtual int GetSerieIndexFromAxisPtrDu(CChartAxis * pAxis) = 0;

	//! Create and attach a point series to the control
	CChartPointsSerie* CreatePointsSerie(bool bSecondaryHorizAxis=false, bool bSecondaryVertAxis=false);
	//! Create and attach a line series to the control
	CChartLineSerie* CreateLineSerie(bool bSecondaryHorizAxis=false, bool bSecondaryVertAxis=false);
	//! Create and attach a surface series to the control
	CChartSurfaceSerie* CreateSurfaceSerie(bool bSecondaryHorizAxis=false, bool bSecondaryVertAxis=false);
	//! Create and attach a bar series to the control
	CChartBarSerie* CreateBarSerie(bool bSecondaryHorizAxis=false, bool bSecondaryVertAxis=false);
	//! Create and attach a candlestick series to the control
	CChartCandlestickSerie* CreateCandlestickSerie(bool bSecondaryHorizAxis=false, bool bSecondaryVertAxis=false);
	//! Create and attach a gantt series to the control
	CChartGanttSerie* CreateGanttSerie(bool bSecondaryHorizAxis=false, bool bSecondaryVertAxis=false);
	//! Attaches a custom series to the chart
	void AttachCustomSerie(CChartSerie* pNewSeries, bool bSecondaryHorizAxis=false, bool bSecondaryVertAxis=false);
	//! Retrieves a specific series from the chart
	CChartSerie* GetSerie(unsigned uSerieId) const;
	//! Removes a specific series from the chart
	void RemoveSerie(unsigned uSerieId);
	//! Removes all the series from the chart
	void RemoveAllSeries();
	//! Returns the number of series in the chart
	size_t GetSeriesCount() const;
	//! 自己添加的
	virtual void CreateSeriesDu(int nSerieCount, int nSerieType) = 0;
	virtual CChartLineSerieDu * CreateLineSerieDu(int nIndex, bool bSecondaryHorizAxis=false, bool bSecondaryVertAxis=false) = 0;
	virtual CChartBarSerieDu * CreateBarSerieDu(int nIndex, bool bSecondaryHorizAxis=false, bool bSecondaryVertAxis=false) = 0;
	virtual CChartSerie * GetActiveSerieDu() = 0;
	virtual CChartSerie * GetSerieFromIndexDu(int nIndex) = 0;
	virtual void SetActiveSerieIndexDu(int nIndex) = 0;
	virtual void AttachCustomSerieDu(CChartXYSerie * pNewSeries, int nSerieIndex, bool bSecondaryHorizAxis=false, bool bSecondaryVertAxis=false) = 0;

	//! Create and attach a cross-hair cursor to the control
	CChartCrossHairCursor* CreateCrossHairCursor(bool bSecondaryHorizAxis=false, bool bSecondaryVertAxis=false);
	//! Create and attach a drag-line cursor to the control
	CChartDragLineCursor* CreateDragLineCursor(EAxisPos relatedAxis);
	//! Attach a custom cursor to the control
	void AttachCustomCursor(CChartCursor* pCursor);
	//! Removes a cursor with a specific Id from the control.
	void RemoveCursor(unsigned cursorId);
	//! 自己添加的
	virtual CChartDragLineCursorDu * CreateDragLineCursorDu() = 0;
	virtual CChartDuCursorXie * CreateDuCursorXie() = 0;
	virtual CChartDuCursorPeak * CreateDuCursorPeak() = 0;
	virtual CChartDuCursorTrough * CreateDuCursorTrough() = 0;
	virtual void RemoveAllCursorDu() = 0;
	virtual size_t GetCursorCountDu() = 0;
	virtual void SetActiveCursorIndexDu(int nIndex) = 0;
	virtual CChartCursor * GetActiveCursorDu() = 0;
	virtual CChartCursor * GetCursorDu(unsigned uCursorId) = 0;
	virtual CChartCursor * GetCursorFromIndexDu(int nIndex) = 0;

	//! Shows/hides the mouse cursor when it is over the plotting area.
	void ShowMouseCursor(bool bShow);

	CChartAxis* GetBottomAxis() const;
	CChartAxis* GetLeftAxis() const;
	CChartAxis* GetTopAxis() const;
	CChartAxis* GetRightAxis() const;
	//! Returns a specific axis attached to the control
	CChartAxis* GetAxis(EAxisPos axisPos) const {return m_pAxes[axisPos];}

	//! Returns the type of the edge used as border.
	UINT GetEdgeType() const        { return EdgeType;    }
	//! Sets the edge type.
	void SetEdgeType(UINT NewEdge)  
	{ 
		EdgeType = NewEdge; 
		RefreshCtrl();
	}

	//! Returns the background color
	COLORREF GetBackColor() const			{ return m_BackColor;   }
	//! Sets the background color.
	void SetBackColor(COLORREF NewCol)		
	{ 
		m_BackColor = NewCol;  
		m_bBackGradient = false; 
		RefreshCtrl();
	}
	//! Returns the color of the plotting area's border 
	COLORREF GetBorderColor() const			{ return m_BorderColor;   }
	//! Sets the color of the plotting area's border 
	void SetBorderColor(COLORREF NewCol)	{ m_BorderColor = NewCol;	RefreshCtrl(); }
	//! Returns the color of the zoom rectangle
	COLORREF GetZoomRectColor() const		{ return m_ZoomRectColor;   }
	//! Sets the color of the zoom rectangle
	void SetZoomRectColor(COLORREF NewCol)	{ m_ZoomRectColor = NewCol; RefreshCtrl(); }
	//! Sets a gradient background
	void SetBackGradient(COLORREF Col1, COLORREF Col2, EGradientType GradientType);

	//! Enables/disables the pan feature
	void SetPanEnabled(bool bEnabled)  { m_bPanEnabled = bEnabled;  }
	//! Returns true if the pan feature is enabled
	bool GetPanEnabled() const		   { return m_bPanEnabled;	    }
	//! Enables/disables the zoom feature
	void SetZoomEnabled(bool bEnabled) { m_bZoomEnabled = bEnabled; }
	//! Returns true if the zoom feature is enabled
	bool GetZoomEnabled() const		   { return m_bZoomEnabled;	    }
	//! Undo all pan and zoom operations that were done on the chart
	void UndoPanZoom();

	//! Forces a refresh of the control.
	virtual void RefreshCtrl();
	//! Enables/disables the refresh of the control
	void EnableRefresh(bool bEnable);
	//! Creates the control dynamically.
	int Create(CWnd* pParentWnd, const RECT& rect, UINT nID, DWORD dwStyle=WS_VISIBLE);
	
	//! Helper function to convert a date to a double value
	static double DateToValue(const COleDateTime& Date);
	//! Helper function to convert a double value to a date
	static COleDateTime ValueToDate(double Value);

	//! Print the chart
    virtual void Print(const TChartString& strTitle, CPrintDialog* pPrntDialog = NULL);

#if _MFC_VER > 0x0600
	//! Saves the chart to an image file
	void SaveAsImage(const TChartString& strFilename, const CRect& rect, 
			int nBPP, REFGUID guidFileType= GUID_NULL);
#endif

	//! Default constructor
    CChartCtrl();	
	//! Default destructor
    virtual ~CChartCtrl();

	//! Register a mouse listener with the control.
	void RegisterMouseListener(CChartMouseListener* pMouseListener) { m_pMouseListener = pMouseListener;}

	//! Tell the control to set the current series to the first series.
	void GoToFirstSerie();
	//! Returns the next series in the control.
	CChartSerie* GetNextSerie();

	//! Refreshes all the axes which are automatic for the screen.
	void RefreshScreenAutoAxes();

	// Generated message map functions
protected:
	//{{AFX_MSG(CChartCtrl)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	
protected:
    virtual void OnBeginPrinting(CDC *pDC, CPrintInfo *pInfo);
    virtual void OnPrint(CDC *pDC, CPrintInfo *pInfo);
    virtual void OnEndPrinting(CDC *pDC, CPrintInfo *pInfo);

	// This function can be called to draw the chart
	// on the screen or for printing.
	virtual void DrawChart(CDC* pDC, CRect ChartRect);
	virtual void DrawBackground(CDC* pDC, CRect ChartRect);

protected:
	//! Register the window class used for this control
	bool RegisterWindowClass();

	//! Notifies the mouse listeners about a mouse event on the control.
	void SendMouseEvent(CChartMouseListener::MouseEvent mouseEvent, const CPoint& screenPoint) const;

	//! Specifies if the refresh is currently enabled or not.
	int m_iEnableRefresh ;
	//! Specifies if there is a pending refresh. 
	bool m_bPendingRefresh;
	//! Memory bitmap on which the chart background is drawn (axis, grid, title, ...)
	CDC m_BackgroundDC;	
	//! Specifies if the memory bitmap has already been created.
	bool m_bMemDCCreated;

	//! Specifies if the background is gradient or solid
	bool m_bBackGradient;	
	//! First gradient color for the background
	COLORREF m_BackGradientCol1;
	//! Second gradient color for the background
	COLORREF m_BackGradientCol2;
	//! The gradient type used for the background
	EGradientType m_BackGradientType;
	//! The background color (if no gradient used)
	COLORREF m_BackColor;	
	//! The border color
	COLORREF m_BorderColor;
	//! The type of edge
	UINT EdgeType;		

	//! Zone in wich the series will be plotted
	CRect m_PlottingRect;
	CRect m_FengkaiPlottingRect[CDuChartCtrlShuxing::CHARTCTRL_MAX_SERIE_COUNT];

	typedef std::map<unsigned, CChartSerie*> TSeriesMap;
	//! Map containing all the series added to the chart.
	TSeriesMap m_mapSeries;	
	//! The four axis of the control.
	CChartAxis* m_pAxes[4 * CDuChartCtrlShuxing::CHARTCTRL_MAX_SERIE_COUNT];

	//! The chart legend
	CChartLegend* m_pLegend;	
	//! The chart titles
	CChartTitle*  m_pTitles;	

	//! Specifies if the mouse panning is enabled
	bool m_bPanEnabled;
	//! Specifies if the right mouse button is currently pressed
	bool m_bRMouseDown;		
	//! The point on which the panning started
	CPoint m_PanAnchor;

	//! Specifies if the zoom is enabled
	bool  m_bZoomEnabled;
	//! Specifies if the left mouse button is currently pressed
	bool  m_bLMouseDown;
	//! The rectangle of the zoom area
	CRect m_rectZoomArea;
	//! The color of the zoom rectangle
	COLORREF m_ZoomRectColor;

	//! Specifies if the toolbars have already been created
	bool m_bToolBarCreated;

	//! The font used for printing
    CFont  m_PrinterFont;  
	//! Page size in chartctrl units.
    CSize m_LogicalPageSize;     
	//! Page size in device units.
    CSize m_PaperSize;    

	typedef std::map<unsigned, CChartCursor*> TCursorMap;
	//! The map containing all the cursors
	TCursorMap m_mapCursors;

	//! The mouse listener registered with this control
	CChartMouseListener* m_pMouseListener;

	//! Specifies if the mouse is visible when over the plotting area.
	bool m_bMouseVisible;

	typedef TSeriesMap::const_iterator TSeriesMapIter;
	//! The iterator of the current series
	TSeriesMapIter m_currentSeries;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

