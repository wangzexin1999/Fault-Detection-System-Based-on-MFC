/************************************************************************
Copyright (C), 2018-2020. ����������ѧ�˹�����ʵ����
�ļ����ƣ� CollectionParaView.h
����ժҪ�� ��������������.��Ҫʵ�ִ�����������ʾ�ʹ������������á���Ӧ��ʵ�����ļ�ΪSersorParaView.cpp��
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
// CollectionParaView �Ի���
#include "DictionaryController.h"
#include "afxwin.h"
class CollectionParaView : public CDialogEx
{
	DECLARE_DYNAMIC(CollectionParaView)

public:
	CollectionParaView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CollectionParaView();

// �Ի�������
	enum { IDD = IDD_DIALOG_SERSOR_PARA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	vector<TbDictionary> m_vcollectionFrequency;
	vector<TbDictionary> m_vcollectionMethod;
	vector<TbDictionary> m_vanalysisFrequency;
	vector<TbDictionary> m_vtriggerMethod;
	vector<TbDictionary> m_vdataBlockCount;
	DictionaryController m_dictionaryController;


	DECLARE_MESSAGE_MAP()
public:
	void CollectionParaInit();
	virtual BOOL OnInitDialog();
	CComboBox m_collectionFrequencyCombo;
	CComboBox m_collectionMethodCombo;
	CComboBox m_analysisFrequencyCombo;
	CComboBox m_triggerMethodCombo;
	CComboBox m_dataBlockCountCombo;

	CEdit m_triggerCountEdit;
	CEdit m_delayBlockCountEdit;
	CEdit m_collectionBatchEdit;
};
