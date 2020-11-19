#include "stdafx.h"
#include "TbProduct.h"

TbProduct::TbProduct(int productId, CString productName){
	m_productId = productId;
	m_productName = productName;
}

TbProduct::TbProduct(int productId, CString productName, TbProductType productType){
	this->m_productId = productId;
	this->m_productName = productName;
	this->m_productType = productType;
}

bool TbProduct::operator == (TbProduct product)
{
	bool tag = true;
	if (m_productId != product.GetProductId()) tag = false;
	if (m_productName != product.GetProductName()) tag = false;
	if (m_productType != product.GetProductType())tag = false;
	return tag;
}

bool TbProduct::operator != (TbProduct product){
	return *this == product ? false : true;
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

TbProductType & TbProduct::GetProductType() {
	return this->m_productType;
}
	
void TbProduct::SetProductType(TbProductType productType) {
	this->m_productType = productType;
}