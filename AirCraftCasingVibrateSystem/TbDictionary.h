#pragma once
class TbDictionary
{
private:
	int m_dictId;
	CString m_dictName;
	CString m_dictValue;
public:
	TbDictionary();
	~TbDictionary();
	
	void SetDictValue(CString dictValue);
	void SetDictName(CString dictName);
	void SetDictId(int  dictId);

	int GetDictId();
	CString GetDictName();
	CString GetDictValue();
};

