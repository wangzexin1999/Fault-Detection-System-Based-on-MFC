#pragma once
#include "ChartAxis.h"
#include "DuExport.h"
class  CChartAxisDu : public CChartAxis
{
public:
	CChartAxisDu(void);
	virtual ~CChartAxisDu(void);

public:
	int m_nDigits;	// С��λ��
};

