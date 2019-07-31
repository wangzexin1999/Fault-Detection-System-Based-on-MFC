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
	CString m_strTableName;//每个类对应的表格名
	int m_iInsertCount;//对应表中字段个数,暂时无用
	PDAttribute *m_key = NULL;//主键

	//设置Vector指针容器和字段类型、名称
	void SetVectorAndField(CString strSqlword, CString strKind, PDAttribute &word);
	//清空对象
	void ClearObjectExceptId();

	//--------------------------查询----------------------------------
	//通过主键查询
	bool SelectByKey();
	bool SelectByKey(vector<PDAttribute *> select);
	//查询符合条件的第一个对象
	bool SelectOneObjectByCondition(CString strSqlQueryWhere);

	//--------------------------更新----------------------------------
	//通过主键更新
	bool UpdateByKey();
	bool UpdateByKey(vector<PDAttribute *> update);
	//通过条件更新
	bool UpdateByCondition(CString strSqlQueryWhere, bool bIsUpdateKeyId = false);
	bool UpdateByCondition(int &iUpdatedNumber, CString strSqlQueryWhere, bool bIsUpdateKeyId = false);
	bool UpdateByCondition(vector<PDAttribute *> update, CString strSqlQueryWhere, bool bIsUpdateKeyId = false);
	bool UpdateByCondition(vector<PDAttribute *> update, int &iUpdatedNumber, CString strSqlQueryWhere, bool bIsUpdateKeyId = false);
	
	//--------------------------删除----------------------------------
	//通过主键删除
	bool DeleteByKey();
	//通过条件删除
	bool DeleteByCondition(CString strSqlQueryWhere);
	bool DeleteByCondition(int &iDeletedNumber, CString strSqlQueryWhere);
	
	//--------------------------插入----------------------------------
	//插入
	bool Insert(bool bIsInsertKeyId = false);
	bool Insert(int &iGetFirstId, bool bIsInsertKeyId = false);
	
	//--------------------------其他----------------------------------
	//判断是否存在数据
	bool JudgeTableIsNull();
	bool JudgeTableIsNull(int &iGetDataCountNumber);

	//通过条件获取主键
	bool GetKeyId(CString &key, CString strSqlQueryWhere);
	bool GetKeyIdList(vector<CString> &keyList, CString strSqlQueryWhere, int iStartNumber = 0, int iRecordCount = 0);
	bool GetKeyId(CString &key, initializer_list<PDAttribute *> part);//weice
	bool GetKeyIdList(vector<CString> &keyList, initializer_list<PDAttribute *> part, int iStartNumber = 0, int iRecordCount = 0);//weice


protected:
	//查询所有符合条件的对象，需要重载使用（没用空指针。感觉实现不了）
	bool SelectObjectsByCondition(vector<vector<CString>> &selectedValueVector, CString strSqlQueryWhere = "");
	bool SelectObjectsByCondition(vector<vector<CString>> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere = "");
	
private:
	vector<PDAttribute *> m_allFieldsVector;//存放全部字段指针。
	CString m_strSqlQuery = "";//数据库操作语句insql_str
	CString m_strSelectOneObjectByCondition = "";//判断查询是按主键查还是按条件
	//类内调用增删查改函数
	bool DBSelect(vector<PDAttribute *> selectVector, CString strSqlQueryWhere, int iStartNumber, int iRecordCount, vector<vector<CString>> &selectedValueVector);
	bool DBUpdate(vector<PDAttribute *> update, int &iUpdatedNumber, CString strSqlQueryWhere, bool bIsUpdateKeyId);
	bool DBDelete(int &iDeletedNumber, CString strSqlQueryWhere);
	bool DBInsert(int &iGetFirstId, bool bIsInsertKeyId);
};

