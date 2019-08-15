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

/*读取数据*/
int SignalAcquisitionService::ReadData()
{
	// TODO:  在此添加控件通知处理程序代码
	int countN = rand() % 100;
	// 取数

	for (int j = 0; j < 1000; j++)
	{
		this->m_signal.PushToX(j);
		///采集数据存入到队列中。
		AcquiredSignal acquiredSignal(this->m_readFromCSVFile[countN][j], DateUtil::GetCurrentCStringTime());

		//m_collectData.push(acquiredSignal);

		///采集数据存入到回显信号的输入数组
		this->m_signal.PushToDin(this->m_readFromCSVFile[countN][j]);

		if (theApp.m_bIsSample){
			////如果此时正在采样，将采样的数据存入到采样队列中。
			m_sampleData.push(acquiredSignal);
		}
		///如果采集的数量已经达到回显的数量。默认1000个点
		if (this->m_signal.GetDinLength() >= theApp.m_signalEchoCount){
			/////对其进行傅里叶变换

			fftw_complex *din = this->m_signal.GetDinArray();
			for (int i = 0; i < 5; i++){
				TRACE("\n+++++++++++++++++ din=%f\n", din[i][0]);
			}

			////////对传入的数据进行傅里叶变换处理
			FFTWUtil fftwUtil;
			//fftwUtil.FastFourierTransformation(m_signal.GetDinLength(),
			//	m_signal.GetDinArray(), m_signal.GetDoutArray());
			////////将处理之后的傅里叶变换转换成XY坐标，用来显示折线图
			fftwUtil.FFTDataToXY(m_signal);

			/*double *x = m_signal.GetXArray();
			double *y = m_signal.GetYArray();
			fftw_complex *din = m_signal.GetDinArray();
			fftw_complex *dout = m_signal.GetDoutArray();
			int size = 1000;
			for (int i = 0; i < 5; i++){
			TRACE("\n++++++++++++++++++++++++++++++窗口：%d din=%f,dout=%f,x=%f,y=%f\n", din[i][0], dout[i][0], x[i], y[i]);
			}*/
			////接受要显示的点
			EchoSignal echoSignal = m_signal;
			m_echoData.push(echoSignal);
			m_signal.ClearSignalData();
		}
		///如果采集的数量达到 
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