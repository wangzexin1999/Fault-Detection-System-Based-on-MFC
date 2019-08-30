#include "stdafx.h"
#include "TbProduct.h"


TbProduct::TbProduct(int productId  , CString productName  , CString productType  ){
	m_productId = productId;
	m_productName = productName;
	m_productType = productType;
}


TbProduct::~TbProduct()
{
}

int TbProduct::GetProductId() {
	return m_productId;
}

void TbProduct::SetProductId(int productId) {
	this->m_productId = productId;
}

CString TbProduct::GetProductName() {
	return m_productName;
}

void TbProduct::SetProductName(CString productName) {
	this->m_productName = productName;
}

CString TbProduct::GetProductType() {
	return m_productType;
}
	
void TbProduct::SetProductType(CString productType) {
	this->m_productType = productType;
}