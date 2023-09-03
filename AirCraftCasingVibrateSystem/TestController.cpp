#include "stdafx.h"
#include "TestController.h"


TestController::TestController()
{
}


TestController::~TestController()
{
}
Result TestController::FindAllTestLocationByProductId(int productId, vector<TbTestlocation> & testLocationVec){
	// ����ָ����Ʒ��Ӧ�Ĳ�Ʒ�ͺ�
	TbProduct product;
	bool isSuccess = m_productService.GetById(productId, product);
	if (!isSuccess) return Result(isSuccess, "��Ʒ����ʧ��");
	// ���ݲ�Ʒ�ͺŲ���ָ���Ĳ���λ��
	isSuccess = m_testService.FindAllTestLocationByProductTypeId(product.GetProductType().GetId(), testLocationVec);
	if (!isSuccess) return Result(isSuccess, "���λ�ü���ʧ��");
	return Result(isSuccess, "���λ�ü����ɹ�");
}


Result TestController::GetTestLocationById(int locationId, TbTestlocation &testLoation){
	bool isSuccess = m_testService.GetTestLocationById(locationId, testLoation);
	if (!isSuccess) return Result(isSuccess, "���λ�ò�ѯʧ��");
	return Result(isSuccess, "���λ�ü����ɹ�");
}