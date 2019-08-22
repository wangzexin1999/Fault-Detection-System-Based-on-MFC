/************************************************************************
Copyright (C), 2018-2020. 哈尔滨理工大学人工智能实验室
文件名称： FileController.h
内容摘要： 传感器的实体类对象。对应的实现类文件为TbSensor.cpp。
其它说明：飞机机匣振动检测系统
当前版本： 1.0
作 者： 刘望
创建日期： 2019-08-19
完成日期:
History:
1. Date:    2019-08-19         Author:马善涛
Modification:
修改记录 1： // 修改历史记录，包括修改日期、修改者及修改内容
修改日期：
版 本 号：
修 改 人：
修改内容：
************************************************************************/
#pragma once
class TbSensor
{

private:

	int m_isensorId;
	int m_itestingDeviceId;
	CString m_sensorType;
	CString m_sensorName;

public:
	TbSensor();
	~TbSensor();

	void SetSensorId(int sensorId);
	void SetTestingDeviceId(int testingDeviceId);
	void SetSensorType(CString sensorType);
	void SetSensorName(CString sensorName);

	int GetSensorId();
	int GetTestingDeviceId();
	CString GetSensorType();
	CString GetSensorName();
};

