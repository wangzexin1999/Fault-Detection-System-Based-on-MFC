#pragma once
#include "GridCtrl_src/GridCtrl.h"
#include "include/rapidjson/document.h"
#include "include/rapidjson/writer.h"
#include "include/rapidjson/stringbuffer.h"
#include <iostream>
#include "afxwin.h"
using namespace std;
using namespace rapidjson;
// CStateSetDialog �Ի���

class CStateSetDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CStateSetDialog)

public:
	CStateSetDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStateSetDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG_STATE_SET };
	void GridCtrlInit();
	void ComboBoxInit();

protected:

	Document m_collectionPlanDoc;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	CGridCtrl m_collectionPlanGrid;
	DECLARE_MESSAGE_MAP()
	CComboBox m_collectionPlanCombo;
public:
	afx_msg void OnCbnSelchangeComboCollectionplan();
	virtual BOOL OnInitDialog();
	void RefreshView();
};
