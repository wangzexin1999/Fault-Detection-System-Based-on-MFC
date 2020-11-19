#pragma once
#include"TbProductType.h"
class TbProduct
{
public:
	//TbProduct(int productId = 0, CString productName = "", CString productType = "");
	TbProduct(int productId = 0, CString productName = "");
	TbProduct(int productId, CString productName, TbProductType productType);
	~TbProduct();
	
	bool operator == (TbProduct product);

	bool operator != (TbProduct product);

	int m_productId;
	CString m_productName;
	TbProductType m_productType;

	int GetProductId();
	void SetProductId(int productId);
	CString GetProductName();
	void SetProductName(CString productName);


	void SetProductType(TbProductType productType);
	//CString GetProductType();
	TbProductType & GetProductType();

};


