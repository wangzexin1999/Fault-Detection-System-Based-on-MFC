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
		return Result(true, "�ܱ�ǩ���سɹ�");
	}
	else{
		return Result(false, "�ܱ�ǩ����ʧ��");
	}
}


