#include "stdafx.h"
#include "CommonUtil.h"



CString CommonUtil::Int2CString(int num){
	CString str;
	str.Format("%d", num);
	return str;
}
///将字符串按照指定的分割字符分割成一个int型的vector向量
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
	///倒着查最后一层目录，分隔符是 “//”
	statIndex = path.ReverseFind('//'); 
	///如果分隔符不是“//”，而是“\\”
	if (statIndex == -1){ statIndex = statIndex = path.ReverseFind('\\\\'); }
	///如果分隔符是‘/’
	if (statIndex == -1){ statIndex = statIndex = path.ReverseFind('/'); }
	///如果分隔符是‘\’
	if (statIndex == -1){ statIndex = statIndex = path.ReverseFind('\\'); }
	///删掉文件路径中文件的后缀名
	path.Delete(path.Find(_T(".")), path.GetLength());
	///返回分割之后的字符串
	return path.Right(path.GetLength()-1-statIndex);
}