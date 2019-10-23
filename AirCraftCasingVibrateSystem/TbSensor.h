/************************************************************************
Copyright (C), 2018-2020. 哈尔滨理工大学人工智能实验室
文件名称： FileController.h
内容摘要： 传感器的实体类对象。对应的实现类文件为TbSensor.cpp。
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

