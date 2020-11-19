/************************************************************************
文件名称： JsonUtil.h
内容摘要： 封装json的。对应的实现类文件为JsonUtil.cpp。
其它说明： 抽象了Json一些
************************************************************************/
#include "include/rapidjson/document.h"
#include "include/rapidjson/writer.h"
#include "include/rapidjson/rapidjson.h"
#include "include/rapidjson/stringbuffer.h"
#include "Result.h"
#include "TbChannel.h"
#include "TbCollectionparas.h"
#include <iostream>
using namespace std;
using namespace rapidjson;

#pragma once

class JsonUtil
{
private:
	static Document m_document;
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
	功能描述：将channel对象封装成一个json格式的dom树Value
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	static Result ConvertChannel2Value(TbChannel channel, Value & value);


	/**********************************************************************
	功能描述：将json格式的dom树Value封装成一个channel对象
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	static void ConvertValue2Channel(Value & value, TbChannel &channel);

	/**********************************************************************
	功能描述：将channel对象封装成一个json格式的dom树Value
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	static void ConvertCollectionparas2Value(TbCollectionparas collectionparas, Value & value);
	/**********************************************************************
	功能描述：将Value对象解析成json字符串
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	static CString GetStringFromDom(const Value &val);

};

