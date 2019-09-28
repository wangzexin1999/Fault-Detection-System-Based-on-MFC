#pragma once
#include "GridCtrl_src/GridCtrl.h"
#include "afxwin.h"
#include "afxdtctl.h"
#include<vector>
#include "TbRecordSignal.h"
#include "SignalController.h"
#include "Result.h"
#include "DateUtil.h"
#include "DictionaryController.h"
#include "ProductController.h"
#include "include/rapidjson/document.h"
#include "include/rapidjson/writer.h"
#include "include/rapidjson/stringbuffer.h"
#include "ProjectController.h"
using namespace std;
using namespace rapidjson;
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
	vector<TbRecordSignal> m_signalVector;
	SignalController m_signalController;
	TbRecordSignal m_selectedSignal;
	DictionaryController m_dictionaryController;
	vector<TbDictionary> m_collectionPlanVec;
	ProductController m_productController;
	vector<TbProduct> m_productVector;
	vector<TbProject> m_projectVector;
	ProjectController m_projectController;
	TbRecordSignal m_searchSignalEntity;
	CComboBox m_productNameCombo;
	CComboBox m_projectNameCombo;
	CComboBox m_planNameCombo;
	vector<CString> m_recordSignalGridTitle;
	vector<CString> m_planParaTitle;
	
	CString GetCollectionParaKeyWords();

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
	void GridCtrlPlanParaInit(const Value& planParaTitle);
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult);
	afx_msg void OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedSearchButton();
	
	
	afx_msg void OnCbnSelchangeComboProductName();
	afx_msg void OnCbnSelchangeComboProjectName();
	afx_msg void OnCbnSelchangeComboPlanName();
	afx_msg void OnCbnSelchangeDateCombo();
};
