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

/*��ȡ����*/
int CSensorService::ReadData(int sensorNum)
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	int countN = rand() % 100;
	EchoSignal signal;
	// ȡ��
	for (int j = 0; j < 1000; j++)
	{
		this->m_signal.PushToX(j);
		///�ɼ����ݴ��뵽�����С�
		AcquiredSignal acquiredSignal(this->m_readFromCSVFile[countN][j], DateUtil::GetCurrentCStringTime());

		theApp.m_collectData[sensorNum].push(acquiredSignal);

		///�ɼ����ݴ��뵽�����źŵ���������
		this->m_signal.PushToDin(this->m_readFromCSVFile[countN][j]);
		if (theApp.m_bIsSample){
			////�����ʱ���ڲ����������������ݴ��뵽���������С�
			theApp.m_sampleData[sensorNum].push(acquiredSignal);
		}
		///����ɼ��������Ѿ��ﵽ���Ե�������Ĭ��1000����
		if (this->m_signal.GetDinLength() >= theApp.m_signalEchoCount){
			/////������и���Ҷ�任
			////////�Դ�������ݽ��и���Ҷ�任����
			FFTWUtil::FastFourierTransformation(m_signal.GetDinLength(),
				m_signal.GetDinArray(), m_signal.GetDoutArray());
			////////������֮��ĸ���Ҷ�任ת����XY���꣬������ʾ����ͼ
			FFTWUtil::FFTDataToXY(m_signal);
			////����Ҫ��ʾ�ĵ�
			 EchoSignal echoSignal = m_signal;
			 this->m_echoSignalQueue.push(echoSignal);
			m_signal.ClearSignalData();
		}
		///����ɼ��������ﵽ 

	}
	return true;
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
EchoSignal CSensorService::FrontEchoSignalQueue(){
	EchoSignal echoSignal;
	if (!m_echoSignalQueue.empty()) {
		///��������Ԫ�أ���ø�Ԫ�أ�����ջ�е�����Ԫ��
		echoSignal = m_echoSignalQueue.front();
		m_echoSignalQueue.pop();
	}
	return echoSignal;
}
bool CSensorService::SaveCollectData(TbProject &project, vector<queue<AcquiredSignal>> &collectData, int saveCount){
	///1.ƴװ����·��
	CString path = "I:\\temp\\";
	//2.ƴװ�ļ���
	CString fileName = CommonUtil::Int2CString(project.GetProjectId()) + "-"
		+ CommonUtil::Int2CString(project.GetTestingDevicePara().GetTestingdevice().GetTestingdeviceId())
			+ "-" + CommonUtil::Int2CString(project.GetDetectedDevice().GetDetecteddeviceId()) 
			+ "-" + CommonUtil::Int2CString(collectData.size()) + "-" + DateUtil::GetCurrentCStringTime("%Y_%m_%d_%H_%M_%S")
			+ ".csv";
	//3.��õ�ǰ������еĿ�ʼ�ɼ�ʱ��ͽ����ɼ�ʱ��
	//3.1 ��ÿ�ʼ�ɼ�ʱ�䡣
	CString startTime = DateUtil::GetCurrentCStringTime();
	for (int i = 0; i < collectData.size(); i++){
		if (!collectData[i].empty()){
			TRACE("\n%s+++++++++++++++++++++++++++++++\n", collectData[i].front().GetAcquireTime());
			TRACE("\n---------------------------------\n");
			//CString acquireTime = collectData[i].front().GetAcquireTime();
			//if (acquireTime < startTime) startTime = acquireTime;
		}
	}
	//4.����FileUtil�����ļ�������ɹ����زɼ��Ľ���ʱ��
	Result res = CFileUtil::SaveCollectionData(collectData, path, fileName, saveCount);
	if (res.GetIsSuccess()){
		///5.�ļ�����ɹ�������¼���浽���ݿ�
		TbSignal signal;
		signal.SetDataUrl(path + fileName);
		signal.SetProjectId(project.GetProjectId());
		signal.SetDetectedDevice(project.GetDetectedDevice());
		signal.SetStartTime(startTime);
		signal.SetEndTime(res.GetMessages());
		/////�����������ŵȵȲ�����Ҫ��
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