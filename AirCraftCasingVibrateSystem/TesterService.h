#pragma once

#include"TbTesterDao.h"
#include "TbTester.h"
class TesterService
{
public:
	TesterService();

	~TesterService();

	bool getOneByCondition(TbTester &tester);
<<<<<<< HEAD
	bool getOneById(TbTester &tester);
=======
	/**********************************************************************
	 功能描述： 
	 输入参数：
	 输出参数： 
	 返 回 值： 
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	bool AddTester(TbTester tester);
>>>>>>> d2ee4f8bb3ab259e3eb270f0d4a87a0a6c04302c

protected:

	TbTesterDao m_testerDao;

};

