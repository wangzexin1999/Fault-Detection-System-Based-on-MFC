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


/*随机数组*/
void CSensorService::RandArray(double* ptr, size_t length)
{
	for (size_t i = 0; i<length; ++i)
	{
		ptr[i] = randf(-1, 1);
	}
}
/*随机*/
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
	///1.拼装保存路径
	CString path = "I:\\temp\\";
	//2.拼装文件名
	CString fileName = CommonUtil::Int2CString(project.GetProjectId()) + "-"
		+ CommonUtil::Int2CString(project.GetTestingDevicePara().GetTestingdevice().GetTestingdeviceId())
			+ "-" + CommonUtil::Int2CString(project.GetDetectedDevice().GetDetecteddeviceId()) 
			+ "-" + CommonUtil::Int2CString(project.GetSensorParaVector().size()) + "-" + DateUtil::GetTimeStampCString()
			+ ".csv";
	
	//3.调用FileUtil保存文件，保存成功返回采集的开始时间和结束时间
	Result res = CFileUtil::SaveCollectionData(path, fileName, saveCount);
	if (res.GetIsSuccess()){
		///4.文件保存成功，将记录保存到数据库
		TbSignal signal;
		signal.SetDataUrl(path + fileName);
		signal.SetProjectId(project.GetProjectId());
		signal.SetDetectedDevice(project.GetDetectedDevice());
		vector<CString> times = CommonUtil::GetCStringVectorFromSplitCString(res.GetMessages(), ","); 
		signal.SetStartTime(times[0]);
		signal.SetEndTime(times[1]);
		/////传感器参数号等等参数还要穿
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