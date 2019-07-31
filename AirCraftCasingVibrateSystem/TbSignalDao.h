#pragma once
#include "PDDatabase.h"
class TbSignalDao :
	public PDDatabase
{
public:
	TbSignalDao();
	~TbSignalDao();
	TbSignalDao(const TbSignalDao & signal);

	PDAttribute m_signalId;
	PDAttribute m_startTime;
	PDAttribute m_endTime;
	PDAttribute m_signalType;
	PDAttribute m_sensorParaId;
	PDAttribute m_detectedDeviceId;
	PDAttribute m_signalStatus;
	PDAttribute m_dataUrl;
};

