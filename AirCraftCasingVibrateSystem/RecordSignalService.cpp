#include "stdafx.h"
#include "RecordSignalService.h"


RecordSignalService::RecordSignalService()
{
}


RecordSignalService::~RecordSignalService()
{
}

bool RecordSignalService::AddRecordSignal(TbRecordSignal recordSignal){
	m_recordSignalDao.SetTableFieldValues(recordSignal);
	return	m_recordSignalDao.Insert();
}