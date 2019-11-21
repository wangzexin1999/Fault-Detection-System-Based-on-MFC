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
	PDAttribute m_saveTime;
	PDAttribute m_signalType;
	PDAttribute m_productId;
	PDAttribute m_signalStatus;
	PDAttribute m_dataUrl;
	PDAttribute m_projectId;
	PDAttribute m_testingDeviceId;
	PDAttribute m_collectionStatus;
	PDAttribute m_pointCount;
	PDAttribute m_collectionPara;

	
	bool SelectObjectsByCondition(vector<TbSignalDao> &selectedValueVector, CString strSqlQueryWhere = "");
	bool SelectObjectsByCondition(vector<TbSignalDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere = "");

	void SetTableFieldValues(TbSignal signal);
	void GetTableFieldValues(TbSignal &signal);
};

