#include "stdafx.h"
#include "FileUtil.h"
#include "CommonUtil.h"


//���ļ�
bool CFileUtil::OpenFile(CString &sFilePath,  CString sRootPath)
{
	//**********************ѡ���ļ�*************************
	BOOL isOpen = TRUE;		//�Ƿ��(����Ϊ����)
	//CString defaultDir = "";	//Ĭ�ϴ򿪵��ļ�·��
	CString fileName = _T("");			//Ĭ�ϴ򿪵��ļ���
	CString m_sRootPath = _T(sRootPath);        // Ĭ��·��
	CString filter = _T("�ļ� (*.txt; *.json; *.xml;*.*)|*.txt;*.json;*.xml;*.*||");
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

//�����ļ�
bool CFileUtil::SaveFile(CString &sFilePath, CString sRootPath)
{
	try
	{
		BOOL isOpen = FALSE;		//�Ƿ��(����Ϊ����)
		CString defaultDir = _T("D:\\");	//Ĭ�ϴ򿪵��ļ�·��
		CString fileName = _T("test.txt");			//Ĭ�ϴ򿪵��ļ���
		CString filter = _T("�ļ� (*.txt; *.doc; *.xls)|*.txt;*.doc;*.xls||");	//�ļ����ǵ�����
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


/*���ļ�*/
bool CFileUtil::ReadFile(CString sFilePath, double(&outRead)[100][1000])
{

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	// ���ļ�Ŀ¼
	 sFilePath = _T("H:\\��Ŀ\\���������ϼ��\\train_data.csv");
	// ������
	CStdioFile fileRead;
	if (!fileRead.Open(sFilePath, CFile::modeRead))//�Զ�ģʽ���ı��ļ�
	{
		return false;
	}
	
	
	CString FileData;           //����һ��CString������Ϊ������
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




/*�������ݴ洢*/
//void CFileUtil::SaveSampleData(vector<queue<double>> signalData)
//{
//	this->m_signalData = signalData;
//	int channelCount = 0,queueCount = 0;
//	/*ɾ����������*/
//	for (int i = 0; i < signalData.size(); i++)
//	{
//		if (signalData[i].size() == 0)
//		{
//			signalData.erase(signalData.begin() + i,signalData.end());
//			break;
//		}
//	}
//	/*������ʼ��*/
//	channelCount = signalData.size();
//	queueCount = signalData[0].size();
//	CString channelString, douhaoString = ",",channelName = _T("ͨ��");
//	/*дͨ��*/
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
//	/*д����*/
//	CFile file;
//	if (!file.Open(_T("H:\\test.csv"), CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate, NULL))
//	{
//		return;
//	}
//	channelString = channelString + "\n";
//	file.Write(channelString, strlen(channelString));
//	/*д����*/
//	vector<EchoSignal> vSignal;
//	int vSignalNums = 0;
//	CString yStr = "";
//	for (int i = 0; i < queueCount; i++)
//	{
//		/*ÿ��ͨ������*/
//		for (int j = 0; j < channelCount; j++)
//		{
//			vSignal.push_back(signalData[j].front());
//			signalData[j].pop();
//		}
//		vSignalNums = vSignal.size();
//		/*ƴ��*/
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

Result CFileUtil::SaveCollectionData(vector<ThreadSafeQueue<AcquiredSignal>> &collectData, CString path, CString fileName, int saveCount){
	if (collectData.size() == 0) return Result(false, "д�����ݲ���Ϊ��"); //vectorΪ�գ��򲻲���
	if (saveCount <= 0) return Result(false, "������������Ϊ0");///��Ҫ���������Ϊ�գ��򲻲���
	CFile file;///�ļ�����
	if (!file.Open(_T(path+fileName), CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate, NULL)){
		return Result(false, "�����ļ�ʧ��"); ////�����ļ�ʧ�ܣ��򲻲���
	}
	CString separator = ",";////���ŷָ���
	///ѭ��д������
	CString endTime="";
	for (int i = 0; i < saveCount;i++){

		if (i == saveCount - 1){
			////��������һ�����ݣ��õ����Ľ���ʱ��
			if (collectData[0].size()!=0){
				endTime = collectData[0].front().GetAcquireTime();
			}
			for (int j = 1; j < collectData.size(); j++){
				if (collectData[j].size() != 0){
					CString acquireTime = collectData[j].front().GetAcquireTime();
					if (acquireTime < endTime) endTime = acquireTime;
				}
			}
		}
		CString data="";
		///ƴװ�ַ���
		int j;
		////���λ��ÿ��ͨ��������
		for (j = 0; j < collectData.size() - 1;j++){
			data += CommonUtil::DoubleOrFloat2CString(collectData[j].wait_and_pop()->GetSignalData()) + separator;
		}
		////������һ��ͨ��������
		if (!collectData[j].empty()){
			data += CommonUtil::DoubleOrFloat2CString(collectData[j].wait_and_pop()->GetSignalData());
		}
		////����׷�ӻ���
		data += "\n";
		file.Write(data, strlen(data));
	}
	file.Close();
	return Result(true, endTime);
}