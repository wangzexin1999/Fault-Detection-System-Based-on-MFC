#include "stdafx.h"
#include "DHTestHardWareController.h"

DHTestHardWareController::DHTestHardWareController()
{
}


DHTestHardWareController::~DHTestHardWareController()
{

}

void DHTestHardWareController::GetChannelCodes(const vector<stuHardChannel> &vecHardChannel,std::vector<CString> &channelCodes){
	for (int i = 0; i < vecHardChannel.size(); i++)
	{
		// 跳过不在线通道
		if (!vecHardChannel[i].m_bOnlineFlag)
			continue;
		CString strGroupID;
		int nGroupID = vecHardChannel[i].m_nChannelGroupID;
		strGroupID.Format("%d", nGroupID + 1);
		CString strChannelID;
		strChannelID.Format("%d", vecHardChannel[i].m_nChannelID + 1);
		CString strText = strGroupID + "-" + strChannelID;
		channelCodes.push_back(strText);
	}
}
// 构建数采通道信息字符串
string DHTestHardWareController::CreateChannelKeyString(vector<stuHardChannel> &vecHardChannel)
{
	string strChannelKeyXML;
	vector<Channel_Key> m_vecChannelKey;
	Channel_Key ChannelKey;
	for (int i = 0; i < vecHardChannel.size(); i++)
	{
		ChannelKey.m_nGroupID = vecHardChannel[i].m_nChannelGroupID;
		ChannelKey.m_strIP = vecHardChannel[i].m_strMachineIP;
		ChannelKey.m_nChannelID = vecHardChannel[i].m_nChannelID;
		ChannelKey.m_nChannelStyle = vecHardChannel[i].m_nChannelStyle;
		m_vecChannelKey.push_back(ChannelKey);
	}
	// 通道信息整合至XML形式字符串内
	strChannelKeyXML = ChannelKey.ConvertToXML(m_vecChannelKey);
	return strChannelKeyXML;
}

long DHTestHardWareController::ModifyParamAndSendCodeSecond(CDHTestHardWare *pHardWare, long lGroupID, LPCTSTR strMachineIP, long ChannelStyle, long ChannelID, long CellID, long ShowParamID, LPCTSTR strParamValue, long nSelectIndex)
{
	long lModifyReturn, lSendCodeReturn;
	pHardWare->ModifyParam(lGroupID, strMachineIP, ChannelStyle, ChannelID, CellID, ShowParamID, strParamValue, nSelectIndex, &lModifyReturn);
	 //修改数采通道参数后,lSendCodeReturn值为0，但是发码已成功，不影响修改参数
	pHardWare->SendChannelParamCode_Single(lGroupID, strMachineIP, ChannelID, &lSendCodeReturn);
	return lModifyReturn;
}

void DHTestHardWareController::GetAllGroupChannel(CDHTestHardWare *pHardWare, vector<stuGroupChannel> &vecGroupChannel, vector<stuHardChannel> &vecHardChannel, CString strChannel)
{
	int i = 0, j = 0;
	long nGroupCount;
	pHardWare->GetChannelGroupCount(&nGroupCount);

	long nGroupChannelID, nChannelFirst, nChannelNumber, nDataType;
	string strMachineIP;
	long lReturnValue = 0;
	stuGroupChannel stuGroupChannel;
	for (i = 0; i < nGroupCount; i++)
	{
		BSTR *strValue = new BSTR();

		// 获取通道组信息
		pHardWare->GetChannelGroup(i, &nGroupChannelID, strValue, &lReturnValue);//strValue<->strMachineIP
		char *pTempData = _com_util::ConvertBSTRToString(*strValue);
		strMachineIP = pTempData;//仪器IP
		delete pTempData;
		stuGroupChannel.m_GroupID = nGroupChannelID;
		stuGroupChannel.m_strMachineIP = strMachineIP;

		// 获取某台仪器的起始通道ID
		pHardWare->GetChannelFirstID(nGroupChannelID, strMachineIP.data(), &nChannelFirst);
		stuGroupChannel.m_nChannelFirst = nChannelFirst;

		// 获取某台仪器的总的通道数
		pHardWare->GetChannelCount(nGroupChannelID, strMachineIP.data(), &nChannelNumber);
		stuGroupChannel.m_nChannelNumber = nChannelNumber;

		// 获取某台仪器的数据类型
		pHardWare->GetChannelGroupDataType(nGroupChannelID, strMachineIP.data(), &nDataType);
		stuGroupChannel.m_nDataType = nDataType;

		vecGroupChannel.push_back(stuGroupChannel);
		delete strValue;

		stuHardChannel HardChannel;
		// 通道信息
		for (j = 0; j < nChannelNumber; j++)
		{
			//long nChannelID = nChannelFirst + j;
			long nChannelID;
			long bOnLine = 0;
			long nMeasureType = 0;
			pHardWare->GetChannelIDFromIndex(nGroupChannelID, strMachineIP.data(), j, &nChannelID);
			pHardWare->IsChannelOnLine(nGroupChannelID, strMachineIP.data(), nChannelID, &bOnLine);
			pHardWare->GetChannelMeasureType(nGroupChannelID, strMachineIP.data(), nChannelID, &nMeasureType);//获取通道测量类型
			HardChannel.m_nChannelGroupID = nGroupChannelID;
			HardChannel.m_nChannelID = nChannelID;
			HardChannel.m_nMeasureType = nMeasureType;
			if (j > 0 && nChannelID == 0)
			{
				HardChannel.m_bOnlineFlag = 0;
			}
			else
			{
				HardChannel.m_bOnlineFlag = bOnLine;
			}
			memcpy(HardChannel.m_strMachineIP, strMachineIP.data(), 32);
			if (strChannel != "")
			{
				BSTR *strValue = new BSTR();
				pHardWare->GetParamValue(nGroupChannelID, strMachineIP.data(), HardChannel.m_nChannelStyle, HardChannel.m_nChannelID, HardChannel.m_nCellID, SHOW_CHANNEL_MEASURETYPE, strValue);
				char *pTmpData = _com_util::ConvertBSTRToString(*strValue);
				string strCurValue = pTmpData;
				delete pTmpData;
				delete strValue;
				if (strcmp(strCurValue.data(), strChannel) == 0)
				{
					vecHardChannel.push_back(HardChannel);
				}
			}
			else
			{
				vecHardChannel.push_back(HardChannel);
			}
		}
	}
}

//将字符串进行分解。strSeprator中的任何一个字符都作为分隔符。返回分节得到的字符串数目
int DHTestHardWareController::BreakString(const string& strSrc, list<string>& lstDest, const string& strSeprator)
{
	//清空列表
	lstDest.clear();
	//个数
	int iCount = 0;

	if (strSeprator.length() == 0)
	{
		lstDest.push_back(strSrc);
		iCount = 1;
		return iCount;
	}

	//查找的位置
	std::string::size_type iPos = 0;
	while (iPos < strSrc.length())
	{
		std::string::size_type iNewPos = strSrc.find_first_of(strSeprator, iPos);
		//当前字符即分隔符
		if (iNewPos == iPos)
		{
			iPos++;
		}
		//没找到分隔符
		else if (iNewPos == std::string::npos)
		{
			lstDest.push_back(strSrc.substr(iPos, strSrc.length() - iPos));
			iCount++;
			iPos = strSrc.length();
		}
		//其它
		else
		{
			lstDest.push_back(strSrc.substr(iPos, iNewPos - iPos));
			iCount++;
			iPos = iNewPos;
			iPos++;
		}
	}

	return iCount;
}


//获取仪器ID
string DHTestHardWareController::GetMachineIP(vector<stuHardChannel> &vecHardChannel,int nID)
{
	string strMachineIP;
	for (int i = 0; i < vecHardChannel.size(); i++)
	{
		int nGroupID = vecHardChannel[i].m_nChannelGroupID;
		if (nGroupID == nID)
		{
			strMachineIP = vecHardChannel[i].m_strMachineIP;
		}
	}
	return strMachineIP;
}


//获取通道参数
void DHTestHardWareController::GetChannelParam(const vector<stuHardChannel> &vecHardChannel,int nID, ChannelParam &ChanParam)
{
	for (int i = 0; i < vecHardChannel.size(); i++)
	{
		int nChannelID = vecHardChannel[i].m_nChannelID;
		if (nChannelID == nID)
		{
			ChanParam.ChannelStyle = vecHardChannel[i].m_nChannelStyle;
			ChanParam.ChannelID = nChannelID;
			ChanParam.CellID = vecHardChannel[i].m_nCellID;
		}
	}
}

Result DHTestHardWareController::SetParam(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel,CString channelCode, int paramType, CString strParamValue, int curSel){
	ChannelParam ChanParam;
	CString strGroupID = channelCode.Left(channelCode.ReverseFind('-'));
	int groupId = atol(strGroupID);
	CString strChannelID = channelCode.Mid(channelCode.ReverseFind('-') + 1);
	int channelId = atol(strChannelID);
	string strMachineIP = GetMachineIP(vecHardChannel,groupId);
	GetChannelParam(vecHardChannel, channelId, ChanParam);
	long lResult;
	lResult = ModifyParamAndSendCodeSecond(pHardWare, groupId, strMachineIP.data(), ChanParam.ChannelStyle, ChanParam.ChannelID, ChanParam.CellID, paramType, strParamValue, curSel);
	if (!lResult)
	{
		return Result(false, "设置参数失败");
	}
	return Result(true, "设置参数成功");
}

Result DHTestHardWareController::SetChannelFullvalue(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel,CString channelCode, CString strParamValue, int curSel)
{
	return SetParam(pHardWare, vecHardChannel,channelCode, SHOW_CHANNEL_FULLVALUE, strParamValue, curSel);
}


Result DHTestHardWareController::SetChannelUpfreq(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel,CString channelCode, CString strParamValue, int curSel)
{
	return SetParam(pHardWare, vecHardChannel, channelCode, SHOW_CHANNEL_UPFREQ, strParamValue, curSel);
}

Result DHTestHardWareController::SetChannelInputmode(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel,CString channelCode, CString strParamValue, int curSel)
{
	/*string inputMode;
	GetDefaultInputMode(pHardWare, vecHardChannel, vecHardChannel[0].m_strMachineIP, inputMode);
	if (strParamValue == inputMode.c_str()) return Result(true, "默认参数");*/
	return SetParam(pHardWare, vecHardChannel, channelCode, SHOW_CHANNEL_ACQ_INPUTMODE, strParamValue, curSel);
}

Result DHTestHardWareController::SetChannelElcPressure(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, CString channelCode, CString strParamValue, int curSel)
{
	return SetParam(pHardWare, vecHardChannel, channelCode, SHOW_ELC_PRESSURE, strParamValue, curSel);
}

Result DHTestHardWareController::SetSensorEF(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, CString channelCode, CString strParamValue)
{
	return SetParam(pHardWare, vecHardChannel, channelCode, SHOW_CHANNEL_SENSECOEF, strParamValue, 0);
}

Result DHTestHardWareController::SetSensorMessureType(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, CString channelCode, CString strParamValue, int curSel){
	return SetParam(pHardWare, vecHardChannel, channelCode, SHOW_CHANNEL_MEASURETYPE, strParamValue, curSel);
}


///设置通道参数
Result DHTestHardWareController::SetChannelParam(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel,TbChannel &channel){
	Result result;
	string messureType, inputNode, upFre, fullValue, sensorEf;
	GetDefaultFullValue(pHardWare, vecHardChannel, vecHardChannel[0].m_strMachineIP, fullValue);
	GetDefaultMessaueType(pHardWare, vecHardChannel, vecHardChannel[0].m_strMachineIP, messureType);
	GetDefaultSensorEF(pHardWare, vecHardChannel, vecHardChannel[0].m_strMachineIP, sensorEf);
	GetDefaultUpFreq(pHardWare, vecHardChannel, vecHardChannel[0].m_strMachineIP, upFre);
	GetDefaultInputMode(pHardWare, vecHardChannel, vecHardChannel[0].m_strMachineIP, inputNode);
	if (messureType.c_str() == channel.GetMessureType().second&&inputNode.c_str() == channel.GetInputMode().second
		&&upFre.c_str() == channel.GetUpFreq().second&&fullValue.c_str() == channel.GetFullValue().second){
		return Result(true,"-");
	}

	result = SetSensorMessureType(pHardWare, vecHardChannel, channel.GetChannelCode(), channel.GetMessureType().second, channel.GetMessureType().first);
	if (!result.GetIsSuccess()) return result;

	result = SetChannelFullvalue(pHardWare, vecHardChannel, channel.GetChannelCode(), channel.GetFullValue().second, channel.GetFullValue().first);
	if (!result.GetIsSuccess()) return result;

	result = SetChannelUpfreq(pHardWare, vecHardChannel, channel.GetChannelCode(), channel.GetUpFreq().second, channel.GetUpFreq().first);
	if (!result.GetIsSuccess()) return result;

	result = SetChannelInputmode(pHardWare, vecHardChannel, channel.GetChannelCode(), channel.GetInputMode().second, channel.GetInputMode().first);
	if (!result.GetIsSuccess()) return result;

	result = SetChannelElcPressure(pHardWare, vecHardChannel, channel.GetChannelCode(), channel.GetElcPressure().second, channel.GetElcPressure().first);
	if (!result.GetIsSuccess()) return result;


	result = SetSensorEF(pHardWare, vecHardChannel, channel.GetChannelCode(), CommonUtil::Int2CString(channel.GetSensitivity()));
	if (!result.GetIsSuccess()) return result;

	return result;
}

int DHTestHardWareController::BreakString(const string& strSrc, vector<string>& vecDest, const string& strSeprator)
{
	//清空列表
	vecDest.clear();
	//个数
	int iCount = 0;

	if (strSeprator.length() == 0)
	{
		vecDest.push_back(strSrc);
		iCount = 1;
		return iCount;
	}

	//查找的位置
	std::string::size_type iPos = 0;
	while (iPos < strSrc.length())
	{
		std::string::size_type iNewPos = strSrc.find_first_of(strSeprator, iPos);
		//当前字符即分隔符
		if (iNewPos == iPos)
		{
			iPos++;
		}
		//没找到分隔符
		else if (iNewPos == std::string::npos)
		{
			vecDest.push_back(strSrc.substr(iPos, strSrc.length() - iPos));
			iCount++;
			iPos = strSrc.length();
		}
		//其它
		else
		{
			vecDest.push_back(strSrc.substr(iPos, iNewPos - iPos));
			iCount++;
			iPos = iNewPos;
			iPos++;
		}
	}

	return iCount;
}

void DHTestHardWareController::GetAllFullValue(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, string strMachineIP,vector<string> &result){
	BSTR *strSelectValue = new BSTR();
	char *pTempData;
	//获取参数可选项列表
	pHardWare->GetParamSelectValue(vecHardChannel[0].m_nChannelGroupID, strMachineIP.data(), vecHardChannel[0].m_nChannelStyle, vecHardChannel[0].m_nChannelID, vecHardChannel[0].m_nCellID, SHOW_CHANNEL_FULLVALUE, strSelectValue);
	if (*strSelectValue){
		pTempData = _com_util::ConvertBSTRToString(*strSelectValue);
		string strFullValueSelect = pTempData;
		int nFullValueCount = BreakString(strFullValueSelect, result, string("|"));
	}
	//delete pTempData;
}

void DHTestHardWareController::GetAllUpFreq(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, string strMachineIP, vector<string> &result){
	//获取所有的上限频率
	BSTR *strSelectValue = new BSTR();
	char *pTempData;
	pHardWare->GetParamSelectValue(vecHardChannel[0].m_nChannelGroupID, strMachineIP.data(), vecHardChannel[0].m_nChannelStyle, vecHardChannel[0].m_nChannelID, vecHardChannel[0].m_nCellID, SHOW_CHANNEL_UPFREQ, strSelectValue);
	if (*strSelectValue){
		pTempData = _com_util::ConvertBSTRToString(*strSelectValue);
		string strUpFreq = pTempData;
		int nUpFreqCount = BreakString(strUpFreq, result, string("|"));
	}
	delete pTempData;
}

void DHTestHardWareController::GetAllInputMode(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, string strMachineIP, vector<string> &result){
	//获取参数可选项列表
	BSTR *strSelectValue = new BSTR();
	char *pTempData;
	pHardWare->GetParamSelectValue(vecHardChannel[0].m_nChannelGroupID, strMachineIP.data(), vecHardChannel[0].m_nChannelStyle, vecHardChannel[0].m_nChannelID, vecHardChannel[0].m_nCellID, SHOW_CHANNEL_ACQ_INPUTMODE, strSelectValue);
	if (*strSelectValue){
		pTempData = _com_util::ConvertBSTRToString(*strSelectValue);
		string strInputMode = pTempData;
		int nInputModeCount = BreakString(strInputMode, result, string("|"));
	}
}

void DHTestHardWareController::GetAllElcPressure(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, string strMachineIP, vector<string> &result){
	BSTR *strSelectValue = new BSTR();
	char *pTempData;
	//获取电压测量范围
	pHardWare->GetParamSelectValue(vecHardChannel[0].m_nChannelGroupID, strMachineIP.data(), vecHardChannel[0].m_nChannelStyle, vecHardChannel[0].m_nChannelID, vecHardChannel[0].m_nCellID, SHOW_ELC_PRESSURE, strSelectValue);
	if (*strSelectValue){
		char *pTempData = _com_util::ConvertBSTRToString(*strSelectValue);
		string strEXCHANGEAB = pTempData;
		int nBridgeTypeCount = BreakString(strEXCHANGEAB, result, string("|"));
	}
}


void DHTestHardWareController::GetAllMessaueType(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, string strMachineIP, vector<string> &result){
	BSTR *strSelectValue = new BSTR();
	//获取参数值
	pHardWare->GetParamSelectValue(vecHardChannel[0].m_nChannelGroupID, strMachineIP.data(), vecHardChannel[0].m_nChannelStyle, vecHardChannel[0].m_nChannelID, vecHardChannel[0].m_nCellID, SHOW_CHANNEL_MEASURETYPE, strSelectValue);
	char *pTmpData = _com_util::ConvertBSTRToString(*strSelectValue);
	string strMeasureTypeSelect = pTmpData;
	int nMeasureTypeCount = BreakString(strMeasureTypeSelect, result, string("|"));
}
void DHTestHardWareController::GetDefaultSensorEF(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, string strMachineIP, string &result){
	//获取默认的灵敏度参数值
	GetDefaultParam(pHardWare, vecHardChannel, strMachineIP, SHOW_CHANNEL_SENSECOEF, result);
}
void DHTestHardWareController::GetDefaultParam(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, string strMachineIP,int paramType, string &result){
	//获取默认的灵敏度参数值
	BSTR *strSelectValue = new BSTR();
	char *pTempData;
	pHardWare->GetParamValue(vecHardChannel[0].m_nChannelGroupID, strMachineIP.data(), vecHardChannel[0].m_nChannelStyle, vecHardChannel[0].m_nChannelID, vecHardChannel[0].m_nCellID, paramType, strSelectValue);
	if (*strSelectValue){
		pTempData = _com_util::ConvertBSTRToString(*strSelectValue);
		result = pTempData;
	}
}

void DHTestHardWareController::GetDefaultInputMode(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, string strMachineIP, string &result){
	GetDefaultParam(pHardWare, vecHardChannel, strMachineIP, SHOW_CHANNEL_ACQ_INPUTMODE, result);
}
void DHTestHardWareController::GetDefaultFullValue(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, string strMachineIP, string &result){
	GetDefaultParam(pHardWare, vecHardChannel, strMachineIP, SHOW_CHANNEL_FULLVALUE, result);
}
void DHTestHardWareController::GetDefaultUpFreq(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, string strMachineIP, string &result){
	GetDefaultParam(pHardWare, vecHardChannel, strMachineIP, SHOW_CHANNEL_FULLVALUE, result);
}

void DHTestHardWareController::GetDefaultElcPressure(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, string strMachineIP, string &result){
	GetDefaultParam(pHardWare, vecHardChannel, strMachineIP, SHOW_ELC_PRESSURE, result);
}

void DHTestHardWareController::GetDefaultMessaueType(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, string strMachineIP, string &result){
	GetDefaultParam(pHardWare, vecHardChannel, strMachineIP, SHOW_CHANNEL_MEASURETYPE, result);
}

//获取仪器采样频率列表     m_listSampleFreq
//nSampleMode – 采样方式 1—瞬态  2—连续
//strFreqList – 可选频率索引（获取的频率索引 10 | 20 | 50 | 100 | 500 | 1000 | 5000 | 10000），每个可选频率使用” | ”分隔开。
void DHTestHardWareController::GetSampleFreqList(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, vector<int> &result)
{
	BSTR *strList = new BSTR();
	//获取采样频率可选项
	pHardWare->GetSampleFreqList(2, strList);
	char *pTemData = _com_util::ConvertBSTRToString(*strList);
	string strFrepList = pTemData;
	delete pTemData;
	vector<string> temp;
	int nFreqCount = BreakString(strFrepList, temp, string("|"));
	for (int i = 0; i < temp.size();i++){
		result.push_back(atoi(temp[i].c_str()));
	}
	delete strList;
}
//获取当前采样参数
void DHTestHardWareController::GetSampleParam(CDHTestHardWare *pHardWare, stuSampleParam &sampleParam)
{
	float fltSampleFreq;
	long nSampleMode, nTrigMode, nBlockSize, nDelayCount, nClockMode;

	//获取采样参数
	pHardWare->GetSampleFreq(&fltSampleFreq);
	pHardWare->GetSampleMode(&nSampleMode);
	pHardWare->GetSampleTrigMode(&nTrigMode);
	pHardWare->GetTrigBlockCount(&nBlockSize);
	pHardWare->GetTrigDelayCount(&nDelayCount);
	pHardWare->GetSampleClockMode(&nClockMode);

	sampleParam.m_fltSampleFrequency = fltSampleFreq;
	sampleParam.m_nSampleMode = nSampleMode;
	sampleParam.m_nSampleTrigMode = nTrigMode;
	sampleParam.m_nSampleBlockSize = nBlockSize;
	sampleParam.m_nSampleDelayPoints = nDelayCount;
	sampleParam.m_nSampleClkMode = nClockMode;
}


//int i = 0, j = 0;
//long nGroupCount;
//pHardWare->GetChannelGroupCount(&nGroupCount);

//long nGroupChannelID, nChannelFirst, nChannelNumber, nDataType;
//string strMachineIP;
//long lReturnValue = 0;
//stuGroupChannel stuGroupChannel;
//for (i = 0; i < nGroupCount; i++)
//{
//	BSTR *strValue = new BSTR();

//	// 获取通道组信息
//	pHardWare->GetChannelGroup(i, &nGroupChannelID, strValue, &lReturnValue);//strValue<->strMachineIP
//	char *pTempData = _com_util::ConvertBSTRToString(*strValue);
//	strMachineIP = pTempData;//仪器IP
//	delete pTempData;
//	stuGroupChannel.m_GroupID = nGroupChannelID;
//	stuGroupChannel.m_strMachineIP = strMachineIP;

//	// 获取某台仪器的起始通道ID
//	pHardWare->GetChannelFirstID(nGroupChannelID, strMachineIP.data(), &nChannelFirst);
//	stuGroupChannel.m_nChannelFirst = nChannelFirst;

//	// 获取某台仪器的总的通道数
//	pHardWare->GetChannelCount(nGroupChannelID, strMachineIP.data(), &nChannelNumber);
//	stuGroupChannel.m_nChannelNumber = nChannelNumber;

//	// 获取某台仪器的数据类型
//	pHardWare->GetChannelGroupDataType(nGroupChannelID, strMachineIP.data(), &nDataType);
//	stuGroupChannel.m_nDataType = nDataType;

//	m_vecGroupChannel.push_back(stuGroupChannel);
//	delete strValue;

//	stuHardChannel HardChannel;
//	// 通道信息
//	for (j = 0; j < nChannelNumber; j++)
//	{
//		//long nChannelID = nChannelFirst + j;
//		long nChannelID;
//		long bOnLine = 0;
//		long nMeasureType = 0;
//		pHardWare->GetChannelIDFromIndex(nGroupChannelID, strMachineIP.data(), j, &nChannelID);
//		pHardWare->IsChannelOnLine(nGroupChannelID, strMachineIP.data(), nChannelID, &bOnLine);
//		pHardWare->GetChannelMeasureType(nGroupChannelID, strMachineIP.data(), nChannelID, &nMeasureType);//获取通道测量类型
//		HardChannel.m_nChannelGroupID = nGroupChannelID;
//		HardChannel.m_nChannelID = nChannelID;
//		HardChannel.m_nMeasureType = nMeasureType;
//		if (j > 0 && nChannelID == 0)
//		{
//			HardChannel.m_bOnlineFlag = 0;
//		}
//		else
//		{
//			HardChannel.m_bOnlineFlag = bOnLine;
//		}
//		memcpy(HardChannel.m_strMachineIP, strMachineIP.data(), 32);
//		if (strChannel != "")
//		{
//			BSTR *strValue = new BSTR();
//			pHardWare->GetParamValue(nGroupChannelID, strMachineIP.data(), HardChannel.m_nChannelStyle, HardChannel.m_nChannelID, HardChannel.m_nCellID, SHOW_CHANNEL_MEASURETYPE, strValue);
//			char *pTmpData = _com_util::ConvertBSTRToString(*strValue);
//			string strCurValue = pTmpData;
//			delete pTmpData;
//			delete strValue;
//			if (strcmp(strCurValue.data(), strChannel) == 0)
//			{
//				m_vecHardChannel.push_back(HardChannel);
//			}
//		}
//		else
//		{
//			m_vecHardChannel.push_back(HardChannel);
//		}
//	}
//}