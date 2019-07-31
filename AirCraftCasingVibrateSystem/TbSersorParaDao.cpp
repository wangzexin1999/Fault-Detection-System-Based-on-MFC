#include "stdafx.h"
#include "TbSersorParaDao.h"


TbSersorParaDao::TbSersorParaDao()
{
	
	this->m_strTableName = "tb_sensorpara";
	m_key = &m_sensorParaId;
	SetVectorAndField("sensorpara_id", "int", m_sensorParaId);
	SetVectorAndField("project_id", "int", m_projectId);
	SetVectorAndField("sensor_id", "int", m_sersorId);
	SetVectorAndField("sensor_status", "CString", m_sersorStatus);
	SetVectorAndField("measure_type", "CString", m_messureType);
	SetVectorAndField("sensor_desc", "CString", m_sensorDesc);
	SetVectorAndField("window_type", "int", m_windowType);
	SetVectorAndField("trigger_magnitude", "float", m_triggerMagnitude);
	SetVectorAndField("trigger_ polarity", "int", m_triggerPolarity);
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
	SetVectorAndField("anti_aliasing_filtering", "CString", m_antiAliasingFiltering);
	SetVectorAndField("max_frequency", "float", m_maxFrequency);
	SetVectorAndField("is_used", "char", m_isUsed);
}

TbSersorParaDao::~TbSersorParaDao()
{
}
TbSersorParaDao::TbSersorParaDao(const TbSersorParaDao &sersorPara){
	this->m_strTableName = "tb_sensorpara";
	m_key = &m_sensorParaId;
	SetVectorAndField("sensorpara_id", "int", m_sensorParaId);
	SetVectorAndField("project_id", "int", m_projectId);
	SetVectorAndField("sensor_id", "int", m_sersorId);
	SetVectorAndField("sensor_status", "CString", m_sersorStatus);
	SetVectorAndField("measure_type", "CString", m_messureType);
	SetVectorAndField("sensor_desc", "CString", m_sensorDesc);
	SetVectorAndField("window_type", "int", m_windowType);
	SetVectorAndField("trigger_magnitude", "float", m_triggerMagnitude);
	SetVectorAndField("trigger_ polarity", "int", m_triggerPolarity);
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
	SetVectorAndField("anti_aliasing_filtering", "CString", m_antiAliasingFiltering);
	SetVectorAndField("max_frequency", "float", m_maxFrequency);
	SetVectorAndField("is_used", "char", m_isUsed);
	operator = (sersorPara);
}
bool TbSersorParaDao::SelectObjectsByCondition(vector<TbSersorParaDao> &selectedValueVector, CString strSqlQueryWhere){
	int iStartNumberIn = 0; int iRecordCountIn = 0;
	return SelectObjectsByCondition(selectedValueVector, iStartNumberIn, iRecordCountIn, strSqlQueryWhere);
}


bool TbSersorParaDao::SelectObjectsByCondition(vector<TbSersorParaDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere){

	vector<CString> tmpDetectedObjecIDs;
	TbSersorParaDao project;
	if (project.GetKeyIdList(tmpDetectedObjecIDs, strSqlQueryWhere, iStartNumber, iRecordCount))
	{
		for (int iStart = 0; iStart < tmpDetectedObjecIDs.size(); iStart++)
		{
			project.m_projectId.m_strValue = tmpDetectedObjecIDs[iStart];
			if (project.SelectByKey())
			{
				selectedValueVector.push_back(project);
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



