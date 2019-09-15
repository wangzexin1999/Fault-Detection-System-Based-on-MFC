#pragma once
#include "afxwin.h"


// CFontView 对话框

class CFontView : public CDialogEx
{
	DECLARE_DYNAMIC(CFontView)
public:
	LOGFONT *m_lFontXCoor;
	LOGFONT *m_lFontYCoor;
	LOGFONT *m_lFontXUnit;
	LOGFONT *m_lFontYUnit;
	LOGFONT *m_lFontCursorValue;
	LOGFONT *m_lFontStaValue;
	LOGFONT *m_lFontLegend;
public:
	CFontView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFontView();

// 对话框数据
	enum { IDD = IDD_DIALOG_FONT };
public:
	CFontDialog m_fontDlg;
	/*CFontDialog m_yCoorFontDlg;
	CFontDialog m_cursorValueFontDlg;
	CFontDialog m_xUnitFontDlg;
	CFontDialog m_yUnitFontDlg;
	CFontDialog m_cursorMarkFontDlg;
	CFontDialog m_textNoteFontDlg;
	CFontDialog m_projectInfFontDlg;*/
public:
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CButton m_xCoor;
	CButton m_yCoor;
	CButton m_cursorValue;
	CButton m_xUnit;
	CButton m_yUnit;
	CButton m_cursorMark;
	CButton m_statisticInf;
	CButton m_textNote;
	CButton m_projectInf;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonXcoor();
	afx_msg void OnBnClickedButtonYcoor();
	afx_msg void OnBnClickedButtonCursorValue();
	afx_msg void OnBnClickedButtonXUnit();
	afx_msg void OnBnClickedButtonYUnit();
	afx_msg void OnBnClickedButtonCursorMark();
	afx_msg void OnBnClickedButtonStatistisInf();
	afx_msg void OnBnClickedButtonTextInf();
	afx_msg void OnBnClickedButtonProjectInf();
};
