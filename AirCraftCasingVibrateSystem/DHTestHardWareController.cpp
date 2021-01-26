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
		// ����������ͨ��
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
// ��������ͨ����Ϣ�ַ���
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
	// ͨ����Ϣ������XML��ʽ�ַ�����
	strChannelKeyXML = ChannelKey.ConvertToXML(m_vecChannelKey);
	return strChannelKeyXML;
}

long DHTestHardWareController::ModifyParamAndSendCodeSecond(CDHTestHardWare *pHardWare, long lGroupID, LPCTSTR strMachineIP, long ChannelStyle, long ChannelID, long CellID, long ShowParamID, LPCTSTR strParamValue, long nSelectIndex)
{
	long lModifyReturn, lSendCodeReturn;
	pHardWare->ModifyParam(lGroupID, strMachineIP, ChannelStyle, ChannelID, CellID, ShowParamID, strParamValue, nSelectIndex, &lModifyReturn);
	 //�޸�����ͨ��������,lSendCodeReturnֵΪ0�����Ƿ����ѳɹ�����Ӱ���޸Ĳ���
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

		// ��ȡͨ������Ϣ
		pHardWare->GetChannelGroup(i, &nGroupChannelID, strValue, &lReturnValue);//strValue<->strMachineIP
		char *pTempData = _com_util::ConvertBSTRToString(*strValue);
		strMachineIP = pTempData;//����IP
		delete pTempData;
		stuGroupChannel.m_GroupID = nGroupChannelID;
		stuGroupChannel.m_strMachineIP = strMachineIP;

		// ��ȡĳ̨��������ʼͨ��ID
		pHardWare->GetChannelFirstID(nGroupChannelID, strMachineIP.data(), &nChannelFirst);
		stuGroupChannel.m_nChannelFirst = nChannelFirst;

		// ��ȡĳ̨�������ܵ�ͨ����
		pHardWare->GetChannelCount(nGroupChannelID, strMachineIP.data(), &nChannelNumber);
		stuGroupChannel.m_nChannelNumber = nChannelNumber;

		// ��ȡĳ̨��������������
		pHardWare->GetChannelGroupDataType(nGroupChannelID, strMachineIP.data(), &nDataType);
		stuGroupChannel.m_nDataType = nDataType;

		vecGroupChannel.push_back(stuGroupChannel);
		delete strValue;

		stuHardChannel HardChannel;
		// ͨ����Ϣ
		for (j = 0; j < nChannelNumber; j++)
		{
			//long nChannelID = nChannelFirst + j;
			long nChannelID;
			long bOnLine = 0;
			long nMeasureType = 0;
			pHardWare->GetChannelIDFromIndex(nGroupChannelID, strMachineIP.data(), j, &nChannelID);
			pHardWare->IsChannelOnLine(nGroupChannelID, strMachineIP.data(), nChannelID, &bOnLine);
			pHardWare->GetChannelMeasureType(nGroupChannelID, strMachineIP.data(), nChannelID, &nMeasureType);//��ȡͨ����������
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

//���ַ������зֽ⡣strSeprator�е��κ�һ���ַ�����Ϊ�ָ��������طֽڵõ����ַ�����Ŀ
int DHTestHardWareController::BreakString(const string& strSrc, list<string>& lstDest, const string& strSeprator)
{
	//����б�
	lstDest.clear();
	//����
	int iCount = 0;

	if (strSeprator.length() == 0)
	{
		lstDest.push_back(strSrc);
		iCount = 1;
		return iCount;
	}

	//���ҵ�λ��
	std::string::size_type iPos = 0;
	while (iPos < strSrc.length())
	{
		std::string::size_type iNewPos = strSrc.find_first_of(strSeprator, iPos);
		//��ǰ�ַ����ָ���
		if (iNewPos == iPos)
		{
			iPos++;
		}
		//û�ҵ��ָ���
		else if (iNewPos == std::string::npos)
		{
			lstDest.push_back(strSrc.substr(iPos, strSrc.length() - iPos));
			iCount++;
			iPos = strSrc.length();
		}
		//����
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


//��ȡ����ID
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


//��ȡͨ������
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
		return Result(false, "���ò���ʧ��");
	}
	return Result(true, "���ò����ɹ�");
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
	if (strParamValue == inputMode.c_str()) return Result(true, "Ĭ�ϲ���");*/
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


///����ͨ������
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
	//����б�
	vecDest.clear();
	//����
	int iCount = 0;

	if (strSeprator.length() == 0)
	{
		vecDest.push_back(strSrc);
		iCount = 1;
		return iCount;
	}

	//���ҵ�λ��
	std::string::size_type iPos = 0;
	while (iPos < strSrc.length())
	{
		std::string::size_type iNewPos = strSrc.find_first_of(strSeprator, iPos);
		//��ǰ�ַ����ָ���
		if (iNewPos == iPos)
		{
			iPos++;
		}
		//û�ҵ��ָ���
		else if (iNewPos == std::string::npos)
		{
			vecDest.push_back(strSrc.substr(iPos, strSrc.length() - iPos));
			iCount++;
			iPos = strSrc.length();
		}
		//����
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
	//��ȡ������ѡ���б�
	pHardWare->GetParamSelectValue(vecHardChannel[0].m_nChannelGroupID, strMachineIP.data(), vecHardChannel[0].m_nChannelStyle, vecHardChannel[0].m_nChannelID, vecHardChannel[0].m_nCellID, SHOW_CHANNEL_FULLVALUE, strSelectValue);
	if (*strSelectValue){
		pTempData = _com_util::ConvertBSTRToString(*strSelectValue);
		string strFullValueSelect = pTempData;
		int nFullValueCount = BreakString(strFullValueSelect, result, string("|"));
	}
	//delete pTempData;
}

void DHTestHardWareController::GetAllUpFreq(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, string strMachineIP, vector<string> &result){
	//��ȡ���е�����Ƶ��
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
	//��ȡ������ѡ���б�
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
	//��ȡ��ѹ������Χ
	pHardWare->GetParamSelectValue(vecHardChannel[0].m_nChannelGroupID, strMachineIP.data(), vecHardChannel[0].m_nChannelStyle, vecHardChannel[0].m_nChannelID, vecHardChannel[0].m_nCellID, SHOW_ELC_PRESSURE, strSelectValue);
	if (*strSelectValue){
		char *pTempData = _com_util::ConvertBSTRToString(*strSelectValue);
		string strEXCHANGEAB = pTempData;
		int nBridgeTypeCount = BreakString(strEXCHANGEAB, result, string("|"));
	}
}


void DHTestHardWareController::GetAllMessaueType(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, string strMachineIP, vector<string> &result){
	BSTR *strSelectValue = new BSTR();
	//��ȡ����ֵ
	pHardWare->GetParamSelectValue(vecHardChannel[0].m_nChannelGroupID, strMachineIP.data(), vecHardChannel[0].m_nChannelStyle, vecHardChannel[0].m_nChannelID, vecHardChannel[0].m_nCellID, SHOW_CHANNEL_MEASURETYPE, strSelectValue);
	char *pTmpData = _com_util::ConvertBSTRToString(*strSelectValue);
	string strMeasureTypeSelect = pTmpData;
	int nMeasureTypeCount = BreakString(strMeasureTypeSelect, result, string("|"));
}
void DHTestHardWareController::GetDefaultSensorEF(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, string strMachineIP, string &result){
	//��ȡĬ�ϵ������Ȳ���ֵ
	GetDefaultParam(pHardWare, vecHardChannel, strMachineIP, SHOW_CHANNEL_SENSECOEF, result);
}
void DHTestHardWareController::GetDefaultParam(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, string strMachineIP,int paramType, string &result){
	//��ȡĬ�ϵ������Ȳ���ֵ
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

//��ȡ��������Ƶ���б�     m_listSampleFreq
//nSampleMode �C ������ʽ 1��˲̬  2������
//strFreqList �C ��ѡƵ����������ȡ��Ƶ������ 10 | 20 | 50 | 100 | 500 | 1000 | 5000 | 10000����ÿ����ѡƵ��ʹ�á� | ���ָ�����
void DHTestHardWareController::GetSampleFreqList(CDHTestHardWare *pHardWare, vector<stuHardChannel> &vecHardChannel, vector<int> &result)
{
	BSTR *strList = new BSTR();
	//��ȡ����Ƶ�ʿ�ѡ��
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
//��ȡ��ǰ��������
void DHTestHardWareController::GetSampleParam(CDHTestHardWare *pHardWare, stuSampleParam &sampleParam)
{
	float fltSampleFreq;
	long nSampleMode, nTrigMode, nBlockSize, nDelayCount, nClockMode;

	//��ȡ��������
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

//	// ��ȡͨ������Ϣ
//	pHardWare->GetChannelGroup(i, &nGroupChannelID, strValue, &lReturnValue);//strValue<->strMachineIP
//	char *pTempData = _com_util::ConvertBSTRToString(*strValue);
//	strMachineIP = pTempData;//����IP
//	delete pTempData;
//	stuGroupChannel.m_GroupID = nGroupChannelID;
//	stuGroupChannel.m_strMachineIP = strMachineIP;

//	// ��ȡĳ̨��������ʼͨ��ID
//	pHardWare->GetChannelFirstID(nGroupChannelID, strMachineIP.data(), &nChannelFirst);
//	stuGroupChannel.m_nChannelFirst = nChannelFirst;

//	// ��ȡĳ̨�������ܵ�ͨ����
//	pHardWare->GetChannelCount(nGroupChannelID, strMachineIP.data(), &nChannelNumber);
//	stuGroupChannel.m_nChannelNumber = nChannelNumber;

//	// ��ȡĳ̨��������������
//	pHardWare->GetChannelGroupDataType(nGroupChannelID, strMachineIP.data(), &nDataType);
//	stuGroupChannel.m_nDataType = nDataType;

//	m_vecGroupChannel.push_back(stuGroupChannel);
//	delete strValue;

//	stuHardChannel HardChannel;
//	// ͨ����Ϣ
//	for (j = 0; j < nChannelNumber; j++)
//	{
//		//long nChannelID = nChannelFirst + j;
//		long nChannelID;
//		long bOnLine = 0;
//		long nMeasureType = 0;
//		pHardWare->GetChannelIDFromIndex(nGroupChannelID, strMachineIP.data(), j, &nChannelID);
//		pHardWare->IsChannelOnLine(nGroupChannelID, strMachineIP.data(), nChannelID, &bOnLine);
//		pHardWare->GetChannelMeasureType(nGroupChannelID, strMachineIP.data(), nChannelID, &nMeasureType);//��ȡͨ����������
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