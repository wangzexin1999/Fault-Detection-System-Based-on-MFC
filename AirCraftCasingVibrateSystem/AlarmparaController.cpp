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
		return Result(true, "信号测试记录加载成功");
	}
	else{
		return Result(false, "信号测试记录加载失败");
	}
}

