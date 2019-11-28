
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
	virtual void AddPoints(double* pX, double* pY, unsigned Count);

	/**********************************************************************
	功能描述： 给显示的表格控件添加点数据
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期     版本号 修改人 修改内容
	2019-11-27    1    马善涛 新建 
	----------------------------------------------------------------------
	***********************************************************************/
	void AddPoints(SChartXYPoint* pPoints,unsigned Count);

	

	virtual void SetPoints(double* pX, double* pY, unsigned Count);

protected:
	// 实时采样计算统计值
	void CalSamplingStatValue(double* pY, unsigned Count);
private:
	void DrawAll(CDC * pDC);
};
