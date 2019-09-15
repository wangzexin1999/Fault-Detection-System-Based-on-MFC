#include "stdafx.h"
#include "TbSensorDao.h"



TbSensorDao::TbSensorDao()
{
	this->m_strTableName = "tb_sensor";
	m_key = &m_id;
	SetVectorAndField("id", "int", m_id);
	SetVectorAndField("sensor_id", "CString", m_sensorId);
	SetVectorAndField("sensor_desc", "CString", m_sensorDesc);
	SetVectorAndField("project_id", "int", m_projectId);
	SetVectorAndField("sensor_status", "char", m_sersorStatus);
	SetVectorAndField("measure_type", "int", m_messureType);
	SetVectorAndField("window_type", "int", m_windowType);
	SetVectorAndField("trigger_magnitude", "float", m_triggerMagnitude);
	SetVectorAndField("trigger_polarity", "int", m_triggerPolarity);
	SetVectorAndField("point_num", "int", m_pointNum);
	SetVectorAndField("coordinate_system", "int", m_coordinateSystem);
	SetVectorAndField("coordinate_systemdirection", "int", m_coordinateSystemDirection);
	SetVectorAndField("is_reference", "int", m_isReference);
	SetVectorAndField("engineering_units", "int", m_engineeringUnits);
	SetVectorAndField("sensitivity", "float", m_sensitivity);
	SetVectorAndField("mileage_range", "float", m_mileageRange);
	SetVectorAndField("integral_type", "int", m_integralType);
	SetVectorAndField("integral_units", "int", m_integralUnits);
	SetVectorAndField("input_method", "int", m_inputMethod);
	SetVectorAndField("anti_aliasing_filtering", "char", m_antiAliasingFiltering);
	SetVectorAndField("max_frequency", "float", m_maxFrequency);
}

TbSensorDao::~TbSensorDao()
{

}
TbSensorDao::TbSensorDao(const TbSensorDao & sensor){
	this->m_strTableName = "tb_sensor";
	m_key = &m_id;
	SetVectorAndField("id", "int", m_id);
	SetVectorAndField("sensor_id", "CString", m_sensorId);
	SetVectorAndField("sensor_desc", "CString", m_sensorDesc);
	SetVectorAndField("project_id", "int", m_projectId);
	SetVectorAndField("sensor_status", "char", m_sersorStatus);
	SetVectorAndField("measure_type", "int", m_messureType);
	SetVectorAndField("window_type", "int", m_windowType);
	SetVectorAndField("trigger_magnitude", "float", m_triggerMagnitude);
	SetVectorAndField("trigger_polarity", "int", m_triggerPolarity);
	SetVectorAndField("point_num", "int", m_pointNum);
	SetVectorAndField("coordinate_system", "int", m_coordinateSystem);
	SetVectorAndField("coordinate_systemdirection", "int", m_coordinateSystemDirection);
	SetVectorAndField("is_reference", "int", m_isReference);
	SetVectorAndField("engineering_units", "int", m_engineeringUnits);
	SetVectorAndField("sensitivity", "float", m_sensitivity);
	SetVectorAndField("mileage_range", "float", m_mileageRange);
	SetVectorAndField("integral_type", "int", m_integralType);
	SetVectorAndField("integral_units", "int", m_integralUnits);
	SetVectorAndField("input_method", "int", m_inputMethod);
	SetVectorAndField("anti_aliasing_filtering", "char", m_antiAliasingFiltering);
	SetVectorAndField("max_frequency", "float", m_maxFrequency);
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
			sensorDao.m_id.m_strValue = tmpDetectedObjecIDs[iStart];
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
	sensor.SetId(m_id.GetInt());
	sensor.SetSensorId(m_sensorId.m_strValue);
	sensor.SetAntiAliasingFiltering(m_antiAliasingFiltering.GetInt());
	sensor.GetCoordinateSystem().SetDictId(m_coordinateSystem.GetInt());
	sensor.GetCoordinateSystemDirection().SetDictId(m_coordinateSystemDirection.GetInt());
	sensor.GetEngineeringUnits().SetDictId(m_engineeringUnits.GetInt());
	sensor.GetInputMethod().SetDictId(m_inputMethod.GetInt());
	sensor.GetIntegralType().SetDictId(m_integralType.GetInt());
	sensor.GetIntegralUnits().SetDictId(m_integralUnits.GetInt());
	sensor.SetIsReference(m_isReference.GetInt());
	sensor.SetMaxFrequency(m_maxFrequency.GetFloatOrDouble());
	sensor.GetMessureType().SetDictId(m_messureType.GetInt());
	sensor.SetMileageRange(m_mileageRange.GetFloatOrDouble());
	sensor.SetPointNum(m_pointNum.GetInt());
	sensor.SetProjectId(m_projectId.GetInt());
	sensor.SetSensitivity(m_sensitivity.GetFloatOrDouble());
	sensor.SetSensorDesc(m_sensorDesc.m_strValue);
	sensor.GetSensorStatus().SetDictId(m_sersorStatus.GetInt());
	sensor.SetTriggerMagnitude(m_triggerMagnitude.GetFloatOrDouble());
	sensor.GetTriggerPolarity().SetDictId(m_triggerPolarity.GetInt());
	sensor.GetWindowType().SetDictId(m_windowType.GetInt());
}