#include "stdafx.h"
#include "AlarmparaController.h"
AlarmparaController::AlarmparaController()
{

}
AlarmparaController::~AlarmparaController()
{

}
Result AlarmparaController::AddAlarmpara(TbAlarmpara Alarmpara)
{
	bool flag = m_AlarmparaService.AddAlarmpara(Alarmpara);
	if (flag){
		return Result(true, "�źŲ��Լ�¼���سɹ�");
	}
	else{
		return Result(false, "�źŲ��Լ�¼����ʧ��");
	}
}

