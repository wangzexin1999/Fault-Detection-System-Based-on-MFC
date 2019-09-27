#include "stdafx.h"
#include "TbTestingDevice.h"


TbTestingDevice::TbTestingDevice(){
	m_id = 0;
	m_delayblockCount = 0;
	m_triggerCount = 0;
	m_collectionBatchs = 0;
}

bool TbTestingDevice::operator == (TbTestingDevice testingDevice){
	bool tag = true;
	if (m_id != testingDevice.GetId()) tag = false;
	if (m_testingDeviceIp != testingDevice.GetTestingDeviceIp()) tag = false;
	//////
	return tag;
}

bool TbTestingDevice::operator != (TbTestingDevice testingDevice){
	return *this == testingDevice ? false : true;
}
TbTestingDevice::~TbTestingDevice()
{
}

void TbTestingDevice::SetId(int id){
	m_id = id;
}
int TbTestingDevice::GetId(){
	return m_id;
}

CString TbTestingDevice::GetTestingDeviceIp() {
	return m_testingDeviceIp;
}

void TbTestingDevice::SetTestingDeviceIp(CString testingdeviceIp) {
	this->m_testingDeviceIp = testingdeviceIp;
}



TbDictionary  &  TbTestingDevice::GetCollectionFrequency(){
	return m_collectionFrequency;
}
TbDictionary  &  TbTestingDevice::GetAnalysisFrequency(){
	return m_analysisFrequency;
}
TbDictionary  &  TbTestingDevice::GetCollectionMethod(){
	return m_collectionMethod;
}
TbDictionary  &  TbTestingDevice::GetTriggerMethod(){
	return m_triggerMethod;
}
TbDictionary  &  TbTestingDevice::GetDatablockCount(){
	return m_datablockCount;
}

void TbTestingDevice::SetCollectionFrequency(TbDictionary collectionFrequency){
	m_collectionFrequency = collectionFrequency;
}
void TbTestingDevice::SetAnalysisFrequency(TbDictionary analysisFrequency){
	m_analysisFrequency = analysisFrequency;
}
void TbTestingDevice::SetCollectionMethod(TbDictionary collectionMethod){
	m_collectionMethod = collectionMethod;
}
void TbTestingDevice::SetTriggerMethod(TbDictionary triggerMethod){
	m_triggerMethod = triggerMethod;
}
void TbTestingDevice::SetDatablockCount(TbDictionary datablockCount){
	m_datablockCount = datablockCount;
}

int TbTestingDevice::GetDelayblockCount() {
	return m_delayblockCount;
}

void TbTestingDevice::SetDelayblockCount(int delayblockCount) {
	this->m_delayblockCount = delayblockCount;
}

int TbTestingDevice::GetTriggerCount() {
	return m_triggerCount;
}

void TbTestingDevice::SetTriggerCount(int triggerCount) {
	this->m_triggerCount = triggerCount;
}

int TbTestingDevice::GetCollectionBatchs() {
	return m_collectionBatchs;
}

void TbTestingDevice::SetCollectionBatchs(int collectionBatchs) {
	this->m_collectionBatchs = collectionBatchs;
}