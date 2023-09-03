#pragma once
#include "Result.h"
#include "TbTestlocation.h"
#include "TbTestlocationDao.h"
class TestService
{

private:
	TbTestlocationDao m_testLocationDao;

public:
	TestService();
	~TestService();
	/**********************************************************************
	������������ѯ�ɼ��豸��Ӧ�����д�����
	����������ɼ��豸id
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	bool FindAllTestLocationByProductTypeId(int productTypeId, vector<TbTestlocation> & testLocationVec);

	/**********************************************************************
	������������ѯ�ɼ��豸��Ӧ�����д�����
	����������ɼ��豸id
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	bool GetTestLocationById(int locationId, TbTestlocation &testLoation);


};

