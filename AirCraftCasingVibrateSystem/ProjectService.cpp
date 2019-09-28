#include "stdafx.h"
#include "ProjectService.h"

ProjectService::ProjectService()
{

}

ProjectService::~ProjectService()
{

}
bool ProjectService::AddProject(TbProject & project){
	m_projectDao.SetTableFieldValues(project);
	bool isSuccess = m_projectDao.Insert(false);
	project.SetProjectId(m_projectDao.m_projectId.GetInt());
	return isSuccess;
}

bool ProjectService::GetAllProjectBySearchCondition(TbProject project, CString startTime, CString endTime, vector<TbProject> &projectVector){
	///1.设置项目的测试人员
	m_projectDao.m_testerId.SetValue(project.GetTester().GetTesterId());
	vector<TbProjectDao>  selectedValueVector;
	////2.查询测试人员的所有项目
	//////2.1 封装sql查询条件
	CString strSqlWhere = "1 = 1 ";
	if (project.GetTester().GetTesterId() != 0) strSqlWhere += " and tester_id ='" + CommonUtil::Int2CString(project.GetTester().GetTesterId()) + "'";
	if (project.GetProjectName() != "") strSqlWhere += " and project_name like '%" + project.GetProjectName() + "%'";
	if (project.GetProduct().GetProductId() != 0) strSqlWhere += " and product_id =" + CommonUtil::Int2CString(project.GetProduct().GetProductId());
	if (startTime != "") strSqlWhere += " and project_createtime >='" + startTime + "'";
	if (endTime != "") strSqlWhere += " and project_createtime <='" + endTime + "'";
	if (project.GetProjectStatus() != 0) strSqlWhere += " and project_status =" + CommonUtil::Int2CString(project.GetProjectStatus());
	//////2.2 根据sql语句查询符合条件的所有项目
	bool isSuccess = m_projectDao.SelectObjectsByCondition(selectedValueVector, strSqlWhere);
	for (auto projectDao : selectedValueVector){
		TbProject tbProject;
		projectDao.GetTableFieldValues(tbProject);
		projectVector.push_back(tbProject);
	}
	return isSuccess;
}


bool  ProjectService::GetLastOpenProjectByUser(TbProject &project){
	CString strSqlWhere = "1 = 1 ";
	if (project.GetTester().GetTesterId() != 0) strSqlWhere += " and tester_id ='" + CommonUtil::Int2CString(project.GetTester().GetTesterId()) + "'";
	strSqlWhere += "ORDER BY project_updatetime desc limit 0,1";
	bool isSuccess = m_projectDao.SelectOneObjectByCondition(strSqlWhere);
	if (m_projectDao.m_projectId.GetInt()!=0)	m_projectDao.GetTableFieldValues(project);
	return isSuccess;
}

bool ProjectService::UpdateProject(TbProject project){
	m_projectDao.SetTableFieldValues(project);
	return m_projectDao.UpdateByKey();
}