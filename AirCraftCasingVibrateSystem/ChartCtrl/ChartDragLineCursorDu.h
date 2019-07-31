
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
	// 光标位置
	void SetPositionIndex(long nIndex) {m_lPositionIndexInData = nIndex;}
    long GetPositionIndex() {return m_lPositionIndexInData;}

	// 左右键
	void KeyLeft();
	void KeyRight();

public:
	// 自动定位光标位置
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
	// 曲线索引、数据索引、屏幕像素之间的转换
	int GetXScreenPixelFromSerieIndexAndXPosition(int nSerieIndex, int nPositionIndexInData);
	int GetXPositionFromSerieIndexAndXScreenPixel(int nSerieIndex, int nXScreenPixel);
	int GetYScreenPixelFromSerieIndexAndXPosition(int nSerieIndex, int nPositionIndexInData);

	// 保护光标位置
	void ProtectCursorPositionIndexInData();

protected:
	//! The axis to which this cursor is attached.
	CChartAxis* m_pRelatedYAxis;

	// 数据索引
	long m_lPositionIndexInData;

protected:
	int m_nPenStyle;
	int m_nWidth;
};
