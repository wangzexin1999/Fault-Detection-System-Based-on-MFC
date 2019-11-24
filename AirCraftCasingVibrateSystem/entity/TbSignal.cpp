#include "stdafx.h"
#include "TbSignal.h"


TbSignal::TbSignal(CString signalId)
{

	m_productId = 0;
	m_signalStatus = 0;
	m_projectId = 0;
	m_testingDeviceId = 0;
}


TbSignal::~TbSignal()
{
}

CString TbSignal::GetSignalId() {
	return m_signalId;
}
void TbSignal::SetSignalId(CString signalId) {
	this->m_signalId = signalId;
}

CString TbSignal::GetSignalType() {
	return m_signalType;
}
void TbSignal::SetSignalType(CString signalType) {
	this->m_signalType = signalType;
}

int TbSignal::GetProductId() {
	return m_productId;
}
void TbSignal::SetProductId(int productId) {
	this->m_productId = productId;
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
int   TbSignal::GetProjectId(){
	return this->m_projectId;
}
int   TbSignal::GetTestingDeviceId(){
	return m_testingDeviceId;
}
void TbSignal::SetTestingDeviceId(int  testingDeviceId){
	m_testingDeviceId = testingDeviceId;
}
void TbSignal::SetCollectionStatus(CString para){
	m_collectionStatus = para;
}
CString TbSignal::GetCollectionStatus(){
	return m_collectionStatus;
}




CString TbSignal::GetStartTime(){
	return m_startTime;
}
void TbSignal::SetStartTime(CString startTime){
	m_startTime = startTime;
}

CString TbSignal::GetEndTime(){
	return m_endTime;
}
void TbSignal::SetEndTime(CString endTime){
	m_endTime = endTime;
}


void TbSignal::SetSensorInfo(CString sensorInfo){
	m_sensorInfo = sensorInfo;
}
CString TbSignal::GetSensorInfo(){
	return m_sensorInfo;
}