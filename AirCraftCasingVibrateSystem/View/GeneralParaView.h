/************************************************************************
Copyright (C), 2018-2020. ����������ѧ�˹�����ʵ����
�ļ����ƣ� GeneralParaView.h
����ժҪ�� ͨ�ò�������.��Ҫʵ��ͨ�ò�����ʾ��ͨ�ò������á���Ӧ��ʵ�����ļ�ΪGeneralParaView.cpp��
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
#include "afxcmn.h"
#include "GridCtrl_src/GridCtrl.h"
#include "ChannelParaController.h"
#include "NewCellTypes/GridCellCheck.h"
#include "NewCellTypes/GridCellCombo.h"
#include "DictionaryController.h"
#include <vector>
#include "AdvantechDaqController.h"
using namespace  std;
// CGeneralParaView �Ի���

class CGeneralParaView : public CDialogEx
{
	DECLARE_DYNAMIC(CGeneralParaView)

public:
	CGeneralParaView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CGeneralParaView();

	// �Ի�������
	enum { IDD = IDD_DIALOG_GENERAL_PARA };
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	CGridCtrl m_generalParaGridCtrl;

	DictionaryController m_dictionController;
	vector<TbDictionary> m_vwindowTypes;  // ������
	vector<TbDictionary> m_vinputMethods; // ���뷽ʽ
	AdvantechDaqController m_advantechDaqController; // Ӳ��������
	vector<vector<int>>  m_measuringRange;

	DECLARE_MESSAGE_MAP()
	ChannelParaController m_channelParaController;
public:
	virtual BOOL OnInitDialog();
	/**********************************************************************
	����������ͨ����������˫���¼���˫�����ÿ��޸���Ϣ
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnGridEndEdit(NMHDR *pNotifyStruct, LRESULT* pResult);
	void GridCtrlInit();
	void GeneralComboInit();
	afx_msg void OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult);

};
