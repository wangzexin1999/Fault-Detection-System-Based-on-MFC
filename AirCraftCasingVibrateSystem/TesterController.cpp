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
		return Result(false, "�û�������Ϊ��");
	}
	if (tester.GetPassWord() == ""){
		return Result(false, "���벻��Ϊ��");
	}
	TbTester selectedTester;
	selectedTester.SetLoginName(tester.GetLoginName());
	bool  isSuccess = m_testerService.getOneByCondition(selectedTester);
	if (!isSuccess){ return Result(false, "�û���ѯʧ��"); }

	if (selectedTester.GetPassWord() == tester.GetPassWord()){
		tester = selectedTester;
		return Result(true,"��¼�ɹ�");
	}
	else{
		return Result(false, "�û������������");
	}

}
