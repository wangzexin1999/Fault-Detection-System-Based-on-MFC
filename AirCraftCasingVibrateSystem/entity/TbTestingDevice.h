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
	TbTestingDevice();
	~TbTestingDevice();
	
	bool operator == (TbTestingDevice testingDevice);
	bool operator != (TbTestingDevice testingDevice);
protected:

	int m_id;
	CString m_testingDeviceIp;
	TbDictionary m_sampleFrequency;
	TbDictionary m_analysisFrequency;
	TbDictionary m_collectionMethod;
	TbDictionary m_collectionPoint;
	int m_collectionTimes;

public:
	
	void SetId(int id);
	int GetId(); 
	void SetTestingDeviceIp(CString testingDeviceIp);
	CString GetTestingDeviceIp();
	TbDictionary  & GetSampleFrequency();
	void SetSampleFrequency(TbDictionary sampleFrequency);
	TbDictionary  & GetAnalysisFrequency();
	void SetAnalysisFrequency(TbDictionary analysisFrequency);
	TbDictionary  & GetCollectionMethod();
	void SetCollectionMethod(TbDictionary collectionMethod);
	TbDictionary  & GetCollectionPoint();
	void SetCollectionPoint(TbDictionary collectionPoint);
	int GetCollectionTimes();
	void SetCollectionTimes(int collectionTimes);

};

