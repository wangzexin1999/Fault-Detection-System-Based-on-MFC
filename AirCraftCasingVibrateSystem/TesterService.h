#pragma once

#include"TbTesterDao.h"
#include "TbTester.h"
class TesterService
{
public:
	TesterService();

	~TesterService();

	bool getOneByCondition(TbTester &tester);
	bool getOneById(TbTester &tester);

protected:

	TbTesterDao m_testerDao;

};

