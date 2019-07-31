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

	TbTesterDao testerDao;

	testerDao.m_loginName.m_strValue = tester.GetLoginName();
	
	CString strWhere = "login_name ='" + tester.GetLoginName()+"'";

	testerService.getOneByCondition(testerDao, strWhere);
	if (testerDao.m_password.m_strValue == tester.GetPassWord()){
		tester.SetTesterId(atoi(testerDao.m_testerId.m_strValue));
		return Result(true,"登录成功");
	}
	else{
		return Result(false, "用户名或密码错误");
	}

}
