#pragma once
#include "afxcmn.h"
#include "CherryTree.h"

// CSignalSelectView 对话框

class CSignalSelectView : public CDialogEx
{
	DECLARE_DYNAMIC(CSignalSelectView)

public:
	CSignalSelectView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSignalSelectView();

// 对话框数据
	enum { IDD = IDD_DIALOG_SIGNAL_SELECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CCherryTree m_treeSignalSelect;
	virtual BOOL OnInitDialog();
	
	afx_msg void OnNMClickTreePath(NMHDR *pNMHDR, LRESULT *pResult);
};
