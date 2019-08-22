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
	SetVectorAndField("sensor_id", "int", m_sensorId);
	SetVectorAndField("detecteddevice_id", "int", m_detectedDeviceId);
	SetVectorAndField("signal_status", "char", m_signalStatus);
	SetVectorAndField("data_url", "CString", m_dataUrl);
	SetVectorAndField("project_id", "int", m_projectId);
	SetVectorAndField("testingdevice_id", "int", m_testingDeviceId);
}
TbRecordSignalDao::TbRecordSignalDao(const TbRecordSignalDao  & signal){
	this->m_strTableName = "tb_recordsignal";
	m_key = &m_signalId;
	SetVectorAndField("signal_id", "int", m_signalId);
	SetVectorAndField("start_time", "CString", m_startTime);
	SetVectorAndField("end_time", "CString", m_endTime);
	SetVectorAndField("signal_type", "CString", m_signalType);
	SetVectorAndField("sensor_id", "int", m_sensorId);
	SetVectorAndField("detecteddevice_id", "int", m_detectedDeviceId);
	SetVectorAndField("signal_status", "char", m_signalStatus);
	SetVectorAndField("data_url", "CString", m_dataUrl);
	SetVectorAndField("project_id", "int", m_projectId);
	SetVectorAndField("testingdevice_id", "int", m_testingDeviceId);
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
void TbRecordSignalDao::GetTableFieldValues(TbSignal &signal){
	signal.SetSignalId(m_signalId.GetInt());
	signal.SetSignalStatus(m_signalStatus.GetInt());
	signal.SetDataUrl(m_dataUrl.m_strValue);
	signal.GetDetectedDevice().SetDetecteddeviceId(m_detectedDeviceId.GetInt());
	signal.SetStartTime(m_startTime.m_strValue);
	signal.SetEndTime(m_endTime.m_strValue);
	////清空传感器参数集合
	signal.GetSensor().SetSensorId(m_sensorId.GetInt());
	signal.SetSignalType(m_signalType.m_strValue);
	signal.SetProjectId(m_projectId.GetInt());
	signal.GetTestingDevice().SetTestingdeviceId(m_testingDeviceId.GetInt());
}