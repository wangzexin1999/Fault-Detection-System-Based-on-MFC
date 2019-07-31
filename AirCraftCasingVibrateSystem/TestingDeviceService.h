#pragma once
#include"TbTestingDeviceDao.h"
class TestingDeviceService
{
public:
	TestingDeviceService();

	~TestingDeviceService();

	TbTestingDeviceDao m_testingDevice;

	bool GetAllTestingDevice(vector<TbTestingDeviceDao> & tbTestingVec);

};

