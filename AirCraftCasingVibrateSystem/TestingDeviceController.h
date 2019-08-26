/************************************************************************
Copyright (C), 2018-2020. ������������ѧ�˹�����ʵ����
�ļ����ƣ� GeneralParaView.h
����ժҪ�� ����豸���Ƶ����ҵ���߼�����Ӧ��ʵ�����ļ�ΪTestingDeviceController.cpp��
����˵�����ɻ���ϻ�񶯼��ϵͳ
��ǰ�汾�� 1.0
�� �ߣ� ������
�������ڣ� 2019-08-16
�������:
History:
1. Date:    2018-08-16         Author:������
Modification:
�޸ļ�¼ 1�� // �޸���ʷ��¼�������޸����ڡ��޸��߼��޸�����
�޸����ڣ�
�� �� �ţ�
�� �� �ˣ�
�޸����ݣ�
************************************************************************/
#pragma once
#include "TbTestingDevice.h"
#include "Result.h"
#include <vector>
#include "TestingDeviceService.h"
using namespace  std;
class TestingDeviceController
{

private:
	TestingDeviceService m_testingDeviceService;
public:
	TestingDeviceController();
	~TestingDeviceController();

	/**********************************************************************
	���������� ���ݲ�ѯ�������زɼ��豸
	��������� ����豸���ƣ���ѯ���ļ���豸���� 
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	Result LoadAllTestingDeviceBySearchCondition(CString testingDeviceName, vector<TbTestingDevice> &testingDeviceVector);

	/**********************************************************************
	���������� ���ݼ���豸idɾ������豸
	��������� ����豸
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	Result DeleteByTestingDeviceId(TbTestingDevice testingDevice);

	/**********************************************************************
	���������� �������豸
	��������� ����豸
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	Result AddTestingDevice(TbTestingDevice testingDevice);

	/**********************************************************************
	���������� ���¼���豸
	��������� ����豸
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	Result UpdateTestingDevice(TbTestingDevice testingDevice);

};
