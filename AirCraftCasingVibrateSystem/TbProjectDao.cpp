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
	SetVectorAndField("testingdevice_paraid", "int", m_testingDeviceParaid);
	SetVectorAndField("product_id", "int", m_productId);
	SetVectorAndField("project_status", "int", m_projectStatus);


}


TbProjectDao::~TbProjectDao()
{
}

TbProjectDao::TbProjectDao(const TbProjectDao &project){
	this->m_strTableName = "tb_project";
	m_key = &m_projectId;;
	SetVectorAndField("project_id", "int", m_projectId);
	SetVectorAndField("tester_id", "int", m_testerId);
	SetVectorAndField("project_name", "CString", m_projectName);
	SetVectorAndField("project_createtime", "CString", m_projectCreatetime);
	SetVectorAndField("testingdevice_paraid", "int", m_testingDeviceParaid);
	SetVectorAndField("product_id", "int", m_productId);
	SetVectorAndField("project_status", "int", m_projectStatus);
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
	this->m_projectName.SetValue(project.GetProjectName());
	this->m_testerId.SetValue(project.GetTester().GetTesterId());
	this->m_testingDeviceParaid.SetValue(project.GetTestingDevicePara().GetTestingdeviceparaId());
	this->m_projectStatus.SetValue(project.GetProjectStatus());
}

void TbProjectDao::GetTableFieldValues(TbProject &project){
	project.SetProjectId(m_projectId.GetInt());
	project.SetProjectCreateTime(m_projectCreatetime.m_strValue);
	project.SetProjectName(m_projectName.m_strValue);
	project.SetProjectStatus(m_projectStatus.GetInt());
	project.GetTester().SetTesterId(m_testerId.GetInt());
	project.GetProduct().SetProductId(m_productId.GetInt());
	project.GetTestingDevicePara().SetTestingdeviceparaId(m_testingDeviceParaid.GetInt());
}