#include "stdafx.h"
#include "TbCollectionparasDao.h"


TbCollectionparasDao::TbCollectionparasDao()
{
	this->m_strTableName = "tb_collectionparas";
	m_key = &m_id;
	SetVectorAndField("id", "int", m_id);
	SetVectorAndField("equipment_id", "CString", m_equipmentId);
	SetVectorAndField("sample_frequency", "double", m_sampleFrequency);
	SetVectorAndField("analysis_frequency", "double", m_analysisFrequency);
	SetVectorAndField("collection_method", "int", m_collectionMethod);
	SetVectorAndField("trigger_method", "int", m_triggerMethod);
	SetVectorAndField("collectionpoint", "int", m_collectionPoint);
	SetVectorAndField("sample_batch", "int", m_sampleBatch);

	SetVectorAndField("data_blocks", "int", m_dataBlocks);
	SetVectorAndField("delay_blocks", "int", m_delayBlocks);
	SetVectorAndField("trigger_times", "int", m_triggerTimes);
	
}
TbCollectionparasDao::TbCollectionparasDao(const TbCollectionparasDao &collectionparas){
	this->m_strTableName = "tb_collectionparas";
	m_key = &m_id;
	SetVectorAndField("id", "int", m_id);
	SetVectorAndField("equipment_id", "CString", m_equipmentId);
	SetVectorAndField("sample_frequency", "double", m_sampleFrequency);
	SetVectorAndField("analysis_frequency", "double", m_analysisFrequency);
	SetVectorAndField("collection_method", "int", m_collectionMethod);
	SetVectorAndField("trigger_method", "int", m_triggerMethod);
	SetVectorAndField("collectionpoint", "int", m_collectionPoint);
	SetVectorAndField("sample_batch", "int", m_sampleBatch);
	SetVectorAndField("data_blocks", "int", m_dataBlocks);
	SetVectorAndField("delay_blocks", "int", m_delayBlocks);
	SetVectorAndField("trigger_times", "int", m_triggerTimes);

	operator = (collectionparas);
}

TbCollectionparasDao::~TbCollectionparasDao()
{
}

bool TbCollectionparasDao::SelectObjectsByCondition(vector<TbCollectionparasDao> &selectedValueVector, CString strSqlQueryWhere){
	return SelectObjectsByCondition(selectedValueVector, 0, 0, strSqlQueryWhere);
}

bool TbCollectionparasDao::SelectObjectsByCondition(vector<TbCollectionparasDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere){
	vector<CString> tmpDetectedObjecIDs;
	TbCollectionparasDao collectionparas;
	if (collectionparas.GetKeyIdList(tmpDetectedObjecIDs, strSqlQueryWhere, iStartNumber, iRecordCount))
	{
		for (int iStart = 0; iStart < tmpDetectedObjecIDs.size(); iStart++)
		{
			collectionparas.m_id.m_strValue = tmpDetectedObjecIDs[iStart];
			if (collectionparas.SelectByKey())
			{
				selectedValueVector.push_back(collectionparas);
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
void TbCollectionparasDao::GetTableFieldValues(TbCollectionparas &collectionparas){
	collectionparas.SetId(m_id.GetInt());
	collectionparas.SetEquipmentId(m_equipmentId.m_strValue);
	collectionparas.SetAnalysisFrequency(m_analysisFrequency.GetFloatOrDouble());
	collectionparas.SetSampleBatch(m_sampleBatch.GetInt());
	collectionparas.SetSampleFrequency(m_sampleFrequency.GetFloatOrDouble());
	collectionparas.GetCollectionMethod().SetDictId(m_collectionMethod.GetInt());
	collectionparas.GetTriggerMethod().SetDictId(m_triggerMethod.GetInt());
	collectionparas.GetCollectionPoint().SetDictId(m_collectionPoint.GetInt());
	collectionparas.SetDataBlocks(m_dataBlocks.GetInt());
	collectionparas.SetDelayBlocks(m_delayBlocks.GetInt());
	collectionparas.SetTriggerTimes(m_triggerTimes.GetInt());
}
void TbCollectionparasDao::SetTableFieldValues(TbCollectionparas collectionparas){
	m_id.SetValue(collectionparas.GetId());
	m_equipmentId.SetValue(collectionparas.GetEquipmentId());
	m_analysisFrequency.SetValue(collectionparas.GetAnalysisFrequency());
	m_sampleBatch.SetValue(collectionparas.GetSampleBatch());
	m_sampleFrequency.SetValue(collectionparas.GetSampleFrequency());
	m_collectionMethod.SetValue(collectionparas.GetCollectionMethod().GetDictId());
	m_triggerMethod.SetValue(collectionparas.GetTriggerMethod().GetDictId());
	m_collectionPoint.SetValue(collectionparas.GetCollectionPoint().GetDictId());
	m_dataBlocks.SetValue(collectionparas.GetDataBlocks());
	m_delayBlocks.SetValue(collectionparas.GetDelayBlocks());
	m_triggerTimes.SetValue(collectionparas.GetTriggerTimes());
}