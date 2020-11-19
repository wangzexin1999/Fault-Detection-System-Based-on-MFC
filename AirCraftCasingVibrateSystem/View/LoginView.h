/************************************************************************
�ļ����ƣ� LoginView.h
����ժҪ�� ��¼����.��Ӧ��ʵ�����ļ�ΪLoginView.cpp��

************************************************************************/
#pragma once
//#include "RegisterView.h"
#include "UserController.h"
#include "afxwin.h"

// CLoginView �Ի���

class CLoginView : public CDialogEx
{
	DECLARE_DYNAMIC(CLoginView)

public:
	CLoginView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLoginView();

// �Ի�������
	enum { IDD = IDD_DIALOG_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP();
	UserController m_TbUserControler;
public:
	afx_msg void OnBnClickedOk();
	CEdit m_loginNameEdit;
	CEdit m_passWordEdit;

	afx_msg void OnClose();
	afx_msg void OnBnClickedButtonLoginviewRegister();
};
