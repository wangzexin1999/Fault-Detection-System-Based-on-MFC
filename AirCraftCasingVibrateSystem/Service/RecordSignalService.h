#pragma once
#include"TbRecordSignal.h"
#include "TbProductDao.h"
#include"TbRecordSignalDao.h"
#include "TbCollectionparasDao.h"
#include "TbProjectDao.h"
class RecordSignalService
{

protected:
	TbRecordSignalDao m_recordSignalDao;
	TbProductDao	m_productDao;
	TbCollectionparasDao m_collectionparasDao;
	TbProjectDao m_projectDao;
public:
	RecordSignalService();
	~RecordSignalService();

	/**********************************************************************
	������������Ӽ�¼�ź�����
	���������TbRecordSignal
	***********************************************************************/

	bool AddRecordSignal(TbRecordSignal recordSignal);
	/**********************************************************************
	�������������ݲ�ѯ������ѯ���еļ�¼����
	��������� ��Ŀ���� ����Ʒ���ƣ�ת�٣��źŲɼ�ʱ�䣬�ź�
	�ɼ�ʱ�䣺�źŵļ��ϡ�
	�� �� ֵ��Result����
	����˵������ѯ���������ļ�����Ҫ��Բ�Ʒ���ͺź�ת�ٽ��в�ѯ
	***********************************************************************/
	bool FindAllRecordSignalBySearchCondition(TbRecordSignal searchEntity, vector<TbRecordSignal> &signalVector);
};

