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

	BaseProjectInfoView m_baseProjectInfoView;
	CollectionParaPresetView m_collectionParaPresetView;
	ChannelParaPresetView m_channelParaPresetView;
	StableStatusParaPresetView m_stableStatusParaPresetView;

	DECLARE_MESSAGE_MAP()
	void InitProjectOperatorTree();
	vector<TbProduct> m_productVector;
	vector<CDialog*> m_pDialogVec;  //��������Ի������ָ��
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
