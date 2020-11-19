#pragma once
#include <vector>
#include <atlstr.h>
using namespace std;
class TbSensor
{
public:
	TbSensor();
	TbSensor(int sensorId, CString sensorName, CString sensorType);
	~TbSensor();
private:
	int m_sensorId;
	CString m_sensorName;
	CString m_sensorType;
public:
	int GetSensorId();
	void SetSensorId(int sensorId);

	CString GetSensorName();
	void SetSensorName(CString sensorName);

	CString GetSensorType();
	void SetSensorType(CString sensorType);
};