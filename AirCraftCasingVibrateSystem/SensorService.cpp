#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "FFTWUtil.h"
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
			FFTWUtil fftwUtil;
			fftwUtil.FastFourierTransformation(m_signal.GetDinLength(),
				m_signal.GetDinArray(), m_signal.GetDoutArray());
			////////������֮��ĸ���Ҷ�任ת����XY���꣬������ʾ����ͼ
			fftwUtil.FFTDataToXY(m_signal);

			double *x = m_signal.GetXArray();
			double *y = m_signal.GetYArray();
			fftw_complex *din = m_signal.GetDinArray();
			fftw_complex *dout = m_signal.GetDoutArray();
			int size = 1000;
			for (int i = 0; i < 5; i++){
				TRACE("\n++++++++++++++++++++++++++++++���ڣ�%d din=%f,dout=%f,x=%f,y=%f\n", sensorNum, din[i][0],dout[i][0],x[i], y[i]);
			}
			////����Ҫ��ʾ�ĵ�
			 EchoSignal echoSignal = m_signal;
			 theApp.m_echoData[sensorNum].push(echoSignal);
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

bool CSensorService::SaveCollectData(TbProject &project, vector<ThreadSafeQueue<AcquiredSignal>> &collectData, int saveCount){
	///1.ƴװ����·��
	CString path = "I:\\temp\\";
	//2.ƴװ�ļ���
	CString fileName = CommonUtil::Int2CString(project.GetProjectId()) + "-"
		+ CommonUtil::Int2CString(project.GetTestingDevicePara().GetTestingdevice().GetTestingdeviceId())
			+ "-" + CommonUtil::Int2CString(project.GetDetectedDevice().GetDetecteddeviceId()) 
			+ "-" + CommonUtil::Int2CString(collectData.size()) + "-" + DateUtil::GetTimeStampCString()
			+ ".csv";
	//3.��õ�ǰ������еĿ�ʼ�ɼ�ʱ��ͽ����ɼ�ʱ��
	//3.1 ��ÿ�ʼ�ɼ�ʱ�䡣
	CString startTime = DateUtil::GetCurrentCStringTime();
	for (int i = 0; i < collectData.size(); i++){
		if (collectData[i].size() != 0){
			CString acquireTime = collectData[i].front().GetAcquireTime();
			if (acquireTime < startTime) startTime = acquireTime;
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
	}
	return false;
}