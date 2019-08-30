#pragma once
#include "PDDatabase.h"
#include "TbSignal.h"
class TbSignalDao :
	public PDDatabase
{
public:
	TbSignalDao();
	~TbSignalDao();
	TbSignalDao(const TbSignalDao & signal);

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

	bool SelectObjectsByCondition(vector<TbSignalDao> &selectedValueVector, CString strSqlQueryWhere = "");
	bool SelectObjectsByCondition(vector<TbSignalDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere = "");

	void SetTableFieldValues(TbSignal signal);
	void GetTableFieldValues(TbSignal &signal);
};

