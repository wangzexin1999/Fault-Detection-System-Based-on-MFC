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
#include "CollectionPlanParaPresetView.h"
#include "TbProject.h"
#include "TbCollectionPlan.h"
#include "include/rapidjson/document.h"
#include "include/rapidjson/writer.h"
#include "include/rapidjson/stringbuffer.h"
#include "TbDictionary.h"
#include <iostream>
using namespace std;
using namespace rapidjson;

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

	TbProject m_project;
	BaseProjectInfoView m_baseProjectInfoView;
	CollectionParaPresetView m_collectionParaPresetView;
	ChannelParaPresetView m_channelParaPresetView;

	//CollectionPlanParaPresetView m_collectionPlanParaPresetView;
	int m_newDialogIndex;
	TbCollectionparas m_collectionparas;
	vector<TbChannel> m_vchannels;
	DECLARE_MESSAGE_MAP()
	vector<CDialog*> m_pDialogVec;  //用来保存对话框对象指针
	int  m_icurSelTabIndex;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	ProjectController m_projectController;
	CTabCtrl m_projectNavigationTab;
	afx_msg void OnTcnSelchangeTabProjectnavigation(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButtonLaststep();
	afx_msg void OnBnClickedButtonNextstep();

};
