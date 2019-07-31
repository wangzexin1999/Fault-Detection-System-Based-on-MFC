#pragma once
#include"Result.h"
#include"TbTester.h"
#include"TesterService.h"

class TesterController
{

public:
	TesterController();
	~TesterController();

	TesterService testerService;

	Result LoginCheck(TbTester &TbTester);

};

