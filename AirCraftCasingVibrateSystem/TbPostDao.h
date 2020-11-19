#pragma once
#include "PDDatabase.h"
#include "TbPost.h"
using namespace std;
class TbPostDao :public PDDatabase
{
public:
	TbPostDao();
	TbPostDao(const TbPostDao &post);
	~TbPostDao();

public:
	PDAttribute m_postId;
	PDAttribute m_name;


	void SetTableFieldValues(TbPost post);
	void GetTableFieldValues(TbPost &post);
	void SelectByObject(TbPost &post);

	bool SelectObjectsByCondition(vector<TbPostDao> &selectedValueVector, CString strSqlQueryWhere);
	bool SelectObjectsByCondition(vector<TbPostDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere);

};