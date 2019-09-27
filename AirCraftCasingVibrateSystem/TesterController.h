#pragma once
#include"Result.h"
#include"TbTester.h"
#include"TesterService.h"

class TesterController
{

private:
	TesterService m_testerService;
public:
	TesterController();
	~TesterController();


	Result LoginCheck(TbTester &TbTester);
	/**********************************************************************
	 ���������� ����û�
	 ���������
	 ��������� 
	 �� �� ֵ�� 
	 ����˵����
	 �޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	Result AddTester(TbTester tester);
};

