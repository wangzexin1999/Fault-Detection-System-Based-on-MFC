
#pragma once
#include "ChartXYSerie.h"
#include "ChartGradient.h"
#include <list>
#include "DuExport.h"
#include "ChartBarSerie.h"
#include "ChartXYSerieDu.h"
#include "ChartLineSerieDu.h"

class  CChartBarSerieDu : public CChartLineSerieDu
{
public:
	//! Constructor
	CChartBarSerieDu(CChartCtrl* pParent);
	//! Destructor
	~CChartBarSerieDu();
private:
	void DrawAll(CDC *pDC);
};
