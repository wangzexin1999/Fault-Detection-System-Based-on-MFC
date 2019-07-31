#include "stdafx.h"
#include "TbSignalDao.h"

TbSignalDao::TbSignalDao()
{
	this->m_strTableName = "tb_signal";
	m_key = &m_signalId;;
	SetVectorAndField("signal_id", "int", m_signalId);
	SetVectorAndField("start_time", "CString", m_startTime);
	SetVectorAndField("end_time", "CString", m_endTime);
	SetVectorAndField("signal_type", "CString", m_signalType);
	SetVectorAndField("sensorpara_id", "int", m_sensorParaId);
	SetVectorAndField("detecteddevice_id", "int", m_detectedDeviceId);
	SetVectorAndField("signal_status", "char", m_signalStatus);
	SetVectorAndField("data_url", "CString", m_dataUrl);
}

TbSignalDao::TbSignalDao(const TbSignalDao & signal){

	this->m_strTableName = "tb_signal";
	m_key = &m_signalId;;
	SetVectorAndField("signal_id", "int", m_signalId);
	SetVectorAndField("start_time", "CString", m_startTime);
	SetVectorAndField("end_time", "CString", m_endTime);

	SetVectorAndField("signal_type", "CString", m_signalType);
	SetVectorAndField("sensorpara_id", "int", m_sensorParaId);

	SetVectorAndField("detecteddevice_id", "int", m_detectedDeviceId);
	SetVectorAndField("signal_status", "char", m_signalStatus);
	SetVectorAndField("data_url", "CString", m_dataUrl);
	operator = (signal);
}

TbSignalDao::~TbSignalDao()
{

}
