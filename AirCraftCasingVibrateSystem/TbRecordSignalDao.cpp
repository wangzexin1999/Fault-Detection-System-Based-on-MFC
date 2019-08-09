#include "stdafx.h"
#include "TbRecordSignalDao.h"
#include <vector>
#include "CommonUtil.h"
using namespace std;
TbRecordSignalDao::TbRecordSignalDao()
{
	this->m_strTableName = "tb_recordsignal";
	m_key = &m_signalId;
	SetVectorAndField("signal_id", "int", m_signalId);
	SetVectorAndField("start_time", "CString", m_startTime);
	SetVectorAndField("end_time", "CString", m_endTime);
	SetVectorAndField("signal_type", "CString", m_signalType);
	SetVectorAndField("sensorparas", "CString", m_sensorParas);
	SetVectorAndField("detecteddevice_id", "int", m_detectedDeviceId);
	SetVectorAndField("signal_status", "char", m_signalStatus);
	SetVectorAndField("data_url", "CString", m_dataUrl);
	SetVectorAndField("project_id", "int", m_projectId);
}
TbRecordSignalDao::TbRecordSignalDao(const TbRecordSignalDao  & signal){
	this->m_strTableName = "tb_recordsignal";
	m_key = &m_signalId;
	SetVectorAndField("signal_id", "int", m_signalId);
	SetVectorAndField("start_time", "CString", m_startTime);
	SetVectorAndField("end_time", "CString", m_endTime);
	SetVectorAndField("signal_type", "CString", m_signalType);
	SetVectorAndField("sensorparas", "CString", m_sensorParas);
	SetVectorAndField("detecteddevice_id", "int", m_detectedDeviceId);
	SetVectorAndField("signal_status", "char", m_signalStatus);
	SetVectorAndField("data_url", "CString", m_dataUrl);
	SetVectorAndField("project_id", "int", m_projectId);
	operator = (signal);
}

TbRecordSignalDao::~TbRecordSignalDao()
{

}
bool TbRecordSignalDao::SelectObjectsByCondition(vector<TbRecordSignalDao> &selectedValueVector, CString strSqlQueryWhere){
	return SelectObjectsByCondition(selectedValueVector, 0, 0, strSqlQueryWhere);
}

bool TbRecordSignalDao::SelectObjectsByCondition(vector<TbRecordSignalDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere){

	vector<CString> tmpDetectedObjecIDs;
	TbRecordSignalDao recordSignal;
	if (recordSignal.GetKeyIdList(tmpDetectedObjecIDs, strSqlQueryWhere, iStartNumber, iRecordCount))
	{
		for (int iStart = 0; iStart < tmpDetectedObjecIDs.size(); iStart++)
		{
			recordSignal.m_signalId.m_strValue = tmpDetectedObjecIDs[iStart];
			if (recordSignal.SelectByKey())
			{
				selectedValueVector.push_back(recordSignal);
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
void TbRecordSignalDao::GetTableFieldValues(TbSignal &recordSignal){
	recordSignal.SetSignalId(m_signalId.GetInt());
	recordSignal.SetSignalStatus(m_signalStatus.GetInt());
	recordSignal.SetDataUrl(m_dataUrl.m_strValue);
	recordSignal.GetDetectedDevice().SetDetecteddeviceId(m_detectedDeviceId.GetInt());
	recordSignal.SetStartTime(m_startTime.m_strValue);
	recordSignal.SetEndTime(m_endTime.m_strValue);
	////清空传感器参数集合
	recordSignal.GetSensorParaVector().clear();
	////创建传感器参数集合
	vector<int> sensorParaIdVector;
	CommonUtil::GetIntVectorFromSplitCString(m_sensorParas.m_strValue, ",", sensorParaIdVector);
	for (auto sensorParaId : sensorParaIdVector)
	{
		TbSensorPara sensorPara;
		sensorPara.SetSensorParaId(sensorParaId);
		recordSignal.GetSensorParaVector().push_back(sensorPara);
	}
	recordSignal.SetSignalType(m_signalType.m_strValue);
	recordSignal.SetProjectId(m_projectId.GetInt());

}