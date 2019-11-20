#include "stdafx.h"
#include "SensorParaService.h"
#include "CommonUtil.h"
#include "TbDictionaryDao.h"
SensorParaService::SensorParaService(){}
SensorParaService::~SensorParaService(){}

////������Ŀid�õ����еĴ���������
bool SensorParaService::GetALLSensorParaByTestingdeviceId(int testingdeviceId, std::vector<TbSensor> &vsensorPara){
	m_sensorDao.m_testingdeviceId.SetValue(testingdeviceId);
	vector<TbSensorDao> selectedValueVector;
	m_sensorDao.SelectObjectsByCondition(selectedValueVector, "testingdevice_id='" + CommonUtil::Int2CString(testingdeviceId) + "'");
	if (!selectedValueVector.empty()){
		////������������Ϊ��ʱ
		for (auto tbsenorParaDao : selectedValueVector){
			////���ݲ�ѯ���Ĵ�����������װTbSensor����
			TbSensor sensorPara;
			tbsenorParaDao.GetTableFieldValues(sensorPara);
			////���ݴ��������������idȥ���ֵ����Ӧ���ֵ�ֵ

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