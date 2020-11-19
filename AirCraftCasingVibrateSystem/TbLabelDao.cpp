#include "stdafx.h"
#include "TbLabelDao.h"
TbLabelDao::TbLabelDao()
{
	this->m_strTableName = "tb_label";
	m_key = &m_labelId;
	SetVectorAndField("label_id", "int", m_labelId);
	SetVectorAndField("label_name", "CString", m_labelName);
	SetVectorAndField("mark", "CString", m_mark);
}
TbLabelDao::TbLabelDao(const TbLabelDao &label)
{
	this->m_strTableName = "tb_label";
	m_key = &m_labelId;
	SetVectorAndField("label_id", "int", m_labelId);
	SetVectorAndField("label_name", "CString", m_labelName);
	SetVectorAndField("mark", "CString", m_mark);
	operator = (label);
}
TbLabelDao::~TbLabelDao()
{

}
void TbLabelDao::SetTableFieldValues(TbLabel label)
{
	this->m_labelId.SetValue(label.GetLabelId());
	this->m_labelName.SetValue(label.GetLabelName());
	this->m_mark.SetValue(label.GetMark());
}
void TbLabelDao::GetTableFieldValues(TbLabel &label)
{
	label.SetLabelId(m_labelId.GetInt());
	label.SetLabelName(m_labelName.m_strValue);
	label.SetMark(m_mark.m_strValue);

}

bool TbLabelDao::SelectObjectsByCondition(vector<TbLabelDao> &selectedValueVector, CString strSqlQueryWhere)
{
	int iStartNumberIn = 0; int iRecordCountIn = 0;
	return SelectObjectsByCondition(selectedValueVector, iStartNumberIn, iRecordCountIn, strSqlQueryWhere);

}
bool TbLabelDao::SelectObjectsByCondition(vector<TbLabelDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere )
{
	vector<CString> tmpDetectedObjecIDs;
	TbLabelDao label;
	if (label.GetKeyIdList(tmpDetectedObjecIDs, strSqlQueryWhere, iStartNumber, iRecordCount))
	{
		for (int iStart = 0; iStart < tmpDetectedObjecIDs.size(); iStart++)
		{
			label.m_labelId.m_strValue = tmpDetectedObjecIDs[iStart];
			if (label.SelectByKey())
			{
				selectedValueVector.push_back(label);
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
