#include "stdafx.h"
#include "TbSignalTestRecordDao.h"
TbSignalTestRecordDao::TbSignalTestRecordDao()
{
	this->m_strTableName = "tb_signal_test_record";
	m_key = &m_recordId;
	SetVectorAndField("record_id", "int", m_recordId);
	SetVectorAndField("record_time", "CString", m_recordTime);
	SetVectorAndField("frequency", "double", m_frequency);
	SetVectorAndField("peak_value", "double", m_peakValue);
	SetVectorAndField("gross_value", "double", m_grossValue);
	SetVectorAndField("signal_id", "int", m_signalId);
}
TbSignalTestRecordDao::TbSignalTestRecordDao(const TbSignalTestRecordDao &signalTestRecord)
{
	this->m_strTableName = "tb_signal_test_record";
	m_key = &m_recordId;
	SetVectorAndField("record_id", "int", m_recordId);
	SetVectorAndField("record_time", "CString", m_recordTime);
	SetVectorAndField("frequency", "double", m_frequency);
	SetVectorAndField("peak_value", "double", m_peakValue);
	SetVectorAndField("gross_value", "double", m_grossValue);
	SetVectorAndField("signal_id", "int", m_signalId);
	operator = (signalTestRecord);
}
TbSignalTestRecordDao::~TbSignalTestRecordDao()
{

}
void TbSignalTestRecordDao::SetTableFieldValues(TbSignalTestRecord signalTestRecord)
{
	m_recordId.SetValue(signalTestRecord.GetRecordId());
	m_recordTime.SetValue(signalTestRecord.GetRecordTime());
	m_frequency.SetValue(signalTestRecord.GetFrequency());
	m_peakValue.SetValue(signalTestRecord.GetPeakValue());
	m_grossValue.SetValue(signalTestRecord.GetGrossValue());
	//this->m_signalId.SetValue(signalTestRecord.GetSignal().GetSignalId());
	m_signalId.SetValue(signalTestRecord.GetSignalId());
}
void TbSignalTestRecordDao::GetTableFieldValues(TbSignalTestRecord &signalTestRecord)
{
	signalTestRecord.SetRecordId(m_recordId.GetInt());
	signalTestRecord.SetRecordTime(m_recordTime.m_strValue);
	signalTestRecord.SetFrequency(m_frequency.GetFloatOrDouble());
	signalTestRecord.SetPeakValue(m_peakValue.GetFloatOrDouble());
	signalTestRecord.SetGrossValue(m_grossValue.GetFloatOrDouble());
	//signalTestRecord.GetSignal().SetSignalId(m_signalId.GetInt());
	signalTestRecord.SetSignalId(m_signalId.GetInt());
}

bool TbSignalTestRecordDao::SelectObjectsByCondition(vector<TbSignalTestRecordDao> &selectedValueVector, CString strSqlQueryWhere = "")
{
	int iStartNumberIn = 0; int iRecordCountIn = 0;
	return SelectObjectsByCondition(selectedValueVector, iStartNumberIn, iRecordCountIn, strSqlQueryWhere);

}
bool TbSignalTestRecordDao::SelectObjectsByCondition(vector<TbSignalTestRecordDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere = "")
{
	vector<CString> tmpDetectedObjecIDs;
	TbSignalTestRecordDao signalTestRecord;
	if (signalTestRecord.GetKeyIdList(tmpDetectedObjecIDs, strSqlQueryWhere, iStartNumber, iRecordCount))
	{
		for (int iStart = 0; iStart < tmpDetectedObjecIDs.size(); iStart++)
		{
			signalTestRecord.m_recordId.m_strValue = tmpDetectedObjecIDs[iStart];
			if (signalTestRecord.SelectByKey())
			{
				selectedValueVector.push_back(signalTestRecord);
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
