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
// CSignalDataView �Ի���

class CSignalDataView : public CDialogEx
{
	DECLARE_DYNAMIC(CSignalDataView)

public:
	CSignalDataView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSignalDataView();
	
// �Ի�������
	enum { IDD = IDD_DIALOG_OPEN_DATA };
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
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
	�����������õ�ѡ�еĲ�������
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
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
