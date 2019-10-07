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
	project.SetProjectStatus(2);
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
	////查询项目的基本信息
	bool flag = m_projectService.GetAllProjectBySearchCondition(project, startTime, endTime, projectVector);
	if (!flag)return Result(false, "项目加载失败");

	for (int i = 0; i < projectVector.size();i++){
		////查询项目的采集设备
		flag = m_testingDeviceService.GetOneById(projectVector[i].GetTestingDevice());
		if (!flag)return Result(false, "采集设备加载失败");
		////查询项目的所有传感器
		flag = m_sensorService.GetALLSensorByProjectId(projectVector[i].GetProjectId(), projectVector[i].GetSensorVector());
		if (!flag)return Result(false, "传感器加载失败");
		////查询项目对应的产品信息
		flag = m_productService.GetProductByID(projectVector[i].GetProduct());
		if (!flag)return Result(false, "产品加载失败");
		////查询用户信息
		flag = m_testerService.getOneById(projectVector[i].GetTester());
		if (!flag)return Result(false, "用户加载失败");

	}
	return Result(true, "项目加载成功");
}

Result ProjectController::FindLastOpenProjectByUser(TbProject &project){
	///加载项目基本信息
	bool flag = m_projectService.GetLastOpenProjectByUser(project);
	if (!flag) return Result(false, "项目加载失败");
	///加载项目其他信息
	////查询项目的采集设备
	flag = m_testingDeviceService.GetOneById(project.GetTestingDevice());
	if (!flag)return Result(false, "采集设备加载失败");
	////查询项目的所有传感器
	flag = m_sensorService.GetALLSensorByProjectId(project.GetProjectId(), project.GetSensorVector());
	if (!flag)return Result(false, "传感器加载失败");
	////查询项目对应的产品信息
	flag = m_productService.GetProductByID(project.GetProduct());
	if (!flag)return Result(false, "产品加载失败");
	////查询用户信息
	flag = m_testerService.getOneById(project.GetTester());

	return Result(true, "项目加载成功");
}

Result ProjectController::UpdateProject(TbProject project){
	bool flag = m_projectService.UpdateProject(project);
	if (flag) return Result(true, "项目更新成功");
	return Result(false, "项目更新失败");
}
