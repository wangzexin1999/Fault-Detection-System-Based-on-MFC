/************************************************************************
Copyright (C), 2018-2020. ����������ѧ�˹�����ʵ����
�ļ����ƣ� FileController.h
����ժҪ�� ��������ʵ������󡣶�Ӧ��ʵ�����ļ�ΪTbSensor.cpp��
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
#include "TbDictionary.h"
#pragma once
class TbSensor
{

private:

	int m_id;
	CString m_sensorId;
	int m_projectId;
	TbDictionary m_sensorStatus;
	TbDictionary m_messureType;
	CString m_sensorDesc;
	TbDictionary m_windowType;
	float m_triggerMagnitude;
	TbDictionary m_triggerPolarity;
	int m_pointNum;
	TbDictionary m_coordinateSystem;
	TbDictionary m_coordinateSystemDirection;
	char m_isReference;
	TbDictionary m_engineeringUnits;
	float  m_sensitivity;
	float m_mileageRange;
	TbDictionary m_integralType;
	TbDictionary m_integralUnits;
	TbDictionary m_inputMethod;
	char m_antiAliasingFiltering;
	float m_maxFrequency;

public:
	TbSensor(int sensorId = 0);
	~TbSensor();

	void SetId(int id);
	int GetId();
	void SetChannelId(CString sensor);
	CString GetChannelId();
	int GetProjectId();
	void SetProjectId(int projectId);
	TbDictionary & GetSensorStatus();
	void SetSensorStatus(TbDictionary SensorStatus);
	TbDictionary & GetMessureType();
	void SetMessureType(TbDictionary messureType);
	CString GetSensorDesc();
	void SetSensorDesc(CString sensorDesc);
	TbDictionary & GetWindowType();
	void SetWindowType(TbDictionary windowType);
	float GetTriggerMagnitude();
	void SetTriggerMagnitude(float triggerMagnitude);
	TbDictionary & GetTriggerPolarity();
	void SetTriggerPolarity(TbDictionary triggerPolarity);
	int GetPointNum();
	void SetPointNum(int pointNum);
	TbDictionary & GetCoordinateSystem();
	void SetCoordinateSystem(TbDictionary coordinateSystem);
	TbDictionary & GetCoordinateSystemDirection();
	void SetCoordinateSystemDirection(TbDictionary coordinateSystemDirection);
	char GetIsReference();
	void SetIsReference(char isReference);
	TbDictionary & GetEngineeringUnits();
	void SetEngineeringUnits(TbDictionary engineeringUnits);
	float GetSensitivity();
	void SetSensitivity(float sensitivity);
	float GetMileageRange();
	void SetMileageRange(float mileageRange);
	TbDictionary & GetIntegralType();
	void SetIntegralType(TbDictionary integralType);
	TbDictionary & GetIntegralUnits();
	void SetIntegralUnits(TbDictionary integralUnits);
	TbDictionary & GetInputMethod();
	void SetInputMethod(TbDictionary inputMethod);
	char GetAntiAliasingFiltering();
	void SetAntiAliasingFiltering(char antiAliasingFiltering);
	float GetMaxFrequency();
	void SetMaxFrequency(float maxFrequency);

};

