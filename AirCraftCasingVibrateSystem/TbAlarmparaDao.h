#pragma once
#include "PDDatabase.h"
#include "TbAlarmpara.h"
class TbAlarmparaDao :
	public PDDatabase
{
public:
	TbAlarmparaDao();
	TbAlarmparaDao(const TbAlarmparaDao & alarmpara);
	~TbAlarmparaDao();

	PDAttribute m_alarmId;
	PDAttribute m_frequency;
	PDAttribute m_peakValue;
	PDAttribute m_grossValue;
	PDAttribute m_channelId;
	PDAttribute m_status;

	void SetTableFieldValues(TbAlarmpara alarmpara);

	void GetTableFieldValues(TbAlarmpara &alarmpara);

	bool SelectObjectsByCondition(vector<TbAlarmparaDao> &selectedValueVector, CString strSqlQueryWhere = "");
	bool SelectObjectsByCondition(vector<TbAlarmparaDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere = "");
};

