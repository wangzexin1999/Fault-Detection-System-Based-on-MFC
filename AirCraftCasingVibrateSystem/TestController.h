#pragma once
#include "Result.h"
#include "TbTestlocationDao.h"
#include "TbTestlocation.h"
#include "ProductService.h"
#include "TestService.h"
class TestController
{

private:
	TestService m_testService;
	ProductService m_productService;
public:
	TestController();

	~TestController();

	/**********************************************************************
	������������ѯָ����Ʒ�����в��λ��
	����������ɼ��豸id
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	Result FindAllTestLocationByProductId(int productId, vector<TbTestlocation> & testLocationVec);


	/**********************************************************************
	������������ѯָ����ŵĲ��λ��
	����������ɼ��豸id
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	Result GetTestLocationById(int locationId, TbTestlocation &testLoation);
};

