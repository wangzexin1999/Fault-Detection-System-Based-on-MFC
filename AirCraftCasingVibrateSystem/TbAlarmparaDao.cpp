#include "stdafx.h"
#include "TbAlarmparaDao.h"



TbAlarmparaDao::TbAlarmparaDao()
{
	this->m_strTableName = "tb_alarm_para";
	m_key = &m_alarmId;
	SetVectorAndField("alarm_id", "int", m_alarmId);
	SetVectorAndField("frequency", "double", m_frequency);
	SetVectorAndField("peak_value", "double", m_peakValue);
	SetVectorAndField("gross_value", "double", m_grossValue);
	SetVectorAndField("channel_id", "int", m_channelId);
	SetVectorAndField("status", "int", m_status);

}

TbAlarmparaDao::~TbAlarmparaDao()
{

}
TbAlarmparaDao::TbAlarmparaDao(const TbAlarmparaDao & alarmpara){
	this->m_strTableName = "tb_alarm_para";
	m_key = &m_alarmId;
	SetVectorAndField("alarm_id", "int", m_alarmId);
	SetVectorAndField("frequency", "double", m_frequency);
	SetVectorAndField("peak_value", "double", m_peakValue);
	SetVectorAndField("gross_value", "double", m_grossValue);
	SetVectorAndField("channel_id", "int", m_channelId);
	SetVectorAndField("status", "int", m_status);
	operator = (alarmpara);
}

bool TbAlarmparaDao::SelectObjectsByCondition(vector<TbAlarmparaDao> &selectedValueVector, CString strSqlQueryWhere){

	int iStartNumberIn = 0; int iRecordCountIn = 0;
	return SelectObjectsByCondition(selectedValueVector, iStartNumberIn, iRecordCountIn, strSqlQueryWhere);
}

bool TbAlarmparaDao::SelectObjectsByCondition(vector<TbAlarmparaDao> &selectedValueVector, int iStartNumberIn, int iRecordCountIn, CString strSqlQueryWhere)
{
	vector<CString> tmpDetectedObjecIDs;
	TbAlarmparaDao alarmparaDao;
	if (alarmparaDao.GetKeyIdList(tmpDetectedObjecIDs, strSqlQueryWhere, iStartNumberIn, iRecordCountIn))
	{
		for (int iStart = 0; iStart < tmpDetectedObjecIDs.size(); iStart++)
		{
			alarmparaDao.m_alarmId.m_strValue = tmpDetectedObjecIDs[iStart];
			if (alarmparaDao.SelectByKey())
			{
				selectedValueVector.push_back(alarmparaDao);
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
void  TbAlarmparaDao::GetTableFieldValues(TbAlarmpara & alarmpara){
	alarmpara.SetAlarmId(m_alarmId.GetInt());
	alarmpara.SetFrequency(m_frequency.GetFloatOrDouble());
	alarmpara.SetGrossValue(m_grossValue.GetFloatOrDouble());
	alarmpara.SetPeakValue(m_peakValue.GetFloatOrDouble());
	alarmpara.SetStatus(m_status.GetInt());
	alarmpara.GetChannel().SetId(m_channelId.GetInt());

}
void TbAlarmparaDao::SetTableFieldValues(TbAlarmpara alarmpara){
	m_alarmId.SetValue(alarmpara.GetAlarmId());
	m_frequency.SetValue(alarmpara.GetFrequency());
	m_grossValue.SetValue(alarmpara.GetGrossValue());
	m_peakValue.SetValue(alarmpara.GetPeakValue());
	m_status.SetValue(alarmpara.GetStatus());
	m_channelId.SetValue(alarmpara.GetChannel().GetId());
}