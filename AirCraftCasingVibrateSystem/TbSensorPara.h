#pragma once
#include "TbDictionary.h"
class TbSensorPara
{
public:
	TbSensorPara();
	~TbSensorPara();

private:
	int m_sensorParaId;
	int m_projectId;
	int m_sensorId;
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
	char m_isUsed;

public:
	int GetSensorParaId();
	void SetSensorParaId(int sensorParaId);
	int GetProjectId();
	void SetProjectId(int projectId);
	int GetSensorId();
	void SetSensorId(int SensorId);

	TbDictionary & GetSensorStatus();
	void SetSensorStatus(TbDictionary SensorStatus);
	char GetSensorIsUsed();
	void SetSensorIsUsed(char isUsed);
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

