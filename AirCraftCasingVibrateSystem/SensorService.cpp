#include "stdafx.h"
#include "SensorService.h"
#include "FileUtil.h"
#include "CommonUtil.h"
#include "AcquiredSignal.h"
#include "DateUtil.h"

double CSensorService::m_readFromCSVFile[100][1000];
CSensorService::CSensorService()
{
	//m_signalBuff.CreateBuffer(102400);
}

CSensorService::CSensorService(int nsignalBuff)
{
	//m_signalBuff.CreateBuffer(nsignalBuff);
}


CSensorService::~CSensorService()
{

}


/*�������*/
void CSensorService::RandArray(double* ptr, size_t length)
{
	for (size_t i = 0; i<length; ++i)
	{
		ptr[i] = randf(-1, 1);
	}
}
/*���*/
double CSensorService::randf(double min, double max)
{
	int minInteger = (int)(min * 10000);
	int maxInteger = (int)(max * 10000);
	int randInteger = rand()*rand();
	int diffInteger = maxInteger - minInteger;
	int resultInteger = randInteger % diffInteger + minInteger;
	return resultInteger / 10000.0;
}

bool CSensorService::SaveCollectData(TbProject &project,int saveCount){
	///1.ƴװ����·��
	CString path = "I:\\temp\\";
	//2.ƴװ�ļ���
	CString fileName = CommonUtil::Int2CString(project.GetProjectId()) + "-"
		+ CommonUtil::Int2CString(project.GetTestingDevicePara().GetTestingdevice().GetTestingdeviceId())
			+ "-" + CommonUtil::Int2CString(project.GetDetectedDevice().GetDetecteddeviceId()) 
			+ "-" + CommonUtil::Int2CString(project.GetSensorParaVector().size()) + "-" + DateUtil::GetTimeStampCString()
			+ ".csv";
	
	//3.����FileUtil�����ļ�������ɹ����زɼ��Ŀ�ʼʱ��ͽ���ʱ��
	Result res = CFileUtil::SaveCollectionData(path, fileName, saveCount);
	if (res.GetIsSuccess()){
		///4.�ļ�����ɹ�������¼���浽���ݿ�
		TbSignal signal;
		signal.SetDataUrl(path + fileName);
		signal.SetProjectId(project.GetProjectId());
		signal.SetDetectedDevice(project.GetDetectedDevice());
		vector<CString> times = CommonUtil::GetCStringVectorFromSplitCString(res.GetMessages(), ","); 
		signal.SetStartTime(times[0]);
		signal.SetEndTime(times[1]);
		/////�����������ŵȵȲ�����Ҫ��
		m_signalDao.SetTableFieldValues(signal);
		m_signalDao.Insert(false);
		return true;
	}
	else
	{
		AfxMessageBox(res.GetMessages());
	}
	return false;
}