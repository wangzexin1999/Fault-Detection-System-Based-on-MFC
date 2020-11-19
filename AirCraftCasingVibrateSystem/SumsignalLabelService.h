#pragma once
#include "TbSumsignalLabel.h"
#include "TbSumsignalLabelDao.h"
class SumsignalLabelService
{
public:
	SumsignalLabelService();
	~SumsignalLabelService();
protected:
	TbSumsignalLabelDao m_SumsignalLabelDao;
public:
	bool AddSumsignalLabel(TbSumsignalLabel sumsignalLabel);
};