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
		return Result(true, "检测设备加载失败");
	}
	else{
		return Result(false, "检测设备加载失败");
	}

}

Result ProjectController::AddProject(TbProject &project){
	/*1.先添加采集设备参数表*/
	bool flag = m_testingDeviceService.AddTestingDevice(project.GetTestingDevice());
	if (!flag) return Result(false, "采集参数创建失败");
	/*2.添加项目表*/
	flag = m_projectService.AddProject(project);
	if (!flag) return Result(false, "项目创建失败");
	/*3.添加传感器参数表*/
	for (int i = 0; i < project.GetSensorVector().size();i++){
		project.GetSensorVector()[i].SetProjectId(project.GetProjectId());
		flag = m_sensorService.AddSensor(project.GetSensorVector()[i]);
		if (!flag) return Result(false, "传感器载入失败");
	}
	return Result(true, "项目创建成功");
}

Result ProjectController::FindAllProjectBySearchCondition(TbProject project, CString startTime, CString endTime, vector<TbProject> &projectVector){
	bool flag = m_projectService.GetAllProjectBySearchCondition(project, startTime, endTime, projectVector);
	if (flag){
		return Result(true, "项目查询");
	}
	else{
		return Result(false, "项目查询失败");
	}
}