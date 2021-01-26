#pragma once
#include "PDDatabase.h"
#include "TbRecordSignal.h"

class TbRecordSignalDao:
	public PDDatabase
{
public:
	TbRecordSignalDao();
	TbRecordSignalDao(const TbRecordSignalDao  & signal);
	~TbRecordSignalDao();

	PDAttribute m_id;
	PDAttribute m_signalId;
	PDAttribute m_startTime;
	PDAttribute m_endTime;
	PDAttribute m_startPos;
	PDAttribute m_endPos;
	PDAttribute m_signalType;
	PDAttribute m_productId;
	PDAttribute m_SignalLabel;
	PDAttribute m_projectId;
	PDAttribute m_collectionparasId;
	PDAttribute m_collectionStatus;
	PDAttribute m_channelInfo;

	bool SelectObjectsByCondition(vector<TbRecordSignalDao> &selectedValueVector, CString strSqlQueryWhere = "");
	bool SelectObjectsByCondition(vector<TbRecordSignalDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere = "");

	void SetTableFieldValues(TbRecordSignal signal);
	void GetTableFieldValues(TbRecordSignal &signal);
};

