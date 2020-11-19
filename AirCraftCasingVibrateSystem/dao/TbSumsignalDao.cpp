#include "stdafx.h"
#include "TbSumsignalDao.h"
#include <vector>
#include "CommonUtil.h"
using namespace std;
TbSumsignalDao::TbSumsignalDao()
{
	this->m_strTableName = "tb_sumsignal";
	m_key = &m_sumsignalId;
	SetVectorAndField("signal_id", "CString", m_sumsignalId);
	SetVectorAndField("start_time", "CString", m_startTime);
	SetVectorAndField("end_time", "CString",m_endTime);
	SetVectorAndField("signal_type", "CString", m_sumsignalType);
	SetVectorAndField("product_id", "int", m_productId);
	SetVectorAndField("signal_status", "char", m_sumsignalStatus);
	SetVectorAndField("data_url", "CString", m_dataUrl);
	SetVectorAndField("project_id", "int", m_projectId);
	SetVectorAndField("collectionparas_id", "int", m_collectionparasId);
	SetVectorAndField("collectionstatus", "CString", m_collectionStatus);
	SetVectorAndField("channelinfo", "CString", m_channelInfo);
}

TbSumsignalDao::TbSumsignalDao(const TbSumsignalDao & sumsignal){

	this->m_strTableName = "tb_sumsignal";
	m_key = &m_sumsignalId;
	SetVectorAndField("signal_id", "CString", m_sumsignalId);
	SetVectorAndField("start_time", "CString", m_startTime);
	SetVectorAndField("end_time", "CString", m_endTime);
	SetVectorAndField("signal_type", "CString", m_sumsignalType);
	SetVectorAndField("product_id", "int", m_productId);
	SetVectorAndField("signal_status", "char", m_sumsignalStatus);
	SetVectorAndField("data_url", "CString", m_dataUrl);
	SetVectorAndField("project_id", "int", m_projectId);
	SetVectorAndField("collectionparas_id", "int", m_collectionparasId);
	SetVectorAndField("collectionstatus", "CString", m_collectionStatus);
	SetVectorAndField("channelinfo", "CString", m_channelInfo);
	operator = (sumsignal);
}

TbSumsignalDao::~TbSumsignalDao()
{

}

bool TbSumsignalDao::SelectObjectsByCondition(vector<TbSumsignalDao> &selectedValueVector, CString strSqlQueryWhere){
	return SelectObjectsByCondition(selectedValueVector, 0, 0, strSqlQueryWhere);
}

bool TbSumsignalDao::SelectObjectsByCondition(vector<TbSumsignalDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere){

	vector<CString> tmpDetectedObjecIDs;
	TbSumsignalDao sumsignal;
	if (sumsignal.GetKeyIdList(tmpDetectedObjecIDs, strSqlQueryWhere, iStartNumber, iRecordCount))
	{
		for (int iStart = 0; iStart < tmpDetectedObjecIDs.size(); iStart++)
		{
			sumsignal.m_sumsignalId.m_strValue = tmpDetectedObjecIDs[iStart];
			if (sumsignal.SelectByKey())
			{
				selectedValueVector.push_back(sumsignal);
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
void TbSumsignalDao::GetTableFieldValues(TbSumsignal &sumsignal){
	sumsignal.SetSumsignalId(m_sumsignalId.m_strValue);
	sumsignal.SetSumsignalStatus(m_sumsignalStatus.GetInt());
	sumsignal.SetDataUrl(m_dataUrl.m_strValue);
	sumsignal.SetProductId(m_productId.GetInt());
	sumsignal.SetStartTime(m_startTime.m_strValue);
	sumsignal.SetEndTime(m_endTime.m_strValue);
	sumsignal.SetSumsignalType(m_sumsignalType.m_strValue);
	sumsignal.SetProjectId(m_projectId.GetInt());
	sumsignal.SetCollectionparasId(m_collectionparasId.GetInt());
	sumsignal.SetCollectionStatus(m_collectionStatus.m_strValue);
	sumsignal.SetChannelInfo(m_channelInfo.m_strValue);
}

void TbSumsignalDao::SetTableFieldValues(TbSumsignal sumsignal){
	m_projectId.SetValue(sumsignal.GetProjectId());
	m_sumsignalId.SetValue(sumsignal.GetSumsignalId());
	m_sumsignalStatus.SetValue(sumsignal.GetSumsignalStatus());
	m_sumsignalType.SetValue(sumsignal.GetSumsignalType());
	m_startTime.SetValue(sumsignal.GetStartTime());
	m_endTime.SetValue(sumsignal.GetEndTime());
	m_dataUrl.SetValue(sumsignal.GetDataUrl());
	m_productId.SetValue(sumsignal.GetProductId());
	m_collectionparasId.SetValue(sumsignal.GetCollectionparasId());
	m_collectionStatus.SetValue(sumsignal.GetCollectionStatus());
	m_channelInfo.SetValue(sumsignal.GetChannelInfo());
}
