#pragma once
class AcquiredSignal
{
public:
	AcquiredSignal();
	AcquiredSignal(double signalData, CString acquireTime);
	~AcquiredSignal();
private:
	double m_signalData;
	CString m_acquiredTime;
public:
	void SetSignalData(double signalData);
	void SetAcquireTime(CString acquireTime);

	double GetSignalData();
	CString GetAcquireTime();
};

