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
	if (!isSuccess) return Result(isSuccess,"����������ʧ��");
	return Result(isSuccess, "�����������ɹ�");
}

Result SensorController::GetById(int sensorId, TbSensor &sensor){
	bool isSuccess = sensorService.GetById(sensorId, sensor);
	if (!isSuccess) return Result(isSuccess, "����������ʧ��");
	return Result(isSuccess, "�����������ɹ�");
}
