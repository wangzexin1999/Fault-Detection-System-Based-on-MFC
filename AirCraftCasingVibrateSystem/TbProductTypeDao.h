#pragma once
#include "PDDatabase.h"
#include "TbProductType.h"
class TbProductTypeDao :
	public PDDatabase
{
public:

	TbProductTypeDao();
	TbProductTypeDao(const TbProductTypeDao & productType);

	~TbProductTypeDao();




	PDAttribute m_Id;
	PDAttribute m_typeName;


	void GetTableFieldValues(TbProductType &productType);
	bool SelectObjectsByCondition(vector<TbProductTypeDao> &selectedValueVector, CString strSqlQueryWhere = "");
	bool SelectObjectsByCondition(vector<TbProductTypeDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere = "");
	void SetTableFieldValues(TbProductType productType);
};