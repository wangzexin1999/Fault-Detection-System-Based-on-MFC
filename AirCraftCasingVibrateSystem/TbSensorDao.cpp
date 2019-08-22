#include "stdafx.h"
#include "TbSensorDao.h"



TbSensorDao::TbSensorDao()
{
	this->m_strTableName = "tb_sensor";
	m_key = &m_sensorId;
	SetVectorAndField("sensor_id", "int", m_sensorId);
	SetVectorAndField("testingdevice_id", "int", m_testingDeviceId);
	SetVectorAndField("sensor_type", "CString", m_sensorType);
	SetVectorAndField("sensor_name", "CString", m_sensorName);
}

TbSensorDao::~TbSensorDao()
{

}
TbSensorDao::TbSensorDao(const TbSensorDao & sensor){
	this->m_strTableName = "tb_sensor";
	m_key = &m_sensorId;
	SetVectorAndField("sensor_id", "int", m_sensorId);
	SetVectorAndField("testingdevice_id", "int", m_testingDeviceId);
	SetVectorAndField("sensor_type", "CString", m_sensorType);
	SetVectorAndField("sensor_name", "CString", m_sensorName);
	operator = (sensor);
}

bool TbSensorDao::SelectObjectsByCondition(vector<TbSensorDao> &selectedValueVector, CString strSqlQueryWhere){

	int iStartNumberIn = 0; int iRecordCountIn = 0;
	return SelectObjectsByCondition(selectedValueVector, iStartNumberIn, iRecordCountIn, strSqlQueryWhere);
}

bool TbSensorDao::SelectObjectsByCondition(vector<TbSensorDao> &selectedValueVector, int iStartNumberIn, int iRecordCountIn, CString strSqlQueryWhere)
{
	vector<CString> tmpDetectedObjecIDs;
	TbSensorDao sensorDao;
	if (sensorDao.GetKeyIdList(tmpDetectedObjecIDs, strSqlQueryWhere, iStartNumberIn, iRecordCountIn))
	{
		for (int iStart = 0; iStart < tmpDetectedObjecIDs.size(); iStart++)
		{
			sensorDao.m_sensorId.m_strValue = tmpDetectedObjecIDs[iStart];
			if (sensorDao.SelectByKey())
			{
				selectedValueVector.push_back(sensorDao);
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
void  TbSensorDao::GetTableFieldValues(TbSensor & sensor){
	sensor.SetSensorId(m_sensorId.GetInt());
	sensor.SetSensorName(m_sensorName.m_strValue);
	sensor.SetSensorType(m_sensorType.m_strValue);
	sensor.SetTestingDeviceId(m_testingDeviceId.GetInt());
}