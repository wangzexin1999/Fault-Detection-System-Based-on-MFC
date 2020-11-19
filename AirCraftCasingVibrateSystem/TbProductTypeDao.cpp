#include "stdafx.h"
#include "TbProductTypeDao.h"
TbProductTypeDao::TbProductTypeDao()
{
	this->m_strTableName = "tb_product_type";
	m_key = &m_Id;
	SetVectorAndField("id", "int", m_Id);
	SetVectorAndField("type_name", "CString", m_typeName);
}
TbProductTypeDao::~TbProductTypeDao()
{
}
TbProductTypeDao::TbProductTypeDao(const TbProductTypeDao & productType)
{
	this->m_strTableName = "tb_product_type";
	m_key = &m_Id;
	SetVectorAndField("id", "int", m_Id);
	SetVectorAndField("type_name", "CString", m_typeName);
	operator = (productType);
}
bool TbProductTypeDao::SelectObjectsByCondition(vector<TbProductTypeDao> &selectedValueVector, CString strSqlQueryWhere){
	return SelectObjectsByCondition(selectedValueVector, 0, 0, strSqlQueryWhere);
}

bool TbProductTypeDao::SelectObjectsByCondition(vector<TbProductTypeDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere){
	vector<CString> tmpDetectedObjecIDs;
	TbProductTypeDao productType;
	if (productType.GetKeyIdList(tmpDetectedObjecIDs, strSqlQueryWhere, iStartNumber, iRecordCount))
	{
		for (int iStart = 0; iStart < tmpDetectedObjecIDs.size(); iStart++)
		{
			productType.m_Id.m_strValue = tmpDetectedObjecIDs[iStart];
			if (productType.SelectByKey())
			{
				selectedValueVector.push_back(productType);
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
void TbProductTypeDao::GetTableFieldValues(TbProductType &productType){
	productType.SetId(m_Id.GetInt());
	productType.SetTypeName(m_typeName.m_strValue);
}

void TbProductTypeDao::SetTableFieldValues(TbProductType productType)
{
	m_Id.SetValue(productType.GetId());
	m_typeName.SetValue(productType.GetTypeName());
}