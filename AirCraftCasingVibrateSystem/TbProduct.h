#pragma once
class TbProduct
{
public:
	TbProduct(int productId = 0, CString productName = "", CString productType = "");
	~TbProduct();
	
	bool operator == (TbProduct product);

	bool operator != (TbProduct product);

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


