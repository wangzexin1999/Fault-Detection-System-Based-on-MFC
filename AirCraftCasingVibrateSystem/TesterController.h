#pragma once
#include"Result.h"
#include"TbTester.h"
#include"TesterService.h"

class TesterController
{

private:
	TesterService m_testerService;
public:
	TesterController();
	~TesterController();


	Result LoginCheck(TbTester &TbTester);

};

