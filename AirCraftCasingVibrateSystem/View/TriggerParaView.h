/************************************************************************
Copyright (C), 2018-2020. 哈尔滨理工大学人工智能实验室
文件名称： TriggerParaView.h
内容摘要： 触发参数界面.主要实现触发参数显示和触发参数设置。对应的实现类文件为TriggerParaView.cpp。
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
#include "GridCtrl_src/GridCtrl.h"
#include "SensorParaController.h"
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
	SensorParaController m_sensorParaController;
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
public:
	void GridCtrlInit();
	afx_msg void OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult);
};
