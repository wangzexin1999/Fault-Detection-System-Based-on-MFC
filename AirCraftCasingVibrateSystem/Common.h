#pragma once
#include <string>
using namespace std;
#include <atlstr.h>

#define SHOW_SAMPLE_DATA		WM_USER+1
#define CLOSE_SHOWDATA_WINDOW	WM_USER+2
#define CK_YB_CHECK			WM_USER+31
void GetValidFloatString(string strText, string &strFloat);

// �ź�Դͨ��
/// ��������
const int SHOW_GENERATOR_WAVE_FORM = 43;
/// ���ε�ѹ(��ֵ)
const int SHOW_GENERATOR_LEVEL = 44;
/// (��ʼ)Ƶ��
const int SHOW_GENERATOR_START_FREQ = 45;
/// ��λ
const int SHOW_GENERATOR_PHASE = 46;
/// ����Ƶ��
const int SHOW_GENERATOR_END_FREQ = 47;
/// ����ʱ��
const int SHOW_GENERATOR_UPTIME = 48;
/// �½�ʱ��
const int SHOW_GENERATOR_DOWNTIME = 49;
/// ռ�ձ�
const int SHOW_GENERATOR_OCCUPY_SCALE = 50;
/// ����
const int SHOW_GENERATOR_CYCLE = 51;
/// �ļ�·��
const int SHOW_GENERATOR_FILEPATH = 52;
/// ϵ��
const int SHOW_GENERATOR_COIEF = 53;
/// ɨƵʱ��
const int SHOW_GENERATOR_USETIME = 54;
/// ɨƵֵ(ɨƵ�ٶ�)
const int SHOW_GENERATOR_SAOVALUE = 55;
/// ɨƵ��ʽ
const int SHOW_GENERATOR_WIDTHUNIT = 56;

/// �Ƿ�����ʵʱ����Ƶ��
const int SHOW_GENERATOR_ALLOWCHANGEFREQ = 57;

/// �ź�ԴƵ������
const int SHOW_GENERATOR_LOWFREQ = 58;

/// �ź�ԴƵ������
const int SHOW_GENERATOR_HIGHFREQ = 59;

// CommonStruct
struct stuSampleParam
{
	/// ����Ƶ��
	float m_fltSampleFrequency;
	/// ������ʽ
	int m_nSampleMode;
	/// �������С
	int m_nSampleBlockSize;
	/// ������ʽ(˲̬ģʽ����Ч)
	int m_nSampleTrigMode;
	/// �ӳٵ���(˲̬ģʽ����Ч)
	int m_nSampleDelayPoints;
	// ����ʱ��
	int m_nSampleClkMode;
};

struct stuGroupChannel 
{
	/// ��ID
	int m_GroupID;
	/// �����汾,��Ӳ����ȡ�İ汾
	string m_Version;
	/// ������������5920��5927
	int m_nInstrumentType;
	/// ���ɽӿ�����, PCI, 1394, USB, COM�������
	int m_nInterfaceType;
	/// �Ŵ����ӿ�����
	int m_nAmpInterfaceType;
	/// ����IP
	string m_strMachineIP;

	int m_nDataType;	// �������ݵ����� short��int��float

	// ʵ�ʶ�ȡ�Ĳɼ�����ʼͨ��
	int m_nChannelFirst;
	// ʵ�ʶ�ȡ�Ĳɼ���ͨ����
	int m_nChannelNumber;

	stuSampleParam m_SampleParam;
};

struct stuHardChannel
{
	/// ��������, Ӧ�䡢��ѹ�����...
	int m_nMeasureType;
	/// ͨ�����,ģ��ͨ������ת��ͨ����CANͨ����GPSͨ����
	int m_nChannelStyle;
	/// ͨ����ID�����ͨ��Ϊһ��
	int m_nChannelGroupID;
	// ����IP
	char m_strMachineIP[32];
	/// ͨ��ID
	int m_nChannelID;
	/// ��ԪID
	int m_nCellID;
	/// ���߱�־����Ӳ����⣬�û���������
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