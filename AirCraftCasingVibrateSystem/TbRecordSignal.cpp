#include "stdafx.h"
#include "TbRecordSignal.h"


TbRecordSignal::TbRecordSignal()
{
}


TbRecordSignal::~TbRecordSignal()
{
}



int TbRecordSignal::GetSignalId() {
	return m_signalId;
}
void TbRecordSignal::SetSignalId(int signalId) {
	this->m_signalId = signalId;
}
CString TbRecordSignal::GetStartTime() {
	return m_startTime;
}
void TbRecordSignal::SetStartTime(CString startTime) {
	this->m_startTime = startTime;
}
CString TbRecordSignal::GetEndTime() {
	return m_endTime;
}
void TbRecordSignal::SetEndTime(CString endTime) {
	this->m_endTime = endTime;
}
CString TbRecordSignal::GetSignalType() {
	return m_signalType;
}
void TbRecordSignal::SetSignalType(CString signalType) {
	this->m_signalType = signalType;
}


int TbRecordSignal::GetProductId() {
	return m_productId;
}
void TbRecordSignal::SetProductId(int productId) {
	this->m_productId = productId;
}
char TbRecordSignal::GetSignalStatus() {
	return m_signalStatus;
}
void TbRecordSignal::SetSignalStatus(char signal_status) {
	this->m_signalStatus = signal_status;
}
void TbRecordSignal::SetProjectId(int projectId){
	this->m_projectId = projectId;
}
int TbRecordSignal::GetProjectId(){
	return this->m_projectId;
}

int TbRecordSignal::GetTestingDeviceId(){
	return m_testingDeviceId;
}

void TbRecordSignal::SetTesingDeviceId(int  testingDeviceId){
	m_testingDeviceId = testingDeviceId;
}
void TbRecordSignal::SetCollectionStatus(CString collectionStatus){
	this->m_collectionStatus = collectionStatus;
}
CString TbRecordSignal::GetCollectionStatus(){
	return this->m_collectionStatus;
}
void TbRecordSignal::SetSensorInfo(CString sensorInfo){
	this->m_sensorInfo = sensorInfo;
}
CString TbRecordSignal::GetSensorInfo(){
	return this->m_sensorInfo;
}