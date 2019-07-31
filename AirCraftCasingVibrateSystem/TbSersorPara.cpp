#include "stdafx.h"
#include "TbSersorPara.h"


TbSersorPara::TbSersorPara()
{
}


TbSersorPara::~TbSersorPara()
{
}
int TbSersorPara::GetSensorParaId() {
	return m_sensorParaId;
}
void TbSersorPara::SetSensorParaId(int sensorParaId) {
	this->m_sensorParaId = sensorParaId;
}
int TbSersorPara::GetProjectId() {
	return m_projectId;
}
void TbSersorPara::SetProjectId(int projectId) {
	this->m_projectId = projectId;
}
int TbSersorPara::GetSersorId() {
	return m_sersorId;
}
void TbSersorPara::SetSersorId(int sersorId) {
	this->m_sersorId = sersorId;
}
char TbSersorPara::GetSersorStatus() {
	return m_sersorStatus;
}
void TbSersorPara::SetSersorStatus(char sersorStatus) {
	this->m_sersorStatus = sersorStatus;
}
int TbSersorPara::GetMessureType() {
	return m_messureType;
}
void TbSersorPara::SetMessureType(int messureType) {
	this->m_messureType = messureType;
}
CString TbSersorPara::GetSensorDesc() {
	return m_sensorDesc;
}
void TbSersorPara::SetSensorDesc(CString sensorDesc) {
	this->m_sensorDesc = sensorDesc;
}
int TbSersorPara::GetWindowType() {
	return m_windowType;
}
void TbSersorPara::SetWindowType(int windowType) {
	this->m_windowType = windowType;
}
float TbSersorPara::GetTriggerMagnitude() {
	return m_triggerMagnitude;
}
void TbSersorPara::SetTriggerMagnitude(float triggerMagnitude) {
	this->m_triggerMagnitude = triggerMagnitude;
}
int TbSersorPara::GetTriggerPolarity() {
	return m_triggerPolarity;
}
void TbSersorPara::SetTriggerPolarity(int triggerPolarity) {
	this->m_triggerPolarity = triggerPolarity;
}
int TbSersorPara::GetPointNum() {
	return m_pointNum;
}
void TbSersorPara::SetPointNum(int pointNum) {
	this->m_pointNum = pointNum;
}
int TbSersorPara::GetCoordinateSystem() {
	return m_coordinateSystem;
}
void TbSersorPara::SetCoordinateSystem(int coordinateSystem) {
	this->m_coordinateSystem = coordinateSystem;
}
int TbSersorPara::GetCoordinateSystemDirection() {
	return m_coordinateSystemDirection;
}
void TbSersorPara::SetCoordinateSystemDirection(int coordinateSystemDirection) {
	this->m_coordinateSystemDirection = coordinateSystemDirection;
}
char TbSersorPara::GetIsReference() {
	return m_isReference;
}
void TbSersorPara::SetIsReference(char isReference) {
	this->m_isReference = isReference;
}
int TbSersorPara::GetEngineeringUnits() {
	return m_engineeringUnits;
}
void TbSersorPara::SetEngineeringUnits(int engineeringUnits) {
	this->m_engineeringUnits = engineeringUnits;
}
float TbSersorPara::GetSensitivity() {
	return m_sensitivity;
}
void TbSersorPara::SetSensitivity(float sensitivity) {
	this->m_sensitivity = sensitivity;
}
float TbSersorPara::GetMileageRange() {
	return m_mileageRange;
}
void TbSersorPara::SetMileageRange(float mileageRange) {
	this->m_mileageRange = mileageRange;
}
int TbSersorPara::GetIntegralType() {
	return m_integralType;
}
void TbSersorPara::SetIntegralType(int integralType) {
	this->m_integralType = integralType;
}
int TbSersorPara::GetIntegralUnits() {
	return m_integralUnits;
}
void TbSersorPara::SetIntegralUnits(int integralUnits) {
	this->m_integralUnits = integralUnits;
}
int TbSersorPara::GetInputMethod() {
	return m_inputMethod;
}
void TbSersorPara::SetInputMethod(int inputMethod) {
	this->m_inputMethod = inputMethod;
}
char TbSersorPara::GetAntiAliasingFiltering() {
	return m_antiAliasingFiltering;
}
void TbSersorPara::SetAntiAliasingFiltering(char antiAliasingFiltering) {
	this->m_antiAliasingFiltering = antiAliasingFiltering;
}
float TbSersorPara::GetMaxFrequency() {
	return m_maxFrequency;
}
void TbSersorPara::SetMaxFrequency(float maxFrequency) {
	this->m_maxFrequency = maxFrequency;
}

char TbSersorPara::GetSersorIsUsed(){
	return m_isUsed;
}
void TbSersorPara::SetSersorIsUsed(char isUsed){
	this->m_isUsed = isUsed;
}