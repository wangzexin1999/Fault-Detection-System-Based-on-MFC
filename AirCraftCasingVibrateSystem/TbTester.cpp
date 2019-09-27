#include "stdafx.h"
#include "TbTester.h"



TbTester::TbTester(int testerId ,CString loginName , CString password ){
	this->m_testerId = testerId;
	this->m_loginName = loginName;
	this->m_Password = password;
}
TbTester::~TbTester()
{
}

CString  TbTester::GetLoginName(){
	 return m_loginName;
}

CString TbTester::GetPassWord(){
	return m_Password;
}

void TbTester::SetLoginName(CString loginName){
	this->m_loginName = loginName;
}
void TbTester::SetPassWord(CString password){
	this->m_Password = password;
}
int TbTester::GetTesterId(){
	return this->m_testerId;
}
void TbTester::SetTesterId(int testerId){
	this->m_testerId = testerId;
}

CString TbTester::GetTesterName(){
	return m_testerName;
}
void TbTester::SetTesterName(CString realName){
	m_testerName = realName;
}
void TbTester::SetTesterPost(CString testerPost){
	m_testerPost = testerPost;
}
CString TbTester::GetTesterPost(){
	return m_testerPost;
}

void  TbTester::SetTesterTelephone(CString telephone){
	m_testerTelephone = telephone;
}
CString TbTester::GetTesterTelephone(){
	return m_testerTelephone;
}


void TbTester::SetTesterStatus(int status)
{
	m_iStatus = status;

}
int TbTester::GetTesterStatus()
{
	return m_iStatus;

}