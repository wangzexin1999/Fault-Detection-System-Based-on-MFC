/************************************************************************
文件名称： LoginView.h
内容摘要： 登录界面.对应的实现类文件为LoginView.cpp。

************************************************************************/
#pragma once
//#include "RegisterView.h"
#include "UserController.h"
#include "afxwin.h"

// CLoginView 对话框

class CLoginView : public CDialogEx
{
	DECLARE_DYNAMIC(CLoginView)

public:
	CLoginView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLoginView();

// 对话框数据
	enum { IDD = IDD_DIALOG_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP();
	UserController m_TbUserControler;
public:
	afx_msg void OnBnClickedOk();
	CEdit m_loginNameEdit;
	CEdit m_passWordEdit;

	afx_msg void OnClose();
	afx_msg void OnBnClickedButtonLoginviewRegister();
};
