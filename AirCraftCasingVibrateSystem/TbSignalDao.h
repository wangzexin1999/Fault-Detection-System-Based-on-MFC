#pragma once
#include "PDDatabase.h"
#include "TbSignal.h"
using namespace std;
class TbSignalDao :public PDDatabase
{
public:
	TbSignalDao();
	TbSignalDao(const TbSignalDao &signal);
	~TbSignalDao();

public:

	PDAttribute m_signalId;
	PDAttribute m_channelId;
	PDAttribute m_sumsignalId;
	PDAttribute m_SignalLabel;
	PDAttribute m_dataUrl;
	//PDAttribute m_sumSignalId;

	void SetTableFieldValues(TbSignal signal);
	void GetTableFieldValues(TbSignal &signal);

	bool SelectObjectsByCondition(vector<TbSignalDao> &selectedValueVector, CString strSqlQueryWhere);
	bool SelectObjectsByCondition(vector<TbSignalDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere );

};