#include "stdafx.h"
#include "TbProductDao.h"


TbProductDao::TbProductDao()
{
	this->m_strTableName = "tb_product";
	m_key = &m_productId;
	SetVectorAndField("product_id", "int", m_productId);
	SetVectorAndField("product_name", "CString", m_productName);
	SetVectorAndField("product_type", "int", m_productType);
}




TbProductDao::~TbProductDao()
{
}
TbProductDao::TbProductDao(const TbProductDao & product){
	this->m_strTableName = "tb_product";
	m_key = &m_productId;
	SetVectorAndField("product_id", "int", m_productId);
	SetVectorAndField("product_name", "CString", m_productName);
	SetVectorAndField("product_type", "int", m_productType);
	operator = (product);
}

bool TbProductDao::SelectObjectsByCondition(vector<TbProductDao> &selectedValueVector, CString strSqlQueryWhere){
	 return SelectObjectsByCondition(selectedValueVector, 0, 0, strSqlQueryWhere);
}

 bool TbProductDao::SelectObjectsByCondition(vector<TbProductDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere){
	 vector<CString> tmpDetectedObjecIDs;
	 TbProductDao product;
	 if (product.GetKeyIdList(tmpDetectedObjecIDs, strSqlQueryWhere, iStartNumber, iRecordCount))
	 {
		 for (int iStart = 0; iStart < tmpDetectedObjecIDs.size(); iStart++)
		 {
			 product.m_productId.m_strValue = tmpDetectedObjecIDs[iStart];
			 if (product.SelectByKey())
			 {
				 selectedValueVector.push_back(product);
			 }
			 else
			 {
				 return false;
			 }
		 }
		 return true;
	 }
	 else
	 {
		 return false;
	 }
}

 void TbProductDao::GetTableFieldValues(TbProduct &product){
	 product.SetProductId(m_productId.GetInt());
	 product.SetProductName(m_productName.m_strValue);
	 //product.SetProductType(m_productType.m_strValue);
	 product.GetProductType().SetId(m_productType.GetInt());
 }

 void TbProductDao::SetTableFieldValues(TbProduct product)
 {
	 m_productId.SetValue(product.GetProductId());
	 m_productName.SetValue(product.GetProductName());
	 //m_productType.SetValue(product.GetProductType());
	 m_productType.SetValue(product.GetProductType().GetId());

 }
