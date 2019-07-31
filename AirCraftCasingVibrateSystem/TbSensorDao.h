#pragma once
#include "PDDatabase.h"
class TbSensorDao :
	public PDDatabase
{
public:
	TbSensorDao();
	TbSensorDao(const TbSensorDao & sensor);
	~TbSensorDao();

	PDAttribute m_sensorId;
	PDAttribute m_testingDeviceId;
	PDAttribute m_sersorType;
	PDAttribute m_sersorName;


};

