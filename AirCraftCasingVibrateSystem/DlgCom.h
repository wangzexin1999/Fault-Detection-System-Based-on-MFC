#pragma once
#include "CDHTestHardWare.h"

// CDlgCom 对话框

class CDlgCom : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgCom)

public:
	CDlgCom(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgCom();

// 对话框数据
	enum { IDD = IDD_DIALOG_COM };
public:
	CDHTestHardWare m_DHHardWare;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
