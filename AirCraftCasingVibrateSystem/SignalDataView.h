#pragma once
#include "GridCtrl_src/GridCtrl.h"
#include "afxwin.h"
#include "afxdtctl.h"
#include<vector>
#include "TbSignal.h"
#include "SignalController.h"
#include "Result.h"
#include "DateUtil.h"
using namespace std;
// CSignalDataView 对话框

class CSignalDataView : public CDialogEx
{
	DECLARE_DYNAMIC(CSignalDataView)

public:
	CSignalDataView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSignalDataView();
	
// 对话框数据
	enum { IDD = IDD_DIALOG_OPEN_DATA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	CGridCtrl m_signalDataGridCtrl;
	CGridCtrl m_planParaGridCtrl;
	void GridCtrlInit();
	DECLARE_MESSAGE_MAP()
	CComboBox m_dateSelectComboBox;
	vector<TbSignal> m_signalVector;
	SignalController m_signalController;
	TbSignal m_selectedSignal;
public:
	/**********************************************************************
	 功能描述：初始化计划参数界面 
	 输入参数：
	 输出参数： 
	 返 回 值： 
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void GridCtrlPlanParaInit();
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult);
	afx_msg void OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedSearchButton();
	
	CComboBox m_comboxProductName;
	CComboBox m_combocProjectName;
	CComboBox m_comboxPlanName;
};
