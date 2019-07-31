
#pragma once

#include "ChartAxis.h"
#include "ChartAxisDu.h"
#include "ChartStandardAxis.h"
#include "DuExport.h"
#include "ChartStandardAxisDu.h"


//! Specialization of a CChartAxis class to display standard values.
class  CChartBarAxisDu : public CChartStandardAxisDu
{
	friend CChartCtrl;
	friend class CDuChartCtrl;

private:
	//! Default constructor
	CChartBarAxisDu();
	//! Default destructor
	virtual ~CChartBarAxisDu();

public:
	void SetString(CString * p, int nCount);
	TChartString GetTickLabel(double TickValue);

protected:
	void RefreshTickIncrement();
	void RefreshFirstTick();
	bool GetNextTickValue(double dCurrentTick, double& dNextTick);

protected:
	//CDuSmartArrayObject<CString> m_smtString;
};
