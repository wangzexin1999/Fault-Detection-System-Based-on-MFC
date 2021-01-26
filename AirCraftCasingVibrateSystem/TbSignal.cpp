#include "stdafx.h"
#include "TbSignal.h"

TbSignal::TbSignal()
{
	//m_signalId = 0;
	//m_signalLabel = 0;
	//m_dataUrl = "";
}
TbSignal::TbSignal(CString signalId, TbChannel channel, TbSumsignal sumsignal, int signalLabel, CString dataUrl)
{
	SetSignalId(signalId);
	SetChannel(channel);
	SetSumsignal(sumsignal);
	SetSignalLabel(signalLabel);
	SetDataUrl(dataUrl);
	//SetSumSignal(sumSignal);
}
TbSignal::~TbSignal()
{

}
CString TbSignal::GetSignalId()
{
	return m_signalId;
}
void TbSignal::SetSignalId(CString signalId)
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

int TbSignal::GetSignalLabel()
{
	return m_signalLabel;
}
void TbSignal::SetSignalLabel(int signalLabel)
{
	this->m_signalLabel = signalLabel;
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