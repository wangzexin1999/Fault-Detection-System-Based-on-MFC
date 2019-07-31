
#include "stdafx.h"
#include "ChartDuCursorTrough.h"
#include "ChartCtrl.h"
#include "ChartXYSerie.h"
#include "ChartLineSerie.h"
#include "ChartLineSerieDu.h"

CChartDuCursorTrough::CChartDuCursorTrough(CChartCtrl* pParent,
										   CChartAxis* pRelatedAxis,  
										   CChartAxis* pRelatedYAxis)
 : CChartDragLineCursorDu(pParent, pRelatedAxis, pRelatedYAxis)
{

}

CChartDuCursorTrough::~CChartDuCursorTrough()
{
}

void CChartDuCursorTrough::AutoDingweiCursorPositionIndexInData()
{
	// 数据点数
	CChartLineSerieDu * pActiveSeries = (CChartLineSerieDu*)m_pParentCtrl->GetActiveSerieDu();
	if (NULL == pActiveSeries)
		return;

	m_lPositionIndexInData = pActiveSeries->m_nMinPositionIndexInData;
}