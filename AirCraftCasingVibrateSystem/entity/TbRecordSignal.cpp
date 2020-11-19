#include "stdafx.h"
#include "TbRecordSignal.h"


TbRecordSignal::TbRecordSignal(CString signalId, CString startTime, CString endTime, CString signalType, char signalStatus, TbProject project, TbProduct product, TbCollectionparas collectionparas, CString collectionStatus, CString channelInfo){
	SetCollectionStatus(collectionStatus);
	SetStartTime(startTime);
	SetEndTime(endTime);
	SetProject(project);
	SetProduct(product);
	SetChannelInfo(channelInfo);
	SetSignalStatus(signalStatus);
	SetSignalType(signalType);
	SetCollectionparas(collectionparas);
}

TbRecordSignal::TbRecordSignal() :m_signalStatus(0), m_startPos(0), m_endPos(0){

}


TbRecordSignal::~TbRecordSignal()
{
}
int TbRecordSignal::GetId(){
	return m_id;
}
void TbRecordSignal::SetId(int id){
	m_id = id;
}

CString TbRecordSignal::GetSignalId() {
	return m_signalId;
}
void TbRecordSignal::SetSignalId(CString signalId) {
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
long long  TbRecordSignal::GetStartPos(){
	return m_startPos;
}
void TbRecordSignal::SetStartPos(long long startPos){
	m_startPos = startPos;
}

long long  TbRecordSignal::GetEndPos(){
	return	m_endPos;
}
void TbRecordSignal::SetEndPos(long long endPos){
	m_endPos = endPos;
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

TbCollectionparas & TbRecordSignal::GetCollectionparas(){
	return m_collectionparas;
}
void TbRecordSignal::SetCollectionparas(TbCollectionparas  collectionparas){
	m_collectionparas = collectionparas;
}

void TbRecordSignal::SetCollectionStatus(CString collectionStatus){
	this->m_collectionStatus = collectionStatus;
}
CString TbRecordSignal::GetCollectionStatus(){
	return this->m_collectionStatus;
}
void TbRecordSignal::SetChannelInfo(CString channelInfo){
	this->m_channelInfo = channelInfo;
}
CString TbRecordSignal::GetChannelInfo(){
	return this->m_channelInfo;
}