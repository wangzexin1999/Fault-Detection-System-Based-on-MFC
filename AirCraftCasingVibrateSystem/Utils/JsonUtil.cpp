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

Result JsonUtil::ConvertSensor2Value(TbSensor sensor, Value & value){
	Value root(kObjectType);
	Value channelId;
	Value channelDesc;
	Value testingDeviceId;
	//Value sensorStatus;
	Value  mileageRange;
	channelId.SetString(sensor.GetChannelId(), m_document.GetAllocator());
	channelDesc.SetString(sensor.GetSensorDesc(), m_document.GetAllocator());
	testingDeviceId.SetInt(sensor.GetTestingdeviceId());
	mileageRange.SetInt(sensor.GetMileageRange());

	root.AddMember("channelId", channelId, m_document.GetAllocator());
	root.AddMember("channelDesc", channelDesc, m_document.GetAllocator());
	root.AddMember("testingDeviceId", testingDeviceId, m_document.GetAllocator());
	root.AddMember("mileageRange", mileageRange, m_document.GetAllocator());
	value = move(root);
	return Result(true, "成功解析json");
}
void JsonUtil::ConvertValue2Sensor(Value & value, TbSensor & sensor){
	Value::ConstMemberIterator itr = value.FindMember("channelId");
	if (itr != value.MemberEnd()) 
			sensor.SetChannelId(itr->value.GetString());
	itr = value.FindMember("channelDesc");
	if (itr != value.MemberEnd()) 
			sensor.SetSensorDesc(itr->value.GetString());
	itr = value.FindMember("testingDeviceId");
	if (itr != value.MemberEnd())	
		sensor.SetTestingdeviceId(itr->value.GetInt());
	itr = value.FindMember("mileageRange");
	if (itr != value.MemberEnd())
		sensor.SetMileageRange(itr->value.GetInt());
}


void JsonUtil::ConvertTestingDevice2Value(TbTestingDevice testingDevice, Value & value){
	Value id;
	Value root(kObjectType);
	Value testingDeviceIp;
	testingDeviceIp.SetString(testingDevice.GetTestingDeviceIp(),m_document.GetAllocator());

	Value sampleFrequency(kObjectType);
	m_document.Parse(testingDevice.GetCollectionFrequency().GetDictValue());
	sampleFrequency.CopyFrom(m_document,m_document.GetAllocator());
	id.SetInt(testingDevice.GetCollectionFrequency().GetDictId());
	sampleFrequency.AddMember("id",id, m_document.GetAllocator());

	Value analysisFrequency;
	m_document.Parse(testingDevice.GetAnalysisFrequency().GetDictValue());
	analysisFrequency.CopyFrom(m_document, m_document.GetAllocator());
	id.SetInt(testingDevice.GetAnalysisFrequency().GetDictId());
	analysisFrequency.AddMember("id", id, m_document.GetAllocator());

	root.AddMember("sampleFrequency", sampleFrequency, m_document.GetAllocator());
	root.AddMember("analysisFrequency", analysisFrequency, m_document.GetAllocator());
	value = move(root);

}
CString JsonUtil::GetStringFromDom(const Value &dom){
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	dom.Accept(writer);
	std::string result = buffer.GetString();
	return result.c_str();
}

