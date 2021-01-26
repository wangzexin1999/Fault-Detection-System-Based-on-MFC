#include "stdafx.h"
#include "TbChannel.h"


TbChannel::TbChannel(int id){
	m_id = id; 
	SetSensitivity(0);
	SetTriggerMagnitude(0);
	SetIsReference(0);
	SetPointNum(0);
	SetAntiAliasingFiltering(0);
}


TbChannel::~TbChannel(){}


void TbChannel::SetId(int id){
	m_id = id;
}
int TbChannel::GetId(){
	return m_id;
}

CString TbChannel::GetChannelCode() {
	return m_channelCode;
}
void TbChannel::SetChannelCode(CString channelCode) {
	this->m_channelCode = channelCode;
}

TbDictionary & TbChannel::GetChannelStatus() {
	return m_channelStatus;
}
void TbChannel::SetChannelStatus(TbDictionary channelStatus) {
	this->m_channelStatus = channelStatus;
}

CString TbChannel::GetChannelDesc() {
	return m_channelDesc;
}
void TbChannel::SetChannelDesc(CString channelDesc) {
	this->m_channelDesc = channelDesc;
}

TbDictionary & TbChannel::GetWindowType() {
	return m_windowType;
}
void TbChannel::SetWindowType(TbDictionary windowType) {
	this->m_windowType = windowType;
}
float TbChannel::GetTriggerMagnitude() {
	return m_triggerMagnitude;
}
void TbChannel::SetTriggerMagnitude(float triggerMagnitude) {
	this->m_triggerMagnitude = triggerMagnitude;
}
TbDictionary & TbChannel::GetTriggerPolarity() {
	return m_triggerPolarity;
}
void TbChannel::SetTriggerPolarity(TbDictionary triggerPolarity) {
	this->m_triggerPolarity = triggerPolarity;
}
int TbChannel::GetPointNum() {
	return m_pointNum;
}
void TbChannel::SetPointNum(int pointNum) {
	this->m_pointNum = pointNum;
}
TbDictionary & TbChannel::GetCoordinateSystem() {
	return m_coordinateSystem;
}
void TbChannel::SetCoordinateSystem(TbDictionary coordinateSystem) {
	this->m_coordinateSystem = coordinateSystem;
}
TbDictionary & TbChannel::GetCoordinateSystemDirection() {
	return m_coordinateSystemDirection;
}
void TbChannel::SetCoordinateSystemDirection(TbDictionary coordinateSystemDirection) {
	this->m_coordinateSystemDirection = coordinateSystemDirection;
}
char TbChannel::GetIsReference() {
	return m_isReference;
}
void TbChannel::SetIsReference(char isReference) {
	this->m_isReference = isReference;
}
TbDictionary & TbChannel::GetEngineeringUnits() {
	return m_engineeringUnits;
}
void TbChannel::SetEngineeringUnits(TbDictionary engineeringUnits) {
	this->m_engineeringUnits = engineeringUnits;
}
//灵敏度
float TbChannel::GetSensitivity() {
	return m_sensitivity;
}
void TbChannel::SetSensitivity(float sensitivity) {
	this->m_sensitivity = sensitivity;
}
//满度量程
std::pair<int, CString> TbChannel::GetFullValue() {
	return m_fullvalue;
}
void TbChannel::SetFullValue(std::pair<int, CString> fullvalue) {
	this->m_fullvalue = fullvalue;
}

TbDictionary & TbChannel::GetIntegralType() {
	return m_integralType;
}
void TbChannel::SetIntegralType(TbDictionary integralType) {
	this->m_integralType = integralType;
}
TbDictionary & TbChannel::GetIntegralUnits() {
	return m_integralUnits;
}
void TbChannel::SetIntegralUnits(TbDictionary integralUnits) {
	this->m_integralUnits = integralUnits;
}
//TbDictionary & TbChannel::GetInputMode() {
//	return m_inputMode;
//}
//void TbChannel::SetInputMode(TbDictionary inputMethod) {
//	this->m_inputMode = inputMethod;
//}
//输入方式更改类型
std::pair<int, CString>  TbChannel::GetInputMode() {
	return m_inputMode;
}
void TbChannel::SetInputMode(std::pair<int, CString> inputMethod) {
	this->m_inputMode = inputMethod;
}
char TbChannel::GetAntiAliasingFiltering() {
	return m_antiAliasingFiltering;
}
void TbChannel::SetAntiAliasingFiltering(char antiAliasingFiltering) {
	this->m_antiAliasingFiltering = antiAliasingFiltering;
}
//上限频率
std::pair<int, CString> TbChannel::GetUpFreq() {
	return m_upFreq;
}
void TbChannel::SetUpFreq(std::pair<int, CString> maxFrequency) {
	this->m_upFreq = maxFrequency;
}


TbSensor & TbChannel::GetSensor() {
	return m_sensor;
}
void TbChannel::SetSensor(TbSensor sensor) {
	this->m_sensor = sensor;
}

std::pair<int, CString> TbChannel::GetElcPressure() {
	return m_elcpressure;
}

void TbChannel::SetElcPressure(std::pair<int, CString> elcPressure) {
	this->m_elcpressure = elcPressure;
}

int TbChannel::GetProjectId(){
	return m_projectId;
}
void TbChannel::SetProjectId(int projectId){
	m_projectId = projectId;
}

std::pair<int, CString> & TbChannel::GetMessureType(){
	return m_messureType;
}
void TbChannel::SetMessureType(std::pair<int, CString> messureType){
	m_messureType = messureType;
}