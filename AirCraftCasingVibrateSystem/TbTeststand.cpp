#include "stdafx.h"
#include "TbTeststand.h"
TbTeststand::TbTeststand()
{

}
TbTeststand::TbTeststand(int standId, TbTestlocation testlocation, TbTeststate teststate, double frequency, double peakValue, double grossValue)
{
	SetStandId(standId);
	SetTestlocation(testlocation);
	SetTeststate(teststate);
	SetFrequency(frequency);
	SetPeakValue(peakValue);
	SetGrossValue(grossValue);
}
TbTeststand::~TbTeststand()
{

}
int TbTeststand::GetStandId()
{
	return m_standId;
}
void TbTeststand::SetStandId(int standId)
{
	this->m_standId = standId;
}

TbTestlocation & TbTeststand::GetTestlocation()
{
	return this->m_testlocation;
}
void TbTeststand::SetTestlocation(TbTestlocation testlocation)
{
	this->m_testlocation = testlocation;
}

TbTeststate & TbTeststand::GetTeststate()
{
	return this->m_teststate;
}
void TbTeststand::SetTeststate(TbTeststate teststate)
{
	this->m_teststate = teststate;
}

double TbTeststand::GetFrequency()
{
	return m_frequency;
}
void TbTeststand::SetFrequency(double frequency)
{
	this->m_frequency = frequency;
}

double TbTeststand::GetPeakValue()
{
	return m_peakValue;
}
void TbTeststand::SetPeakValue(double peakValue)
{
	this->m_peakValue = peakValue;
}

double TbTeststand::GetGrossValue()
{
	return m_grossValue;
}
void TbTeststand::SetGrossValue(double grossValue)
{
	this->m_grossValue = grossValue;
}