#pragma once
class DateUtil
{
public:
	/**********************************************************************
	功能描述： 按照指定格式得到当前的时间
	输入参数： 时间的格式
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	static CString GetCurrentCStringTime(CString format = "%Y-%m-%d %H:%M:%S");
	static CString GetCStringTimeFormCTime(CTime time);
	static CTime & GetAWeekAgoDate();

};

