#pragma once
#include "GridCtrl_src/GridCtrl.h"
#include "NewCellTypes/GridCellCheck.h"
#include "include/rapidjson/document.h"
#include "include/rapidjson/writer.h"
#include "include/rapidjson/stringbuffer.h"
#include "TbCollectionPlan.h"
#include "TbDictionary.h"
#include <iostream>
using namespace std;
using namespace rapidjson;
// CollectionPlanParaPresetView �Ի���

class CollectionPlanParaPresetView : public CDialogEx
{
	DECLARE_DYNAMIC(CollectionPlanParaPresetView)

public:
	CollectionPlanParaPresetView(TbDictionary collectionPlan,CWnd* pParent = NULL);   // ��׼���캯��
	CollectionPlanParaPresetView(CWnd* pParent = NULL);
	virtual ~CollectionPlanParaPresetView();

// �Ի�������
	enum { IDD = IDD_DIALOG_STABLESTATUSPRESET };
	/**********************************************************************
	�����������õ��ɼ��ƻ�
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void GetCollectionPlan(TbCollectionPlan &collectionPlan);

protected:

	TbDictionary m_collectionPlan; ///�ɼ��ƻ�����

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	CGridCtrl m_stableStatusGridCtrl;
	void GridCtrlInit();
	DECLARE_MESSAGE_MAP()

	/**********************************************************************
	����������ת�ٵȲ������ĵ����¼�
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult);

	/**********************************************************************
	�������������ñ���еĶ�ѡ���ѡ��״̬
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void SetGridCellCheck(int row, int col, bool isChecked);
	afx_msg void OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult);

	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonAdd();

	
};
