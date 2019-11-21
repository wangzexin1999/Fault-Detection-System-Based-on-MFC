#pragma once
#include "ProjectController.h"
#include "TbProject.h"
#include "Result.h"
#include <vector>
#include "GridCtrl_src/GridCtrl.h"
#include "afxwin.h"
#include "afxdtctl.h"
#include "DateUtil.h"
// COpenProjectView �Ի���

class COpenProjectView : public CDialogEx
{
	DECLARE_DYNAMIC(COpenProjectView)

public:
	COpenProjectView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~COpenProjectView();

// �Ի�������
	enum { IDD = IDD_DIALOG_PROJECT_MANAGE };
	void GridCtrlInit();

protected:
	CGridCtrl m_projectGrid;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	vector<TbProject> m_projectVector;
	TbProject m_selectedProject;
	ProjectController m_projectController;
	DECLARE_MESSAGE_MAP()
public:
	
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedSearchbutton();
	afx_msg void OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult);
	afx_msg void OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult);
	CEdit m_proSearchNameEdit;
	CComboBox m_dateSelectComboBox;
};
