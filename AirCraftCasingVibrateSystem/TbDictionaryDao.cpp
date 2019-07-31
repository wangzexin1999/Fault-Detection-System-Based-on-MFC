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

TbDictionaryDao::~TbDictionaryDao()
{
	
}
