#include "stdafx.h"
#include "TestService.h"
#include "CommonUtil.h"

TestService::TestService()
{
}


TestService::~TestService()
{
}

bool TestService::FindAllTestLocationByProductTypeId(int productTypeId, vector<TbTestlocation> & testLocationVec){
	vector<TbTestlocationDao> selectedValueVector;
	bool issuccess = m_testLocationDao.SelectObjectsByCondition(selectedValueVector, "product_type_id = " + CommonUtil::Int2CString(productTypeId));
	for (int i = 0; i < selectedValueVector.size(); i++){
		TbTestlocation testLocation;
		selectedValueVector[i].GetTableFieldValues(testLocation);
		testLocationVec.push_back(testLocation);
	}
	return issuccess;
}

bool TestService::GetTestLocationById(int locationId, TbTestlocation &testLoation){
	m_testLocationDao.m_key->SetValue(locationId);
	bool isSuccess = m_testLocationDao.SelectByKey();
	m_testLocationDao.GetTableFieldValues(testLoation);
	return isSuccess;
}