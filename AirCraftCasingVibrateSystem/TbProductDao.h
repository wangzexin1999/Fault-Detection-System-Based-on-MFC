#pragma once
#include "PDDatabase.h"
#include "TbProduct.h"
class TbProductDao :
	public PDDatabase
{
public:

	TbProductDao();
	TbProductDao(const TbProductDao & product);

	~TbProductDao();

	PDAttribute m_productId;
	PDAttribute m_productName;
	PDAttribute m_productType;
	

	void GetTableFieldValues(TbProduct &product);
	bool SelectObjectsByCondition(vector<TbProductDao> &selectedValueVector, CString strSqlQueryWhere = "");
	bool SelectObjectsByCondition(vector<TbProductDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere = "");
};

