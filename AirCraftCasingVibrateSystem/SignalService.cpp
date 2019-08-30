#include "stdafx.h"
#include "SignalService.h"

SignalService::SignalService()
{

}

SignalService::~SignalService()
{

}
////查询所有的记录的信号数据。
bool SignalService::GetAllRecordedSignalBySearchCondition(TbSignal signal, CString startTime, CString endTime, vector<TbSignal> &signalVector){
	/////1.封装查询条件
	CString strSqlWhere = "1=1";
	if (signal.GetProject().GetProjectId() != 0) strSqlWhere += " and project_id='" + CommonUtil::Int2CString(signal.GetProject().GetProjectId()) + "'";
	if (signal.GetProduct().GetProductId() != 0) strSqlWhere += " and product_id =" + CommonUtil::Int2CString(signal.GetProduct().GetProductId());
	if (startTime != "" ) strSqlWhere += " and end_time >='" + startTime + "'";
	if (endTime != "" ) strSqlWhere += " and start_time <='" + endTime + "'";

	/////2.查询信号记录
	vector<TbRecordSignalDao> recordSignalDaoVector;
	bool isSuccess = m_recordSignalDao.SelectObjectsByCondition(recordSignalDaoVector, strSqlWhere);
	if (isSuccess){
	/////记录信号查询成功，遍历记录信号的集合
		for (auto signalDao : recordSignalDaoVector){
			TbSignal recordSignal;
			signalDao.GetTableFieldValues(recordSignal);
			///查询数据的产品的信息
			m_productDao.m_key->SetValue(recordSignal.GetProduct().GetProductId());
			isSuccess = m_productDao.SelectByKey();
			if (isSuccess){
			///查询产品成功
				m_productDao.GetTableFieldValues(recordSignal.GetProduct());
			}
			signalVector.push_back(recordSignal);
		}
    }
	return isSuccess;
}