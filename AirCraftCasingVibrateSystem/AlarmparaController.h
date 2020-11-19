#pragma once
#include "AlarmparaService.h"
#include "Result.h"
class AlarmparaController
{

public:
	AlarmparaController();
	~AlarmparaController();
private:
	AlarmparaService m_AlarmparaService;
public:
	Result AddAlarmpara(TbAlarmpara Alarmpara);
};

