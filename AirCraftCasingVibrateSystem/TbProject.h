#pragma once
#include "TbTester.h"
#include"TbTestingDevicePara.h"
#include "TbDetectedDevice.h"
#include "TbSensorPara.h"
#include <vector>
using namespace std;
class TbProject
{
public:
	TbProject();
	TbProject(int projectId, TbTester tester, CString  projectName, CString projectCreatetime, TbTestingDevicePara  testingDevicePara, TbDetectedDevice  detectedDevice);
	~TbProject();
protected:
	int m_projectId;
	TbTester m_tester;
	CString  m_projectName;
	CString m_projectCreatetime;
	TbTestingDevicePara  m_testingDevicePara;
	TbDetectedDevice m_detectedDevice;
	vector<TbSensorPara> m_sensorParaVector;

public:
	void SetProjectId(int projectId);
	void SetProjectName(CString projectName);
	void SetTester(TbTester tester);
	void SetTestingDevicePara(TbTestingDevicePara testingDevicePara);
	TbTestingDevicePara & GetTestingDevicePara();
	TbDetectedDevice & GetDetectedDevice();
	void SetDetectedDevice(TbDetectedDevice  detectedDevice);
	void SetProjectCreateTime(CString m_projectCreatetime);
	TbTester & GetTester();
	CString GetProjectCreateTime();
	CString GetProjectName();
	vector<TbSensorPara> GetTbSensorParaVector();
	int GetProjectId();
};

