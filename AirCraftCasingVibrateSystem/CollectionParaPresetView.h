#pragma once
#include "afxwin.h"
#include <vector>
#include "TbDictionary.h"
#include "DictionaryController.h"
#include "Result.h"
using namespace std;

// CollectionParaPresetView 对话框

class CollectionParaPresetView : public CDialogEx
{
	DECLARE_DYNAMIC(CollectionParaPresetView)

public:
	CollectionParaPresetView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CollectionParaPresetView();

// 对话框数据
	enum { IDD = IDD_DIALOG_COLLECTIONPARAPRESET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	vector<TbDictionary> m_vcollectionFrequency;
	vector<TbDictionary> m_vcollectionMethod;
	vector<TbDictionary> m_vanalysisFrequency;
	vector<TbDictionary> m_vtriggerMethod;
	vector<TbDictionary> m_vdataBlockCount;

	DictionaryController m_dictionaryController;

	CComboBox m_collectionFrequencyCombo;
	CComboBox m_collectionMethodCombo;
	CComboBox m_analysisFrequencyCombo;
	CComboBox m_triggerMethodCombo;
	CComboBox m_dataBlockCountCombo;
	CEdit m_triggerCountEdit;
	CEdit m_delayBlockCountEdit;
	CEdit m_collectionBatchEdit;

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	void GetSelectedTestingDevicePara(TbTestingDevicePara &testingDevicePara);
};
