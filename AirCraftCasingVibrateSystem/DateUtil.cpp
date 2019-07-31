#include "stdafx.h"
#include "DateUtil.h"


DateUtil::DateUtil()
{
}


DateUtil::~DateUtil()
{
}


CString DateUtil::GetCurrentTimeCString(){
	CTime tm;
	tm = CTime::GetCurrentTime();
	return tm.Format("%Y-%m-%d %H:%M:%S");
}

//CString DateUtil::GetCStringTimeFormCDateTimeCtrl(CDateTimeCtrl dateTimeCtrl){
//	CTime ctime;
//	dateTimeCtrl.GetTime(ctime);
//	return ctime.Format("%Y-%m-%d");
//}

CString DateUtil::GetCStringTimeFormCTime(CTime time){
	return time.Format("%Y-%m-%d");
}
CTime & DateUtil::GetAWeekAgoDate(){
	CTime   currentTime = CTime::GetCurrentTime();
	CTimeSpan aweekSpan(7, 0, 0, 0);

	return currentTime - aweekSpan;
}