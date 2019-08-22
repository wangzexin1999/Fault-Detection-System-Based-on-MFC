#pragma once
#include "TbDetectedDevice.h"
#include "TbSensor.h"
#include "TbTestingDevice.h"
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
	TbSensor m_sensor;
	TbDetectedDevice m_detectedDevice;
	char m_signalStatus;
	CString m_dataUrl;
	vector<vector<double> >  m_signalData; ///ÐÅºÅÊý¾Ý
	TbTestingDevice m_testingDevice;
public:
	int GetSignalId();
	void SetSignalId(int signalId);
	CString GetStartTime();
	void SetStartTime(CString startTime);
	CString GetEndTime();
	void SetEndTime(CString endTime);
	CString GetSignalType();
	void SetSignalType(CString signalType);
	TbDetectedDevice & GetDetectedDevice();
	void SetDetectedDevice(TbDetectedDevice detectedDevice);
	char GetSignalStatus();
	void SetSignalStatus(char signal_status);
	CString GetDataUrl();
	void SetDataUrl(CString data_url);

	void SetProjectId(int project_Id);
	int GetProjectId();

	TbSensor & GetSensor();
	void SetSensor(TbSensor  sensor);


	TbTestingDevice & GetTestingDevice();
	void SetTesingDevice(TbTestingDevice  testingDevice);


};

