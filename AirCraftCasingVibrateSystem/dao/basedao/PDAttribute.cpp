#include "stdafx.h"
#include "PDAttribute.h"


PDAttribute::PDAttribute()
{
}

PDAttribute::PDAttribute(const PDAttribute &dbAttribute)
{
	this->m_strKind = dbAttribute.m_strKind;
	this->m_strSqlField = dbAttribute.m_strSqlField;
	this->m_strValue = dbAttribute.m_strValue;
}

//void PDAttribute::operator = (const PDAttribute &dbAttribute)
//{
//	this->m_strKind = dbAttribute.m_strKind;
//	this->m_strSqlField = dbAttribute.m_strSqlField;
//	this->m_strValue = dbAttribute.m_strValue;
//}

PDAttribute::~PDAttribute()
{
}

void PDAttribute::CreateSQLWord(CString strSqlField, CString strKind)
{
	this->m_strSqlField = strSqlField;
	this->m_strKind = strKind;
	this->m_strValue = "";
}

void PDAttribute::SetValue(int value)
{
	ASSERT(this->m_strKind == "int" || this->m_strKind == "char");
	this->m_strValue.Format("%d", value);
}

void PDAttribute::SetValue(float value)
{
	ASSERT(this->m_strKind == "float");
	this->m_strValue.Format("%.6f", value);
}

void PDAttribute::SetValue(double value)
{
	ASSERT(this->m_strKind == "double");
	this->m_strValue.Format("%.6lf", value);
}

void PDAttribute::SetValue(CString value)
{
	ASSERT(this->m_strKind == "CString");
	this->m_strValue = value;
}

int PDAttribute::GetInt()
{
	if (this->m_strKind == "int" || this->m_strKind=="char")
		return atoi(this->m_strValue);
	else
		ASSERT(0);
}

float PDAttribute::GetFloatOrDouble()
{
	if (this->m_strKind == "float" || this->m_strKind == "double")
		return atof(this->m_strValue);
	else
		ASSERT(0);
}
