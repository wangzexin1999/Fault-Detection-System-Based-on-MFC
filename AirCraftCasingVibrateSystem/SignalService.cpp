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
	if (searchEntity.GetSumSignalId() != "") strSqlWhere += " and sumsignal_id ='" + searchEntity.GetSumSignalId() + "'";
	vector<TbSignalDao> signalDaoVec;
	TbSignalDao m_SignalDao;
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

bool SignalService::SaveSignal(TbSignal saveSignal){
	TbSignalDao m_SignalDao;
	m_SignalDao.SetTableFieldValues(saveSignal);
	bool isSuccess = m_SignalDao.Insert(true);
	return isSuccess;
}

bool SignalService::saveSumSignal(TbSumsignal sumSignal){
	TbSumsignalDao sumSignalDao;
	 sumSignalDao.SetTableFieldValues(sumSignal);
	 bool isSuccess = sumSignalDao.Insert(true);
	 return isSuccess;
}

bool SignalService::updateSumSignal(TbSumsignal sumSignal){
	TbSumsignalDao sumSignalDao;
	sumSignalDao.SetTableFieldValues(sumSignal);
	bool isSuccess = sumSignalDao.UpdateByKey();
	return isSuccess;
}

bool SignalService::GetSumSignalByProductId(int productId, vector<TbSumsignal> &sumSignalVec){
	CString strSqlWhere = "1 =1 ";
	if (productId != 0) strSqlWhere += "and product_id = " + CommonUtil::Int2CString(productId);
	TbSumsignalDao sumSignalDao;
	vector<TbSumsignalDao> signalDaoVec;
	bool isSuccess = sumSignalDao.SelectObjectsByCondition(signalDaoVec, strSqlWhere);
	if (isSuccess){
		for (auto signalDao : signalDaoVec){
			TbSumsignal signal;
			signalDao.GetTableFieldValues(signal);
			sumSignalVec.push_back(signal);
		}
	}
	return isSuccess; 
}

bool SignalService::GetSignalsBySumSignalId(CString sumSignalId, vector<TbSignal> &signals){
	CString strSqlWhere = "1 = 1 ";
	if (sumSignalId != "") strSqlWhere += "and sum_signal_id = '" + sumSignalId + "'";
	TbSignalDao signalDao;
	signalDao.m_sumSignalId.SetValue(sumSignalId);
	vector<TbSignalDao> signalDaoVec;
	bool isSuccess = signalDao.SelectObjectsByCondition(signalDaoVec, strSqlWhere);
	if (isSuccess){
		for (auto signalDao : signalDaoVec){
			TbSignal signal;
			signalDao.GetTableFieldValues(signal);
			signals.push_back(signal);
		}
	}
	return isSuccess;
}

bool SignalService::FindAllSumSignalBySearchCondition(TbSumsignal searchEntity, vector<TbSumsignal> &signalVector){
	CString strSqlWhere = "1 = 1 ";
	if (searchEntity.GetProductId() != 0)	
		strSqlWhere += " and product_id ='" + CommonUtil::Int2CString(searchEntity.GetProductId()) + "'";
	/*if (searchEntity.GetStartTime() != "" && searchEntity.GetEndTime() == "") strSqlWhere += " and end_time >='" + searchEntity.GetStartTime() + "'";
	if (searchEntity.GetEndTime() != "" && searchEntity.GetStartTime() == "") strSqlWhere += " and start_time <='" + searchEntity.GetEndTime() + "'";*/
	if (searchEntity.GetEndTime() != "" && searchEntity.GetStartTime() != "") 
		strSqlWhere += " and start_time >= '" + searchEntity.GetStartTime() + "' AND end_time <= '" + searchEntity.GetEndTime()+"'";
	strSqlWhere += " ORDER BY start_time desc";
	vector<TbSumsignalDao> recordSignalDaoVector;
	TbSumsignalDao sumSignalDao;
	bool isSuccess = sumSignalDao.SelectObjectsByCondition(recordSignalDaoVector, strSqlWhere);
	if (isSuccess == true){
		for (auto signalDao : recordSignalDaoVector){
			TbSumsignal recordSignal;
			signalDao.GetTableFieldValues(recordSignal);
			///��ѯ���ݵĲ�Ʒ����Ϣ
			m_productDao.m_key->SetValue(recordSignal.GetProductId());
			isSuccess = m_productDao.SelectByKey();
			if (!isSuccess){ AfxMessageBox("��Ʒ����ʧ��"); }
			else m_productDao.GetTableFieldValues(recordSignal.GetProduct());
			///��ѯ�����ź�
			//GetSignalsBySumSignalId(recordSignal.GetSumsignalId(), recordSignal.GetAllSignal());
			/*///��ѯ�ɼ��豸��Ϣ
			m_collectionparasDao.m_key->SetValue(recordSignal.GetCollectionparas().GetId());
			isSuccess = m_collectionparasDao.SelectByKey();
			if (!isSuccess){ AfxMessageBox("�ɼ��豸����ʧ��"); }
			else m_collectionparasDao.GetTableFieldValues(recordSignal.GetCollectionparas());*/
			///��ѯ��Ŀ��Ϣ
			/*m_projectDao.m_key->SetValue(recordSignal.GetProject().GetProjectId());
			isSuccess = m_projectDao.SelectByKey();
			m_projectDao.GetTableFieldValues(recordSignal.GetProject());
			if (!isSuccess){ AfxMessageBox("��Ŀ����ʧ��"); }*/
			signalVector.push_back(recordSignal);
		}
	}

	return true;
}