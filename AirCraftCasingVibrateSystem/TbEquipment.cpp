#include "stdafx.h"
#include"TbEquipment.h"
TbEquipment::TbEquipment()
{

}
TbEquipment::TbEquipment(int equipmentId, CString ip, CString createTime, int status)
{
	SetEquipmentId(equipmentId);
	SetIp(ip);
	SetCreateTime(createTime);
	SetStatus(status);
}
TbEquipment::~TbEquipment()
{

}
int TbEquipment::GetEquipmentId()
{
	return m_equipmentId;
}
void TbEquipment::SetEquipmentId(int equipmentId)
{
	this->m_equipmentId = equipmentId;
}

CString TbEquipment::GetIp()
{
	return m_ip;
}
void TbEquipment::SetIp(CString ip)
{
	this->m_ip = ip;
}

CString TbEquipment::GetCreateTime()
{
	return m_createTime;
}
void TbEquipment::SetCreateTime(CString createTime)
{
	this->m_createTime = createTime;
}

int TbEquipment::GetStatus()
{
	return m_status;
}
void TbEquipment::SetStatus(int status)
{
	this->m_status = status;
}
