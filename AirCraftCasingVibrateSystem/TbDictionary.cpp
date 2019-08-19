#include "stdafx.h"
#include "TbDictionary.h"


TbDictionary::TbDictionary()
{
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