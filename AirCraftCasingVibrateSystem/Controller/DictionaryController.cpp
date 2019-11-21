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
		return Result(true,"�ֵ���ѯ�ɹ�");
	}
	return Result(false, "�ֵ���ѯʧ��");
}


Result DictionaryController::DeleteById(TbDictionary dictionary)
{
	bool isSuccess = m_dictionaryService.DeleteById(dictionary);
	if (isSuccess){
		return Result(true, "�ֵ���ѯ�ɹ�");
	}
	return Result(false, "�ֵ���ѯʧ��");

}


Result DictionaryController::UpdateDictionary(TbDictionary dictionary)
{
	bool isSuccess = m_dictionaryService.UpdateDictionary(dictionary);
	if (isSuccess){
		return Result(true, "�ֵ���ѯ�ɹ�");
	}
	return Result(false, "�ֵ���ѯʧ��");

}

Result DictionaryController::AddDictionary(TbDictionary dictionary)
{

	bool isSuccess = m_dictionaryService.AddDictionary(dictionary);
	if (isSuccess){
		return Result(true, "�ֵ���ѯ�ɹ�");
	}
	return Result(false, "�ֵ���ѯʧ��");

}