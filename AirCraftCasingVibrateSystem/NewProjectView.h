#pragma once
#include "afxwin.h"

#include "ProjectController.h"

// CNewProjectView 对话框

class CNewProjectView : public CDialogEx
{
	DECLARE_DYNAMIC(CNewProjectView)

public:
	CNewProjectView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CNewProjectView();

// 对话框数据
	enum { IDD = IDD_DIALOG_New_PROJECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

	vector<TbDetectedDeviceDao> m_detectedDeviceVector;

	vector<TbTestingDeviceDao> m_testingDeviceVector;

public:
	afx_msg void OnBnClickedOk();

	CComboBox m_testingDeviceCombo;
	CComboBox m_detectedDeviceCombo;

	virtual BOOL OnInitDialog();
	ProjectController m_projectController;
	CEdit m_projectNameEdit;

};
