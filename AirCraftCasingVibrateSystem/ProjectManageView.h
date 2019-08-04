#pragma once
#include "ProjectController.h"
#include "TbProject.h"
#include "Result.h"
#include <vector>
#include "GridCtrl_src/GridCtrl.h"
#include "afxwin.h"
#include "afxdtctl.h"
#include "DateUtil.h"
// CProjectManageView 对话框

class CProjectManageView : public CDialogEx
{
	DECLARE_DYNAMIC(CProjectManageView)

public:
	CProjectManageView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CProjectManageView();

// 对话框数据
	enum { IDD = IDD_DIALOG_PROJECT_MANAGE };
	void GridCtrlInit();

protected:
	CGridCtrl m_projectGrid;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
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
	CButton m_dateSelectCheckBox;
	CDateTimeCtrl m_proStartTimeCtrl;
	CDateTimeCtrl m_proEndTimeCtrl;
};
