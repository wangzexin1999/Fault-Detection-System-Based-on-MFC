#include "stdafx.h"
#include "TbCollectionPlan.h"


TbCollectionPlan::TbCollectionPlan(int id, int m_planId, CString planPara , int projectId )
{
	m_id = id;
	m_planId = id;
	m_planPara = planPara;
	m_projectId = projectId;
}

TbCollectionPlan::~TbCollectionPlan()
{
}
void TbCollectionPlan::SetId(int id){
	m_id = id;
}
int TbCollectionPlan::GetId(){
	return m_id;
}
void TbCollectionPlan::SetPlanId(int planId){
	m_planId = planId;
}
int TbCollectionPlan::GetPlanId(){
	return m_planId;
}
void TbCollectionPlan::SetPlanPara(CString planPara){
	m_planPara = planPara;
}
CString TbCollectionPlan::GetPlanPara(){
	return m_planPara;
}

void TbCollectionPlan::SetProjectId(int projectId){
	m_projectId = projectId;
}
int TbCollectionPlan::GetProjectId(){
	return m_projectId; 
}