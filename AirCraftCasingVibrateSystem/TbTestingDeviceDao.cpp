#include "stdafx.h"
#include "TbTestingDeviceDao.h"


TbTestingDeviceDao::TbTestingDeviceDao()
{
	this->m_strTableName = "tb_testingdevice";
	m_key = &m_id;
	SetVectorAndField("id", "int", m_id);
	SetVectorAndField("testingdevice_ip", "CString", m_testingDeviceIp);
	SetVectorAndField("collection_frequency", "int", m_collectionFrequency);
	SetVectorAndField("analysis_frequency", "int", m_analysisFrequency);
	SetVectorAndField("collection_method", "int", m_collectionMethod);
	SetVectorAndField("trigger_method", "int", m_triggerMethod);
	SetVectorAndField("datablock_count", "int", m_datablockCount);
	SetVectorAndField("delayblock_count", "int", m_delayblockCount);
	SetVectorAndField("trigger_count", "int", m_triggerCount);
	SetVectorAndField("collection_batchs", "int", m_collectionBatchs);
	
}
TbTestingDeviceDao::TbTestingDeviceDao(const TbTestingDeviceDao &testingDevice){
	this->m_strTableName = "tb_testingdevice";
	m_key = &m_id;
	SetVectorAndField("id", "int", m_id);
	SetVectorAndField("testingdevice_ip", "CString", m_testingDeviceIp);
	SetVectorAndField("collection_frequency", "int", m_collectionFrequency);
	SetVectorAndField("analysis_frequency", "int", m_analysisFrequency);
	SetVectorAndField("collection_method", "int", m_collectionMethod);
	SetVectorAndField("trigger_method", "int", m_triggerMethod);
	SetVectorAndField("datablock_count", "int", m_datablockCount);
	SetVectorAndField("delayblock_count", "int", m_delayblockCount);
	SetVectorAndField("trigger_count", "int", m_triggerCount);
	SetVectorAndField("collection_batchs", "int", m_collectionBatchs);
	operator = (testingDevice);
}

TbTestingDeviceDao::~TbTestingDeviceDao()
{
}

bool TbTestingDeviceDao::SelectObjectsByCondition(vector<TbTestingDeviceDao> &selectedValueVector, CString strSqlQueryWhere){
	return SelectObjectsByCondition(selectedValueVector, 0, 0, strSqlQueryWhere);
}

bool TbTestingDeviceDao::SelectObjectsByCondition(vector<TbTestingDeviceDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere){
	vector<CString> tmpDetectedObjecIDs;
	TbTestingDeviceDao testingDevice;
	if (testingDevice.GetKeyIdList(tmpDetectedObjecIDs, strSqlQueryWhere, iStartNumber, iRecordCount))
	{
		for (int iStart = 0; iStart < tmpDetectedObjecIDs.size(); iStart++)
		{
			testingDevice.m_id.m_strValue = tmpDetectedObjecIDs[iStart];
			if (testingDevice.SelectByKey())
			{
				selectedValueVector.push_back(testingDevice);
			}
			else
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}
void TbTestingDeviceDao::GetTableFieldValues(TbTestingDevice &testingDevice){
	testingDevice.SetId(m_id.GetInt());
	testingDevice.SetTestingDeviceIp(m_testingDeviceIp.m_strValue);
	testingDevice.SetAnalysisFrequency(m_analysisFrequency.GetInt());
	testingDevice.SetDatablockCount(m_datablockCount.GetInt());
	testingDevice.SetDelayblockCount(m_delayblockCount.GetInt());
	testingDevice.SetCollectionBatchs(m_collectionBatchs.GetInt());
	testingDevice.GetCollectionFrequency().SetDictId(m_collectionFrequency.GetInt());
	testingDevice.GetCollectionMethod().SetDictId(m_collectionMethod.GetInt());
	testingDevice.SetTriggerCount(m_triggerCount.GetInt());
	testingDevice.GetTriggerMethod().SetDictId(m_triggerMethod.GetInt());
}
void TbTestingDeviceDao::SetTableFieldValues(TbTestingDevice testingDevice){
	m_id.SetValue(testingDevice.GetId());
	m_testingDeviceIp.SetValue(testingDevice.GetTestingDeviceIp());
	m_analysisFrequency.SetValue(testingDevice.GetAnalysisFrequency().GetDictId());
	m_datablockCount.SetValue(testingDevice.GetDatablockCount().GetDictId());
	m_delayblockCount.SetValue(testingDevice.GetDelayblockCount());
	m_collectionBatchs.SetValue(testingDevice.GetCollectionBatchs());
	m_collectionFrequency.SetValue(testingDevice.GetCollectionFrequency().GetDictId());
	m_collectionMethod.SetValue(testingDevice.GetCollectionMethod().GetDictId());
	m_triggerCount.SetValue(testingDevice.GetTriggerCount());
	m_triggerMethod.SetValue(testingDevice.GetTriggerMethod().GetDictId());
}