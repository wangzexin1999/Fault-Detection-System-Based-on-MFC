#pragma once
#include "PDDatabase.h"
#include "TbSumsignalLabel.h"
using namespace std;
class TbSumsignalLabelDao :public PDDatabase
{
public:
	TbSumsignalLabelDao();
	TbSumsignalLabelDao(const TbSumsignalLabelDao &sumsignalLabel);
	~TbSumsignalLabelDao();

public:
	PDAttribute  m_id;
	PDAttribute m_sumsignalId;
	PDAttribute  m_labelId;
	PDAttribute m_startTime;
	PDAttribute m_endTime;


	void SetTableFieldValues(TbSumsignalLabel sumsignalLabel);
	void GetTableFieldValues(TbSumsignalLabel &sumsignalLabel);

	bool SelectObjectsByCondition(vector<TbSumsignalLabelDao> &selectedValueVector, CString strSqlQueryWhere);
	bool SelectObjectsByCondition(vector<TbSumsignalLabelDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere);

};