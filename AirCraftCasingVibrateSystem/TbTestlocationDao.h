#pragma once
#include "PDDatabase.h"
#include "TbTestlocation.h"
using namespace std;
class TbTestlocationDao :public PDDatabase
{
public:
	TbTestlocationDao();
	TbTestlocationDao(const TbTestlocationDao &testlocation);
	~TbTestlocationDao();

public:
	PDAttribute m_locationId;
	PDAttribute m_locationName;
	PDAttribute m_productTypeId;

	void SetTableFieldValues(TbTestlocation testlocation);
	void GetTableFieldValues(TbTestlocation &testlocation);

	bool SelectObjectsByCondition(vector<TbTestlocationDao> &selectedValueVector, CString strSqlQueryWhere = "");
	bool SelectObjectsByCondition(vector<TbTestlocationDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere = "");

};