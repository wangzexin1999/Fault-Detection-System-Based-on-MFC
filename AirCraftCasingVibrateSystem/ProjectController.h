/************************************************************************
Copyright (C), 2018-2020. ����������ѧ�˹�����ʵ����
�ļ����ƣ� SignalController.h
����ժҪ�� ��Ŀ��ص�ҵ���߼�.��Ӧ��ʵ�����ļ�ΪProjectController.cpp��
����˵�����ɻ���ϻ�񶯼��ϵͳ
��ǰ�汾�� 1.0
�� �ߣ� ������
�������ڣ� 2019-07-30
�������:
History:
1. Date:    2018-07-30         Author:������
Modification:
�޸ļ�¼ 1�� // �޸���ʷ��¼�������޸����ڡ��޸��߼��޸�����
�޸����ڣ�
�� �� �ţ�
�� �� �ˣ�
�޸����ݣ�
************************************************************************/
#pragma once
#include"TbTestingDeviceDao.h"
#include "ProductService.h"
#include "TestingDeviceService.h"
#include "TbProject.h"
#include "SensorService.h"
#include "ProjectService.h"
//#include "Colle"
#include"Result.h"
class ProjectController
{

private:
	TestingDeviceService m_testingDeviceService;
	ProductService m_productService;
	ProjectService m_projectService;
	CSensorService m_sensorService;

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
	Result FindAllTestingDevice(vector<TbTestingDeviceDao> & tbTestingVec);

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

