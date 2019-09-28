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
	if (isSuccess) return Result(true, "�������ݼ���ʧ��");
	return Result(false, "�������ݼ���ʧ��");
}
Result SignalController::SaveSampleSignal(TbRecordSignal m_recordSignal){
	bool isSuccess = m_recordSignalService.AddRecordSignal(m_recordSignal);
	if (isSuccess) return Result(true,"�������ݱ���ɹ�");
	return Result(false, "�������ݱ���ʧ��");
}
Result SignalController::FindAllSignalBySearchCondition(TbSignal searchEntity, vector<TbSignal> &signalVector){
	bool isSuccess = m_signalService.GetAllSignalBySearchCondition(searchEntity, signalVector);
	if (isSuccess) return Result(true, "�ɼ����ݲ�ѯ�ɹ�");
	return Result(false, "�ɼ����ݲ�ѯʧ��");
}
