#include "stdafx.h"
#include "TbSumsignal.h"


TbSumsignal::TbSumsignal(CString sumsignalId)
{

	m_productId = 0;
	m_sumsignalStatus = 0;
	m_projectId = 0;
	m_collectionparasId = 0;
}


TbSumsignal::~TbSumsignal()
{
}

CString TbSumsignal::GetSumsignalId() {
	return m_sumsignalId;
}
void TbSumsignal::SetSumsignalId(CString sumsignalId) {
	this->m_sumsignalId = sumsignalId;
}

CString TbSumsignal::GetSumsignalType() {
	return m_sumsignalType;
}
void TbSumsignal::SetSumsignalType(CString sumsignalType) {
	this->m_sumsignalType = sumsignalType;
}

int TbSumsignal::GetProductId() {
	return m_productId;
}
void TbSumsignal::SetProductId(int productId) {
	this->m_productId = productId;
}
char TbSumsignal::GetSumsignalStatus() {
	return m_sumsignalStatus;
}
void TbSumsignal::SetSumsignalStatus(char sumsignalStatus) {
	this->m_sumsignalStatus = sumsignalStatus;
}
CString TbSumsignal::GetDataUrl() {
	return m_dataUrl;
}
void TbSumsignal::SetDataUrl(CString dataUrl) {
	this->m_dataUrl = dataUrl;
}
void TbSumsignal::SetProjectId(int projectId){
	this->m_projectId = projectId;
}
int   TbSumsignal::GetProjectId(){
	return this->m_projectId;
}
int   TbSumsignal::GetCollectionparasId(){
	return m_collectionparasId;
}
void TbSumsignal::SetCollectionparasId(int  collectionparasId){
	m_collectionparasId = collectionparasId;
}
void TbSumsignal::SetCollectionStatus(CString para){
	m_collectionStatus = para;
}
CString TbSumsignal::GetCollectionStatus(){
	return m_collectionStatus;
}




CString TbSumsignal::GetStartTime(){
	return m_startTime;
}
void TbSumsignal::SetStartTime(CString startTime){
	m_startTime = startTime;
}

CString TbSumsignal::GetEndTime(){
	return m_endTime;
}
void TbSumsignal::SetEndTime(CString endTime){
	m_endTime = endTime;
}


void TbSumsignal::SetChannelInfo(CString channelInfo){
	m_channelInfo = channelInfo;
}
CString TbSumsignal::GetChannelInfo(){
	return m_channelInfo;
}