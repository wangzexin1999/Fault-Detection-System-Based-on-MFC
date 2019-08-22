#include "stdafx.h"
#include "FFTWUtil.h"


HANDLE FFTWUtil::m_hMutex;


FFTWUtil::FFTWUtil(){
	m_hMutex = ::CreateMutex(NULL, FALSE, NULL);
}

FFTWUtil::~FFTWUtil()
{
	//::CloseHandle(m_hMutex);
}

bool FFTWUtil::FastFourierTransformation(int nCounts, fftw_complex *din, fftw_complex *out)
{
	//::WaitForSingleObject(m_hMutex, INFINITE);
	if ((din == NULL) || (out == NULL))
	{
		printf("Error:insufficient available memory\n");
		return false;
	}
	fftw_plan plan = fftw_plan_dft_1d(
		nCounts,
		din,
		out, FFTW_FORWARD, FFTW_ESTIMATE);
	if (NULL != plan)
	{
		fftw_execute(plan);
		fftw_destroy_plan(plan);
		return TRUE;
	}
	//::ReleaseMutex(m_hMutex);
	return FALSE;
}
/*傅里叶变换之后转成坐标*/
int FFTWUtil::FFTDataToXY(SmartFFTWComplexArray  & fftwOut, SmartArray<double> &yData, int pointCount){
	fftw_complex * out = fftwOut.GeFFTWComplexArray();
	yData.push_back(0);
	for (int i = 1; i < pointCount; i++)
	{
		yData.push_back(2 * sqrt(out[i][0] * out[i][0] + out[i][1] * out[i][1]) / 1000);
	}
	return 0;
}