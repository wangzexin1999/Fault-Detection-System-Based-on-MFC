#pragma once
#include"TbRecordSignal.h"
#include"TbRecordSignalDao.h"
class RecordSignalService
{

protected:
	TbRecordSignalDao m_recordSignalDao;

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
};

