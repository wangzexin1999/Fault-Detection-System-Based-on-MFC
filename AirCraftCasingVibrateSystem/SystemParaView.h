/************************************************************************
Copyright (C), 2018-2020. 哈尔滨理工大学人工智能实验室
文件名称： SystemParaView.h
内容摘要： 系统参数界面.主要实现系统参数显示和系统参数设置。对应的实现类文件为SystemParaView.cpp。
			主要分为两个部分，一是传感器参数，二是设备参数
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
#include "SystemParaDialog.h"

// CSystemParaView

class CSystemParaView : public CDockablePane
{
	DECLARE_DYNAMIC(CSystemParaView)

public:
	CSystemParaView();
	virtual ~CSystemParaView();
public:

	CSystemParaDialog   m_systemParaDialog;
	void RefreshView();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


