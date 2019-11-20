#include "stdafx.h"
#include "RealTimeSignal.h"


RealTimeSignal::RealTimeSignal(vector<double> realTimeSignalVal, vector<CString> realTimeSignalTime)
{
	SetRealTimeSignalData(realTimeSignalVal);
	SetRealTimeSignalTime(realTimeSignalTime);
}


RealTimeSignal::~RealTimeSignal()
{
}


vector<double>& RealTimeSignal::GetRealTimeSignalData()
{ 
	return m_realTimeSignalData; 
}
void RealTimeSignal::SetRealTimeSignalData(vector<double> val) {
	m_realTimeSignalData = val; 
}

vector<CString>& RealTimeSignal::GetRealTimeSignalTime()  {
	return m_realTimeSignalTime; 
}
void RealTimeSignal::SetRealTimeSignalTime(vector<CString> val) {
	m_realTimeSignalTime = val; }