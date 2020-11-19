#include "stdafx.h"
#include "TbTeststandDao.h"
TbTeststandDao::TbTeststandDao()
{
	this->m_strTableName = "tb_teststand";
	m_key = &m_standId;
	SetVectorAndField("stand_id", "int", m_standId);
	SetVectorAndField("test_location_id", "int", m_testlocationId);
	SetVectorAndField("test_state_id", "int", m_teststateId);
	SetVectorAndField("frequency", "double", m_frequency);
	SetVectorAndField("peak_value", "double", m_peakValue);
	SetVectorAndField("gross_value", "double", m_grossValue);
}
TbTeststandDao::TbTeststandDao(const TbTeststandDao &teststand)
{
	this->m_strTableName = "tb_teststand";
	m_key = &m_standId;
	SetVectorAndField("stand_id", "int", m_standId);
	SetVectorAndField("test_location_id", "int", m_testlocationId);
	SetVectorAndField("test_state_id", "int", m_teststateId);
	SetVectorAndField("frequency", "double", m_frequency);
	SetVectorAndField("peak_value", "double", m_peakValue);
	SetVectorAndField("gross_value", "double", m_grossValue);
	operator = (teststand);
}
TbTeststandDao::~TbTeststandDao()
{

}
void TbTeststandDao::SetTableFieldValues(TbTeststand teststand)
{
	this->m_standId.SetValue(teststand.GetStandId());
	this->m_testlocationId.SetValue(teststand.GetTestlocation().GetLocationId());
	this->m_teststateId.SetValue(teststand.GetTeststate().GetStateId());
	this->m_frequency.SetValue(teststand.GetFrequency());
	this->m_peakValue.SetValue(teststand.GetPeakValue());
	this->m_grossValue.SetValue(teststand.GetGrossValue());
}
void TbTeststandDao::GetTableFieldValues(TbTeststand &teststand)
{
	teststand.SetStandId(m_standId.GetInt());
	teststand.GetTestlocation().SetLocationId(m_testlocationId.GetInt());
	teststand.GetTeststate().SetStateId(m_teststateId.GetInt());
	teststand.SetFrequency(m_frequency.GetFloatOrDouble());
	teststand.SetPeakValue(m_peakValue.GetFloatOrDouble());
	teststand.SetGrossValue(m_grossValue.GetFloatOrDouble());
}

bool TbTeststandDao::SelectObjectsByCondition(vector<TbTeststandDao> &selectedValueVector, CString strSqlQueryWhere )
{
	int iStartNumberIn = 0; int iRecordCountIn = 0;
	return SelectObjectsByCondition(selectedValueVector, iStartNumberIn, iRecordCountIn, strSqlQueryWhere);

}
bool TbTeststandDao::SelectObjectsByCondition(vector<TbTeststandDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere )
{
	vector<CString> tmpDetectedObjecIDs;
	TbTeststandDao teststand;
	if (teststand.GetKeyIdList(tmpDetectedObjecIDs, strSqlQueryWhere, iStartNumber, iRecordCount))
	{
		for (int iStart = 0; iStart < tmpDetectedObjecIDs.size(); iStart++)
		{
			teststand.m_standId.m_strValue = tmpDetectedObjecIDs[iStart];
			if (teststand.SelectByKey())
			{
				selectedValueVector.push_back(teststand);
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
