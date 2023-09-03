#pragma once
#include "Result.h"
#include "TbSensor.h"
#include <vector>
#include "TbSensorDao.h"
class SensorService
{
public:
	SensorService();
	~SensorService();
	bool FindAllSensor(std::vector<TbSensor> & sensorVec);
	bool GetById(int sensorId, TbSensor &sensor);
};

