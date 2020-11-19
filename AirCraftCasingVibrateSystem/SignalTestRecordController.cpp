#include "stdafx.h"
#include "SignalTestRecordController.h"
SignalTestRecordController::SignalTestRecordController()
{

}
SignalTestRecordController::~SignalTestRecordController()
{

}

Result SignalTestRecordController::AddSignalTestRecord(TbSignalTestRecord signalTestRecord)
{
	bool flag = m_SignalTestRecordService.AddSignalTestRecord(signalTestRecord);
	if (flag){
		return Result(true, "信号测试记录加载成功");
	}
	else{
		return Result(false, "信号测试记录加载失败");
	}

}
Result SignalTestRecordController::UpdateSignalTestRecord(TbSignalTestRecord signalTestRecord)
{
	bool flag = m_SignalTestRecordService.UpdateSignalTestRecord(signalTestRecord);
	if (flag){
		return Result(true, "信号测试记录更新成功");
	}
	else{
		return Result(false, "信号测试记录更新失败");
	}

}