
#pragma once

#include "ChartDragLineCursor.h"
#include "DuExport.h"

class CChartAxis;
class CDuChartCtrlShuxing;

class  CChartDragLineCursorDu : public CChartDragLineCursor
{
	friend CChartCtrl;
	friend CDuChartCtrl;
	friend CDuChartCtrlShuxing;

public:
	//! Constructor
	CChartDragLineCursorDu(CChartCtrl* pParent, CChartAxis* pRelatedAxis, CChartAxis* pRelatedYAxis);
	//! Destructor
	virtual ~CChartDragLineCursorDu();

public:
	// ���λ��
	void SetPositionIndex(long nIndex) {m_lPositionIndexInData = nIndex;}
    long GetPositionIndex() {return m_lPositionIndexInData;}

	// ���Ҽ�
	void KeyLeft();
	void KeyRight();

public:
	// �Զ���λ���λ��
	virtual void AutoDingweiCursorPositionIndexInData() {}

protected:
	//! Called when the mouse is moved over the plot area.
	virtual void OnMouseMove(CPoint mousePoint);
	//! Called when the mouse button is pressed over the plot area.
	virtual void OnMouseButtonDown(CPoint mousePoint);
	//! Called when the mouse button is released over the plot area.
	virtual void OnMouseButtonUp(CPoint mousePoint);

	//! Draw the cursor.
	virtual void Draw(CDC* pDC);

protected:
	// ����������������������Ļ����֮���ת��
	int GetXScreenPixelFromSerieIndexAndXPosition(int nSerieIndex, int nPositionIndexInData);
	int GetXPositionFromSerieIndexAndXScreenPixel(int nSerieIndex, int nXScreenPixel);
	int GetYScreenPixelFromSerieIndexAndXPosition(int nSerieIndex, int nPositionIndexInData);

	// �������λ��
	void ProtectCursorPositionIndexInData();

protected:
	//! The axis to which this cursor is attached.
	CChartAxis* m_pRelatedYAxis;

	// ��������
	long m_lPositionIndexInData;

protected:
	int m_nPenStyle;
	int m_nWidth;
};
