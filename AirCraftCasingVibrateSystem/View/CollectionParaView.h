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
#include "CDHTestHardWare.h"
#include "DHTestHardWareController.h"
#include "CollectionparasController.h"
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
	DHTestHardWareController m_dhTestHardWareController;
	long lReturnValue;
	CollectionparasController m_collectionParasController;


	CollectionparasController m_colletionParasController;

	DictionaryController m_dictionaryController;
	CComboBox m_sampleFrequencyCombo;
	CComboBox m_collectionMethodCombo;
	CComboBox m_collectionPointCombo;
	CComboBox m_ComboSampleClock;
	CEdit m_sampleBatchEdit;
	stuSampleParam m_SampleParam;

	virtual BOOL OnInitDialog();
	void CollectionParaInfoInit();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	void SaveCollectionparas(TbCollectionparas &collectionparas);
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnCbnSelchangeCombo3();
	afx_msg void OnCbnSelchangeComboCollectionPoints();
	afx_msg void OnCbnSelchangeComboClock();
	// ��ʼ������ʱ��
	void InitSampleClock();
	JsonUtil m_jsonUtil;
	//afx_msg void OnEnChangeEditCollectiontimes();
	DECLARE_MESSAGE_MAP()
public:
	void RefreshView();
	//afx_msg void OnCbnSelchangeComboCollectionPoints();
	afx_msg void OnEnChangeEditSampleBatch();
	//���ò�������
	long SetSampleParam();
private:
	int analysisFrequencyCurSel = 0;
	void updateCollectionPara();
public:
	CEdit m_line;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnCbnSelchangeComboFreq();

};
