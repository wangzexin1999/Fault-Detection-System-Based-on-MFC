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
		return Result(true, "��Ʒ���سɹ�");
	}
	else{
		return Result(false, "��Ʒ����ʧ��");
	}
}