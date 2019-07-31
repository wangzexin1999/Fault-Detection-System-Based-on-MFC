
#pragma once

#include "ChartDragLineCursor.h"
#include "ChartDragLineCursorDu.h"
#include "DuExport.h"

class CChartAxis;

class  CChartDuCursorXie : public CChartDragLineCursorDu
{
	friend CChartCtrl;
	friend CDuChartCtrl;
	friend class CDuChartCtrlShuxing;

public:
	//! Constructor
	CChartDuCursorXie(CChartCtrl* pParent, CChartAxis* pRelatedAxis, CChartAxis* pRelatedYAxis);
	//! Destructor
	virtual ~CChartDuCursorXie();

public:
	//! Draw the cursor.
	virtual void Draw(CDC* pDC);
};
