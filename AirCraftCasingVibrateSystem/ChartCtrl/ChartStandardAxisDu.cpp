
#include "stdafx.h"
#include "ChartStandardAxisDu.h"
#include "ChartCtrl.h"
#include <sstream>
#include <iostream>
#include <iomanip>
#include <math.h>
#include "DuChartCtrl.h"

using namespace std;

CChartStandardAxisDu::CChartStandardAxisDu()
 : CChartStandardAxis()
{
}

CChartStandardAxisDu::~CChartStandardAxisDu()
{
}

void CChartStandardAxisDu::Draw(CDC* pDC)
{
	__super::Draw(pDC);
}