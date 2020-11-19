#include "stdafx.h"
#include "ChannelController.h"
#include "AirCraftCasingVibrateSystem.h"
#include "AcquiredSignal.h"

ChannelController::ChannelController(void)
{
}


ChannelController::~ChannelController()
{
	
}
HANDLE  ChannelController::m_popCollectDataQueueMutex = CreateMutex(NULL, FALSE, NULL);

HANDLE  ChannelController::m_popSampleDataQueueMutex = CreateMutex(NULL, FALSE, NULL);


Result ChannelController::SaveCollectionData(CString channelCode, ThreadSafeQueue<AcquiredSignal> &collectionData) {
	TbSumsignal signal;
	signal.SetProjectId(theApp.m_currentProject.GetProjectId());
	signal.SetProductId(theApp.m_currentProject.GetProduct().GetProductId());
	signal.SetCollectionparasId(theApp.m_currentProject.GetCollectionparas().GetId());
	//signal.SetChannels(sensorId);
	//signal.SetCollectionStatus(theApp.m_jsonCollectionStatusPara);
	Result res = m_channelService.AddCollectData(signal, collectionData);
	return res;
}

Result ChannelController::FindAllChannelByCollectionparasId(int collectionparasId, vector<TbChannel> & channelVector){
	channelVector.clear();
	bool isSuccess = m_channelService.GetAllChannelByCollectionparasId(collectionparasId, channelVector);
	if (isSuccess){
		return Result(true,"���ش��������ݳɹ�");
	}
	return Result(false, "���ش���������ʧ��");
}
Result ChannelController::UpdateChannel(TbChannel channel){
	bool isSuccess = m_channelService.Update(channel);
	if (isSuccess){
		return Result(true, "��ӳɹ�");
	}
	return Result(false, "���ʧ��");
}