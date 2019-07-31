#pragma once
#include "PDDatabase.h"
class TbRecordSignalDao :
	public PDDatabase
{
public:
	TbRecordSignalDao();
	TbRecordSignalDao(const TbRecordSignalDao  & signal);
	~TbRecordSignalDao();

	PDAttribute m_signalId;
	PDAttribute m_startTime;
	PDAttribute m_endTime;
	PDAttribute m_signalType;
	PDAttribute m_sensorParaId;
	PDAttribute m_detectedDeviceId;
	PDAttribute m_signalStatus;
	PDAttribute m_dataUrl;

};

