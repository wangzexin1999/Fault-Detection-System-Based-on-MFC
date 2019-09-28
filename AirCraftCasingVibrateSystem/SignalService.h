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
#include "TbRecordSignal.h"
#include "TbRecordSignalDao.h"
class SignalService
{
public:
	SignalService();
	~SignalService();
	  
protected:
	TbSensorDao m_sensorParaDao;
	TbProductDao m_productDao;
	TbRecordSignalDao m_recordSignalDao;
public:

	/**********************************************************************
	�������������ݲ�ѯ������ѯ���еļ�¼����
	�����������ѯ�źŶ����źŲɼ�ʱ�䣬�źŽ����ɼ�ʱ�䡣�źŵļ��ϡ�
	���������
	�� �� ֵ��bool
	����˵����
	�޸�����	 �汾��		�޸���		�޸�����
	2019-07-30   1.0		������		��ʼ��
	----------------------------------------------------------------------
	***********************************************************************/
	bool GetAllRecordedSignalBySearchCondition(TbRecordSignal signal, CString startTime, CString endTime, vector<TbRecordSignal> &signalVector);
	
};

