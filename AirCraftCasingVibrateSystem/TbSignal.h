#pragma once
#include "TbDetectedDevice.h"
#include "TbSersorPara.h"
#include <vector>
using namespace std;

class TbSignal
{
public:
	TbSignal();
	~TbSignal();

	int m_signalId;
	CString m_startTime;
	CString m_endTime;
	CString m_signalType;
	TbSersorPara m_sensorPara;
	TbDetectedDevice m_detectedDevice;
	CString m_signalStatus;
	CString m_dataUrl;
	vector<vector<double> >  m_signalData; ///ÐÅºÅÊý¾Ý


	int GetSignalId();
	void SetSignalId(int signalId);
	CString GetStartTime();
	void SetStartTime(CString startTime);
	CString GetEndTime();
	void SetEndTime(CString endTime);
	CString GetSignalType();
	void SetSignalType(CString signalType);
	TbSersorPara & GetSensorPara();
	void SetSensorPara(TbSersorPara sensorPara);
	TbDetectedDevice & GetDetectedDevice();
	void SetDetectedDevice(TbDetectedDevice detectedDevice);
	CString GetSignalStatus();
	void SetSignalStatus(CString signal_status);
	CString GetDataUrl();
	void SetDataUrl(CString data_url);

};

