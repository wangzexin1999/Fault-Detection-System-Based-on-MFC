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

void TbTesterDao::SetTableFieldValues(TbTester tester){
	m_testerId.SetValue(tester.GetTesterId());
	m_testerName.SetValue(tester.GetTesterName());
	m_loginName.SetValue(tester.GetLoginName());
	m_password.SetValue(tester.GetPassWord());
	m_testerPost.SetValue(tester.GetTesterPost());
	m_testerTelephone.SetValue(tester.GetTesterTelephone());
}

void TbTesterDao::GetTableFieldValues(TbTester &tester){
	tester.SetTesterId(m_testerId.GetInt());
	tester.SetLoginName(m_testerName.m_strValue);
	tester.SetPassWord(m_password.m_strValue);
	tester.SetTesterName(m_testerName.m_strValue);
	tester.SetTesterPost(m_testerPost.m_strValue);
	tester.SetTesterTelephone(m_testerTelephone.m_strValue);
}