#include "stdafx.h"
#include "ProductController.h"


ProductController::ProductController()
{
}


ProductController::~ProductController()
{
}
Result ProductController::FindAllProduct(vector<TbProduct> & productVec){

	bool flag = m_productService.GetAllProductBySearchCondition(TbProduct(), productVec);
	if (flag){
		return Result(true, "产品加载成功");
	}
	else{
		return Result(false, "产品加载失败");
	}
}