/************************************************************************
Copyright (C), 2018-2020. 哈尔滨理工大学人工智能实验室
文件名称： CollectionParaView.h
内容摘要： 传感器参数界面.主要实现传感器参数显示和传感器参数设置。对应的实现类文件为SersorParaView.cpp。
其它说明：飞机机匣振动检测系统
当前版本： 1.0
作 者： 刘望
创建日期： 2019-05-24
完成日期:
History:
1. Date:    2018-05-24         Author:刘望
Modification:
修改记录 1： // 修改历史记录，包括修改日期、修改者及修改内容
修改日期：
版 本 号：
修 改 人：
修改内容：
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
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
