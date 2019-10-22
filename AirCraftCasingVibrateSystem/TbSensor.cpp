#include "stdafx.h"
#include "TbSensor.h"


TbSensor::TbSensor(int id){
	m_id = id; 
	SetProjectId(0);
	SetSensitivity(0);
	SetTriggerMagnitude(0);
	SetIsReference(0);
	SetPointNum(0);
	SetAntiAliasingFiltering(0);
	SetMaxFrequency(0);
}


TbSensor::~TbSensor(){}


void TbSensor::SetId(int id){
	m_id = id;
}
int TbSensor::GetId(){
	return m_id;
}

int TbSensor::GetProjectId() {
	return m_projectId;
}
void TbSensor::SetProjectId(int projectId) {
	this->m_projectId = projectId;
}
CString TbSensor::GetChannels() {
	return m_sensorId;
}
void TbSensor::SetChannelId(CString sensorId) {
	this->m_sensorId = sensorId;
}

TbDictionary & TbSensor::GetSensorStatus() {
	return m_sensorStatus;
}
void TbSensor::SetSensorStatus(TbDictionary sersorStatus) {
	this->m_sensorStatus = sersorStatus;
}
TbDictionary & TbSensor::GetMessureType() {
	return m_messureType;
}
void TbSensor::SetMessureType(TbDictionary messureType) {
	this->m_messureType = messureType;
}
CString TbSensor::GetSensorDesc() {
	return m_sensorDesc;
}
void TbSensor::SetSensorDesc(CString sensorDesc) {
	this->m_sensorDesc = sensorDesc;
}
TbDictionary & TbSensor::GetWindowType() {
	return m_windowType;
}
void TbSensor::SetWindowType(TbDictionary windowType) {
	this->m_windowType = windowType;
}
float TbSensor::GetTriggerMagnitude() {
	return m_triggerMagnitude;
}
void TbSensor::SetTriggerMagnitude(float triggerMagnitude) {
	this->m_triggerMagnitude = triggerMagnitude;
}
TbDictionary & TbSensor::GetTriggerPolarity() {
	return m_triggerPolarity;
}
void TbSensor::SetTriggerPolarity(TbDictionary triggerPolarity) {
	this->m_triggerPolarity = triggerPolarity;
}
int TbSensor::GetPointNum() {
	return m_pointNum;
}
void TbSensor::SetPointNum(int pointNum) {
	this->m_pointNum = pointNum;
}
TbDictionary & TbSensor::GetCoordinateSystem() {
	return m_coordinateSystem;
}
void TbSensor::SetCoordinateSystem(TbDictionary coordinateSystem) {
	this->m_coordinateSystem = coordinateSystem;
}
TbDictionary & TbSensor::GetCoordinateSystemDirection() {
	return m_coordinateSystemDirection;
}
void TbSensor::SetCoordinateSystemDirection(TbDictionary coordinateSystemDirection) {
	this->m_coordinateSystemDirection = coordinateSystemDirection;
}
char TbSensor::GetIsReference() {
	return m_isReference;
}
void TbSensor::SetIsReference(char isReference) {
	this->m_isReference = isReference;
}
TbDictionary & TbSensor::GetEngineeringUnits() {
	return m_engineeringUnits;
}
void TbSensor::SetEngineeringUnits(TbDictionary engineeringUnits) {
	this->m_engineeringUnits = engineeringUnits;
}
float TbSensor::GetSensitivity() {
	return m_sensitivity;
}
void TbSensor::SetSensitivity(float sensitivity) {
	this->m_sensitivity = sensitivity;
}
float TbSensor::GetMileageRange() {
	return m_mileageRange;
}
void TbSensor::SetMileageRange(float mileageRange) {
	this->m_mileageRange = mileageRange;
}
TbDictionary & TbSensor::GetIntegralType() {
	return m_integralType;
}
void TbSensor::SetIntegralType(TbDictionary integralType) {
	this->m_integralType = integralType;
}
TbDictionary & TbSensor::GetIntegralUnits() {
	return m_integralUnits;
}
void TbSensor::SetIntegralUnits(TbDictionary integralUnits) {
	this->m_integralUnits = integralUnits;
}
TbDictionary & TbSensor::GetInputMethod() {
	return m_inputMethod;
}
void TbSensor::SetInputMethod(TbDictionary inputMethod) {
	this->m_inputMethod = inputMethod;
}
char TbSensor::GetAntiAliasingFiltering() {
	return m_antiAliasingFiltering;
}
void TbSensor::SetAntiAliasingFiltering(char antiAliasingFiltering) {
	this->m_antiAliasingFiltering = antiAliasingFiltering;
}
float TbSensor::GetMaxFrequency() {
	return m_maxFrequency;
}
void TbSensor::SetMaxFrequency(float maxFrequency) {
	this->m_maxFrequency = maxFrequency;
}