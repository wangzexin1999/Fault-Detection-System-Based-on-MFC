#pragma once
#include "GridCtrl_src/GridCtrl.h"
#include "include/rapidjson/document.h"
#include "include/rapidjson/writer.h"
#include "include/rapidjson/stringbuffer.h"
#include <iostream>
#include "afxwin.h"
using namespace std;
using namespace rapidjson;
// CStateSetDialog 对话框

class CStateSetDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CStateSetDialog)

public:
	CStateSetDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStateSetDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG_STATE_SET };
	void GridCtrlInit();
	void ComboBoxInit();

protected:

	Document m_collectionPlanDoc;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	CGridCtrl m_collectionPlanGrid;
	DECLARE_MESSAGE_MAP()
	CComboBox m_collectionPlanCombo;
public:
	/**********************************************************************
	功能描述： 下拉框的选项改变事件
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnCbnSelchangeComboCollectionplan();
	virtual BOOL OnInitDialog();
	void RefreshView();
	CStatic m_staticCurrentPlanPara;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult);
};
