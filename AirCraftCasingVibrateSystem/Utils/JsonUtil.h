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
#include "include/rapidjson/document.h"
#include "include/rapidjson/writer.h"
#include "include/rapidjson/stringbuffer.h"
#include "Result.h"
#include "TbSensor.h"
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
	功能描述：从json格式的字符串中拿到指定key的Value对象
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	static Result GetValueFromJsonString(CString jsonString, CString key, Value & value);



	/**********************************************************************
	功能描述：将sensor对象封装成一个json格式的dom树Value
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	static Result ConvertSensor2Value(TbSensor sensor,Value & value);



};

