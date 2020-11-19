#include "stdafx.h"
#include "TbPost.h"
TbPost::TbPost()
{

}
TbPost::TbPost(int postId, CString name)
{
	SetPostId(postId);
	SetName(name);
}
TbPost::~TbPost()
{

}
int TbPost::GetPostId()
{
	return m_postId;
}

void TbPost::SetPostId(int postId)
{
	this->m_postId = postId;
}

CString TbPost::GetName()
{
	return m_name;
}
void TbPost::SetName(CString name)
{
	this->m_name = name;
}
