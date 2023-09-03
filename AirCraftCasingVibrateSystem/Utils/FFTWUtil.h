#pragma once
#include "fftw3.h"
#include "EchoSignal.h"
#include <memory>
#include "SmartFFTWComplexArray.h"
#include "SmartArray.h"
#include <mutex>
#include <condition_variable>
#include "ChartCtrl/ChartXYSerie.h"

class FFTWUtil
{

protected:
	static  std::mutex m_hMutex;
public:
	FFTWUtil();
	~FFTWUtil();
	/**********************************************************************
	���������� FFT�任����ԭʼ����ת���ɸ���Ҷ����
	***********************************************************************/
	static bool FastFourierTransformation(int nCounts, fftw_complex *din, fftw_complex *out);


	/**********************************************************************
	���������� FFT�任����ԭʼ����ת���ɸ���Ҷ����
	***********************************************************************/
	static bool FastFourierTransformation(int nCounts, double *din, fftw_complex *out);


	/**********************************************************************
	����������������Ҷ�任����֮�������ת����X,Y����
	***********************************************************************/
	static void FFTDataToXY(SmartFFTWComplexArray & fftwOut, SChartXYPoint*chartPoints, int pointCount);
};

