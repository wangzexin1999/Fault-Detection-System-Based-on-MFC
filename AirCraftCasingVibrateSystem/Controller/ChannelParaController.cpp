#include "stdafx.h"
#include "ChannelParaController.h"
#include "ChannelParaService.h"
ChannelParaController::ChannelParaController(){}
ChannelParaController::~ChannelParaController(){}

////找到指定项目id的所有传感器参数
Result ChannelParaController::FindALLChannelParaByProjectId(TbProject &project){
	vector<TbChannel> vchannel;
	//bool isSuccess = sensorParaService.GetALLSensorParaByProjectId(project.GetProjectId(), vsensor);
	bool isSuccess = channelParaService.GetALLChannelParaByCollectionparasId(project.GetCollectionparas().GetId(), vchannel);
	if (isSuccess){
		project.SetChannelVector(vchannel);
		return Result(true,"加载传感器参数成功");
	}
	return Result(false,"加载传感器参数失败");
}