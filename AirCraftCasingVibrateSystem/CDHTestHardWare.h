// CDHTestHardWare.h : 由 Microsoft Visual C++ 创建的 ActiveX 控件包装器类的声明

#pragma once

/////////////////////////////////////////////////////////////////////////////
// CDHTestHardWare

class CDHTestHardWare : public CWnd
{
protected:
	DECLARE_DYNCREATE(CDHTestHardWare)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0xBE2DDC3D, 0x230E, 0x4A6A, { 0x95, 0x2, 0x30, 0xD3, 0xAF, 0x26, 0x87, 0x5 } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
						const RECT& rect, CWnd* pParentWnd, UINT nID, 
						CCreateContext* pContext = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); 
	}

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, 
				UINT nID, CFile* pPersist = NULL, BOOL bStorage = FALSE,
				BSTR bstrLicKey = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); 
	}

// 特性
public:

// 操作
public:

	void Init(LPCTSTR strParentDir, LPCTSTR strMultiLanguage, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strParentDir, strMultiLanguage, ReturnValue);
	}
	void DHQuit()
	{
		InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void GetSampleFreqList(long nSampleMode, BSTR * strFreqList)
	{
		static BYTE parms[] = VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nSampleMode, strFreqList);
	}
	void IsSampling(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void IsConnectMachine(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void IsExistHardTrig(long * bExistHardTrig)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bExistHardTrig);
	}
	void IsExistExtraTrig(long * bExistExtraTrig)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bExistExtraTrig);
	}
	void GetHardTrigRAM(long * nTrigRamSize)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x8, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nTrigRamSize);
	}
	void GetAllowFreqModeValue(long * nAllowFreqMode)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x9, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nAllowFreqMode);
	}
	void StartSample(LPCTSTR strRunName, long nInstantIndex, long nBlockSize, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strRunName, nInstantIndex, nBlockSize, ReturnValue);
	}
	void StopSample(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void ReConnectAllMac(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void ResetDefaultParam(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void ChannelClearZero(LPCTSTR strXMLClearZeroChn, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXMLClearZeroChn, ReturnValue);
	}
	void ChannelBalance(LPCTSTR strXMLBalanceChn, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0xf, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXMLBalanceChn, ReturnValue);
	}
	void AllChannelClearZero(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x10, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void AllChannelBalance(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x11, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void IsSignalSourceHandle(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void IsSignalSourceStart(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x13, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void SetSignalSourceHandle(long bHandle)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x14, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bHandle);
	}
	void StartSignalSource()
	{
		InvokeHelper(0x15, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void StopSignalSource()
	{
		InvokeHelper(0x16, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void SendChannelParamCode(LPCTSTR strXMLChn, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x17, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXMLChn, ReturnValue);
	}
	void GetAllGroupChannel(BSTR * strGroupChannelXML)
	{
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x18, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strGroupChannelXML);
	}
	void SetAllGroupChannel(LPCTSTR strChannelXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x19, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strChannelXML, ReturnValue);
	}
	void GetGroupChannel(long nGroupID, LPCTSTR strMachineIP, BSTR * strGroupChannelXML)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PBSTR ;
		InvokeHelper(0x1a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nGroupID, strMachineIP, strGroupChannelXML);
	}
	void SetGroupChannel(long nGroupID, LPCTSTR strMachineIP, LPCTSTR strChannelXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x1b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nGroupID, strMachineIP, strChannelXML, ReturnValue);
	}
	void GetChannel(long GroupChannelID, LPCTSTR strMachineIP, long ChannelStyle, long ChannelID, long CellID, BSTR * strXMLChannel, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x1c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, GroupChannelID, strMachineIP, ChannelStyle, ChannelID, CellID, strXMLChannel, ReturnValue);
	}
	void SetChannel(long GroupChannelID, LPCTSTR strMachineIP, long ChannelStyle, long ChannelID, long CellID, LPCTSTR strXMLChannel, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x1d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, GroupChannelID, strMachineIP, ChannelStyle, ChannelID, CellID, strXMLChannel, ReturnValue);
	}
	void GetSampleParam(BSTR * strSampleParam, long * ReturnValue)
	{
		static BYTE parms[] = VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x1e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strSampleParam, ReturnValue);
	}
	void SetSampleParam(LPCTSTR strSampleParam, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x1f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strSampleParam, ReturnValue);
	}
	void GetParamSelectValue(long GroupChannelID, LPCTSTR strMachineIP, long ChannelStyle, long ChannelID, long CellID, long ShowParamID, BSTR * strSelectValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x20, DISPATCH_METHOD, VT_EMPTY, NULL, parms, GroupChannelID, strMachineIP, ChannelStyle, ChannelID, CellID, ShowParamID, strSelectValue);
	}
	void GetParamValue(long ChannelGroupID, LPCTSTR strMachineIP, long ChannelStyle, long ChannelID, long CellID, long ParamShowID, BSTR * strParamValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x21, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ChannelGroupID, strMachineIP, ChannelStyle, ChannelID, CellID, ParamShowID, strParamValue);
	}
	void ModifyParam(long GroupChannelID, LPCTSTR strMachineIP, long ChannelStyle, long ChannelID, long CellID, long ShowParamID, LPCTSTR strParamValue, long nSelectIndex, long * Result)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_I4 VTS_PI4 ;
		InvokeHelper(0x22, DISPATCH_METHOD, VT_EMPTY, NULL, parms, GroupChannelID, strMachineIP, ChannelStyle, ChannelID, CellID, ShowParamID, strParamValue, nSelectIndex, Result);
	}
	void ChangeChannelUsedStatus(LPCTSTR strXMLChn, long nUsedFlag)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x23, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXMLChn, nUsedFlag);
	}
	void IsAllowContinueSample(long GroupChannelID, LPCTSTR strMachineIP, float fltSampleFreq, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_R4 VTS_PI4 ;
		InvokeHelper(0x24, DISPATCH_METHOD, VT_EMPTY, NULL, parms, GroupChannelID, strMachineIP, fltSampleFreq, ReturnValue);
	}
	void MakeAbsolutePath(LPCTSTR strParent, LPCTSTR strChild, BSTR * strPath)
	{
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_PBSTR ;
		InvokeHelper(0x25, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strParent, strChild, strPath);
	}
	void MakeRelativePath(LPCTSTR strParent, LPCTSTR strChild, BSTR * strPath)
	{
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_PBSTR ;
		InvokeHelper(0x26, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strParent, strChild, strPath);
	}
	void ChangeChannelGroupID(long ChannelGroupID, LPCTSTR strMachineIP, long nNewChannelGroupID, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_PI4 ;
		InvokeHelper(0x27, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ChannelGroupID, strMachineIP, nNewChannelGroupID, ReturnValue);
	}
	void SingleResistanceTest(LPCTSTR strXMLChn, long * nStatus, float * fltValue, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 VTS_PR4 VTS_PI4 ;
		InvokeHelper(0x28, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXMLChn, nStatus, fltValue, ReturnValue);
	}
	void AllChannelResistanceTest(BSTR * strResistanceValue, long * ReturnValue)
	{
		static BYTE parms[] = VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x29, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strResistanceValue, ReturnValue);
	}
	void MacAutoCheck(BSTR * strCheckValue, long * ReturnValue)
	{
		static BYTE parms[] = VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x2a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strCheckValue, ReturnValue);
	}
	void IsOnLineRebackData(long nSampleMode, float fltSampleFreq, long * bOnlineRebackData)
	{
		static BYTE parms[] = VTS_I4 VTS_R4 VTS_PI4 ;
		InvokeHelper(0x2b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nSampleMode, fltSampleFreq, bOnlineRebackData);
	}
	void GetMaxContinueSampleFeq(float * fltMaxContinueFreq)
	{
		static BYTE parms[] = VTS_PR4 ;
		InvokeHelper(0x2c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, fltMaxContinueFreq);
	}
	void GetMaxRebackDataSampleFeq(float * fltMaxContinueFreq)
	{
		static BYTE parms[] = VTS_PR4 ;
		InvokeHelper(0x2d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, fltMaxContinueFreq);
	}
	void GetCallbackTestInfo(LPCTSTR strTestName, LPCTSTR strMachineIPXML, BSTR * strGroupInfoXML, long * nTotalDataCount, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_PBSTR VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x2e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strTestName, strMachineIPXML, strGroupInfoXML, nTotalDataCount, ReturnValue);
	}
	void CallbackData(LPCTSTR strTestName, LPCTSTR strGroupInfo, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x2f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strTestName, strGroupInfo, ReturnValue);
	}
	void GetCanLinkMacInfo(BSTR * strMacXML)
	{
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x30, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strMacXML);
	}
	void GetExistLinkMacInfo(BSTR * strMacXML)
	{
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x31, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strMacXML);
	}
	void ModifyLinkMacInfo(LPCTSTR strMacXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x32, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strMacXML, ReturnValue);
	}
	void GetShowParamInfo(long nInstrumentType, long nInterfaceType, long nMeasureType, BSTR * strXMLShowParamInfo)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x33, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nInstrumentType, nInterfaceType, nMeasureType, strXMLShowParamInfo);
	}
	void GetInstrumentPrjInfo(LPCTSTR strMachineIP, long nMachineID, BSTR * strXMLPrjInfo)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x34, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strMachineIP, nMachineID, strXMLPrjInfo);
	}
	void DeleteInstrumentPrj(LPCTSTR strMachineIP, long nMachineID, LPCTSTR strPrjName, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x35, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strMachineIP, nMachineID, strPrjName, ReturnValue);
	}
	void GetInstrumentFreeSpace(LPCTSTR strMachineIP, long nMachineID, long * nFreeSpace, long * nTotalSpace)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x36, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strMachineIP, nMachineID, nFreeSpace, nTotalSpace);
	}
	void IsExistInstantSampleMode(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x37, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void IsExistContinueSampleMode(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x38, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void ReconnectMac(LPCTSTR strMachineIP, long nMachineID, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_PI4 ;
		InvokeHelper(0x39, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strMachineIP, nMachineID, ReturnValue);
	}
	void GetPortAndBoundRate(long * nPort, long * nBoundRate)
	{
		static BYTE parms[] = VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x3a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nPort, nBoundRate);
	}
	void SetPortAndBoundRate(long nPort, long nBoundRate, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x3b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nPort, nBoundRate, ReturnValue);
	}
	void GetSelectPort(BSTR * strPort)
	{
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x3c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strPort);
	}
	void GetOldProjectInfo(LPCTSTR strDapFilePath, BSTR * strXMLGroupInfo, long * SampleTime, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PBSTR VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x3d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strDapFilePath, strXMLGroupInfo, SampleTime, ReturnValue);
	}
	void ConvertOldProjectDataToFile(LPCTSTR strKeyInfo, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x3e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strKeyInfo, ReturnValue);
	}
	void PrepareInit(long nInstrumentMinorType)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x3f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nInstrumentMinorType);
	}
	void GetSampleFreq(float * fltSampleFreq)
	{
		static BYTE parms[] = VTS_PR4 ;
		InvokeHelper(0x40, DISPATCH_METHOD, VT_EMPTY, NULL, parms, fltSampleFreq);
	}
	void SetSampleFreq(float fltSampleFreq, long * ReturnValue)
	{
		static BYTE parms[] = VTS_R4 VTS_PI4 ;
		InvokeHelper(0x41, DISPATCH_METHOD, VT_EMPTY, NULL, parms, fltSampleFreq, ReturnValue);
	}
	void GetSampleMode(long * nSampleMode)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x42, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nSampleMode);
	}
	void SetSampleMode(long nSampleMode, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x43, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nSampleMode, ReturnValue);
	}
	void GetSampleTrigMode(long * nTrigMode)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x44, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nTrigMode);
	}
	void SetSampleTrigMode(long nTrigMode, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x45, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nTrigMode, ReturnValue);
	}
	void GetTrigBlockCount(long * nBlockSize)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x46, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nBlockSize);
	}
	void SetTrigBlockCount(long nBlockSize, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x47, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nBlockSize, ReturnValue);
	}
	void GetTrigDelayCount(long * nDelayCount)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x48, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nDelayCount);
	}
	void SetTrigDelayCount(long nDelayCount, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x49, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nDelayCount, ReturnValue);
	}
	void GetChannelGroupCount(long * nChannelGroupCount)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x4a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nChannelGroupCount);
	}
	void GetChannelGroup(long nIndex, long * nGroupChannelID, BSTR * strMachineIP, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x4b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nIndex, nGroupChannelID, strMachineIP, ReturnValue);
	}
	void GetChannelFirstID(long GroupChannelID, LPCTSTR strMachineIP, long * nChannelFirstID)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x4c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, GroupChannelID, strMachineIP, nChannelFirstID);
	}
	void GetChannelCount(long GroupChannelID, LPCTSTR strMachineIP, long * nChannelCount)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x4d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, GroupChannelID, strMachineIP, nChannelCount);
	}
	void IsChannelOnLine(long GroupChannelID, LPCTSTR strMachineIP, long nChannelID, long * bOnLine)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_PI4 ;
		InvokeHelper(0x4e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, GroupChannelID, strMachineIP, nChannelID, bOnLine);
	}
	void GetChannelGroupDataType(long GroupChannelID, LPCTSTR strMachineIP, long * nDataType)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x4f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, GroupChannelID, strMachineIP, nDataType);
	}
	void GetChannelMeasureType(long GroupChannelID, LPCTSTR strMachineIP, long nChannelID, long * nMeasureType)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_PI4 ;
		InvokeHelper(0x50, DISPATCH_METHOD, VT_EMPTY, NULL, parms, GroupChannelID, strMachineIP, nChannelID, nMeasureType);
	}
	void SetChannelMeasureType(long GroupChannelID, LPCTSTR strMachineIP, long nChannelID, long nMeasureType, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x51, DISPATCH_METHOD, VT_EMPTY, NULL, parms, GroupChannelID, strMachineIP, nChannelID, nMeasureType, ReturnValue);
	}
	void GetChannelADtoMVCoief(long GroupChannelID, LPCTSTR strMachineIP, long nChannelID, float * fltCoief)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_PR4 ;
		InvokeHelper(0x52, DISPATCH_METHOD, VT_EMPTY, NULL, parms, GroupChannelID, strMachineIP, nChannelID, fltCoief);
	}
	void GetChannelADtoEUCoief(long GroupChannelID, LPCTSTR strMachineIP, long nChannelID, float * fltCoief)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_PR4 ;
		InvokeHelper(0x53, DISPATCH_METHOD, VT_EMPTY, NULL, parms, GroupChannelID, strMachineIP, nChannelID, fltCoief);
	}
	void SendChannelParamCode_Single(long GroupChannelID, LPCTSTR strMachineIP, long ChannelID, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_PI4 ;
		InvokeHelper(0x54, DISPATCH_METHOD, VT_EMPTY, NULL, parms, GroupChannelID, strMachineIP, ChannelID, ReturnValue);
	}
	void GetAllChnData(long nBufferSize, long BufferPoint, long * nTotalDataPos, long * nReceiveCount, long * nChnCount, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x55, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nBufferSize, BufferPoint, nTotalDataPos, nReceiveCount, nChnCount, ReturnValue);
	}
	void GetAllChnDataEx(VARIANT * varChnData, long * nTotalDataPos, long * nReceiveCount, long * nChnCount, long * ReturnValue)
	{
		static BYTE parms[] = VTS_PVARIANT VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x56, DISPATCH_METHOD, VT_EMPTY, NULL, parms, varChnData, nTotalDataPos, nReceiveCount, nChnCount, ReturnValue);
	}
	void ChangeChannelGroupIDEx(LPCTSTR strXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x57, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML, ReturnValue);
	}
	void SetUseSynchTrans(long bUseSynchTrans)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x58, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bUseSynchTrans);
	}
	void IsExistChnAutoCheck(long * bExistChnAutoCheck)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x59, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bExistChnAutoCheck);
	}
	void GetNetModuleParam(LPCTSTR strMachineIP, BSTR * strNetInfoXML)
	{
		static BYTE parms[] = VTS_BSTR VTS_PBSTR ;
		InvokeHelper(0x5a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strMachineIP, strNetInfoXML);
	}
	void SetNetModuleParam(LPCTSTR strMachineIP, LPCTSTR strNetInfoXML)
	{
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x5b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strMachineIP, strNetInfoXML);
	}
	void GetGPSSynchStatus(long * bSynch)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x5c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bSynch);
	}
	void SetUseGPSSynch(long nSynch)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x5d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nSynch);
	}
	void SetCameraInfo(LPCTSTR strXMLCamera)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x5e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXMLCamera);
	}
	void GetNotAssicateChnParamSelectValue(long GroupChannelID, LPCTSTR strMachineIP, long ChannelStyle, long ChannelID, long CellID, long ShowParamID, BSTR * strSelectValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x5f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, GroupChannelID, strMachineIP, ChannelStyle, ChannelID, CellID, ShowParamID, strSelectValue);
	}
	void GetNotAssicateChnParamValue(long ChannelGroupID, LPCTSTR strMachineIP, long ChannelStyle, long ChannelID, long CellID, long ParamShowID, BSTR * strParamValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x60, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ChannelGroupID, strMachineIP, ChannelStyle, ChannelID, CellID, ParamShowID, strParamValue);
	}
	void ModifyNotAssicateChnParam(long ChannelGroupID, LPCTSTR strMachineIP, long ChannelStyle, long ChannelID, long CellID, long ShowParamID, LPCTSTR strParamValue, long * Result)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x61, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ChannelGroupID, strMachineIP, ChannelStyle, ChannelID, CellID, ShowParamID, strParamValue, Result);
	}
	void ChangeNotAssicateChnUsedStatus(LPCTSTR strXMLChn, long nUsedFlag)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x62, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXMLChn, nUsedFlag);
	}
	void GetNotAssicateChannel(long GroupChannelID, LPCTSTR strMachineIP, long ChannelStyle, long ChannelID, long CellID, BSTR * strXMLChannel, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x63, DISPATCH_METHOD, VT_EMPTY, NULL, parms, GroupChannelID, strMachineIP, ChannelStyle, ChannelID, CellID, strXMLChannel, ReturnValue);
	}
	void GetNotAssicateGroupChannel(long nGroupID, LPCTSTR strMachineIP, BSTR * strGroupChannelXML)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PBSTR ;
		InvokeHelper(0x64, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nGroupID, strMachineIP, strGroupChannelXML);
	}
	void WriteIOChnOutputValue(long GroupChannelID, LPCTSTR strMachineIP, long ChannelID, long CellID, long nValue, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, parms, GroupChannelID, strMachineIP, ChannelID, CellID, nValue, ReturnValue);
	}
	void DeleteInstrumentPrjFile(LPCTSTR strPrjName, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strPrjName, ReturnValue);
	}
	void SendChannelParamCodeEx(long GroupChannelID, LPCTSTR strMachineIP, long ChannelStyle, long ChannelID, long CellID, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x67, DISPATCH_METHOD, VT_EMPTY, NULL, parms, GroupChannelID, strMachineIP, ChannelStyle, ChannelID, CellID, ReturnValue);
	}
	void SetGetDataCountEveryTime(long nDataCount, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x68, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nDataCount, ReturnValue);
	}
	void SetClientSN(LPCTSTR strSerialNumber)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x69, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strSerialNumber);
	}
	void IsExistExtraTrigSignal(long * bExistExtraTrigSignal)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x6a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bExistExtraTrigSignal);
	}
	void GetSignalPortAndBoundRate(long nType, long * nPort, long * nBoundRate)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x6b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nType, nPort, nBoundRate);
	}
	void SetSignalPortAndBoundRate(long nType, long nPort, long nBoundRate, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x6c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nType, nPort, nBoundRate, ReturnValue);
	}
	void SelectSinalSouceType(long nType, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x6d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nType, ReturnValue);
	}
	void GetSignalSourceType(long * nType)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x6e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nType);
	}
	void SendAgilentSignalSourceVoltage(long nWaveForm, float fltFreq, float fltVoltage, float fltDelta, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_R4 VTS_R4 VTS_R4 VTS_PI4 ;
		InvokeHelper(0x6f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nWaveForm, fltFreq, fltVoltage, fltDelta, ReturnValue);
	}
	void SendStrainSignalSourceValue(long nMachineID, long nChannelID, long nMeaType, long nBridgeType, long nStrainValue, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x70, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nMachineID, nChannelID, nMeaType, nBridgeType, nStrainValue, ReturnValue);
	}
	void GetCallbackTestInfoEx(LPCTSTR strTestName, LPCTSTR strMachineIPXML, BSTR * strGroupInfoXML, long * nSampleTime, long * nTotalDataCount, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_PBSTR VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x71, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strTestName, strMachineIPXML, strGroupInfoXML, nSampleTime, nTotalDataCount, ReturnValue);
	}
	void SetUseTeam(long bUseTeam)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x72, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bUseTeam);
	}
	void GetUseTeam(long * bUseTeam)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x73, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bUseTeam);
	}
	void GetTeamSampleFreqList(long nTeamID, long nSampleMode, BSTR * strFreqList)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x74, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nTeamID, nSampleMode, strFreqList);
	}
	void GetTeamSampleParam(long nTeamID, BSTR * strSampleParam, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x75, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nTeamID, strSampleParam, ReturnValue);
	}
	void SetTeamSampleParam(long nTeamID, LPCTSTR strSampleParam, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x76, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nTeamID, strSampleParam, ReturnValue);
	}
	void ChangeChannelGroupTeamID(LPCTSTR strXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x77, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML, ReturnValue);
	}
	void ChangeAutoCheckType(long bCalibrate, long nLevel, LPCTSTR strChannelKey, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x78, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bCalibrate, nLevel, strChannelKey, ReturnValue);
	}
	void IsSupportBalanceDataDown(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x79, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void GetBalanceData(BSTR * strBalanceData, long * ReturnValue)
	{
		static BYTE parms[] = VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x7a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strBalanceData, ReturnValue);
	}
	void DownBalanceData(LPCTSTR strBalanceData, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x7b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strBalanceData, ReturnValue);
	}
	void InitVltAndResistanceTest(BSTR * strInitValue, long * ReturnValue)
	{
		static BYTE parms[] = VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x7c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strInitValue, ReturnValue);
	}
	void AmpBalanceOperate(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x7d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void GetCalibrateBattery(long * nBattery, long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x7e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nBattery, ReturnValue);
	}
	void SetNetSyncClkParam()
	{
		InvokeHelper(0x7f, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void IsUseMultimeter(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x80, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void SetUseMultimeter(long bUse)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x81, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bUse);
	}
	void GetDemoWaveParam(BSTR * strBalanceData, long * ReturnValue)
	{
		static BYTE parms[] = VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x82, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strBalanceData, ReturnValue);
	}
	void SetDemoWaveParam(LPCTSTR strBalanceData, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x83, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strBalanceData, ReturnValue);
	}
	void IsExistNewSignalSouce(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x84, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void IsSupportGNDBalance(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x85, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void AllChannelGNDBalance(long * ReturnValue, BSTR * strError)
	{
		static BYTE parms[] = VTS_PI4 VTS_PBSTR ;
		InvokeHelper(0x86, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue, strError);
	}
	void ChannelGNDBalance(LPCTSTR strXMLBalanceChn, long * ReturnValue, BSTR * strError)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 VTS_PBSTR ;
		InvokeHelper(0x87, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXMLBalanceChn, ReturnValue, strError);
	}
	void GetAllFindMac(BSTR * strXML)
	{
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x88, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML);
	}
	void IsDelLinuxData(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x89, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void SetDelLinuxData(long ReturnValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x8a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void SendGetPower()
	{
		InvokeHelper(0x8b, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void GetPower(BSTR * strXML)
	{
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x8c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML);
	}
	void IsSupportChnMultiFreq(long * bSupport)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x8d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bSupport);
	}
	void GetAllChnSampleRate(BSTR * strXML)
	{
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x8e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML);
	}
	void GetAllSampleTime(BSTR * strXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x8f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML, ReturnValue);
	}
	void GetSignalSourceUseType(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x90, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void SetSignalSourceUseType(long ReturnValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x91, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void SetDemoStatus(long bDemoStatus)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x92, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bDemoStatus);
	}
	void CheckExistAudioData(LPCTSTR strRunName, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x93, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strRunName, ReturnValue);
	}
	void RebackAudioData(LPCTSTR strRunName, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x94, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strRunName, ReturnValue);
	}
	void CheckRebackAudioEnd(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x95, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void SendAgilentSignalSourceVoltageEx(long nWaveForm, float fltFreq, float fltVoltage, float fltDelta, float * fltResult, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_R4 VTS_R4 VTS_R4 VTS_PR4 VTS_PI4 ;
		InvokeHelper(0x96, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nWaveForm, fltFreq, fltVoltage, fltDelta, fltResult, ReturnValue);
	}
	void GetExtraTrigSupportType(BSTR * strXML)
	{
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x97, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML);
	}
	void PrePareDownLoadSignalData(LPCTSTR strXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x98, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML, ReturnValue);
	}
	void DownLoadSignalData(LPCTSTR strXML, LPCTSTR strData, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x99, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML, strData, ReturnValue);
	}
	void WireLessChange(long bWireLess)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x9a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bWireLess);
	}
	void RefreshTedsSensorInfo(LPCTSTR strXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x9b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML, ReturnValue);
	}
	void IsSupportReadTedsSensor(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x9c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void SetReconnectStatus(long bReconnect)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x9d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bReconnect);
	}
	void GetSelMacFreeSpace(LPCTSTR strXML, BSTR * strFreeSpace)
	{
		static BYTE parms[] = VTS_BSTR VTS_PBSTR ;
		InvokeHelper(0x9e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML, strFreeSpace);
	}
	void DeleteInstrumentData(LPCTSTR strXML, long nDayCount, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_PI4 ;
		InvokeHelper(0x9f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML, nDayCount, ReturnValue);
	}
	void IsSupportPositive(long * bSupport)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0xa0, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bSupport);
	}
	void GetReversalLength(long * nLength)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0xa1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nLength);
	}
	void UpdateQueryInfoFile(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0xa2, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void GetCapacitorTypeCoief(long nInstrumentType, long nInterfaceType, long nChannelType, float * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_PR4 ;
		InvokeHelper(0xa3, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nInstrumentType, nInterfaceType, nChannelType, ReturnValue);
	}
	void IsSupportSetupInterface(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0xa4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void ShowSupportSetupInterface()
	{
		InvokeHelper(0xa5, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void GetOutDataSourceGroupChannel(BSTR * strGroupChannelXML)
	{
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0xa6, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strGroupChannelXML);
	}
	void GetOutDataSourceStatus(long * nUseOutDataSource, BSTR * strServerIP, long * ServerPort)
	{
		static BYTE parms[] = VTS_PI4 VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0xa7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nUseOutDataSource, strServerIP, ServerPort);
	}
	void SetOutDataSourceStatus(long nUseOutDataSource, LPCTSTR strServerIP, long ServerPort, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_PI4 ;
		InvokeHelper(0xa8, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nUseOutDataSource, strServerIP, ServerPort, ReturnValue);
	}
	void SetContinueTestCount(__int64 nCount, __int64 tmSample)
	{
		static BYTE parms[] = VTS_I8 VTS_I8 ;
		InvokeHelper(0xa9, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nCount, tmSample);
	}
	void IsSupportShowElec(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0xaa, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void SetupDigital(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0xab, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void GetNotAssicateGroupChannelXML(BSTR * strGroupChannelXML)
	{
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0xac, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strGroupChannelXML);
	}
	void IsSupportPowerOff(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0xad, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void PowerOff(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0xae, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	long ClearInstrumentFS(long nMachineID, LPCTSTR strMachineIP)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0xaf, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nMachineID, strMachineIP);
		return result;
	}
	void IsSupportOffLineSample(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0xb0, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void ChangeOffLineSampleStatus(long nOffLineSampleStatus, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0xb1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nOffLineSampleStatus, ReturnValue);
	}
	void GetOffLineSampleStatus(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0xb2, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void GetAllChnRectifyCoief(BSTR * strXML)
	{
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0xb3, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML);
	}
	void IsSupportHighSpeedSample(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0xb4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void GetHighSpeedSampleStatus(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0xb5, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void SetHighSpeedSampleStatus(long bHighSpeedSample)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xb6, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bHighSpeedSample);
	}
	void SetHighSpeedSampleFilePath(LPCTSTR strXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0xb7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML, ReturnValue);
	}
	void GetSelectedChnData(long nMachineID, VARIANT varChannelID, VARIANT * varSelectedChnData, long * nTotalDataPos, long * nReceiveCount, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_VARIANT VTS_PVARIANT VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0xb8, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nMachineID, &varChannelID, varSelectedChnData, nTotalDataPos, nReceiveCount, ReturnValue);
	}
	void SetDataGain(LPCTSTR strMacXML, long nGain, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_PI4 ;
		InvokeHelper(0xb9, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strMacXML, nGain, ReturnValue);
	}
	void GetDataGain(LPCTSTR strMacXML, long * nGain)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0xba, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strMacXML, nGain);
	}
	void IsSupportSoftExtraTrigInstant(long * bSupportExtraTrigInstant)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0xbb, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bSupportExtraTrigInstant);
	}
	void ChangeAcqFullCoief(LPCTSTR strXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0xbc, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML, ReturnValue);
	}
	void GetAcqFullCoief(LPCTSTR strXML, BSTR * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PBSTR ;
		InvokeHelper(0xbd, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML, ReturnValue);
	}
	void IsSupportNormalSample(long * bSupport)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0xbe, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bSupport);
	}
	void GetSampleStatValue(long nMachineID, long nChannelStyle, long nValueType, float * fltTime, float * fltValue, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_PR4 VTS_PR4 VTS_PI4 ;
		InvokeHelper(0xbf, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nMachineID, nChannelStyle, nValueType, fltTime, fltValue, ReturnValue);
	}
	void GetComputerMacAddress(BSTR * strMacAddress, long * ReturnValue)
	{
		static BYTE parms[] = VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0xc0, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strMacAddress, ReturnValue);
	}
	void IsSupportLeadResistanceTest(LPCTSTR strXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0xc1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML, ReturnValue);
	}
	void IsSupportModifyCoief(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0xc2, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void GetChnModifyCoiefInfo(LPCTSTR strXML, long nParamType, BSTR * strCoiefInfo, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0xc3, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML, nParamType, strCoiefInfo, ReturnValue);
	}
	void SetChnModifyCoiefInfo(long nParamType, LPCTSTR strCoiefInfo, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PI4 ;
		InvokeHelper(0xc4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nParamType, strCoiefInfo, ReturnValue);
	}
	void IsSupportChangeWaveFormVlt(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0xc5, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void ChangeWaveFormVlt(LPCTSTR strChnXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0xc6, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strChnXML, ReturnValue);
	}
	void RebackLostData(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0xc7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void IsGPSOutput(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0xc8, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void SetGPSOutputStatus(long nOutput)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xc9, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nOutput);
	}
	void GetGPSOutputPortAndBoundRate(long * nPort, long * nBoundRate)
	{
		static BYTE parms[] = VTS_PI4 VTS_PI4 ;
		InvokeHelper(0xca, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nPort, nBoundRate);
	}
	void SetGPSOutputPortAndBoundRate(long nPort, long nBoundRate, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0xcb, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nPort, nBoundRate, ReturnValue);
	}
	void OutputGPSData(LPCTSTR gpsdata, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0xcc, DISPATCH_METHOD, VT_EMPTY, NULL, parms, gpsdata, ReturnValue);
	}
	void IsSupportMoogOutData(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0xcd, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void GetMoogIOProtocol(BSTR * DAStoLCS, BSTR * LCStoDAS)
	{
		static BYTE parms[] = VTS_PBSTR VTS_PBSTR ;
		InvokeHelper(0xce, DISPATCH_METHOD, VT_EMPTY, NULL, parms, DAStoLCS, LCStoDAS);
	}
	void SetMoogIOProtocol(LPCTSTR DAStoLCS, LPCTSTR LCStoDAS, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_PI4 ;
		InvokeHelper(0xcf, DISPATCH_METHOD, VT_EMPTY, NULL, parms, DAStoLCS, LCStoDAS, ReturnValue);
	}
	void GetOutDataSourceStatusEx(long nOutDataType, long * bUseOutDataSource, BSTR * strServerIP, long * ServerPort)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0xd0, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nOutDataType, bUseOutDataSource, strServerIP, ServerPort);
	}
	void SetOutDataSourceStatusEx(long nOutDataType, long bUseOutDataSource, LPCTSTR strServerIP, long ServerPort, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR VTS_I4 VTS_PI4 ;
		InvokeHelper(0xd1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nOutDataType, bUseOutDataSource, strServerIP, ServerPort, ReturnValue);
	}
	void IsSupportChangeFirstChnIDAndChnNumber(long nInstrumentType, long nInterfaceType, long * bSupport)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0xd2, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nInstrumentType, nInterfaceType, bSupport);
	}
	void SendDataOutput(long nType, long nChnCount, long nDataCount, VARIANT varChnData, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_VARIANT VTS_PI4 ;
		InvokeHelper(0xd3, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nType, nChnCount, nDataCount, &varChnData, ReturnValue);
	}
	void SendDataOutputChnInfo(LPCTSTR strChnXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0xd4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strChnXML, ReturnValue);
	}
	void ChangeOutDataChnUsedStatus(LPCTSTR strXMLChn, long nUsedFlag)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0xd5, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXMLChn, nUsedFlag);
	}
	void IsConnectOutDataSource(long nOutDataType, long * bConnect)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0xd6, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nOutDataType, bConnect);
	}
	void IsSupportEID(long * bSupport)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0xd7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bSupport);
	}
	void RefreshEIDChn(LPCTSTR strXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0xd8, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML, ReturnValue);
	}
	void ChangeChnEIDInfo(LPCTSTR strXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0xd9, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML, ReturnValue);
	}
	void SendCanOutChnInfo(long nType, LPCTSTR strChnXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PI4 ;
		InvokeHelper(0xda, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nType, strChnXML, ReturnValue);
	}
	void SendDataOutChnInfo(long nType, LPCTSTR strChnXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PI4 ;
		InvokeHelper(0xdb, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nType, strChnXML, ReturnValue);
	}
	void SendDataOut(long nType, __int64 nTotalDataCount, long nChnCount, long nDataCount, VARIANT varChnData, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I8 VTS_I4 VTS_I4 VTS_VARIANT VTS_PI4 ;
		InvokeHelper(0xdc, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nType, nTotalDataCount, nChnCount, nDataCount, &varChnData, ReturnValue);
	}
	void SendBlockDataOut(LPCTSTR strSingalName, long nSplitCount, long nDataCount, VARIANT varChnData, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_I4 VTS_VARIANT VTS_PI4 ;
		InvokeHelper(0xdd, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strSingalName, nSplitCount, nDataCount, &varChnData, ReturnValue);
	}
	void GetPortAndBoundRateEx(BSTR * strXML)
	{
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0xde, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML);
	}
	void SetPortAndBoundRateEx(LPCTSTR strXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0xdf, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML, ReturnValue);
	}
	void GetAgilentOutValue(float * OutValue, long * ReturnValue)
	{
		static BYTE parms[] = VTS_PR4 VTS_PI4 ;
		InvokeHelper(0xe0, DISPATCH_METHOD, VT_EMPTY, NULL, parms, OutValue, ReturnValue);
	}
	void CallbackDataToDir(LPCTSTR strTestName, LPCTSTR strDestDir, LPCTSTR strMacIP, long bDelLinuxData, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 VTS_PI4 ;
		InvokeHelper(0xe1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strTestName, strDestDir, strMacIP, bDelLinuxData, ReturnValue);
	}
	void ReConnectServer(LPCTSTR serverIP, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0xe2, DISPATCH_METHOD, VT_EMPTY, NULL, parms, serverIP, ReturnValue);
	}
	void ReConnectAllServer(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0xe3, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void ChangeSoftParam(LPCTSTR softParam)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xe4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, softParam);
	}
	void GetServerSoftParam(BSTR * softParam)
	{
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0xe5, DISPATCH_METHOD, VT_EMPTY, NULL, parms, softParam);
	}
	void GetServerAllClientInfo(BSTR * strXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0xe6, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML, ReturnValue);
	}
	void DisconnectClient(LPCTSTR strXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0xe7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML, ReturnValue);
	}
	void DisconnectServer(LPCTSTR serverIP, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0xe8, DISPATCH_METHOD, VT_EMPTY, NULL, parms, serverIP, ReturnValue);
	}
	void GetMachineToNTPServerError(BSTR * strXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0xe9, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML, ReturnValue);
	}
	void SetChnModifyConditionerCoiefInfo(long nConderType, long nChnID, long nParamType, long nCode, float fCoief, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_R4 VTS_PI4 ;
		InvokeHelper(0xea, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nConderType, nChnID, nParamType, nCode, fCoief, ReturnValue);
	}
	void IsExistClientControl(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0xeb, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void GetTeamInfo(BSTR * strTeamXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0xec, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strTeamXML, ReturnValue);
	}
	void ChangeTeamInfo(LPCTSTR strTeamXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0xed, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strTeamXML, ReturnValue);
	}
	void GetAllControlFreeSpace(BSTR * xmlFreeSpace, long * ReturnValue)
	{
		static BYTE parms[] = VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0xee, DISPATCH_METHOD, VT_EMPTY, NULL, parms, xmlFreeSpace, ReturnValue);
	}
	void SendFreeSpaceToClient(__int64 lFreeSpace)
	{
		static BYTE parms[] = VTS_I8 ;
		InvokeHelper(0xef, DISPATCH_METHOD, VT_EMPTY, NULL, parms, lFreeSpace);
	}
	void GetDataIndex(long nMachineID, LPCTSTR strMachineIP, long nChannelID, long * nDataIndex, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0xf0, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nMachineID, strMachineIP, nChannelID, nDataIndex, ReturnValue);
	}
	void GetServerExistLinkMacInfo(LPCTSTR serverIP, long nInstrumentType, long nInterfaceType, BSTR * macXML)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_I4 VTS_PBSTR ;
		InvokeHelper(0xf1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, serverIP, nInstrumentType, nInterfaceType, macXML);
	}
	void GetServerCanLinkMacInfo(LPCTSTR serverIP, long nInstrumentType, long nInterfaceType, BSTR * macXML)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_I4 VTS_PBSTR ;
		InvokeHelper(0xf2, DISPATCH_METHOD, VT_EMPTY, NULL, parms, serverIP, nInstrumentType, nInterfaceType, macXML);
	}
	void ModifyServerLinkMacInfo(LPCTSTR serverIP, long nInstrumentType, long nInterfaceType, LPCTSTR macXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_I4 VTS_BSTR VTS_PI4 ;
		InvokeHelper(0xf3, DISPATCH_METHOD, VT_EMPTY, NULL, parms, serverIP, nInstrumentType, nInterfaceType, macXML, ReturnValue);
	}
	void DownZeroData(LPCTSTR strBalanceData, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0xf4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strBalanceData, ReturnValue);
	}
	void ModifyParamEx(LPCTSTR strXML, long ShowParamID, LPCTSTR strParamValue, long * Result)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_BSTR VTS_PI4 ;
		InvokeHelper(0xf5, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML, ShowParamID, strParamValue, Result);
	}
	void IsControlExistRunName(LPCTSTR runName, long * Result)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0xf6, DISPATCH_METHOD, VT_EMPTY, NULL, parms, runName, Result);
	}
	void SendToControlExistRunName(long existName)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xf7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, existName);
	}
	void SendRunDataToClient(long status, LPCTSTR xml, long * Result)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PI4 ;
		InvokeHelper(0xf8, DISPATCH_METHOD, VT_EMPTY, NULL, parms, status, xml, Result);
	}
	void IsSupportSwitchClockMode(long * Result)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0xf9, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Result);
	}
	void SetUpSoftParam(long nType, LPCTSTR name)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0xfa, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nType, name);
	}
	void GetOneMacChnData(long nMacID, VARIANT * varChnData, long * nTotalDataPos, long * nReceiveCount, long * nChnCount, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PVARIANT VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0xfb, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nMacID, varChnData, nTotalDataPos, nReceiveCount, nChnCount, ReturnValue);
	}
	void GetOneMacChnDataEx(long nMacID, long point, long * nTotalDataPos, long * nReceiveCount, long * nChnCount, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0xfc, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nMacID, point, nTotalDataPos, nReceiveCount, nChnCount, ReturnValue);
	}
	void IsPrepareSample(LPCTSTR xml, long * bSupport, BSTR * showXML)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 VTS_PBSTR ;
		InvokeHelper(0xfd, DISPATCH_METHOD, VT_EMPTY, NULL, parms, xml, bSupport, showXML);
	}
	void ChangeSignalSourceVlt(long nMachineID, LPCTSTR strMachineIP, long nChannelType, long nChannelID, float fltVlt, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_R4 VTS_PI4 ;
		InvokeHelper(0xfe, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nMachineID, strMachineIP, nChannelType, nChannelID, fltVlt, ReturnValue);
	}
	void ChangeSignalSourceFreq(long nMachineID, LPCTSTR strMachineIP, long nChannelType, long nChannelID, float fltFreq, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_R4 VTS_PI4 ;
		InvokeHelper(0xff, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nMachineID, strMachineIP, nChannelType, nChannelID, fltFreq, ReturnValue);
	}
	void ChangeSignalSourcePhase(long nMachineID, LPCTSTR strMachineIP, long nChannelType, long nChannelID, float fltPhase, long refChnID, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_R4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x100, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nMachineID, strMachineIP, nChannelType, nChannelID, fltPhase, refChnID, ReturnValue);
	}
	void SetRebackFilterInfo(long bUseRebackFilter, LPCTSTR xml, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x101, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bUseRebackFilter, xml, ReturnValue);
	}
	void GetCanLinkMacInfoEx(long nInstrumentType, long nInterfaceType, BSTR * strMacXML)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x102, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nInstrumentType, nInterfaceType, strMacXML);
	}
	void GetExistLinkMacInfoEx(long nInstrumentType, long nInterfaceType, BSTR * strMacXML)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x103, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nInstrumentType, nInterfaceType, strMacXML);
	}
	void ModifyLinkMacInfoEx(long nInstrumentType, long nInterfaceType, LPCTSTR strMacXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x104, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nInstrumentType, nInterfaceType, strMacXML, ReturnValue);
	}
	void ReConnectAllMacEx(long nInstrumentType, long nInterfaceType, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x105, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nInstrumentType, nInterfaceType, ReturnValue);
	}
	void IsSupportSetupInterfaceEx(long nInstrumentType, long nInterfaceType, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x106, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nInstrumentType, nInterfaceType, ReturnValue);
	}
	void ShowSupportSetupInterfaceEx(long nInstrumentType, long nInterfaceType)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x107, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nInstrumentType, nInterfaceType);
	}
	void ChangeConvergentCoeff(LPCTSTR xml, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x108, DISPATCH_METHOD, VT_EMPTY, NULL, parms, xml, ReturnValue);
	}
	void IsMultiHardWareManage(BSTR * xml, long * bMultiHardWareManage)
	{
		static BYTE parms[] = VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x109, DISPATCH_METHOD, VT_EMPTY, NULL, parms, xml, bMultiHardWareManage);
	}
	void IsUseClock(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x10a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void ChangeUseClockStatus(long bUseClock, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x10b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bUseClock, ReturnValue);
	}
	void GetHardWareManageLinkInfo(long nInstrumentType, long nInterfaceType, BSTR * strMacXML)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x10c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nInstrumentType, nInterfaceType, strMacXML);
	}
	void GetTeamMaxContinueSampleFreq(long nTeamID, float * fltMaxContinueFreq)
	{
		static BYTE parms[] = VTS_I4 VTS_PR4 ;
		InvokeHelper(0x10d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nTeamID, fltMaxContinueFreq);
	}
	void GetMacFromDefInstrumentType(LPCTSTR xmlMachine, long * nInstrumentType, long * nInterfaceType, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x10e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, xmlMachine, nInstrumentType, nInterfaceType, ReturnValue);
	}
	void IsSupportPowerOffEx(long nInstrumentType, long nInterfaceType, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x10f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nInstrumentType, nInterfaceType, ReturnValue);
	}
	void PowerOffEx(long nInstrumentType, long nInterfaceType, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x110, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nInstrumentType, nInterfaceType, ReturnValue);
	}
	void GetMultiMacCallbackTestInfo(long nInstrumentType, long nInterfaceType, LPCTSTR strTestName, LPCTSTR strMachineIPXML, BSTR * strGroupInfoXML, long * nSampleTime, long * nTotalDataCount, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR VTS_PBSTR VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x111, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nInstrumentType, nInterfaceType, strTestName, strMachineIPXML, strGroupInfoXML, nSampleTime, nTotalDataCount, ReturnValue);
	}
	void CallbackDataEx(long nInstrumentType, long nInterfaceType, LPCTSTR strTestName, LPCTSTR strGroupInfo, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x112, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nInstrumentType, nInterfaceType, strTestName, strGroupInfo, ReturnValue);
	}
	void DeleteInstrumentPrjFileEx(long nInstrumentType, long nInterfaceType, LPCTSTR strPrjName, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x113, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nInstrumentType, nInterfaceType, strPrjName, ReturnValue);
	}
	void SetStoreType(long nStoreType, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x114, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nStoreType, ReturnValue);
	}
	void GetMoogSampleFreq(float * fltSampleFreq, long * ReturnValue)
	{
		static BYTE parms[] = VTS_PR4 VTS_PI4 ;
		InvokeHelper(0x115, DISPATCH_METHOD, VT_EMPTY, NULL, parms, fltSampleFreq, ReturnValue);
	}
	void SetMoogSampleFreq(float fltSampleFreq, long * ReturnValue)
	{
		static BYTE parms[] = VTS_R4 VTS_PI4 ;
		InvokeHelper(0x116, DISPATCH_METHOD, VT_EMPTY, NULL, parms, fltSampleFreq, ReturnValue);
	}
	void GetOutDataSampleParam(long nChannelGroupID, BSTR * strSampleParam, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x117, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nChannelGroupID, strSampleParam, ReturnValue);
	}
	void SetHLHighSampleFilePath(LPCTSTR strXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x118, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML, ReturnValue);
	}
	void WriteHardWareSerialNumber(long ChannelGroupID, LPCTSTR strMachineIP, LPCTSTR strSerialNumber, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x119, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ChannelGroupID, strMachineIP, strSerialNumber, ReturnValue);
	}
	void ReadHardWareSerialNumber(long ChannelGroupID, LPCTSTR strMachineIP, BSTR * strSerialNumber, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x11a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ChannelGroupID, strMachineIP, strSerialNumber, ReturnValue);
	}
	void ChangeSampleFreqAndChnSampleRate(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x11b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void ChangeMoogStatus(long type, long nStatus, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x11c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, type, nStatus, ReturnValue);
	}
	void SetOutChannel(LPCTSTR strKey, LPCTSTR strXMLChannel, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x11d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strKey, strXMLChannel, ReturnValue);
	}
	void GetMoogDataStatus(long type, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x11e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, type, ReturnValue);
	}
	void ChannelAdjustZero(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x11f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void ChangeNTPDebugChn(long useDebugChn, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x120, DISPATCH_METHOD, VT_EMPTY, NULL, parms, useDebugChn, ReturnValue);
	}
	void GetNTPDebugChn(long * bUse)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x121, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bUse);
	}
	void IsAllegroDIO(long * bAllegroDIO)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x122, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bAllegroDIO);
	}
	void GetCanDBCMessageInfo(LPCTSTR strDBCFile, BSTR * strDBCInfo, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x123, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strDBCFile, strDBCInfo, ReturnValue);
	}
	void GetAllChannelZeroValue(BSTR * strBalanceData)
	{
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x124, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strBalanceData);
	}
	void ChangeNeedSendClientStatus(long bDeal)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x125, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bDeal);
	}
	void UpdateClientChannelParam(LPCTSTR keyxml)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x126, DISPATCH_METHOD, VT_EMPTY, NULL, parms, keyxml);
	}
	void IsClientNeedDeal(long * bDeal)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x127, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bDeal);
	}
	void ElecChemAdjustAD(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x128, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void STQGetPower(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x129, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void CreateCableAlg(long index, LPCTSTR cableParam, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x12a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, index, cableParam, ReturnValue);
	}
	void DelAllCableAlg(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x12b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void ResetCableAlg(long index, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x12c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, index, ReturnValue);
	}
	void CalCable(long index, LPCTSTR data, float * cabledata, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PR4 VTS_PI4 ;
		InvokeHelper(0x12d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, index, data, cabledata, ReturnValue);
	}
	void GetFrequencyMode(long * lFreqMode)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x12e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, lFreqMode);
	}
	void SetFrequencyMode(long nFreqMode, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x12f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nFreqMode, ReturnValue);
	}
	void IsReceiveMacReconnect(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x130, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void SendSelOutChnInfo(long nType, LPCTSTR strChnXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x131, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nType, strChnXML, ReturnValue);
	}
	void GetOneMacChnData708(long nMacID, long bufferSize, long point, long * nTotalDataPos, long * nReceiveCount, long * nStartChnID, long * nChnCount, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x132, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nMacID, bufferSize, point, nTotalDataPos, nReceiveCount, nStartChnID, nChnCount, ReturnValue);
	}
	void IsSupportShafting(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x133, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void GetShaftingParam(BSTR * strChnXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x134, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strChnXML, ReturnValue);
	}
	void SetShaftingParam(LPCTSTR strChnXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x135, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strChnXML, ReturnValue);
	}
	void GetSensorLinkStatus(BSTR * strSensorXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x136, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strSensorXML, ReturnValue);
	}
	void SetIgnoreSensorLinkStatus(LPCTSTR strChnXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x137, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strChnXML, ReturnValue);
	}
	void SendDataOutEx(long nType, LPCTSTR strChnXML, __int64 nTotalDataCount, long nChnCount, long nDataCount, VARIANT varChnData, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I8 VTS_I4 VTS_I4 VTS_VARIANT VTS_PI4 ;
		InvokeHelper(0x138, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nType, strChnXML, nTotalDataCount, nChnCount, nDataCount, &varChnData, ReturnValue);
	}
	void SetJumpDataType(long nType, long nMulti, LPCTSTR strChnXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x139, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nType, nMulti, strChnXML, ReturnValue);
	}
	void Get8301SignalInfo(long * isOutput, long * nSignalType, float * fltVltValue, long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 VTS_PI4 VTS_PR4 VTS_PI4 ;
		InvokeHelper(0x13a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, isOutput, nSignalType, fltVltValue, ReturnValue);
	}
	void Switch8301Signal(long isOutput, long nSignalType, float fltVltValue, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_R4 VTS_PI4 ;
		InvokeHelper(0x13b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, isOutput, nSignalType, fltVltValue, ReturnValue);
	}
	void SendCANData(LPCTSTR strXML, LPCTSTR strParam, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x13c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML, strParam, ReturnValue);
	}
	void SetOutDataSampleParam(LPCTSTR strXMLSample, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x13d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXMLSample, ReturnValue);
	}
	void GetAllChnParamSetStatus(LPCTSTR strXMLChn, BSTR * strXML)
	{
		static BYTE parms[] = VTS_BSTR VTS_PBSTR ;
		InvokeHelper(0x13e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXMLChn, strXML);
	}
	void SaveLocalIPInfoToIni(LPCTSTR strIP, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x13f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strIP, ReturnValue);
	}
	void PrepareAudioPlay(long samplePerSec, long wBitsPerSample, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x140, DISPATCH_METHOD, VT_EMPTY, NULL, parms, samplePerSec, wBitsPerSample, ReturnValue);
	}
	void PlayAudio(VARIANT varChnData, long bytes, long * ReturnValue)
	{
		static BYTE parms[] = VTS_VARIANT VTS_I4 VTS_PI4 ;
		InvokeHelper(0x141, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &varChnData, bytes, ReturnValue);
	}
	void StopAudioPlay()
	{
		InvokeHelper(0x142, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void IsExistMacSampling(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x143, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void IsSupportBalance(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x144, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void IsSupportSwitchGPSSystem(long nMacID, LPCTSTR strIP, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x145, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nMacID, strIP, ReturnValue);
	}
	void GetGPSSystem(long nMacID, LPCTSTR strIP, long * nGPSSystem, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x146, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nMacID, strIP, nGPSSystem, ReturnValue);
	}
	void SwitchGPSSystem(long nMacID, LPCTSTR strIP, long nGPSSystem, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_PI4 ;
		InvokeHelper(0x147, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nMacID, strIP, nGPSSystem, ReturnValue);
	}
	void IsSupportDownOfflineParam(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x148, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void DownOfflineParamFile(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x149, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void IsSupportClearInstrumentFS(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x14a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void GetDeviceLockStatus(LPCTSTR strXMLMac, BSTR * strXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x14b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXMLMac, strXML, ReturnValue);
	}
	void SetDeviceLockStatus(LPCTSTR strXMLMac, long bLock, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_PI4 ;
		InvokeHelper(0x14c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXMLMac, bLock, ReturnValue);
	}
	void AllChannelClearZeroEx(long bGND, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x14d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bGND, ReturnValue);
	}
	void GetChannelIDFromIndex(long GroupChannelID, LPCTSTR strMachineIP, long nIndex, long * nChannelID)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_PI4 ;
		InvokeHelper(0x14e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, GroupChannelID, strMachineIP, nIndex, nChannelID);
	}
	void GetGroupChannelBinarySize(long type, long * nBinarySize)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x14f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, type, nBinarySize);
	}
	void GetGroupChannelFromBinary(long type, long point, long nBufferSize)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x150, DISPATCH_METHOD, VT_EMPTY, NULL, parms, type, point, nBufferSize);
	}
	void GetSignalSourceChannelNUmbers(long * nChannelCount)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x151, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nChannelCount);
	}
	void GetChannelBinarySize(long GroupChannelID, LPCTSTR strMachineIP, long ChannelStyle, long ChannelID, long CellID, long * nBinarySize)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x152, DISPATCH_METHOD, VT_EMPTY, NULL, parms, GroupChannelID, strMachineIP, ChannelStyle, ChannelID, CellID, nBinarySize);
	}
	void GetChannelFromBinary(long GroupChannelID, LPCTSTR strMachineIP, long ChannelStyle, long ChannelID, long CellID, long point, long * nBufferSize)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x153, DISPATCH_METHOD, VT_EMPTY, NULL, parms, GroupChannelID, strMachineIP, ChannelStyle, ChannelID, CellID, point, nBufferSize);
	}
	void GetChannelStatus(LPCTSTR useGroupChannelxml, BSTR * machinechannelNumber, BSTR * channeluse)
	{
		static BYTE parms[] = VTS_BSTR VTS_PBSTR VTS_PBSTR ;
		InvokeHelper(0x154, DISPATCH_METHOD, VT_EMPTY, NULL, parms, useGroupChannelxml, machinechannelNumber, channeluse);
	}
	void GetAllChnRectifyCoiefEx(long point, long * nBinarySize)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x155, DISPATCH_METHOD, VT_EMPTY, NULL, parms, point, nBinarySize);
	}
	void GetSignalSourceVersion(long * nBinarySize)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x156, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nBinarySize);
	}
	void UpdateMaterialFile(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x157, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void GetPlaneTrigCondition(BSTR * strXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x158, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML, ReturnValue);
	}
	void GetAllMTSStatus(LPCTSTR strFileName, BSTR * strXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x159, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strFileName, strXML, ReturnValue);
	}
	void IsCanHandTrig(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x15a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void GetSampleStatusIndex(BSTR * strSampleStatus, long * ReturnValue)
	{
		static BYTE parms[] = VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x15b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strSampleStatus, ReturnValue);
	}
	void ChangeSampleStatus(LPCTSTR strSampleStatus, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x15c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strSampleStatus, ReturnValue);
	}
	void HandleTrig(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x15d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void DownLoadMTSParam(LPCTSTR strXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x15e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML, ReturnValue);
	}
	void ModifySampleStatusList(LPCTSTR strSampleStatusList, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x15f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strSampleStatusList, ReturnValue);
	}
	void GetAllChannelZeroValueEx(long point, long * nBinarySize)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x160, DISPATCH_METHOD, VT_EMPTY, NULL, parms, point, nBinarySize);
	}
	void SetExternalTrigModeChn(long outTrigChn, long ExternalTrigMode, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x161, DISPATCH_METHOD, VT_EMPTY, NULL, parms, outTrigChn, ExternalTrigMode, ReturnValue);
	}
	void ComAutoControllInstrument(LPCTSTR strParam, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x162, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strParam, ReturnValue);
	}
	void ECSolutionResistanceTest(BSTR * strXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x163, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML, ReturnValue);
	}
	void DownECSolutionResistance(LPCTSTR strResistanceValue, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x164, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strResistanceValue, ReturnValue);
	}
	void DownSelectChnID(LPCTSTR strXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x165, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML, ReturnValue);
	}
	void ECSendTrigSampleFlag(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x166, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void GetSignalPortAndBoundRateEx(long nType, BSTR * nPort, long * nBoundRate)
	{
		static BYTE parms[] = VTS_I4 VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x167, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nType, nPort, nBoundRate);
	}
	void SetSignalPortAndBoundRateEx(long nType, LPCTSTR nPort, long nBoundRate, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_PI4 ;
		InvokeHelper(0x168, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nType, nPort, nBoundRate, ReturnValue);
	}
	void GetSignalSourceChannelNumbersEx(long nPortID, long * nChannelCount)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x169, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nPortID, nChannelCount);
	}
	void GetCalibrateBatteryEx(long nPortID, long * nBattery, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x16a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nPortID, nBattery, ReturnValue);
	}
	void GetSignalSourceVersionEx(long nPortID, long * nBinarySize)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x16b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nPortID, nBinarySize);
	}
	void WritePWMChnDutyValue(long GroupChannelID, LPCTSTR strMachineIP, long ChannelID, long CellID, float fltValue, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_R4 VTS_PI4 ;
		InvokeHelper(0x16c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, GroupChannelID, strMachineIP, ChannelID, CellID, fltValue, ReturnValue);
	}
	void GetDIOCurrentStatus(long GroupChannelID, LPCTSTR strMachineIP, long ChannelID, long CellID, long * nStatus, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x16d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, GroupChannelID, strMachineIP, ChannelID, CellID, nStatus, ReturnValue);
	}
	void SendCANDataEx(long GroupChannelID, LPCTSTR strMachineIP, long ChannelID, long CellID, long count, long point, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x16e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, GroupChannelID, strMachineIP, ChannelID, CellID, count, point, ReturnValue);
	}
	void Get5916SyncClockLinkStatus(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x16f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void GetPWMCurrentDuty(long GroupChannelID, LPCTSTR strMachineIP, long ChannelID, long CellID, float * fltDuty, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_PR4 VTS_PI4 ;
		InvokeHelper(0x170, DISPATCH_METHOD, VT_EMPTY, NULL, parms, GroupChannelID, strMachineIP, ChannelID, CellID, fltDuty, ReturnValue);
	}
	void RS485AutoControl(long cmdId, LPCTSTR strMachineInfo, LPCTSTR strValue, long point, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_I4 VTS_PI4 ;
		InvokeHelper(0x171, DISPATCH_METHOD, VT_EMPTY, NULL, parms, cmdId, strMachineInfo, strValue, point, ReturnValue);
	}
	void SetCtrlCard24VOutput(long nOutput, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x172, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nOutput, ReturnValue);
	}
	void IsSupportInstantSetPoint(long * bSupport)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x173, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bSupport);
	}
	void ChangeExtTrigKeepTime(long nKeepTime, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x174, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nKeepTime, ReturnValue);
	}
	void GetCalibrateMachineId(long nPortID, long * nMachineID, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x175, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nPortID, nMachineID, ReturnValue);
	}
	void GetChnPluseData(long nChnID, long nNeedBufferSize, VARIANT * varChnPluserData, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PVARIANT VTS_PI4 ;
		InvokeHelper(0x176, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nChnID, nNeedBufferSize, varChnPluserData, ReturnValue);
	}
	void ECSetSampleStopResetFlag(LPCTSTR strXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x177, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML, ReturnValue);
	}
	void ECSendChnAutoGainFlag(LPCTSTR strXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x178, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML, ReturnValue);
	}
	void ECSetMultiSampleFlag(LPCTSTR strXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x179, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML, ReturnValue);
	}
	void IsSupportCustomA(long GroupChannelID, LPCTSTR strMachineIP, long ChannelStyle, long ChannelID, long CellID, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x17a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, GroupChannelID, strMachineIP, ChannelStyle, ChannelID, CellID, ReturnValue);
	}
	void IsSupportMultiRebackData(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x17b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void SetMultiRebackDataStatus(long rebackStatus)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x17c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, rebackStatus);
	}
	void IsSupportCANSendData(long GroupChannelID, LPCTSTR strMachineIP, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x17d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, GroupChannelID, strMachineIP, ReturnValue);
	}
	void GetRS485ChnData(long nMachineID, long nChannelID, long nBufferSize, long BufferPoint, long * nReceiveCount, long * nSignalCount, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x17e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nMachineID, nChannelID, nBufferSize, BufferPoint, nReceiveCount, nSignalCount, ReturnValue);
	}
	void SetMachineIDEx(long nPortID, long nMachineID, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x17f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nPortID, nMachineID, ReturnValue);
	}
	void IsHighStoreExcuteRule(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x180, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void ChangeHighStoreRuleStatus(long UserStopRule)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x181, DISPATCH_METHOD, VT_EMPTY, NULL, parms, UserStopRule);
	}
	void SendCANDataContainOut(long GroupChannelID, LPCTSTR strMachineIP, long ChannelID, long CellID, long bAssicate, long count, long point, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x182, DISPATCH_METHOD, VT_EMPTY, NULL, parms, GroupChannelID, strMachineIP, ChannelID, CellID, bAssicate, count, point, ReturnValue);
	}
	void SetLibraryPath(LPCTSTR path)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x183, DISPATCH_METHOD, VT_EMPTY, NULL, parms, path);
	}
	void GetOutDataChannel(long GroupChannelID, LPCTSTR strMachineIP, long ChannelStyle, long ChannelID, long CellID, BSTR * strXMLChannel, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x184, DISPATCH_METHOD, VT_EMPTY, NULL, parms, GroupChannelID, strMachineIP, ChannelStyle, ChannelID, CellID, strXMLChannel, ReturnValue);
	}
	void IsSupportBalanceResultDisplay(long nInstrumentType, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x185, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nInstrumentType, ReturnValue);
	}
	void GetMacCardChnCount(long nInstrumentType, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x186, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nInstrumentType, ReturnValue);
	}
	void IsSupportEditSensorCoief(long nInstrumentType, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x187, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nInstrumentType, ReturnValue);
	}
	void SetPFIOutDataSourceStatus(long bUseOutDataSource, LPCTSTR strServerIP, long ServerPort, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_PI4 ;
		InvokeHelper(0x188, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bUseOutDataSource, strServerIP, ServerPort, ReturnValue);
	}
	void GetPFIOutDataSourceStatus(long * bUseOutDataSource, BSTR * strServerIP, long * ServerPort)
	{
		static BYTE parms[] = VTS_PI4 VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x189, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bUseOutDataSource, strServerIP, ServerPort);
	}
	void GetPFIOutDataChannelsInfo(BSTR * strChannelInfoXML)
	{
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x18a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strChannelInfoXML);
	}
	void GetPFIOutDataSelectedList(BSTR * strSelectedListXML)
	{
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x18b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strSelectedListXML);
	}
	void SetPFIOutDataChannelParam(long ShowParamID, LPCTSTR strParamValue, long nChnCount, LPCTSTR strChnIDList, long * Result, BSTR * strChannelInfoXML)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_BSTR VTS_PI4 VTS_PBSTR ;
		InvokeHelper(0x18c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ShowParamID, strParamValue, nChnCount, strChnIDList, Result, strChannelInfoXML);
	}
	void CheckNIBindPFIIsCorrect(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x18d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void GetInitialVolAndRes(BSTR * strXML)
	{
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x18e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML);
	}
	void SetNIOutDataChannelParam(LPCTSTR strNIParamXML)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x18f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strNIParamXML);
	}
	void GetNIOutDataChannelParam(BSTR * strNIParamXML)
	{
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x190, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strNIParamXML);
	}
	void GetHardTrigRAMEx(float sampleFreq, long * nTrigRamSize)
	{
		static BYTE parms[] = VTS_R4 VTS_PI4 ;
		InvokeHelper(0x191, DISPATCH_METHOD, VT_EMPTY, NULL, parms, sampleFreq, nTrigRamSize);
	}
	void PFIConstCurrentRegulate(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x192, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void PFIAmpBalance(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x193, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void GetGPSClockStatus(BSTR * strXML)
	{
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x194, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML);
	}
	void GetAllChnData_NanjingCompass(long nBufferSize, long BufferPoint, long * nTotalDataPos, long * nReceiveCount, long * nChnCount, BSTR * strGPSTime, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x195, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nBufferSize, BufferPoint, nTotalDataPos, nReceiveCount, nChnCount, strGPSTime, ReturnValue);
	}
	void GetAllChnDataEx_NanjingCompass(VARIANT * varChnData, long * nTotalDataPos, long * nReceiveCount, long * nChnCount, BSTR * strGPSTime, long * ReturnValue)
	{
		static BYTE parms[] = VTS_PVARIANT VTS_PI4 VTS_PI4 VTS_PI4 VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x196, DISPATCH_METHOD, VT_EMPTY, NULL, parms, varChnData, nTotalDataPos, nReceiveCount, nChnCount, strGPSTime, ReturnValue);
	}
	void GetGPSSynchStatus_NanjingCompass(long * nSynchStatus)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x197, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nSynchStatus);
	}
	void GetLayoutFileNameBaseInstrumentType(long nInstrumentType, long nInterfaceType, BSTR * strFileName, BSTR * strHardWareFileName)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PBSTR VTS_PBSTR ;
		InvokeHelper(0x198, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nInstrumentType, nInterfaceType, strFileName, strHardWareFileName);
	}
	void GetMachineTrigStatue(BSTR * strXML)
	{
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x199, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML);
	}
	void ECModifyParam(LPCTSTR strXML, long nFlagType, VARIANT varFlagValue, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_VARIANT VTS_PI4 ;
		InvokeHelper(0x19a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML, nFlagType, &varFlagValue, ReturnValue);
	}
	void IsTeamSupportPositive(long teamID, long * bSupport)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x19b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, teamID, bSupport);
	}
	void IsTeamExistExtraTrig(long teamID, long * bExistExtraTrig)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x19c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, teamID, bExistExtraTrig);
	}
	void GetTeamHardTrigRAM(long teamID, float sampleFreq, long * nTrigRamSize)
	{
		static BYTE parms[] = VTS_I4 VTS_R4 VTS_PI4 ;
		InvokeHelper(0x19d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, teamID, sampleFreq, nTrigRamSize);
	}
	void IsTeamExistHardTrig(long teamID, long * bExistHardTrig)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x19e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, teamID, bExistHardTrig);
	}
	void IsTeamSupportInstantSetPoint(long teamID, long * bSupport)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x19f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, teamID, bSupport);
	}
	void GetAllMacSerialNo(BSTR * xml)
	{
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x1a0, DISPATCH_METHOD, VT_EMPTY, NULL, parms, xml);
	}
	void ChangeAllMacSerialNo(LPCTSTR xml, long * bChange)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x1a1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, xml, bChange);
	}
	void GetTeamExtraTrigSupportType(long teamID, BSTR * strXML)
	{
		static BYTE parms[] = VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x1a2, DISPATCH_METHOD, VT_EMPTY, NULL, parms, teamID, strXML);
	}
	void GetTeamAllowFreqModeValue(long teamID, long * nAllowFreqMode)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x1a3, DISPATCH_METHOD, VT_EMPTY, NULL, parms, teamID, nAllowFreqMode);
	}
	void IsTeamExistInstantSampleMode(long teamID, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x1a4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, teamID, ReturnValue);
	}
	void ChangeKiolMulitInstrStatus(long bKiloMultiInstr)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x1a5, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bKiloMultiInstr);
	}
	void GetExtendedParamValue(long ChannelGroupID, LPCTSTR strMachineIP, long ChannelStyle, long ChannelID, long CellID, long ShowParamID, BSTR * strParamValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x1a6, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ChannelGroupID, strMachineIP, ChannelStyle, ChannelID, CellID, ShowParamID, strParamValue);
	}
	void SetExtendedParamValue(long ChannelGroupID, LPCTSTR strMachineIP, long ChannelStyle, long ChannelID, long CellID, long ShowParamID, LPCTSTR strParamValue, long * Result)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x1a7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ChannelGroupID, strMachineIP, ChannelStyle, ChannelID, CellID, ShowParamID, strParamValue, Result);
	}
	void SetIsUseWithOtherMachine(long bIsUseWithOtherMachine)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x1a8, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bIsUseWithOtherMachine);
	}
	void GetIsUseWithOtherMachine(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x1a9, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void SetAlarmLight(long bIsAlarm, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x1aa, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bIsAlarm, ReturnValue);
	}
	void GetLinuxProjectInfo(LPCTSTR strDapFilePath, BSTR * strXMLGroupInfo, long * SampleTime, long * dataFileOffset, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PBSTR VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x1ab, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strDapFilePath, strXMLGroupInfo, SampleTime, dataFileOffset, ReturnValue);
	}
	void ModifyChannelsParam(LPCTSTR strXML, long ShowParamID, LPCTSTR strParamValue, BSTR * assicatechn)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_BSTR VTS_PBSTR ;
		InvokeHelper(0x1ac, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXML, ShowParamID, strParamValue, assicatechn);
	}
	void SetSoftOutput(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x1ad, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void GetOutDataData(long nMacID, long bufferSize, long point, long * nTotalDataPos, long * nReceiveCount, long * nStartChnID, long * nChnCount, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x1ae, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nMacID, bufferSize, point, nTotalDataPos, nReceiveCount, nStartChnID, nChnCount, ReturnValue);
	}
	void GetOutDataSourceCount(long * nOutDataSourceCount)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x1af, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nOutDataSourceCount);
	}
	void GetOutDataSourceType(BSTR * strDataTypeList)
	{
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x1b0, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strDataTypeList);
	}
	void GetOneTypeOutDataSourceStatus(long * nUseOutDataSource, long nOutDataType, BSTR * strInfo)
	{
		static BYTE parms[] = VTS_PI4 VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x1b1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nUseOutDataSource, nOutDataType, strInfo);
	}
	void SetOneTypeOutDataSourceStatus(long nUseOutDataSource, long nOutDataType, LPCTSTR strInfo, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x1b2, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nUseOutDataSource, nOutDataType, strInfo, ReturnValue);
	}
	void IsConnectDHOutDataSource(long nDHType, long * bConnect)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x1b3, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nDHType, bConnect);
	}
	void Call5916backDataToDir(LPCTSTR strTestName, LPCTSTR strDestDir, long nMachineID, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_I4 VTS_PI4 ;
		InvokeHelper(0x1b4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strTestName, strDestDir, nMachineID, ReturnValue);
	}
	void QHMCleaZero()
	{
		InvokeHelper(0x1b5, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void IsLinuxSystemMac(long nInstrumentType, long nInterfaceType, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x1b6, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nInstrumentType, nInterfaceType, ReturnValue);
	}
	void IsSupportRunRebackData(long nInstrumentType, long nInterfaceType, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x1b7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nInstrumentType, nInterfaceType, ReturnValue);
	}
	void IsAllDataValidTachoValue(long nInstrumentType, long nInterfaceType, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x1b8, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nInstrumentType, nInterfaceType, ReturnValue);
	}
	void CollectSampleInfo(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x1b9, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void MeasureBridgeVlt(BSTR * strXMLGroupInfo, long * ReturnValue)
	{
		static BYTE parms[] = VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x1ba, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXMLGroupInfo, ReturnValue);
	}
	void CheckSensorStatus(LPCTSTR strXMLGroupInfo, float fltFreq, long bStart, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_R4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x1bb, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXMLGroupInfo, fltFreq, bStart, ReturnValue);
	}
	void IsSupporWireLessSwitch(long nInstrumentType, long nInterfaceType, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x1bc, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nInstrumentType, nInterfaceType, ReturnValue);
	}
	void GetAllWireLessLinuxInstrument(BSTR * strInstruIDs)
	{
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x1bd, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strInstruIDs);
	}
	void GetTachoTestFreq(BSTR * strClockValue)
	{
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x1be, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strClockValue);
	}
	void SendDataOutNew(long nType, long nChannelID, LPCTSTR strChnXML, __int64 nTotalDataCount, long nChnCount, long nDataCount, VARIANT varChnData, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR VTS_I8 VTS_I4 VTS_I4 VTS_VARIANT VTS_PI4 ;
		InvokeHelper(0x1bf, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nType, nChannelID, strChnXML, nTotalDataCount, nChnCount, nDataCount, &varChnData, ReturnValue);
	}
	void GetSampleClockMode(long * nClockMode)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x1c0, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nClockMode);
	}
	void SetSampleClockMode(long nClockMode, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x1c1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nClockMode, ReturnValue);
	}
	void IsSupportBalanceEx(LPCTSTR strChnXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x1c2, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strChnXML, ReturnValue);
	}
	void IsWireLessUsed(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x1c3, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void GetCheckSensorChn(BSTR * strChnXML)
	{
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x1c4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strChnXML);
	}
	void GetServerDefInstrumentType(LPCTSTR strServerIP, BSTR * strXML)
	{
		static BYTE parms[] = VTS_BSTR VTS_PBSTR ;
		InvokeHelper(0x1c5, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strServerIP, strXML);
	}
	void ChannelClearZeroEx(LPCTSTR strXMLClearZeroChn, long bGND, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_PI4 ;
		InvokeHelper(0x1c6, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strXMLClearZeroChn, bGND, ReturnValue);
	}
	void IsSupportGNDClearZero(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x1c7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void StartMultiMacSample(LPCTSTR strMacXML, LPCTSTR strRunName, long nInstantIndex, long nBlockSize, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x1c8, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strMacXML, strRunName, nInstantIndex, nBlockSize, ReturnValue);
	}
	void StopMultiMacSample(LPCTSTR strMacXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x1c9, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strMacXML, ReturnValue);
	}
	void GetSampleTime(__int64 * time, long * millionTime, long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI8 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x1ca, DISPATCH_METHOD, VT_EMPTY, NULL, parms, time, millionTime, ReturnValue);
	}
	void GetMacCallbackTestInfo(long nInstrumentType, long nInterfaceType, LPCTSTR strTestName, LPCTSTR strMachineIPXML, BSTR * strGroupInfoXML, __int64 * nSampleTime, __int64 * nTotalDataCount, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR VTS_PBSTR VTS_PI8 VTS_PI8 VTS_PI4 ;
		InvokeHelper(0x1cb, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nInstrumentType, nInterfaceType, strTestName, strMachineIPXML, strGroupInfoXML, nSampleTime, nTotalDataCount, ReturnValue);
	}
	void Set5916EOutputChnInfo(long nGroupID, long nCANChnNum, long nCANChnId, long nRS485ChnNum, long nRS485ChnId, float fltOutSampleFreq, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_R4 VTS_PI4 ;
		InvokeHelper(0x1cc, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nGroupID, nCANChnNum, nCANChnId, nRS485ChnNum, nRS485ChnId, fltOutSampleFreq, ReturnValue);
	}
	void Get5916EOutputChnInfo(long nGroupID, long * nCANChnNum, long nCANChnId, long * nRS485ChnNum, long nRS485ChnId, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_I4 VTS_PI4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x1cd, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nGroupID, nCANChnNum, nCANChnId, nRS485ChnNum, nRS485ChnId, ReturnValue);
	}
	void SetPowerOffTime(long ChannelGroupID, LPCTSTR strMachineIP, long nTime1, long nTime2, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x1ce, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ChannelGroupID, strMachineIP, nTime1, nTime2, ReturnValue);
	}
	void GetPowerOffTime(long ChannelGroupID, LPCTSTR strMachineIP, long * nTime1, long * nTime2, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x1cf, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ChannelGroupID, strMachineIP, nTime1, nTime2, ReturnValue);
	}
	void GetMachineTemp(long ChannelGroupID, LPCTSTR strMachineIP, float * fltPWRtemp, float * fltIPCtemp, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PR4 VTS_PR4 VTS_PI4 ;
		InvokeHelper(0x1d0, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ChannelGroupID, strMachineIP, fltPWRtemp, fltIPCtemp, ReturnValue);
	}
	void GetErrorMsg(long ChannelGroupID, LPCTSTR strMachineIP, long nChannelID, long * nErrorCode, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x1d1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ChannelGroupID, strMachineIP, nChannelID, nErrorCode, ReturnValue);
	}
	void SetIRIGSyns(long nIRIGSynch, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x1d2, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nIRIGSynch, ReturnValue);
	}
	void GetClockType(BSTR * clockType)
	{
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x1d3, DISPATCH_METHOD, VT_EMPTY, NULL, parms, clockType);
	}
	void SetClockType(LPCTSTR clockType, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x1d4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, clockType, ReturnValue);
	}
	void GetAllClockType(BSTR * clockType)
	{
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x1d5, DISPATCH_METHOD, VT_EMPTY, NULL, parms, clockType);
	}
	void GetAllPortAndBoundRate(long nInstrumentType, long nInterfaceType, BSTR * strXML)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x1d6, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nInstrumentType, nInterfaceType, strXML);
	}
	void SetAllPortAndBoundRate(long nInstrumentType, long nInterfaceType, LPCTSTR strXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x1d7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nInstrumentType, nInterfaceType, strXML, ReturnValue);
	}
	void ServerReConnectAllMac(LPCTSTR serverIP, long nInstrumentType, long nInterfaceType, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x1d8, DISPATCH_METHOD, VT_EMPTY, NULL, parms, serverIP, nInstrumentType, nInterfaceType, ReturnValue);
	}
	void IsSupportMultiCom(long nInstrumentType, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x1d9, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nInstrumentType, ReturnValue);
	}
	void GetOneTypeOutDataSourceParam(long nOutDataType, BSTR * strInfo)
	{
		static BYTE parms[] = VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x1da, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nOutDataType, strInfo);
	}
	void SetOneTypeOutDataSourceParam(long nOutDataType, LPCTSTR strInfo, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x1db, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nOutDataType, strInfo, ReturnValue);
	}
	void Close4G(long nGroupID, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x1dc, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nGroupID, ReturnValue);
	}
	void GetSwitchBox(BSTR * strInfo)
	{
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x1dd, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strInfo);
	}
	void ChangeSwitchBox(LPCTSTR strInfo, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x1de, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strInfo, ReturnValue);
	}
	void IsHighLowSampleCheck(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x1df, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void ChangeHighLowSample(long bEnable)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x1e0, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bEnable);
	}
	void SensorAutoCheck(BSTR * strCheckValue, float fltFreq, long nType, long * ReturnValue)
	{
		static BYTE parms[] = VTS_PBSTR VTS_R4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x1e1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strCheckValue, fltFreq, nType, ReturnValue);
	}
	void GetSensorAutoCheckChn(BSTR * strChnXML, long nType)
	{
		static BYTE parms[] = VTS_PBSTR VTS_I4 ;
		InvokeHelper(0x1e2, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strChnXML, nType);
	}
	void ClearRunData(LPCTSTR strChnXML, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x1e3, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strChnXML, ReturnValue);
	}
	void SendToControlDelRunFile(long bDel)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x1e4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bDel);
	}
	void SetChannelFromBinary(long GroupChannelID, LPCTSTR strMachineIP, long ChannelStyle, long ChannelID, long CellID, long point, long nBinarySize, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x1e5, DISPATCH_METHOD, VT_EMPTY, NULL, parms, GroupChannelID, strMachineIP, ChannelStyle, ChannelID, CellID, point, nBinarySize, ReturnValue);
	}
	void SetMultiChannel(LPCTSTR strChannelKeyValue, LPCTSTR strAllChannel, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x1e6, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strChannelKeyValue, strAllChannel, ReturnValue);
	}
	void SetMultiChannelFromBinary(LPCTSTR strChannelKeyValue, long point, long * ReturnValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_PI4 ;
		InvokeHelper(0x1e7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strChannelKeyValue, point, ReturnValue);
	}
	void GetOneMacChnData_Copter(long nMacID, VARIANT * varChnData, long * nTotalDataPos, long * nReceiveCount, long * nChnCount, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PVARIANT VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x1e8, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nMacID, varChnData, nTotalDataPos, nReceiveCount, nChnCount, ReturnValue);
	}
	void WriteHardWareMachineNumber(long ChannelGroupID, LPCTSTR strMachineIP, LPCTSTR strMachineNumber, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x1e9, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ChannelGroupID, strMachineIP, strMachineNumber, ReturnValue);
	}
	void ReadHardWareMachineNumber(long ChannelGroupID, LPCTSTR strMachineIP, BSTR * strMachineNumber, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x1ea, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ChannelGroupID, strMachineIP, strMachineNumber, ReturnValue);
	}
	void IsSupportDataTransJumpPoint(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x1eb, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void IsSupportGPSTiming(long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x1ec, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ReturnValue);
	}
	void GetGPSTimingInfo(long * isUseGPSTiming, __int64 * lGPSTime)
	{
		static BYTE parms[] = VTS_PI4 VTS_PI8 ;
		InvokeHelper(0x1ed, DISPATCH_METHOD, VT_EMPTY, NULL, parms, isUseGPSTiming, lGPSTime);
	}
	void SetGPSTimingInfo(long isUseGPSTiming, __int64 lGPSTime, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I8 VTS_PI4 ;
		InvokeHelper(0x1ee, DISPATCH_METHOD, VT_EMPTY, NULL, parms, isUseGPSTiming, lGPSTime, ReturnValue);
	}
	void ChangeSaveBuffer(long bSaveBuffer)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x1ef, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bSaveBuffer);
	}
	void GetTachoValue(long * nTachoValue)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x1f0, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nTachoValue);
	}
	void ChangeTachoValue(long nTachoValue, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x1f1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nTachoValue, ReturnValue);
	}
	void GetDataIndexInTeam(long nMachineID, LPCTSTR strMachineIP, long nChannelID, long nTeamID, long * nDataIndex, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x1f2, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nMachineID, strMachineIP, nChannelID, nTeamID, nDataIndex, ReturnValue);
	}
	void GetChannelTeamID(long GroupChannelID, LPCTSTR strMachineIP, long nChannelID, long * nTeamID)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_PI4 ;
		InvokeHelper(0x1f3, DISPATCH_METHOD, VT_EMPTY, NULL, parms, GroupChannelID, strMachineIP, nChannelID, nTeamID);
	}
	void GetOneMacTeamChnData(long nMacID, long nTeamID, long point, long nBufferSize, long * nTotalDataPos, long * nReceiveCount, long * nChnCount, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x1f4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nMacID, nTeamID, point, nBufferSize, nTotalDataPos, nReceiveCount, nChnCount, ReturnValue);
	}
	void SetChannelParamInfo(long GroupChannelID, LPCTSTR strMachineIP, long ChannelStyle, long ChannelID, long CellID, long point, long nParamSize, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x1f5, DISPATCH_METHOD, VT_EMPTY, NULL, parms, GroupChannelID, strMachineIP, ChannelStyle, ChannelID, CellID, point, nParamSize, ReturnValue);
	}
	void GetAssignPathPrjInfo(LPCTSTR strMachineIP, long nMachineID, LPCTSTR strAssignPath, BSTR * strXMLPrjInfo)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_BSTR VTS_PBSTR ;
		InvokeHelper(0x1f6, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strMachineIP, nMachineID, strAssignPath, strXMLPrjInfo);
	}
	void GetVIBChnData(long nMachineID, long nChannelID, long nBufferSize, long BufferPoint, long * nReceiveCount, long * nSignalCount, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x1f7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nMachineID, nChannelID, nBufferSize, BufferPoint, nReceiveCount, nSignalCount, ReturnValue);
	}
	void GetTeamID(long nGroupChannelID, long * teamID, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x1f8, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nGroupChannelID, teamID, ReturnValue);
	}
	void GetTeamSampleFreq(long nTeamID, float * fltSampleFreq, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PR4 VTS_PI4 ;
		InvokeHelper(0x1f9, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nTeamID, fltSampleFreq, ReturnValue);
	}
	void SetTeamSampleFreq(long nTeamID, float fltSampleFreq, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_R4 VTS_PI4 ;
		InvokeHelper(0x1fa, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nTeamID, fltSampleFreq, ReturnValue);
	}
	void GetExtraTrigType(long * nExtraTrigType)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x1fb, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nExtraTrigType);
	}
	void SetExtraTrigType(long nExtraTrigType, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x1fc, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nExtraTrigType, ReturnValue);
	}
	void ChangeCurrent(long nMachineID, long nChannelID, float fltCurrentValue, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_R4 VTS_PI4 ;
		InvokeHelper(0x1fd, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nMachineID, nChannelID, fltCurrentValue, ReturnValue);
	}
	void GetFireCapacitorStatus(long * nStatus, long * ReturnValue)
	{
		static BYTE parms[] = VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x1fe, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nStatus, ReturnValue);
	}
	void SetFireDevice(long nType, long * nStatus, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x1ff, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nType, nStatus, ReturnValue);
	}
	void BindCommonToOutputChannel(long nGroupID, LPCTSTR strCommonId, LPCTSTR strOutputId, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x200, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nGroupID, strCommonId, strOutputId, ReturnValue);
	}
	void SetDataToOutputChannel(long nBufferSize, long BufferPoint, long nGroupID, long nOutputChannelId, long * ReturnValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x201, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nBufferSize, BufferPoint, nGroupID, nOutputChannelId, ReturnValue);
	}


};
