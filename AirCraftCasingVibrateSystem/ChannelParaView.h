/************************************************************************
Copyright (C), 2018-2020. 哈尔滨理工大学人工智能实验室
文件名称： ChannelParaView.h
内容摘要： 通道参数界面.主要实现设置通道参数，子类主要有通道子参数，通用参数，几何参数触发参数
			对应的实现类文件为ChannelParaView.cpp。
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
#include "DeviceParaView.h"
#include "ChannelParaDialog.h"

// CChannelParaView

class CChannelParaView : public CDockablePane
{
	DECLARE_DYNAMIC(CChannelParaView)

public:
	CChannelParaView();
	virtual ~CChannelParaView();
	void RefreshView();

private:
	CMFCTabCtrl m_tab;
	CChannelParaDialog m_channelParaDialog;
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//void ShowPane(BOOL bShow, BOOL bDelay, BOOL bActivate);
};


