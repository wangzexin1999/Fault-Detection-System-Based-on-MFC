#include "stdafx.h"
#include "SignalService.h"


SignalService::SignalService()
{

}


SignalService::~SignalService()
{
}



bool SignalService::FastFourierTransformation(int nCounts, fftw_complex *din, fftw_complex *out)
{

	int i;
	fftw_plan p;
	if ((din == NULL) || (out == NULL))
	{
		printf("Error:insufficient available memory\n");
	}
	else
	{
		
	}
	p = fftw_plan_dft_1d(nCounts, din, out, FFTW_FORWARD, FFTW_ESTIMATE);
	fftw_execute(p); /* repeat as needed */
	//fftw_destroy_plan(p);
	//fftw_cleanup();
	

	//if (din != NULL) fftw_free(din);
	//if (out != NULL) fftw_free(out);

	return 0;
}

////查询所有的记录的信号数据。
bool SignalService::GetAllRecordedSignalBySearchCondition(int projectId, CString signalName, CString startTime, CString endTime, vector<TbSignal> &signalVector){
	/////根据项目id查询所有的传感器参数
	m_sensorParaDao.m_projectId.SetValue(projectId);
	/////

	return true;
}