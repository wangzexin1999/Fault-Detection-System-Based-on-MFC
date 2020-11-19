
#pragma once
#include"TbCollectionparasDao.h"
#include "ProductService.h"
#include "CollectionparasService.h"
#include "TbProject.h"
#include "ChannelService.h"
#include "ProjectService.h"
#include "UserService.h"
//#include "Colle"
#include"Result.h"
class ProjectController
{

private:
	CollectionparasService m_collectionparasService;
	ProductService m_productService;
	ProjectService m_projectService;
	CChannelService m_channelService;
	UserService m_userService;
public:
	ProjectController();
	~ProjectController();

	/**********************************************************************
	�����������������еĲ����豸
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	Result FindAllCollectionparas(vector<TbCollectionparasDao> & tbCollectionparasVec);

	/**********************************************************************
	�����������½���Ŀ
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	Result AddProject(TbProject & project);

	/**********************************************************************
	�������������ݲ�ѯ�����������е���Ŀ
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	Result FindAllProjectBySearchCondition(TbProject project, CString startTime, CString endTime,vector<TbProject> &projectVector);
	/**********************************************************************
	�����������ҵ����򿪵���Ŀ
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	Result FindLastOpenProjectByUser(TbProject &project);

	/**********************************************************************
	����������������Ŀ
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	Result Update(TbProject project);
	/**********************************************************************
	�������������ݼ������е���Ŀ
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
//	Result FindAllProjectBySearchCondition(int testerId, CString projectName, CString startTime, CString endTime, vector<TbProject> &projectVector);

};

