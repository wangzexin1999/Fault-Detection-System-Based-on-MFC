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

bool TestingDeviceService::Update(TbTestingDevice testingDevice){
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
		///查询TbTestingDevice的各个参数id对应的字典表的实体值
		////查询采集频率对应id的字典对象
		m_dictionaryDao.m_key->SetValue(searchEntity.GetCollectionFrequency().GetDictId());
		m_dictionaryDao.SelectByKey();
		m_dictionaryDao.GetTableFieldValues(searchEntity.GetCollectionFrequency());
		////查询采集点数对应的id的字典对象
		m_dictionaryDao.m_key->SetValue(searchEntity.GetCollectionPoint().GetDictId());
		m_dictionaryDao.SelectByKey();
		m_dictionaryDao.GetTableFieldValues(searchEntity.GetCollectionPoint());
	}
	return isSuccess;
}

bool TestingDeviceService::Delete(TbTestingDevice testingDevice){
	CString strWhere = "1=1 ";
	if (testingDevice.GetId() != 0) strWhere += "and id =" + CommonUtil::Int2CString(testingDevice.GetId()) + "'";
	if (testingDevice.GetTestingDeviceIp() != "")  strWhere += "and testingdevice_ip like'%" + testingDevice.GetTestingDeviceIp() + "%'";
	return  m_testingDeviceDao.DeleteByCondition(strWhere);
}