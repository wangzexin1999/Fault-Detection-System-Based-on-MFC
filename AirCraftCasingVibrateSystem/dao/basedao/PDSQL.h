#pragma once
#include "mysql.h"
#include <vector>
using namespace std;
class PDSQL
{
public:
	PDSQL(void);
	~PDSQL(void);
	MYSQL m_mysql;
	int OpenSql();
	void CloseMysql();
	void SetMysql(CString strIp, CString strUser, CString strPassword, CString strDatabase, int iPort = 3306);
	
	bool SelectMysql(vector<vector<CString>> &selectedValueVector, CString strSqlQuery);
	bool SelectMysqlCount(int &iReceiveNumber, CString strSqlQuery);
	bool SelectMysqlOneFiled(vector<CString> &selectedValue, CString strSqlQuery);
	bool InsertMysql(int &iReceiveNumber, CString strSqlQuery);
	bool UpdateMysql(int &iReceiveNumber, CString strSqlQuery);
	bool DeleteMysql(int &iReceiveNumber, CString strSqlQuery);
	bool QueryMysql(int &iReceiveNumber, CString strSqlQuery);

private:
	CString m_strMyIp, m_strMyUser, m_strMyPassword, m_strMyDatabase;
	int m_iPort;
	
};

