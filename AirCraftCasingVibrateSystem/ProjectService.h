#pragma once
#include "TbProjectDao.h"
#include "TbProject.h"
#include "TbTester.h"
#include "TbTestingDeviceParaDao.h"
#include "TbTestingDevicePara.h"
#include "TbTestingDeviceDao.h"
#include "TbDetectedDeviceDao.h"
#include "CommonUtil.h"

class ProjectService
{
public:
	ProjectService();
	~ProjectService();
protected:
	TbTestingDeviceDao m_testingDeviceDao;
	TbProjectDao  m_projectDao;
	TbTestingDeviceParaDao m_testingDeviceParaDao;
	TbDetectedDeviceDao m_detectedDeviceDao;
public:
	bool AddProject(TbProject & project);
	bool GetAllProjectBySearchCondition(int testerId, CString projectName, CString startTime, CString endTime, vector<TbProject> &projectVector);
	//bool GetAllProjectIdBySearchCondition(int testerId, CString projectName, CString startTime, CString endTime, vector<int> &projectIdVector);
};

