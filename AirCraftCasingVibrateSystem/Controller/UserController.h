#pragma once
#include"Result.h"
#include"TbUser.h"
#include"UserService.h"

class UserController
{

private:
	UserService m_userService;
public:
	UserController();
	~UserController();


	Result LoginCheck(TbUser &TbUser);
	/**********************************************************************
	 功能描述： 添加用户
	***********************************************************************/
	Result AddUser(TbUser user);
};

