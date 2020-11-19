#include "stdafx.h"
#include "TbSignal.h"

TbSignal::TbSignal()
{
	//m_signalId = 0;
	//m_signalStatus = 0;
	//m_dataUrl = "";
}
TbSignal::TbSignal(int signalId, TbChannel channel, TbSumsignal sumsignal, int signalStatus, CString dataUrl)
{
	SetSignalId(signalId);
	SetChannel(channel);
	SetSumsignal(sumsignal);
	SetSignalStatus(signalStatus);
	SetDataUrl(dataUrl);
	//SetSumSignal(sumSignal);
}
TbSignal::~TbSignal()
{

}
int TbSignal::GetSignalId()
{
	return m_signalId;
}
void TbSignal::SetSignalId(int signalId)
{
	this->m_signalId = signalId;
}

TbChannel & TbSignal::GetChannel()
{
	return this->m_channel;
}
void TbSignal::SetChannel(TbChannel channel)
{
	this->m_channel = channel;
}

TbSumsignal & TbSignal::GetSumsignal()
{
	return m_sumsignalId;
}
void TbSignal::SetSumsignal(TbSumsignal sumsignal)
{
	this->m_sumsignalId = sumsignal;
}

int TbSignal::GetSignalStatus()
{
	return m_signalStatus;
}
void TbSignal::SetSignalStatus(int signalStatus)
{
	this->m_signalStatus = signalStatus;
}

CString TbSignal::GetDataUrl()
{
	return m_dataUrl;
}
void TbSignal::SetDataUrl(CString dataUrl)
{
	this->m_dataUrl = dataUrl;
}


//TbSumsignal & TbSignal::GetSumSignal()
//{
//	return this->m_sumSignal;
//}
//void TbSignal::SetSumSignal(TbSumsignal sumSignal)
//{
//	this->m_sumSignal = sumSignal;
//}
//vector<TbSignalTestRecord> & TbSignal::GetSignalTestRecordVector(){
//	return this->m_signalTestRecordVector;
//}
//
//void TbSignal::SetSignalTestRecordVector(vector<TbSignalTestRecord> signalTestRecordVector){
//	this->m_signalTestRecordVector = signalTestRecordVector;
//}