#pragma once
#include "PDDatabase.h"
#include "TbSignalTestRecord.h"
using namespace std;
class TbSignalTestRecordDao :public PDDatabase
{
public:
	TbSignalTestRecordDao();
	TbSignalTestRecordDao(const TbSignalTestRecordDao &signalTestRecord);
	~TbSignalTestRecordDao();

public:
	PDAttribute m_recordId;
	PDAttribute m_recordTime;
	PDAttribute m_frequency;
	PDAttribute m_peakValue;
	PDAttribute m_grossValue;
	PDAttribute m_signalId;


	void SetTableFieldValues(TbSignalTestRecord signalTestRecord);
	void GetTableFieldValues(TbSignalTestRecord &signalTestRecord);

	bool SelectObjectsByCondition(vector<TbSignalTestRecordDao> &selectedValueVector, CString strSqlQueryWhere);
	bool SelectObjectsByCondition(vector<TbSignalTestRecordDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere);

};