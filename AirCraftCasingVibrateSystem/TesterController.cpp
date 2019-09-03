#include "stdafx.h"
#include "TesterController.h"
#include "TbTesterDao.h"

TesterController::TesterController()
{
}


TesterController::~TesterController()
{
}

Result TesterController::LoginCheck(TbTester & tester){

	if (tester.GetLoginName() == ""){
		return Result(false, "用户名不能为空");
	}
	if (tester.GetPassWord() == ""){
		return Result(false, "密码不能为空");
	}
	TbTester selectedTester;
	selectedTester.SetLoginName(tester.GetLoginName());
	bool  isSuccess = m_testerService.getOneByCondition(selectedTester);
	if (!isSuccess){ return Result(false, "用户查询失败"); }

	if (selectedTester.GetPassWord() == tester.GetPassWord()){
		tester = selectedTester;
		return Result(true,"登录成功");
	}
	else{
		return Result(false, "用户名或密码错误");
	}

}
