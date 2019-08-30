#pragma once
class TbProduct
{
public:
	TbProduct(int productId = 0, CString productName = "", CString productType = "");
	~TbProduct();
	
	int m_productId;
	CString m_productName;
	CString m_productType;

	int GetProductId();
	void SetProductId(int productId);
	CString GetProductName();
	void SetProductName(CString productName);
	void SetProductType(CString productType);
	CString GetProductType();

};


