#pragma once
#include "TbProductDao.h"
#include "TbProduct.h"
class ProductService
{
public:
	TbProductDao m_productDao;

	ProductService();

	~ProductService();

	bool GetAllProductBySearchCondition(TbProduct searchProduct, vector<TbProduct> & productVec);
};

