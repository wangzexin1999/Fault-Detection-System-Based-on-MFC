#include "stdafx.h"
#include "SensorParaController.h"
#include "SensorParaService.h"
SensorParaController::SensorParaController(){}
SensorParaController::~SensorParaController(){}

////�ҵ�ָ����Ŀid�����д���������
Result SensorParaController::FindALLSensorParaByProjectId(TbProject &project){
	vector<TbSensorPara> vsensorPara;
	bool isSuccess = sensorParaService.GetALLSensorParaByProjectId(project.GetProjectId(), vsensorPara);
	if (isSuccess){
		project.SetSensorParaVector(vsensorPara);
		return Result(true,"���ش����������ɹ�");
	}
	return Result(false,"���ش���������ʧ��");
}