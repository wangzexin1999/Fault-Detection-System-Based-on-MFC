/************************************************************************
文件名称： CollectionParaView.h
内容摘要： 传感器参数界面.主要实现传感器参数显示和传感器参数设置。对应的实现类文件为SersorParaView.cpp。
************************************************************************/
#pragma once
// CollectionParaView 对话框
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
	CollectionParaView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CollectionParaView();

// 对话框数据
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
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
