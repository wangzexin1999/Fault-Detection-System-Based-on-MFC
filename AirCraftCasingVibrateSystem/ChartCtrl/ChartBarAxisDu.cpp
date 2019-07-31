
#include "stdafx.h"
#include "ChartBarAxisDu.h"
#include "ChartCtrl.h"
#include <sstream>
#include <iostream>
#include <iomanip>
#include <math.h>
#include "DuChartCtrl.h"

using namespace std;

CChartBarAxisDu::CChartBarAxisDu() : CChartStandardAxisDu()
{
}

CChartBarAxisDu::~CChartBarAxisDu()
{
}

TChartString CChartBarAxisDu::GetTickLabel(double TickValue)
{
	/*int n = static_cast<int>(TickValue);
	CString * pString = m_smtString.GetBuffer();
	int nBufferSize = m_smtString.GetBufferElementSize();*/
	TChartString tc;
	/*if (n >= 0 && n <= nBufferSize - 1)
		tc = pString[n];*/
	return tc;
}

void CChartBarAxisDu::SetString(CString * p, int nCount)
{
	/*m_smtString.CreateBuffer(nCount);
	CString * pString = m_smtString.GetBuffer();
	for (int i=0; i<nCount; i++)
		pString[i] = p[i];*/
}

void CChartBarAxisDu::RefreshTickIncrement()
{
	m_dTickIncrement = 1;
	SetDecimals(0);
}

void CChartBarAxisDu::RefreshFirstTick()
{
	m_dFirstTickValue = 0;
}

bool CChartBarAxisDu::GetNextTickValue(double dCurrentTick, double& dNextTick)
{
	/*int nBufferSize = m_smtString.GetBufferElementSize();
	if (dCurrentTick >= nBufferSize - 1)
		return false;*/
	return __super::GetNextTickValue(dCurrentTick, dNextTick);
}