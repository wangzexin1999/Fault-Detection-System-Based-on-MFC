#pragma once
#include "SmartArray.h"
#include <string.h>
#include <vector>

using namespace std;

class RealTimeSignal
{
public:
	RealTimeSignal(vector<double> realTimeSignalVal, vector<CString> realTimeSignalTime);
	~RealTimeSignal();


	
public:
	vector<double>& GetRealTimeSignalData();
	void SetRealTimeSignalData(vector<double> val);
	vector<CString> &GetRealTimeSignalTime();
	void SetRealTimeSignalTime(vector<CString> val);
	
private:
	vector<double> m_realTimeSignalData; //时域信号数值
	vector<CString> m_realTimeSignalTime;//时域信号时间

};

