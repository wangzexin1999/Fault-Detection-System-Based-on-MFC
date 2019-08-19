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

void TbDictionaryDao::SelectByObject(TbDictionary &dictionary){
	m_dictId.SetValue(dictionary.GetDictId());
	bool isSuccess = SelectByKey();
	if (isSuccess){
		GetTableFieldValues(dictionary);
	}
}