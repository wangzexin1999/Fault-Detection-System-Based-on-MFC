/************************************************************************
文件名称： UUIDUtil.h
内容摘要： UUID随机数生成类。对应的实现类文件为UUIDUtil.cpp。
其它说明： 随机序列uuid的生成类
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

