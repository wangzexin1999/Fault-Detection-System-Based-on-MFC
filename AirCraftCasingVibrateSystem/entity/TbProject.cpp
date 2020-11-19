#include "stdafx.h"
#include "TbProject.h"


TbProject::TbProject(int projectId, CString  projectName, int projectStatus)
{
	m_projectId = projectId;
	m_projectName = projectName;
	m_projectStatus = projectStatus;
}

TbProject::TbProject(int projectId, CString  projectName, CString projectCreatetime, TbUser user, TbCollectionparas collectionparas, TbProduct  product){
	this->m_projectId = projectId;
	this->m_user = user;
	this->m_projectName = projectName;
	this->m_projectCreatetime = projectCreatetime;
	this->m_collectionparas = collectionparas;
	this->m_product = product;
}


TbProject::~TbProject()
{

}
void TbProject::SetProjectId(int projectId){
	this->m_projectId = projectId;
}

void TbProject::SetProduct(TbProduct  product){
	this->m_product = product;
}

void TbProject::SetProjectName(CString projectName){

	this->m_projectName = projectName;
}
void TbProject::SetUser(TbUser user){
	this->m_user = user;
}

void TbProject::SetCollectionparas(TbCollectionparas collectionparas){
	this->m_collectionparas = collectionparas;
}

TbUser & TbProject::GetUser(){
	return this->m_user;
}

void TbProject::SetProjectCreateTime(CString m_projectCreatetime){
	this->m_projectCreatetime = m_projectCreatetime;
}
void TbProject::SetProjectUpdateTime(CString projectUpdatetime){
	this->m_projectUpdatetime = projectUpdatetime; 
}
TbCollectionparas & TbProject::GetCollectionparas(){
	return this->m_collectionparas;
}

TbProduct & TbProject::GetProduct(){
	return this->m_product;
}

CString TbProject::GetProjectCreateTime(){
	return this->m_projectCreatetime;
}

CString TbProject::GetProjectName(){
	return this->m_projectName;
}

vector<TbChannel> & TbProject::GetChannelVector(){
	return this->m_channelVector;
}

void TbProject::SetChannelVector(vector<TbChannel> channelVector){
	this->m_channelVector = channelVector;
}
int TbProject::GetProjectId(){
	return this->m_projectId;
}

void TbProject::SetProjectStatus(int status){
	m_projectStatus = status;
}

int TbProject::GetProjectStatus(){
	return m_projectStatus;
}
void TbProject::SetCollectionPlans(CString collectionPlans){
	m_collectionPlans = collectionPlans;
}
CString TbProject::GetCollectionPlans(){
	return m_collectionPlans;
}

void TbProject::SetCollectionStatus(CString collectionStatus){
	m_collectionStatus = collectionStatus;
}
CString TbProject::GetCollectionStatus(){
	return m_collectionStatus;
}

CString TbProject::GetProjectUpdateTime(){
	return m_projectUpdatetime;
}