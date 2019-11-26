#include "stdafx.h"
#include "TbTestingDevice.h"


TbTestingDevice::TbTestingDevice(){
	m_id = 0;
	m_collectionTimes = 0;
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



TbDictionary  &  TbTestingDevice::GetSampleFrequency(){
	return m_sampleFrequency;
}
TbDictionary  &  TbTestingDevice::GetAnalysisFrequency(){
	return m_analysisFrequency;
}
TbDictionary  &  TbTestingDevice::GetCollectionMethod(){
	return m_collectionMethod;
}
TbDictionary  &  TbTestingDevice::GetCollectionPoint(){
	return m_collectionPoint;
}

void TbTestingDevice::SetSampleFrequency(TbDictionary sampleFrequency){
	m_sampleFrequency = sampleFrequency;
}
void TbTestingDevice::SetAnalysisFrequency(TbDictionary analysisFrequency){
	m_analysisFrequency = analysisFrequency;
}
void TbTestingDevice::SetCollectionMethod(TbDictionary collectionMethod){
	m_collectionMethod = collectionMethod;
}
void TbTestingDevice::SetCollectionPoint(TbDictionary collectionPoint){
	m_collectionPoint = collectionPoint;
}

int TbTestingDevice::GetCollectionTimes() {
	return m_collectionTimes;
}

void TbTestingDevice::SetCollectionTimes(int collectionTimes) {
	this->m_collectionTimes = collectionTimes;
}

