#include "stdafx.h"
#include "DictionaryService.h"
#include "CommonUtil.h"

DictionaryService::DictionaryService()
{
}


DictionaryService::~DictionaryService()
{
}

bool DictionaryService::GetAllBySearchCondition(vector<TbDictionary> & dictionaryVec, TbDictionary searchEntity){
	CString whereSql = "1 = 1 ";
	if (searchEntity.GetDictId() != 0){ whereSql += " and dict_id = '" + CommonUtil::Int2CString(searchEntity.GetDictId()) +"'"; }
	if (searchEntity.GetDictName() != ""){ whereSql += " and dict_name = '" + searchEntity.GetDictName() + "'"; }
	if (searchEntity.GetDictValue() != ""){ whereSql += " and dict_value = '" + searchEntity.GetDictValue() + "'"; }
	m_dictionaryDao.SetTableFieldValues(searchEntity);
	vector<TbDictionaryDao> dictionaryDaoVec;
	bool isSuccess = m_dictionaryDao.SelectObjectsByCondition(dictionaryDaoVec, whereSql);
	if (isSuccess){
		for (auto dictionaryDao : dictionaryDaoVec){
			TbDictionary dict;
			dictionaryDao.GetTableFieldValues(dict);
			dictionaryVec.push_back(dict);
		}
	}
	return isSuccess;
}