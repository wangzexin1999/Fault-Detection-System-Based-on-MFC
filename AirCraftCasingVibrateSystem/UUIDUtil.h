/************************************************************************
�ļ����ƣ� UUIDUtil.h
����ժҪ�� UUID����������ࡣ��Ӧ��ʵ�����ļ�ΪUUIDUtil.cpp��
����˵���� �������uuid��������
************************************************************************/
#pragma once
#include <objbase.h>
#include <stdio.h>
#include "Result.h"
#define GUID_LEN 64

class UUIDUtil
{
public:

	static Result GetUUID(CString &uuid);


};

