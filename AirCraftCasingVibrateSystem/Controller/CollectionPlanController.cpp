#include "stdafx.h"
#include "CollectionPlanController.h"


CollectionPlanController::CollectionPlanController()
{
}


CollectionPlanController::~CollectionPlanController()
{
}
Result CollectionPlanController::FindAllBySearchCondition(vector<TbDictionary> & dictionaryVec, int dictId, CString dictName, CString dictValue){
	bool isSuccess = m_collectionPlanService.GetAllBySearchCondition(dictionaryVec, TbDictionary(dictId, dictName, dictValue));
	if (isSuccess){
		return Result(true, "采集计划查询成功");
	}
	return Result(false, "采集计划查询失败");
}


Result CollectionPlanController::DeleteById(TbDictionary dictionary)
{
	bool isSuccess = m_collectionPlanService.DeleteById(dictionary);
	if (isSuccess){
		return Result(true, "采集计划删除成功");
	}
	return Result(false, "采集计划删除失败");

}


Result CollectionPlanController::Update(TbDictionary dictionary)
{
	bool isSuccess = m_collectionPlanService.UpdateDictionary(dictionary);
	if (isSuccess){
		return Result(true, "采集计划查询成功");
	}
	return Result(false, "采集计划查询失败");

}

Result CollectionPlanController::Add(TbDictionary dictionary)
{
	bool isSuccess = m_collectionPlanService.AddDictionary(dictionary);
	if (isSuccess){
		return Result(true, "采集计划查询成功");
	}
	return Result(false, "采集计划查询失败");

}