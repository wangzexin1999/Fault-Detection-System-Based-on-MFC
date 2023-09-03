#include "stdafx.h"
#include "ProjectController.h"


ProjectController::ProjectController()
{

}


ProjectController::~ProjectController()
{
}
Result ProjectController::FindAllCollectionparas(vector<TbCollectionparasDao> & tbTestingVec){
	bool flag = m_collectionparasService.GetAllCollectionparas(tbTestingVec);
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
	bool flag = m_collectionparasService.AddCollectionparas(project.GetCollectionparas());
	if (!flag) return Result(false, "采集参数创建失败");
	/*2.添加项目表*/
	flag = m_projectService.AddProject(project);
	if (!flag) return Result(false, "项目创建失败");
	/*3.添加通道参数表*/
	for (int i = 0; i < project.GetChannelVector().size(); i++){
		project.GetChannelVector()[i].SetProjectId(project.GetProjectId());
		flag = m_channelService.AddChannel(project.GetChannelVector()[i]);
		if (!flag) return Result(false, "通道参数保存失败");
	}
	return Result(true, "项目创建成功");
}

Result ProjectController::FindAllProjectBySearchCondition(TbProject project, CString startTime, CString endTime, vector<TbProject> &projectVector){
	////查询项目的基本信息
	bool flag = m_projectService.GetAllProjectBySearchCondition(project, startTime, endTime, projectVector);
	if (!flag)return Result(false, "项目加载失败");

	for (int i = 0; i < projectVector.size();i++){
		// 查询项目的采集设备
		flag = m_collectionparasService.GetOneById(projectVector[i].GetCollectionparas());
		if (!flag)return Result(false, "采集设备加载失败");
		// 查询项目的所有传感器
		flag = m_channelService.GetALLSensorByProjectId(projectVector[i].GetProjectId(), projectVector[i].GetChannelVector());
		if (!flag)return Result(false, "通道加载失败");
		//  查询项目对应的产品信息
		flag = m_productService.GetProductByID(projectVector[i].GetProduct());
		if (!flag)return Result(false, "产品加载失败");
		////查询用户信息
		flag = m_userService.getOneById(projectVector[i].GetUser());
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
	flag = m_collectionparasService.GetOneById(project.GetCollectionparas());
	if (!flag)return Result(false, "采集设备加载失败");
	////查询项目的所有传感器
	flag = m_channelService.GetALLSensorByProjectId(project.GetProjectId(), project.GetChannelVector());
	if (!flag)return Result(false, "传感器加载失败");//
	////查询项目对应的产品信息
	flag = m_productService.GetProductByID(project.GetProduct());//
	if (!flag)return Result(false, "产品加载失败");
	////查询用户信息
	flag = m_userService.getOneById(project.GetUser());
	return Result(true, "项目加载成功");
}

Result  ProjectController::UpdateTime(TbProject project){
	bool flag = m_projectService.Update(project);
	if (!flag) return Result(false, "项目更新失败");
	return Result(false, "项目更新成功");
}

Result ProjectController::Update(TbProject project){
	//1. 首先更新项目的基本信息表
	bool flag = m_projectService.Update(project);
	if (!flag) return Result(false, "项目更新失败");
	//3. 更新通道对象
	for (int i = 0; i < project.GetChannelVector().size(); i++){
		project.GetChannelVector()[i].SetProjectId(project.GetProjectId());
		flag = m_channelService.Update(project.GetChannelVector()[i]);
		if (!flag) return Result(false, "项目传感器更新失败");
	}
	project.GetChannelVector().clear();
	m_channelService.GetALLSensorByProjectId(project.GetProjectId(), project.GetChannelVector());
	//4. 更新采集设备的信息及其参数
	flag = m_collectionparasService.Update(project.GetCollectionparas());
	if (flag) return Result(true, "项目更新成功");
	return Result(false, "项目更新失败");
}
