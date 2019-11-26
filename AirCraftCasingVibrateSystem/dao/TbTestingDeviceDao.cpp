#include "stdafx.h"
#include "TbTestingDeviceDao.h"


TbTestingDeviceDao::TbTestingDeviceDao()
{
	this->m_strTableName = "tb_testingdevice";
	m_key = &m_id;
	SetVectorAndField("id", "int", m_id);
	SetVectorAndField("testingdevice_ip", "CString", m_testingDeviceIp);
	SetVectorAndField("sample_frequency", "int", m_sampleFrequency);
	SetVectorAndField("analysis_frequency", "int", m_analysisFrequency);
	SetVectorAndField("collection_method", "int", m_collectionMethod);
	SetVectorAndField("collectionpoint", "int", m_collectionPoint);
	SetVectorAndField("collection_times", "int", m_collectionTimes);

	
}
TbTestingDeviceDao::TbTestingDeviceDao(const TbTestingDeviceDao &testingDevice){
	this->m_strTableName = "tb_testingdevice";
	m_key = &m_id;
	SetVectorAndField("id", "int", m_id);
	SetVectorAndField("testingdevice_ip", "CString", m_testingDeviceIp);
	SetVectorAndField("sample_frequency", "int", m_sampleFrequency);
	SetVectorAndField("analysis_frequency", "int", m_analysisFrequency);
	SetVectorAndField("collection_method", "int", m_collectionMethod);
	SetVectorAndField("collectionpoint", "int", m_collectionPoint);
	SetVectorAndField("collection_times", "int", m_collectionTimes);

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
	testingDevice.SetCollectionTimes(m_collectionTimes.GetInt());
	testingDevice.GetSampleFrequency().SetDictId(m_sampleFrequency.GetInt());
	testingDevice.GetCollectionMethod().SetDictId(m_collectionMethod.GetInt());
	testingDevice.GetCollectionPoint().SetDictId(m_collectionPoint.GetInt());
}
void TbTestingDeviceDao::SetTableFieldValues(TbTestingDevice testingDevice){
	m_id.SetValue(testingDevice.GetId());
	m_testingDeviceIp.SetValue(testingDevice.GetTestingDeviceIp());
	m_analysisFrequency.SetValue(testingDevice.GetAnalysisFrequency().GetDictId());
	m_collectionTimes.SetValue(testingDevice.GetCollectionTimes());
	m_sampleFrequency.SetValue(testingDevice.GetSampleFrequency().GetDictId());
	m_collectionMethod.SetValue(testingDevice.GetCollectionMethod().GetDictId());
	m_collectionPoint.SetValue(testingDevice.GetCollectionPoint().GetDictId());
}