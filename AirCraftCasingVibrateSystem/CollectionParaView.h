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
class CollectionParaView : public CDialogEx
{
	DECLARE_DYNAMIC(CollectionParaView)

public:
	CollectionParaView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CollectionParaView();

// 对话框数据
	enum { IDD = IDD_DIALOG_SERSOR_PARA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
