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
vector<TbSensorPara> & TbSignal::GetSensorParaVector() {
	return m_sensorParaVector;
}
void TbSignal::SetSensorParaVector(vector<TbSensorPara> sensorParaVector) {
	this->m_sensorParaVector = sensorParaVector;
}

TbDetectedDevice & TbSignal::GetDetectedDevice() {
	return m_detectedDevice;
}
void TbSignal::SetDetectedDevice(TbDetectedDevice detectedDevice) {
	this->m_detectedDevice = detectedDevice;
}
CString TbSignal::GetSignalStatus() {
	return m_signalStatus;
}
void TbSignal::SetSignalStatus(CString signal_status) {
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