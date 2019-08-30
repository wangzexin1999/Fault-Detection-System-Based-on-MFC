#include "stdafx.h"
#include "TbSignal.h"


TbSignal::TbSignal(int signalId, int sensorCount)
{
	m_signalId = signalId;
	m_sensorCount = sensorCount;
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


TbProduct & TbSignal::GetProduct() {
	return m_product;
}
void TbSignal::SetProduct(TbProduct product) {
	this->m_product = product;
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
void TbSignal::SetProject(TbProject project){
	this->m_project = project;
}
TbProject & TbSignal::GetProject(){
	return this->m_project;
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

void TbSignal::SetSensorCount(int sensorCount){
	m_sensorCount = sensorCount;
}
int TbSignal::GetSensorCount(){
	return m_sensorCount;
}