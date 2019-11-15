#include "stdafx.h"
#include "TbProjectDao.h"


TbProjectDao::TbProjectDao()
{
	this->m_strTableName = "tb_project";
	m_key = &m_projectId;;
	SetVectorAndField("project_id", "int", m_projectId);
	SetVectorAndField("tester_id", "int", m_testerId);
	SetVectorAndField("project_name", "CString", m_projectName);
	SetVectorAndField("project_createtime", "CString", m_projectCreatetime);
	SetVectorAndField("project_updatetime", "CString", m_projectUpdatetime);
	SetVectorAndField("testingdevice_id", "int", m_testingDeviceid);
	SetVectorAndField("product_id", "int", m_productId);
	SetVectorAndField("project_status", "int", m_projectStatus);
	SetVectorAndField("collection_plan", "CString", m_collectionPlans);
	SetVectorAndField("collectionstatus", "CString", m_collectionStatus);
}


TbProjectDao::~TbProjectDao()
{

}

TbProjectDao::TbProjectDao(const TbProjectDao &project){
	this->m_strTableName = "tb_project";
	m_key = &m_projectId;
	SetVectorAndField("project_id", "int", m_projectId);
	SetVectorAndField("tester_id", "int", m_testerId);
	SetVectorAndField("project_name", "CString", m_projectName);
	SetVectorAndField("project_createtime", "CString", m_projectCreatetime);
	SetVectorAndField("project_updatetime", "CString", m_projectUpdatetime);
	SetVectorAndField("testingdevice_id", "int", m_testingDeviceid);
	SetVectorAndField("product_id", "int", m_productId);
	SetVectorAndField("project_status", "int", m_projectStatus);
	SetVectorAndField("collection_plan", "CString", m_collectionPlans);
	SetVectorAndField("collectionstatus", "CString", m_collectionStatus);
	operator = (project);
}

bool TbProjectDao::SelectObjectsByCondition(vector<TbProjectDao> &selectedValueVector, CString strSqlQueryWhere ){
	int iStartNumberIn = 0; int iRecordCountIn = 0;
	return SelectObjectsByCondition(selectedValueVector, iStartNumberIn, iRecordCountIn, strSqlQueryWhere);
}

bool TbProjectDao::SelectObjectsByCondition(vector<TbProjectDao> &selectedValueVector, int iStartNumberIn, int iRecordCountIn, CString strSqlQueryWhere)
{
	vector<CString> tmpDetectedObjecIDs;
	TbProjectDao project;
	if (project.GetKeyIdList(tmpDetectedObjecIDs, strSqlQueryWhere, iStartNumberIn, iRecordCountIn))
	{
		for (int iStart = 0; iStart < tmpDetectedObjecIDs.size(); iStart++)
		{
			project.m_projectId.m_strValue = tmpDetectedObjecIDs[iStart];
			if (project.SelectByKey())
			{
				selectedValueVector.push_back(project);
			}
			else
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

void TbProjectDao::SetTableFieldValues(TbProject project){
	this->m_projectId.SetValue(project.GetProjectId());
	this->m_productId.SetValue(project.GetProduct().GetProductId());
	this->m_projectCreatetime.SetValue(project.GetProjectCreateTime());
	this->m_projectUpdatetime.SetValue(project.GetProjectUpdateTime());
	this->m_projectName.SetValue(project.GetProjectName());
	this->m_testerId.SetValue(project.GetTester().GetTesterId());
	this->m_testingDeviceid.SetValue(project.GetTestingDevice().GetId());
	this->m_projectStatus.SetValue(project.GetProjectStatus());
	this->m_collectionPlans.m_strValue = project.GetCollectionPlans();
	this->m_collectionStatus.m_strValue = project.GetCollectionStatus();
}

void TbProjectDao::GetTableFieldValues(TbProject &project){
	project.SetProjectId(m_projectId.GetInt());
	project.SetProjectCreateTime(m_projectCreatetime.m_strValue);
	project.SetProjectUpdateTime(m_projectUpdatetime.m_strValue);
	project.SetProjectName(m_projectName.m_strValue);
	project.SetProjectStatus(m_projectStatus.GetInt());
	project.GetTester().SetTesterId(m_testerId.GetInt());
	project.GetProduct().SetProductId(m_productId.GetInt());
	project.GetTestingDevice().SetId(m_testingDeviceid.GetInt());
	project.SetCollectionPlans(m_collectionPlans.m_strValue);
	project.SetCollectionStatus(m_collectionStatus.m_strValue);
}