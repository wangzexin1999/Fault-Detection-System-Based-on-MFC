#pragma once
#include "TbDetectedDeviceDao.h"

class DetectedDeviceService
{
public:
	TbDetectedDeviceDao m_detectedDevice;

	DetectedDeviceService();

	~DetectedDeviceService();

	bool GetAllDetectedDevice(vector<TbDetectedDeviceDao> & TbDetectedDeviceDaoVec);
};

