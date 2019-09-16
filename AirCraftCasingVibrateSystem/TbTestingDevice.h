/************************************************************************
Copyright (C), 2018-2020. ����������ѧ�˹�����ʵ����
�ļ����ƣ� GeneralParaView.h
����ժҪ�� ����豸���ݿ���Ӧ��ʵ����󡣶�Ӧ��ʵ�����ļ�ΪTbTestingDevice.cpp��
����˵�����ɻ���ϻ�񶯼��ϵͳ
��ǰ�汾�� 1.0
�� �ߣ� ������
�������ڣ� 2019-07-24
�������:
History:
1. Date:    2018-07-24         Author:������
Modification:
�޸ļ�¼ 1�� // �޸���ʷ��¼�������޸����ڡ��޸��߼��޸�����
�޸����ڣ�
�� �� �ţ�
�� �� �ˣ�
�޸����ݣ�
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

