#include "stdafx.h"
#include "TbTestingDevice.h"


TbTestingDevice::TbTestingDevice()
{
}


TbTestingDevice::~TbTestingDevice()
{
}
int TbTestingDevice::GetTestingdeviceId() {
	return m_testingdeviceId;
}

void TbTestingDevice::SetTestingdeviceId(int testingdeviceId) {
	this->m_testingdeviceId = testingdeviceId;
}

CString TbTestingDevice::GetTestingdeviceIp() {
	return m_testingdeviceIp;
}

void TbTestingDevice::SetTestingdeviceIp(CString testingdeviceIp) {
	this->m_testingdeviceIp = testingdeviceIp;
}

CString TbTestingDevice::GetTestingdeviceName() {
	return m_testingdeviceName;
}

void TbTestingDevice::SetTestingdeviceName(CString testingdeviceName) {
	this->m_testingdeviceName = testingdeviceName ;
}

CString TbTestingDevice::GetTestingdeviceBorndate() {
	return m_testingdeviceBorndate;
}

void TbTestingDevice::SetTestingdeviceBorndate(CString testingdeviceBorndate) {
	this->m_testingdeviceBorndate = testingdeviceBorndate ;
}

CString TbTestingDevice::GetTestingdeviceImportdate() {
	return m_testingdeviceImportdate;
}

void TbTestingDevice::SetTestingdeviceImportdate(CString testingdeviceImportdate) {
	this->m_testingdeviceImportdate = testingdeviceImportdate ;
}