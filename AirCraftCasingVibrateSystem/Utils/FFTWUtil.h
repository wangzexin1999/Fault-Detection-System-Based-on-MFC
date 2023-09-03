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
	功能描述： FFT变换，将原始数据转换成傅里叶数据
	***********************************************************************/
	static bool FastFourierTransformation(int nCounts, fftw_complex *din, fftw_complex *out);


	/**********************************************************************
	功能描述： FFT变换，将原始数据转换成傅里叶数据
	***********************************************************************/
	static bool FastFourierTransformation(int nCounts, double *din, fftw_complex *out);


	/**********************************************************************
	功能描述：将傅里叶变换处理之后的数据转换成X,Y坐标
	***********************************************************************/
	static void FFTDataToXY(SmartFFTWComplexArray & fftwOut, SChartXYPoint*chartPoints, int pointCount);
};

