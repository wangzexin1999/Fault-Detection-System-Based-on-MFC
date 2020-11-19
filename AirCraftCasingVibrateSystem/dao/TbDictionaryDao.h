
#pragma once
#include "PDDatabase.h"
#include "TbDictionary.h"
class TbDictionaryDao :
	public PDDatabase
{
public:
	TbDictionaryDao();
	TbDictionaryDao(const TbDictionaryDao  & dictionary);
	~TbDictionaryDao();
public:
	
	PDAttribute m_dictId;

	PDAttribute m_dictName;
	PDAttribute m_dictValue;

	/**********************************************************************
	��������������TbDictionaryDao������ֵ����װ������TbDictionary
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void GetTableFieldValues(TbDictionary &dictionary);
	/**********************************************************************
	��������������TbDictionary������ֵ����װ������TbDictionaryDao
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void SetTableFieldValues(TbDictionary dictionary);
	/**********************************************************************
	��������������������ѯ�ֵ�����
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void SelectByObject(TbDictionary &dictionary);

	/**********************************************************************
	�������������ݲ�ԃ�l����ѯ
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	bool SelectObjectsByCondition(vector<TbDictionaryDao> &selectedValueVector, CString strSqlQueryWhere = "");
	bool SelectObjectsByCondition(vector<TbDictionaryDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere = "");
};

