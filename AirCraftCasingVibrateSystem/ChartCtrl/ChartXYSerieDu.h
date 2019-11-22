
#pragma once
#include "ChartSerieBase.h"
#include "DuExport.h"
#include "ChartXYSerie.h"

class  CChartXYSerieDu : public CChartXYSerie
{
public:
	//! Constructor
	CChartXYSerieDu(CChartCtrl* pParent);
	//! Destructor
	virtual ~CChartXYSerieDu();

public:
	virtual void GetMinMax(double & dMin, double & dMax);

	virtual CString GetExportXPointValue(int nIndex);

protected:
	// ���ֵ��Сֵ
	int m_nMaxPositionIndexInData;
	int m_nMinPositionIndexInData;
	double m_dMaxData;
	double m_dMinData;

	// �Ƿ���Ҫ����ͳ��ֵ
	BOOL m_bNeedCalStatValue;
	double m_dStatMaxValue;
	double m_dStatMinValue;
	double m_dStatAveValue;
	double m_dStatPeakValue;
	double m_dStatStdValue;
	double m_dStatRmsValue;
	double m_dStatSumValue;
};
