#include "stdafx.h"
#include "TesterService.h"


TesterService::TesterService()
{
}


TesterService::~TesterService()
{
}


bool TesterService::getOneByCondition(TbTester &tester){
	CString strWhere = "login_name ='" + tester.GetLoginName() + "'";
	bool flag = m_testerDao.SelectOneObjectByCondition(strWhere);
	m_testerDao.GetTableFieldValues(tester);
	return flag;
}
bool  TesterService::getOneById(TbTester &tester){
	m_testerDao.m_testerId.SetValue(tester.GetTesterId());
	bool isSuccess = m_testerDao.SelectByKey();
	if (isSuccess){
		m_testerDao.GetTableFieldValues(tester);
	}
	return isSuccess;
}