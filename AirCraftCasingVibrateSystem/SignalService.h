#pragma once
/************************************************************************
Copyright (C), 2018-2020. ����������ѧ�˹�����ʵ����
�ļ����ƣ� SignalController.h
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
#include "fftw3.h"
#include"TbRecordSignalDao.h"
#include"TbSignal.h"
#include "TbSensorPara.h"
#include "TbSensorParaDao.h"
#include "CommonUtil.h"
#include "TbDetectedDeviceDao.h"
class SignalService
{
public:
	SignalService();
	~SignalService();

protected:
	TbSensorParaDao m_sensorParaDao;
	TbRecordSignalDao m_recordSignalDao;
	TbDetectedDeviceDao m_detectedDeviceDao;
public:
	/**********************************************************************
	���������� FFT�任
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	bool FastFourierTransformation(int nCounts, fftw_complex *din, fftw_complex *out);

	/**********************************************************************
	�������������ݲ�ѯ������ѯ���еļ�¼����
	�����������Ŀid ���ź����ƣ��źŲɼ�ʱ�䣬�źŽ����ɼ�ʱ�䡣�źŵļ��ϡ�
	���������
	�� �� ֵ��bool
	����˵����
	�޸�����	 �汾��		�޸���		�޸�����
	2019-07-30   1.0		������		��ʼ��
	----------------------------------------------------------------------
	***********************************************************************/
	bool GetAllRecordedSignalBySearchCondition(int projectId, CString signalName, CString startTime, CString endTime, vector<TbSignal> &signalVector);
	
};

