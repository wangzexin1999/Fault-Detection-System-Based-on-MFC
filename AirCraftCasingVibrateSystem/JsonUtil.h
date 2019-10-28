/************************************************************************
Copyright (C), 2018-2020. 哈尔滨理工大学人工智能实验室
文件名称： JsonUtil.h
内容摘要： 封装json的。对应的实现类文件为JsonUtil.cpp。
其它说明： 抽象了Json一些
当前版本： 1.0
作 者： 刘望
创建日期： 2019-10-27
完成日期:
History:
1. Date:    2019-10-27         Author:马善涛
Modification:
修改记录 1： // 修改历史记录，包括修改日期、修改者及修改内容
修改日期：
版 本 号：
修 改 人：
修改内容：
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

