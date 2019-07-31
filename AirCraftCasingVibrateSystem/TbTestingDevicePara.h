#pragma once
#include "TbTestingDevice.h"
class TbTestingDevicePara
{
public:
	TbTestingDevicePara();

	~TbTestingDevicePara();

	int m_testingdeviceparaId;
	
	TbTestingDevice m_testingDevice;

	int m_projetId;

	int m_samplingFrequency;

	int m_analysisFrequency;

	int m_samplingMethod;
	int m_triggerMethod;
	int m_datablockCount;
	int m_delayblockCount;
	int m_triggerCount;
	int m_samplingBatchs;

	int GetTestingdeviceparaId();
	TbTestingDevice & GetTestingdevice();
	int GetSamplingFrequency();
	int GetAnalysisFrequency();
	int GetSamplingMethod();
	int GetTriggerMethod();
	int GetDatablockCount();
	int GetDelayblockCount();
	int GetTriggerCount();
	int GetSamplingBatchs();

	void SetTestingdeviceparaId(int testingdeviceparaId);
	void SetTestingdevice(TbTestingDevice testingDevice);
	void SetSamplingFrequency(int samplingFrequency);
	void SetAnalysisFrequency(int analysisFrequency);
	void SetSamplingMethod(int samplingMethod);
	void SetTriggerMethod(int triggerMethod);
	void SetDatablockCount(int datablockCount);
	void SetDelayblockCount(int delayblockCount);
	void SetTriggerCount(int triggerCount);
	void SetSamplingBatchs(int samplingBatchs);
};

