#include "stdafx.h"
#include "TbCollectionparas.h"


TbCollectionparas::TbCollectionparas(){
	m_id = 0;
	m_sampleBatch = 0;
	m_dataBlocks= 0;
	m_delayBlocks = 0;
	m_triggerTimes = 0;
	m_equipmentId = 1;
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

int TbCollectionparas::GetEquipmentId() {
	return m_equipmentId;
}

void TbCollectionparas::SetEquipmentId(int equipmentId) {
	this->m_equipmentId = equipmentId;
}

std::pair<int, int> TbCollectionparas::GetSampleFrequency(){
	return m_sampleFrequency;
}

TbDictionary  &  TbCollectionparas::GetCollectionMethod(){
	return m_collectionMethod;
}

TbDictionary  &  TbCollectionparas::GetTriggerMethod(){
	return m_triggerMethod;
}

void TbCollectionparas::SetSampleFrequency(std::pair<int, int> sampleFrequency){
	m_sampleFrequency = sampleFrequency;
}
void TbCollectionparas::SetCollectionMethod(TbDictionary collectionMethod){
	m_collectionMethod = collectionMethod;
}
void TbCollectionparas::SetTriggerMethod(TbDictionary triggerMethod){
	m_triggerMethod = triggerMethod;
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

void TbCollectionparas::SetLine(int line){
	this->line = line;
}
int TbCollectionparas::GetLine(){
	return line;
}