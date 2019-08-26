#include "stdafx.h"
#include "SignalService.h"

SignalService::SignalService()
{

}

SignalService::~SignalService()
{

}
////��ѯ���еļ�¼���ź����ݡ�
bool SignalService::GetAllRecordedSignalBySearchCondition(int projectId, CString signalName, CString startTime, CString endTime, vector<TbSignal> &signalVector){
	/////1.��װ��ѯ����
	CString strSqlWhere = "project_id='" + CommonUtil::Int2CString(projectId) + "'";
	if (signalName != "") strSqlWhere += "and data_url like '%" + signalName + "%'";
	if (startTime != "") strSqlWhere += "and start_time >='" + startTime + "'";
	if (endTime != "") strSqlWhere += "or end_time <='" + endTime + "'";
	if (startTime != ""&&endTime != "") strSqlWhere += "or start_time <='" + startTime + "' and end_time >= '"+endTime+"'";

	/////2.��ѯ�źż�¼
	vector<TbRecordSignalDao> recordSignalDaoVector;
	bool isSuccess = m_recordSignalDao.SelectObjectsByCondition(recordSignalDaoVector, strSqlWhere);
	if (isSuccess){
	/////��¼�źŲ�ѯ�ɹ���������¼�źŵļ���
		for (auto signalDao : recordSignalDaoVector){
			TbSignal recordSignal;
			signalDao.GetTableFieldValues(recordSignal);
			///��ѯ���ݵĲ�Ʒ����Ϣ
			m_detectedDeviceDao.m_key->SetValue(recordSignal.GetDetectedDevice().GetDetecteddeviceId());
			isSuccess = m_detectedDeviceDao.SelectByKey();
			if (isSuccess){
			///��ѯ��Ʒ�ɹ�
				m_detectedDeviceDao.GetTableFieldValues(recordSignal.GetDetectedDevice());
			}
			signalVector.push_back(recordSignal);
		}
    }
	return isSuccess;
}