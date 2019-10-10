#pragma once
#include "GridCtrl_src/GridCtrl.h"
#include "NewCellTypes/GridCellCheck.h"
#include "include/rapidjson/document.h"
#include "include/rapidjson/writer.h"
#include "include/rapidjson/stringbuffer.h"
#include "TbDictionary.h"
#include <iostream>
#include "ProductController.h"
#include "CollectionPlanController.h"
#include <vector>
#include "afxwin.h"
#include "TbProject.h"

using namespace std;
using namespace rapidjson;

// CollectionPlanManageView 对话框

class CollectionPlanManageView : public CDialogEx
{
	DECLARE_DYNAMIC(CollectionPlanManageView)

public:
	CollectionPlanManageView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CollectionPlanManageView();

// 对话框数据
	enum { IDD = IDD_DIALOG_COLLECTIONPLANMANAGE };
	void CollectionPlanBaseInfoGridCtrlInit();
	/**********************************************************************
	功能描述：采集计划基本参数列表初始化。
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void CollectionPlanParaInfoGridCtrlInit();
	/**********************************************************************
	功能描述：采集状态基本信息表格的单击事件
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnCollectionPlanBaseInfoGridClick(NMHDR *pNotifyStruct, LRESULT* pResult);
	/**********************************************************************
	功能描述：采集状态基本信息表格的双击事件，双击设置可修改信息
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnCollectionPlanBaseInfoGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult);
	/**********************************************************************
	功能描述：采集状态参数信息表格的单击事件
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnCollectionPlanParaInfoGridClick(NMHDR *pNotifyStruct, LRESULT* pResult);
	/**********************************************************************
	功能描述：采集状态基本信息表格的双击事件，双击设置可修改信息
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnCollectionPlanParaInfoGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	vector<TbDictionary> m_vcollectionPlan;
	CGridCtrl m_collectionPlanBaseInfoGridCtrl;
	CGridCtrl m_collectionPlanParaInfoGridCtrl;
	CollectionPlanController m_collectionPlanController;
	int m_selectedPlanIndex;
	int m_selectedPlanParaIndex;
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonAddPlanBaseInfo();
	afx_msg void OnBnClickedButtonDelPlanBaseInfo();
	afx_msg void OnBnClickedButtonSavePlanBaseInfo();
	afx_msg void OnBnClickedButtonAddPlanParaRow();
	afx_msg void OnBnClickedButtonDelPlanParaRow();
	afx_msg void OnBnClickedButtonAddPlanParaCol();
	afx_msg void OnBnClickedButtonSavePlanPara();
};
