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
TbSersorPara & TbSignal::GetSensorPara() {
	return m_sensorPara;
}
void TbSignal::SetSensorPara(TbSersorPara sensorPara) {
	this->m_sensorPara = sensorPara;
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