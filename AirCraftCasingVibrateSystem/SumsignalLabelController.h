#pragma once
#include "SumsignalLabelService.h"
#include "Result.h"

class SumsignalLabelController
{
public:
	SumsignalLabelController();
	~SumsignalLabelController();
private:
	SumsignalLabelService m_SumsignalLabelService;
public:
	Result AddSumsignalLabel(TbSumsignalLabel sumsignalLabel);
};