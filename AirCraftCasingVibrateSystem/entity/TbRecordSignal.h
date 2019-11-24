/************************************************************************
Copyright (C), 2018-2020. 哈尔滨理工大学人工智能实验室
文件名称： FileController.h
内容摘要： 记录实体类对象。对应的实现类文件为TbRecordSignal.cpp。
其它说明：飞机机匣振动检测系统
当前版本： 1.0
作 者： 马善涛
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
#include "TbTestingDevice.h"
#include "TbProduct.h"
#include "TbTestingDevice.h"
#include "TbProject.h"
#include <vector>
using namespace std;

class TbRecordSignal
{
public:

	TbRecordSignal(CString signalId, CString startTime, CString endTime, CString signalType, char signalStatus, TbProject project, TbProduct product, TbTestingDevice testingDevice, CString collectionStatus, CString sensorInfo);
	TbRecordSignal();
	~TbRecordSignal();

private:

	CString m_signalId;
	CString m_startTime;
	CString m_endTime;
	CString m_signalType;
	TbProduct m_product;
	char m_signalStatus;
	TbProject m_project;
	TbTestingDevice m_testingDevice;
	CString m_collectionStatus;
	CString m_sensorInfo;

public:
	CString GetSignalId();
	void SetSignalId(CString signalId);
	CString GetStartTime();
	void SetStartTime(CString startTime);
	CString GetEndTime();
	void SetEndTime(CString endTime);
	CString GetSignalType();
	void SetSignalType(CString signalType);
	TbProduct & GetProduct();
	void SetProduct(TbProduct product);
	char GetSignalStatus();
	void SetSignalStatus(char signal_status);

	void SetProject(TbProject project);
	TbProject & GetProject();



	TbTestingDevice & GetTestingDevice();
	void SetTesingDevice(TbTestingDevice  testingDevice);
	void SetCollectionStatus(CString collectionStatus);
	CString GetCollectionStatus();
	void SetSensorInfo(CString sensorInfo);
	CString GetSensorInfo();
};

