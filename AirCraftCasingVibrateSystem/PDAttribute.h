#pragma once
class PDAttribute
{
public:
	PDAttribute();
	PDAttribute(const PDAttribute &dbAttribute);
	//void operator=(const PDAttribute &dbAttribute);
	~PDAttribute();
public:
	CString m_strSqlField;//对应数据库中字段
	CString m_strValue;//数据值
	void CreateSQLWord(CString strSqlField, CString strKind);//设置数据库字段和数据类型
	
	//格式转换	
	void SetValue(double dValue);//设置double类型值
	void SetValue(float fValue);//设置float类型值
	void SetValue(int iValue);//设置int类型值
	void SetValue(CString strValue);//设置CString类型值	
	int GetInt();//获取int类型的值
	float GetFloatOrDouble();//获取float或者double类型的值
private:
	CString m_strKind;//数据类型
};

