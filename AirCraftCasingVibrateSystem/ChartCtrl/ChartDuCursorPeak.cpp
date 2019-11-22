
#include "stdafx.h"
#include "ChartDuCursorPeak.h"
#include "ChartCtrl.h"
#include "ChartXYSerie.h"
#include "ChartLineSerie.h"
#include "ChartLineSerieDu.h"

CChartDuCursorPeak::CChartDuCursorPeak(CChartCtrl* pParent,
										   CChartAxis* pRelatedAxis,  
										   CChartAxis* pRelatedYAxis)
 : CChartDragLineCursorDu(pParent, pRelatedAxis, pRelatedYAxis)
{

}

CChartDuCursorPeak::~CChartDuCursorPeak()
{
}

void CChartDuCursorPeak::AutoDingweiCursorPositionIndexInData()
{
	// ���ݵ���
	CChartLineSerieDu * pActiveSeries = (CChartLineSerieDu*)m_pParentCtrl->GetActiveSerieDu();
	if (NULL == pActiveSeries)
		return;

	m_lPositionIndexInData = pActiveSeries->m_nMaxPositionIndexInData;
	//SetPositionIndex(m_lPositionIndexInData);
	TRACE("\n��ǰ���λ��%d\n",m_lPositionIndexInData);
}