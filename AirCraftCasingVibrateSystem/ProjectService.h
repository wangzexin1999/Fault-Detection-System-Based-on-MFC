#pragma once
#include "TbProjectDao.h"
#include "TbProject.h"
#include "TbTester.h"
#include "TbTestingDeviceDao.h"
#include "TbProductDao.h"
#include "CommonUtil.h"
#include "TbTesterDao.h"
class ProjectService
{
public:
	ProjectService();
	~ProjectService();
protected:
	TbTestingDeviceDao m_testingDeviceDao;
	TbProjectDao  m_projectDao;
	TbProductDao m_productDao;
	TbTesterDao m_testerDao;
public:
	bool AddProject(TbProject & project);

	bool GetAllProjectBySearchCondition(TbProject project, CString startTime, CString endTime, vector<TbProject> &projectVector);
	//bool GetAllProjectIdBySearchCondition(int testerId, CString projectName, CString startTime, CString endTime, vector<int> &projectIdVector);
};

