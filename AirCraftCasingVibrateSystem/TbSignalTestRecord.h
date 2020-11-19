#pragma once
#include"TbSignal.h"
#include <vector>
#include <atlstr.h>
using namespace std;
class TbSignalTestRecord
{
public:
	TbSignalTestRecord();
	TbSignalTestRecord(int recordId, CString recordTime, double frequency, double peakValue, double grossValue, int signalId);
	~TbSignalTestRecord();
private:
	int m_recordId;
	CString m_recordTime;
	double m_frequency;
	double m_peakValue;
	double m_grossValue;
	int m_signalId;
public:

	int GetRecordId();
	void SetRecordId(int recordId);

	CString GetRecordTime();
	void SetRecordTime(CString recordTime);

	double GetFrequency();
	void SetFrequency(double frequency);

	double GetPeakValue();
	void SetPeakValue(double  peakValue);

	double GetGrossValue();
	void SetGrossValue(double grossValue);


	//TbSignal & GetSignal();
	//void SetSignal(TbSignal signal);
	int GetSignalId();
	void SetSignalId(int signalId);
};