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
	/**********************************************************************
	 功能描述： 添加用户
	 输入参数：
	 输出参数： 
	 返 回 值： 
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	Result AddTester(TbTester tester);
};

