#include "stdafx.h"
#include "SignalService.h"

SignalService::SignalService()
{

}

SignalService::~SignalService()
{

}
////查询所有的记录的信号数据。
bool SignalService::GetAllRecordedSignalBySearchCondition(TbRecordSignal signal, CString startTime, CString endTime, vector<TbRecordSignal> &signalVector){
	/////1.封装查询条件
	CString strSqlWhere = "1=1";
	if (signal.GetProjectId() != 0) strSqlWhere += " and project_id='" + CommonUtil::Int2CString(signal.GetProjectId()) + "'";
	if (signal.GetProductId() != 0) strSqlWhere += " and product_id =" + CommonUtil::Int2CString(signal.GetProductId());
	if (startTime != "" ) strSqlWhere += " and end_time >='" + startTime + "'";
	if (endTime != "" ) strSqlWhere += " and start_time <='" + endTime + "'";

	/////2.查询信号记录
	vector<TbRecordSignalDao> recordSignalDaoVector;
	bool isSuccess = m_recordSignalDao.SelectObjectsByCondition(recordSignalDaoVector, strSqlWhere);
	if (isSuccess){
	/////记录信号查询成功，遍历记录信号的集合
		for (auto signalDao : recordSignalDaoVector){
			TbRecordSignal recordSignal;
			signalDao.GetTableFieldValues(recordSignal);
			signalVector.push_back(recordSignal);
		}
    }
	return isSuccess;
}