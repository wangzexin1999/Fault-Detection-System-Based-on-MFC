#include "stdafx.h"
#include "DetectedDeviceService.h"

DetectedDeviceService::DetectedDeviceService()
{

}


DetectedDeviceService::~DetectedDeviceService()
{
}
bool DetectedDeviceService::GetAllDetectedDevice(vector<TbDetectedDeviceDao> & TbDetectedDeviceDaoVec){
	 return m_detectedDevice.SelectObjectsByCondition(TbDetectedDeviceDaoVec, "1=1");
}
