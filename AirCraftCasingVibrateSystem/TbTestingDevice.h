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
#include "TbDictionary.h"
#pragma once
class TbTestingDevice
{
public:
	TbTestingDevice(int testingdeviceId = 0);
	~TbTestingDevice();
	
	bool operator == (TbTestingDevice testingDevice);
	bool operator != (TbTestingDevice testingDevice);
protected:

	int m_id;
	CString m_testingDeviceIp;
	TbDictionary m_collectionFrequency;
	TbDictionary m_analysisFrequency;
	TbDictionary m_collectionMethod;
	TbDictionary m_triggerMethod;
	TbDictionary m_datablockCount;
	int m_delayblockCount;
	int m_triggerCount;
	int m_collectionBatchs;

public:
	
	void SetId(int id);
	int GetId(); 
	void SetTestingDeviceIp(CString testingDeviceIp);
	CString GetTestingDeviceIp();
	TbDictionary  & GetCollectionFrequency();
	void SetCollectionFrequency(TbDictionary collectionFrequency);
	TbDictionary  & GetAnalysisFrequency();
	void SetAnalysisFrequency(TbDictionary analysisFrequency);
	TbDictionary  & GetCollectionMethod();
	void SetCollectionMethod(TbDictionary collectionMethod);
	TbDictionary  & GetTriggerMethod();
	void SetTriggerMethod(TbDictionary triggerMethod);
	TbDictionary  & GetDatablockCount();
	void SetDatablockCount(TbDictionary datablockCount);
	int GetDelayblockCount();
	void SetDelayblockCount(int delayblockCount);
	int GetTriggerCount();
	void SetTriggerCount(int triggerCount);
	int GetCollectionBatchs();
	void SetCollectionBatchs(int collectionBatchs);

};

