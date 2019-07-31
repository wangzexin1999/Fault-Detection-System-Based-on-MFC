
#include "stdafx.h"
#include "ChartXYSerieDu.h"
#include "DuChartCtrl.h"
#include "ChartBarAxisDu.h"

CChartXYSerieDu::CChartXYSerieDu(CChartCtrl* pParent) : CChartXYSerie(pParent)
{
	m_nMaxPositionIndexInData = 0;
	m_nMinPositionIndexInData = 0;
	m_dMaxData = 0;
	m_dMinData = 0;

	m_bNeedCalStatValue = FALSE;
	m_dStatMaxValue = 0;
	m_dStatMinValue = 0;
	m_dStatAveValue = 0;
	m_dStatPeakValue = 0;
	m_dStatStdValue = 0;
	m_dStatRmsValue = 0;
}

CChartXYSerieDu::~CChartXYSerieDu()
{
}

void CChartXYSerieDu::GetMinMax(double & dMin, double & dMax)
{
	dMin = m_dMinData;
	dMax = m_dMaxData;
}

CString CChartXYSerieDu::GetExportXPointValue(int nIndex)
{
	CDuChartCtrl * pDuChartCtrl = (CDuChartCtrl*)m_pParentCtrl;
	CChartAxisDu * pHorAxisDu = (CChartAxisDu*)m_pHorizontalAxis;

	int nSerieType = pDuChartCtrl->m_shuxing.m_nSerieType;
	CString strXValue;

	switch (nSerieType)
	{
	case CDuChartCtrlShuxing::typeSerieLine:
		{
			TCHAR tchar[16] = {0};
			_stprintf_s(tchar, TEXT("%%.%df"), pHorAxisDu->m_nDigits);
			double dXValue = GetXPointValue(nIndex);
			strXValue.Format(tchar, dXValue);
		}
		break;
	case CDuChartCtrlShuxing::typeSerieBeipc:
		{
			double dXValue = GetXPointValue(nIndex);
			CChartBarAxisDu * pBarHorAxisDu = (CChartBarAxisDu*)m_pHorizontalAxis;
			strXValue = pBarHorAxisDu->GetTickLabel(dXValue).c_str();
		}
		break;
	default: {ASSERT(FALSE);}
	}
	return strXValue;
}