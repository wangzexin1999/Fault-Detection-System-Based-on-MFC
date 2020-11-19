#pragma once
#include "PDDatabase.h"
#include "TbUser.h"

class TbUserDao :
	public PDDatabase
{
public:

	TbUserDao();
	TbUserDao(const TbUserDao & userDao);
	~TbUserDao();


public:

	PDAttribute  m_userId;
	PDAttribute  m_loginName;
	PDAttribute  m_password;
	PDAttribute  m_Name;
	PDAttribute  m_Post;
	PDAttribute  m_Telephone;
	PDAttribute  m_status;


	void SetTableFieldValues(TbUser user);
	void GetTableFieldValues(TbUser &user);

};

