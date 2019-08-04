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
	CEdit m_singnalDataNameCtrl;
	CDateTimeCtrl m_signalDataStartTimeCtrl;
	CDateTimeCtrl m_signalDataEndTimeCtrl;
	vector<TbSignal> m_signalVector;
	SignalController m_signalController;
	TbSignal m_selectedSignal;

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult);
	afx_msg void OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedSearchButton();
	CButton m_dateSelectCheckBox;
};
