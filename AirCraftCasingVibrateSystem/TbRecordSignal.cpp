#include "stdafx.h"
#include "TbRecordSignal.h"


TbRecordSignal::TbRecordSignal()
{
	m_signalId = 0;
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


TbProduct & TbRecordSignal::GetProduct() {
	return m_product;
}
void TbRecordSignal::SetProduct(TbProduct product) {
	this->m_product = product;
}
char TbRecordSignal::GetSignalStatus() {
	return m_signalStatus;
}
void TbRecordSignal::SetSignalStatus(char signal_status) {
	this->m_signalStatus = signal_status;
}
void TbRecordSignal::SetProject(TbProject project){
	this->m_project = project;
}
TbProject & TbRecordSignal::GetProject(){
	return this->m_project;
}

TbTestingDevice & TbRecordSignal::GetTestingDevice(){
	return m_testingDevice;
}
void TbRecordSignal::SetTesingDevice(TbTestingDevice  testingDevice){
	m_testingDevice = testingDevice;
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