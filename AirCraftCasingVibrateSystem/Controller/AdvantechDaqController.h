
#include <vector>
#include "include/Inc/bdaqctrl.h"
#include "include/Inc/compatibility.h"
#include "Result.h"
using namespace Automation::BDaq;
using namespace std;
#define  USER_BUFFER_LENTH_MAX_PER_CHAN 8000000 //125000000 

#pragma once

///�ɼ������ýṹ��
typedef struct DiveceConfigueInfomation
{
	int			deviceNumber;//�豸�ţ��ɼ����ı��
	int			channelStart;//��ʼͨ��
	int			channelCount;
	double      clockRatePerChan;//�ɼ�Ƶ��
	int32			sectionLength;//һ�δӻ�����ȡ���ٸ���
	WCHAR       profilePath[256];//��������Ĭ�ϵ������ļ��������·��
	vector<int>	vrgTypes;  //����
}DevConfParam;



class AdvantechDaqController
{
public:
	AdvantechDaqController();
	~AdvantechDaqController();

	/**********************************************************************
	���������� ����ɼ�����
	----------------------------------------------------------------------
	***********************************************************************/
	void GetInstalledDevices(ICollection<DeviceTreeNode> *& devices);


	/**********************************************************************
	���������� �õ�����ͨ��,��ʽ:�ɼ��������к�-ͨ���š�
	����˵����ע�⣬Ϊ�˷����û��鿴ͨ�������ｫͨ���źͲɼ��������кŴ��㿪ʼ��������ʵ�Ĳɼ������к���
	***********************************************************************/
	void GetChannels(vector<CString> & channels);


	/**********************************************************************
	���������� ���òɼ��豸
	***********************************************************************/
	void ConfigurateDevice(DevConfParam devConfigPara, WaveformAiCtrl *);


	/**********************************************************************
	���������� ��ȡ���̵���Ϣ�����ֵ����Сֵ�����͡�
	***********************************************************************/
	void GetValueRangeInformationByVrgType(MathInterval & rangeY);


	/**********************************************************************
	���������� �����豸�Ż��������Ϣ��
	***********************************************************************/
	void GetValueRangeInformationByDeviceNum(int deviceNum,Array<ValueRange>*& ValueRanges);


	/**********************************************************************
	���������� ���ɼ����Ĵ�����Ϣ
	***********************************************************************/
	void CheckError(ErrorCode error);
};

