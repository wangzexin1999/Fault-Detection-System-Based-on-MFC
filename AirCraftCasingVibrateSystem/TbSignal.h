#pragma once
#include"TbChannel.h"
#include"TbSumsignal.h"
//#include"TbSignalTestRecord.h"
#include <vector>
#include <atlstr.h>
using namespace std;
class TbSignal
{
public:
	TbSignal();
	TbSignal(int signalId, TbChannel channel, TbSumsignal sumsignalId, int signalStatus, CString dataUrl);
	~TbSignal();
private:
	int m_signalId;
	TbChannel m_channel;
	TbSumsignal m_sumsignalId;
	int m_signalStatus;
	CString m_dataUrl;
	//TbSumsignal m_sumSignal;
	//vector<TbSignalTestRecord> m_signalTestRecordVector;
public:

	int GetSignalId();
	void SetSignalId(int signalId);

	TbChannel & GetChannel();
	void SetChannel(TbChannel channel);

	TbSumsignal & GetSumsignal();
	void SetSumsignal(TbSumsignal sumsignal);

	int GetSignalStatus();
	void SetSignalStatus(int signalStatus);

	CString GetDataUrl();
	void SetDataUrl(CString dataUrl);


	//TbSumsignal & GetSumSignal();
	//void SetSumSignal(TbSumsignal sumSignal);

	/*vector<TbSignalTestRecord> & GetSignalTestRecordVector();
	void SetSignalTestRecordVector(vector<TbSignalTestRecord> signalTestRecordVector);*/



};