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
	TbSignal(CString signalId, TbChannel channel, TbSumsignal sumsignalId, int SignalLabel, CString dataUrl);
	~TbSignal();

private:
	CString m_signalId;
	TbChannel m_channel;
	TbSumsignal m_sumsignalId;
	int m_signalLabel;
	CString m_dataUrl;
	//vector<TbSignalTestRecord> m_signalTestRecordVector;
public:

	CString GetSignalId();
	void SetSignalId(CString signalId);

	TbChannel & GetChannel();
	void SetChannel(TbChannel channel);

	TbSumsignal & GetSumsignal();
	void SetSumsignal(TbSumsignal sumsignal);

	int GetSignalLabel();
	void SetSignalLabel(int SignalLabel);

	CString GetDataUrl();
	void SetDataUrl(CString dataUrl);


	//TbSumsignal & GetSumSignal();
	//void SetSumSignal(TbSumsignal sumSignal);

	/*vector<TbSignalTestRecord> & GetSignalTestRecordVector();
	void SetSignalTestRecordVector(vector<TbSignalTestRecord> signalTestRecordVector);*/



};