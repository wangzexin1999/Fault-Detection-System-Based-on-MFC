#pragma once

#include"TbTesterDao.h"
#include "TbTester.h"
class TesterService
{
public:
	TesterService();

	~TesterService();

	bool getOneByCondition(TbTester &tester);
<<<<<<< HEAD
	bool getOneById(TbTester &tester);
=======
	/**********************************************************************
	 ���������� 
	 ���������
	 ��������� 
	 �� �� ֵ�� 
	 ����˵����
	 �޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	bool AddTester(TbTester tester);
>>>>>>> d2ee4f8bb3ab259e3eb270f0d4a87a0a6c04302c

protected:

	TbTesterDao m_testerDao;

};

