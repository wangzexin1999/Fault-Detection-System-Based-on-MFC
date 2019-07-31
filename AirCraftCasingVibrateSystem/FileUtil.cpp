#include "stdafx.h"
#include "FileUtil.h"


CFileUtil::CFileUtil()
{
}


CFileUtil::~CFileUtil()
{
}




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
	 sFilePath = _T("D:\\train_data.csv");
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

/*采样数据存储*/
void CFileUtil::SaveSampleData(vector<queue<CSignal>> signalData)
{
	this->m_signalData = signalData;
	int channelCount = 0,queueCount = 0;
	/*删除无用数据*/
	for (int i = 0; i < signalData.size(); i++)
	{
		if (signalData[i].size() == 0)
		{
			signalData.erase(signalData.begin() + i,signalData.end());
			break;
		}
	}
	/*变量初始化*/
	channelCount = signalData.size();
	queueCount = signalData[0].size();
	CString channelString, douhaoString = ",",channelName = _T("通道");
	/*写通道*/
	for (int k = 0; k < channelCount; k++)
	{
		CString iTempStr;
		iTempStr.Format("%d",k+1);
		
		if (k == channelCount-1)
		{
			channelString = channelString + channelName + iTempStr;
		}
		else
		{
			channelString = channelString + channelName + iTempStr + douhaoString;
		}
	}
	/*写操作*/
	CFile file;
	if (!file.Open(_T("D:\\test.csv"), CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate, NULL))
	{
		return;
	}
	channelString = channelString + "\n";
	file.Write(channelString, strlen(channelString));
	/*写数据*/
	vector<CSignal> vSignal;
	int vSignalNums = 0;
	CString yStr = "";
	for (int i = 0; i < queueCount; i++)
	{
		/*每个通道出队*/
		for (int j = 0; j < channelCount; j++)
		{
			vSignal.push_back(signalData[j].front());
			signalData[j].pop();
		}
		vSignalNums = vSignal.size();
		/*拼接*/
		for (int m = 0; m < 1000; m++)
		{
			for (int n = 0; n < vSignalNums; n++)
			{
				CString yStrTemp;
				yStrTemp.Format("%lf", vSignal[n].m_Y[m]);
				if (n == vSignalNums - 1)
				{
					yStr = yStr + yStrTemp;
				}
				else
				{
					yStr = yStr+yStrTemp + douhaoString;
				}
				
			}
			yStr = yStr + "\n";
			file.Write(yStr, strlen(yStr));
			yStr = "";
			
		}
		vSignal.clear();
		
	}
	file.Close();

	
	

}