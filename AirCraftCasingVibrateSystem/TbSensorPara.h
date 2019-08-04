#pragma once
class TbSensorPara
{
public:
	TbSensorPara();
	~TbSensorPara();

private:
	int m_sensorParaId;
	int m_projectId;
	int m_sensorId;
	char m_sensorStatus;
	int m_messureType;
	CString m_sensorDesc;
	int m_windowType;
	float m_triggerMagnitude;
	int m_triggerPolarity;
	int m_pointNum;
	int m_coordinateSystem;
	int m_coordinateSystemDirection;
	char m_isReference;
	int m_engineeringUnits;
	float  m_sensitivity;
	float m_mileageRange;
	int m_integralType;
	int m_integralUnits;
	int m_inputMethod;
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
	char GetSensorStatus();
	void SetSensorStatus(char SensorStatus);
	char GetSensorIsUsed();
	void SetSensorIsUsed(char isUsed);
	int GetMessureType();
	void SetMessureType(int messureType);
	CString GetSensorDesc();
	void SetSensorDesc(CString sensorDesc);
	int GetWindowType();
	void SetWindowType(int windowType);
	float GetTriggerMagnitude();
	void SetTriggerMagnitude(float triggerMagnitude);
	int GetTriggerPolarity();
	void SetTriggerPolarity(int triggerPolarity);
	int GetPointNum();
	void SetPointNum(int pointNum);
	int GetCoordinateSystem();
	void SetCoordinateSystem(int coordinateSystem);
	int GetCoordinateSystemDirection();
	void SetCoordinateSystemDirection(int coordinateSystemDirection);
	char GetIsReference();
	void SetIsReference(char isReference);
	int GetEngineeringUnits();
	void SetEngineeringUnits(int engineeringUnits);
	float GetSensitivity();
	void SetSensitivity(float sensitivity);
	float GetMileageRange();
	void SetMileageRange(float mileageRange);
	int GetIntegralType();
	void SetIntegralType(int integralType);
	int GetIntegralUnits();
	void SetIntegralUnits(int integralUnits);
	int GetInputMethod();
	void SetInputMethod(int inputMethod);
	char GetAntiAliasingFiltering();
	void SetAntiAliasingFiltering(char antiAliasingFiltering);
	float GetMaxFrequency();
	void SetMaxFrequency(float maxFrequency);
};

