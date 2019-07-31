#include "stdafx.h"
#include "PDDatabase.h"


PDDatabase::PDDatabase()
{
	m_iInsertCount = 0;
}

void PDDatabase::operator = (const PDDatabase &dbDatabase)
{
	for (int i = 0; i < m_allFieldsVector.size(); i++)
	{
		this->m_allFieldsVector[i]->m_strValue = dbDatabase.m_allFieldsVector[i]->m_strValue;
	}
}

PDDatabase::~PDDatabase()
{
	m_key = NULL;
	for (int i = 0; i < m_allFieldsVector.size(); i++)
	{
		m_allFieldsVector[i] = NULL;
	}
	m_allFieldsVector.clear();
}

//���ܣ�������ʼ��ʱ���ã���PDAttribute��sqlword��kind
void PDDatabase::SetVectorAndField(CString strSqlField, CString strKind, PDAttribute &word)
{
	word.CreateSQLWord(strSqlField, strKind);
	m_iInsertCount++;
	m_allFieldsVector.push_back(&word);
}

//��ն���
void PDDatabase::ClearObjectExceptId()
{
	//id������
	for (int i = 1; i < m_allFieldsVector.size(); i++)
	{
		m_allFieldsVector[i]->m_strValue = "";
	}
}

bool PDDatabase::SelectByKey()
{
	return SelectByKey(m_allFieldsVector);
}

bool PDDatabase::SelectByKey(vector<PDAttribute *> select)
{
	vector<vector<CString>> selectedValueByKey;
	int iStartNumber = 0;
	int iRecordCount = 0;
	CString strSqlQueryWhere;
	if (0 == m_strSelectOneObjectByCondition.Compare(""))
	{
		strSqlQueryWhere = m_key->m_strSqlField + " = '" + m_key->m_strValue + "'";
	}
	else
	{
		strSqlQueryWhere = m_strSelectOneObjectByCondition;
	}
	bool endResult;
	if (select.size() == 0)
	{
		AfxMessageBox("��������ȷ������");
		return false;
	}
	else
	{
		//��ֵ
		endResult = DBSelect(select, strSqlQueryWhere, iStartNumber, iRecordCount, selectedValueByKey);
		//��ֵ
		ClearObjectExceptId();
		if (selectedValueByKey.size() != 0)
		{
			for (int i = 0; i < selectedValueByKey[0].size(); i++)
			{
				select[i]->m_strValue = selectedValueByKey[0][i];
			}
		}
	}
	return endResult;
}

bool PDDatabase::SelectOneObjectByCondition(CString strSqlQueryWhere)
{
	m_strSelectOneObjectByCondition = strSqlQueryWhere;
	return SelectByKey(m_allFieldsVector);
}


bool PDDatabase::UpdateByKey()
{
	return UpdateByKey(m_allFieldsVector);
}

bool PDDatabase::UpdateByKey(vector<PDAttribute *> update)
{
	int iUpdatedNumber; //Ϊ�˵��ú��������壬���������ֵΪ1
	bool bIsUpdateKeyId = false;
	if (0 == m_key->m_strValue.Compare(""))
	{
		AfxMessageBox("����ֵΪ�գ������¸�ֵ��");
		return false;
	}
	CString strSqlQueryWhere = m_key->m_strSqlField + " = '" + m_key->m_strValue + "'";
	return DBUpdate(update, iUpdatedNumber, strSqlQueryWhere, bIsUpdateKeyId);
}

bool PDDatabase::UpdateByCondition(CString strSqlQueryWhere, bool bIsUpdateKeyId)
{
	int iUpdatedNumber;
	return UpdateByCondition(m_allFieldsVector, iUpdatedNumber, strSqlQueryWhere, bIsUpdateKeyId);
}

bool PDDatabase::UpdateByCondition(int &iUpdatedNumber, CString strSqlQueryWhere, bool bIsUpdateKeyId)
{
	return UpdateByCondition(m_allFieldsVector, iUpdatedNumber, strSqlQueryWhere, bIsUpdateKeyId);
}

bool PDDatabase::UpdateByCondition(vector<PDAttribute *> update, CString strSqlQueryWhere, bool bIsUpdateKeyId)
{
	int iUpdatedNumber;
	return UpdateByCondition(update, iUpdatedNumber, strSqlQueryWhere, bIsUpdateKeyId);
}

bool PDDatabase::UpdateByCondition(vector<PDAttribute *> update, int &iUpdatedNumber, CString strSqlQueryWhere, bool bIsUpdateKeyId)
{
	return DBUpdate(update, iUpdatedNumber, strSqlQueryWhere, bIsUpdateKeyId);
}

bool PDDatabase::DeleteByKey()
{
	CString strSqlQueryWhere = m_key->m_strSqlField + " = '" + m_key->m_strValue + "'";
	return DeleteByCondition(strSqlQueryWhere);
}

bool PDDatabase::DeleteByCondition(CString strSqlQueryWhere)
{
	int iDeletedNumber;
	return DeleteByCondition(iDeletedNumber, strSqlQueryWhere);
}

bool PDDatabase::DeleteByCondition(int &iDeletedNumber, CString strSqlQueryWhere)
{
	return DBDelete(iDeletedNumber,strSqlQueryWhere);
}

bool PDDatabase::Insert(bool bIsInsertKeyId)
{
	int iGetFirstId;
	return Insert(iGetFirstId, bIsInsertKeyId);
}


bool PDDatabase::Insert(int &iGetFirstId, bool bIsInsertKeyId)
{
	if (DBInsert(iGetFirstId, bIsInsertKeyId))
	{
		m_key->m_strValue.Format("%d", iGetFirstId);
		return true;
	}
	else
	{
		return false;
	}
}

bool PDDatabase::GetKeyId(CString &key, CString strSqlQueryWhere)
{
	int iStartNumber = 0;
	int iRecordCount = 2;
	vector<CString> keyList;
	if (GetKeyIdList(keyList, strSqlQueryWhere, iStartNumber, iRecordCount))
	{
		key = keyList[0];
		return true;
	}
	else
	{
		key = "";
		return false;
	}

}

bool PDDatabase::GetKeyIdList(vector<CString> &keyList, CString strSqlQueryWhere, int iStartNumber, int iRecordCount)
{
	m_strSqlQuery = "SELECT " + m_key->m_strSqlField + " FROM " + m_strTableName + " WHERE " + strSqlQueryWhere;
	CString strStartNumber = "";
	CString strRecordCount = "";
	strStartNumber.Format("%d", iStartNumber);
	strRecordCount.Format("%d", iRecordCount);
	if (iRecordCount != 0)
	{
		m_strSqlQuery += " LIMIT " + strStartNumber + "," + strRecordCount;
	}
	int res = theApp.PDsql.SelectMysqlOneFiled(keyList, m_strSqlQuery);
	if (res > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

////weice
bool PDDatabase::GetKeyId(CString &key, initializer_list<PDAttribute *> part)
{
	CString strSqlQueryWhere = "";
	if (part.size() == 0)
	{
		AfxMessageBox("�����б�Ϊ�գ����������룡");
		return false;
	}
	for (auto ptr = part.begin(); ptr != part.end(); ptr++)
	{
		strSqlQueryWhere += (*ptr)->m_strSqlField + "=" + (*ptr)->m_strValue;
	}
	GetKeyId(key, strSqlQueryWhere);
}

//weice
bool PDDatabase::GetKeyIdList(vector<CString> &keyList, initializer_list<PDAttribute *> part, int iStartNumber, int iRecordCount)
{
	CString strSqlQueryWhere = "";
	if (part.size() == 0)
	{
		AfxMessageBox("�����б�Ϊ�գ����������룡");
		return false;
	}
	for (auto ptr = part.begin(); ptr != part.end(); ptr++)
	{
		strSqlQueryWhere += (*ptr)->m_strSqlField + "=" + (*ptr)->m_strValue;
	}
	GetKeyIdList(keyList, strSqlQueryWhere, iStartNumber, iRecordCount);
}


bool PDDatabase::JudgeTableIsNull()
{
	int iGetDataCountNumber;
	return JudgeTableIsNull(iGetDataCountNumber);
}

bool PDDatabase::JudgeTableIsNull(int &iGetDataCountNumber)
{
	m_strSqlQuery = "SELECT COUNT(*) FROM " + m_strTableName;
	int res = theApp.PDsql.SelectMysqlCount(iGetDataCountNumber, m_strSqlQuery);
	if (res > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool PDDatabase::SelectObjectsByCondition(vector<vector<CString>> &selectedValueVector, CString strSqlQueryWhere)
{
	int iStartNumber = 0; int iRecordCount = 0;
	return SelectObjectsByCondition(selectedValueVector, iStartNumber, iRecordCount, strSqlQueryWhere);
}

bool PDDatabase::SelectObjectsByCondition(vector<vector<CString>> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere)
{
	bool endResult = DBSelect(m_allFieldsVector, strSqlQueryWhere, iStartNumber, iRecordCount, selectedValueVector);
	return endResult;
}

bool PDDatabase::DBSelect(vector<PDAttribute *> selectVector, CString strSqlQueryWhere, int iStartNumber, int iRecordCount, vector<vector<CString>> &selectedValueVector)
{
	m_strSqlQuery = "SELECT ";
	int i;//ƴ���ַ���ѭ������
	bool bResult;
	//ƴ�Ӳ�ѯ�ֶ�
	for (i = 0; i < selectVector.size() - 1; i++)
	{
		m_strSqlQuery += selectVector[i]->m_strSqlField + ",";
	}
	m_strSqlQuery += selectVector[i]->m_strSqlField + " FROM " + this->m_strTableName;
	//ƴ�Ӳ�ѯ����
	if (strSqlQueryWhere != "")
	{
		m_strSqlQuery += " WHERE " + strSqlQueryWhere;
	}
	//ƴ�ӷ�ҳ���//iRecordCount��Ϊ0ʱ���
	if (iRecordCount != 0)
	{
		CString strStartNumber; CString strRecordCount;
		strStartNumber.Format("%d", iStartNumber);
		strRecordCount.Format("%d", iRecordCount);
		m_strSqlQuery += " LIMIT " + strStartNumber + "," + strRecordCount;
	}
	//�ײ��ѯ
	bResult = theApp.PDsql.SelectMysql(selectedValueVector, m_strSqlQuery);
	return bResult;
}

bool PDDatabase::DBUpdate(vector<PDAttribute *> update, int &iUpdatedNumber, CString strSqlQueryWhere, bool bIsUpdateKeyId)
{
	int i;
	if (bIsUpdateKeyId)
	{
		i = 0;
	}
	else
	{
		if (update.size() == m_iInsertCount)
		{
			//��ʱupdate���µ��������ֶΣ���bIsUpdateKeyIdΪfalse��
			//����Ӧ��������һ���ֶΡ���ǡ�ô����ֶε������ֶθ�������Ϊ���ú���������󣬸Ų�����
			i = 1;
		}
		else
		{
			//��ʱupdate���µ��Ǵ����ֶΣ���bIsUpdateKeyIdΪfalse��
			//���Բ���������һ���ֶΣ�����Ҫ��⴫���ֶ��Ƿ���Id�ֶΡ�
			i = 0;
			for (int iCheck = 0; iCheck < update.size(); iCheck++)
			{
				if (0 == update[iCheck]->m_strSqlField.Compare(m_key->m_strSqlField))
				{
					AfxMessageBox("��Ҫ���������ֶΣ�");
					return false;
				}
			}
		}
	}
	//ƴ�Ӹ����ֶ�
	m_strSqlQuery = "UPDATE " + m_strTableName + " SET ";
	for (; i < update.size(); i++)
	{
		if (update[i]->m_strValue == "")
		{
			update[i]->m_strValue = "NULL";
		}
		m_strSqlQuery += update[i]->m_strSqlField + " = '" + update[i]->m_strValue + "',";
	}
	m_strSqlQuery = m_strSqlQuery.Left(m_strSqlQuery.GetLength() - 1);//ɾ�����Ķ���;
	//ƴ�Ӹ�������
	m_strSqlQuery += " WHERE " + strSqlQueryWhere;

	bool bResult = theApp.PDsql.UpdateMysql(iUpdatedNumber, m_strSqlQuery);
	return bResult;
}

bool PDDatabase::DBDelete(int &iDeletedNumber, CString strSqlQueryWhere)
{
	m_strSqlQuery = "DELETE FROM " + m_strTableName;

	m_strSqlQuery += " WHERE " + strSqlQueryWhere;
	bool bResult = theApp.PDsql.DeleteMysql(iDeletedNumber, m_strSqlQuery);
	return bResult;
}

bool PDDatabase::DBInsert(int &iGetFirstId, bool bIsInsertKeyId)
{
	int iField; int iValue;
	m_strSqlQuery = "INSERT INTO " + m_strTableName + "(";
	if (bIsInsertKeyId)
	{
		if (0 == m_key->m_strValue.Compare(""))
		{
			AfxMessageBox("������ֵ,��ȷ�ϲ�����");
			return false;
		}
		else
		{
			iField = 0; iValue = 0;
		}
	}
	else
	{
		iField = 1; iValue = 1;
	}
	//ƴ�Ӳ����ֶΣ��������
	for (; iField < m_allFieldsVector.size(); iField++)
	{
		//ֵ��Ϊ�������
		if (0 != m_allFieldsVector[iField]->m_strValue.Compare(""))
		{
			m_strSqlQuery += m_allFieldsVector[iField]->m_strSqlField + ",";
		}
	}
	m_strSqlQuery = m_strSqlQuery.Left(m_strSqlQuery.GetLength() - 1);//ɾ�����Ķ���
	m_strSqlQuery += ") VALUES ";
	m_strSqlQuery += "(";
	//ƴ�Ӳ���ֵ���������
	for (; iValue < m_allFieldsVector.size(); iValue++)
	{
		if (0 != m_allFieldsVector[iValue]->m_strValue.Compare(""))
		{
			m_strSqlQuery += "'" + m_allFieldsVector[iValue]->m_strValue + "',";
		}
	}
	m_strSqlQuery = m_strSqlQuery.Left(m_strSqlQuery.GetLength() - 1);//ɾ�����Ķ���
	m_strSqlQuery += ")";
	bool bResult = theApp.PDsql.InsertMysql(iGetFirstId, m_strSqlQuery);
	return bResult;
}
