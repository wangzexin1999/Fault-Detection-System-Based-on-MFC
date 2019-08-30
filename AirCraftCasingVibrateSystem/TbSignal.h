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
	TbSignal(int signalId = 0, int sensorCount = 0);
	~TbSignal();

private:
	int m_signalId;
	
	TbProject m_project;

	CString m_startTime;
	CString m_endTime;
	CString m_signalType;
	TbSensor m_sensor;
	TbProduct m_product;
	char m_signalStatus;
	CString m_dataUrl;
	TbTestingDevice m_testingDevice;
	int m_sensorCount; ////传感器数量

public:
	int GetSignalId();
	void SetSignalId(int signalId);
	CString GetStartTime();
	void SetStartTime(CString startTime);
	CString GetEndTime();
	void SetEndTime(CString endTime);
	CString GetSignalType();
	void SetSignalType(CString signalType);
	TbProduct & GetProduct();
	void SetProduct(TbProduct product);
	char GetSignalStatus();
	void SetSignalStatus(char signal_status);
	CString GetDataUrl();
	void SetDataUrl(CString data_url);

	void SetProject(TbProject project);
	TbProject & GetProject();

	TbSensor & GetSensor();
	void SetSensor(TbSensor  sensor);


	TbTestingDevice & GetTestingDevice();
	void SetTesingDevice(TbTestingDevice  testingDevice);

	void SetSensorCount(int sensorCount);
	int GetSensorCount();

};

