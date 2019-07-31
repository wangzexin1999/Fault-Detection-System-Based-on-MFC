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


int TbTestingDevicePara::GetSamplingFrequency() {
	return m_samplingFrequency;
}

void TbTestingDevicePara::SetSamplingFrequency(int samplingFrequency) {
	this->m_samplingFrequency = samplingFrequency;
}

int TbTestingDevicePara::GetAnalysisFrequency() {
	return m_analysisFrequency;
}

void TbTestingDevicePara::SetAnalysisFrequency(int analysisFrequency) {
	this->m_analysisFrequency = analysisFrequency;
}

int TbTestingDevicePara::GetSamplingMethod() {
	return m_samplingMethod;
}

void TbTestingDevicePara::SetSamplingMethod(int samplingMethod) {
	this->m_samplingMethod = samplingMethod;
}

int TbTestingDevicePara::GetTriggerMethod() {
	return m_triggerMethod;
}

void TbTestingDevicePara::SetTriggerMethod(int triggerMethod) {
	this->m_triggerMethod = triggerMethod;
}

int TbTestingDevicePara::GetDatablockCount() {
	return m_datablockCount;
}

void TbTestingDevicePara::SetDatablockCount(int datablockCount) {
	this->m_datablockCount = datablockCount;
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

int TbTestingDevicePara::GetSamplingBatchs() {
	return m_samplingBatchs;
}

void TbTestingDevicePara::SetSamplingBatchs(int samplingBatchs) {
	this->m_samplingBatchs = samplingBatchs;
}