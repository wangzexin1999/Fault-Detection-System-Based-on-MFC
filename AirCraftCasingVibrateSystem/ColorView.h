#pragma once
#include "afxbutton.h"


// CColorView 对话框

class CColorView : public CDialogEx
{
	DECLARE_DYNAMIC(CColorView)

public:
	CColorView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CColorView();

// 对话框数据
	enum { IDD = IDD_DIALOG_CORLOR };
public:
	COLORREF m_colSerie[4];					 // 曲线颜色
	COLORREF m_colBKColor;                    // 背景颜色
	COLORREF m_colGBKColor;                   // 图形区背景颜色
	COLORREF m_colTBKColor;                   // 信息窗背景颜色
	COLORREF m_colGridLineColor;              // 网格线颜色
	COLORREF m_colCoorColor;                  // 坐标轴颜色
	COLORREF m_colCursor1;                    // 光标1颜色
	COLORREF m_colCursor2;                    // 光标2颜色
	COLORREF m_colScale;						// 刻度颜色
	COLORREF m_colXCoor;						// X坐标颜色
	COLORREF m_colYCoor;						// Y坐标颜色
	COLORREF m_colStatisticInf;               // 统计信息颜色
	CString m_color = "color";
public:
	/**********************************************************************
	 功能描述： 颜色控件
	 输入参数： 
	 输出参数： 
	 返 回 值： 颜色
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	 ----------------------------------------------------------------------
	 ***********************************************************************/
	COLORREF  GetColorDiag();
	/**********************************************************************
	 功能描述： 设置按钮背景
	 输入参数：btn--按钮，color--颜色
	 输出参数： 
	 返 回 值：void 
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void SetMFCButtonColor(CMFCButton & btn, COLORREF color);
	/**********************************************************************
	 功能描述： 初始化成员属性
	 输入参数：
	 输出参数： 
	 返 回 值： 
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void InitAttri();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CMFCButton m_windowBGColor;
	CMFCButton m_graphBGColor;
	CMFCButton m_infWinBGColor;
	CMFCButton m_series1Color;
	CMFCButton m_series2Color;
	CMFCButton m_series3Color;
	CMFCButton m_series4Color;
	CMFCButton m_gridColor;
	CMFCButton m_coordinateColor;
	CMFCButton m_scaleColor;
	CMFCButton m_cursorColor;
	CMFCButton m_xAxisColor;
	CMFCButton m_yAxisColor;
	CMFCButton m_statisticsInfColor;
	afx_msg void OnBnClickedMfcbuttonWinBg();
	afx_msg void OnBnClickedMfcbuttonGraphBg();
	afx_msg void OnBnClickedMfcbuttonInfBg();
	afx_msg void OnBnClickedMfcbuttonSeris1Bg();
	afx_msg void OnBnClickedMfcbuttonSeris2Bg();
	afx_msg void OnBnClickedMfcbuttonSeris33Bg();
	afx_msg void OnBnClickedMfcbuttonSeris4Bg();
	afx_msg void OnBnClickedMfcbuttonGridBg();
	afx_msg void OnBnClickedMfcbuttonCoorBg();
	afx_msg void OnBnClickedMfcbuttonScaleBg();
	afx_msg void OnBnClickedMfcbuttonCurlorBg();
	afx_msg void OnBnClickedMfcbuttonXBg();
	afx_msg void OnBnClickedMfcbuttonYBg();
	afx_msg void OnBnClickedMfcbuttonStatiscBg();
	virtual BOOL OnInitDialog();
};
