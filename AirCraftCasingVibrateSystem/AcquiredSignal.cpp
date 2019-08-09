#include "stdafx.h"
#include "AcquiredSignal.h"


AcquiredSignal::AcquiredSignal()
{
}
AcquiredSignal::AcquiredSignal(double signalData, CString acquireTime){
	this->m_acquiredTime = acquireTime;
	this->m_signalData = signalData;
}

AcquiredSignal::~AcquiredSignal()
{
}


void AcquiredSignal::SetAcquireTime(CString acquireTime){
	this->m_acquiredTime = acquireTime;
}
void AcquiredSignal::SetSignalData(double signalData){
	this->m_signalData = signalData;
}
CString AcquiredSignal::GetAcquireTime(){
	return m_acquiredTime;
}

double AcquiredSignal::GetSignalData(){
	return m_signalData;
}