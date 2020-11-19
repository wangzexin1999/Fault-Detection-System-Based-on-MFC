#include "stdafx.h"
#include "TbAlarmpara.h"
TbAlarmpara::TbAlarmpara(int alarmId, double frequency, double peakValue, double grossValue, TbChannel channel, int status){

	SetAlarmId(alarmId);
	SetFrequency(frequency);
	SetPeakValue(peakValue);
	SetGrossValue(grossValue);
	SetChannel(channel);
	SetStatus(status);
}
TbAlarmpara::~TbAlarmpara()
{
}
TbAlarmpara::TbAlarmpara()
{

}
int TbAlarmpara::GetAlarmId()
{
	return m_alarmId;
}
void TbAlarmpara::SetAlarmId(int alarmId)
{
	this->m_alarmId = alarmId;
}

double TbAlarmpara::GetFrequency()
{
	return m_frequency;
}
void TbAlarmpara::SetFrequency(double frequency)
{
	this->m_frequency = frequency;
}

double TbAlarmpara::GetPeakValue()
{
	return m_peakValue;
}
void TbAlarmpara::SetPeakValue(double peakValue)
{
	this->m_peakValue = peakValue;
}

double TbAlarmpara::GetGrossValue()
{
	return m_grossValue;
}
void TbAlarmpara::SetGrossValue(double grossValue)
{
	this->m_grossValue = grossValue;
}

TbChannel & TbAlarmpara::GetChannel()
{
	return this->m_channel;
}
void TbAlarmpara::SetChannel(TbChannel channel)
{
	this->m_channel = channel;
}

int TbAlarmpara::GetStatus()
{
	return m_status;
}
void TbAlarmpara::SetStatus(int status)
{
	this->m_status = status;
}