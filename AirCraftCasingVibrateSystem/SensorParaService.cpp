#include "stdafx.h"
#include "SensorParaService.h"
#include "CommonUtil.h"
#include "TbDictionaryDao.h"
SensorParaService::SensorParaService(){}
SensorParaService::~SensorParaService(){}

////������Ŀid�õ����еĴ���������
bool SensorParaService::GetALLSensorParaByProjectId(int projectId,std::vector<TbSensorPara> &vsensorPara){
	m_sensorParaDao.m_projectId.SetValue(projectId);
	vector<TbSensorParaDao> selectedValueVector;
	m_sensorParaDao.SelectObjectsByCondition(selectedValueVector, "project_id='" + CommonUtil::Int2CString(projectId) + "'");
	if (!selectedValueVector.empty()){
		////������������Ϊ��ʱ
		for (auto tbsenorParaDao : selectedValueVector){
			////���ݲ�ѯ���Ĵ�����������װTbSensorPara����
			TbSensorPara sensorPara;
			tbsenorParaDao.GetTableFieldValues(sensorPara);
			////���ݴ��������������idȥ���ֵ���Ӧ���ֵ�ֵ

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

			////���뵽��������������
			vsensorPara.push_back(sensorPara);
		}
	}
	return true;
}