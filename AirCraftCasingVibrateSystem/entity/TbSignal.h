#pragma once
#include "TbProduct.h"
#include "TbSensor.h"
#include "TbTestingDevice.h"
#include <vector>
#include "TbProject.h"
using namespace std;

class TbSignal
{
public:
	TbSignal(CString signalId = "");
	~TbSignal();

private:

	CString m_signalId;
	CString m_startTime;
	CString m_endTime;
	CString m_signalType;
	int m_productId;
	char m_signalStatus;
	CString m_dataUrl;
	int  m_projectId;
	int m_testingDeviceId;
	CString m_collectionStatus;
	CString m_sensorInfo;

	

public:
	CString GetSignalId();
	void SetSignalId(CString signalId);

	CString GetStartTime();
	void SetStartTime(CString startTime);
	CString GetEndTime();
	void SetEndTime(CString endTime);

	CString GetSignalType();
	void SetSignalType(CString signalType);
	int   GetProductId();
	void SetProductId(int productId);
	char GetSignalStatus();
	void SetSignalStatus(char signal_status);
	CString GetDataUrl();
	void SetDataUrl(CString data_url);
	void SetProjectId(int projectId);
	int   GetProjectId();
	int  GetTestingDeviceId();
	void SetTestingDeviceId(int  testingDeviceId);
	void SetCollectionStatus(CString para);
	CString GetCollectionStatus();
	CString GetSensorInfo();
	void SetSensorInfo(CString sensorinfo);
};

