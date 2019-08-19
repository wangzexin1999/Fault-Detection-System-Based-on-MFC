/************************************************************************
Copyright (C), 2018-2020. 哈尔滨理工大学人工智能实验室
文件名称： GeneralParaView.h
内容摘要： 检测设备数据库表对应的实体对象。对应的实现类文件为TbTestingDevice.cpp。
其它说明：飞机机匣振动检测系统
当前版本： 1.0
作 者： 马善涛
创建日期： 2019-07-24
完成日期:
History:
1. Date:    2018-07-24         Author:马善涛
Modification:
修改记录 1： // 修改历史记录，包括修改日期、修改者及修改内容
修改日期：
版 本 号：
修 改 人：
修改内容：
************************************************************************/
#pragma once
class TbTestingDevice
{
public:
	TbTestingDevice(int testingdeviceId = 0);
	~TbTestingDevice();
	
	bool operator == (TbTestingDevice testingDevice);
	bool operator != (TbTestingDevice testingDevice);
protected:
	int m_testingdeviceId;
	CString m_testingdeviceIp;
	CString m_testingdeviceName;
	CString m_testingdeviceBorndate;
	CString m_testingdeviceImportdate;
	int m_testingdeviceStatus;

public:
	int GetTestingdeviceId();

	void SetTestingdeviceId(int testingdeviceId);

	CString GetTestingdeviceIp();

	void SetTestingdeviceIp(CString testingdeviceIp);

	CString GetTestingdeviceName();

	void SetTestingdeviceName(CString testingdeviceName);

	CString GetTestingdeviceBorndate();

	void SetTestingdeviceBorndate(CString testingdeviceBorndate);
	CString GetTestingdeviceImportdate();
	void SetTestingdeviceImportdate(CString testingdeviceImportdate);

	void SetTestingDeviceStatus(int status);
	int GetTestingDeviceStatus();

};

