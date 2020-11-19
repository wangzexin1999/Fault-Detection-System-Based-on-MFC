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
	 ���������� 
	 ���������
	 ��������� 
	 �� �� ֵ�� 
	 ����˵����
	 �޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	bool AddUser(TbUser user);

protected:

	TbUserDao m_userDao;

};

