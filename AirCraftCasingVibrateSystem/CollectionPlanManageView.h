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

// CollectionPlanManageView �Ի���

class CollectionPlanManageView : public CDialogEx
{
	DECLARE_DYNAMIC(CollectionPlanManageView)

public:
	CollectionPlanManageView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CollectionPlanManageView();

// �Ի�������
	enum { IDD = IDD_DIALOG_COLLECTIONPLANMANAGE };
	void CollectionPlanBaseInfoGridCtrlInit();
	/**********************************************************************
	�����������ɼ��ƻ����������б��ʼ����
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void CollectionPlanParaInfoGridCtrlInit();
	/**********************************************************************
	�����������ɼ�״̬������Ϣ���ĵ����¼�
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnCollectionPlanBaseInfoGridClick(NMHDR *pNotifyStruct, LRESULT* pResult);
	/**********************************************************************
	�����������ɼ�״̬������Ϣ����˫���¼���˫�����ÿ��޸���Ϣ
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnCollectionPlanBaseInfoGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult);
	/**********************************************************************
	�����������ɼ�״̬������Ϣ���ĵ����¼�
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnCollectionPlanParaInfoGridClick(NMHDR *pNotifyStruct, LRESULT* pResult);
	/**********************************************************************
	�����������ɼ�״̬������Ϣ����˫���¼���˫�����ÿ��޸���Ϣ
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnCollectionPlanParaInfoGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
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
