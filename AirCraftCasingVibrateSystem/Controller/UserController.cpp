#include "stdafx.h"
#include "UserController.h"
#include "TbUserDao.h"

UserController::UserController()
{
}


UserController::~UserController()
{
}

Result UserController::LoginCheck(TbUser & user){

	if (user.GetLoginName() == ""){
		return Result(false, "�û�������Ϊ��");
	}
	if (user.GetPassWord() == ""){
		return Result(false, "���벻��Ϊ��");
	}
	TbUser selectedUser;
	selectedUser.SetLoginName(user.GetLoginName());
	bool  isSuccess = m_userService.getOneByCondition(selectedUser);
	if (!isSuccess){ return Result(false, "�û���ѯʧ��"); }

	if (selectedUser.GetPassWord() == user.GetPassWord()){
		user = selectedUser;
		return Result(true,"��¼�ɹ�");
	}
	else{
		return Result(false, "�û������������");
	}

}


Result UserController::AddUser(TbUser user)
{

	if (user.GetLoginName() == ""){
		return Result(false, "�û�������Ϊ��");
	}
	if (user.GetPassWord() == ""){
		return Result(false, "���벻��Ϊ��");
	}
	bool  isSuccess = m_userService.AddUser(user);
	if (!isSuccess){ return Result(false, "ע��ʧ��"); }
	else{ return Result(true, "ע��ɹ�"); }
}
