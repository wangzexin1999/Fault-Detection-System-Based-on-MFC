#include "stdafx.h"
#include "TbSensorPara.h"


TbSensorPara::TbSensorPara()
{
}


TbSensorPara::~TbSensorPara()
{
}
int TbSensorPara::GetSensorParaId() {
	return m_sensorParaId;
}
void TbSensorPara::SetSensorParaId(int sensorParaId) {
	this->m_sensorParaId = sensorParaId;
}
int TbSensorPara::GetProjectId() {
	return m_projectId;
}
void TbSensorPara::SetProjectId(int projectId) {
	this->m_projectId = projectId;
}
int TbSensorPara::GetSensorId() {
	return m_sensorId;
}
void TbSensorPara::SetSensorId(int sensorId) {
	this->m_sensorId = sensorId;
}
char TbSensorPara::GetSensorStatus() {
	return m_sensorStatus;
}
void TbSensorPara::SetSensorStatus(char sersorStatus) {
	this->m_sensorStatus = sersorStatus;
}
int TbSensorPara::GetMessureType() {
	return m_messureType;
}
void TbSensorPara::SetMessureType(int messureType) {
	this->m_messureType = messureType;
}
CString TbSensorPara::GetSensorDesc() {
	return m_sensorDesc;
}
void TbSensorPara::SetSensorDesc(CString sensorDesc) {
	this->m_sensorDesc = sensorDesc;
}
int TbSensorPara::GetWindowType() {
	return m_windowType;
}
void TbSensorPara::SetWindowType(int windowType) {
	this->m_windowType = windowType;
}
float TbSensorPara::GetTriggerMagnitude() {
	return m_triggerMagnitude;
}
void TbSensorPara::SetTriggerMagnitude(float triggerMagnitude) {
	this->m_triggerMagnitude = triggerMagnitude;
}
int TbSensorPara::GetTriggerPolarity() {
	return m_triggerPolarity;
}
void TbSensorPara::SetTriggerPolarity(int triggerPolarity) {
	this->m_triggerPolarity = triggerPolarity;
}
int TbSensorPara::GetPointNum() {
	return m_pointNum;
}
void TbSensorPara::SetPointNum(int pointNum) {
	this->m_pointNum = pointNum;
}
int TbSensorPara::GetCoordinateSystem() {
	return m_coordinateSystem;
}
void TbSensorPara::SetCoordinateSystem(int coordinateSystem) {
	this->m_coordinateSystem = coordinateSystem;
}
int TbSensorPara::GetCoordinateSystemDirection() {
	return m_coordinateSystemDirection;
}
void TbSensorPara::SetCoordinateSystemDirection(int coordinateSystemDirection) {
	this->m_coordinateSystemDirection = coordinateSystemDirection;
}
char TbSensorPara::GetIsReference() {
	return m_isReference;
}
void TbSensorPara::SetIsReference(char isReference) {
	this->m_isReference = isReference;
}
int TbSensorPara::GetEngineeringUnits() {
	return m_engineeringUnits;
}
void TbSensorPara::SetEngineeringUnits(int engineeringUnits) {
	this->m_engineeringUnits = engineeringUnits;
}
float TbSensorPara::GetSensitivity() {
	return m_sensitivity;
}
void TbSensorPara::SetSensitivity(float sensitivity) {
	this->m_sensitivity = sensitivity;
}
float TbSensorPara::GetMileageRange() {
	return m_mileageRange;
}
void TbSensorPara::SetMileageRange(float mileageRange) {
	this->m_mileageRange = mileageRange;
}
int TbSensorPara::GetIntegralType() {
	return m_integralType;
}
void TbSensorPara::SetIntegralType(int integralType) {
	this->m_integralType = integralType;
}
int TbSensorPara::GetIntegralUnits() {
	return m_integralUnits;
}
void TbSensorPara::SetIntegralUnits(int integralUnits) {
	this->m_integralUnits = integralUnits;
}
int TbSensorPara::GetInputMethod() {
	return m_inputMethod;
}
void TbSensorPara::SetInputMethod(int inputMethod) {
	this->m_inputMethod = inputMethod;
}
char TbSensorPara::GetAntiAliasingFiltering() {
	return m_antiAliasingFiltering;
}
void TbSensorPara::SetAntiAliasingFiltering(char antiAliasingFiltering) {
	this->m_antiAliasingFiltering = antiAliasingFiltering;
}
float TbSensorPara::GetMaxFrequency() {
	return m_maxFrequency;
}
void TbSensorPara::SetMaxFrequency(float maxFrequency) {
	this->m_maxFrequency = maxFrequency;
}

char TbSensorPara::GetSensorIsUsed(){
	return m_isUsed;
}
void TbSensorPara::SetSensorIsUsed(char isUsed){
	this->m_isUsed = isUsed;
}