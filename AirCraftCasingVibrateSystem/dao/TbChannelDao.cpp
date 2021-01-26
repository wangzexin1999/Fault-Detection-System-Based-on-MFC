#include "stdafx.h"
#include "TbChannelDao.h"
#include "AirCraftCasingVibrateSystem.h"


TbChannelDao::TbChannelDao()
{
	this->m_strTableName = "tb_channel";
	m_key = &m_id;
	SetVectorAndField("id", "int", m_id);
	SetVectorAndField("channel_code", "CString", m_channelCode);
	SetVectorAndField("sensor_id", "int", m_sensorId);
	SetVectorAndField("channel_desc", "CString", m_channelDesc);
	//SetVectorAndField("equipment_id", "int", m_equipmentId);
	//SetVectorAndField("collectionparas_id", "int", m_collectionparasId);
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
	SetVectorAndField("sensitivity", "float", m_sensitivity);//������
	SetVectorAndField("full_value", "int", m_fullvalue);//��������
	SetVectorAndField("integral_type", "int", m_integralType);
	SetVectorAndField("integral_units", "int", m_integralUnits);
	SetVectorAndField("input_mode", "int", m_inputMode);//���뷽ʽ
	SetVectorAndField("anti_aliasing_filtering", "char", m_antiAliasingFiltering);
	SetVectorAndField("up_freq", "int", m_upFreq);//����Ƶ��
	SetVectorAndField("elc_pressure", "int", m_elcpressure);//��ѹ������Χ
	SetVectorAndField("project_id", "int", m_projectId);//��Ŀ���
	
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
	//SetVectorAndField("collectionparas_id", "int", m_collectionparasId);
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
	SetVectorAndField("sensitivity", "float", m_sensitivity);//������
	SetVectorAndField("full_value", "int", m_fullvalue);//��������
	SetVectorAndField("integral_type", "int", m_integralType);
	SetVectorAndField("integral_units", "int", m_integralUnits);
	SetVectorAndField("input_method", "int", m_inputMode);//���뷽ʽ
	SetVectorAndField("anti_aliasing_filtering", "char", m_antiAliasingFiltering);
	SetVectorAndField("up_freq", "int", m_upFreq);//����Ƶ��
	SetVectorAndField("elc_pressure", "int", m_elcpressure);//��ѹ������Χ
	SetVectorAndField("project_id", "int", m_projectId);//��Ŀ���
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
	channel.SetInputMode(std::make_pair(m_inputMode.GetInt(), theApp.m_listInputMode[m_inputMode.GetInt()].c_str()));
	channel.GetIntegralType().SetDictId(m_integralType.GetInt());
	channel.GetIntegralUnits().SetDictId(m_integralUnits.GetInt());
	channel.SetIsReference(m_isReference.GetInt());
	channel.SetUpFreq(std::make_pair(m_upFreq.GetInt(), theApp.m_listUpFreq[m_upFreq.GetInt()].c_str()));
	channel.SetMessureType(std::make_pair(m_messureType.GetInt(), theApp.m_listMessaueType[m_messureType.GetInt()].c_str()));
	channel.SetFullValue(std::make_pair(m_fullvalue.GetInt(), theApp.m_listFullValue[m_fullvalue.GetInt()].c_str()));
	channel.SetPointNum(m_pointNum.GetInt());
	//channel.SetCollectionparasId(m_collectionparasId.GetInt());
	channel.SetSensitivity(m_sensitivity.GetFloatOrDouble());
	channel.SetChannelDesc(m_channelDesc.m_strValue);
	channel.GetChannelStatus().SetDictId(m_sersorStatus.GetInt());
	channel.SetTriggerMagnitude(m_triggerMagnitude.GetFloatOrDouble());
	channel.GetTriggerPolarity().SetDictId(m_triggerPolarity.GetInt());
	channel.GetWindowType().SetDictId(m_windowType.GetInt());
	channel.GetSensor().SetSensorId(m_sensorId.GetInt());
	channel.SetProjectId(m_projectId.GetInt());
	channel.SetElcPressure(std::make_pair(m_elcpressure.GetInt(), theApp.m_elcpressure[m_elcpressure.GetInt()].c_str()));
	//channel.GetEquipment().SetEquipmentId(m_equipmentId.GetInt());
}
void TbChannelDao::SetTableFieldValues(TbChannel channel){
	m_antiAliasingFiltering.SetValue(channel.GetAntiAliasingFiltering());
	m_coordinateSystem.SetValue(channel.GetCoordinateSystem().GetDictId());
	m_coordinateSystemDirection.SetValue(channel.GetCoordinateSystemDirection().GetDictId());
	m_engineeringUnits.SetValue(channel.GetEngineeringUnits().GetDictId());
	m_id.SetValue(channel.GetId());
	m_inputMode.SetValue(channel.GetInputMode().first);
	m_integralType.SetValue(channel.GetIntegralType().GetDictId());
	m_integralUnits.SetValue(channel.GetIntegralUnits().GetDictId());
	m_isReference.SetValue(channel.GetIsReference());
	m_upFreq.SetValue(channel.GetUpFreq().first);
	m_messureType.SetValue(channel.GetMessureType().first);
	m_fullvalue.SetValue(channel.GetFullValue().first);
	m_pointNum.SetValue(channel.GetPointNum());
	//m_collectionparasId.SetValue(channel.GetCollectionparasId());
	m_sensitivity.SetValue(channel.GetSensitivity());
	m_channelDesc.SetValue(channel.GetChannelDesc());
	m_channelCode.SetValue(channel.GetChannelCode());
	m_sersorStatus.SetValue(channel.GetChannelStatus().GetDictId());
	m_triggerMagnitude.SetValue(channel.GetTriggerMagnitude());
	m_triggerPolarity.SetValue(channel.GetTriggerPolarity().GetDictId());
	m_windowType.SetValue(channel.GetWindowType().GetDictId());

	m_sensorId.SetValue(channel.GetSensor().GetSensorId());
	m_projectId.SetValue(channel.GetProjectId());
	m_elcpressure.SetValue(channel.GetElcPressure().first);
	//m_equipmentId.SetValue(channel.GetEquipment().GetEquipmentId());
}