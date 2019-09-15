#include "stdafx.h"
#include "ProjectController.h"


ProjectController::ProjectController()
{

}


ProjectController::~ProjectController()
{
}
Result ProjectController::FindAllTestingDevice(vector<TbTestingDeviceDao> & tbTestingVec){
	bool flag = m_testingDeviceService.GetAllTestingDevice(tbTestingVec);
	if (flag){
		return Result(true, "����豸����ʧ��");
	}
	else{
		return Result(false, "����豸����ʧ��");
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

Result ProjectController::FindAllProjectBySearchCondition(TbProject project, CString startTime, CString endTime, vector<TbProject> &projectVector){
	bool flag = m_projectService.GetAllProjectBySearchCondition(project, startTime, endTime, projectVector);
	if (flag){
		return Result(true, "��Ŀ��ѯ");
	}
	else{
		return Result(false, "��Ŀ��ѯʧ��");
	}
}