#include "stdafx.h"
#include "TbSignalTestRecord.h"
TbSignalTestRecord::TbSignalTestRecord()
{

}
TbSignalTestRecord::TbSignalTestRecord(int recordId, CString recordTime, double frequency, double peakValue, double grossValue, int signal)
{
	SetRecordId(recordId);
	SetRecordTime(recordTime);
	SetFrequency(frequency);
	SetPeakValue(peakValue);
	SetGrossValue(grossValue);
	SetSignalId(signal);
}
TbSignalTestRecord::~TbSignalTestRecord()
{

}
int TbSignalTestRecord::GetRecordId()
{
	return m_recordId;
}
void TbSignalTestRecord::SetRecordId(int recordId)
{
	this->m_recordId = recordId;
}

CString TbSignalTestRecord::GetRecordTime()
{
	return m_recordTime;
}
void TbSignalTestRecord::SetRecordTime(CString recordTime)
{
	this->m_recordTime = recordTime;
}

double TbSignalTestRecord::GetFrequency()
{
	return m_frequency;
}
void TbSignalTestRecord::SetFrequency(double frequency)
{
	this->m_frequency = frequency;
}

double TbSignalTestRecord::GetPeakValue()
{
	return m_peakValue;
}
void TbSignalTestRecord::SetPeakValue(double  peakValue)
{
	this->m_peakValue = peakValue;
}

double TbSignalTestRecord::GetGrossValue()
{
	return m_grossValue;
}
void TbSignalTestRecord::SetGrossValue(double grossValue)
{
	this->m_grossValue = grossValue;
}


//TbSignal & TbSignalTestRecord::GetSignal()
//{
//	return this->m_signal;
//}
//void TbSignalTestRecord::SetSignal(TbSignal signal)
//{
//	this->m_signal = signal;
//}

int TbSignalTestRecord::GetSignalId()
{
	return m_signalId;
}
void TbSignalTestRecord::SetSignalId(int signal)
{
	this->m_signalId = signal;
}