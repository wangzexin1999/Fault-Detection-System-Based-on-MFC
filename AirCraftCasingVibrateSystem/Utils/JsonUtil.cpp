#include "stdafx.h"
#include "JsonUtil.h"

Document JsonUtil::m_document;

JsonUtil::JsonUtil()
{
}

JsonUtil::~JsonUtil()
{
}
Result JsonUtil::GetValueFromJsonString(CString jsonString, CString key, Value & value){
	m_document.Parse(jsonString);
	if (m_document.HasParseError()){ return Result(false, "Json字符串格式错误"); }
	if (!m_document.HasMember(key)){ return Result(false,"Json中找不到该元素"); }
	value = m_document[key.GetString()];
	return Result(true,"成功解析json");
}

Result JsonUtil::ConvertChannel2Value(TbChannel channel, Value & value){
	Value root(kObjectType);
	Value channelCode;
	Value channelDesc;
	Value collectionparasId;
	//Value sensorStatus;
	Value  mileageRange;
	channelCode.SetString(channel.GetChannelCode(), m_document.GetAllocator());
	channelDesc.SetString(channel.GetChannelDesc(), m_document.GetAllocator());
	collectionparasId.SetInt(channel.GetCollectionparasId());
	mileageRange.SetInt(channel.GetMileageRange());

	root.AddMember("channelCode", channelCode, m_document.GetAllocator());
	root.AddMember("channelDesc", channelDesc, m_document.GetAllocator());
	root.AddMember("collectionparasId", collectionparasId, m_document.GetAllocator());
	root.AddMember("mileageRange", mileageRange, m_document.GetAllocator());
	value = move(root);
	return Result(true, "成功解析json");
}
void JsonUtil::ConvertValue2Channel(Value & value, TbChannel & channel){
	Value::ConstMemberIterator itr = value.FindMember("channelCode");
	if (itr != value.MemberEnd()) 
		channel.SetChannelCode(itr->value.GetString());
	itr = value.FindMember("channelDesc");
	if (itr != value.MemberEnd()) 
		channel.SetChannelDesc(itr->value.GetString());
	itr = value.FindMember("collectionparasId");
	if (itr != value.MemberEnd())	
		channel.SetCollectionparasId(itr->value.GetInt());
	itr = value.FindMember("mileageRange");
	if (itr != value.MemberEnd())
		channel.SetMileageRange(itr->value.GetInt());
}


void JsonUtil::ConvertCollectionparas2Value(TbCollectionparas collectionparas, Value & value){
	Value id;
	Value root(kObjectType);
	Value equipmentId;
	equipmentId.SetString(collectionparas.GetEquipmentId(), m_document.GetAllocator());

	//Value sampleFrequency(kObjectType);
	//m_document.Parse(collectionparas.GetSampleFrequency().GetDictValue());
	//sampleFrequency.CopyFrom(m_document,m_document.GetAllocator());
	//id.SetInt(collectionparas.GetSampleFrequency().GetDictId());
	//sampleFrequency.AddMember("id",id, m_document.GetAllocator());

	//Value analysisFrequency;
	//m_document.Parse(collectionparas.GetAnalysisFrequency().GetDictValue());
	//analysisFrequency.CopyFrom(m_document, m_document.GetAllocator());
	//id.SetInt(collectionparas.GetAnalysisFrequency().GetDictId());
	//analysisFrequency.AddMember("id", id, m_document.GetAllocator());

	//root.AddMember("sampleFrequency", sampleFrequency, m_document.GetAllocator());
	//root.AddMember("analysisFrequency", analysisFrequency, m_document.GetAllocator());
	value = move(root);

}
CString JsonUtil::GetStringFromDom(const Value &dom){
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	dom.Accept(writer);
	std::string result = buffer.GetString();
	return result.c_str();
}

