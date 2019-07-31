
#pragma once

#include "ChartDragLineCursor.h"
#include "ChartDragLineCursorDu.h"
#include "DuExport.h"

class CChartAxis;

class  CChartDuCursorPeak : public CChartDragLineCursorDu
{
	friend CChartCtrl;
	friend CDuChartCtrl;
	friend class CDuChartCtrlShuxing;

public:
	//! Constructor
	CChartDuCursorPeak(CChartCtrl* pParent, CChartAxis* pRelatedAxis, CChartAxis* pRelatedYAxis);
	//! Destructor
	virtual ~CChartDuCursorPeak();

public:
	// 自动定位光标位置
	virtual void AutoDingweiCursorPositionIndexInData();

protected:
	//! Called when the mouse button is pressed over the plot area.
	virtual void OnMouseButtonDown(CPoint mousePoint) {}
};
