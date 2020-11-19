#include "stdafx.h"
#include "SumsignalLabelController.h"
SumsignalLabelController::SumsignalLabelController()
{

}
SumsignalLabelController::~SumsignalLabelController()
{

}
Result SumsignalLabelController::AddSumsignalLabel(TbSumsignalLabel sumsignalLabel)
{
	bool flag = m_SumsignalLabelService.AddSumsignalLabel(sumsignalLabel);
	if (flag){
		return Result(true, "总标签加载成功");
	}
	else{
		return Result(false, "总标签加载失败");
	}
}


