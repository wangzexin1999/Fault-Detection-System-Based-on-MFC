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
		return Result(true, "检测设备加载失败");
	}
	else{
		return Result(false, "检测设备加载失败");
	}

}
Result ProjectController::LoadAllProduct(vector<TbProduct> & productVec){
	
	bool flag = m_productService.GetAllProductBySearchCondition(TbProduct(),productVec);
	if (flag){
		return Result(true,"产品加载成功");
	}
	else{
		return Result(false, "产品加载失败");
	}
}
Result ProjectController::AddProject(TbProject &project){
	bool flag = m_projectService.AddProject(project);
	if (flag){
		return Result(true, "项目创建成功");
	}
	else{
		return Result(false, "项目创建失败");
	}
}

Result ProjectController::LoadAllProjectBySearchCondition(int testerId, CString projectName, CString startTime, CString endTime, vector<TbProject> &projectVector){
	TbProject project;
	project.GetTester().SetTesterId(testerId);
	project.SetProjectName(projectName);
	bool flag = m_projectService.GetAllProjectBySearchCondition(project, startTime, endTime, projectVector);
	if (flag){
		return Result(true, "项目查询");
	}
	else{
		return Result(false, "项目查询失败");
	}
}