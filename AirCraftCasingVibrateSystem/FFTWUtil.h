#pragma once
#include "fftw3.h"
#include "EchoSignal.h"
#include <memory>
#include "SmartFFTWComplexArray.h"
#include "SmartArray.h"
#include <mutex>
#include <condition_variable>
	
class FFTWUtil
{

protected:
	
	static HANDLE m_hMutex;

public:
	FFTWUtil();
	~FFTWUtil();
	/**********************************************************************
	功能描述： FFT变换，将原始数据转换成傅里叶数据
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	static bool FastFourierTransformation(int nCounts, fftw_complex *din, fftw_complex *out);

	/**********************************************************************
	功能描述： FFT变换，将原始数据转换成傅里叶数据
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	static bool FastFourierTransformation(int nCounts, double *din, fftw_complex *out);

	/**********************************************************************
	功能描述：将傅里叶变换处理之后的数据转换成X,Y坐标
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	static void FFTDataToXY(SmartFFTWComplexArray & fftwOut, SmartArray<double> &yData, int pointCount);
};

