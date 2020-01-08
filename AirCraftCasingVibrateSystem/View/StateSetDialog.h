#pragma once
#include "GridCtrl_src/GridCtrl.h"
#include "include/rapidjson/document.h"
#include "include/rapidjson/writer.h"
#include "include/rapidjson/stringbuffer.h"
#include <iostream>
#include "afxwin.h"
#include "ProjectController.h"
#include "TbProject.h"
using namespace std;
using namespace rapidjson;
class CStateSetDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CStateSetDialog)

public:
	CStateSetDialog(CWnd* pParent = NULL);  
	virtual ~CStateSetDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG_STATE_SET };
	void GridCtrlInit();
	void ComboBoxInit();

protected:

	Document m_collectionPlanDoc;
	Document m_collectionPlanStatus;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	CGridCtrl m_collectionPlanGrid;
	DECLARE_MESSAGE_MAP()
	CComboBox m_collectionPlanCombo;

	TbProject m_project;
	ProjectController m_projectController;
public:
	/**********************************************************************
	���������� �������ѡ��ı��¼�
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnCbnSelchangeComboCollectionplan();
	virtual BOOL OnInitDialog();
	void RefreshView();
	CStatic m_staticCurrentPlanPara;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult);
};
