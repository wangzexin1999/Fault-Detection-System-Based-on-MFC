#pragma once
#include "fftw3.h"
#define  POINT_COUNTS  1000

class CSignal
{
public:
	CSignal();
	~CSignal();

public:
	double m_X[POINT_COUNTS]; // ת��֮���X
	double m_Y[POINT_COUNTS]; // ת��֮���Y

	

	fftw_complex din[POINT_COUNTS], out[POINT_COUNTS]; // ����Ҷ�任֮ǰ��֮��
};

