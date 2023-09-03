
#pragma once

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChartXYSerie.h"
#include "ChartLineSerie.h"
#include "DuExport.h"
#include "ChartXYSerieDu.h"

class  CChartLineSerieDu : public CChartLineSerie
{
	friend class CChartDuCursorPeak;
	friend class CChartDuCursorTrough;
	friend class CDuChartCtrlShuxing;

public:
	CChartLineSerieDu(CChartCtrl* pParent);
	virtual ~CChartLineSerieDu();

public:
	virtual void SetNeedCalStatValue(BOOL b) {m_bNeedCalStatValue = b;}
public:
	virtual void DrawDu();

	/**********************************************************************
	功能描述： 给显示的表格控件添加点数据
	***********************************************************************/
	void AddPoints(SChartXYPoint* pPoints,unsigned Count);
	double GetMax();
	double GetSum();
	virtual void SetPoints(SChartXYPoint* pPoints, unsigned Count);

protected:
	// 实时采样计算统计值
	void CalSamplingStatValue(SChartXYPoint* pPoints, unsigned Count);
private:
	void DrawAll(CDC * pDC);
};
