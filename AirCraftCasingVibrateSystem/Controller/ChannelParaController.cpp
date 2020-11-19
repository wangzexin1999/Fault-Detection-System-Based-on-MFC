#include "stdafx.h"
#include "ChannelParaController.h"
#include "ChannelParaService.h"
ChannelParaController::ChannelParaController(){}
ChannelParaController::~ChannelParaController(){}

////�ҵ�ָ����Ŀid�����д���������
Result ChannelParaController::FindALLChannelParaByProjectId(TbProject &project){
	vector<TbChannel> vchannel;
	//bool isSuccess = sensorParaService.GetALLSensorParaByProjectId(project.GetProjectId(), vsensor);
	bool isSuccess = channelParaService.GetALLChannelParaByCollectionparasId(project.GetCollectionparas().GetId(), vchannel);
	if (isSuccess){
		project.SetChannelVector(vchannel);
		return Result(true,"���ش����������ɹ�");
	}
	return Result(false,"���ش���������ʧ��");
}