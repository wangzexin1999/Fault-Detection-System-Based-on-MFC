#pragma once
#include "Result.h"
#include "TbSensor.h"
#include <vector>
#include "SensorService.h"

class SensorController
{
private:
	SensorService sensorService;
public:
	SensorController();
	~SensorController();

	Result FindAllSensor(std::vector<TbSensor> &sensorVec);

	Result GetById(int sensorId, TbSensor &sensor);
};

