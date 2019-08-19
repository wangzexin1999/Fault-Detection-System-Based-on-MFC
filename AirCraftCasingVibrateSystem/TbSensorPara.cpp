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
TbDictionary & TbSensorPara::GetSensorStatus() {
	return m_sensorStatus;
}
void TbSensorPara::SetSensorStatus(TbDictionary sersorStatus) {
	this->m_sensorStatus = sersorStatus;
}
TbDictionary & TbSensorPara::GetMessureType() {
	return m_messureType;
}
void TbSensorPara::SetMessureType(TbDictionary messureType) {
	this->m_messureType = messureType;
}
CString TbSensorPara::GetSensorDesc() {
	return m_sensorDesc;
}
void TbSensorPara::SetSensorDesc(CString sensorDesc) {
	this->m_sensorDesc = sensorDesc;
}
TbDictionary & TbSensorPara::GetWindowType() {
	return m_windowType;
}
void TbSensorPara::SetWindowType(TbDictionary windowType) {
	this->m_windowType = windowType;
}
float TbSensorPara::GetTriggerMagnitude() {
	return m_triggerMagnitude;
}
void TbSensorPara::SetTriggerMagnitude(float triggerMagnitude) {
	this->m_triggerMagnitude = triggerMagnitude;
}
TbDictionary & TbSensorPara::GetTriggerPolarity() {
	return m_triggerPolarity;
}
void TbSensorPara::SetTriggerPolarity(TbDictionary triggerPolarity) {
	this->m_triggerPolarity = triggerPolarity;
}
int TbSensorPara::GetPointNum() {
	return m_pointNum;
}
void TbSensorPara::SetPointNum(int pointNum) {
	this->m_pointNum = pointNum;
}
TbDictionary & TbSensorPara::GetCoordinateSystem() {
	return m_coordinateSystem;
}
void TbSensorPara::SetCoordinateSystem(TbDictionary coordinateSystem) {
	this->m_coordinateSystem = coordinateSystem;
}
TbDictionary & TbSensorPara::GetCoordinateSystemDirection() {
	return m_coordinateSystemDirection;
}
void TbSensorPara::SetCoordinateSystemDirection(TbDictionary coordinateSystemDirection) {
	this->m_coordinateSystemDirection = coordinateSystemDirection;
}
char TbSensorPara::GetIsReference() {
	return m_isReference;
}
void TbSensorPara::SetIsReference(char isReference) {
	this->m_isReference = isReference;
}
TbDictionary & TbSensorPara::GetEngineeringUnits() {
	return m_engineeringUnits;
}
void TbSensorPara::SetEngineeringUnits(TbDictionary engineeringUnits) {
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
TbDictionary & TbSensorPara::GetIntegralType() {
	return m_integralType;
}
void TbSensorPara::SetIntegralType(TbDictionary integralType) {
	this->m_integralType = integralType;
}
TbDictionary & TbSensorPara::GetIntegralUnits() {
	return m_integralUnits;
}
void TbSensorPara::SetIntegralUnits(TbDictionary integralUnits) {
	this->m_integralUnits = integralUnits;
}
TbDictionary & TbSensorPara::GetInputMethod() {
	return m_inputMethod;
}
void TbSensorPara::SetInputMethod(TbDictionary inputMethod) {
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