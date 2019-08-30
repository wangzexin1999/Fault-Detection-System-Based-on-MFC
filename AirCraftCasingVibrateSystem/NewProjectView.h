#pragma once
#include "afxwin.h"

#include "ProjectController.h"

// CNewProjectView �Ի���

class CNewProjectView : public CDialogEx
{
	DECLARE_DYNAMIC(CNewProjectView)

public:
	CNewProjectView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CNewProjectView();

// �Ի�������
	enum { IDD = IDD_DIALOG_New_PROJECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

	vector<TbProduct> m_productVector;

	vector<TbTestingDeviceDao> m_testingDeviceVector;

public:
	afx_msg void OnBnClickedOk();

	CComboBox m_testingDeviceCombo;
	CComboBox m_productCombo;

	virtual BOOL OnInitDialog();
	ProjectController m_projectController;
	CEdit m_projectNameEdit;

};
