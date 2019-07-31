/************************************************************************
Copyright (C), 2018-2020. 哈尔滨理工大学人工智能实验室
文件名称： EngineerUintView.h
内容摘要： 工程单位界面.主要实现工程单位的CRUD。对应的实现类文件为EngineerUintView.cpp。
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


// CEngineerUnitView 对话框

class CEngineerUnitView : public CDialogEx
{
	DECLARE_DYNAMIC(CEngineerUnitView)

public:
	CEngineerUnitView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEngineerUnitView();

// 对话框数据
	enum { IDD = IDD_DIALOG_ENGINEER_UINT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
