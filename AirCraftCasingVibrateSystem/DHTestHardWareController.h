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
	vector<stuHardChannel> m_vecHardChannel;			//ͨ����Ϣ
	vector<stuGroupChannel> m_vecGroupChannel;			//ͨ������Ϣ

	/**********************************************************************
	���������� �õ�����ͨ��,��ʽ:�ɼ��������к�-ͨ���š�
	����˵����ע�⣬Ϊ�˷����û��鿴ͨ�������ｫͨ���źͲɼ��������кŴ��㿪ʼ��������ʵ�Ĳɼ������к���
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

	const int SHOW_CHANNEL_USE = 3; 	/// ͨ��ʹ�ñ�־
	const int SHOW_CHANNEL_MEASURETYPE = 4; /// ͨ����������1
	const int SHOW_CHANNEL_FULLVALUE = 5; 	/// ��������1
	const int SHOW_CHANNEL_SENSECOEF = 6; 	/// ������������1
	const int SHOW_CHANNEL_UPFREQ = 10; 	/// ����Ƶ��1
	const int SHOW_CHANNEL_DOWNFREQ = 11; 	/// ����Ƶ��1
	const int SHOW_CHANNEL_ACQ_INPUTMODE = 12; 	/// ���뷽ʽ1
	const int SHOW_CHANNEL_ANTIFILTER = 14; 	/// �����˲���
	//////////////////////////////////////////////////////////////////////////
	// Ӧ��Ӧ��
	const int SHOW_STRAIN_SHOWTYPE = 27; 	/// Ӧ��Ӧ����ʾ����
	const int SHOW_STRAIN_BRIDGETYPE = 28; 	/// ��·��ʽ
	const int SHOW_STRAIN_GAUGE = 29; 	/// Ӧ�����ֵ
	const int SHOW_STRAIN_LEAD = 30; 	/// ������ֵ
	const int SHOW_STRAIN_SENSECOEF = 31; 	/// ������ϵ��
	const int SHOW_STRAIN_POSION = 32; 	/// ���ɱ�
	const int SHOW_STRAIN_ELASTICITY = 33; 	/// ����ģ��

	//////////////////////////////////////////////////////////////////////////

	// ��ʽ������
	const int SHOW_CHANNEL_BRIDGE_MODE = 34; 	/// ����
	const int SHOW_STRAIN_BRIDGEVOLTAGE = 35; 	/// ��ѹ
	// ���������
	const int SHOW_PT_TYPE = 38; 	/// ����������			
	//////////////////////////////////////////////////////////////////////////

	// �ȵ�ż����
	const int SHOW_THERMO_TYPE = 40; 	/// �ȵ�ż����
	const int SHOW_THERMO_COOLTEMPERATURE = 41; 	/// ����¶�

	// ������������
	const int SHOW_PULSE_EXCHANGE = 61; // AB�����־
	const int SHOW_PULSE_SIGNAL_MODE = 62;	/// �ź�ģʽ
	const int SHOW_PULSE_X_MODE = 63;	 /// ��Ƶ��ʽ
	const int SHOW_PULSE_RESET_MODE = 64;	 /// ��λ��ʽ
	const int SHOW_PULSE_PHA_REVERSE = 65;	 /// PHA����
	const int SHOW_PULSE_PHB_REVERSE = 66;	 /// PHB����
	const int SHOW_PULSE_INDEX_REVERSE = 67;	 /// Index����
	const int SHOW_PULSE_MAX_POS = 70;	 /// λ�ü������������ֵ
	const int SHOW_PULSE_RESET_SET = 72;	/// ��λ
	const int SHOW_PULSE_POSCOEF = 74;	 /// λ��ϵ��

	/// ���봫��������
	/// </summary>
	const int SHOW_COUNTER_SENSOR_TYPE = 207;

	/// <summary>
	/// ����������
	/// </summary>
	const int SHOW_MEASURE_METERAGE = 80;
	/// <summary>

	//��ѹ������Χ1
	const int SHOW_ELC_PRESSURE = 90;

	/// ��������
	/// </summary>
	const int SHOW_SOLATETYPE = 81;
	/// <summary>
	/// �˲�������
	/// </summary>
	const int SHOW_FILTERTYPE = 82;

	const int SAMPLE_ANALOG_DATA = 0;	// ģ��ͨ������
	const int SAMPLE_STATIC_DATA = 1;	// ��̬ͨ������

	/// <summary>
	/// ˲̬��¼
	/// </summary>
	const int SAMPLE_MODE_INSTANT = 1;
	/// <summary>
	/// ������¼
	/// </summary>
	const int SAMPLE_MODE_CONTINUAL = 2;
	/// <summary>
	/// ��������
	/// </summary>
	const int SAMPLE_MODE_TRIGCONTINUAL = 3;

	// ����ʱ��ģʽ
	const int SAMPLE_CLK_INTER = 0;		//�ڲ�����ʱ��
	const int SAMPLE_CLK_OUTER = 1;		//�ⲿ����ʱ��

	std::string CreateChannelKeyString(vector<stuHardChannel> &vecHardChannel);
	long  ModifyParamAndSendCodeSecond(CDHTestHardWare *pHardWare, long lGroupID, LPCTSTR strMachineIP, long ChannelStyle, long ChannelID, long CellID, long ShowParamID, LPCTSTR strParamValue, long nSelectIndex);
	int  BreakString(const string& strSrc, list<string>& lstDest, const string& strSeprator);
	string GetMachineIP(vector<stuHardChannel> &vecHardChannel, int nID);
	Result SetParam(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel,  CString channelCode, int paramType, CString strParamValue, int curSel);
	void GetDefaultParam(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, string strMachineIP, int paramType, string &result);
	int BreakString(const string& strSrc, vector<string>& vecDest, const string& strSeprator);
};