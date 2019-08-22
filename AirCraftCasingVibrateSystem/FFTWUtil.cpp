#include "stdafx.h"
#include "FFTWUtil.h"

FFTWUtil::FFTWUtil(){
}

FFTWUtil::~FFTWUtil(){
	//::CloseHandle(m_hMutex);
}

bool FFTWUtil::FastFourierTransformation(int nCounts, fftw_complex *din, fftw_complex *out)
{
	if ((din == NULL) || (out == NULL))
	{
		printf("Error:insufficient available memory\n");
		return false;
	}
	fftw_plan plan = fftw_plan_dft_1d(nCounts,din,out, FFTW_FORWARD, FFTW_ESTIMATE);
	fftw_execute(plan);
	return FALSE;
}
/*傅里叶变换之后转成坐标*/
void FFTWUtil::FFTDataToXY(SmartFFTWComplexArray  & fftwOut, SmartArray<double> &yData, int pointCount){
	fftw_complex * out = fftwOut.GeFFTWComplexArray();
	yData.push_back(0);
	for (int i = 1; i < pointCount; i++)
	{
		yData.push_back(2 * sqrt(out[i][0] * out[i][0] + out[i][1] * out[i][1]) / 1000);
	}
}