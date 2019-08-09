#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "FFTWUtil.h"
#include "FileUtil.h"
#include "CommonUtil.h"
#include "AcquiredSignal.h"
#include "DateUtil.h"

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

/*读取数据*/
int CSensorService::ReadData(int sensorNum)
{
	// TODO:  在此添加控件通知处理程序代码
	int countN = rand() % 100;
	EchoSignal signal;
	// 取数
	for (int j = 0; j < 1000; j++)
	{
		this->m_signal.PushToX(j);
		///采集数据存入到队列中。
		AcquiredSignal acquiredSignal(this->m_readFromCSVFile[countN][j], DateUtil::GetCurrentCStringTime());

		theApp.m_collectData[sensorNum].push(acquiredSignal);

		///采集数据存入到回显信号的输入数组
		this->m_signal.PushToDin(this->m_readFromCSVFile[countN][j]);
		if (theApp.m_bIsSample){
			////如果此时正在采样，将采样的数据存入到采样队列中。
			theApp.m_sampleData[sensorNum].push(acquiredSignal);
		}
		///如果采集的数量已经达到回显的数量。默认1000个点
		if (this->m_signal.GetDinLength() >= theApp.m_signalEchoCount){
			/////对其进行傅里叶变换
			////////对传入的数据进行傅里叶变换处理
			FFTWUtil::FastFourierTransformation(m_signal.GetDinLength(),
				m_signal.GetDinArray(), m_signal.GetDoutArray());
			////////将处理之后的傅里叶变换转换成XY坐标，用来显示折线图
			FFTWUtil::FFTDataToXY(m_signal);
			////接受要显示的点
			 EchoSignal echoSignal = m_signal;
			 this->m_echoSignalQueue.push(echoSignal);
			m_signal.ClearSignalData();
		}
		///如果采集的数量达到 

	}
	return true;
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
EchoSignal CSensorService::FrontEchoSignalQueue(){
	EchoSignal echoSignal;
	if (!m_echoSignalQueue.empty()) {
		///队列中有元素，获得该元素，并从栈中弹出该元素
		echoSignal = m_echoSignalQueue.front();
		m_echoSignalQueue.pop();
	}
	return echoSignal;
}
bool CSensorService::SaveCollectData(TbProject &project, vector<queue<AcquiredSignal>> &collectData, int saveCount){
	///1.拼装保存路径
	CString path = "I:\\temp\\";
	//2.拼装文件名
	CString fileName = CommonUtil::Int2CString(project.GetProjectId()) + "-"
		+ CommonUtil::Int2CString(project.GetTestingDevicePara().GetTestingdevice().GetTestingdeviceId())
			+ "-" + CommonUtil::Int2CString(project.GetDetectedDevice().GetDetecteddeviceId()) 
			+ "-" + CommonUtil::Int2CString(collectData.size()) + "-" + DateUtil::GetCurrentCStringTime("%Y_%m_%d_%H_%M_%S")
			+ ".csv";
	//3.获得当前保存队列的开始采集时间和结束采集时间
	//3.1 获得开始采集时间。
	CString startTime = DateUtil::GetCurrentCStringTime();
	for (int i = 0; i < collectData.size(); i++){
		if (!collectData[i].empty()){
			TRACE("\n%s+++++++++++++++++++++++++++++++\n", collectData[i].front().GetAcquireTime());
			TRACE("\n---------------------------------\n");
			//CString acquireTime = collectData[i].front().GetAcquireTime();
			//if (acquireTime < startTime) startTime = acquireTime;
		}
	}
	//4.调用FileUtil保存文件，保存成功返回采集的结束时间
	Result res = CFileUtil::SaveCollectionData(collectData, path, fileName, saveCount);
	if (res.GetIsSuccess()){
		///5.文件保存成功，将记录保存到数据库
		TbSignal signal;
		signal.SetDataUrl(path + fileName);
		signal.SetProjectId(project.GetProjectId());
		signal.SetDetectedDevice(project.GetDetectedDevice());
		signal.SetStartTime(startTime);
		signal.SetEndTime(res.GetMessages());
		/////传感器参数号等等参数还要穿
		m_signalDao.SetTableFieldValues(signal);
		m_signalDao.Insert(false);
		return true;
	}
	else
	{
		AfxMessageBox(res.GetMessages());
		TRACE("%d+++++++++++++++++++++++++++++++++++++++++++\n", saveCount);
	}
	return false;
}