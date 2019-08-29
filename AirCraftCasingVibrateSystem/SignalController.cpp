#include "stdafx.h"
#include "SignalController.h"


SignalController::SignalController()
{
}


SignalController::~SignalController()
{
}

Result SignalController::LoadAllRecordedSignalBySearchCondition(CString projectName, CString productName, CString rotatingSpeed, CString startTime, CString endTime, vector<TbSignal> &signalVector){
	if (projectName != ""){
		///如果项目名不为空时，查询模糊查询之后的项目id
		vector<TbProject> projectVector;
		m_projectService.GetAllProjectBySearchCondition(0, projectName,"","",projectVector);

	}
	else{
		///项目名为空时，查询所有的项目。
	}


	/*bool tag = m_signalService.GetAllRecordedSignalBySearchCondition(projectId, signalName, startTime, endTime, signalVector);
	if (tag){
		return Result(true,"信号加载成功");
	}
	else{
		return Result(true, "信号加载失败");
	}*/
	return Result(true, "信号加载成功");
}