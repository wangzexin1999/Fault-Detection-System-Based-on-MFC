#include "stdafx.h"
#include "SignalController.h"


SignalController::SignalController()
{
}


SignalController::~SignalController()
{
}

Result SignalController::LoadAllRecordedSignalBySearchCondition(int projectId, CString signalName, CString startTime, CString endTime, vector<TbSignal> &signalVector){
	bool tag = m_signalService.GetAllRecordedSignalBySearchCondition(projectId, signalName, startTime, endTime, signalVector);
	if (tag){
		return Result(true,"�źż��سɹ�");
	}
	else{
		return Result(true, "�źż���ʧ��");
	}
}