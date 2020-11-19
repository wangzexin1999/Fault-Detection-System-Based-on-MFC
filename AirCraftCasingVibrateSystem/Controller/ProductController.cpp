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


Result ProductController::DeleteByProductId(TbProduct collectionparas)
{


	bool flag = m_productService.DeletProductByID(collectionparas);
	if (flag){
		return Result(true, "��Ʒ���سɹ�");
	}
	else{
		return Result(false, "��Ʒ����ʧ��");
	}
}


Result ProductController::UpdateProduct(TbProduct product)
{

	bool flag = m_productService.UpdateProduct(product);
	if (flag){
		return Result(true, "��Ʒ���سɹ�");
	}
	else{
		return Result(false, "��Ʒ����ʧ��");
	}

}

Result ProductController::AddProduct(TbProduct product)
{
	bool flag = m_productService.AddProduct(product);
	if (flag){
		return Result(true, "��Ʒ���سɹ�");
	}
	else{
		return Result(false, "��Ʒ����ʧ��");
	}

}


Result ProductController::FindProductByProductName(TbProduct product, vector<TbProduct> &vProduct)
{

	bool flag = m_productService.GetAllProductBySearchCondition(product, vProduct);
	if (flag){
		return Result(true, "��Ʒ���سɹ�");
	}
	else{
		return Result(false, "��Ʒ����ʧ��");
	}

}