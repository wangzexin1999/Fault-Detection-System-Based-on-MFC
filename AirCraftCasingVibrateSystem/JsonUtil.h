/************************************************************************
Copyright (C), 2018-2020. ����������ѧ�˹�����ʵ����
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
#pragma once
struct Json
{
	CString m_key;
	CString m_value;
};

class JsonUtil
{
public:
	JsonUtil();
	~JsonUtil();
	void GetValue(CString jsonString,CString key);

};

