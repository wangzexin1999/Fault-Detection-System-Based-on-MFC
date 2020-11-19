#pragma once
#include "TbProjectDao.h"
#include "TbProject.h"
#include "TbUser.h"
#include "TbCollectionparasDao.h"
#include "TbProductDao.h"
#include "CommonUtil.h"
#include "TbUserDao.h"
class ProjectService
{
public:
	ProjectService();
	~ProjectService();
protected:
	TbCollectionparasDao m_collectionparasDao;
	TbProjectDao  m_projectDao;
	TbProductDao m_productDao;
	TbUserDao m_userDao;
public:
	bool AddProject(TbProject & project);

	bool GetAllProjectBySearchCondition(TbProject project, CString startTime, CString endTime, vector<TbProject> &projectVector);
	/**********************************************************************
	功能描述：查询最后打开的项目
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	bool GetLastOpenProjectByUser(TbProject &project);
	/**********************************************************************
	功能描述：更新项目
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	bool Update(TbProject project);
	//bool GetAllProjectIdBySearchCondition(int testerId, CString projectName, CString startTime, CString endTime, vector<int> &projectIdVector);
};

