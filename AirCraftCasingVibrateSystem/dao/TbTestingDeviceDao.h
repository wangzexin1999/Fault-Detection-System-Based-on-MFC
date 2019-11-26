#pragma once
#include "PDDatabase.h"
#include "TbTestingDevice.h"

class TbTestingDeviceDao :
	public PDDatabase
{
public:
	TbTestingDeviceDao();
	TbTestingDeviceDao(const TbTestingDeviceDao &testingDevice);
	~TbTestingDeviceDao();

	bool SelectObjectsByCondition(vector<TbTestingDeviceDao> &selectedValueVector, CString strSqlQueryWhere = "");
	bool SelectObjectsByCondition(vector<TbTestingDeviceDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere = "");
	void GetTableFieldValues(TbTestingDevice &testingDevice);
	void SetTableFieldValues(TbTestingDevice testingDevice);
public:
	PDAttribute m_id;
	PDAttribute m_testingDeviceIp;
	PDAttribute m_sampleFrequency;
	PDAttribute m_analysisFrequency;
	PDAttribute m_collectionMethod;
	PDAttribute m_collectionPoint;
	PDAttribute m_collectionTimes;

};

