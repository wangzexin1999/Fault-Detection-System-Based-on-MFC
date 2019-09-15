#include "stdafx.h"
#include "SensorParaController.h"
#include "SensorParaService.h"
SensorParaController::SensorParaController(){}
SensorParaController::~SensorParaController(){}

////�ҵ�ָ����Ŀid�����д���������
Result SensorParaController::FindALLSensorParaByProjectId(TbProject &project){
	vector<TbSensor> vsensor;
	bool isSuccess = sensorParaService.GetALLSensorParaByProjectId(project.GetProjectId(), vsensor);
	if (isSuccess){
		project.SetSensorVector(vsensor);
		return Result(true,"���ش����������ɹ�");
	}
	return Result(false,"���ش���������ʧ��");
}