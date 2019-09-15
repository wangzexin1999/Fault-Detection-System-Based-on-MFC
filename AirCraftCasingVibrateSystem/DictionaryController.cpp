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