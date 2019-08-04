#include "stdafx.h"
#include "CommonUtil.h"



CString CommonUtil::Int2CString(int num){
	CString str;
	str.Format("%d", num);
	return str;
}
///���ַ�������ָ���ķָ��ַ��ָ��һ��int�͵�vector����
void CommonUtil::GetIntVectorFromSplitCString(CString strSource, CString separator, vector<int> & intVector){
	int iPos = 0;
	CString strTmp;
	strTmp = strSource.Tokenize(separator, iPos);

	while (strTmp.Trim() != _T(""))
	{
		intVector.push_back(atoi(strTmp));
		strTmp = strSource.Tokenize(separator, iPos);
	}
}

CString CommonUtil::GetFileNameFromFilePath(CString path){
	int statIndex = -1;
	///���Ų����һ��Ŀ¼���ָ����� ��//��
	statIndex = path.ReverseFind('//'); 
	///����ָ������ǡ�//�������ǡ�\\��
	if (statIndex == -1){ statIndex = statIndex = path.ReverseFind('\\\\'); }
	///����ָ����ǡ�/��
	if (statIndex == -1){ statIndex = statIndex = path.ReverseFind('/'); }
	///����ָ����ǡ�\��
	if (statIndex == -1){ statIndex = statIndex = path.ReverseFind('\\'); }
	///ɾ���ļ�·�����ļ��ĺ�׺��
	path.Delete(path.Find(_T(".")), path.GetLength());
	///���طָ�֮����ַ���
	return path.Right(path.GetLength()-1-statIndex);
}