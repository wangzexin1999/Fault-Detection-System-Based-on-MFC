
#pragma once

#include "ChartAxis.h"
#include "ChartAxisDu.h"
#include "ChartStandardAxis.h"
#include "DuExport.h"

//! Specialization of a CChartAxis class to display standard values.
class  CChartStandardAxisDu : public CChartStandardAxis
{
	friend CChartCtrl;
	friend class CDuChartCtrl;

protected:
	//! Default constructor
	CChartStandardAxisDu();
	//! Default destructor
	virtual ~CChartStandardAxisDu();

protected:
	virtual void Draw(CDC* pDC);
};
