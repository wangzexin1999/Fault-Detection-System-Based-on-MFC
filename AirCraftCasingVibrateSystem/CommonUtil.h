#pragma once
#include<vector>
using namespace std;
class CommonUtil
{
public:

	static CString Int2CString(int num);
	static CString DoubleOrFloat2CString(double num);
	static void GetIntVectorFromSplitCString(CString strSource, CString separator, vector<int> & intVector);
	static vector<CString> GetCStringVectorFromSplitCString(CString strSource, CString separator);
	static CString GetFileNameFromFilePath(CString path);
	
	CString GetMergeCString(CString str1,CString separtor,CString str2);
};

