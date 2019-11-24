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

