#include "stdafx.h"
#include "TbDetectedDevice.h"


TbDetectedDevice::TbDetectedDevice()
{
}


TbDetectedDevice::~TbDetectedDevice()
{
}

int TbDetectedDevice::GetDetecteddeviceId() {
	return m_detectedDeviceId;
}

void TbDetectedDevice::SetDetecteddeviceId(int detecteddeviceId) {
	this->m_detectedDeviceId = detecteddeviceId;
}

CString TbDetectedDevice::GetDetecteddeviceName() {
	return m_detectedDeviceName;
}

void TbDetectedDevice::SetDetecteddeviceName(CString detecteddeviceName) {
	this->m_detectedDeviceName = detecteddeviceName;
}

CString TbDetectedDevice::GetDetecteddeviceType() {
	return m_detectedDeviceType;
}
	
void TbDetectedDevice::SetDetecteddeviceType(CString detecteddeviceType) {
	this->m_detectedDeviceType = detecteddeviceType;
}