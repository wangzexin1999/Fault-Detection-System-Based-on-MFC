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
#include "include/rapidjson/document.h"
#include "JsonUtil.h"
using namespace std;
using namespace rapidjson;
class CollectionParaView : public CDialogEx
{
	DECLARE_DYNAMIC(CollectionParaView)

public:
	CollectionParaView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CollectionParaView();

// �Ի�������
	enum { IDD = IDD_DIALOG_SERSOR_PARA };

protected:

	vector<TbDictionary> m_vcollectionFrequency;
	vector<TbDictionary> m_vanalysisFrequency; 
	vector<TbDictionary> m_vcollectionMethod;
	vector<TbDictionary> m_vcollectionPoint;

	DictionaryController m_dictionaryController;
	CComboBox m_collectionFrequencyCombo;
	CComboBox m_collectionMethodCombo;
	CComboBox m_analysisFrequencyCombo;
	CComboBox m_collectionPointCombo;
	CEdit m_collectionTimesEdit;
	
	virtual BOOL OnInitDialog();
	void CollectionParaInfoInit();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	void SaveTestingDevice(TbTestingDevice &testingDevice);
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnCbnSelchangeCombo3();
	afx_msg void OnCbnSelchangeComboCollectionPoints();

	JsonUtil m_jsonUtil;
	//afx_msg void OnEnChangeEditCollectiontimes();
	DECLARE_MESSAGE_MAP()

public:
	void RefreshView();
	//afx_msg void OnCbnSelchangeComboCollectionPoints();
	afx_msg void OnEnChangeEditCollectionTimes();
};
