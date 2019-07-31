#pragma once
class TbSersorPara
{
public:
	TbSersorPara();
	~TbSersorPara();

private:
	int m_sensorParaId;
	int m_projectId;
	int m_sersorId;
	char m_sersorStatus;
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

	int GetSensorParaId();
	void SetSensorParaId(int sensorParaId);
	int GetProjectId();
	void SetProjectId(int projectId);
	int GetSersorId();
	void SetSersorId(int sersorId);
	char GetSersorStatus();
	void SetSersorStatus(char sersorStatus);
	char GetSersorIsUsed();
	void SetSersorIsUsed(char isUsed);
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

