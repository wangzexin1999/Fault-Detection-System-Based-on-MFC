#pragma once
#include "afxcmn.h"
#include "CherryTree.h"

// CSignalSelectView �Ի���

class CSignalSelectView : public CDialogEx
{
	DECLARE_DYNAMIC(CSignalSelectView)

public:
	CSignalSelectView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSignalSelectView();

// �Ի�������
	enum { IDD = IDD_DIALOG_SIGNAL_SELECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CCherryTree m_treeSignalSelect;
	virtual BOOL OnInitDialog();
	
	afx_msg void OnNMClickTreePath(NMHDR *pNMHDR, LRESULT *pResult);
};
