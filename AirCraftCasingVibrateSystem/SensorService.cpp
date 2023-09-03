#include "stdafx.h"
#include "SensorService.h"


SensorService::SensorService()
{
}


SensorService::~SensorService()
{
}
bool SensorService::FindAllSensor(std::vector<TbSensor> &sensorVec){
	TbSensorDao sensorDao;
	vector<TbSensorDao> selectedValueVector;
	bool isSuccess  =  sensorDao.SelectObjectsByCondition(selectedValueVector, "1=1");
	for (int i = 0; i < selectedValueVector.size(); i++){
		TbSensor sensor;
		selectedValueVector[i].GetTableFieldValues(sensor);
		sensorVec.push_back(sensor);
	}
	return isSuccess;
}

bool SensorService::GetById(int sensorId, TbSensor &sensor){
	TbSensorDao sensorDao;
	sensorDao.m_key->SetValue(sensorId);
	bool issuccess = sensorDao.SelectByKey();
	sensorDao.GetTableFieldValues(sensor);
	return issuccess;
}