#pragma once
#include "PDSQL.h"
#include "PDAttribute.h"
#include <vector>
#include "AirCraftCasingVibrateSystem.h"
using namespace std;

class PDDatabase
{
public:
	PDDatabase();
	void operator=(const PDDatabase &dbDatabase);
	~PDDatabase();
	CString m_strTableName;//ÿ�����Ӧ�ı����
	int m_iInsertCount;//��Ӧ�����ֶθ���,��ʱ����
	PDAttribute *m_key = NULL;//����

	//����Vectorָ���������ֶ����͡�����
	void SetVectorAndField(CString strSqlword, CString strKind, PDAttribute &word);
	//��ն���
	void ClearObjectExceptId();

	//--------------------------��ѯ----------------------------------
	//ͨ��������ѯ
	bool SelectByKey();
	bool SelectByKey(vector<PDAttribute *> select);
	//��ѯ���������ĵ�һ������
	bool SelectOneObjectByCondition(CString strSqlQueryWhere);

	//--------------------------����----------------------------------
	//ͨ����������
	bool UpdateByKey();
	bool UpdateByKey(vector<PDAttribute *> update);
	//ͨ����������
	bool UpdateByCondition(CString strSqlQueryWhere, bool bIsUpdateKeyId = false);
	bool UpdateByCondition(int &iUpdatedNumber, CString strSqlQueryWhere, bool bIsUpdateKeyId = false);
	bool UpdateByCondition(vector<PDAttribute *> update, CString strSqlQueryWhere, bool bIsUpdateKeyId = false);
	bool UpdateByCondition(vector<PDAttribute *> update, int &iUpdatedNumber, CString strSqlQueryWhere, bool bIsUpdateKeyId = false);
	
	//--------------------------ɾ��----------------------------------
	//ͨ������ɾ��
	bool DeleteByKey();
	//ͨ������ɾ��
	bool DeleteByCondition(CString strSqlQueryWhere);
	bool DeleteByCondition(int &iDeletedNumber, CString strSqlQueryWhere);
	
	//--------------------------����----------------------------------
	//����
	bool Insert(bool bIsInsertKeyId = false);
	bool Insert(int &iGetFirstId, bool bIsInsertKeyId = false);
	
	//--------------------------����----------------------------------
	//�ж��Ƿ��������
	bool JudgeTableIsNull();
	bool JudgeTableIsNull(int &iGetDataCountNumber);

	//ͨ��������ȡ����
	bool GetKeyId(CString &key, CString strSqlQueryWhere);
	bool GetKeyIdList(vector<CString> &keyList, CString strSqlQueryWhere, int iStartNumber = 0, int iRecordCount = 0);
	bool GetKeyId(CString &key, initializer_list<PDAttribute *> part);//weice
	bool GetKeyIdList(vector<CString> &keyList, initializer_list<PDAttribute *> part, int iStartNumber = 0, int iRecordCount = 0);//weice


protected:
	//��ѯ���з��������Ķ�����Ҫ����ʹ�ã�û�ÿ�ָ�롣�о�ʵ�ֲ��ˣ�
	bool SelectObjectsByCondition(vector<vector<CString>> &selectedValueVector, CString strSqlQueryWhere = "");
	bool SelectObjectsByCondition(vector<vector<CString>> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere = "");
	
private:
	vector<PDAttribute *> m_allFieldsVector;//���ȫ���ֶ�ָ�롣
	CString m_strSqlQuery = "";//���ݿ�������insql_str
	CString m_strSelectOneObjectByCondition = "";//�жϲ�ѯ�ǰ������黹�ǰ�����
	//���ڵ�����ɾ��ĺ���
	bool DBSelect(vector<PDAttribute *> selectVector, CString strSqlQueryWhere, int iStartNumber, int iRecordCount, vector<vector<CString>> &selectedValueVector);
	bool DBUpdate(vector<PDAttribute *> update, int &iUpdatedNumber, CString strSqlQueryWhere, bool bIsUpdateKeyId);
	bool DBDelete(int &iDeletedNumber, CString strSqlQueryWhere);
	bool DBInsert(int &iGetFirstId, bool bIsInsertKeyId);
};

