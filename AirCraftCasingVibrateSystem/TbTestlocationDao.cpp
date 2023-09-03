#include "stdafx.h"
#include "TbTestlocationDao.h"
TbTestlocationDao::TbTestlocationDao()
{
	this->m_strTableName = "tb_testlocation";
	m_key = &m_locationId;
	SetVectorAndField("location_id", "int", m_locationId);
	SetVectorAndField("location_name", "CString", m_locationName);
	SetVectorAndField("product_type_id", "int", m_productTypeId);
}
TbTestlocationDao::TbTestlocationDao(const TbTestlocationDao &testlocation)
{
	this->m_strTableName = "tb_testlocation";
	m_key = &m_locationId;
	SetVectorAndField("location_id", "int", m_locationId);
	SetVectorAndField("location_name", "CString", m_locationName);
	SetVectorAndField("product_type_id", "int", m_productTypeId);
	operator = (testlocation);

}
TbTestlocationDao::~TbTestlocationDao()
{

}
void TbTestlocationDao::SetTableFieldValues(TbTestlocation testlocation)
{
	this->m_locationId.SetValue(testlocation.GetLocationId());
	this->m_locationName.SetValue(testlocation.GetLocationName());
	this->m_productTypeId.SetValue(testlocation.GetProductTypeId());
}
void TbTestlocationDao::GetTableFieldValues(TbTestlocation &testlocation)
{
	testlocation.SetLocationId(m_locationId.GetInt());
	testlocation.SetLocationName(m_locationName.m_strValue);
	testlocation.SetProductTypeId(m_productTypeId.GetInt());
}

bool TbTestlocationDao::SelectObjectsByCondition(vector<TbTestlocationDao> &selectedValueVector, CString strSqlQueryWhere )
{
	int iStartNumberIn = 0; int iRecordCountIn = 0;
	return SelectObjectsByCondition(selectedValueVector, iStartNumberIn, iRecordCountIn, strSqlQueryWhere);

}
bool TbTestlocationDao::SelectObjectsByCondition(vector<TbTestlocationDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere )
{
	vector<CString> tmpDetectedObjecIDs;
	TbTestlocationDao testlocation;
	if (testlocation.GetKeyIdList(tmpDetectedObjecIDs, strSqlQueryWhere, iStartNumber, iRecordCount))
	{
		for (int iStart = 0; iStart < tmpDetectedObjecIDs.size(); iStart++)
		{
			testlocation.m_locationId.m_strValue = tmpDetectedObjecIDs[iStart];
			if (testlocation.SelectByKey())
			{
				selectedValueVector.push_back(testlocation);
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
