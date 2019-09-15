#include "stdafx.h"
#include "SensorParaService.h"
#include "CommonUtil.h"
#include "TbDictionaryDao.h"
SensorParaService::SensorParaService(){}
SensorParaService::~SensorParaService(){}

////根据项目id得到所有的传感器参数
bool SensorParaService::GetALLSensorParaByProjectId(int projectId, std::vector<TbSensor> &vsensorPara){
	m_sensorDao.m_projectId.SetValue(projectId);
	vector<TbSensorDao> selectedValueVector;
	m_sensorDao.SelectObjectsByCondition(selectedValueVector, "project_id='" + CommonUtil::Int2CString(projectId) + "'");
	if (!selectedValueVector.empty()){
		////传感器参数不为空时
		for (auto tbsenorParaDao : selectedValueVector){
			////根据查询到的传感器参数封装TbSensor对象
			TbSensor sensorPara;
			tbsenorParaDao.GetTableFieldValues(sensorPara);
			////根据传感器各类参数的id去查字典表对应的字典值

			TbDictionaryDao  dictionaryDao;
			dictionaryDao.SelectByObject(sensorPara.GetWindowType());
			dictionaryDao.SelectByObject(sensorPara.GetTriggerPolarity());
			dictionaryDao.SelectByObject(sensorPara.GetCoordinateSystem());
			dictionaryDao.SelectByObject(sensorPara.GetCoordinateSystemDirection());
			dictionaryDao.SelectByObject(sensorPara.GetEngineeringUnits());
			dictionaryDao.SelectByObject(sensorPara.GetIntegralType());
			dictionaryDao.SelectByObject(sensorPara.GetIntegralUnits());
			dictionaryDao.SelectByObject(sensorPara.GetInputMethod());
			dictionaryDao.SelectByObject(sensorPara.GetSensorStatus());
			dictionaryDao.SelectByObject(sensorPara.GetSensorStatus());
			dictionaryDao.SelectByObject(sensorPara.GetMessureType());

			////存入到传感器参数集合
			vsensorPara.push_back(sensorPara);
		}
	}
	return true;
}