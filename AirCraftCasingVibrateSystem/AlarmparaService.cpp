#include "stdafx.h"
#include "AlarmparaService.h"
#include "DateUtil.h"
#include "FileUtil.h"
AlarmparaService::AlarmparaService()
{

}
AlarmparaService::~AlarmparaService()
{

}
bool AlarmparaService::AddAlarmpara(TbAlarmpara Alarmpara)
{
	m_TbAlarmparaDao.SetTableFieldValues(Alarmpara);
	bool isSuccess = m_TbAlarmparaDao.Insert();
	return isSuccess;
}

