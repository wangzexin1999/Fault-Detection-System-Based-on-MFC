/************************************************************************
Copyright (C), 2018-2020. ����������ѧ�˹�����ʵ����
�ļ����ƣ� EngineerUintView.h
����ժҪ�� ���̵�λ����.��Ҫʵ�ֹ��̵�λ��CRUD����Ӧ��ʵ�����ļ�ΪEngineerUintView.cpp��
����˵�����ɻ���ϻ�񶯼��ϵͳ
��ǰ�汾�� 1.0
�� �ߣ� ����
�������ڣ� 2019-05-24
�������:
History:
1. Date:    2018-05-24         Author:����
Modification:
�޸ļ�¼ 1�� // �޸���ʷ��¼�������޸����ڡ��޸��߼��޸�����
�޸����ڣ�
�� �� �ţ�
�� �� �ˣ�
�޸����ݣ�
************************************************************************/
#pragma once
#include "GridCtrl_src/GridCtrl.h"
#include "NewCellTypes/GridCellCheck.h"
#include "NewCellTypes/GridCellCombo.h"
#include "DictionaryController.h"
// CEngineerUnitView �Ի���

class CEngineerUnitView : public CDialogEx
{
	DECLARE_DYNAMIC(CEngineerUnitView)

public:
	CEngineerUnitView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEngineerUnitView();

// �Ի�������
	enum { IDD = IDD_DIALOG_ENGINEER_UINT };
public:
	CGridCtrl m_engineerUintManageGridCtrl;
	DictionaryController m_dictionController;
	vector<TbDictionary> m_vEngineerUint;
	TbDictionary m_selectedDictionary;
public:
	/**********************************************************************
	������������ʼ�����ؼ�
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void GridCtrlInit();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonEuAdd();
	afx_msg void OnBnClickedButtonEuDelete();
	afx_msg void OnBnClickedEuSave();
	afx_msg void OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult);
	afx_msg void OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult);
};
