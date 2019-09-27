#include "stdafx.h"
#include "TbSignalDao.h"
#include <vector>
#include "CommonUtil.h"
using namespace std;
TbSignalDao::TbSignalDao()
{
	this->m_strTableName = "tb_signal";
	m_key = &m_signalId;
	SetVectorAndField("signal_id", "int", m_signalId);
	SetVectorAndField("start_time", "CString", m_startTime);
	SetVectorAndField("end_time", "CString", m_endTime);
	SetVectorAndField("signal_type", "CString", m_signalType);
	SetVectorAndField("sensor_id", "CString", m_sensorId);
	SetVectorAndField("product_id", "int", m_productId);
	SetVectorAndField("signal_status", "char", m_signalStatus);
	SetVectorAndField("data_url", "CString", m_dataUrl);
	SetVectorAndField("project_id", "int", m_projectId);
	SetVectorAndField("testingdevice_id", "int", m_testingDeviceId);
	SetVectorAndField("collectionstatus_para", "CString", m_collectionStatusPara);

}

TbSignalDao::TbSignalDao(const TbSignalDao & signal){

	this->m_strTableName = "tb_signal";
	m_key = &m_signalId;
	SetVectorAndField("signal_id", "int", m_signalId);
	SetVectorAndField("start_time", "CString", m_startTime);
	SetVectorAndField("end_time", "CString", m_endTime);
	SetVectorAndField("signal_type", "CString", m_signalType);
	SetVectorAndField("sensor_id", "CString", m_sensorId);
	SetVectorAndField("product_id", "int", m_productId);
	SetVectorAndField("signal_status", "char", m_signalStatus);
	SetVectorAndField("data_url", "CString", m_dataUrl);
	SetVectorAndField("project_id", "int", m_projectId);
	SetVectorAndField("testingdevice_id", "int", m_testingDeviceId);
	SetVectorAndField("collectionstatus_para", "CString", m_collectionStatusPara);
	operator = (signal);
}

TbSignalDao::~TbSignalDao()
{

}

bool TbSignalDao::SelectObjectsByCondition(vector<TbSignalDao> &selectedValueVector, CString strSqlQueryWhere){
	return SelectObjectsByCondition(selectedValueVector, 0, 0, strSqlQueryWhere);
}

bool TbSignalDao::SelectObjectsByCondition(vector<TbSignalDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere){

	vector<CString> tmpDetectedObjecIDs;
	TbSignalDao signal;
	if (signal.GetKeyIdList(tmpDetectedObjecIDs, strSqlQueryWhere, iStartNumber, iRecordCount))
	{
		for (int iStart = 0; iStart < tmpDetectedObjecIDs.size(); iStart++)
		{
			signal.m_signalId.m_strValue = tmpDetectedObjecIDs[iStart];
			if (signal.SelectByKey())
			{
				selectedValueVector.push_back(signal);
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
void TbSignalDao::GetTableFieldValues(TbSignal &signal){
	signal.SetSignalId(m_signalId.GetInt());
	signal.SetSignalStatus(m_signalStatus.GetInt());
	signal.SetDataUrl(m_dataUrl.m_strValue);
	signal.SetProductId(m_productId.GetInt());
	signal.SetStartTime(m_startTime.m_strValue);
	signal.SetEndTime(m_endTime.m_strValue);
	signal.SetSignalType(m_signalType.m_strValue);
	signal.SetProjectId(m_projectId.GetInt());
	signal.SetTestingDeviceId(m_testingDeviceId.GetInt());
	signal.SetSensorId(m_sensorId.m_strValue);
	signal.SetCollectionStatusPara(m_collectionStatusPara.m_strValue);
}

void TbSignalDao::SetTableFieldValues(TbSignal signal){
	m_projectId.SetValue(signal.GetProjectId());
	m_sensorId.SetValue(signal.GetSensorId());
	m_signalId.SetValue(signal.GetSignalId());
	m_signalStatus.SetValue(signal.GetSignalStatus());
	m_signalType.SetValue(signal.GetSignalType());
	m_startTime.SetValue(signal.GetStartTime());
	m_endTime.SetValue(signal.GetEndTime());
	m_dataUrl.SetValue(signal.GetDataUrl());
	m_productId.SetValue(signal.GetProductId());
	m_testingDeviceId.SetValue(signal.GetTestingDeviceId());
	m_collectionStatusPara.SetValue(signal.GetCollectionStatusPara());
}
