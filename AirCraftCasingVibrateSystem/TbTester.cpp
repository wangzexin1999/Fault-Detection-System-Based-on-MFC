#include "stdafx.h"
#include "TbTester.h"


TbTester::TbTester()
{
}

TbTester::TbTester(int testerId,CString loginName, CString password){
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