#include "stdafx.h"
#include "TbSignal.h"


TbSignal::TbSignal(int signalId)
{

	m_signalId = 0;
	m_productId = 0;
	m_signalStatus = 0;
	m_projectId = 0;
	m_testingDeviceId = 0;
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

void TbSignal::SetPointCount(int pointCount){
	m_pointCount = pointCount;
}
int TbSignal::GetPointCount(){
	return m_pointCount;
}


CString TbSignal::GetSaveTime(){
	return m_saveTime;
}
void TbSignal::SetSaveTime(CString saveTime){
	m_saveTime = saveTime;
}

void TbSignal::SetCollectionPara(CString collectionPara){
	m_collectionPara = collectionPara;
}
CString TbSignal::GetCollectionPara(){
	return m_collectionPara;
}