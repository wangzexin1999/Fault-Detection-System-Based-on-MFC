#include "stdafx.h"
#include "TbSensorDao.h"



TbSensorDao::TbSensorDao()
{
	this->m_strTableName = "tb_sensor";
	m_key = &m_sensorId;
	SetVectorAndField("sensor_id", "int", m_sensorId);
	SetVectorAndField("testingdevice_id", "int", m_testingDeviceId);
	SetVectorAndField("sersor_type", "CString", m_sersorType);
	SetVectorAndField("sersor_name", "CString", m_sersorName);
}

TbSensorDao::~TbSensorDao()
{

}
TbSensorDao::TbSensorDao(const TbSensorDao & sensor){
	this->m_strTableName = "tb_sensor";
	m_key = &m_sensorId;
	SetVectorAndField("sensor_id", "int", m_sensorId);
	SetVectorAndField("testingdevice_id", "int", m_testingDeviceId);
	SetVectorAndField("sersor_type", "CString", m_sersorType);
	SetVectorAndField("sersor_name", "CString", m_sersorName);
	operator = (sensor);
}

