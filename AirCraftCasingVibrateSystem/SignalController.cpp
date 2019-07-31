#include "stdafx.h"
#include "SignalController.h"


SignalController::SignalController()
{
}


SignalController::~SignalController()
{
}

Result SignalController::LoadAllRecordedSignalBySearchCondition(int projectId, CString signalName, CString startTime, CString endTime, vector<TbSignal> &signalVector){
	bool tag;
	if (tag){
		return Result(true,"信号加载成功");
	}
	else{
		return Result(true, "信号加载失败");
	}
}