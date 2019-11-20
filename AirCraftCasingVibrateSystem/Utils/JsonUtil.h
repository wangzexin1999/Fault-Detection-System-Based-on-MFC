/************************************************************************
Copyright (C), 2018-2020. ������������ѧ�˹�����ʵ����
�ļ����ƣ� JsonUtil.h
����ժҪ�� ��װjson�ġ���Ӧ��ʵ�����ļ�ΪJsonUtil.cpp��
����˵���� ������JsonһЩ
��ǰ�汾�� 1.0
�� �ߣ� ����
�������ڣ� 2019-10-27
�������:
History:
1. Date:    2019-10-27         Author:������
Modification:
�޸ļ�¼ 1�� // �޸���ʷ��¼�������޸����ڡ��޸��߼��޸�����
�޸����ڣ�
�� �� �ţ�
�� �� �ˣ�
�޸����ݣ�
************************************************************************/
#include "include/rapidjson/document.h"
#include "include/rapidjson/writer.h"
#include "include/rapidjson/stringbuffer.h"
#include "Result.h"
using namespace rapidjson;

#pragma once

class JsonUtil
{
private:
	Document m_document;
public:
	JsonUtil();
	~JsonUtil();

	/**********************************************************************
	������������json��ʽ���ַ������õ�ָ��key��Value����
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	static Result GetValueFromJsonString(CString jsonString, CString key, Value & value);

};
