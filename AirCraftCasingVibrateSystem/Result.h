#pragma once
class Result
{
public:

	Result();
	Result(bool isSuccess, CString message);
	~Result();
	bool GetIsSuccess();
	CString GetMessages();

protected:
	bool m_isSuccess;
	CString m_message;

};

