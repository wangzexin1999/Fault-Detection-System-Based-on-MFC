#include "stdafx.h"
#include "TbProject.h"


TbProject::TbProject()
{

}
TbProject::TbProject(int projectId, TbTester tester, CString  projectName, CString projectCreatetime, TbTestingDevicePara  testingDevicePara, TbDetectedDevice  detectedDevice){
	this->m_projectId = projectId;
	this->m_tester = tester;
	this->m_projectName = projectName;
	this->m_projectCreatetime = projectCreatetime;
	this->m_testingDevicePara = testingDevicePara;
	this->m_detectedDevice = detectedDevice;
}


TbProject::~TbProject()
{

}
void TbProject::SetProjectId(int projectId){
	this->m_projectId = projectId;
}

void TbProject::SetDetectedDevice(TbDetectedDevice  detectedDevice){
	this->m_detectedDevice = detectedDevice;
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

TbDetectedDevice & TbProject::GetDetectedDevice(){
	return this->m_detectedDevice;
}

CString TbProject::GetProjectCreateTime(){
	return this->m_projectCreatetime;
}

CString TbProject::GetProjectName(){
	return this->m_projectName;
}

vector<TbSersorPara> TbProject::GetTbSersorParaVector(){
	return this->m_sensorParaVector;
}
int TbProject::GetProjectId(){
	return this->m_projectId;
}