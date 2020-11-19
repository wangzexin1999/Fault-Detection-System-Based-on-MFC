#pragma once
#include "PDDatabase.h"
#include "TbSensor.h"
using namespace std;
class TbSensorDao :public PDDatabase
{
public:
	TbSensorDao();
	TbSensorDao(const TbSensorDao &sensor);
	~TbSensorDao();

public:
	PDAttribute m_sensorId;
	PDAttribute m_sensorName;
	PDAttribute m_sensorType;

	void SetTableFieldValues(TbSensor sensor);
	void GetTableFieldValues(TbSensor &sensor);

	bool SelectObjectsByCondition(vector<TbSensorDao> &selectedValueVector, CString strSqlQueryWhere);
	bool SelectObjectsByCondition(vector<TbSensorDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere );

};