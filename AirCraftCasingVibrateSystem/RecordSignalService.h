#pragma once
#include"TbRecordSignal.h"
#include "TbProductDao.h"
#include"TbRecordSignalDao.h"
#include "TbTestingDeviceDao.h"
#include "TbProjectDao.h"
class RecordSignalService
{

protected:
	TbRecordSignalDao m_recordSignalDao;
	TbProductDao	m_productDao;
	TbTestingDeviceDao m_testingDeviceDao;
	TbProjectDao m_projectDao;
public:
	RecordSignalService();
	~RecordSignalService();

	/**********************************************************************
	������������Ӽ�¼�ź�����
	���������TbRecordSignal
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	bool AddRecordSignal(TbRecordSignal recordSignal);
	/**********************************************************************
	�������������ݲ�ѯ������ѯ���еļ�¼����
	��������� ��Ŀ���� ����Ʒ���ƣ�ת�٣��źŲɼ�ʱ�䣬�ź�
	�ɼ�ʱ�䡣�źŵļ��ϡ�
	���������
	�� �� ֵ��Result����
	����˵������ѯ���������ļ�����Ҫ��Բ�Ʒ���ͺź�ת�ٽ��в�ѯ
	�޸�����	 �汾��		�޸���		�޸�����
	2019-07-30   1.0		������		��ʼ��
	----------------------------------------------------------------------
	***********************************************************************/
	bool FindAllRecordSignalBySearchCondition(TbRecordSignal searchEntity, vector<TbRecordSignal> &signalVector);
};

