#pragma once
#include "afxwin.h"
#include "TbUser.h"
#include "UserController.h"
// CRegisterView 对话框

class CRegisterView : public CDialogEx
{
	DECLARE_DYNAMIC(CRegisterView)

public:
	CRegisterView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRegisterView();

// 对话框数据
	enum { IDD = IDD_DIALOG_REGISTER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	UserController m_userController;
public:
	virtual BOOL OnInitDialog();
	CEdit m_editRegisterLoginName;
	CEdit m_editRegidterPost;
	CEdit m_editRegisterTell;
	CEdit m_editRegisterName;
	CEdit m_editRegisterPSW;
	CEdit m_editRegisterQPSW;
	afx_msg void OnBnClickedRegister();
};
