#include "stdafx.h"
#include "RecordSignalService.h"
#include "CommonUtil.h"

RecordSignalService::RecordSignalService()
{
}


RecordSignalService::~RecordSignalService()
{
}

bool RecordSignalService::AddRecordSignal(TbRecordSignal recordSignal){
	m_recordSignalDao.SetTableFieldValues(recordSignal);
	return	m_recordSignalDao.Insert();
}
bool RecordSignalService::FindAllRecordSignalBySearchCondition(TbRecordSignal searchEntity,vector<TbRecordSignal> &signalVector){
	CString strSqlWhere = "1 = 1 ";
	if (searchEntity.GetProduct().GetProductId() != 0)	strSqlWhere += " and product_id ='" + CommonUtil::Int2CString(searchEntity.GetProduct().GetProductId()) + "'";
	if (searchEntity.GetProject().GetProjectId() != 0)   strSqlWhere += " and project_id ='" + CommonUtil::Int2CString(searchEntity.GetProject().GetProjectId()) + "'";
	if (searchEntity.GetTestingDevice().GetId() != 0)  strSqlWhere += " and testingdevice_id ='" + CommonUtil::Int2CString(searchEntity.GetTestingDevice().GetId()) + "'";
	if (searchEntity.GetCollectionStatus() != ""){
		///拆开封装好的关键字字符串
		vector<CString> keyWords = CommonUtil::GetCStringVectorFromSplitCString(searchEntity.GetCollectionStatus(), ",");
		for (auto keyWord :keyWords){
			strSqlWhere += "and collectionstatus like'%" + keyWord + "%'";
		}
	}
	if (searchEntity.GetStartTime() != "" && searchEntity.GetEndTime() == "") strSqlWhere += " and end_time >='" + searchEntity.GetStartTime() + "'";
	if (searchEntity.GetEndTime() != "" && searchEntity.GetStartTime() == "") strSqlWhere += " and start_time <='" + searchEntity.GetEndTime() + "'";
	vector<TbRecordSignalDao> recordSignalDaoVector;
	bool isSuccess = m_recordSignalDao.SelectObjectsByCondition(recordSignalDaoVector, strSqlWhere);
	if (isSuccess==true){
		for (auto signalDao : recordSignalDaoVector){
			TbRecordSignal recordSignal;
			signalDao.GetTableFieldValues(recordSignal);
			///查询数据的产品的信息
			m_productDao.m_key->SetValue(recordSignal.GetProduct().GetProductId());
			isSuccess = m_productDao.SelectByKey();
			if (!isSuccess){ AfxMessageBox("产品加载失败"); }
			else m_productDao.GetTableFieldValues(recordSignal.GetProduct());
			///查询采集设备信息
			m_testingDeviceDao.m_key->SetValue(recordSignal.GetTestingDevice().GetId());
			isSuccess = m_testingDeviceDao.SelectByKey();
			if (!isSuccess){ AfxMessageBox("采集设备加载失败"); }
			else m_testingDeviceDao.GetTableFieldValues(recordSignal.GetTestingDevice());
			///查询项目信息
			m_projectDao.m_key->SetValue(recordSignal.GetProject().GetProjectId());
			isSuccess = m_projectDao.SelectByKey();
			m_projectDao.GetTableFieldValues(recordSignal.GetProject());
			if (!isSuccess){ AfxMessageBox("项目加载失败"); }
			signalVector.push_back(recordSignal);
		}
	}

	return true;
}