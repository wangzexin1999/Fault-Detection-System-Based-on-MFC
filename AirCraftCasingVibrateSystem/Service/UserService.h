#pragma once

#include"TbUserDao.h"
#include "TbUser.h"
class UserService
{
public:
	UserService();

	~UserService();

	bool getOneByCondition(TbUser &user);
	bool getOneById(TbUser &user);
	/**********************************************************************
	 功能描述： 
	 输入参数：
	 输出参数： 
	 返 回 值： 
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	bool AddUser(TbUser user);

protected:

	TbUserDao m_userDao;

};

