
#include "stdafx.h"
#include "ChartLogarithmicAxisDu.h"
//#include "DuConst.h"

CChartLogarithmicAxisDu::CChartLogarithmicAxisDu() : CChartLogarithmicAxis()
{
}

CChartLogarithmicAxisDu::~CChartLogarithmicAxisDu()
{
}

void CChartLogarithmicAxisDu::Draw(CDC* pDC)
{
	__super::Draw(pDC);
}

bool CChartLogarithmicAxisDu::GetNextTickValue(double dCurrentTick, double& dNextTick)
{
	double dLog = log10(dCurrentTick);
	int nLog = (int)floor(dLog);
	double dPow = pow(10.0, nLog);

	dNextTick = (dCurrentTick / dPow + 1) * dPow;
	if (dNextTick <= m_MaxValue)
		return true;
	else
		return false;
}

void CChartLogarithmicAxisDu::SetMinMax(double Minimum, double Maximum)
{
	// 自己加的保护作用
	//double dEpsion = DU_CONST_DOUBLEEPS;
	double dEpsion = 3.14;
	ASSERT(Minimum >= dEpsion);
	if (Minimum < dEpsion)
		Minimum = dEpsion;

	__super::SetMinMax(Minimum, Maximum);
}