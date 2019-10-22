#include "stdafx.h"
#include "SensorParaController.h"
#include "SensorParaService.h"
SensorParaController::SensorParaController(){}
SensorParaController::~SensorParaController(){}

////找到指定项目id的所有传感器参数
Result SensorParaController::FindALLSensorParaByProjectId(TbProject &project){
	vector<TbSensor> vsensor;
	//bool isSuccess = sensorParaService.GetALLSensorParaByProjectId(project.GetProjectId(), vsensor);
	bool isSuccess = sensorParaService.GetALLSensorParaByTestingdeviceId(project.GetTestingDevice().GetId(), vsensor);
	if (isSuccess){
		project.SetSensorVector(vsensor);
		return Result(true,"加载传感器参数成功");
	}
	return Result(false,"加载传感器参数失败");
}