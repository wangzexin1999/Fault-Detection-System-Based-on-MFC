#include "stdafx.h"
#include "AdvantechDaqController.h"
#include "CommonUtil.h"

AdvantechDaqController::AdvantechDaqController()
{

}

AdvantechDaqController::~AdvantechDaqController()
{
}
void AdvantechDaqController::GetInstalledDevices(ICollection<DeviceTreeNode> *& devices){
	DeviceCtrl *devicectrl;
	devices = devicectrl->getInstalledDevices();
}

void  AdvantechDaqController::GetChannels(vector<CString> & channels){
	ICollection<DeviceTreeNode> * devices;
	GetInstalledDevices(devices);
	for (int i = 0; i < devices->getCount(); i++){
		int deviceNum = devices->getItem(i).DeviceNumber;
		WaveformAiCtrl   *wfAiCtrl = WaveformAiCtrl::Create();
		wfAiCtrl->setSelectedDevice(DeviceInformation(deviceNum));
		int channelCount = wfAiCtrl->getChannelCount();
		for (int j = 0; j < channelCount; j++){
			channels.push_back(CommonUtil::Int2CString(deviceNum) + "-" + CommonUtil::Int2CString(j));
		}
	}
}

void AdvantechDaqController::CheckError(ErrorCode error){
	if (BioFailed(error))
	{
		CString str;
		str.Format(_T("Some errors happened, the error code is: 0x%X !\n"), error);
		AfxMessageBox(str);
	}
}

void AdvantechDaqController::ConfigurateDevice(DevConfParam devConfigPara, WaveformAiCtrl *waveformAiCtrl){
	ErrorCode	errorCode;
	// 根据设备号设置一些设备信息
	DeviceInformation devInfo(devConfigPara.deviceNumber);
	errorCode = waveformAiCtrl->setSelectedDevice(devInfo);
	CheckError(errorCode);

	// 设置参数信息 会话长度
	int sectionLength = (devConfigPara.sectionLength > USER_BUFFER_LENTH_MAX_PER_CHAN) ? USER_BUFFER_LENTH_MAX_PER_CHAN : devConfigPara.sectionLength;
	int32 bufferDataLength = devConfigPara.sectionLength * devConfigPara.channelCount;
	// 给 buffered AI operation设置必要的操作 
	Conversion * conversion = waveformAiCtrl->getConversion();
	errorCode = conversion->setChannelStart(devConfigPara.channelStart);
	CheckError(errorCode);

	errorCode = conversion->setChannelCount(devConfigPara.channelCount);
	CheckError(errorCode);
	errorCode = conversion->setClockRate(devConfigPara.clockRatePerChan);
	CheckError(errorCode);
	Record * record = waveformAiCtrl->getRecord();
	errorCode = record->setSectionCount(0);// 0 means 'streaming mode'.
	CheckError(errorCode);
	errorCode = record->setSectionLength(sectionLength);
	CheckError(errorCode);
	int count = waveformAiCtrl->getFeatures()->getChannelCountMax();
	Array<AiChannel> *channels = waveformAiCtrl->getChannels();
	int channel = devConfigPara.channelStart;
	for (int i = 0; i < devConfigPara.channelCount; ++i)
	{
		if (channel >= count){
			channel = 0;
		}
		if (channels->getItem(channel).getSignalType() == Differential)
		{
			if (channel % 2 == 1){
				channel -= 1;
			}
			errorCode = channels->getItem(channel%count).setValueRange((ValueRange)(devConfigPara.vrgTypes[i]));
			CheckError(errorCode);
			channel += 1;
		}
		errorCode = channels->getItem(channel%count).setValueRange((ValueRange)(devConfigPara.vrgTypes[i]));
		CheckError(errorCode);
		channel += 1;
	}

	// 准备 buffered AI. 
	errorCode = waveformAiCtrl->Prepare();
	CheckError(errorCode);
}


void  AdvantechDaqController::GetValueRangeInformationByVrgType(MathInterval & rangeY){
	ValueUnit	  unit;
	if (rangeY.Type < Jtype_0To760C){
		CheckError(AdxGetValueRangeInformation((ValueRange)rangeY.Type, 0, NULL, &rangeY, &unit));
		if (Milliampere == unit || Millivolt == unit){
			rangeY.Max /= 1000;
			rangeY.Min /= 1000;
		}
	}
}
void AdvantechDaqController::GetValueRangeInformationByDeviceNum(int deviceNum, Array<ValueRange>*& ValueRanges){
	DeviceInformation devInfo(deviceNum);
	WaveformAiCtrl *  wfAiCtrl = WaveformAiCtrl::Create();
	ErrorCode errorCode = wfAiCtrl->setSelectedDevice(devInfo);
	CheckError(errorCode);
	ValueRanges = wfAiCtrl->getFeatures()->getValueRanges();
}