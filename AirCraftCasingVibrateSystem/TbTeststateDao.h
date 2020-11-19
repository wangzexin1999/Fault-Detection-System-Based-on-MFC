#pragma once
#include "PDDatabase.h"
#include "TbTeststate.h"
using namespace std;
class TbTeststateDao :public PDDatabase
{
public:
	TbTeststateDao();
	TbTeststateDao(const TbTeststateDao &teststate);
	~TbTeststateDao();

public:

	PDAttribute m_stateId;
	PDAttribute  m_stateName;
	PDAttribute  m_speed;
	PDAttribute  m_acceleration;
	PDAttribute m_productTypeId;

	void SetTableFieldValues(TbTeststate teststate);
	void GetTableFieldValues(TbTeststate &teststate);

	bool SelectObjectsByCondition(vector<TbTeststateDao> &selectedValueVector, CString strSqlQueryWhere = "");
	bool SelectObjectsByCondition(vector<TbTeststateDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere = "");

};