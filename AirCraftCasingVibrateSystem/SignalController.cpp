#include "stdafx.h"
#include "SignalController.h"


SignalController::SignalController()
{
}


SignalController::~SignalController()
{

}

Result SignalController::FindAllRecordSignalBySearchCondition(TbRecordSignal searchEntity, vector<TbRecordSignal> &signalVector){
	bool isSuccess = m_recordSignalService.FindAllRecordSignalBySearchCondition(searchEntity,signalVector);
	if (isSuccess) return Result(true, "采样数据加载失败");
	return Result(false, "采样数据加载失败");
}
Result SignalController::SaveSampleSignal(TbRecordSignal m_recordSignal){
	bool isSuccess = m_recordSignalService.AddRecordSignal(m_recordSignal);
	if (isSuccess) return Result(true,"采样数据保存成功");
	return Result(false, "采样数据保存失败");
}
Result SignalController::FindAllSignalBySearchCondition(TbSignal searchEntity, vector<TbSignal> &signalVector){
	bool isSuccess = m_signalService.GetAllSignalBySearchCondition(searchEntity, signalVector);
	if (isSuccess) return Result(true, "采集数据查询成功");
	return Result(false, "采集数据查询失败");
}
