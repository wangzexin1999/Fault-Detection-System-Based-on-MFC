#pragma once
class DateUtil
{
public:
	DateUtil();
	~DateUtil();

	static CString GetCurrentTimeCString();
	//static CString GetCStringTimeFormCDateTimeCtrl(CDateTimeCtrl dateTimeCtrl);
	static CString GetCStringTimeFormCTime(CTime time);
	static CTime & GetAWeekAgoDate();
};

