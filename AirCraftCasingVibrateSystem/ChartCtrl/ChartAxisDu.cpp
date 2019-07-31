#include "StdAfx.h"
#include "ChartAxisDu.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CChartAxisDu::CChartAxisDu(void)
{
	m_strFontName = _T("Microsoft Sans Serif");
	m_nFontSize = 90;

	//////////////////////////////////////////////////////////////////////////

	m_nDigits = 5;
}

CChartAxisDu::~CChartAxisDu(void)
{
}
