/************************************************************************
文件名称： GeneralParaView.h
内容摘要： 检测设备数据库表对应的实体对象。对应的实现类文件为TbCollectionparas.cpp。
************************************************************************/
#include "TbDictionary.h"
#include <iostream>
#include <utility>
#pragma once
class TbCollectionparas
{
public:
	TbCollectionparas();
	~TbCollectionparas();
	
	bool operator == (TbCollectionparas collectionparas);
	bool operator != (TbCollectionparas collectionparas);
protected:

	int m_id;
	int m_equipmentId;
	std::pair<int, int> m_sampleFrequency;
	TbDictionary m_collectionMethod;
	TbDictionary m_triggerMethod;
	int m_dataBlocks;
	int m_delayBlocks;
	int m_triggerTimes;
	int line;//谱线数
	int m_sampleBatch;

public:
	
	void SetId(int id);
	int GetId(); 
	void SetEquipmentId(int equipmentId);
	int GetEquipmentId();


	void SetLine(int line);
	int GetLine();

	//TbDictionary  & GetSampleFrequency();
	//void SetSampleFrequency(TbDictionary sampleFrequency);
	//TbDictionary  & GetAnalysisFrequency();
	//void SetAnalysisFrequency(TbDictionary analysisFrequency);
	//TbDictionary  & GetCollectionMethod();
	//void SetCollectionMethod(TbDictionary collectionMethod);
	//TbDictionary  & GetCollectionPoint();
	//void SetCollectionPoint(TbDictionary collectionPoint);


	std::pair<int, int> GetSampleFrequency();
	void SetSampleFrequency(std::pair<int, int> sampleFrequency);
	TbDictionary  & GetCollectionMethod();
	void SetCollectionMethod(TbDictionary collectionMethod);

	TbDictionary  & GetTriggerMethod();
	void SetTriggerMethod(TbDictionary triggerMethod);
	int GetSampleBatch();
	void SetSampleBatch(int sampleBatch);



	int GetDataBlocks();
	void SetDataBlocks(int dataBlocks);

	int GetDelayBlocks();
	void SetDelayBlocks(int delayBlocks);

	int GetTriggerTimes();
	void SetTriggerTimes(int triggerTimes);

};

