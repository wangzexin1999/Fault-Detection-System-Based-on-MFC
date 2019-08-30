#include "stdafx.h"
#include "TbProject.h"


TbProject::TbProject(int projectId, CString  projectName  )
{
	m_projectId = projectId;
	m_projectName = projectName;

}
TbProject::TbProject(int projectId, CString  projectName, CString projectCreatetime, TbTester tester, TbTestingDevicePara  testingDevicePara, TbProduct  product){
	this->m_projectId = projectId;
	this->m_tester = tester;
	this->m_projectName = projectName;
	this->m_projectCreatetime = projectCreatetime;
	this->m_testingDevicePara = testingDevicePara;
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
void TbProject::SetTester(TbTester tester){
	this->m_tester = tester;
}

void TbProject::SetTestingDevicePara(TbTestingDevicePara testingDevicePara){
	this->m_testingDevicePara = testingDevicePara;
}

TbTester & TbProject::GetTester(){
	return this->m_tester;
}

void TbProject::SetProjectCreateTime(CString m_projectCreatetime){
	this->m_projectCreatetime = m_projectCreatetime;
}

TbTestingDevicePara & TbProject::GetTestingDevicePara(){
	return this->m_testingDevicePara;
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

vector<TbSensorPara> & TbProject::GetSensorParaVector(){
	return this->m_sensorParaVector;
}

void TbProject::SetSensorParaVector(vector<TbSensorPara> sensorParaVector){
	this->m_sensorParaVector = sensorParaVector;
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

