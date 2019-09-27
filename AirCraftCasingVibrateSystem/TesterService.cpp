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

bool TesterService::AddTester(TbTester tester)
{
	m_testerDao.SetTableFieldValues(tester);
	bool flag = m_testerDao.Insert();

	return flag;
}
