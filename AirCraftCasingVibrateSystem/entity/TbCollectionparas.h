/************************************************************************
文件名称： GeneralParaView.h
内容摘要： 检测设备数据库表对应的实体对象。对应的实现类文件为TbCollectionparas.cpp。
************************************************************************/
#include "TbDictionary.h"
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
	CString m_equipmentId;
	double m_sampleFrequency;
	double m_analysisFrequency;
	TbDictionary m_collectionMethod;
	TbDictionary m_triggerMethod;
	TbDictionary m_collectionPoint;
	int m_dataBlocks;
	int m_delayBlocks;
	int m_triggerTimes;

	int m_sampleBatch;

public:
	
	void SetId(int id);
	int GetId(); 
	void SetEquipmentId(CString equipmentId);
	CString GetEquipmentId();
	//TbDictionary  & GetSampleFrequency();
	//void SetSampleFrequency(TbDictionary sampleFrequency);
	//TbDictionary  & GetAnalysisFrequency();
	//void SetAnalysisFrequency(TbDictionary analysisFrequency);
	//TbDictionary  & GetCollectionMethod();
	//void SetCollectionMethod(TbDictionary collectionMethod);
	//TbDictionary  & GetCollectionPoint();
	//void SetCollectionPoint(TbDictionary collectionPoint);


	double GetSampleFrequency();
	void SetSampleFrequency(double sampleFrequency);
	double GetAnalysisFrequency();
	void SetAnalysisFrequency(double analysisFrequency);
	TbDictionary  & GetCollectionMethod();
	void SetCollectionMethod(TbDictionary collectionMethod);

	TbDictionary  & GetTriggerMethod();
	void SetTriggerMethod(TbDictionary triggerMethod);
	TbDictionary  & GetCollectionPoint();
	void SetCollectionPoint(TbDictionary collectionPoint);
	int GetSampleBatch();
	void SetSampleBatch(int sampleBatch);



	int GetDataBlocks();
	void SetDataBlocks(int dataBlocks);

	int GetDelayBlocks();
	void SetDelayBlocks(int delayBlocks);

	int GetTriggerTimes();
	void SetTriggerTimes(int triggerTimes);

};

