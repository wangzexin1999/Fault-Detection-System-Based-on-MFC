#include "stdafx.h"
#include "FFTWUtil.h"
#include "AirCraftCasingVibrateSystem.h"

FFTWUtil::FFTWUtil(){
}

FFTWUtil::~FFTWUtil(){

}
std::mutex FFTWUtil::m_hMutex;
bool FFTWUtil::FastFourierTransformation(int nCounts, fftw_complex *din, fftw_complex *out)
{
	m_hMutex.lock();
	if ((din == NULL) || (out == NULL))
	{
		printf("Error:insufficient available memory\n");
		return false;
	}
	fftw_plan plan = fftw_plan_dft_1d(nCounts,din,out, FFTW_FORWARD, FFTW_ESTIMATE);
	fftw_execute(plan);
	fftw_destroy_plan(plan);
	m_hMutex.unlock();
	return FALSE;
}
bool FFTWUtil::FastFourierTransformation(int nCounts, double *din, fftw_complex *out){
	m_hMutex.lock();
	if ((din == NULL) || (out == NULL))
	{
		printf("Error:insufficient available memory\n");
		return false;
	}
	fftw_plan plan = fftw_plan_dft_r2c_1d(nCounts, din, out,FFTW_ESTIMATE);
	fftw_execute(plan);
	fftw_destroy_plan(plan);
	m_hMutex.unlock();
	return FALSE;
}

/*傅里叶变换之后转成坐标*/
void FFTWUtil::FFTDataToXY(SmartFFTWComplexArray  & fftwOut, SChartXYPoint*chartPoints, int pointCount){
	fftw_complex * out = fftwOut.GeFFTWComplexArray();
	chartPoints[0].Y = 0;
	for (int i = 1; i < pointCount / theApp.FFTRATE; i++)
	{
		int j = 2 * sqrt(out[i][0] * out[i][0] + out[i][1] * out[i][1]);
		chartPoints[i].Y = 2 * sqrt(out[i][0] * out[i][0] + out[i][1] * out[i][1]);
	}
}


