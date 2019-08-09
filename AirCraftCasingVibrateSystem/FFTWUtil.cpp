#include "stdafx.h"
#include "FFTWUtil.h"

bool FFTWUtil::FastFourierTransformation(int nCounts, fftw_complex *din, fftw_complex *out)
{
	int i;
	fftw_plan p;
	if ((din == NULL) || (out == NULL))
	{
		printf("Error:insufficient available memory\n");
		return false;
	}
	p = fftw_plan_dft_1d(nCounts, din, out, FFTW_FORWARD, FFTW_ESTIMATE);
	fftw_execute(p); 
	return true;
}

/*傅里叶变换之后转成坐标*/
int FFTWUtil::FFTDataToXY(EchoSignal & echoSignal){
	fftw_complex * out = echoSignal.GetDoutArray();
	for (int i = 0; i < echoSignal.GetXLength(); i++)
	{
		echoSignal.PushToY(2 * sqrt(out[i][0] * out[i][0] + out[i][1] * out[i][1]) / 1000);
	}
	echoSignal.UpdateY(0, 0);
	return 0;
}