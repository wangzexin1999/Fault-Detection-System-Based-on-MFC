#pragma once
#include "PDDatabase.h"
#include "TbLabel.h"
using namespace std;
class TbLabelDao :public PDDatabase
{
public:
	TbLabelDao();
	TbLabelDao(const TbLabelDao &label);
	~TbLabelDao();

public:
	PDAttribute m_labelId;
	PDAttribute m_labelName;
	PDAttribute m_mark;

	void SetTableFieldValues(TbLabel label);
	void GetTableFieldValues(TbLabel &label);

	bool SelectObjectsByCondition(vector<TbLabelDao> &selectedValueVector, CString strSqlQueryWhere = "");
	bool SelectObjectsByCondition(vector<TbLabelDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere = "");

};