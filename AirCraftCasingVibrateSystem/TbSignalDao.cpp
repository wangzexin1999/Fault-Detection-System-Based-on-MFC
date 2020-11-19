#include "stdafx.h"
#include "TbSignalDao.h"
TbSignalDao::TbSignalDao()
{
	this->m_strTableName = "tb_signal";
	m_key = &m_signalId;
	SetVectorAndField("signal_id", "int", m_signalId);
	SetVectorAndField("channel_id", "int", m_channelId);
	SetVectorAndField("sumsignal_id ", "CString", m_sumsignalId);
	SetVectorAndField("signal_status", "int", m_signalStatus);
	SetVectorAndField("data_url", "CString", m_dataUrl);
	//SetVectorAndField("sum_signal_id", "CString", m_sumSignalId);
}
TbSignalDao::TbSignalDao(const TbSignalDao &signal)
{
	this->m_strTableName = "tb_signal";
	m_key = &m_signalId;
	SetVectorAndField("signal_id", "int", m_signalId);
	SetVectorAndField("channel_id", "int", m_channelId);
	SetVectorAndField("sumsignal_id ", "CString", m_sumsignalId);
	SetVectorAndField("signal_status", "int", m_signalStatus);
	SetVectorAndField("data_url", "CString", m_dataUrl);
	//SetVectorAndField("sum_signal_id", "CString", m_sumSignalId);
	operator = (signal);
}
TbSignalDao::~TbSignalDao()
{

}

void TbSignalDao::SetTableFieldValues(TbSignal signal)
{
	this->m_signalId.SetValue(signal.GetSignalId());
	this->m_channelId.SetValue(signal.GetChannel().GetId());
	this->m_sumsignalId.SetValue(signal.GetSumsignal().GetSumsignalId());
	this->m_signalStatus.SetValue(signal.GetSignalStatus());
	this->m_dataUrl.SetValue(signal.GetDataUrl());
	//this->m_sumsignalId.SetValue(signal.GetSumSignal().GetSumsignalId());
}
void TbSignalDao::GetTableFieldValues(TbSignal &signal)
{
	signal.SetSignalId(m_signalId.GetInt());
	signal.GetChannel().SetId(m_channelId.GetInt());
	signal.GetSumsignal().SetSumsignalId(m_sumsignalId.m_strValue);
	signal.SetSignalStatus(m_signalStatus.GetInt());
	signal.SetDataUrl(m_dataUrl.m_strValue);
	//signal.GetSumSignal().SetSumsignalId(m_sumSignalId.m_strValue);
}

bool TbSignalDao::SelectObjectsByCondition(vector<TbSignalDao> &selectedValueVector, CString strSqlQueryWhere = "")
{
	int iStartNumberIn = 0; int iRecordCountIn = 0;
	return SelectObjectsByCondition(selectedValueVector, iStartNumberIn, iRecordCountIn, strSqlQueryWhere);

}
bool TbSignalDao::SelectObjectsByCondition(vector<TbSignalDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere = "")
{
	vector<CString> tmpDetectedObjecIDs;
	TbSignalDao signal;
	if (signal.GetKeyIdList(tmpDetectedObjecIDs, strSqlQueryWhere, iStartNumber, iRecordCount))
	{
		for (int iStart = 0; iStart < tmpDetectedObjecIDs.size(); iStart++)
		{
			signal.m_signalId.m_strValue = tmpDetectedObjecIDs[iStart];
			if (signal.SelectByKey())
			{
				selectedValueVector.push_back(signal);
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
