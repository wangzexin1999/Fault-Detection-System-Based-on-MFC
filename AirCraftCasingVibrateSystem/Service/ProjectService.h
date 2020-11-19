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
	������������ѯ���򿪵���Ŀ
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	bool GetLastOpenProjectByUser(TbProject &project);
	/**********************************************************************
	����������������Ŀ
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	bool Update(TbProject project);
	//bool GetAllProjectIdBySearchCondition(int testerId, CString projectName, CString startTime, CString endTime, vector<int> &projectIdVector);
};

