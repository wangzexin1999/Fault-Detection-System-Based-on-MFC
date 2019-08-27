#pragma once
/************************************************************************
Copyright (C), 2018-2020. ����������ѧ�˹�����ʵ����
�ļ����ƣ� SignalController.h
����ժҪ�� �ź�������ص�ҵ���߼�.��Ӧ��ʵ�����ļ�ΪSignalController.cpp��
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
#include "Result.h"
#include "TbSignal.h"
#include "SignalService.h"
#include "ProjectService.h"
class SignalController
{

private:
	SignalService m_signalService;
	ProjectService m_projectService;
public:
	SignalController();
	~SignalController();
	/**********************************************************************
	�������������ݲ�ѯ������ѯ���еļ�¼����
	�����������Ŀ���� ����Ʒ���ƣ�ת�٣��źŲɼ�ʱ�䣬�źŽ����ɼ�ʱ�䡣�źŵļ��ϡ�
	���������
	�� �� ֵ��Result����
	����˵����
	�޸�����	 �汾��		�޸���		�޸�����
	2019-07-30   1.0		������		��ʼ��	
	----------------------------------------------------------------------
	***********************************************************************/
	Result LoadAllRecordedSignalBySearchCondition(CString projectName, CString productName, CString rotatingSpeed, CString startTime, CString endTime, vector<TbSignal> &signalVector);
};

