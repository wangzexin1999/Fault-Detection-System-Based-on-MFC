#include "stdafx.h"
#include "SignalAcquisitionService.h"
#include "DateUtil.h"
#include "FFTWUtil.h"
#include "AirCraftCasingVibrateSystem.h"
SignalAcquisitionService::SignalAcquisitionService()
{

}


SignalAcquisitionService::~SignalAcquisitionService()
{
}

/*��ȡ����*/
int SignalAcquisitionService::ReadData()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	int countN = rand() % 100;
	// ȡ��

	for (int j = 0; j < 1000; j++)
	{
		this->m_signal.PushToX(j);
		///�ɼ����ݴ��뵽�����С�
		AcquiredSignal acquiredSignal(this->m_readFromCSVFile[countN][j], DateUtil::GetCurrentCStringTime());

		//m_collectData.push(acquiredSignal);

		///�ɼ����ݴ��뵽�����źŵ���������
		this->m_signal.PushToDin(this->m_readFromCSVFile[countN][j]);

		if (theApp.m_bIsSample){
			////�����ʱ���ڲ����������������ݴ��뵽���������С�
			m_sampleData.push(acquiredSignal);
		}
		///����ɼ��������Ѿ��ﵽ���Ե�������Ĭ��1000����
		if (this->m_signal.GetDinLength() >= theApp.m_signalEchoCount){
			/////������и���Ҷ�任

			fftw_complex *din = this->m_signal.GetDinArray();
			for (int i = 0; i < 5; i++){
				TRACE("\n+++++++++++++++++ din=%f\n", din[i][0]);
			}

			////////�Դ�������ݽ��и���Ҷ�任����
			FFTWUtil fftwUtil;
			//fftwUtil.FastFourierTransformation(m_signal.GetDinLength(),
			//	m_signal.GetDinArray(), m_signal.GetDoutArray());
			////////������֮��ĸ���Ҷ�任ת����XY���꣬������ʾ����ͼ
			fftwUtil.FFTDataToXY(m_signal);

			/*double *x = m_signal.GetXArray();
			double *y = m_signal.GetYArray();
			fftw_complex *din = m_signal.GetDinArray();
			fftw_complex *dout = m_signal.GetDoutArray();
			int size = 1000;
			for (int i = 0; i < 5; i++){
			TRACE("\n++++++++++++++++++++++++++++++���ڣ�%d din=%f,dout=%f,x=%f,y=%f\n", din[i][0], dout[i][0], x[i], y[i]);
			}*/
			////����Ҫ��ʾ�ĵ�
			EchoSignal echoSignal = m_signal;
			m_echoData.push(echoSignal);
			m_signal.ClearSignalData();
		}
		///����ɼ��������ﵽ 
	}
	return true;
}

ThreadSafeQueue<AcquiredSignal> & SignalAcquisitionService::GetCollectData(){
	return m_collectData;
}

ThreadSafeQueue<EchoSignal> & SignalAcquisitionService::GetEchoData(){
	return m_echoData;
}
int SignalAcquisitionService::GetCollectDataSize(){
	return m_collectData.size();
}