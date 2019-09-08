#pragma once
#include "afxwin.h"
#include <vector>
#include "ProjectController.h"
#include "afxcmn.h"
#include "CherryTree.h"
#include "GridCtrl_src/GridCtrl.h"
#include "BaseProjectInfoView.h"
#include "CollectionParaPresetView.h"
#include "ChannelParaPresetView.h"
#include "StableStatusParaPresetView.h"
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

	BaseProjectInfoView m_baseProjectInfoView;
	CollectionParaPresetView m_collectionParaPresetView;
	ChannelParaPresetView m_channelParaPresetView;
	StableStatusParaPresetView m_stableStatusParaPresetView;

	DECLARE_MESSAGE_MAP()
	void InitProjectOperatorTree();
	vector<TbProduct> m_productVector;
	vector<CDialog*> m_pDialogVec;  //用来保存对话框对象指针
	int  m_icurSelTabIndex;
public:
	afx_msg void OnBnClickedOk();


	virtual BOOL OnInitDialog();
	ProjectController m_projectController;

	CGridCtrl m_projectOperatorDataGridCtrl;
	void GridCtrlInit();

	CCherryTree m_projectOperatorTreeCtrl;
	CTabCtrl m_projectNavigationTab;


	afx_msg void OnTcnSelchangeTabProjectnavigation(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButtonLaststep();
	afx_msg void OnBnClickedButtonNextstep();
};
