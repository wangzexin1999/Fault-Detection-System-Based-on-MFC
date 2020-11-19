#pragma once
#include "PDDatabase.h"
#include "TbTeststand.h"
using namespace std;
class TbTeststandDao :public PDDatabase
{
public:
	TbTeststandDao();
	TbTeststandDao(const TbTeststandDao &teststand);
	~TbTeststandDao();

public:

	PDAttribute m_standId;
	PDAttribute m_testlocationId;
	PDAttribute m_teststateId;
	PDAttribute m_frequency;
	PDAttribute m_peakValue;
	PDAttribute m_grossValue;


	void SetTableFieldValues(TbTeststand teststand);
	void GetTableFieldValues(TbTeststand &teststand);

	bool SelectObjectsByCondition(vector<TbTeststandDao> &selectedValueVector, CString strSqlQueryWhere = "");
	bool SelectObjectsByCondition(vector<TbTeststandDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere = "");

};