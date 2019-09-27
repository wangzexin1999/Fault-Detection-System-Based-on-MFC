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
<<<<<<< HEAD
bool  TesterService::getOneById(TbTester &tester){
	m_testerDao.m_testerId.SetValue(tester.GetTesterId());
	bool isSuccess = m_testerDao.SelectByKey();
	if (isSuccess){
		m_testerDao.GetTableFieldValues(tester);
	}
	return isSuccess;
}
=======

bool TesterService::AddTester(TbTester tester)
{
	m_testerDao.SetTableFieldValues(tester);
	bool flag = m_testerDao.Insert();

	return flag;
}
>>>>>>> d2ee4f8bb3ab259e3eb270f0d4a87a0a6c04302c
