#pragma once
#include "TbSignalTestRecordDao.h"
#include "TbSignalTestRecord.h"
class SignalTestRecordService
{
public:
	SignalTestRecordService();
	~SignalTestRecordService();
protected:
	TbSignalTestRecordDao m_SignalTestRecordDao;
public:
	bool AddSignalTestRecord(TbSignalTestRecord signalTestRecord);
	bool UpdateSignalTestRecord(TbSignalTestRecord signalTestRecord);
};