/************************************************************************
文件名称： TriggerParaView.h
内容摘要： 触发参数界面.主要实现触发参数显示和触发参数设置。对应的实现类文件为TriggerParaView.cpp。

************************************************************************/
#pragma once
#include "GridCtrl_src/GridCtrl.h"
#include "ChannelParaController.h"
// CTriggerParaView 对话框

class CTriggerParaView : public CDialogEx
{
	DECLARE_DYNAMIC(CTriggerParaView)

public:
	CTriggerParaView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTriggerParaView();

// 对话框数据
	enum { IDD = IDD_DIALOG_TRIGGER_PARA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	CGridCtrl m_triggerParaGridCtrl;
	ChannelParaController m_channelParaController;
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
public:
	void GridCtrlInit();
	afx_msg void OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult);
};
