/************************************************************************
Copyright (C), 2018-2020. 哈尔滨理工大学人工智能实验室
文件名称： DeviceParaView.h
内容摘要： 设备参数界面.主要实现设备信息显示和设备信息的设置。对应的实现类文件为DeviceParaView.cpp。
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


// CDeviceParaView 对话框

class CDeviceParaView : public CDialogEx
{
	DECLARE_DYNAMIC(CDeviceParaView)

public:
	CDeviceParaView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDeviceParaView();

// 对话框数据
	enum { IDD = IDD_DIALOG_DEVICE_PARA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
