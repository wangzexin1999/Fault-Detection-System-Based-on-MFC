#include "stdafx.h"
#include "TestingDeviceService.h"
#include "CommonUtil.h"

TestingDeviceService::TestingDeviceService()
{
}


TestingDeviceService::~TestingDeviceService()
{

}

bool TestingDeviceService::GetAllTestingDevice(vector<TbTestingDeviceDao> & tbTestingVec){
	return m_testingDeviceDao.SelectObjectsByCondition(tbTestingVec, "1=1");
}


///根据查询条件查询所有检测设备
bool  TestingDeviceService::GetAllTestingDeviceBySearchCondition(TbTestingDevice searchEntity, vector<TbTestingDevice> &testingDeviceVector){
	CString strWhere = "testingdevice_status != -1 ";
	if (searchEntity.GetTestingDeviceIp() != "")  strWhere += "and testingdevice_ip like'%" + searchEntity.GetTestingDeviceIp() + "%'";
	if (searchEntity.GetId() != 0) strWhere += "and id =" + CommonUtil::Int2CString(searchEntity.GetId()) + "'";
	vector<TbTestingDeviceDao>  tbTestingDviceDaoVec;
	bool isSuccess = m_testingDeviceDao.SelectObjectsByCondition(tbTestingDviceDaoVec, strWhere);
	if (isSuccess){
		for (auto testingDeviceDao : tbTestingDviceDaoVec){
			TbTestingDevice testingDevice;
			testingDeviceDao.GetTableFieldValues(testingDevice);
			testingDeviceVector.push_back(testingDevice);
		}
	}
	return isSuccess;
}

bool TestingDeviceService::UpdateByTestingDevice(TbTestingDevice testingDevice){
	m_testingDeviceDao.SetTableFieldValues(testingDevice);
	bool isSuccess = m_testingDeviceDao.UpdateByKey();
	return isSuccess;
}

bool TestingDeviceService::AddTestingDevice(TbTestingDevice & testingDevice){
	TbTestingDeviceDao testingDeviceDao;
	testingDeviceDao.SetTableFieldValues(testingDevice);
	bool isSuccess =  testingDeviceDao.Insert(false);
	testingDeviceDao.GetTableFieldValues(testingDevice);
	return isSuccess;
}
bool TestingDeviceService::GetOneById(TbTestingDevice &searchEntity){
	m_testingDeviceDao.m_id.SetValue(searchEntity.GetId());
	bool isSuccess = m_testingDeviceDao.SelectByKey();
	if (isSuccess){
		m_testingDeviceDao.GetTableFieldValues(searchEntity);
	}
	return isSuccess;
}