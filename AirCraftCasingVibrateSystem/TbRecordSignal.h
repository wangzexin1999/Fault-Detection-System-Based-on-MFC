/************************************************************************
Copyright (C), 2018-2020. ����������ѧ�˹�����ʵ����
�ļ����ƣ� FileController.h
����ժҪ�� ��¼ʵ������󡣶�Ӧ��ʵ�����ļ�ΪTbRecordSignal.cpp��
����˵�����ɻ���ϻ�񶯼��ϵͳ
��ǰ�汾�� 1.0
�� �ߣ� ������
�������ڣ� 2019-08-19
�������:
History:
1. Date:    2019-08-19         Author:������
Modification:
�޸ļ�¼ 1�� // �޸���ʷ��¼�������޸����ڡ��޸��߼��޸�����
�޸����ڣ�
�� �� �ţ�
�� �� �ˣ�
�޸����ݣ�
************************************************************************/
#pragma once
#include "TbTestingDevice.h"
#include <vector>
using namespace std;

class TbRecordSignal
{
public:

	TbRecordSignal();
	~TbRecordSignal();

private:

	int m_signalId;
	CString m_startTime;
	CString m_endTime;
	CString m_signalType;
	int m_productId;
	char m_signalStatus;
	int m_projectId;
	int m_testingDeviceId;
	CString m_collectionStatus;
	CString m_sensorInfo;

public:
	int GetSignalId();
	void SetSignalId(int signalId);
	CString GetStartTime();
	void SetStartTime(CString startTime);
	CString GetEndTime();
	void SetEndTime(CString endTime);
	CString GetSignalType();
	void SetSignalType(CString signalType);
	int GetProductId();
	void SetProductId(int product);
	char GetSignalStatus();
	void SetSignalStatus(char signal_status);
	void SetProjectId(int projectId);
	int  GetProjectId();
	int  GetTestingDeviceId();
	void SetTesingDeviceId(int  testingDeviceId);
	void SetCollectionStatus(CString collectionStatus);
	CString GetCollectionStatus();
	void SetSensorInfo(CString sensorInfo);
	CString GetSensorInfo();
};

