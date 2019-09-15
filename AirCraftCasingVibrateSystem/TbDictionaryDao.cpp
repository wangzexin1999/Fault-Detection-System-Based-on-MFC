#include "stdafx.h"
#include "TbDictionaryDao.h"


TbDictionaryDao::TbDictionaryDao()
{
	this->m_strTableName = "tb_dictionary";
	m_key = &m_dictId;
	SetVectorAndField("dict_id", "int", m_dictId);
	SetVectorAndField("dict_name", "CString", m_dictName);
	SetVectorAndField("dict_value", "CString", m_dictValue);
}
TbDictionaryDao::TbDictionaryDao(const TbDictionaryDao  & dictionary){
	this->m_strTableName = "tb_dictionary";
	m_key = &m_dictId;
	SetVectorAndField("dict_id", "int", m_dictId);
	SetVectorAndField("dict_name", "CString", m_dictName);
	SetVectorAndField("dict_value", "CString", m_dictValue);
	operator = (dictionary);
}

TbDictionaryDao::~TbDictionaryDao(){}

void TbDictionaryDao::GetTableFieldValues(TbDictionary &dictionary){
	dictionary.SetDictId(m_dictId.GetInt());
	dictionary.SetDictName(m_dictName.m_strValue);
	dictionary.SetDictValue(m_dictValue.m_strValue);
}
void TbDictionaryDao::SetTableFieldValues(TbDictionary dictionary){
	m_dictId.SetValue(dictionary.GetDictId());
	m_dictName.SetValue(dictionary.GetDictName());
	m_dictValue.SetValue(dictionary.GetDictValue());
}
void TbDictionaryDao::SelectByObject(TbDictionary &dictionary){
	m_dictId.SetValue(dictionary.GetDictId());
	bool isSuccess = SelectByKey();
	if (isSuccess){
		GetTableFieldValues(dictionary);
	}
}

bool TbDictionaryDao::SelectObjectsByCondition(vector<TbDictionaryDao> &selectedValueVector, CString strSqlQueryWhere){
	return SelectObjectsByCondition(selectedValueVector, 0, 0, strSqlQueryWhere);
}

bool TbDictionaryDao::SelectObjectsByCondition(vector<TbDictionaryDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere){
	vector<CString> tmpDetectedObjecIDs;
	TbDictionaryDao dictionary;
	if (dictionary.GetKeyIdList(tmpDetectedObjecIDs, strSqlQueryWhere, iStartNumber, iRecordCount))
	{
		for (int iStart = 0; iStart < tmpDetectedObjecIDs.size(); iStart++)
		{
			dictionary.m_dictId.m_strValue = tmpDetectedObjecIDs[iStart];
			if (dictionary.SelectByKey())
			{
				selectedValueVector.push_back(dictionary);
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