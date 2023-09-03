
#pragma once

#include "ChartSerie.h"
#include "ChartAxis.h"
#include "ChartGrid.h"
#include "ChartLegend.h"
#include "ChartTitle.h"
#include "ChartGradient.h"
#include "ChartCursor.h"
#include "ChartMouseListener.h"
#include "ChartStandardAxis.h"
#include "ChartLogarithmicAxis.h"
#include "ChartDateTimeAxis.h"
#include "ChartCrossHairCursor.h"
#include "ChartDragLineCursor.h"
	
#include <map>
#include "DuChartCtrlShuxing.h"
#include "DuExport.h"

#include "TbChannel.h"

#define ID_NEW_EDIT 4001
class  CDuChartCtrl : public CChartCtrl
{
public:
	//! Default constructor
    CDuChartCtrl();	
	//! Default destructor
    virtual ~CDuChartCtrl();

public:
	//! ����ͼ������
	virtual CRect GetPlottingRectFromSerieIndexDu(int nIndex)  const;
	virtual int GetPlottingGraphCount();
	virtual int GetPlottingGraphIndexFromPoint(CPoint pt);

	//! ��ͼ
	virtual void RefreshCtrl();
	virtual void DrawChart(CDC* pDC, CRect ChartRect);

	//! ������
	virtual void RemoveAllAxisDu();
	virtual void CreateAxisDu();
	virtual void CreateAxisDu(int nSerieCount, int nXAxisType, int nYAxisType);
	virtual CChartStandardAxisDu * CreateStandardAxisDu(EAxisPos axisPos, int nIndex);
	virtual CChartLogarithmicAxisDu * CreateLogarithmicAxisDu(EAxisPos axisPos, int nIndex);
	virtual CChartBarAxisDu* CreateBarAxisDu(EAxisPos axisPos, int nIndex);
	virtual void AttachCustomAxisDu(CChartAxis* pAxis, EAxisPos axisPos, int nIndex);
	virtual CChartAxis* GetAxisDu(EAxisPos axisPos, int nIndex);
	virtual int GetSerieIndexFromAxisPtrDu(CChartAxis * pAxis);

	//! ����
	virtual void CreateSeriesDu(int nSerieCount, int nSerieType);
	virtual CChartLineSerieDu * CreateLineSerieDu(int nIndex, bool bSecondaryHorizAxis=false, bool bSecondaryVertAxis=false);
	virtual CChartBarSerieDu * CreateBarSerieDu(int nIndex, bool bSecondaryHorizAxis=false, bool bSecondaryVertAxis=false);
	virtual CChartSerie * GetActiveSerieDu();
	virtual CChartSerie * GetSerieFromIndexDu(int nIndex);
	virtual void SetActiveSerieIndexDu(int nIndex);
	virtual void AttachCustomSerieDu(CChartXYSerie* pNewSeries, int nSerieIndex, bool bSecondaryHorizAxis=false, bool bSecondaryVertAxis=false);

	//! ���
	virtual CChartDragLineCursorDu * CreateDragLineCursorDu();
	virtual CChartDuCursorXie * CreateDuCursorXie();
	virtual CChartDuCursorPeak * CreateDuCursorPeak();
	virtual CChartDuCursorTrough * CreateDuCursorTrough();
	virtual void RemoveAllCursorDu();
	virtual size_t GetCursorCountDu();
	virtual void SetActiveCursorIndexDu(int nIndex);
	virtual CChartCursor * GetActiveCursorDu();
	virtual CChartCursor * GetCursorDu(unsigned uCursorId);
	virtual CChartCursor * GetCursorFromIndexDu(int nIndex);

	// �Զ��̶�
	virtual void AutoXScale(BOOL bRefresh);
	virtual void AutoYScale(BOOL bRefresh);

	// ͼ������
	CDuChartCtrlShuxing m_shuxing;

	// �Ƿ񻭺���
	BOOL m_bDrawHengxian;
	int m_nDrawHengxianCount;
	float m_fHengxianValueX[128];
	float m_fHengxianValueY[128];

public:
	// ����
	virtual void SetCursorNone(BOOL bRefresh);		// �޹��
	virtual void SetCursorSingle(BOOL bRefresh);	// �����
	virtual void SetCursorTwo(BOOL bRefresh);		// ˫���
	virtual void SetCursorPeak(BOOL bRefresh);		// ����
	virtual void SetCursorTrough(BOOL bRefresh);	// �ȹ��
	virtual void SetCursorXie(BOOL bRefresh);		// г���
	virtual void KeyUpOrDown(int nUpOrDown);		// ���¼�
	virtual void KeyLeftOrRight(int nLeftOrRight);	// ���Ҽ�

	virtual void HengxiangFangda();					// ����Ŵ�
	virtual void HengxiangSuoxiao();				// ������С
	virtual void ZongxiangFangda();					// ����Ŵ�
	virtual void ZongxiangSuoxiao();				// ������С

protected:
	// �����ID������
	unsigned m_uActiveSerieID;
	unsigned m_uActiveSerieIndex;
	// ����ID
	unsigned m_uActiveCursorID;
public:
	// ͼ����������ɫ
	COLORREF m_GraphBKColor;

	// Generated message map functions
protected:
	//{{AFX_MSG(CDuChartCtrl)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnEdit();
	CEdit	p_MyEdit;

	BOOL PreTranslateMessage(MSG* pMsg);
protected:
	//! Register the window class used for this control
	bool RegisterWindowClass();

	// �Ƿ񵥻���Ϣ����
	bool LButtonDownRectTracker(CPoint & point);
	bool MouseMoveRectTracker(CPoint & point);
	bool LButtonUpRectTracker(CPoint & point);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

