#pragma once
#include "PDDatabase.h"
#include "TbTestingDevicePara.h"

class TbTestingDeviceParaDao :public PDDatabase
{
public:
	TbTestingDeviceParaDao();
	TbTestingDeviceParaDao(const TbTestingDeviceParaDao & testingPara);
	~TbTestingDeviceParaDao();
	void SetTableFieldValues(TbTestingDevicePara testingDevicePara);
	void GetTableFieldValues(TbTestingDevicePara &testingDevicePara);
public:
	PDAttribute m_testingDeviceParaId;
	PDAttribute m_testingdeviceId;
	PDAttribute m_samplingFrequency;
	PDAttribute m_analysisFrequency;
	PDAttribute m_samplingMethod;
	PDAttribute m_triggerMethod;
	PDAttribute m_datablockCount;
	PDAttribute m_delayblockCount;
	PDAttribute m_triggerCount;
	PDAttribute m_samplingBatchs;
};

