#pragma once
#include "fftw3.h"
#include "EchoSignal.h"
#include <mutex>
#include <memory>
#include "SmartFFTWComplexArray.h"
#include "SmartArray.h"
#include <mutex>
#include <condition_variable>
class FFTWUtil
{
private:
	static HANDLE m_hMutex;
public:
	FFTWUtil();
	~FFTWUtil();
	/**********************************************************************
	���������� FFT�任����ԭʼ����ת���ɸ���Ҷ����
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	bool FastFourierTransformation(int nCounts, fftw_complex *din, fftw_complex *out);

	/**********************************************************************
	����������������Ҷ�任����֮�������ת����X,Y����
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	int FFTDataToXY(SmartFFTWComplexArray & fftwOut, SmartArray<double> &yData, int pointCount);
};

