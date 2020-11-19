#include "stdafx.h"
#include "TbCollectionparas.h"


TbCollectionparas::TbCollectionparas(){
	m_id = 0;
	m_sampleBatch = 0;
	m_dataBlocks= 0;
	m_delayBlocks = 0;
	m_triggerTimes = 0;
	m_equipmentId = "1";
}

bool TbCollectionparas::operator == (TbCollectionparas collectionparas){
	bool tag = true;
	if (m_id != collectionparas.GetId()) tag = false;
	if (m_equipmentId != collectionparas.GetEquipmentId()) tag = false;
	//////
	return tag;
}

bool TbCollectionparas::operator != (TbCollectionparas collectionparas){
	return *this == collectionparas ? false : true;
}
TbCollectionparas::~TbCollectionparas()
{
}

void TbCollectionparas::SetId(int id){
	m_id = id;
}
int TbCollectionparas::GetId(){
	return m_id;
}

CString TbCollectionparas::GetEquipmentId() {
	return m_equipmentId;
}

void TbCollectionparas::SetEquipmentId(CString equipmentId) {
	this->m_equipmentId = equipmentId;
}



double TbCollectionparas::GetSampleFrequency(){
	return m_sampleFrequency;
}
double TbCollectionparas::GetAnalysisFrequency(){
	return m_analysisFrequency;
}
TbDictionary  &  TbCollectionparas::GetCollectionMethod(){
	return m_collectionMethod;
}
TbDictionary  &  TbCollectionparas::GetTriggerMethod(){
	return m_triggerMethod;
}
TbDictionary  &  TbCollectionparas::GetCollectionPoint(){
	return m_collectionPoint;
}

void TbCollectionparas::SetSampleFrequency(double sampleFrequency){
	m_sampleFrequency = sampleFrequency;
}
void TbCollectionparas::SetAnalysisFrequency(double analysisFrequency){
	m_analysisFrequency = analysisFrequency;
}
void TbCollectionparas::SetCollectionMethod(TbDictionary collectionMethod){
	m_collectionMethod = collectionMethod;
}
void TbCollectionparas::SetTriggerMethod(TbDictionary triggerMethod){
	m_triggerMethod = triggerMethod;
}
void TbCollectionparas::SetCollectionPoint(TbDictionary collectionPoint){
	m_collectionPoint = collectionPoint;
}

int TbCollectionparas::GetSampleBatch() {
	return m_sampleBatch;
}

void TbCollectionparas::SetSampleBatch(int sampleBatch) {
	this->m_sampleBatch = sampleBatch;
}


int TbCollectionparas::GetDataBlocks() {
	return m_dataBlocks;
}

void TbCollectionparas::SetDataBlocks(int dataBlocks) {
	this->m_dataBlocks = dataBlocks;
}

int TbCollectionparas::GetDelayBlocks() {
	return m_delayBlocks;
}

void TbCollectionparas::SetDelayBlocks(int delayBlocks) {
	this->m_delayBlocks = delayBlocks;
}

int TbCollectionparas::GetTriggerTimes() {
	return m_triggerTimes;
}

void TbCollectionparas::SetTriggerTimes(int triggerTimes) {
	this->m_triggerTimes = triggerTimes;
}