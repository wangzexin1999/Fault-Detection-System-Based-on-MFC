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
		return Result(true, "�ɼ��ƻ���ѯ�ɹ�");
	}
	return Result(false, "�ɼ��ƻ���ѯʧ��");
}


Result CollectionPlanController::DeleteById(TbDictionary dictionary)
{
	bool isSuccess = m_collectionPlanService.DeleteById(dictionary);
	if (isSuccess){
		return Result(true, "�ɼ��ƻ�ɾ���ɹ�");
	}
	return Result(false, "�ɼ��ƻ�ɾ��ʧ��");

}


Result CollectionPlanController::Update(TbDictionary dictionary)
{
	bool isSuccess = m_collectionPlanService.UpdateDictionary(dictionary);
	if (isSuccess){
		return Result(true, "�ɼ��ƻ���ѯ�ɹ�");
	}
	return Result(false, "�ɼ��ƻ���ѯʧ��");

}

Result CollectionPlanController::Add(TbDictionary dictionary)
{
	bool isSuccess = m_collectionPlanService.AddDictionary(dictionary);
	if (isSuccess){
		return Result(true, "�ɼ��ƻ���ѯ�ɹ�");
	}
	return Result(false, "�ɼ��ƻ���ѯʧ��");

}