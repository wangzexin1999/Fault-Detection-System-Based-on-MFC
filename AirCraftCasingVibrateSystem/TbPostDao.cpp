#include "stdafx.h"
#include "TbPostDao.h"

TbPostDao::TbPostDao()
{
	this->m_strTableName = "tb_post";
	m_key = &m_postId;
	SetVectorAndField("post_id", "int", m_postId);
	SetVectorAndField("name", "CString", m_name);
}
TbPostDao::TbPostDao(const TbPostDao &post)
{
	this->m_strTableName = "tb_post";
	m_key = &m_postId;
	SetVectorAndField("post_id", "int", m_postId);
	SetVectorAndField("name", "CString", m_name);
	operator = (post);
}
TbPostDao::~TbPostDao()
{

}
void TbPostDao::SetTableFieldValues(TbPost post)
{
	this->m_postId.SetValue(post.GetPostId());
	this->m_name.SetValue(post.GetName());
}
void TbPostDao::GetTableFieldValues(TbPost &post)
{
	post.SetPostId(m_postId.GetInt());
	post.SetName(m_name.m_strValue);
}

void TbPostDao::SelectByObject(TbPost &post){
	m_postId.SetValue(post.GetPostId());
	bool isSuccess = SelectByKey();
	if (isSuccess){
		GetTableFieldValues(post);
	}
}
bool TbPostDao::SelectObjectsByCondition(vector<TbPostDao> &selectedValueVector, CString strSqlQueryWhere = "")
{
	int iStartNumberIn = 0; int iRecordCountIn = 0;
	return SelectObjectsByCondition(selectedValueVector, iStartNumberIn, iRecordCountIn, strSqlQueryWhere);

}
bool TbPostDao::SelectObjectsByCondition(vector<TbPostDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere = "")
{
	vector<CString> tmpDetectedObjecIDs;
	TbPostDao post;
	if (post.GetKeyIdList(tmpDetectedObjecIDs, strSqlQueryWhere, iStartNumber, iRecordCount))
	{
		for (int iStart = 0; iStart < tmpDetectedObjecIDs.size(); iStart++)
		{
			post.m_postId.m_strValue = tmpDetectedObjecIDs[iStart];
			if (post.SelectByKey())
			{
				selectedValueVector.push_back(post);
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
