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
		for (int j = 1; j <= channelCount; j++){
			channels.push_back(CommonUtil::Int2CString(deviceNum+1) + "-" + CommonUtil::Int2CString(j));
		}
	}
}