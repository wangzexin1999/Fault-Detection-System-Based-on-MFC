#include "stdafx.h"
#include "SignalService.h"

SignalService::SignalService()
{

}

SignalService::~SignalService()
{

}

bool  SignalService::GetAllSignalBySearchCondition(TbSignal searchEntity, vector<TbSignal> &signalVector){
	CString strSqlWhere = "1 = 1 ";
	if (searchEntity.GetProductId() != 0)	strSqlWhere += " and product_id ='" + CommonUtil::Int2CString(searchEntity.GetProductId()) + "'";
	if (searchEntity.GetProjectId() != 0)   strSqlWhere += " and project_id ='" + CommonUtil::Int2CString(searchEntity.GetProjectId()) + "'";
	if (searchEntity.GetTestingDeviceId() != 0)  strSqlWhere += " and testingdevice_id ='" + CommonUtil::Int2CString(searchEntity.GetTestingDeviceId()) + "'";
	if (searchEntity.GetStartTime() != "" && searchEntity.GetEndTime() == "") strSqlWhere += " and end_time >='" + searchEntity.GetStartTime() + "'";
	if (searchEntity.GetEndTime() != "" && searchEntity.GetStartTime() == "") strSqlWhere += " and start_time <='" + searchEntity.GetEndTime() + "'";
	if (searchEntity.GetSensorId() != "") strSqlWhere += " and sensor_id ='" + searchEntity.GetSensorId()+"'";
	if (searchEntity.GetCollectionStatus() != "") strSqlWhere += " and collectionstatus ='" + searchEntity.GetCollectionStatus()+"'";
	
	vector<TbSignalDao> signalDaoVec;
	bool isSuccess = m_signalDao.SelectObjectsByCondition(signalDaoVec,strSqlWhere);
	if (isSuccess){
		for (auto signalDao:signalDaoVec){
			TbSignal signal;
			signalDao.GetTableFieldValues(signal); 
			signalVector.push_back(signal); 
		}
	}
	return isSuccess;
}
