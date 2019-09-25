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
	/*1.����Ӳɼ��豸������*/
	bool flag = m_testingDeviceService.AddTestingDevice(project.GetTestingDevice());
	if (!flag) return Result(false, "�ɼ���������ʧ��");
	/*2.�����Ŀ��*/
	flag = m_projectService.AddProject(project);
	if (!flag) return Result(false, "��Ŀ����ʧ��");
	/*3.��Ӵ�����������*/
	for (int i = 0; i < project.GetSensorVector().size();i++){
		project.GetSensorVector()[i].SetProjectId(project.GetProjectId());
		flag = m_sensorService.AddSensor(project.GetSensorVector()[i]);
		if (!flag) return Result(false, "����������ʧ��");
	}
	return Result(true, "��Ŀ�����ɹ�");
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