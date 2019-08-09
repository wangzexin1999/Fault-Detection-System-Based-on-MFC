#pragma once
#include "TbDetectedDevice.h"
#include "TbSensorPara.h"
#include <vector>
using namespace std;

class TbSignal
{
public:
	TbSignal();
	~TbSignal();

private:
	int m_signalId;
	int m_projectId;
	CString m_startTime;
	CString m_endTime;
	CString m_signalType;
	vector<TbSensorPara> m_sensorParaVector;
	CString m_sensorParas;
	TbDetectedDevice m_detectedDevice;
	char m_signalStatus;
	CString m_dataUrl;
	vector<vector<double> >  m_signalData; ///ÐÅºÅÊý¾Ý

public:
	int GetSignalId();
	void SetSignalId(int signalId);
	CString GetStartTime();
	void SetStartTime(CString startTime);
	CString GetEndTime();
	void SetEndTime(CString endTime);
	CString GetSignalType();
	void SetSignalType(CString signalType);
	vector<TbSensorPara> & GetSensorParaVector();
	void SetSensorParaVector(vector<TbSensorPara> sensorParaVector);
	TbDetectedDevice & GetDetectedDevice();
	void SetDetectedDevice(TbDetectedDevice detectedDevice);
	char GetSignalStatus();
	void SetSignalStatus(char signal_status);
	CString GetDataUrl();
	void SetDataUrl(CString data_url);

	void SetProjectId(int project_Id);
	int GetProjectId();
};

