#include "stdafx.h"
#include "DictionaryController.h"


DictionaryController::DictionaryController()
{
}


DictionaryController::~DictionaryController()
{
}
Result DictionaryController::FindAllBySearchCondition(vector<TbDictionary> & dictionaryVec, int dictId  , CString dictName  , CString dictValue ){
	bool isSuccess = m_dictionaryService.GetAllBySearchCondition(dictionaryVec, TbDictionary(dictId,dictName,dictValue));
	if (isSuccess){
		return Result(true,"字典表查询成功");
	}
	return Result(false, "字典表查询失败");
}


Result DictionaryController::DeleteEUByEUId(TbDictionary dictionary)
{
	bool isSuccess = m_dictionaryService.DeleteEUByEUId(dictionary);
	if (isSuccess){
		return Result(true, "字典表查询成功");
	}
	return Result(false, "字典表查询失败");

}


Result DictionaryController::UpdateDictionary(TbDictionary dictionary)
{
	bool isSuccess = m_dictionaryService.UpdateDictionary(dictionary);
	if (isSuccess){
		return Result(true, "字典表查询成功");
	}
	return Result(false, "字典表查询失败");

}

Result DictionaryController::AddDictionary(TbDictionary dictionary)
{

	bool isSuccess = m_dictionaryService.AddDictionary(dictionary);
	if (isSuccess){
		return Result(true, "字典表查询成功");
	}
	return Result(false, "字典表查询失败");

}