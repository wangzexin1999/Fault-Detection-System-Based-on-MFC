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
		return Result(true, "�źŲ��Լ�¼���سɹ�");
	}
	else{
		return Result(false, "�źŲ��Լ�¼����ʧ��");
	}

}
Result SignalTestRecordController::UpdateSignalTestRecord(TbSignalTestRecord signalTestRecord)
{
	bool flag = m_SignalTestRecordService.UpdateSignalTestRecord(signalTestRecord);
	if (flag){
		return Result(true, "�źŲ��Լ�¼���³ɹ�");
	}
	else{
		return Result(false, "�źŲ��Լ�¼����ʧ��");
	}

}