#pragma once
#include "TbChannel.h"
#include <vector>
using namespace std;
class TbAlarmpara
{
public:
	TbAlarmpara();
	TbAlarmpara(int alarmId, double frequency, double peakValue, double grossValue, TbChannel channel, int status);
	~TbAlarmpara();

private:
	int m_alarmId;
	double m_frequency;
	double m_peakValue;
	double m_grossValue;
	TbChannel m_channel;
	int m_status;

public:
	int GetAlarmId();
	void SetAlarmId(int alarmId);

	double GetFrequency();
	void SetFrequency(double frequency);

	double GetPeakValue();
	void SetPeakValue(double peakValue);

	double GetGrossValue();
	void SetGrossValue(double grossValue);

	TbChannel& GetChannel();
	void SetChannel(TbChannel channel);

	int GetStatus();
	void SetStatus(int status);
};