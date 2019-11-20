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

	PDAttribute m_id;
	PDAttribute m_sensorId;
	PDAttribute m_sensorDesc;
	PDAttribute m_testingdeviceId;
	PDAttribute m_sersorStatus;
	PDAttribute m_messureType;
	PDAttribute m_windowType;
	PDAttribute m_triggerMagnitude;
	PDAttribute m_triggerPolarity;
	PDAttribute m_pointNum;
	PDAttribute m_coordinateSystem;
	PDAttribute m_coordinateSystemDirection;
	PDAttribute m_isReference;
	PDAttribute m_engineeringUnits;
	PDAttribute m_sensitivity;
	PDAttribute m_mileageRange;
	PDAttribute m_integralType;
	PDAttribute m_integralUnits;
	PDAttribute m_inputMethod;
	PDAttribute m_antiAliasingFiltering;
	PDAttribute m_maxFrequency;

	void SetTableFieldValues(TbSensor sensor);

	void GetTableFieldValues(TbSensor &sensor);

	bool SelectObjectsByCondition(vector<TbSensorDao> &selectedValueVector, CString strSqlQueryWhere = "");
	bool SelectObjectsByCondition(vector<TbSensorDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere = "");
};

