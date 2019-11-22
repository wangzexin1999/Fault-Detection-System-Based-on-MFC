#pragma once
#include "ChartFont.h"
#include "DuExport.h"
#include <vector>
class  CDuChartCtrlShuxing
{
public:
	friend class CDuChartCtrl;

public:
	CDuChartCtrlShuxing(void);
	virtual ~CDuChartCtrlShuxing(void);

public:
	enum
	{
		CHARTCTRL_MAX_SERIE_COUNT = 16,		// ������߸���
	};

	enum ESerieType
	{
		typeSerieError = -1,
		typeSerieLine = 0,
		typeSerieBeipc,
	};

	enum EHebingOrFengkai
	{
		typeHebingOrFengkaiError = -1,
		typeHebing = 0,		// �ϲ���ʾ
		typeFengkai,		// �ֿ���ʾ
		typeGongyongXZhou,	// ����X��
	};

	enum ECursorType
	{
		typeCursorError = -1,
		typeCursorNone = 0,	// �޹��
		typeCursorSingle,	// �����
		typeCursorTwo,		// ˫���
		typeCursorPeak,		// ����
		typeCursorTrough,	// �ȹ��
		typeCursorXie,		// г���
		typeEnd,
	};

	enum EAxisType
	{
		typeAxisError = -1,
		typeAxisLine = 0,	// ��������
		typeAxisLog,		// ��������
		typeAxisBar,		// ��ͼ����
	};

	enum EXAxisZoomType
	{
		typeXZoomError = -1,
		typeXZoomCenter = 0,	// ����ʱ�м�̶�
		typeXZoomLeft,			// ����ʱ��߹̶�
	};

	enum EYAxisZoomType
	{
		typeYZoomError = -1,
		typeYZoomCenter = 0,	// ����ʱ�м�̶�
		typeYZoomBottom ,		// ����ʱ�±߹̶�
		typeYZoomZero ,			// ����ʱ��ֵ�̶�
	};
	
public:
	int m_nSerieType;					// ͼ������
	int m_nHebingOrFengkai;				// �ϲ����߷ֿ�
	int m_nFengkaiColumnCount;			// �ֿ�����
	int m_nCursorType;					// �������

public:
	COLORREF m_colTBKColor;				// ��Ϣ���򱳾���ɫ
	CChartFont m_chartFontTBKValue;		// ��Ϣ��������

	COLORREF m_colCursorColor1;			// ���1��ɫ
	COLORREF m_colCursorColor2;			// ���2��ɫ

	BOOL m_bDrawCursorValue;			// �Ƿ񻭹��ֵ
	BOOL m_bDrawLegend;					// �Ƿ�ͼ��
	BOOL m_bDrawStatValue;				// �Ƿ�ͳ��ֵ
	int m_nXieMaxCount;					// г���������
	BOOL m_bDrawStatMax;				// �Ƿ���ʾ���ֵ
	BOOL m_bDrawStatMin;				// �Ƿ���ʾ��Сֵ
	BOOL m_bDrawStatAve;				// �Ƿ���ʾƽ��ֵ
	BOOL m_bDrawStatPeak;				// �Ƿ���ʾ���ֵ
	BOOL m_bDrawStatStd;				// �Ƿ���ʾ��׼��
	BOOL m_bDrawStatRms;				// �Ƿ���ʾ��Чֵ
	BOOL m_bDrawStatSum;                // �Ƿ���ʾ��ֵ

	CRectTracker m_rectCursorValue;		// ���ֵ����
	CRectTracker m_rectLegend;			// ͼ������
	CRectTracker m_rectStatValue;		// ͳ��ֵ����

	// ������ɫ
	COLORREF m_colorSerie[CHARTCTRL_MAX_SERIE_COUNT];

	int m_nXZoomType;					// X����������
	int m_nYZoomType;					// Y����������

public:
	//! ��ͼ

	void DrawCursorValue(CDC * pDC);		// �����ֵ
	void DrawLegend(CDC * pDC);				// ��ͼ��
	void DrawStatValue(CDC * pDC);			// ��ͳ��ֵ
	void ClipCursorValueArea(CDC * pDC);	// ������ֵ����
	void ClipCursorValueAreaOne(CDC * pDC);	// ������ֵ���� - �����
	void ClipCursorValueAreaTwo(CDC * pDC);	// ������ֵ���� - ˫���
	void ClipCursorValueAreaXie(CDC * pDC);	// ������ֵ���� - г���
	void ClipLegendArea(CDC * pDC);			// ����ͼ������
	void ClipStatValueArea(CDC * pDC);		// ����ͳ��ֵ����
	void ProtectTrackerRect(CRectTracker * pTrackerRect, CRect * pRect);
	void DrawTrackerValue(CDC* pDC, CRectTracker * pTracker);
	void DrawLegendTrackerValue(CDC* pDC, CRectTracker * pTracker);

protected:
	class CChartCtrl * m_pParentCtrl;

	// ��Ϣ
	int m_nTrackerValueRowCount;			// ����
	int m_nTrackerValueColumnCount;			// ����
	int m_nTrackerValueColumnWidth[3];		// ���
	CString m_strTrackerValue[3][22];		// �ַ���
	COLORREF m_colorTrackerValue[3][22];	// ��ɫ

public:
	std::vector<CString> m_addDrawString;
};

