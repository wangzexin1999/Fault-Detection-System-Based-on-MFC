#include "stdafx.h"
#include "FileUtil.h"
#include "CommonUtil.h"
#include "AirCraftCasingVibrateSystem.h"
#include "DateUtil.h"
//打开文件
bool CFileUtil::OpenFile(CString &sFilePath,  CString sRootPath)
{
	//**********************选择文件*************************
	BOOL isOpen = TRUE;		//是否打开(否则为保存)
	//CString defaultDir = "";	//默认打开的文件路径
	CString fileName = _T("");			//默认打开的文件名
	CString m_sRootPath = _T(sRootPath);        // 默认路径
	CString filter = _T("文件 (*.txt; *.json; *.xml;*.*)|*.txt;*.json;*.xml;*.*||");
	CFileDialog openFileDlg(isOpen, NULL, fileName, OFN_HIDEREADONLY | OFN_READONLY, filter, NULL);
	openFileDlg.GetOFN().lpstrInitialDir = m_sRootPath;
	INT_PTR result = openFileDlg.DoModal();
	CString strFolderPath = m_sRootPath;
	if (result == IDOK) {
		strFolderPath = openFileDlg.GetPathName();
	}
	m_sRootPath = strFolderPath;
	sFilePath = strFolderPath;

	return true;

}


template<class T>
int length(T& arr)
{
	//cout << sizeof(arr[0]) << endl;
	//cout << sizeof(arr) << endl;
	return sizeof(arr) / sizeof(arr[0]);
}

bool CFileUtil::WirteFile(CString sFilePath, double dX[], double dY[],int dataSize)
{

	CFile file;
	if (file.Open(sFilePath, CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate, NULL))
	{
		for (int i = 0; i < dataSize; i++)
		{
			CString xStr;
			xStr.Format("%lf", dX[i]);
			CString yStr;
			yStr.Format("%lf", dY[i]);
			CString xyStr;
			xyStr = xStr + " " + yStr + "\n";
			file.Write(xyStr, strlen(xyStr));
		}
		file.Close();
	}
	else
	{
		return false;
	}
	return true;

}

//保存文件
bool CFileUtil::SaveFile(CString &sFilePath, CString sRootPath)
{
	try
	{
		BOOL isOpen = FALSE;		//是否打开(否则为保存)
		CString defaultDir = _T("D:\\");	//默认打开的文件路径
		CString fileName = _T("test.txt");			//默认打开的文件名
		CString filter = _T("文件 (*.txt; *.doc; *.xls)|*.txt;*.doc;*.xls||");	//文件过虑的类型
		CFileDialog openFileDlg(isOpen, defaultDir, fileName, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, filter, NULL);
		openFileDlg.GetOFN().lpstrInitialDir = _T("E:\\FileTest\\test.doc");
		INT_PTR result = openFileDlg.DoModal();
		CString filePath = defaultDir + "\\" + fileName;
		if (result == IDOK) {
			filePath = openFileDlg.GetPathName();
		}
		sFilePath = filePath;
		return true;
	}
	catch (CString str)
	{
		return false;
	}
	
	
	
}


/*读文件*/
bool CFileUtil::ReadFile(CString sFilePath, double(&outRead)[100][1000])
{

	// TODO:  在此添加控件通知处理程序代码
	// 打开文件目录
	 sFilePath = _T("C:\\train_data.csv");
	// 读数据
	CStdioFile fileRead;
	if (!fileRead.Open(sFilePath, CFile::modeRead))//以读模式打开文本文件
	{
		return false;
	}
	
	CString FileData;           //定义一个CString变量作为缓冲区
	CString str;
	double xTemp, y;
	for (int i = 0; i < 100; i++)
	{
		fileRead.ReadString(FileData);
		for (int j = 0; j < 1000; j++)
		{
			AfxExtractSubString(str, FileData, j, _T(','));
			xTemp = _ttof(str);//ecg data
			outRead[i][j] = xTemp;

		}
	}
	fileRead.Close();
	return true;
}




//Result CFileUtil::SaveCollectionData(CString path, CString fileName, int saveCount){
//	this->m_signalData = signalData;
//	int channelCount = 0,queueCount = 0;
//	/*删除无用数据*/
//	for (int i = 0; i < signalData.size(); i++)
//	{
//		if (signalData[i].size() == 0)
//		{
//			signalData.erase(signalData.begin() + i,signalData.end());
//			break;
//		}
//	}
//	/*变量初始化*/
//	channelCount = signalData.size();
//	queueCount = signalData[0].size();
//	CString channelString, douhaoString = ",",channelName = _T("通道");
//	/*写通道*/
//	for (int k = 0; k < channelCount; k++)
//	{
//		CString iTempStr;
//		iTempStr.Format("%d",k+1);
//		
//		if (k == channelCount-1)
//		{
//			channelString = channelString + channelName + iTempStr;
//		}
//		else
//		{
//			channelString = channelString + channelName + iTempStr + douhaoString;
//		}
//	}
//	/*写操作*/
//	CFile file;
//	if (!file.Open(_T("H:\\test.csv"), CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate, NULL))
//	{
//		return;
//	}
//	channelString = channelString + "\n";
//	file.Write(channelString, strlen(channelString));
//	/*写数据*/
//	vector<EchoSignal> vSignal;
//	int vSignalNums = 0;
//	CString yStr = "";
//	for (int i = 0; i < queueCount; i++)
//	{
//		/*每个通道出队*/
//		for (int j = 0; j < channelCount; j++)
//		{
//			vSignal.push_back(signalData[j].front());
//			signalData[j].pop();
//		}
//		vSignalNums = vSignal.size();
//		/*拼接*/
//		for (int m = 0; m < 1000; m++)
//		{
//			for (int n = 0; n < vSignalNums; n++)
//			{
//				CString yStrTemp;
//				yStrTemp.Format("%lf", vSignal[n].m_Y[m]);
//				if (n == vSignalNums - 1)
//				{
//					yStr = yStr + yStrTemp;
//				}
//				else
//				{
//					yStr = yStr+yStrTemp + douhaoString;
//				}
//				
//			}
//			yStr = yStr + "\n";
//			file.Write(yStr, strlen(yStr));
//			yStr = "";
//			
//		}
//		vSignal.clear();
//		
//	}
//	file.Close();
//}


/*
////获得开始采集时间
for (int i = 0; i < theApp.m_vSignalAcquisitionService.size() ; i++){
if (theApp.m_vSignalAcquisitionService[0].GetCollectDataSize() != 0){
CString acquiredTime = theApp.m_vSignalAcquisitionService[i].GetCollectData().front().GetAcquireTime();
if (acquiredTime < startTime){
startTime = acquiredTime;
}
}
}
///循环写入数据
for (int i = 0,j = 0; i < saveCount;i++){
////如果是最后一条数据，拿到结束采集时间
if (i == saveCount - 1){
if (theApp.m_vSignalAcquisitionService[0].GetCollectDataSize() != 0){
endTime = theApp.m_vSignalAcquisitionService[0].GetCollectData().front().GetAcquireTime();
}
for (int j = 1; j < theApp.m_vSignalAcquisitionService.size(); j++){
if (theApp.m_vSignalAcquisitionService[j].GetCollectDataSize() != 0){
CString acquireTime = theApp.m_vSignalAcquisitionService[0].GetCollectData().front().GetAcquireTime();
if (acquireTime < endTime) endTime = acquireTime;
}
}
}
CString data="";
///拼装字符串
////依次获得每个通道的数据
for (j = 0; j < theApp.m_vSignalAcquisitionService.size() - 1; j++){
data += CommonUtil::DoubleOrFloat2CString(theApp.m_vSignalAcquisitionService[j].GetCollectData().wait_and_pop()->GetSignalData()) + separator;
}
////获得最后一个通道的数据
data += CommonUtil::DoubleOrFloat2CString(theApp.m_vSignalAcquisitionService[j].GetCollectData().wait_and_pop()->GetSignalData());
////程序追加换行
data += "\n";
file.Write(data, strlen(data));
}
////获得最后一条数据的结束时间

*/
Result CFileUtil::SaveCollectionData(CString path, CString fileName, ThreadSafeQueue<AcquiredSignal> &collectionData){
	
	CFile file;///文件对象
	if (!file.Open(_T(path+fileName), CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate, NULL)){
		return Result(false, "创建文件失败"); ////创建文件失败，则不操作
	}
	CString separator = ",";////逗号分隔符
	CString endTime;
	int saveCount = collectionData.size();
	for (int i = 0; i < saveCount;i++){
		////循环采集数据的队列去保存数据
		CString data = "";
		shared_ptr<AcquiredSignal>	acquireSignal = collectionData.wait_and_pop();
		data += acquireSignal->GetAcquireTime() + separator;
		data += CommonUtil::DoubleOrFloat2CString(acquireSignal->GetSignalData()) + "\n";
		if (i == saveCount - 1) endTime = acquireSignal->GetAcquireTime();
		file.Write(data, strlen(data));
	}
	file.Close();
	return Result(true, endTime);
}


// 转换成JSON格式
bool  CFileUtil::RealTimeSignal2JSON(vector<double> dYValue, vector<CString> dXValue, int nDataLen, int nChannelIndex, CString &strData)
{
	try
	{
		// 拼接坐标
		CString xy;
		CString tailStr = "],";
		for (int i = 0; i < nDataLen; i++)
		{
			char  ytemp[10];

			sprintf_s(ytemp, "%.1lf", dYValue[i]);
			if (i == nDataLen - 1)
			{
				tailStr = "]]\"";
			}
			xy = xy + "[" + dXValue[i] + "," + ytemp + tailStr;
		}

		xy = "\"[" + xy;
		CString indexStr;
		indexStr.Format("%d", nChannelIndex);
		// 加入通道
		strData = strData + "\"channel" + indexStr + "\":" + xy;
	}
	catch (CMemoryException* e)
	{
		return false;
	}
	catch (CFileException* e)
	{
		return false;
		
	}
	catch (CException* e)
	{
		return false;
	}
	
	return true;

}

// 实时数据转成JSON格式
bool  CFileUtil::RealTimeSignal2JSON(double dYValue[], string dXValue[], int nDataLen, int nChannelIndex, CString &strData)
{

	CString xy;
	CString tailStr = "],";
	int length = 800;
	for (int i = 0; i < length; i++)
	{
	char  ytemp[10];

	sprintf_s(ytemp, "%.1lf", dYValue[i]);
	if (i == length - 1)
	{
	tailStr = "]]\"";
	}
	xy = xy + "[" + dXValue[i].c_str() + "," + ytemp + tailStr;
	}

	xy = "\"[" + xy;
	CString indexStr;

	//indexStr.Format("%d", i);

	/*if (i != m_nChannelNums)
	{
	strData = strData + "\"channel" + indexStr + "\":" + xy + ",";
	}
	else
	{
	strData = strData + "\"channel" + indexStr + "\":" + xy;
	}*/


	//strData = "{" + strData + "}";
	return 0;

}


void CFileUtil::SeparateCString(CString strInput, char cSeparator, vector<CString> &strOutput)
{

	while (TRUE)
	{
		int index = strInput.Find(_T(cSeparator));
		if (index == -1)
		{
			strOutput.push_back(strInput);
			break;
		}
		CString test1 = strInput.Left(index);
		strOutput.push_back(test1);
		strInput = strInput.Right(strInput.GetLength() - index - 1);
	}
}

bool CFileUtil::ReadSampleDataByPath(CString strFilePath, vector<AcquiredSignal> &sampleSignal)
{

	// 打开文件
	// 读数据
	CStdioFile fileRead;
	if (!fileRead.Open(strFilePath, CFile::modeRead))//以读模式打开文本文件
	{
		return false;
	}
	CString strFileData;           //定义一个CString变量作为缓冲区,读取一行
	CString strSplitDataAndTime;  // 时间
	double dSplitData;    // 数据
	while (fileRead.ReadString(strFileData))
	{
		AcquiredSignal signalTemp;
		AfxExtractSubString(strSplitDataAndTime, strFileData, 0, _T(','));
		signalTemp.SetAcquireTime(strSplitDataAndTime); // 时间
		AfxExtractSubString(strSplitDataAndTime, strFileData, 1, _T(','));
		dSplitData = _ttof(strSplitDataAndTime);//ecg data
		signalTemp.SetSignalData(dSplitData);
		sampleSignal.push_back(signalTemp);
	}
	fileRead.Close();

}

bool CFileUtil::ReadSampleDataByPaths(vector<CString> vStrFilePaths, vector<AcquiredSignal> &sampleSignal)
{
	int nFileNums = vStrFilePaths.size();
	
	for (int i = 0; i < nFileNums; i++)
	{
		// 读数据
		CStdioFile fileRead;
		// 打开文件
		if (!fileRead.Open(vStrFilePaths[i], CFile::modeRead))//以读模式打开文本文件
		{
			return false;
		}
		CString strFileData;           //定义一个CString变量作为缓冲区,读取一行
		CString strSplitDataAndTime;  // 时间
		double dSplitData;    // 数据
		while (fileRead.ReadString(strFileData))
		{
			AcquiredSignal signalTemp;
			AfxExtractSubString(strSplitDataAndTime, strFileData, 0, _T(',')); // 数据
			signalTemp.SetAcquireTime(strSplitDataAndTime); // 时间
			AfxExtractSubString(strSplitDataAndTime, strFileData, 1, _T(','));  // 时间
			dSplitData = _ttof(strSplitDataAndTime);//ecg data
			signalTemp.SetSignalData(dSplitData);
			sampleSignal.push_back(signalTemp);
		}
		fileRead.Close();//关闭文件
	}
	
}

bool  CFileUtil::SaveCollectionData(CString path, CString fileName, map<CString, ThreadSafeQueue<double>> & acquireSignal){
	CFile file;///文件对象
	if (!file.Open(_T(path + fileName), CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate, NULL)){ return false; }
	CString separator = ",";////逗号分隔符
	CString endTime;
	int saveCount = acquireSignal[0].size();
	int channelCount = acquireSignal.size();
	map<CString, ThreadSafeQueue<double>>::iterator signalDataIterator;
	for (int i = 0; i < saveCount; i++){
		////循环采集数据的队列去保存数据
		CString data = "";
		signalDataIterator = acquireSignal.begin();
		for (int i = 0; i < channelCount-1;i++){
			shared_ptr<DOUBLE> signal = signalDataIterator->second.wait_and_pop();
			data += CommonUtil::DoubleOrFloat2CString(*signal) + separator;
			signalDataIterator++;
		}
		data += CommonUtil::DoubleOrFloat2CString(*signalDataIterator->second.wait_and_pop()) + "\n";
		file.Write(data, strlen(data));
	}
	file.Close();
	return true;
}