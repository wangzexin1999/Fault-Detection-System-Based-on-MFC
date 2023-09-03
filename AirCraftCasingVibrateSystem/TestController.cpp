#include "stdafx.h"
#include "TestController.h"


TestController::TestController()
{
}


TestController::~TestController()
{
}
Result TestController::FindAllTestLocationByProductId(int productId, vector<TbTestlocation> & testLocationVec){
	// 查找指定产品对应的产品型号
	TbProduct product;
	bool isSuccess = m_productService.GetById(productId, product);
	if (!isSuccess) return Result(isSuccess, "产品检索失败");
	// 根据产品型号查找指定的测试位置
	isSuccess = m_testService.FindAllTestLocationByProductTypeId(product.GetProductType().GetId(), testLocationVec);
	if (!isSuccess) return Result(isSuccess, "测点位置检索失败");
	return Result(isSuccess, "测点位置检索成功");
}


Result TestController::GetTestLocationById(int locationId, TbTestlocation &testLoation){
	bool isSuccess = m_testService.GetTestLocationById(locationId, testLoation);
	if (!isSuccess) return Result(isSuccess, "检测位置查询失败");
	return Result(isSuccess, "测点位置检索成功");
}