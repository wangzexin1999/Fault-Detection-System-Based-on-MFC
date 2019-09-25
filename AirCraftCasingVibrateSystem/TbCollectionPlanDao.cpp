#include "stdafx.h"
#include "TbCollectionPlanDao.h"


TbCollectionPlanDao::TbCollectionPlanDao()
{
	this->m_strTableName = "tb_collectionplan";
	m_key = &m_id;
	SetVectorAndField("id", "int", m_id);
	SetVectorAndField("plan_id", "int", m_planId);
	SetVectorAndField("plan_para", "CString", m_planPara);
	SetVectorAndField("project_id", "int", m_projectId);
}
TbCollectionPlanDao::TbCollectionPlanDao(const TbCollectionPlanDao & collectionDao){
	this->m_strTableName = "tb_collectionplan";
	m_key = &m_id;
	SetVectorAndField("id", "int", m_id);
	SetVectorAndField("plan_id", "int", m_planId);
	SetVectorAndField("plan_para", "CString", m_planPara);
	SetVectorAndField("project_id", "int", m_projectId);
	operator = (collectionDao);
}

TbCollectionPlanDao::~TbCollectionPlanDao()
{
	
}
