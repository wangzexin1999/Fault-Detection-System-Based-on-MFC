#pragma once
#include "PDDatabase.h"
#include "TbProject.h"
class TbProjectDao :
	public PDDatabase
{
public:
	TbProjectDao();
	TbProjectDao(const TbProjectDao &project);
	~TbProjectDao();
public:
	PDAttribute m_projectId;
	PDAttribute m_testerId;
	PDAttribute m_projectName;
	PDAttribute m_projectCreatetime;
	PDAttribute m_testingDeviceid;
	PDAttribute m_productId;
	PDAttribute m_projectStatus;
	
	void SetTableFieldValues(TbProject project);
	void GetTableFieldValues(TbProject &project);

	bool SelectObjectsByCondition(vector<TbProjectDao> &selectedValueVector, CString strSqlQueryWhere = "");
	bool SelectObjectsByCondition(vector<TbProjectDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere = "");

};

