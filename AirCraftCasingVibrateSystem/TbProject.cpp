#include "stdafx.h"
#include "TbProject.h"


TbProject::TbProject(int projectId, CString  projectName, int projectStatus)
{
	m_projectId = projectId;
	m_projectName = projectName;
	m_projectStatus = projectStatus;
}

TbProject::TbProject(int projectId, CString  projectName, CString projectCreatetime, TbTester tester, TbTestingDevice  testingDevice, TbProduct  product){
	this->m_projectId = projectId;
	this->m_tester = tester;
	this->m_projectName = projectName;
	this->m_projectCreatetime = projectCreatetime;
	this->m_testingDevice = testingDevice;
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

void TbProject::SetTestingDevice(TbTestingDevice testingDevice){
	this->m_testingDevice = testingDevice;
}

TbTester & TbProject::GetTester(){
	return this->m_tester;
}

void TbProject::SetProjectCreateTime(CString m_projectCreatetime){
	this->m_projectCreatetime = m_projectCreatetime;
}

TbTestingDevice & TbProject::GetTestingDevice(){
	return this->m_testingDevice;
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

vector<TbSensor> & TbProject::GetSensorVector(){
	return this->m_sensorVector;
}

void TbProject::SetSensorVector(vector<TbSensor> sensorVector){
	this->m_sensorVector = sensorVector;
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

