#include "stdafx.h"
#include "SignalAcquisitionService.h"
#include "DateUtil.h"
#include "FFTWUtil.h"
#include "AirCraftCasingVibrateSystem.h"
SignalAcquisitionService::SignalAcquisitionService()
{

}


SignalAcquisitionService::~SignalAcquisitionService()
{
}

ThreadSafeQueue<AcquiredSignal> & SignalAcquisitionService::GetCollectData(){
	return m_collectData;
}

ThreadSafeQueue<EchoSignal> & SignalAcquisitionService::GetEchoData(){
	return m_echoData;
}
int SignalAcquisitionService::GetCollectDataSize(){
	return m_collectData.size();
}