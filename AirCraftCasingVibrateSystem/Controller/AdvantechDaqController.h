
#include <vector>
#include "include/Inc/bdaqctrl.h"
#include "include/Inc/compatibility.h"
#include "Result.h"
using namespace Automation::BDaq;
using namespace std;
#define  USER_BUFFER_LENTH_MAX_PER_CHAN 8000000 //125000000 

#pragma once

///采集卡配置结构体
typedef struct DiveceConfigueInfomation
{
	int			deviceNumber;//设备号，采集卡的编号
	int			channelStart;//开始通道
	int			channelCount;
	double      clockRatePerChan;//采集频率
	int32			sectionLength;//一次从缓冲区取多少个数
	WCHAR       profilePath[256];//可以载入默认的配置文件，这个是路径
	vector<int>	vrgTypes;  //量程
}DevConfParam;



class AdvantechDaqController
{
public:
	AdvantechDaqController();
	~AdvantechDaqController();

	/**********************************************************************
	功能描述： 保存采集数据
	----------------------------------------------------------------------
	***********************************************************************/
	void GetInstalledDevices(ICollection<DeviceTreeNode> *& devices);


	/**********************************************************************
	功能描述： 得到所有通道,格式:采集卡的序列号-通道号。
	其它说明：注意，为了方便用户查看通道，这里将通道号和采集卡的序列号从零开始。所以真实的采集卡序列号是
	***********************************************************************/
	void GetChannels(vector<CString> & channels);


	/**********************************************************************
	功能描述： 配置采集设备
	***********************************************************************/
	void ConfigurateDevice(DevConfParam devConfigPara, WaveformAiCtrl *);


	/**********************************************************************
	功能描述： 获取量程的信息，最大值，最小值，类型。
	***********************************************************************/
	void GetValueRangeInformationByVrgType(MathInterval & rangeY);


	/**********************************************************************
	功能描述： 根据设备号获得量程信息。
	***********************************************************************/
	void GetValueRangeInformationByDeviceNum(int deviceNum,Array<ValueRange>*& ValueRanges);


	/**********************************************************************
	功能描述： 检查采集卡的错误信息
	***********************************************************************/
	void CheckError(ErrorCode error);
};

