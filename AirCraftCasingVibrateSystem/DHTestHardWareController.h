#pragma once
#include <iostream>
#include "Common.h"
#include <vector>
#include "Result.h"
#include "Constdefine.h"
#include "CDHTestHardWare.h"
#include <list>
#include "TbChannel.h"
#include "CommonUtil.h"
class DHTestHardWareController
{
public:
	struct ChannelParam
	{
		int ChannelStyle;
		int ChannelID;
		int CellID;
	};

	DHTestHardWareController();
	~DHTestHardWareController();
	vector<stuHardChannel> m_vecHardChannel;			//通道信息
	vector<stuGroupChannel> m_vecGroupChannel;			//通道组信息

	/**********************************************************************
	功能描述： 得到所有通道,格式:采集卡的序列号-通道号。
	其它说明：注意，为了方便用户查看通道，这里将通道号和采集卡的序列号从零开始。所以真实的采集卡序列号是
	***********************************************************************/
	void GetChannelCodes(const vector<stuHardChannel> &vecHardChannel, std::vector<CString> &channelCodes);


	void GetAllGroupChannel(CDHTestHardWare *pHardWare, vector<stuGroupChannel> &vecGroupChannel, vector<stuHardChannel> &vecHardChannel, CString  strChannel = "");

	void GetChannelParam(const vector<stuHardChannel> &vecHardChannel, int nID, ChannelParam &ChanParam);

	Result SetChannelFullvalue(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, CString channelCode, CString strParamValue, int curSel);

	Result SetChannelUpfreq(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, CString channelCode, CString strParamValue, int curSel);

	Result SetChannelInputmode(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel,  CString channelCode, CString strParamValue, int curSel);

	Result SetChannelElcPressure(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel,  CString channelCode, CString strParamValue, int curSel);

	Result SetSensorMessureType(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, CString channelCode, CString strParamValue, int curSel);

	Result SetSensorEF(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel,  CString channelCode, CString strParamValue);


	Result SetChannelParam(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, TbChannel &channel);

	

	
	


	void GetAllFullValue(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, string strMachineIP, vector<string> &result);

	void GetAllUpFreq(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, string strMachineIP, vector<string> &result);

	void GetAllInputMode(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, string strMachineIP, vector<string> &result);

	void GetAllElcPressure(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, string strMachineIP, vector<string> &result);

	void GetAllMessaueType(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, string strMachineIP, vector<string> &result);

	void GetDefaultSensorEF(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, string strMachineIP, string &result);

	void GetDefaultInputMode(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, string strMachineIP, string &result);

	void GetDefaultFullValue(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, string strMachineIP, string &result);

	void GetDefaultUpFreq(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, string strMachineIP, string &result);

	void GetDefaultElcPressure(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, string strMachineIP, string &result);

	void GetDefaultMessaueType(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, string strMachineIP, string &result);

	void GetSampleFreqList(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, vector<int> &result);

	void GetSampleParam(CDHTestHardWare *pHardWare, stuSampleParam &sampleParam);

	
private:

	const int SHOW_CHANNEL_USE = 3; 	/// 通道使用标志
	const int SHOW_CHANNEL_MEASURETYPE = 4; /// 通道测量类型1
	const int SHOW_CHANNEL_FULLVALUE = 5; 	/// 满度量程1
	const int SHOW_CHANNEL_SENSECOEF = 6; 	/// 传感器灵敏度1
	const int SHOW_CHANNEL_UPFREQ = 10; 	/// 上限频率1
	const int SHOW_CHANNEL_DOWNFREQ = 11; 	/// 下限频率1
	const int SHOW_CHANNEL_ACQ_INPUTMODE = 12; 	/// 输入方式1
	const int SHOW_CHANNEL_ANTIFILTER = 14; 	/// 抗混滤波器
	//////////////////////////////////////////////////////////////////////////
	// 应变应力
	const int SHOW_STRAIN_SHOWTYPE = 27; 	/// 应变应力显示类型
	const int SHOW_STRAIN_BRIDGETYPE = 28; 	/// 桥路方式
	const int SHOW_STRAIN_GAUGE = 29; 	/// 应变计阻值
	const int SHOW_STRAIN_LEAD = 30; 	/// 导线阻值
	const int SHOW_STRAIN_SENSECOEF = 31; 	/// 灵敏度系数
	const int SHOW_STRAIN_POSION = 32; 	/// 泊松比
	const int SHOW_STRAIN_ELASTICITY = 33; 	/// 弹性模量

	//////////////////////////////////////////////////////////////////////////

	// 桥式传感器
	const int SHOW_CHANNEL_BRIDGE_MODE = 34; 	/// 供桥
	const int SHOW_STRAIN_BRIDGEVOLTAGE = 35; 	/// 桥压
	// 铂电阻测温
	const int SHOW_PT_TYPE = 38; 	/// 铂电阻类型			
	//////////////////////////////////////////////////////////////////////////

	// 热电偶测温
	const int SHOW_THERMO_TYPE = 40; 	/// 热电偶类型
	const int SHOW_THERMO_COOLTEMPERATURE = 41; 	/// 冷端温度

	// 计数器传感器
	const int SHOW_PULSE_EXCHANGE = 61; // AB项交换标志
	const int SHOW_PULSE_SIGNAL_MODE = 62;	/// 信号模式
	const int SHOW_PULSE_X_MODE = 63;	 /// 倍频方式
	const int SHOW_PULSE_RESET_MODE = 64;	 /// 复位方式
	const int SHOW_PULSE_PHA_REVERSE = 65;	 /// PHA反向
	const int SHOW_PULSE_PHB_REVERSE = 66;	 /// PHB反向
	const int SHOW_PULSE_INDEX_REVERSE = 67;	 /// Index反向
	const int SHOW_PULSE_MAX_POS = 70;	 /// 位置计数器最大限制值
	const int SHOW_PULSE_RESET_SET = 72;	/// 复位
	const int SHOW_PULSE_POSCOEF = 74;	 /// 位置系数

	/// 接入传感器类型
	/// </summary>
	const int SHOW_COUNTER_SENSOR_TYPE = 207;

	/// <summary>
	/// 测量量类型
	/// </summary>
	const int SHOW_MEASURE_METERAGE = 80;
	/// <summary>

	//电压测量范围1
	const int SHOW_ELC_PRESSURE = 90;

	/// 隔离类型
	/// </summary>
	const int SHOW_SOLATETYPE = 81;
	/// <summary>
	/// 滤波器类型
	/// </summary>
	const int SHOW_FILTERTYPE = 82;

	const int SAMPLE_ANALOG_DATA = 0;	// 模拟通道数据
	const int SAMPLE_STATIC_DATA = 1;	// 静态通道数据

	/// <summary>
	/// 瞬态记录
	/// </summary>
	const int SAMPLE_MODE_INSTANT = 1;
	/// <summary>
	/// 连续记录
	/// </summary>
	const int SAMPLE_MODE_CONTINUAL = 2;
	/// <summary>
	/// 触发连续
	/// </summary>
	const int SAMPLE_MODE_TRIGCONTINUAL = 3;

	// 采样时钟模式
	const int SAMPLE_CLK_INTER = 0;		//内部采样时钟
	const int SAMPLE_CLK_OUTER = 1;		//外部采样时钟

	std::string CreateChannelKeyString(vector<stuHardChannel> &vecHardChannel);
	long  ModifyParamAndSendCodeSecond(CDHTestHardWare *pHardWare, long lGroupID, LPCTSTR strMachineIP, long ChannelStyle, long ChannelID, long CellID, long ShowParamID, LPCTSTR strParamValue, long nSelectIndex);
	int  BreakString(const string& strSrc, list<string>& lstDest, const string& strSeprator);
	string GetMachineIP(vector<stuHardChannel> &vecHardChannel, int nID);
	Result SetParam(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel,  CString channelCode, int paramType, CString strParamValue, int curSel);
	void GetDefaultParam(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, string strMachineIP, int paramType, string &result);
	int BreakString(const string& strSrc, vector<string>& vecDest, const string& strSeprator);
};