#pragma once
#include "fftw3.h"
#define  POINT_COUNTS  1000

class CSignal
{
public:
	CSignal();
	~CSignal();

public:
	double m_X[POINT_COUNTS]; // 转换之后的X
	double m_Y[POINT_COUNTS]; // 转换之后的Y

	

	fftw_complex din[POINT_COUNTS], out[POINT_COUNTS]; // 傅里叶变换之前和之后
};

