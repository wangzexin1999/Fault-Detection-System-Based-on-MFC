#pragma once
#include "PDDatabase.h"
class TbCollectionPlanDao :
	public PDDatabase
{
public:
	TbCollectionPlanDao();
	TbCollectionPlanDao(const TbCollectionPlanDao & collectionDao);


	
	~TbCollectionPlanDao();

	PDAttribute m_id;
	PDAttribute m_planId;
	PDAttribute m_planPara;
	PDAttribute m_projectId;

};

