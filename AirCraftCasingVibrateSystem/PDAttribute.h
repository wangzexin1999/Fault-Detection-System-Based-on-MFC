#pragma once
class PDAttribute
{
public:
	PDAttribute();
	PDAttribute(const PDAttribute &dbAttribute);
	//void operator=(const PDAttribute &dbAttribute);
	~PDAttribute();
public:
	CString m_strSqlField;//��Ӧ���ݿ����ֶ�
	CString m_strValue;//����ֵ
	void CreateSQLWord(CString strSqlField, CString strKind);//�������ݿ��ֶκ���������
	
	//��ʽת��	
	void SetValue(double dValue);//����double����ֵ
	void SetValue(float fValue);//����float����ֵ
	void SetValue(int iValue);//����int����ֵ
	void SetValue(CString strValue);//����CString����ֵ	
	int GetInt();//��ȡint���͵�ֵ
	float GetFloatOrDouble();//��ȡfloat����double���͵�ֵ
private:
	CString m_strKind;//��������
};

