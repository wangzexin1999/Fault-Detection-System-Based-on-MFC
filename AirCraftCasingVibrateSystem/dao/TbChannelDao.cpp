#include "stdafx.h"
#include "TbChannelDao.h"



TbChannelDao::TbChannelDao()
{
	this->m_strTableName = "tb_channel";
	m_key = &m_id;
	SetVectorAndField("id", "int", m_id);
	SetVectorAndField("channel_code", "CString", m_channelCode);
	SetVectorAndField("sensor_id", "int", m_sensorId);
	SetVectorAndField("channel_desc", "CString", m_channelDesc);
	//SetVectorAndField("equipment_id", "int", m_equipmentId);
	SetVectorAndField("collectionparas_id", "int", m_collectionparasId);
	SetVectorAndField("channel_status", "char", m_sersorStatus);
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
	SetVectorAndField("mileage_range", "int", m_mileageRange);
	SetVectorAndField("integral_type", "int", m_integralType);
	SetVectorAndField("integral_units", "int", m_integralUnits);
	SetVectorAndField("input_method", "int", m_inputMethod);
	SetVectorAndField("anti_aliasing_filtering", "char", m_antiAliasingFiltering);
	SetVectorAndField("max_frequency", "float", m_maxFrequency);

}

TbChannelDao::~TbChannelDao()
{

}
TbChannelDao::TbChannelDao(const TbChannelDao & channel){
	this->m_strTableName = "tb_channel";
	m_key = &m_id;
	SetVectorAndField("id", "int", m_id);
	SetVectorAndField("channel_code", "CString", m_channelCode);
	SetVectorAndField("sensor_id", "int", m_sensorId);
	SetVectorAndField("channel_desc", "CString", m_channelDesc);
	//SetVectorAndField("equipment_id", "int", m_equipmentId);
	SetVectorAndField("collectionparas_id", "int", m_collectionparasId);
	SetVectorAndField("channel_status", "char", m_sersorStatus);
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
	SetVectorAndField("mileage_range", "int", m_mileageRange);
	SetVectorAndField("integral_type", "int", m_integralType);
	SetVectorAndField("integral_units", "int", m_integralUnits);
	SetVectorAndField("input_method", "int", m_inputMethod);
	SetVectorAndField("anti_aliasing_filtering", "char", m_antiAliasingFiltering);
	SetVectorAndField("max_frequency", "float", m_maxFrequency);
	operator = (channel);
}

bool TbChannelDao::SelectObjectsByCondition(vector<TbChannelDao> &selectedValueVector, CString strSqlQueryWhere){

	int iStartNumberIn = 0; int iRecordCountIn = 0;
	return SelectObjectsByCondition(selectedValueVector, iStartNumberIn, iRecordCountIn, strSqlQueryWhere);
}

bool TbChannelDao::SelectObjectsByCondition(vector<TbChannelDao> &selectedValueVector, int iStartNumberIn, int iRecordCountIn, CString strSqlQueryWhere)
{
	vector<CString> tmpDetectedObjecIDs;
	TbChannelDao channelDao;
	if (channelDao.GetKeyIdList(tmpDetectedObjecIDs, strSqlQueryWhere, iStartNumberIn, iRecordCountIn))
	{
		for (int iStart = 0; iStart < tmpDetectedObjecIDs.size(); iStart++)
		{
			channelDao.m_id.m_strValue = tmpDetectedObjecIDs[iStart];
			if (channelDao.SelectByKey())
			{
				selectedValueVector.push_back(channelDao);
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
void  TbChannelDao::GetTableFieldValues(TbChannel & channel){
	channel.SetId(m_id.GetInt());
	channel.SetChannelCode(m_channelCode.m_strValue);
	channel.SetAntiAliasingFiltering(m_antiAliasingFiltering.GetInt());
	channel.GetCoordinateSystem().SetDictId(m_coordinateSystem.GetInt());
	channel.GetCoordinateSystemDirection().SetDictId(m_coordinateSystemDirection.GetInt());
	channel.GetEngineeringUnits().SetDictId(m_engineeringUnits.GetInt());
	channel.GetInputMethod().SetDictId(m_inputMethod.GetInt());
	channel.GetIntegralType().SetDictId(m_integralType.GetInt());
	channel.GetIntegralUnits().SetDictId(m_integralUnits.GetInt());
	channel.SetIsReference(m_isReference.GetInt());
	channel.SetMaxFrequency(m_maxFrequency.GetFloatOrDouble());
	channel.GetMessureType().SetDictId(m_messureType.GetInt());
	channel.SetMileageRange(m_mileageRange.GetInt());
	channel.SetPointNum(m_pointNum.GetInt());
	channel.SetCollectionparasId(m_collectionparasId.GetInt());
	channel.SetSensitivity(m_sensitivity.GetFloatOrDouble());
	channel.SetChannelDesc(m_channelDesc.m_strValue);
	channel.GetChannelStatus().SetDictId(m_sersorStatus.GetInt());
	channel.SetTriggerMagnitude(m_triggerMagnitude.GetFloatOrDouble());
	channel.GetTriggerPolarity().SetDictId(m_triggerPolarity.GetInt());
	channel.GetWindowType().SetDictId(m_windowType.GetInt());
	channel.GetSensor().SetSensorId(m_sensorId.GetInt());
	//channel.GetEquipment().SetEquipmentId(m_equipmentId.GetInt());
}
void TbChannelDao::SetTableFieldValues(TbChannel channel){
	m_antiAliasingFiltering.SetValue(channel.GetAntiAliasingFiltering());
	m_coordinateSystem.SetValue(channel.GetCoordinateSystem().GetDictId());
	m_coordinateSystemDirection.SetValue(channel.GetCoordinateSystemDirection().GetDictId());
	m_engineeringUnits.SetValue(channel.GetEngineeringUnits().GetDictId());
	m_id.SetValue(channel.GetId());
	m_inputMethod.SetValue(channel.GetInputMethod().GetDictId());
	m_integralType.SetValue(channel.GetIntegralType().GetDictId());
	m_integralUnits.SetValue(channel.GetIntegralUnits().GetDictId());
	m_isReference.SetValue(channel.GetIsReference());
	m_maxFrequency.SetValue(channel.GetMaxFrequency());
	m_messureType.SetValue(channel.GetIntegralType().GetDictId());
	m_mileageRange.SetValue(channel.GetMileageRange());
	m_pointNum.SetValue(channel.GetPointNum());
	m_collectionparasId.SetValue(channel.GetCollectionparasId());
	m_sensitivity.SetValue(channel.GetSensitivity());
	m_channelDesc.SetValue(channel.GetChannelDesc());
	m_channelCode.SetValue(channel.GetChannelCode());
	m_sersorStatus.SetValue(channel.GetChannelStatus().GetDictId());
	m_triggerMagnitude.SetValue(channel.GetTriggerMagnitude());
	m_triggerPolarity.SetValue(channel.GetTriggerPolarity().GetDictId());
	m_windowType.SetValue(channel.GetWindowType().GetDictId());

	m_sensorId.SetValue(channel.GetSensor().GetSensorId());
	//m_equipmentId.SetValue(channel.GetEquipment().GetEquipmentId());
}