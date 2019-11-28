
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
	���������� ����ʾ�ı��ؼ���ӵ�����
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸�����     �汾�� �޸��� �޸�����
	2019-11-27    1    ������ �½� 
	----------------------------------------------------------------------
	***********************************************************************/
	void AddPoints(SChartXYPoint* pPoints,unsigned Count);

	

	virtual void SetPoints(double* pX, double* pY, unsigned Count);

protected:
	// ʵʱ��������ͳ��ֵ
	void CalSamplingStatValue(double* pY, unsigned Count);
private:
	void DrawAll(CDC * pDC);
};
