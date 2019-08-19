#include "stdafx.h"
#include "TbTestingDevice.h"


TbTestingDevice::TbTestingDevice(int testingdeviceID){
	m_testingdeviceId = testingdeviceID;
}

bool TbTestingDevice::operator == (TbTestingDevice testingDevice){
	bool tag = true;
	if (m_testingdeviceId != testingDevice.GetTestingdeviceId()) tag = false;
	if (m_testingdeviceIp != testingDevice.GetTestingdeviceIp()) tag = false;
	if (m_testingdeviceName != testingDevice.GetTestingdeviceName()) tag = false;
	if (m_testingdeviceBorndate!= testingDevice.GetTestingdeviceBorndate()) tag = false;
	if (m_testingdeviceImportdate != testingDevice.GetTestingdeviceImportdate()) tag = false;
	if (m_testingdeviceStatus != testingDevice.GetTestingDeviceStatus()) tag = false;
	return tag;
}

bool TbTestingDevice::operator != (TbTestingDevice testingDevice){
	return *this == testingDevice ? false : true;
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

void TbTestingDevice::SetTestingDeviceStatus(int status){
	m_testingdeviceStatus = status;
}
int TbTestingDevice::GetTestingDeviceStatus(){
	return m_testingdeviceStatus;
}