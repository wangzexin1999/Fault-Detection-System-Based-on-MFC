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
#include "TbProduct.h"
#include "TbSensor.h"
#include "TbTestingDevice.h"
#include <vector>
#include "TbProject.h"
using namespace std;

class TbRecordSignal
{
public:
	TbRecordSignal();
	~TbRecordSignal();


private:
	int m_signalId;

	TbProject m_project;
	CString m_startTime;
	CString m_endTime;
	CString m_signalType;
	TbSensor m_sensor;
	TbProduct m_product;
	char m_signalStatus;
	TbTestingDevice m_testingDevice;
	int m_sensorCount; ////����������

public:
	int GetSignalId();
	void SetSignalId(int signalId);
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

	TbSensor & GetSensor();
	void SetSensor(TbSensor  sensor);


	TbTestingDevice & GetTestingDevice();
	void SetTesingDevice(TbTestingDevice  testingDevice);

	void SetSensorCount(int sensorCount);
	int GetSensorCount();

};

