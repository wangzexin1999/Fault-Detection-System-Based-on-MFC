#include "stdafx.h"
#include "UserService.h"


UserService::UserService()
{
}


UserService::~UserService()
{
}


bool UserService::getOneByCondition(TbUser &user){
	CString strWhere = "login_name ='" + user.GetLoginName() + "'";
	bool flag = m_userDao.SelectOneObjectByCondition(strWhere);
	m_userDao.GetTableFieldValues(user);
	return flag;
}
bool  UserService::getOneById(TbUser &user){
	m_userDao.m_userId.SetValue(user.GetUserId());
	bool isSuccess = m_userDao.SelectByKey();
	if (isSuccess){
		m_userDao.GetTableFieldValues(user);
	}
	return isSuccess;
}

bool UserService::AddUser(TbUser user)
{
	m_userDao.SetTableFieldValues(user);
	bool flag = m_userDao.Insert();

	return flag;
}
