#pragma once
#include <vector>
#include <atlstr.h>
using namespace std;
class TbPost
{
public:
	TbPost();
	TbPost(int postId = 0, CString name="");
	~TbPost();
private:
	int m_postId;
	CString m_name;
public:
	int GetPostId();
	void SetPostId(int postId);

	CString GetName();
	void SetName(CString name);
};