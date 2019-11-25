#pragma once
#include "DuExport.h"
#include "DuChartCtrlShuxing.h"
class  CDuChartCtrlStaticFunction
{
public:
	CDuChartCtrlStaticFunction(void);
	virtual ~CDuChartCtrlStaticFunction(void);

public:
	// �������
	static void RemoveAll(class CDuChartCtrl * pDuChartCtrl);

    // ���úϲ���ʾ��ֿ���ʾ
    static void SetHebingOrFenkai(class CDuChartCtrl * pDuChartCtrl, int n) {}

	// ����������
	static void CreateAxis(class CDuChartCtrl * pDuChartCtrl, int nSerieCount, 
		int nXAxisType = CDuChartCtrlShuxing::typeAxisLine, 
		int nYAxisType = CDuChartCtrlShuxing::typeAxisLine);

	// ��������
	static void CreateSeries(class CDuChartCtrl * pDuChartCtrl, int nSerieCount, int nSerieType);

	// �޹��
	static void SetCursorNone(class CDuChartCtrl * pDuChartCtrl, BOOL bRefresh = FALSE);
	// �����
	static void SetCursorSingle(class CDuChartCtrl * pDuChartCtrl, BOOL bRefresh = FALSE);
	// ˫���
	static void SetCursorTwo(class CDuChartCtrl * pDuChartCtrl, BOOL bRefresh = FALSE);
	// ����
	static void SetCursorPeak(class CDuChartCtrl * pDuChartCtrl, BOOL bRefresh = FALSE);
	// �ȹ��
	static void SetCursorTrough(class CDuChartCtrl * pDuChartCtrl, BOOL bRefresh = FALSE);
	// г���
	static void SetCursorXie(class CDuChartCtrl * pDuChartCtrl, BOOL bRefresh = FALSE);

	// ����
	static void KeyUp(class CDuChartCtrl * pDuChartCtrl);
	// ����
	static void KeyDown(class CDuChartCtrl * pDuChartCtrl);
	// ����
	static void KeyLeft(class CDuChartCtrl * pDuChartCtrl);
	// ����
	static void KeyRight(class CDuChartCtrl * pDuChartCtrl);

	// �Զ��̶�
	static void AutoXScale(class CDuChartCtrl * pDuChartCtrl, BOOL bRefresh);
	static void AutoYScale(class CDuChartCtrl * pDuChartCtrl, BOOL bRefresh);

	// ����Ŵ�
	static void HengxiangFangda(class CDuChartCtrl * pDuChartCtrl);
	static void HengxiangSuoxiao(class CDuChartCtrl * pDuChartCtrl);
	static void ZongxiangFangda(class CDuChartCtrl * pDuChartCtrl);
	static void ZongxiangSuoxiao(class CDuChartCtrl * pDuChartCtrl);
	
};

