
#pragma once

#include "ChartAxis.h"
#include "DuExport.h"
#include "ChartLogarithmicAxis.h"

class  CChartLogarithmicAxisDu : public CChartLogarithmicAxis
{
public:
	//! Constructor
	CChartLogarithmicAxisDu();
	//! Destructor
	virtual ~CChartLogarithmicAxisDu();

private:
	virtual void SetMinMax(double Minimum, double Maximum);
	virtual bool GetNextTickValue(double dCurrentTick, double& dNextTick);
	virtual void Draw(CDC* pDC);
};
