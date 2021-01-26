#pragma once
#include "PDDatabase.h"
#include "TbSumsignal.h"
class TbSumsignalDao :
	public PDDatabase
{
public:
	TbSumsignalDao();
	~TbSumsignalDao();
	TbSumsignalDao(const TbSumsignalDao & sumsignal);

	PDAttribute m_sumsignalId;
	PDAttribute m_startTime;
	PDAttribute m_endTime;
	PDAttribute m_sumsignalLabel;
	PDAttribute m_productId;
	PDAttribute m_sumSignalLabel;
	PDAttribute m_dataUrl;
	
	bool SelectObjectsByCondition(vector<TbSumsignalDao> &selectedValueVector, CString strSqlQueryWhere = "");
	bool SelectObjectsByCondition(vector<TbSumsignalDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere = "");

	void SetTableFieldValues(TbSumsignal sumsignal);
	void GetTableFieldValues(TbSumsignal &sumsignal);
};

