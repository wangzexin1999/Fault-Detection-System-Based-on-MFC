#include "stdafx.h"
#include "ProductService.h"
#include "CommonUtil.h"
ProductService::ProductService()
{

}


ProductService::~ProductService()
{
}
bool ProductService::GetAllProductBySearchCondition(TbProduct searchProduct, vector<TbProduct> & productVec){
	CString strSearchCondition = "1=1 ";
	if (searchProduct.GetProductId() != 0){ 
		strSearchCondition += "and product_id = " + CommonUtil::Int2CString(searchProduct.GetProductId()) ; 
	}
	else{
		if (searchProduct.GetProductName() != "") 
				strSearchCondition += "and product_name like '%" + searchProduct.GetProductName()+"%'";
		if (searchProduct.GetProductType() != "")
			strSearchCondition += "and product_type like '%" + searchProduct.GetProductType() + "%'";
	}
	vector<TbProductDao>  productDaoVec;
	bool isSuccess = m_productDao.SelectObjectsByCondition(productDaoVec, strSearchCondition);
	if (isSuccess){
		for (auto productDao : productDaoVec){
			TbProduct product;
			productDao.GetTableFieldValues(product);
			productVec.push_back(product); 
		}
	}
	return isSuccess;
}


bool ProductService::DeletProductByID(TbProduct product)
{

	m_productDao.SetTableFieldValues(product);
	bool isSuccess = m_productDao.DeleteByKey();
	return isSuccess;
}

bool ProductService::UpdateProduct(TbProduct product)
{
	m_productDao.SetTableFieldValues(product);
	bool isSuccess = m_productDao.UpdateByKey();
	return isSuccess;
}

bool ProductService::AddProduct(TbProduct product)
{

	m_productDao.SetTableFieldValues(product);
	bool isSuccess = m_productDao.Insert();
	return isSuccess;

}