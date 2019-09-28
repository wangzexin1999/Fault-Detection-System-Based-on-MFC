#include "stdafx.h"
#include "SignalService.h"

SignalService::SignalService()
{

}

SignalService::~SignalService()
{

}
////��ѯ���еļ�¼���ź����ݡ�
bool SignalService::GetAllRecordedSignalBySearchCondition(TbRecordSignal signal, CString startTime, CString endTime, vector<TbRecordSignal> &signalVector){
	/////1.��װ��ѯ����
	CString strSqlWhere = "1=1";
	if (signal.GetProjectId() != 0) strSqlWhere += " and project_id='" + CommonUtil::Int2CString(signal.GetProjectId()) + "'";
	if (signal.GetProductId() != 0) strSqlWhere += " and product_id =" + CommonUtil::Int2CString(signal.GetProductId());
	if (startTime != "" ) strSqlWhere += " and end_time >='" + startTime + "'";
	if (endTime != "" ) strSqlWhere += " and start_time <='" + endTime + "'";

	/////2.��ѯ�źż�¼
	vector<TbRecordSignalDao> recordSignalDaoVector;
	bool isSuccess = m_recordSignalDao.SelectObjectsByCondition(recordSignalDaoVector, strSqlWhere);
	if (isSuccess){
	/////��¼�źŲ�ѯ�ɹ���������¼�źŵļ���
		for (auto signalDao : recordSignalDaoVector){
			TbRecordSignal recordSignal;
			signalDao.GetTableFieldValues(recordSignal);
			signalVector.push_back(recordSignal);
		}
    }
	return isSuccess;
}