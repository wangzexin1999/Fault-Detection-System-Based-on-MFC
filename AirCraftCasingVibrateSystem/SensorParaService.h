/************************************************************************
Copyright (C), 2018-2020. ����������ѧ�˹�����ʵ����
�ļ����ƣ� SignalController.h
����ժҪ�� ������������صķ���ҵ���߼�.��Ӧ��ʵ�����ļ�ΪSensorParaService.cpp��
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
#include <vector>
#include "TbSensorPara.h"
#include "TbSensorParaDao.h"
using namespace std;
class SensorParaService
{

private:
	TbSensorParaDao m_sensorParaDao;
public:
	SensorParaService();
	~SensorParaService();

	/**********************************************************************
	����������������Ŀid�õ����еĴ���������
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	bool GetALLSensorParaByProjectId(int projectId, std::vector<TbSensorPara> &vsensorPara);
};

