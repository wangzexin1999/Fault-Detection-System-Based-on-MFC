#include "StdAfx.h"
#include "DuChartCtrlStaticFunction.h"
#include "ChartCtrl.h"
#include "DuChartCtrl.h"
#include "ChartDuCursorPeak.h"
#include "ChartDuCursorTrough.h"
#include "ChartDuCursorXie.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDuChartCtrlStaticFunction::CDuChartCtrlStaticFunction(void)
{
}

CDuChartCtrlStaticFunction::~CDuChartCtrlStaticFunction(void)
{
}

void CDuChartCtrlStaticFunction::SetCursorNone(class CDuChartCtrl * pDuChartCtrl, BOOL bRefresh)
{
	pDuChartCtrl->SetCursorNone(bRefresh);
}

void CDuChartCtrlStaticFunction::SetCursorSingle(class CDuChartCtrl * pDuChartCtrl, BOOL bRefresh)
{
	pDuChartCtrl->SetCursorSingle(bRefresh);
}

void CDuChartCtrlStaticFunction::SetCursorTwo(class CDuChartCtrl * pDuChartCtrl, BOOL bRefresh)
{
	pDuChartCtrl->SetCursorTwo(bRefresh);
}

void CDuChartCtrlStaticFunction::SetCursorPeak(class CDuChartCtrl * pDuChartCtrl, BOOL bRefresh)
{
	pDuChartCtrl->SetCursorPeak(bRefresh);
}

void CDuChartCtrlStaticFunction::SetCursorTrough(class CDuChartCtrl * pDuChartCtrl, BOOL bRefresh)
{
	pDuChartCtrl->SetCursorTrough(bRefresh);
}

void CDuChartCtrlStaticFunction::SetCursorXie(class CDuChartCtrl * pDuChartCtrl, BOOL bRefresh)
{
	pDuChartCtrl->SetCursorXie(bRefresh);
}

void CDuChartCtrlStaticFunction::CreateAxis(class CDuChartCtrl * pDuChartCtrl, int nSerieCount, 
	int nXAxisType, int nYAxisType)
{
	pDuChartCtrl->CreateAxisDu(nSerieCount, nXAxisType, nYAxisType);
}

void CDuChartCtrlStaticFunction::RemoveAll(class CDuChartCtrl * pDuChartCtrl)
{
	pDuChartCtrl->RemoveAllCursorDu();
	pDuChartCtrl->RemoveAllSeries();
	pDuChartCtrl->RemoveAllAxisDu();
	pDuChartCtrl->GetTitle()->RemoveAll();
}

void CDuChartCtrlStaticFunction::KeyUp(class CDuChartCtrl * pDuChartCtrl)
{
	pDuChartCtrl->KeyUpOrDown(0);
}

void CDuChartCtrlStaticFunction::KeyDown(class CDuChartCtrl * pDuChartCtrl)
{
	pDuChartCtrl->KeyUpOrDown(1);
}

void CDuChartCtrlStaticFunction::KeyLeft(class CDuChartCtrl * pDuChartCtrl)
{
	pDuChartCtrl->KeyLeftOrRight(0);
}

void CDuChartCtrlStaticFunction::KeyRight(class CDuChartCtrl * pDuChartCtrl)
{
	pDuChartCtrl->KeyLeftOrRight(1);
}

void CDuChartCtrlStaticFunction::CreateSeries(class CDuChartCtrl * pDuChartCtrl, int nSerieCount, int nSerieType)
{
	pDuChartCtrl->CreateSeriesDu(nSerieCount, nSerieType);
}

void CDuChartCtrlStaticFunction::AutoXScale(class CDuChartCtrl * pDuChartCtrl, BOOL bRefresh)
{
	pDuChartCtrl->AutoXScale(bRefresh);
}

void CDuChartCtrlStaticFunction::AutoYScale(class CDuChartCtrl * pDuChartCtrl, BOOL bRefresh)
{
	pDuChartCtrl->AutoYScale(bRefresh);
}

void CDuChartCtrlStaticFunction::HengxiangFangda(class CDuChartCtrl * pDuChartCtrl)
{
	pDuChartCtrl->HengxiangFangda();
}

void CDuChartCtrlStaticFunction::HengxiangSuoxiao(class CDuChartCtrl * pDuChartCtrl)
{
	pDuChartCtrl->HengxiangSuoxiao();
}

void CDuChartCtrlStaticFunction::ZongxiangFangda(class CDuChartCtrl * pDuChartCtrl)
{
	pDuChartCtrl->ZongxiangFangda();
}

void CDuChartCtrlStaticFunction::ZongxiangSuoxiao(class CDuChartCtrl * pDuChartCtrl)
{
	pDuChartCtrl->ZongxiangSuoxiao();
}

// void CDuChartCtrlStaticFunction::SetHebingOrFenkai(class CDuChartCtrl * pDuChartCtrl, int n)
// {
//     pDuChartCtrl->m_shuxing.m_nHebingOrFengkai = n;
// }
