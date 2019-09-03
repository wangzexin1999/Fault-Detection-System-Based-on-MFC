#pragma once
#include "PDDatabase.h"
#include "TbTester.h"

class TbTesterDao :
	public PDDatabase
{
public:

	TbTesterDao();
	TbTesterDao(const TbTesterDao & testerDao);
	~TbTesterDao();


public:

	PDAttribute  m_testerId;
	PDAttribute  m_loginName;
	PDAttribute  m_password;
	PDAttribute  m_testerName;
	PDAttribute  m_testerPost;
	PDAttribute  m_testerTelephone;
	PDAttribute  m_testerStatus;

	void SetTableFieldValues(TbTester tester);
	void GetTableFieldValues(TbTester &tester);

};

