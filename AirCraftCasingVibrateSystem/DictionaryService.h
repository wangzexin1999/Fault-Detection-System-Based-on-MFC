/************************************************************************
Copyright (C), 2018-2020. ����������ѧ�˹�����ʵ����
�ļ����ƣ� DictionaryController.h
����ժҪ�� �ֵ�������߼�����������㣬���ڵ�dao ��
����˵�����ɻ���ϻ�񶯼��ϵͳ
��ǰ�汾�� 1.0
�� �ߣ� ������
�������ڣ� 2019-09-09
�������:
History:
1. Date:    2018-09-09         Author:������
Modification:
�޸ļ�¼ 1�� // �޸���ʷ��¼�������޸����ڡ��޸��߼��޸�����
�޸����ڣ�
�� �� �ţ�
�� �� �ˣ�
�޸����ݣ�
************************************************************************/
#pragma once
#include "TbDictionary.h"
#include "TbDictionaryDao.h"

#include <vector>
using namespace  std;
class DictionaryService
{

private:
	TbDictionaryDao m_dictionaryDao;

public:
	DictionaryService();
	~DictionaryService();
	/**********************************************************************
	�����������õ�ָ���ֵ����������ֵ����
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	bool GetAllBySearchCondition(vector<TbDictionary> & dictionaryVec, TbDictionary searchEntity);
};

