#pragma once
#include "PDDatabase.h"
#include "TbSignal.h"

class TbRecordSignalDao :
	public PDDatabase
{
public:
	TbRecordSignalDao();
	TbRecordSignalDao(const TbRecordSignalDao  & signal);
	~TbRecordSignalDao();

	PDAttribute m_signalId;
	PDAttribute m_startTime;
	PDAttribute m_endTime;
	PDAttribute m_signalType;
	PDAttribute m_productId;
	PDAttribute m_signalStatus;
	PDAttribute m_dataUrl;
	PDAttribute m_sensorId;
	PDAttribute m_projectId;
	PDAttribute m_testingDeviceId;


	bool SelectObjectsByCondition(vector<TbRecordSignalDao> &selectedValueVector, CString strSqlQueryWhere = "");
	bool SelectObjectsByCondition(vector<TbRecordSignalDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere = "");

	void SetTableFieldValues(TbSignal signal);
	void GetTableFieldValues(TbSignal &signal);
};

