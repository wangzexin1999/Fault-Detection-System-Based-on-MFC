#include "stdafx.h"
#include "DateUtil.h"



CString DateUtil::GetCurrentCStringTime(CString format){
	CTime tm;
	tm = CTime::GetCurrentTime();
	return tm.Format(format);
}

CString DateUtil::GetCStringTimeFormCTime(CTime time){
	return time.Format("%Y-%m-%d");
}
CTime & DateUtil::GetAWeekAgoDate(){
	CTime   currentTime = CTime::GetCurrentTime();
	CTimeSpan aweekSpan(7, 0, 0, 0);

	return currentTime - aweekSpan;
}

CString DateUtil::GetTimeStampCString(){
	SYSTEMTIME tmSys;
	GetLocalTime(&tmSys);
	CTime tm3(tmSys);
	__int64 tmDst = __int64(tm3.GetTime()) * 1000 + tmSys.wMilliseconds;
	CString timeStamp;
	_i64toa(tmDst, timeStamp.GetBuffer(100), 10);
	timeStamp.ReleaseBuffer();
	return timeStamp;
}
