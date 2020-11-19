#include "stdafx.h"
#include "TbSensorDao.h"
TbSensorDao::TbSensorDao()
{
	this->m_strTableName = "tb_sensor";
	m_key = &m_sensorId;
	SetVectorAndField("sensor_id", "int", m_sensorId);
	SetVectorAndField("sensor_name", "CString", m_sensorName);
	SetVectorAndField("sensor_type", "CString", m_sensorType);
}
TbSensorDao::TbSensorDao(const TbSensorDao &sensor)
{
	this->m_strTableName = "tb_sensor";
	m_key = &m_sensorId;
	SetVectorAndField("sensor_id", "int", m_sensorId);
	SetVectorAndField("sensor_name", "CString", m_sensorName);
	SetVectorAndField("sensor_type", "CString", m_sensorType);
	operator = (sensor);
}
TbSensorDao::~TbSensorDao()
{

}
void TbSensorDao::SetTableFieldValues(TbSensor sensor)
{
	this->m_sensorId.SetValue(sensor.GetSensorId());
	this->m_sensorName.SetValue(sensor.GetSensorName());
	this->m_sensorType.SetValue(sensor.GetSensorType());
}
void TbSensorDao::GetTableFieldValues(TbSensor &sensor)
{
	sensor.SetSensorId(m_sensorId.GetInt());
	sensor.SetSensorName(m_sensorName.m_strValue);
	sensor.SetSensorType(m_sensorType.m_strValue);
}

bool TbSensorDao::SelectObjectsByCondition(vector<TbSensorDao> &selectedValueVector, CString strSqlQueryWhere = "")
{
	int iStartNumberIn = 0; int iRecordCountIn = 0;
	return SelectObjectsByCondition(selectedValueVector, iStartNumberIn, iRecordCountIn, strSqlQueryWhere);

}
bool TbSensorDao::SelectObjectsByCondition(vector<TbSensorDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere = "")
{
	vector<CString> tmpDetectedObjecIDs;
	TbSensorDao sensor;
	if (sensor.GetKeyIdList(tmpDetectedObjecIDs, strSqlQueryWhere, iStartNumber, iRecordCount))
	{
		for (int iStart = 0; iStart < tmpDetectedObjecIDs.size(); iStart++)
		{
			sensor.m_sensorId.m_strValue = tmpDetectedObjecIDs[iStart];
			if (sensor.SelectByKey())
			{
				selectedValueVector.push_back(sensor);
			}
			else
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}
