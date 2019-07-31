#include "stdafx.h"
#include "PDSQL.h"

PDSQL::PDSQL(void)
{
}

PDSQL::~PDSQL(void)
{
}

int PDSQL::OpenSql()
{
	::CoInitialize(NULL);          //初始化COM环境
	try
	{
		//创建连接对象实例
		mysql_init(&m_mysql);//初始化
		mysql_options(&m_mysql, MYSQL_SET_CHARSET_NAME, "gbk");
		bool isConnected = mysql_real_connect(&m_mysql, m_strMyIp, m_strMyUser, m_strMyPassword, m_strMyDatabase, m_iPort, 0, 0);//连
		if (isConnected)
		{
			printf("success connected!");
			return 1;
		}
		else
		{
			int i = mysql_errno(&m_mysql);//连接出错
			const char * s = mysql_error(&m_mysql);
			printf("failed to connect! Please check for your db service.");
			return -1;
		}
	}
	catch (_com_error e)
	{
		AfxMessageBox(e.Description());
	}
	return -2;
}

void PDSQL::CloseMysql()
{
	mysql_close(&m_mysql);//关闭sql
}

void PDSQL::SetMysql(CString strIp, CString strUser, CString strPassword, CString strDatabase, int iPort)
{
	m_strMyIp = strIp;
	m_strMyUser = strUser;
	m_strMyPassword = strPassword;
	m_strMyDatabase = strDatabase;
	m_iPort = iPort;
}

bool PDSQL::SelectMysql(vector<vector<CString>> &selectedValueVector, CString strSqlQuery)
{
	selectedValueVector.clear();//防止传进时有值
	MYSQL_RES *result;
	MYSQL_ROW sqlRow;
	if (!m_mysql.host)
	{
		OpenSql();
	}
	
	int iResult = mysql_query(&m_mysql, strSqlQuery);//执行sql命令
	int iErrorNumber = mysql_errno(&m_mysql);
	if (iResult == 0)
	{
		result = mysql_store_result(&m_mysql);//保存查询到的数据到result
		if (result)
		{
			int iRows = mysql_num_rows(result);		//数据行数	
			int iFielsds = mysql_num_fields(result);	//数据列数	
			for (int i = 0; i < iRows; i++)
			{
				if (sqlRow = mysql_fetch_row(result))
				{
					vector<CString> setSelectedValueVectorTmp;
					for (int j = 0; j < iFielsds; j++)
					{
						CString setValueTmp;
						setValueTmp.Format("%s", sqlRow[j]);
						if (setValueTmp == "(null)")
						{
							setValueTmp = "";
						}
						setSelectedValueVectorTmp.push_back(setValueTmp);
					}
					selectedValueVector.push_back(setSelectedValueVectorTmp);
				}
			}
			if (result != NULL)
			{
				mysql_free_result(result);
			}
			return true;
		}
		else
		{
			return true;
		}
	}
	else
	{
		CString strError = "";
		strError.Format("%d",iErrorNumber);
		AfxMessageBox("error number is " + strError);
		return false;
	}
}

bool PDSQL::SelectMysqlCount(int &iReceiveNumber, CString str)
{
	MYSQL_RES *result;
	MYSQL_ROW sql_row;
	if (!m_mysql.host)
	{
		OpenSql();
	}
	int res = mysql_query(&m_mysql, str);//执行sql命令
	if (res == 0)
	{
		result = mysql_store_result(&m_mysql);//保存查询到的数据到result
		if (result)
		{
			sql_row = mysql_fetch_row(result);
			iReceiveNumber = atoi(sql_row[0]);
			return true;
		}
		else
		{
			iReceiveNumber = 0;
			return true;
		}
	}
	else
	{
		int iErrorNumber = mysql_errno(&m_mysql);
		CString strError = "";
		strError.Format("%d", iErrorNumber);
		AfxMessageBox("sql error number is " + strError);
		iReceiveNumber = 0;
		return false;
	}
}
bool PDSQL::SelectMysqlOneFiled(vector<CString> &selectedValue, CString strSqlQuery)
{
	selectedValue.clear();//防止传进时有值
	MYSQL_RES *result;
	MYSQL_ROW sqlRow;
	if (!m_mysql.host)
	{
		OpenSql();
	}
	int iResult = mysql_query(&m_mysql, strSqlQuery);//执行sql命令
	int iErrorNumber = mysql_errno(&m_mysql);
	if (iResult == 0)
	{
		result = mysql_store_result(&m_mysql);//保存查询到的数据到result
		if (result)
		{
			int iRows = mysql_num_rows(result);		//数据行数	
			int iFielsds = mysql_num_fields(result);	//数据列数	
			for (int i = 0; i < iRows; i++)
			{
				if (sqlRow = mysql_fetch_row(result))
				{
					CString setValueTmp;
					setValueTmp.Format("%s", sqlRow[0]);
					if (setValueTmp == "(null)")
					{
						setValueTmp = "";
					}
					selectedValue.push_back(setValueTmp);
				}
			}
			if (result != NULL)
			{
				mysql_free_result(result);
			}
			return true;
		}
		else
		{
			return true;
		}
	}
	else
	{
		CString strError = "";
		strError.Format("%d", iErrorNumber);
		AfxMessageBox("error number is " + strError);
		return false;
	}
}

bool PDSQL::InsertMysql(int &iReceiveNumber, CString strSqlQuery)
{
	if (m_mysql.host == "")
	{
		OpenSql();
	}
	int iResult = mysql_query(&m_mysql, strSqlQuery);
	if (iResult == 0)
	{
		iReceiveNumber = mysql_insert_id(&m_mysql);//只返回插入成功第一条数据id
		return true;
	}
	else
	{
		int iErrorNumber = mysql_errno(&m_mysql);
		CString strError = "";
		strError.Format("%d", iErrorNumber);
		AfxMessageBox("sql error number is " + strError);
		return false;
	}
}

bool PDSQL::UpdateMysql(int &iReceiveNumber, CString strSqlQuery)
{
	if (m_mysql.host == "")
	{
		OpenSql();
	}
	int iResult = mysql_query(&m_mysql, strSqlQuery);
	if (iResult == 0)
	{
		iReceiveNumber = mysql_affected_rows(&m_mysql);
		return true;
	}
	else
	{
		int iErrorNumber = mysql_errno(&m_mysql);
		CString strError = "";
		strError.Format("%d", iErrorNumber);
		AfxMessageBox("sql error number is " + strError);
		return false;
	}
}

bool PDSQL::DeleteMysql(int &iReceiveNumber, CString strSqlQuery)
{
	if (m_mysql.host == "")
	{
		OpenSql();
	}
	int iResult = mysql_query(&m_mysql, strSqlQuery);
	if (iResult == 0)
	{
		iReceiveNumber = mysql_affected_rows(&m_mysql);
		return true;
	}
	else
	{
		int iErrorNumber = mysql_errno(&m_mysql);
		CString strError = "";
		strError.Format("%d", iErrorNumber);
		AfxMessageBox("sql error number is " + strError);
		return false;
	}
}


bool PDSQL::QueryMysql(int &iReceiveNumber, CString strSqlQuery)
{
	if (m_mysql.host == "")
	{
		OpenSql();
	}
	int iResult = mysql_query(&m_mysql, strSqlQuery);
	if (iResult == 0)
	{
		iReceiveNumber = mysql_affected_rows(&m_mysql);
		return true;
	}
	else
	{
		return false;
	}
}
