#include "stdafx.h"
#include "TbTestingDeviceParaDao.h"


TbTestingDeviceParaDao::TbTestingDeviceParaDao()
{
	this->m_strTableName = "tb_testingdevicepara";
	m_key = &m_testingDeviceParaId;
	SetVectorAndField("testingdevicepara_id", "int", m_testingDeviceParaId);
	SetVectorAndField("testingdevice_id", "int", m_testingdeviceId);
	SetVectorAndField("sampling_frequency", "int", m_samplingFrequency);
	SetVectorAndField("analysis_frequency", "int", m_analysisFrequency);
	SetVectorAndField("sampling_method", "int", m_samplingMethod);
	SetVectorAndField("trigger_method", "int", m_triggerMethod);
	SetVectorAndField("datablock_count", "int", m_datablockCount);
	SetVectorAndField("delayblock_count", "int", m_delayblockCount);
	SetVectorAndField("trigger_count", "int", m_triggerCount);
	SetVectorAndField("sampling_batchs", "int", m_samplingBatchs);

}

TbTestingDeviceParaDao::TbTestingDeviceParaDao(const TbTestingDeviceParaDao & testingPara){
	this->m_strTableName = "tb_TbTester";
	m_key = &m_testingDeviceParaId;
	SetVectorAndField("testingdevicepara_id", "int", m_testingDeviceParaId);
	SetVectorAndField("testingdevice_id", "int", m_testingdeviceId);
	SetVectorAndField("sampling_frequency", "int", m_samplingFrequency);
	SetVectorAndField("analysis_frequency", "int", m_analysisFrequency);
	SetVectorAndField("sampling_method", "int", m_samplingMethod);
	SetVectorAndField("trigger_method", "int", m_triggerMethod);
	SetVectorAndField("datablock_count", "int", m_datablockCount);
	SetVectorAndField("delayblock_count", "int", m_delayblockCount);
	SetVectorAndField("trigger_count", "int", m_triggerCount);
	SetVectorAndField("sampling_batchs", "int", m_samplingBatchs);
	operator = (testingPara);
}

TbTestingDeviceParaDao::~TbTestingDeviceParaDao()
{
}

void TbTestingDeviceParaDao::SetTableFieldValues(TbTestingDevicePara testingDevicePara){
	m_analysisFrequency.SetValue(testingDevicePara.GetAnalysisFrequency().GetDictId());
	m_datablockCount.SetValue(testingDevicePara.GetDatablockCount().GetDictId());
	m_delayblockCount.SetValue(testingDevicePara.GetDelayblockCount());
	m_samplingBatchs.SetValue(testingDevicePara.GetCollectionBatchs());
	m_samplingFrequency.SetValue(testingDevicePara.GetCollectionFrequency().GetDictId());
	m_samplingMethod.SetValue(testingDevicePara.GetCollectionMethod().GetDictId());
	m_testingdeviceId.SetValue(testingDevicePara.GetTestingdevice().GetTestingdeviceId());
	m_triggerCount.SetValue(testingDevicePara.GetTriggerCount());
	m_triggerMethod.SetValue(testingDevicePara.GetTriggerMethod().GetDictId());

}
void TbTestingDeviceParaDao::GetTableFieldValues(TbTestingDevicePara &testingDevicePara){
	testingDevicePara.SetAnalysisFrequency(m_analysisFrequency.GetInt());
	testingDevicePara.SetDatablockCount(m_datablockCount.GetInt());
	testingDevicePara.SetDelayblockCount(m_delayblockCount.GetInt());
	testingDevicePara.GetCollectionBatchs();

	testingDevicePara.SetCollectionBatchs(m_samplingBatchs.GetInt());
	testingDevicePara.GetCollectionFrequency().SetDictId(m_samplingFrequency.GetInt());
	testingDevicePara.GetCollectionMethod().SetDictId(m_samplingMethod.GetInt());
	TbTestingDevice g_testingDevice;
	g_testingDevice.SetTestingdeviceId(m_testingdeviceId.GetInt());
	testingDevicePara.SetTestingdevice(g_testingDevice);
	testingDevicePara.SetTestingdeviceparaId(m_testingDeviceParaId.GetInt());
	testingDevicePara.SetTriggerCount(m_triggerCount.GetInt());
	testingDevicePara.GetTriggerMethod().SetDictId(m_triggerMethod.GetInt());
}