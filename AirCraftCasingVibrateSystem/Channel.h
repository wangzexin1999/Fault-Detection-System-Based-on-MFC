#pragma once

#include <string>
#include <map>
#include <list>
using namespace std;

#import "bin\msxml4.dll"

/// <summary>
/// ͨ����������
/// </summary>
class HardChannel
{
public:
	HardChannel();
	~HardChannel();

public:
	static const string XML_HARDCHANNEL;
	static const string XML_CHANNELSTYLE;
	static const string XML_CHANNELGROUPID;
	static const string XML_MACHINEIP;
	static const string XML_CHANNELID;
	static const string XML_CELLID;
	static const string XML_CHANNELTYPE;
	static const string XML_MEASUERTYPE;
	static const string XML_METERAGETYPE;

	static const string XML_MACHINEID;
	static const string XML_MACCHNID;
	static const string XML_ONLINEFLAG;
	static const string XML_CHANUSEDFLAG;
	static const string XML_FULLVALUE;
	static const string XML_VOLTAGEBASE;
	static const string XML_ADBASE;
	static const string XML_FULLVOLTAGE;
	static const string XML_TRANSFACTOR;
	static const string XML_ADTOMVCOEF;
	static const string XML_ADTOEUCOEF;

	static const int N_CHANNELSTYLE = 0;
	static const int N_GROUPID = 1;
	static const int N_CHANNELID = 2;
	static const int N_CELLID = 3;
	static const int N_CHANNELTYPE = 4;
	static const int N_MEASUERTYPE = 5;
	static const int N_GROUPTYPE = 6;

	static const int N_MACHINEID = 8;
	static const int N_MACCHNID = 9;

	static const int N_ONLINEFLAG = 11;
	static const int N_CHANUSEDFLAG = 12;

	static const int N_FULLVALUE = 22;
	static const int N_VOLTAGEBASE = 23;
	static const int N_ADBASE = 24;
	static const int N_FULLVOLTAGE = 25;
	static const int N_TRANSFACTOR = 26;
	static const int N_ADTOMVCOEF = 27;
	static const int N_ADTOEUCOEF = 29;

	static const int N_MACHINEIP = 37;

	static map<string,int> _Mapkey;

public:
	/// <summary>
	/// ��������, Ӧ�䡢��ѹ�����...
	/// </summary>
	int m_nMeasureType;

	/// <summary>
	/// ͨ�����,ģ��ͨ������ת��ͨ����CANͨ����GPSͨ����
	/// </summary>
	int m_nChannelStyle;

	/// <summary>
	/// ͨ����ID�����ͨ��Ϊһ��
	/// </summary>
	int m_nChannelGroupID;

	// ����IP
	char m_strMachineIP[32];

	/// <summary>
	/// ͨ��ID
	/// </summary>
	int m_nChannelID;

	/// <summary>
	/// ��ԪID
	/// </summary>
	int m_nCellID;

public:
	// ���ز���
	void Load(MSXML2::IXMLDOMNodePtr node);

public:
	// �Ƿ�Ϊ������ͨͨ��
	bool IsCommonChn() const;
	// �Ƿ�Ϊ�ź�Դͨ��
	bool IsSignalChn() const;
	// �Ƿ�Ϊ���ƿ��ź�Դ
	bool IsExtraSignalChn() const;
	// �Ƿ�Ϊ�������ͨ��
	bool IsPulseChn() const;
	// �Ƿ�Ϊת��ͨ��
	bool IsRotateChn() const;
	// �Ƿ�Ϊ���ƿ�ת��
	bool IsExtraRotateChn() const;
	// ����ϵ��
	void CalcChannelCoiefs();

	// �Ƿ�Ϊ����ͨ��
	bool IsMeasureTemperatureChn() const;
	// ��ѧ������������ת��
	float VoltageToPhysicsValue(float dbVoltageVal) const;
};

// ��������
enum MEASURE_TYPE
{
	MEASURE_TYPE_INTERNAL_DA,					// ����������		// CChanGeneralParam
	MEASURE_TYPE_EXTERNAL_DA,					// ����������		// CChanGeneralParam
	MEASURE_TYPE_STRAINMETER,					// Ӧ��Ӧ��			// CStrainChanParam ����ͨ������
	MEASURE_TYPE_SENSOR_PE,						// ��ɴ�����		// CChanGeneralParam
	MEASURE_TYPE_SENSOR_BT,						// ��ʽ������		// CChanGeneralParam
	MEASURE_TYPE_TEMPERATURE_PT,				// ���������		// CPtTemperatureChnParam
	MEASURE_TYPE_TEMPERATURE_THERMO,			// �ȵ�ż����		// CThermoTemperatureChnParam

	MEASURE_TYPE_ROTATE_SPEED,					// ת�ٲ���			// CTachoChnParam
	MEASURE_TYPE_SIGNAL,						// �źŷ�����		// CWaveChanParam

	MEASURE_TYPE_DIF_DC,	                        // �ֱ��
	MEASURE_TYPE_SIN_DC,                           // ����ֱ��
	MEASURE_TYPE_SIN_AC,                           // ���˽���
	MEASURE_TYPE_ICP_INTER,                        // ����ICP
	MEASURE_TYPE_ICP_OUTER,                        // ����ICP
	MEASURE_TYPE_GND,                              // ����˶�·

	MEASURE_TYPE_CURRENT,							// ��������			// CChanGeneralParam

	MEASURE_TWIST_STRAIN,			               // Ӧ��ʽŤ�ز���
	MEASURE_PULSE_COUNTER,			               // �������������
	MEASURE_PRESSURE_TEST,			               // ѹ������
	MEASURE_SPECIAL_TEST,			               // �������
	MEASURE_HEAT_FLOW, 			                   // ��������

	MEASURE_TYPE_LASERDISTANCE,						//������
	MEASURE_TYPE_EXACTATOV,							//���Ӷ�

	MEASUER_TYPE_GPS = 30,							// GPS����
	MEASUER_TYPE_CAN = 31,							// CAN����
};

// ͨ����� 
enum CHANNEL_STYLE
{
	ANALOG_CHANNEL_STYLE,			// ģ��ͨ��
	EXTRATACHO_CHANNEL_STYLE,		// ���ƿ�ת��ͨ��
	EXTRASIGNAL_CHANNEL_STYLE,		// ���ƿ��ź�Դͨ��
	CAN_CHANNEL_STYLE,				// CANͨ��
	GPS_CHANNEL_STYLE,				// GPSͨ��
	EXTRAPLUS_CHANNEL_STYLE,		// ���ƿ�������ͨ��
	AUDIO_CHANNEL_STYLE,			// ��Ƶͨ��
	VIDEO_CHANNEL_STYLE,			// ��Ƶͨ��
};
