#include "stdafx.h"
#include "TbSensor.h"
TbSensor::TbSensor()
{

}
TbSensor::TbSensor(int sensorId, CString sensorName, CString sensorType)
{
	SetSensorId(sensorId);
	SetSensorName(sensorName);
	SetSensorType(sensorType);
}
TbSensor::~TbSensor()
{

}
int TbSensor::GetSensorId()
{
	return m_sensorId;
}
void TbSensor::SetSensorId(int sensorId)
{
	this->m_sensorId = sensorId;
}

CString TbSensor::GetSensorName()
{
	return m_sensorName;
}
void TbSensor::SetSensorName(CString sensorName)
{
	this->m_sensorName = sensorName;
}

CString TbSensor::GetSensorType()
{
	return m_sensorType;
}
void TbSensor::SetSensorType(CString sensorType)
{
	this->m_sensorType = sensorType;
}