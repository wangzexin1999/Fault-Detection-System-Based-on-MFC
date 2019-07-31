#pragma once
#include "PDDatabase.h"
class TbDetectedDeviceDao :
	public PDDatabase
{
public:

	TbDetectedDeviceDao();
	TbDetectedDeviceDao(const TbDetectedDeviceDao & detectedDevice);

	~TbDetectedDeviceDao();

	PDAttribute m_detecteddeviceId;
	PDAttribute m_detecteddeviceName;
	PDAttribute m_detecteddeviceType;
	

	void GetTableFieldValues(TbDetectedDevice &detectedDevice);
	bool SelectObjectsByCondition(vector<TbDetectedDeviceDao> &selectedValueVector, CString strSqlQueryWhere = "");
	bool SelectObjectsByCondition(vector<TbDetectedDeviceDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere = "");
};

