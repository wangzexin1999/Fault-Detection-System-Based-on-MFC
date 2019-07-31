#include "stdafx.h"
#include "TbTesterDao.h"


TbTesterDao::TbTesterDao()
{
	this->m_strTableName = "tb_tester";
	m_key = &m_testerId;
	SetVectorAndField("tester_id", "int", m_testerId);
	SetVectorAndField("login_name", "CString", m_loginName);
	SetVectorAndField("login_password", "CString", m_password);
	SetVectorAndField("tester_name", "CString", m_testerName);
	SetVectorAndField("tester_post", "int", m_testerPost);
	SetVectorAndField("tester_telephone", "CString", m_testerTelephone);
	SetVectorAndField("tester_status", "int", m_testerStatus);
}


TbTesterDao::~TbTesterDao()
{

}
TbTesterDao::TbTesterDao(const TbTesterDao & testerDao){
	this->m_strTableName = "tb_tester";
	m_key = &m_testerId;
	SetVectorAndField("tester_id", "int", m_testerId);
	SetVectorAndField("login_name", "CString", m_loginName);
	SetVectorAndField("login_password", "CString", m_password);
	SetVectorAndField("tester_name", "CString", m_testerName);
	SetVectorAndField("tester_post", "int", m_testerPost);
	SetVectorAndField("tester_telephone", "CString", m_testerTelephone);
	SetVectorAndField("tester_status", "int", m_testerStatus);
	operator = (testerDao);
}