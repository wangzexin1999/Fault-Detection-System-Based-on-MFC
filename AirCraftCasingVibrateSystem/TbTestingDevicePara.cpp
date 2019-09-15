#include "stdafx.h"
#include "TbTestingDevicePara.h"


TbTestingDevicePara::TbTestingDevicePara()
{
}

TbTestingDevicePara::~TbTestingDevicePara()
{
}

int TbTestingDevicePara::GetTestingdeviceparaId() {
	return	m_testingdeviceparaId;
}

void TbTestingDevicePara::SetTestingdeviceparaId(int testingdeviceparaId) {
	this->m_testingdeviceparaId = testingdeviceparaId;
}

TbTestingDevice & TbTestingDevicePara::GetTestingdevice() {
	return m_testingDevice;
}

void TbTestingDevicePara::SetTestingdevice(TbTestingDevice testingdevice) {
	this->m_testingDevice = testingdevice;
}

TbDictionary  &  TbTestingDevicePara::GetCollectionFrequency(){
	return m_collectionFrequency;
}
TbDictionary  &  TbTestingDevicePara::GetAnalysisFrequency(){
	return m_analysisFrequency;
}
TbDictionary  &  TbTestingDevicePara::GetCollectionMethod(){
	return m_collectionMethod;
}
TbDictionary  &  TbTestingDevicePara::GetTriggerMethod(){
	return m_triggerMethod;
}
TbDictionary  &  TbTestingDevicePara::GetDatablockCount(){
	return m_datablockCount;
}

void TbTestingDevicePara::SetCollectionFrequency(TbDictionary collectionFrequency){
	m_collectionFrequency = collectionFrequency;
}
void TbTestingDevicePara::SetAnalysisFrequency(TbDictionary analysisFrequency){
	m_analysisFrequency = analysisFrequency;
}
void TbTestingDevicePara::SetCollectionMethod(TbDictionary collectionMethod){
	m_collectionMethod = collectionMethod;
}
void TbTestingDevicePara::SetTriggerMethod(TbDictionary triggerMethod){
	m_triggerMethod = triggerMethod;
}
void TbTestingDevicePara::SetDatablockCount(TbDictionary datablockCount){
	m_datablockCount = datablockCount;
}

int TbTestingDevicePara::GetDelayblockCount() {
	return m_delayblockCount;
}

void TbTestingDevicePara::SetDelayblockCount(int delayblockCount) {
	this->m_delayblockCount = delayblockCount;
}

int TbTestingDevicePara::GetTriggerCount() {
	return m_triggerCount;
}

void TbTestingDevicePara::SetTriggerCount(int triggerCount) {
	this->m_triggerCount = triggerCount;
}

int TbTestingDevicePara::GetCollectionBatchs() {
	return m_collectionBatchs;
}

void TbTestingDevicePara::SetCollectionBatchs(int collectionBatchs) {
	this->m_collectionBatchs = collectionBatchs;
}