#pragma once
#include"TbProduct.h"
#include <vector>
#include <atlstr.h>
using namespace std;
class TbTestlocation
{
public:
	TbTestlocation();
	TbTestlocation(int locationId, TbProduct product, CString locationName, int productTypeId);
	~TbTestlocation();
private:
	int m_locationId;
	TbProduct m_product;
	CString m_locationName;
	int  m_productTypeId;
public:
	int GetLocationId();
	void SetLocationId(int locationId);

	TbProduct & GetProduct();
	void SetProduct(TbProduct product);

	CString GetLocationName();
	void SetLocationName(CString locationName);

	int GetProductTypeId();
	void SetProductTypeId(int productTypeId);
};