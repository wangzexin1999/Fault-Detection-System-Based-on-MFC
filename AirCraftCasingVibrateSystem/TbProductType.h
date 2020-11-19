#pragma once
#include <atlstr.h>
class TbProductType
{
public:
	TbProductType(int Id = 0, CString typeName = "");
	~TbProductType();

	bool operator == (TbProductType productType);

	bool operator != (TbProductType productType);

	int m_Id;
	CString m_typeName;

	int GetId();
	void SetId(int Id);
	CString GetTypeName();
	void SetTypeName(CString typeName);

};
