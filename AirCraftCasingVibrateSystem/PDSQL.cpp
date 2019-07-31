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
	::CoInitialize(NULL);          //��ʼ��COM����
	try
	{
		//�������Ӷ���ʵ��
		mysql_init(&m_mysql);//��ʼ��
		mysql_options(&m_mysql, MYSQL_SET_CHARSET_NAME, "gbk");
		bool isConnected = mysql_real_connect(&m_mysql, m_strMyIp, m_strMyUser, m_strMyPassword, m_strMyDatabase, m_iPort, 0, 0);//��
		if (isConnected)
		{
			printf("success connected!");
			return 1;
		}
		else
		{
			int i = mysql_errno(&m_mysql);//���ӳ���
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
	mysql_close(&m_mysql);//�ر�sql
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
	selectedValueVector.clear();//��ֹ����ʱ��ֵ
	MYSQL_RES *result;
	MYSQL_ROW sqlRow;
	if (!m_mysql.host)
	{
		OpenSql();
	}
	
	int iResult = mysql_query(&m_mysql, strSqlQuery);//ִ��sql����
	int iErrorNumber = mysql_errno(&m_mysql);
	if (iResult == 0)
	{
		result = mysql_store_result(&m_mysql);//�����ѯ�������ݵ�result
		if (result)
		{
			int iRows = mysql_num_rows(result);		//��������	
			int iFielsds = mysql_num_fields(result);	//��������	
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
	int res = mysql_query(&m_mysql, str);//ִ��sql����
	if (res == 0)
	{
		result = mysql_store_result(&m_mysql);//�����ѯ�������ݵ�result
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
	selectedValue.clear();//��ֹ����ʱ��ֵ
	MYSQL_RES *result;
	MYSQL_ROW sqlRow;
	if (!m_mysql.host)
	{
		OpenSql();
	}
	int iResult = mysql_query(&m_mysql, strSqlQuery);//ִ��sql����
	int iErrorNumber = mysql_errno(&m_mysql);
	if (iResult == 0)
	{
		result = mysql_store_result(&m_mysql);//�����ѯ�������ݵ�result
		if (result)
		{
			int iRows = mysql_num_rows(result);		//��������	
			int iFielsds = mysql_num_fields(result);	//��������	
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
		iReceiveNumber = mysql_insert_id(&m_mysql);//ֻ���ز���ɹ���һ������id
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
