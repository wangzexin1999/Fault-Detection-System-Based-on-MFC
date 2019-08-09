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
	SetVectorAndField("sensorparas", "CString", m_sensorParas);
	SetVectorAndField("detecteddevice_id", "int", m_detectedDeviceId);
	SetVectorAndField("signal_status", "char", m_signalStatus);
	SetVectorAndField("data_url", "CString", m_dataUrl);
	SetVectorAndField("project_id", "int", m_projectId);
}

TbSignalDao::TbSignalDao(const TbSignalDao & signal){

	this->m_strTableName = "tb_signal";
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
	signal.GetDetectedDevice().SetDetecteddeviceId(m_detectedDeviceId.GetInt());
	signal.SetStartTime(m_startTime.m_strValue);
	signal.SetEndTime(m_endTime.m_strValue);
	////清空传感器参数集合
	signal.GetSensorParaVector().clear();
	////创建传感器参数集合
	vector<int> sensorParaIdVector;
	CommonUtil::GetIntVectorFromSplitCString(m_sensorParas.m_strValue, ",", sensorParaIdVector);
	for (auto sensorParaId : sensorParaIdVector)
	{
		TbSensorPara sensorPara;
		sensorPara.SetSensorParaId(sensorParaId);
		signal.GetSensorParaVector().push_back(sensorPara);
	}
	signal.SetSignalType(m_signalType.m_strValue);
	signal.SetProjectId(m_projectId.GetInt());
}

void TbSignalDao::SetTableFieldValues(TbSignal signal){
	m_projectId.SetValue(signal.GetProjectId());
	vector<TbSensorPara> sensorPara = signal.GetSensorParaVector();

	////封装参数集合
	CString strSensorParas = "";
	int size = sensorPara.size();
	for (int i = 0; i < size - 1; i++){
		strSensorParas += CommonUtil::Int2CString(sensorPara[i].GetSensorParaId())+",";
	}
	if (sensorPara.size()>0) strSensorParas += CommonUtil::Int2CString(sensorPara[sensorPara.size() - 1].GetSensorParaId());
	
	m_sensorParas.m_strValue = strSensorParas; 
	m_signalId.SetValue(signal.GetSignalId());
	if (signal.GetSignalStatus() >= 0){
		m_signalStatus.SetValue(signal.GetSignalStatus());
	}
	m_signalType.SetValue(signal.GetSignalType());
	m_startTime.SetValue(signal.GetStartTime());
	m_endTime.SetValue(signal.GetEndTime());
	m_dataUrl.SetValue(signal.GetDataUrl());
	m_detectedDeviceId.SetValue(signal.GetDetectedDevice().GetDetecteddeviceId());
}
