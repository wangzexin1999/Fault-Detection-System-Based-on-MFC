/************************************************************************
Copyright (C), 2018-2020. ����������ѧ�˹�����ʵ����
�ļ����ƣ� SignalController.h
����ժҪ�� ������������ص�ҵ���߼�.��Ӧ��ʵ�����ļ�ΪSensorParaController.cpp��
����˵�����ɻ���ϻ�񶯼��ϵͳ
��ǰ�汾�� 1.0
�� �ߣ� ������
�������ڣ� 2019-08-15
�������:
History:
1. Date:    2019-08-15         Author:������
Modification:
�޸ļ�¼ 1�� // �޸���ʷ��¼�������޸����ڡ��޸��߼��޸�����
�޸����ڣ�
�� �� �ţ�
�� �� �ˣ�
�޸����ݣ�
************************************************************************/
#pragma once
#include "TbProject.h"
#include "Result.h"
#include "SensorParaService.h"
#include "vector"
using namespace std;
class SensorParaController
{

private:
	SensorParaService sensorParaService;

public:
	SensorParaController();
	~SensorParaController();

	/**********************************************************************
	������������ѯָ����Ŀ�Ĵ���������
	���������
	���������
	�� �� ֵ��Result ����
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	Result FindALLSensorParaByProjectId(TbProject &project);
};

