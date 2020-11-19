#pragma once
class TbUser
{
public:
	TbUser(int userId = 0, CString loginName = "", CString password = "", int Status = 1);
	~TbUser();
	CString GetLoginName();
	CString GetPassWord();
	void SetLoginName(CString loginName);
	void SetPassWord(CString password);
	void SetUserId(int userId);
	int GetUserId();
	CString GetName();
	void SetName(CString realName);
	void SetPost(CString Post);
	CString GetPost();
	void SetTelephone(CString telephone);
	CString GetTelephone();

	void SetStatus(int Status);
	int GetStatus();

protected:

	int m_userId;
	CString m_loginName;
	CString m_Password;
	CString m_Name;
	CString m_Post;
	CString m_Telephone;
	int m_status;

};

