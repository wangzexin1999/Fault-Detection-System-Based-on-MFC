#include "stdafx.h"
#include "SensorController.h"


SensorController::SensorController()
{
}


SensorController::~SensorController()
{
}

Result SensorController::FindAllSensor(std::vector<TbSensor> &sensorVec){
	bool isSuccess =  sensorService.FindAllSensor(sensorVec);
	if (!isSuccess) return Result(isSuccess,"传感器检索失败");
	return Result(isSuccess, "传感器检索成功");
}

Result SensorController::GetById(int sensorId, TbSensor &sensor){
	bool isSuccess = sensorService.GetById(sensorId, sensor);
	if (!isSuccess) return Result(isSuccess, "传感器检索失败");
	return Result(isSuccess, "传感器检索成功");
}
