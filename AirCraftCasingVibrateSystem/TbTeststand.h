#pragma once
#include"TbTestlocation.h"
#include"TbTeststate.h"
#include <vector>
#include <atlstr.h>
using namespace std;
class TbTeststand
{
public:
	TbTeststand();
	TbTeststand(int standId, TbTestlocation testlocation, TbTeststate teststate, double frequency, double peakValue, double grossValue);
	~TbTeststand();
private:
	int m_standId;
	TbTestlocation m_testlocation;
	TbTeststate m_teststate;
	double m_frequency;
	double m_peakValue;
	double m_grossValue;
public:
	int GetStandId();
	void SetStandId(int standId);

	TbTestlocation & GetTestlocation();
	void SetTestlocation(TbTestlocation testlocation);

	TbTeststate & GetTeststate();
	void SetTeststate(TbTeststate teststate);

	double GetFrequency();
	void SetFrequency(double frequency);

	double GetPeakValue();
	void SetPeakValue(double peakValue);

	double GetGrossValue();
	void SetGrossValue(double grossValue);


};