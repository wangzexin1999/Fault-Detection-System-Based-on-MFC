#pragma once
#include <string>
using namespace std;
#include <atlstr.h>

#define SHOW_SAMPLE_DATA		WM_USER+1
#define CLOSE_SHOWDATA_WINDOW	WM_USER+2
#define CK_YB_CHECK			WM_USER+31
void GetValidFloatString(string strText, string &strFloat);

// 信号源通道
/// 波形类型
const int SHOW_GENERATOR_WAVE_FORM = 43;
/// 波形电压(幅值)
const int SHOW_GENERATOR_LEVEL = 44;
/// (起始)频率
const int SHOW_GENERATOR_START_FREQ = 45;
/// 相位
const int SHOW_GENERATOR_PHASE = 46;
/// 结束频率
const int SHOW_GENERATOR_END_FREQ = 47;
/// 上升时间
const int SHOW_GENERATOR_UPTIME = 48;
/// 下降时间
const int SHOW_GENERATOR_DOWNTIME = 49;
/// 占空比
const int SHOW_GENERATOR_OCCUPY_SCALE = 50;
/// 周期
const int SHOW_GENERATOR_CYCLE = 51;
/// 文件路径
const int SHOW_GENERATOR_FILEPATH = 52;
/// 系数
const int SHOW_GENERATOR_COIEF = 53;
/// 扫频时间
const int SHOW_GENERATOR_USETIME = 54;
/// 扫频值(扫频速度)
const int SHOW_GENERATOR_SAOVALUE = 55;
/// 扫频方式
const int SHOW_GENERATOR_WIDTHUNIT = 56;

/// 是否允许实时更改频率
const int SHOW_GENERATOR_ALLOWCHANGEFREQ = 57;

/// 信号源频率下限
const int SHOW_GENERATOR_LOWFREQ = 58;

/// 信号源频率上限
const int SHOW_GENERATOR_HIGHFREQ = 59;

// CommonStruct
struct stuSampleParam
{
	/// 采样频率
	float m_fltSampleFrequency;
	/// 采样方式
	int m_nSampleMode;
	/// 采样块大小
	int m_nSampleBlockSize;
	/// 触发方式(瞬态模式下有效)
	int m_nSampleTrigMode;
	/// 延迟点数(瞬态模式下有效)
	int m_nSampleDelayPoints;
	// 采样时钟
	int m_nSampleClkMode;
};

struct stuGroupChannel 
{
	/// 组ID
	int m_GroupID;
	/// 仪器版本,从硬件读取的版本
	string m_Version;
	/// 仪器类型例如5920、5927
	int m_nInstrumentType;
	/// 数采接口类型, PCI, 1394, USB, COM，网络等
	int m_nInterfaceType;
	/// 放大器接口类型
	int m_nAmpInterfaceType;
	/// 仪器IP
	string m_strMachineIP;

	int m_nDataType;	// 保存数据的类型 short、int、float

	// 实际读取的采集的起始通道
	int m_nChannelFirst;
	// 实际读取的采集的通道数
	int m_nChannelNumber;

	stuSampleParam m_SampleParam;
};

struct stuHardChannel
{
	/// 测量类型, 应变、电压、电荷...
	int m_nMeasureType;
	/// 通道风格,模拟通道、外转速通道、CAN通道、GPS通道等
	int m_nChannelStyle;
	/// 通道组ID，多个通道为一组
	int m_nChannelGroupID;
	// 仪器IP
	char m_strMachineIP[32];
	/// 通道ID
	int m_nChannelID;
	/// 单元ID
	int m_nCellID;
	/// 在线标志，由硬件检测，用户不可设置
	BOOL m_bOnlineFlag;

	stuHardChannel::stuHardChannel()
	{
		m_nMeasureType = 0;
		m_nChannelStyle = 0;
		m_nChannelGroupID = 0;
		strcpy_s(m_strMachineIP, "");
		m_nChannelID = 0;
		m_nCellID = 0;
		m_bOnlineFlag = TRUE;
	}
};