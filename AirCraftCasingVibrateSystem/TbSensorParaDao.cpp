#include "stdafx.h"
#include "TbSensorParaDao.h"


TbSensorParaDao::TbSensorParaDao()
{
	
	this->m_strTableName = "tb_sensorpara";
	m_key = &m_sensorParaId;
	SetVectorAndField("sensorpara_id", "int", m_sensorParaId);
	SetVectorAndField("project_id", "int", m_projectId);
	SetVectorAndField("sensor_id", "int", m_sersorId);
	SetVectorAndField("sensor_status", "char", m_sersorStatus);
	SetVectorAndField("measure_type", "int", m_messureType);
	SetVectorAndField("sensor_desc", "CString", m_sensorDesc);
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
	SetVectorAndField("is_used", "char", m_isUsed);
}

TbSensorParaDao::~TbSensorParaDao()
{
}
TbSensorParaDao::TbSensorParaDao(const TbSensorParaDao &sersorPara){
	this->m_strTableName = "tb_sensorpara";
	m_key = &m_sensorParaId;
	SetVectorAndField("sensorpara_id", "int", m_sensorParaId);
	SetVectorAndField("project_id", "int", m_projectId);
	SetVectorAndField("sensor_id", "int", m_sersorId);
	SetVectorAndField("sensor_status", "char", m_sersorStatus);
	SetVectorAndField("measure_type", "int", m_messureType);
	SetVectorAndField("sensor_desc", "CString", m_sensorDesc);
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
	SetVectorAndField("is_used", "char", m_isUsed);
	operator = (sersorPara);
}
bool TbSensorParaDao::SelectObjectsByCondition(vector<TbSensorParaDao> &selectedValueVector, CString strSqlQueryWhere){
	return SelectObjectsByCondition(selectedValueVector, 0, 0, strSqlQueryWhere);
}

bool TbSensorParaDao::SelectObjectsByCondition(vector<TbSensorParaDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere){

	vector<CString> tmpDetectedObjecIDs;
	TbSensorParaDao sensorPara;
	if (sensorPara.GetKeyIdList(tmpDetectedObjecIDs, strSqlQueryWhere, iStartNumber, iRecordCount))
	{
		for (int iStart = 0; iStart < tmpDetectedObjecIDs.size(); iStart++)
		{
			sensorPara.m_sensorParaId.m_strValue = tmpDetectedObjecIDs[iStart];

			if (sensorPara.SelectByKey())
			{
				selectedValueVector.push_back(sensorPara);
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


void TbSensorParaDao::GetTableFieldValues(TbSensorPara &sensorPara){
	sensorPara.SetSensorParaId(m_sensorParaId.GetInt());
	sensorPara.SetAntiAliasingFiltering(m_antiAliasingFiltering.GetInt());
	sensorPara.SetCoordinateSystem(m_coordinateSystem.GetInt());
	sensorPara.SetCoordinateSystemDirection(m_coordinateSystemDirection.GetInt());
	sensorPara.SetEngineeringUnits(m_engineeringUnits.GetInt());
	sensorPara.SetInputMethod(m_inputMethod.GetInt());
	sensorPara.SetIntegralType(m_integralType.GetInt());
	sensorPara.SetIntegralUnits(m_integralUnits.GetInt());
	sensorPara.SetIsReference(m_isReference.GetInt());
	sensorPara.SetMaxFrequency(m_maxFrequency.GetFloatOrDouble());
	sensorPara.SetMessureType(m_messureType.GetInt());
	sensorPara.SetMileageRange(m_mileageRange.GetFloatOrDouble());
	sensorPara.SetPointNum(m_pointNum.GetInt());
	sensorPara.SetProjectId(m_projectId.GetInt());
	sensorPara.SetSensitivity(m_sensitivity.GetFloatOrDouble());
	sensorPara.SetSensorDesc(m_sensorDesc.m_strValue);
	sensorPara.SetSensorId(m_sersorId.GetInt());
	sensorPara.SetSensorIsUsed(m_isUsed.GetInt());
	sensorPara.SetSensorStatus(m_sersorStatus.GetInt());
	sensorPara.SetTriggerMagnitude(m_triggerMagnitude.GetFloatOrDouble());
	sensorPara.SetTriggerPolarity(m_triggerPolarity.GetInt());
	sensorPara.SetWindowType(m_windowType.GetInt());
}