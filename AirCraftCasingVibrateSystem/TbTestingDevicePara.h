#pragma once
#include "TbTestingDevice.h"
#include "TbDictionary.h"
class TbTestingDevicePara
{
public:
	TbTestingDevicePara();

	~TbTestingDevicePara();

	int m_testingdeviceparaId;
	
	TbTestingDevice m_testingDevice;
	 
	int m_projetId;
	 
	TbDictionary m_collectionFrequency;

	TbDictionary m_analysisFrequency;

	TbDictionary m_collectionMethod;
	TbDictionary m_triggerMethod;
	TbDictionary m_datablockCount;

	int m_delayblockCount;
	int m_triggerCount;
	int m_collectionBatchs;

	int GetTestingdeviceparaId();

	TbTestingDevice & GetTestingdevice();

	TbDictionary  & GetCollectionFrequency();
	TbDictionary  & GetAnalysisFrequency();
	TbDictionary  & GetCollectionMethod();
	TbDictionary  & GetTriggerMethod();
	TbDictionary  & GetDatablockCount();

	int GetDelayblockCount();
	int GetTriggerCount();
	int GetCollectionBatchs();

	void SetTestingdeviceparaId(int testingdeviceparaId);
	void SetTestingdevice(TbTestingDevice testingDevice);

	void SetCollectionFrequency(TbDictionary collectionFrequency);
	void SetAnalysisFrequency(TbDictionary analysisFrequency);
	void SetCollectionMethod(TbDictionary collectionMethod);
	void SetTriggerMethod(TbDictionary triggerMethod);
	void SetDatablockCount(TbDictionary datablockCount);

	void SetDelayblockCount(int delayblockCount);
	void SetTriggerCount(int triggerCount);
	void SetCollectionBatchs(int collectionBatchs);
};

