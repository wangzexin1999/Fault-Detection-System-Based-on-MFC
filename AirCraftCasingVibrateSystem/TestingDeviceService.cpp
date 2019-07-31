#include "stdafx.h"
#include "TestingDeviceService.h"


TestingDeviceService::TestingDeviceService()
{
}


TestingDeviceService::~TestingDeviceService()
{

}

bool TestingDeviceService::GetAllTestingDevice(vector<TbTestingDeviceDao> & tbTestingVec){
	return m_testingDevice.SelectObjectsByCondition(tbTestingVec,"1=1");
}
