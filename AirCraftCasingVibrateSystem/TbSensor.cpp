#include "stdafx.h"
#include "TbSensor.h"


TbSensor::TbSensor(int sensorId){ m_isensorId = sensorId; }


TbSensor::~TbSensor(){}



void TbSensor::SetSensorId(int sensorId){
	m_isensorId = sensorId;
}
void TbSensor::SetTestingDeviceId(int testingDeviceId){
	m_itestingDeviceId = testingDeviceId;
}
void TbSensor::SetSensorType(CString sensorType){
	m_sensorType = sensorType;
}
void TbSensor::SetSensorName(CString sensorName){
	m_sensorName = sensorName;
}
int TbSensor::GetSensorId(){
	return m_isensorId;
}
int TbSensor::GetTestingDeviceId(){
	return m_itestingDeviceId;
}
CString TbSensor::GetSensorType(){
	return m_sensorType;
}
CString TbSensor::GetSensorName(){
	return m_sensorName;
}