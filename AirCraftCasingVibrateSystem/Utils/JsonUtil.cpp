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
	if (m_document.HasParseError()){ return Result(false, "Json�ַ�����ʽ����"); }
	if (!m_document.HasMember(key)){ return Result(false,"Json���Ҳ�����Ԫ��"); }
	value = m_document[key.GetString()];
	return Result(true,"�ɹ�����json");
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
	///��������
	//mileageRange.SetInt(channel.GetFullValue());

	root.AddMember("channelCode", channelCode, m_document.GetAllocator());
	root.AddMember("channelDesc", channelDesc, m_document.GetAllocator());
	root.AddMember("collectionparasId", collectionparasId, m_document.GetAllocator());
	root.AddMember("mileageRange", mileageRange, m_document.GetAllocator());
	value = move(root);
	return Result(true, "�ɹ�����json");
}
//�������Է����ˣ���������������
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
	rapidjson::Value dataArray(rapidjson::kArrayType);// ����һ������Ԫ��
	int saveCount = dataQueue.size();
	for (int i = 0; i < saveCount; i++){
		////ѭ���ɼ����ݵĶ���ȥ��������
		shared_ptr<DOUBLE> signal = dataQueue.wait_and_pop();
		dataArray.PushBack(*signal, allocator);	
	}

	jsonDoc.AddMember("CollectionData", dataArray, allocator);

	//�����ַ���
	rapidjson::StringBuffer buffer;
	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
	jsonDoc.Accept(writer);

	std::string strJson = std::string(buffer.GetString());
	return strJson.c_str();

}


void JsonUtil::JsonTest(){

	//����һ�����µ�json��ʽ�ַ�����������
	// {
	// "name":"qfl",
	// "age":20,
	// "letter":["a","b","c"],
	// "location": {"province":"fujian","city":"xiamen","number":16}
	// "book":[{"name":"book1", "isbn":"123"},{"name":"book2","isbn":"456"}],
	// "healthy":true,
	// }

	//����Json��
	rapidjson::Document jsonDoc;    //����һ��domԪ��Document
	rapidjson::Document::AllocatorType &allocator = jsonDoc.GetAllocator(); //��ȡ������
	jsonDoc.SetObject();    //����ǰ��Document����Ϊһ��object��Ҳ����˵������Document��һ��Object���͵�domԪ��

	//�������
	jsonDoc.AddMember("name", "qfl", allocator);    //����ַ���ֵ
	jsonDoc.AddMember("age", 20, allocator);        //���int����ֵ

	//����array
	rapidjson::Value letterArray(rapidjson::kArrayType);//����һ��Array���͵�Ԫ��
	/*letterArray.PushBack(5, allocator);
	letterArray.PushBack(6, allocator);
	letterArray.PushBack(7, allocator);*/
	for (int i = 0; i < 1000; i++){
		letterArray.PushBack(6, allocator);//dataQueue[i]
	}
	jsonDoc.AddMember("letter", letterArray, allocator);    //�������

	//����һ��object
	rapidjson::Value locationObj(rapidjson::kObjectType);//����һ��Object���͵�Ԫ��
	locationObj.AddMember("province", "fujian", allocator);
	locationObj.AddMember("city", "xiamen", allocator);
	locationObj.AddMember("number", 16, allocator);
	jsonDoc.AddMember("location", locationObj, allocator);  //���object��Document��

	//����һ��object����
	rapidjson::Value bookArray(rapidjson::kArrayType);//����һ��Array���͵�Ԫ�أ��������Object
	rapidjson::Value book1(rapidjson::kObjectType); //����book1
	book1.AddMember("name", "book1", allocator);
	book1.AddMember("isbn", "123", allocator);
	bookArray.PushBack(book1, allocator);           //��ӵ�����

	rapidjson::Value book2(rapidjson::kObjectType); //����book2
	book2.AddMember("name", "book2", allocator);
	book2.AddMember("isbn", "456", allocator);
	bookArray.PushBack(book2, allocator);           //��ӵ�����
	jsonDoc.AddMember("book", bookArray, allocator);

	//�������
	jsonDoc.AddMember("healthy", true, allocator);  //���bool����ֵ
	// jsonDoc.AddMember("sports", NULL, allocator);//��ӿ�ֵ,����ᵼ�±���

	//�����ַ���
	rapidjson::StringBuffer buffer;
	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
	jsonDoc.Accept(writer);

	std::string strJson = std::string(buffer.GetString());
	printf("-----���ɵ�Json:\n%s", strJson.c_str());

	//д���ļ�
	std::string strPath = "D:\\pinpu\\JsonFile.txt";
	FILE* myFile = fopen(strPath.c_str(), "wb");  //windowsƽ̨Ҫʹ��wb
	if (myFile)
	{
		fputs(buffer.GetString(), myFile);
		fclose(myFile);
	}

}