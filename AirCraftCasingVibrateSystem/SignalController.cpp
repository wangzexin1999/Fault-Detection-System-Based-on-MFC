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
		///�����Ŀ����Ϊ��ʱ����ѯģ����ѯ֮�����Ŀid
		vector<TbProject> projectVector;
		m_projectService.GetAllProjectBySearchCondition(0, projectName,"","",projectVector);

	}
	else{
		///��Ŀ��Ϊ��ʱ����ѯ���е���Ŀ��
	}


	/*bool tag = m_signalService.GetAllRecordedSignalBySearchCondition(projectId, signalName, startTime, endTime, signalVector);
	if (tag){
		return Result(true,"�źż��سɹ�");
	}
	else{
		return Result(true, "�źż���ʧ��");
	}*/
	return Result(true, "�źż��سɹ�");
}