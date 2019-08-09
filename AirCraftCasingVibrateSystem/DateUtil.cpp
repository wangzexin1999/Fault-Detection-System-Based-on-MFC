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
