#pragma once
#include "afxwin.h"
#include <vector>
#include "TbDictionary.h"
#include "DictionaryController.h"
#include "Result.h"
#include "DHTestHardWareController.h"
using namespace std;

// CollectionParaPresetView �Ի���

class CollectionParaPresetView : public CDialogEx
{
	DECLARE_DYNAMIC(CollectionParaPresetView)

public:
	CollectionParaPresetView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CollectionParaPresetView();

// �Ի�������
	enum { IDD = IDD_DIALOG_COLLECTIONPARAPRESET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	/*vector<TbDictionary> m_vcollectionMethod;
	vector<TbDictionary> m_DanalysisFrequency;
	vector<TbDictionary> m_vcollectionPoint;*/

	DictionaryController m_dictionaryController;
	DHTestHardWareController m_dhTestHardWareController;

	CComboBox m_sampleFrequencyCombo;
	CComboBox m_collectionMethodCombo;
	CComboBox m_analysisFrequencyCombo;
	CEdit m_sampleBatchEdit;

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	void CollectionParaInfoInit();
	void GetSelectedCollectionparas(TbCollectionparas &collectionparas);
	afx_msg void OnCbnSelchangeComboSamplefrequency();
	CEdit m_lineEdit;
};
