#pragma once
#include "PDDatabase.h"
#include "TbSensor.h"
class TbSensorDao :
	public PDDatabase
{
public:
	TbSensorDao();
	TbSensorDao(const TbSensorDao & sensor);
	~TbSensorDao();

	PDAttribute m_sensorId;
	PDAttribute m_testingDeviceId;
	PDAttribute m_sensorType;
	PDAttribute m_sensorName;

	void SetTableFieldValues(TbSensor sensor);

	void GetTableFieldValues(TbSensor &sensor);

	bool SelectObjectsByCondition(vector<TbSensorDao> &selectedValueVector, CString strSqlQueryWhere = "");
	bool SelectObjectsByCondition(vector<TbSensorDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere = "");
};

