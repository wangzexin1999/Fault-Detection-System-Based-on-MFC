/************************************************************************
Copyright (C), 2018-2020. ����������ѧ�˹�����ʵ����
�ļ����ƣ� LoginView.h
����ժҪ�� ��¼����.��Ӧ��ʵ�����ļ�ΪLoginView.cpp��
����˵�����ɻ���ϻ�񶯼��ϵͳ
��ǰ�汾�� 1.0
�� �ߣ� ����
�������ڣ� 2019-05-24
�������:
History:
1. Date:    2018-05-24         Author:����
Modification:
�޸ļ�¼ 1�� // �޸���ʷ��¼�������޸����ڡ��޸��߼��޸�����
�޸����ڣ�
�� �� �ţ�
�� �� �ˣ�
�޸����ݣ�
************************************************************************/
#pragma once
#include "RegisterView.h"
#include "TesterController.h"
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
	TesterController m_TbTesterControler;
public:
	afx_msg void OnBnClickedOk();
	CEdit m_loginNameEdit;
	CEdit m_passWordEdit;

	afx_msg void OnClose();
	afx_msg void OnBnClickedButtonLoginviewRegister();
};
