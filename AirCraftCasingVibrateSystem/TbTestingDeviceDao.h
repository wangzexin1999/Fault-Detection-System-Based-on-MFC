#pragma once
#include "PDDatabase.h"

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
public:
	PDAttribute m_testingDeviceId;
	PDAttribute m_testingDeviceIp;
	PDAttribute m_testingDeviceName;
	PDAttribute m_testingDeviceBornDate;
	PDAttribute m_testingDevicImportDate;

};

