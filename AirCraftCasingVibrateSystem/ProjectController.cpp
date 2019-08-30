#include "stdafx.h"
#include "ProjectController.h"


ProjectController::ProjectController()
{

}


ProjectController::~ProjectController()
{
}
Result ProjectController::LoadAllTestingDevice(vector<TbTestingDeviceDao> & tbTestingVec){
	bool flag = m_testingDeviceService.GetAllTestingDevice(tbTestingVec);
	if (flag){
		return Result(true, "����豸����ʧ��");
	}
	else{
		return Result(false, "����豸����ʧ��");
	}

}
Result ProjectController::LoadAllProduct(vector<TbProduct> & productVec){
	
	bool flag = m_productService.GetAllProductBySearchCondition(TbProduct(),productVec);
	if (flag){
		return Result(true,"��Ʒ���سɹ�");
	}
	else{
		return Result(false, "��Ʒ����ʧ��");
	}
}
Result ProjectController::AddProject(TbProject &project){
	bool flag = m_projectService.AddProject(project);
	if (flag){
		return Result(true, "��Ŀ�����ɹ�");
	}
	else{
		return Result(false, "��Ŀ����ʧ��");
	}
}

Result ProjectController::LoadAllProjectBySearchCondition(int testerId, CString projectName, CString startTime, CString endTime, vector<TbProject> &projectVector){
	TbProject project;
	project.GetTester().SetTesterId(testerId);
	project.SetProjectName(projectName);
	bool flag = m_projectService.GetAllProjectBySearchCondition(project, startTime, endTime, projectVector);
	if (flag){
		return Result(true, "��Ŀ��ѯ");
	}
	else{
		return Result(false, "��Ŀ��ѯʧ��");
	}
}