#pragma once
class TbTester
{
public:
	TbTester(int testerId = 0, CString loginName = "", CString password = "");
	~TbTester();
	CString GetLoginName();
	CString GetPassWord();
	void SetLoginName(CString loginName);
	void SetPassWord(CString password);
	void SetTesterId(int testerId);
	int GetTesterId();
	CString GetTesterName();
	void SetTesterName(CString realName);
	void SetTesterPost(CString testerPost);
	CString GetTesterPost();
	void SetTesterTelephone(CString telephone);
	CString GetTesterTelephone();

protected:

	int m_testerId;
	CString m_loginName;
	CString m_Password;
	CString m_testerName;
	CString m_testerPost;
	CString m_testerTelephone;
};

