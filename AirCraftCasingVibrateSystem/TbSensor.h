/************************************************************************
Copyright (C), 2018-2020. ����������ѧ�˹�����ʵ����
�ļ����ƣ� FileController.h
����ժҪ�� ��������ʵ������󡣶�Ӧ��ʵ�����ļ�ΪTbSensor.cpp��
����˵�����ɻ���ϻ�񶯼��ϵͳ
��ǰ�汾�� 1.0
�� �ߣ� ����
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

