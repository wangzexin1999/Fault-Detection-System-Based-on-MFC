#pragma once

#include"TbTesterDao.h"

class TesterService
{
public:
	TesterService();

	~TesterService();

	bool getOneByCondition(TbTesterDao & TbTester, CString strWhere);

protected:

	TbTesterDao m_TbTesterDao;

};

