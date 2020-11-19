/************************************************************************
�ļ����ƣ� CollectionParaView.h
����ժҪ�� ��������������.��Ҫʵ�ִ�����������ʾ�ʹ������������á���Ӧ��ʵ�����ļ�ΪSersorParaView.cpp��
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


	vector<TbDictionary> m_DsampleFrequency;
	vector<TbDictionary> m_DanalysisFrequency; 
	vector<TbDictionary> m_vcollectionMethod;
	vector<TbDictionary> m_vcollectionPoint;

	DictionaryController m_dictionaryController;
	CComboBox m_sampleFrequencyCombo;
	CComboBox m_collectionMethodCombo;
	CComboBox m_analysisFrequencyCombo;
	CComboBox m_collectionPointCombo;
	CEdit m_sampleBatchEdit;
	
	virtual BOOL OnInitDialog();
	void CollectionParaInfoInit();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	void SaveCollectionparas(TbCollectionparas &collectionparas);
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
	afx_msg void OnEnChangeEditSampleBatch();

private:
	int analysisFrequencyCurSel = 0;
};
