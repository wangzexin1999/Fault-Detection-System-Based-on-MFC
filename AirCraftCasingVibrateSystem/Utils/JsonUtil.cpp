#include "stdafx.h"
#include "JsonUtil.h"

using namespace std;

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
	//collectionparasId.SetInt(channel.GetCollectionparasId());
	///丢弃！！
	//mileageRange.SetInt(channel.GetFullValue());

	root.AddMember("channelCode", channelCode, m_document.GetAllocator());
	root.AddMember("channelDesc", channelDesc, m_document.GetAllocator());
	root.AddMember("collectionparasId", collectionparasId, m_document.GetAllocator());
	root.AddMember("mileageRange", mileageRange, m_document.GetAllocator());
	value = move(root);
	return Result(true, "成功解析json");
}
//这个类可以放弃了！！！！！！！！
void JsonUtil::ConvertValue2Channel(Value & value, TbChannel & channel){
	Value::ConstMemberIterator itr = value.FindMember("channelCode");
	if (itr != value.MemberEnd()) 
		channel.SetChannelCode(itr->value.GetString());
	itr = value.FindMember("channelDesc");
	if (itr != value.MemberEnd()) 
		channel.SetChannelDesc(itr->value.GetString());
	itr = value.FindMember("collectionparasId");
	//if (itr != value.MemberEnd())	
	//	channel.SetCollectionparasId(itr->value.GetInt());
	itr = value.FindMember("mileageRange");
	//if (itr != value.MemberEnd())
	//	channel.SetFullValue(itr->value.GetInt());
}


void JsonUtil::ConvertCollectionparas2Value(TbCollectionparas collectionparas, Value & value){
	Value id;
	Value root(kObjectType);
	Value equipmentId;
	//equipmentId.SetString(collectionparas.GetEquipmentId(), m_document.GetAllocator());

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

CString JsonUtil::DataSerialize(ThreadSafeQueue<double> &dataQueue){
	
	
	rapidjson::Document jsonDoc;    
	rapidjson::Document::AllocatorType &allocator = jsonDoc.GetAllocator(); 
	jsonDoc.SetObject();
	rapidjson::Value dataArray(rapidjson::kArrayType);// 创建一个数组元素
	int saveCount = dataQueue.size();
	for (int i = 0; i < saveCount; i++){
		////循环采集数据的队列去保存数据
		shared_ptr<DOUBLE> signal = dataQueue.wait_and_pop();
		dataArray.PushBack(*signal, allocator);	
	}

	jsonDoc.AddMember("CollectionData", dataArray, allocator);

	//生成字符串
	rapidjson::StringBuffer buffer;
	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
	jsonDoc.Accept(writer);

	std::string strJson = std::string(buffer.GetString());
	return strJson.c_str();

}


void JsonUtil::JsonTest(){

	//生成一串如下的json格式字符串，并解析
	// {
	// "name":"qfl",
	// "age":20,
	// "letter":["a","b","c"],
	// "location": {"province":"fujian","city":"xiamen","number":16}
	// "book":[{"name":"book1", "isbn":"123"},{"name":"book2","isbn":"456"}],
	// "healthy":true,
	// }

	//生成Json串
	rapidjson::Document jsonDoc;    //生成一个dom元素Document
	rapidjson::Document::AllocatorType &allocator = jsonDoc.GetAllocator(); //获取分配器
	jsonDoc.SetObject();    //将当前的Document设置为一个object，也就是说，整个Document是一个Object类型的dom元素

	//添加属性
	jsonDoc.AddMember("name", "qfl", allocator);    //添加字符串值
	jsonDoc.AddMember("age", 20, allocator);        //添加int类型值

	//生成array
	rapidjson::Value letterArray(rapidjson::kArrayType);//创建一个Array类型的元素
	/*letterArray.PushBack(5, allocator);
	letterArray.PushBack(6, allocator);
	letterArray.PushBack(7, allocator);*/
	for (int i = 0; i < 1000; i++){
		letterArray.PushBack(6, allocator);//dataQueue[i]
	}
	jsonDoc.AddMember("letter", letterArray, allocator);    //添加数组

	//生成一个object
	rapidjson::Value locationObj(rapidjson::kObjectType);//创建一个Object类型的元素
	locationObj.AddMember("province", "fujian", allocator);
	locationObj.AddMember("city", "xiamen", allocator);
	locationObj.AddMember("number", 16, allocator);
	jsonDoc.AddMember("location", locationObj, allocator);  //添加object到Document中

	//生成一个object数组
	rapidjson::Value bookArray(rapidjson::kArrayType);//生成一个Array类型的元素，用来存放Object
	rapidjson::Value book1(rapidjson::kObjectType); //生成book1
	book1.AddMember("name", "book1", allocator);
	book1.AddMember("isbn", "123", allocator);
	bookArray.PushBack(book1, allocator);           //添加到数组

	rapidjson::Value book2(rapidjson::kObjectType); //生成book2
	book2.AddMember("name", "book2", allocator);
	book2.AddMember("isbn", "456", allocator);
	bookArray.PushBack(book2, allocator);           //添加到数组
	jsonDoc.AddMember("book", bookArray, allocator);

	//添加属性
	jsonDoc.AddMember("healthy", true, allocator);  //添加bool类型值
	// jsonDoc.AddMember("sports", NULL, allocator);//添加空值,这里会导致报错

	//生成字符串
	rapidjson::StringBuffer buffer;
	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
	jsonDoc.Accept(writer);

	std::string strJson = std::string(buffer.GetString());
	printf("-----生成的Json:\n%s", strJson.c_str());

	//写到文件
	std::string strPath = "D:\\pinpu\\JsonFile.txt";
	FILE* myFile = fopen(strPath.c_str(), "wb");  //windows平台要使用wb
	if (myFile)
	{
		fputs(buffer.GetString(), myFile);
		fclose(myFile);
	}

}