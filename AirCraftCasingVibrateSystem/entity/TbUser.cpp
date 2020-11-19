#include "stdafx.h"
#include "TbUser.h"



TbUser::TbUser(int userId, CString loginName, CString password, int Status){
	this->m_userId = userId;
	this->m_loginName = loginName;
	this->m_Password = password;
	this->m_status = Status;
}
TbUser::~TbUser()
{
}

CString  TbUser::GetLoginName(){
	 return m_loginName;
}

CString TbUser::GetPassWord(){
	return m_Password;
}

void TbUser::SetLoginName(CString loginName){
	this->m_loginName = loginName;
}
void TbUser::SetPassWord(CString password){
	this->m_Password = password;
}
int TbUser::GetUserId(){
	return this->m_userId;
}
void TbUser::SetUserId(int userId){
	this->m_userId = userId;
}

CString TbUser::GetName(){
	return m_Name;
}
void TbUser::SetName(CString realName){
	m_Name = realName;
}
void TbUser::SetPost(CString Post){
	m_Post = Post;
}
CString TbUser::GetPost(){
	return m_Post;
}

void  TbUser::SetTelephone(CString telephone){
	m_Telephone = telephone;
}
CString TbUser::GetTelephone(){
	return m_Telephone;
}

void TbUser::SetStatus(int Status)
{
	m_status = Status;
}
int TbUser::GetStatus()
{
	return m_status;
}
