#pragma once
/************************************************************************
Copyright (C), 2018-2020. ����������ѧ�˹�����ʵ����
�ļ����ƣ� SignalService.h
����ժҪ�� �ź���ص�ҵ���߼�.��Ӧ��ʵ�����ļ�ΪSignalService.cpp��
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

#include"TbSignal.h"
#include "TbSensor.h"
#include "TbSensorDao.h"
#include "CommonUtil.h"
#include "TbProductDao.h"
#include "TbSignal.h"
#include "TbSignalDao.h"
class SignalService
{
public:
	SignalService();
	~SignalService();
	  
protected:
	TbSensorDao m_sensorParaDao;
	TbProductDao m_productDao;
	TbSignalDao m_signalDao;
public:
	/**********************************************************************
	�������������ݲ�ѯ������ѯ���еĲɼ�����
	���������
	���������
	�� �� ֵ��Result����
	����˵������ѯ�ɼ�����
	�޸�����	 �汾��		�޸���		�޸�����
	2019-07-30   1.0		������		��ʼ��
	----------------------------------------------------------------------
	***********************************************************************/
	bool GetAllSignalBySearchCondition(TbSignal searchEntity, vector<TbSignal> &signalVector);
};

