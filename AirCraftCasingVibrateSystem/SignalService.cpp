#include "stdafx.h"
#include "SignalService.h"


SignalService::SignalService()
{

}


SignalService::~SignalService()
{
}



bool SignalService::FastFourierTransformation(int nCounts, fftw_complex *din, fftw_complex *out)
{

	int i;
	fftw_plan p;
	if ((din == NULL) || (out == NULL))
	{
		printf("Error:insufficient available memory\n");
	}
	else
	{
		
	}
	p = fftw_plan_dft_1d(nCounts, din, out, FFTW_FORWARD, FFTW_ESTIMATE);
	fftw_execute(p); /* repeat as needed */
	//fftw_destroy_plan(p);
	//fftw_cleanup();
	

	//if (din != NULL) fftw_free(din);
	//if (out != NULL) fftw_free(out);

	return 0;
}

////查询所有的记录的信号数据。
bool SignalService::GetAllRecordedSignalBySearchCondition(int projectId, CString signalName, CString startTime, CString endTime, vector<TbSignal> &signalVector){
	/////1.封装查询条件
	CString strSqlWhere = "project_id='" + CommonUtil::Int2CString(projectId) + "'";
	if (signalName != "") strSqlWhere += "and data_url like '%" + signalName + "%'";
	if (startTime != "") strSqlWhere += "and start_time >='" + startTime + "'";
	if (endTime != "") strSqlWhere += "or end_time <='" + endTime + "'";
	if (startTime != ""&&endTime != "") strSqlWhere += "or start_time <='" + startTime + "' and end_time >= '"+endTime+"'";

	/////2.查询信号记录
	vector<TbRecordSignalDao> recordSignalDaoVector;
	bool isSuccess = m_recordSignalDao.SelectObjectsByCondition(recordSignalDaoVector, strSqlWhere);
	if (isSuccess){
	/////记录信号查询成功，遍历记录信号的集合
		for (auto signalDao : recordSignalDaoVector){
			TbSignal recordSignal;
			signalDao.GetTableFieldValues(recordSignal);
			///查询数据的被检测设备的信息
			m_detectedDeviceDao.m_key->SetValue(recordSignal.GetDetectedDevice().GetDetecteddeviceId());
			isSuccess = m_detectedDeviceDao.SelectByKey();
			if (isSuccess){
			///查询被检测设备成功
				m_detectedDeviceDao.GetTableFieldValues(recordSignal.GetDetectedDevice());
			}
			signalVector.push_back(recordSignal);
		}
    }
	return isSuccess;
}