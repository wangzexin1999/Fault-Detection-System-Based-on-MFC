#include "stdafx.h"
#include "SensorService.h"


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
int CSensorService::ReadData()
{
	/*for (size_t i = 0; i<2096; ++i)
	{
	m_X[i] = i;
	}
	RandArray(m_Y, 2096);
	return 0;*/
	// TODO:  在此添加控件通知处理程序代码
	int countN = rand() % 100;
	CSignal signal;
	// 取数
	for (int j = 0; j < 1000; j++)
	{
		this->m_signalService.din[j][0] = this->m_readFromCSVFile[countN][j];
		if (this->m_bIsSample)
		{
			signal.m_Y[j] = m_readFromCSVFile[countN][j];
		}
		
	}
	
	if (this->m_bIsSample)
	{
		pushSignal(signal);
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
/*傅里叶变换之后转成坐标*/
int CSensorService::FFTDataToXY(fftw_complex * out)
{
	for (int i = 0; i < 1000; i++)
	{
		this->m_signalService.m_Y [i]= 2 * sqrt(out[i][0] * out[i][0] + out[i][1] * out[i][1]) / 1000;
		
	}
	this->m_signalService.m_Y[0] = 0;
	return 0;
}\

/*入队*/
void CSensorService::pushSignal(CSignal signal)
{
	m_signalSampleQueue.push(signal);

}

/*出队*/
CSignal CSensorService::popSignal()
{

	CSignal signal =  m_signalSampleQueue.front();
	m_signalSampleQueue.pop();
	return signal;
}