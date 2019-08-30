#include "stdafx.h"
#include "SignalService.h"

SignalService::SignalService()
{

}

SignalService::~SignalService()
{

}
////��ѯ���еļ�¼���ź����ݡ�
bool SignalService::GetAllRecordedSignalBySearchCondition(TbSignal signal, CString startTime, CString endTime, vector<TbSignal> &signalVector){
	/////1.��װ��ѯ����
	CString strSqlWhere = "1=1";
	if (signal.GetProject().GetProjectId() != 0) strSqlWhere += " and project_id='" + CommonUtil::Int2CString(signal.GetProject().GetProjectId()) + "'";
	if (signal.GetProduct().GetProductId() != 0) strSqlWhere += " and product_id =" + CommonUtil::Int2CString(signal.GetProduct().GetProductId());
	if (startTime != "" ) strSqlWhere += " and end_time >='" + startTime + "'";
	if (endTime != "" ) strSqlWhere += " and start_time <='" + endTime + "'";

	/////2.��ѯ�źż�¼
	vector<TbRecordSignalDao> recordSignalDaoVector;
	bool isSuccess = m_recordSignalDao.SelectObjectsByCondition(recordSignalDaoVector, strSqlWhere);
	if (isSuccess){
	/////��¼�źŲ�ѯ�ɹ���������¼�źŵļ���
		for (auto signalDao : recordSignalDaoVector){
			TbSignal recordSignal;
			signalDao.GetTableFieldValues(recordSignal);
			///��ѯ���ݵĲ�Ʒ����Ϣ
			m_productDao.m_key->SetValue(recordSignal.GetProduct().GetProductId());
			isSuccess = m_productDao.SelectByKey();
			if (isSuccess){
			///��ѯ��Ʒ�ɹ�
				m_productDao.GetTableFieldValues(recordSignal.GetProduct());
			}
			signalVector.push_back(recordSignal);
		}
    }
	return isSuccess;
}