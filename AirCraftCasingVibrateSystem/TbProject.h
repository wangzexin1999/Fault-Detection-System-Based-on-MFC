#pragma once
#include "TbTester.h"
#include"TbTestingDevice.h"
#include "TbProduct.h"
#include "TbSensor.h"
#include <vector>
using namespace std;
class TbProject
{
public:

	TbProject(int projectId = 0,CString  projectName = "",int projectStatus = 0);
	TbProject(int projectId, CString  projectName, CString projectCreatetime, TbTester tester, TbTestingDevice  testingDevice, TbProduct  product);
	~TbProject();

protected:

	int m_projectId;
	TbTester m_tester;
	CString  m_projectName;
	CString m_projectCreatetime;
	CString m_projectUpdatetime;
	TbTestingDevice  m_testingDevice;
	TbProduct m_product;
	vector<TbSensor> m_sensorVector;
	int m_projectStatus;
	CString m_collectionPlans;

public:
	void SetProjectId(int projectId);
	void SetProjectName(CString projectName);
	void SetTester(TbTester tester);
	void SetTestingDevice(TbTestingDevice testingDevice);
	TbTestingDevice & GetTestingDevice();
	TbProduct & GetProduct();
	void SetProduct(TbProduct  product);
	void SetProjectCreateTime(CString m_projectCreatetime);
	void SetProjectUpdateTime(CString projectUpdatetime);

	TbTester & GetTester();
	CString GetProjectCreateTime();
	CString GetProjectUpdateTime();

	CString GetProjectName();
	vector<TbSensor> & GetSensorVector();
	void SetSensorVector(vector<TbSensor> sensorParaVector);
	int GetProjectId();
	void SetProjectStatus(int status);
	int GetProjectStatus();
	void SetCollectionPlans(CString collectionPlans);
	CString GetCollectionPlans();
};

