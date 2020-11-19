#include "stdafx.h"
#include "SignalTestRecordService.h"
#include "DateUtil.h"
#include "FileUtil.h"
SignalTestRecordService::SignalTestRecordService()
{

}
SignalTestRecordService::~SignalTestRecordService()
{

}

bool SignalTestRecordService::AddSignalTestRecord(TbSignalTestRecord signalTestRecord)
{
	m_SignalTestRecordDao.SetTableFieldValues(signalTestRecord);
	bool isSuccess = m_SignalTestRecordDao.Insert();
	return isSuccess;
}
bool SignalTestRecordService::UpdateSignalTestRecord(TbSignalTestRecord signalTestRecord)
{
	m_SignalTestRecordDao.SetTableFieldValues(signalTestRecord);
	bool isSuccess = m_SignalTestRecordDao.UpdateByKey();
	return isSuccess;
}
