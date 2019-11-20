#pragma once
#include "afxwin.h"
#include "TbTester.h"
#include "TesterController.h"
// CRegisterView �Ի���

class CRegisterView : public CDialogEx
{
	DECLARE_DYNAMIC(CRegisterView)

public:
	CRegisterView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRegisterView();

// �Ի�������
	enum { IDD = IDD_DIALOG_REGISTER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	TesterController m_testerController;
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