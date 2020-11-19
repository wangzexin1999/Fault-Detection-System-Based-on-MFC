#include "stdafx.h"
#include "SignalService.h"
#include "DateUtil.h"
#include "FileUtil.h"
SignalService::SignalService()
{

}

SignalService::~SignalService()
{

}
HANDLE SignalService::m_hMsqlMutex = CreateMutex(NULL, FALSE, NULL);
bool  SignalService::GetAllSignalBySearchCondition(TbSignal searchEntity, vector<TbSignal> &signalVector){
	CString strSqlWhere = "1 = 1 ";
	//if (searchEntity.GetProductId() != 0)	strSqlWhere += " and product_id ='" + CommonUtil::Int2CString(searchEntity.GetProductId()) + "'";
	//if (searchEntity.GetProjectId() != 0)   strSqlWhere += " and project_id ='" + CommonUtil::Int2CString(searchEntity.GetProjectId()) + "'";
	//if (searchEntity.GetCollectionparasId() != 0)  strSqlWhere += " and collectionparas_id ='" + CommonUtil::Int2CString(searchEntity.GetCollectionparasId()) + "'";
	/*if (searchEntity.GetStartTime() != "" && searchEntity.GetEndTime() == "") strSqlWhere += " and end_time >='" + searchEntity.GetStartTime() + "'";
	if (searchEntity.GetEndTime() != "" && searchEntity.GetStartTime() == "") strSqlWhere += " and start_time <='" + searchEntity.GetEndTime() + "'";*/
	//if (searchEntity.GetSignalId() != 0)strSqlWhere += "and signal_id='" + CommonUtil::Int2CString(searchEntity.GetSignalId()) + "'";
	//if (searchEntity.GetSumsignalId() != "")  strSqlWhere += " and signal_id ='" + searchEntity.GetSumsignalId() + "'";
	if (searchEntity.GetSumsignal().GetSumsignalId() != "") strSqlWhere += " and sumsignal_id ='" + searchEntity.GetSumsignal().GetSumsignalId() + "'";
	vector<TbSignalDao> signalDaoVec;
	bool isSuccess = m_SignalDao.SelectObjectsByCondition(signalDaoVec,strSqlWhere);
	if (isSuccess){
		for (auto signalDao : signalDaoVec){
			TbSignal signal;
			signalDao.GetTableFieldValues(signal);
			signalVector.push_back(signal);
		}
	}
	return isSuccess;
}

//bool SignalService::AddSignalData(map<CString, ThreadSafeQueue<double>> & acquireSignal, TbSignal &saveSignal){
//	///1.ƴװ����·��
//	CString path = "C:/collectionData/";
//	//CString escapePath = "C:\\\\collectionData\\\\";
//	//2.ƴװ �ļ��� ��Ŀid_�����豸id_��Ʒid_ʱ���
//	CString fileName = CommonUtil::Int2CString(saveSignal.GetProjectId()) + "-"
//		+ CommonUtil::Int2CString(saveSumsignal.GetCollectionparasId())
//		+ "-" + DateUtil::GetTimeStampCString()
//		+ ".csv";
//	//����FileUtil�����ļ�������ɹ����زɼ��Ľ���ʱ��
//	bool isSuccess = CFileUtil::SaveCollectionData(path, fileName, acquireSignal);
//	if (isSuccess){
//		///�ļ�����ɹ�������¼���浽���ݿ�
//		saveSumsignal.SetDataUrl(path + fileName);
//		m_SumsignalDao.SetTableFieldValues(saveSumsignal);
//		/*�������ݿ�������ֹ���߳�*/
//		WaitForSingleObject(m_hMsqlMutex, INFINITE);
//		isSuccess = m_SumsignalDao.Insert(false);
//		ReleaseMutex(m_hMsqlMutex);
//	}
//	return isSuccess;
//}

bool SignalService::AddSignal(TbSignal saveSignal){
	m_SignalDao.SetTableFieldValues(saveSignal);
	bool isSuccess = m_SignalDao.Insert();
	return isSuccess;
}