#pragma once
#include "ColorView.h"
#include "FontView.h"
#include "LineView.h"
#include "SelectView.h"
#include "CoordinateView.h"
#include "afxcmn.h"
#include "afxwin.h"

// CGraphAttributeView 对话框

class CGraphAttributeView : public CDialogEx
{
	DECLARE_DYNAMIC(CGraphAttributeView)

public:
	CGraphAttributeView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CGraphAttributeView();

// 对话框数据
	enum { IDD = IDD_DIALOG_GRAPH_ATRR };
public:
	CColorView	m_colorView;
	CFontView	m_fontView;
	CLineView	m_lineView;
	CSelectView	m_selectView;
	CCoordinateView	m_coordinateView;
	CDialog* pDialog[5];  //用来保存对话框对象指针
	int m_CurSelTab;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tabGraphAttribute;
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeTabGraphAttr(NMHDR *pNMHDR, LRESULT *pResult);
	CButton m_appAllWinodw;
};
