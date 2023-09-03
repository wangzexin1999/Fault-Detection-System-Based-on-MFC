#pragma once
#include "GridCtrl_src/GridCtrl.h"
#include "afxwin.h"
#include "afxdtctl.h"
#include<vector>
#include "TbSumsignal.h"
#include "Result.h"
#include "DateUtil.h"
#include "DictionaryController.h"
#include "ProductController.h"
#include "ProjectController.h"
#include "SignalController.h"

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
	void GridCtrlInit();
	DECLARE_MESSAGE_MAP()
	CComboBox m_dateSelectComboBox;
	vector<TbSumsignal> m_signalVector;
	TbSumsignal m_selectedSignal;
	DictionaryController m_dictionaryController;
	vector<TbDictionary> m_vcollectionPlan;
	ProductController m_productController;
	vector<TbProduct> m_productVector;
	vector<TbProject> m_projectVector;
	ProjectController m_projectController;
	CComboBox m_productNameCombo;
	vector<CString> m_recordSignalGridTitle;
	vector<CString> m_planParaTitle;

	SignalController m_signalController;
	TbSumsignal m_searchSignalEntity;

public:
	/**********************************************************************
	功能描述：得到选中的采样数据
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	TbSumsignal GetSelectedSumSignal();

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult);
	afx_msg void OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedSearchButton();
	
	
	afx_msg void OnCbnSelchangeComboProductName();
	afx_msg void OnCbnSelchangeDateCombo();
};
