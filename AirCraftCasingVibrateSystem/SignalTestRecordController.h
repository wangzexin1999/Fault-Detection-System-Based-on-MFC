#pragma once
#include "SignalTestRecordService.h"
#include "Result.h"
class SignalTestRecordController
{

public:
	SignalTestRecordController();
	~SignalTestRecordController();
private:
	SignalTestRecordService m_SignalTestRecordService;
public:
	Result AddSignalTestRecord(TbSignalTestRecord signalTestRecord);
	Result UpdateSignalTestRecord(TbSignalTestRecord signalTestRecord);
};