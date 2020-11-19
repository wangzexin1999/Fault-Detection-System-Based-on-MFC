#include "stdafx.h"
#include "SumsignalLabelService.h"
#include "DateUtil.h"
#include "FileUtil.h"
SumsignalLabelService::SumsignalLabelService()
{

}
SumsignalLabelService::~SumsignalLabelService()
{

}

bool SumsignalLabelService::AddSumsignalLabel(TbSumsignalLabel sumsignalLabel)
{
	m_SumsignalLabelDao.SetTableFieldValues(sumsignalLabel);
	bool isSuccess = m_SumsignalLabelDao.Insert();
	return isSuccess;
}