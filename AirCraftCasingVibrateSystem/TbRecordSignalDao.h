#pragma once
#include "PDDatabase.h"
#include "TbSignal.h"
#include <vector>
#include "CommonUtil.h"
using namespace std;
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
	PDAttribute m_sensorParas;
	PDAttribute m_detectedDeviceId;
	PDAttribute m_signalStatus;
	PDAttribute m_dataUrl;
	PDAttribute m_projectId;


	bool SelectObjectsByCondition(vector<TbRecordSignalDao> &selectedValueVector, CString strSqlQueryWhere = "");
	bool SelectObjectsByCondition(vector<TbRecordSignalDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere = "");

	void GetTableFieldValues(TbSignal &recordSignal);
};

