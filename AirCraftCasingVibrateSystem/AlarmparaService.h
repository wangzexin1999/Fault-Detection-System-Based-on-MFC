
#pragma once
#include "TbAlarmparaDao.h"
#include "TbAlarmpara.h"
class AlarmparaService
{
public:
	AlarmparaService();
	~AlarmparaService();
protected:
	TbAlarmparaDao m_TbAlarmparaDao;
public:
	bool AddAlarmpara(TbAlarmpara TbAlarmpara);
};