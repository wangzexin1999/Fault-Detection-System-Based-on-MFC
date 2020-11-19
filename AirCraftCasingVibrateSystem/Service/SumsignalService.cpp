#include "stdafx.h"
#include "SumsignalService.h"
#include "DateUtil.h"
#include "FileUtil.h"
SumsignalService::SumsignalService()
{

}

SumsignalService::~SumsignalService()
{

}
HANDLE SumsignalService::m_hMsqlMutex = CreateMutex(NULL, FALSE, NULL);
bool  SumsignalService::GetAllSignalBySearchCondition(TbSumsignal searchEntity, vector<TbSumsignal> &sumsignalVector){
	CString strSqlWhere = "1 = 1 ";
	if (searchEntity.GetProductId() != 0)	strSqlWhere += " and product_id ='" + CommonUtil::Int2CString(searchEntity.GetProductId()) + "'";
	if (searchEntity.GetProjectId() != 0)   strSqlWhere += " and project_id ='" + CommonUtil::Int2CString(searchEntity.GetProjectId()) + "'";
	if (searchEntity.GetCollectionparasId() != 0)  strSqlWhere += " and collectionparas_id ='" + CommonUtil::Int2CString(searchEntity.GetCollectionparasId()) + "'";
	/*if (searchEntity.GetStartTime() != "" && searchEntity.GetEndTime() == "") strSqlWhere += " and end_time >='" + searchEntity.GetStartTime() + "'";
	if (searchEntity.GetEndTime() != "" && searchEntity.GetStartTime() == "") strSqlWhere += " and start_time <='" + searchEntity.GetEndTime() + "'";*/
	if (searchEntity.GetSumsignalId() != "")  strSqlWhere += " and signal_id ='" + searchEntity.GetSumsignalId() + "'";
	if (searchEntity.GetCollectionStatus() != "") strSqlWhere += " and collectionstatus ='" + searchEntity.GetCollectionStatus()+"'";
	
	vector<TbSumsignalDao> sumsignalDaoVec;
	bool isSuccess = m_SumsignalDao.SelectObjectsByCondition(sumsignalDaoVec, strSqlWhere);
	if (isSuccess){
		for (auto SumsignalDao : sumsignalDaoVec){
			TbSumsignal sumsignal;
			SumsignalDao.GetTableFieldValues(sumsignal);
			sumsignalVector.push_back(sumsignal);
		}
	}
	return isSuccess;
}

bool SumsignalService::AddSignalData(map<CString, ThreadSafeQueue<double>> & acquireSignal, TbSumsignal &saveSumsignal){
	///1.ƴװ����·��
	CString path = "C:/collectionData/";
	//CString escapePath = "C:\\\\collectionData\\\\";
	//2.ƴװ �ļ��� ��Ŀid_�����豸id_��Ʒid_ʱ���
	CString fileName = CommonUtil::Int2CString(saveSumsignal.GetProjectId()) + "-"
		+ CommonUtil::Int2CString(saveSumsignal.GetCollectionparasId())
		+ "-" + DateUtil::GetTimeStampCString()
		+ ".csv";
	//����FileUtil�����ļ�������ɹ����زɼ��Ľ���ʱ��
	bool isSuccess = CFileUtil::SaveCollectionData(path, fileName, acquireSignal);
	if (isSuccess){
		///�ļ�����ɹ�������¼���浽���ݿ�
		saveSumsignal.SetDataUrl(path + fileName);
		m_SumsignalDao.SetTableFieldValues(saveSumsignal);
		/*�������ݿ�������ֹ���߳�*/
		WaitForSingleObject(m_hMsqlMutex, INFINITE);
		isSuccess = m_SumsignalDao.Insert(false);
		ReleaseMutex(m_hMsqlMutex);
	}
	return isSuccess;
}

bool SumsignalService::AddSignal(TbSumsignal saveSumsignal){
	m_SumsignalDao.SetTableFieldValues(saveSumsignal);
	bool isSuccess = m_SumsignalDao.Insert(true);
	return isSuccess;
}