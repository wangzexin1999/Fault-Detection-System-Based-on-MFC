#include "stdafx.h"
#include "TbSignal.h"


TbSignal::TbSignal()
{
}


TbSignal::~TbSignal()
{
}

int TbSignal::GetSignalId() {
	return m_signalId;
}
void TbSignal::SetSignalId(int signalId) {
	this->m_signalId = signalId;
}
CString TbSignal::GetStartTime() {
	return m_startTime;
}
void TbSignal::SetStartTime(CString startTime) {
	this->m_startTime = startTime;
}
CString TbSignal::GetEndTime() {
	return m_endTime;
}
void TbSignal::SetEndTime(CString endTime) {
	this->m_endTime = endTime;
}
CString TbSignal::GetSignalType() {
	return m_signalType;
}
void TbSignal::SetSignalType(CString signalType) {
	this->m_signalType = signalType;
}


TbDetectedDevice & TbSignal::GetDetectedDevice() {
	return m_detectedDevice;
}
void TbSignal::SetDetectedDevice(TbDetectedDevice detectedDevice) {
	this->m_detectedDevice = detectedDevice;
}
char TbSignal::GetSignalStatus() {
	return m_signalStatus;
}
void TbSignal::SetSignalStatus(char signal_status) {
	this->m_signalStatus = signal_status;
}
CString TbSignal::GetDataUrl() {
	return m_dataUrl;
}
void TbSignal::SetDataUrl(CString dataUrl) {
	this->m_dataUrl = dataUrl;
}
void TbSignal::SetProjectId(int projectId){
	this->m_projectId = projectId;
}
int TbSignal::GetProjectId(){
	return this->m_projectId;
}
TbSensor & TbSignal::GetSensor(){
	return m_sensor;
}
void TbSignal::SetSensor(TbSensor  sensor){
	m_sensor = sensor;
}
TbTestingDevice & TbSignal::GetTestingDevice(){
	return m_testingDevice;
}
void TbSignal::SetTesingDevice(TbTestingDevice  testingDevice){
	m_testingDevice = testingDevice;
}