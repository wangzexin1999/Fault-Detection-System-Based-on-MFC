/************************************************************************
Copyright (C), 2018-2020. 哈尔滨理工大学人工智能实验室
文件名称： UUIDUtil.h
内容摘要： UUID随机数生成类。对应的实现类文件为UUIDUtil.cpp。
其它说明： 随机序列uuid的生成类
当前版本： 1.0
作 者： 马善涛
创建日期： 2019-11-24
完成日期:
History:
1. Date:    2018-11-24         Author:马善涛
Modification:
修改记录 1： // 修改历史记录，包括修改日期、修改者及修改内容
修改日期：
版 本 号：
修 改 人：
修改内容：
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

