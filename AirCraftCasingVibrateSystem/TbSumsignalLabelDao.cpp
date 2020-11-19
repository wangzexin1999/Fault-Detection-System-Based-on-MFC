#include "stdafx.h"
#include "TbSumsignalLabelDao.h"
TbSumsignalLabelDao::TbSumsignalLabelDao()
{
	this->m_strTableName = "tb_sumsignal_label";
	m_key = &m_id;
	SetVectorAndField("id", "int", m_id);
	SetVectorAndField("sumsignal_id ", "CString", m_sumsignalId);
	SetVectorAndField("label_id", "int", m_labelId);
	SetVectorAndField("start_time", "CString", m_startTime);
	SetVectorAndField("end_time", "CString", m_endTime);
}
TbSumsignalLabelDao::TbSumsignalLabelDao(const TbSumsignalLabelDao &sumsignalLabel)
{
	this->m_strTableName = "tb_sumsignal_label";
	m_key = &m_id;
	SetVectorAndField("id", "int", m_id);
	SetVectorAndField("sumsignal_id ", "CString", m_sumsignalId);
	SetVectorAndField("label_id", "int", m_labelId);
	SetVectorAndField("start_time", "CString", m_startTime);
	SetVectorAndField("end_time", "CString", m_endTime);
	operator = (sumsignalLabel);
}
TbSumsignalLabelDao::~TbSumsignalLabelDao()
{

}

void TbSumsignalLabelDao::SetTableFieldValues(TbSumsignalLabel sumsignalLabel)
{
	this->m_id.SetValue(sumsignalLabel.GetId());
	this->m_sumsignalId.SetValue(sumsignalLabel.GetSumsignalId());
	//this->m_labelId.SetValue(sumsignalLabel.GetLabel().GetLabelId());
	this->m_labelId.SetValue(sumsignalLabel.GetLabel());
	this->m_startTime.SetValue(sumsignalLabel.GetStartTime());
	this->m_endTime.SetValue(sumsignalLabel.GetEndTime());

}
void TbSumsignalLabelDao::GetTableFieldValues(TbSumsignalLabel &sumsignalLabel)
{
	sumsignalLabel.SetId(m_id.GetInt());
	sumsignalLabel.SetSumsignalId(m_sumsignalId.m_strValue);
	//sumsignalLabel.GetLabel().SetLabelId(m_labelId.GetInt());
	sumsignalLabel.SetLabel(m_labelId.GetInt());
	sumsignalLabel.SetStartTime(m_startTime.m_strValue);
	sumsignalLabel.SetEndTime(m_endTime.m_strValue);
}

bool TbSumsignalLabelDao::SelectObjectsByCondition(vector<TbSumsignalLabelDao> &selectedValueVector, CString strSqlQueryWhere = "")
{
	int iStartNumberIn = 0; int iRecordCountIn = 0;
	return SelectObjectsByCondition(selectedValueVector, iStartNumberIn, iRecordCountIn, strSqlQueryWhere);

}
bool TbSumsignalLabelDao::SelectObjectsByCondition(vector<TbSumsignalLabelDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere = "")
{
	vector<CString> tmpDetectedObjecIDs;
	TbSumsignalLabelDao sumsignalLabel;
	if (sumsignalLabel.GetKeyIdList(tmpDetectedObjecIDs, strSqlQueryWhere, iStartNumber, iRecordCount))
	{
		for (int iStart = 0; iStart < tmpDetectedObjecIDs.size(); iStart++)
		{
			sumsignalLabel.m_id.m_strValue = tmpDetectedObjecIDs[iStart];
			if (sumsignalLabel.SelectByKey())
			{
				selectedValueVector.push_back(sumsignalLabel);
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
