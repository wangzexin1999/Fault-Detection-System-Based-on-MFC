#include "stdafx.h"
#include "JsonUtil.h"


JsonUtil::JsonUtil()
{
}

JsonUtil::~JsonUtil()
{
}
Result JsonUtil::GetValueFromJsonString(CString jsonString, CString key, Value & value){
	Document doc;
	doc.Parse(jsonString);
	if (doc.HasParseError()){ return Result(false, "Json字符串格式错误"); }
	if (!doc.HasMember(key)){ return Result(false,"Json中找不到该元素"); }
	value = std::move(doc[key.GetString()]);
	return Result(true,"成功解析json");
}
