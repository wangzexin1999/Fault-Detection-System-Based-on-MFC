#pragma once
class TbDetectedDevice
{
public:
	TbDetectedDevice();
	~TbDetectedDevice();

	int m_detectedDeviceId;
	CString m_detectedDeviceName;
	CString m_detectedDeviceType;

	int GetDetecteddeviceId();
	void SetDetecteddeviceId(int detecteddeviceId);
	CString GetDetecteddeviceName();
	void SetDetecteddeviceName(CString detecteddeviceName);
	void SetDetecteddeviceType(CString detecteddeviceType);
	CString GetDetecteddeviceType();

};


