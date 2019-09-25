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
	if (isSuccess){
		for (auto tbProjectDao : selectedValueVector){
			TbProject tbProject;
			tbProjectDao.GetTableFieldValues(tbProject);
			m_testingDeviceDao.m_id.SetValue(tbProjectDao.m_testingDeviceid.GetInt());
			isSuccess = m_testingDeviceDao.SelectByKey();
			if (isSuccess){
				////封装查询到的设备参数信息
				m_testingDeviceDao.GetTableFieldValues(tbProject.GetTestingDevice());
				////查询设备参数信息中的检测设备
				m_testingDeviceDao.m_id.SetValue(tbProject.GetTestingDevice().GetId());
				isSuccess = m_testingDeviceDao.SelectByKey();
				if (isSuccess){
					///封装检测设备对象
					m_testingDeviceDao.GetTableFieldValues(tbProject.GetTestingDevice());
				}
			}
			tbProject.SetProjectCreateTime(tbProjectDao.m_projectCreatetime.m_strValue);
			////查询产品的信息
			tbProject.GetProduct().SetProductId(tbProjectDao.m_productId.GetInt());
			m_productDao.m_productId.SetValue(tbProjectDao.m_productId.GetInt());
			isSuccess = m_productDao.SelectByKey();
			if (isSuccess){
				m_productDao.GetTableFieldValues(tbProject.GetProduct());
			}
			////查询用户信息
			m_testerDao.m_key->SetValue(tbProject.GetTester().GetTesterId());
			isSuccess = m_testerDao.SelectByKey();
			if (isSuccess) m_testerDao.GetTableFieldValues(tbProject.GetTester());
			////查询所有传感器参数信息

			projectVector.push_back(tbProject);
		}
	}
	return isSuccess;
}

