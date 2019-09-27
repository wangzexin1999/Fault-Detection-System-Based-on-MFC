#include "stdafx.h"
#include "TbDictionary.h"


TbDictionary::TbDictionary(int dictId  , CString dictName , CString dictValue  )
{
	m_dictId = dictId;
	m_dictName = dictName;
	m_dictValue = dictValue;
}

bool TbDictionary::operator == (TbDictionary dictionary)
{

	bool tag = true;
	if (m_dictId != dictionary.GetDictId()) tag = false;
	if (m_dictValue != dictionary.GetDictValue())
	{
		tag = false;
	}
	return tag;
}

bool TbDictionary::operator != (TbDictionary dictionary)
{

	return *this == dictionary ? false : true;

}



TbDictionary::~TbDictionary()
{
}

void TbDictionary::SetDictValue(CString dictValue){
	this->m_dictValue = dictValue;
}
void TbDictionary::SetDictName(CString dictName){
	this->m_dictName = dictName;
}
void TbDictionary::SetDictId(int  dictId){
	this->m_dictId = dictId;
}

int TbDictionary::GetDictId(){
	return this->m_dictId;
}
CString TbDictionary::GetDictName(){
	return this->m_dictName;
}
CString TbDictionary::GetDictValue(){
	return this->m_dictValue;
}