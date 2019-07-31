#include "stdafx.h"
#include "TesterService.h"


TesterService::TesterService()
{
}


TesterService::~TesterService()
{
}

bool TesterService::getOneByCondition(TbTesterDao & TbTester,CString strWhere){
	bool flag = m_TbTesterDao.SelectOneObjectByCondition(strWhere);
	TbTester = m_TbTesterDao;
	return flag;
}