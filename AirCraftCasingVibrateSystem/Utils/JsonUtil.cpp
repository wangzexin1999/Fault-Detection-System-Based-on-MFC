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
	if (doc.HasParseError()){ return Result(false, "Json�ַ�����ʽ����"); }
	if (!doc.HasMember(key)){ return Result(false,"Json���Ҳ�����Ԫ��"); }
	value = std::move(doc[key.GetString()]);
	return Result(true,"�ɹ�����json");
}

Result JsonUtil::ConvertSensor2Value(TbSensor sensor, Value & value){
	Value channelId;
	Value channelDesc;
	Value testingDeviceId;
	Value sensorStatus;

	return Result(true, "�ɹ�����json");
}