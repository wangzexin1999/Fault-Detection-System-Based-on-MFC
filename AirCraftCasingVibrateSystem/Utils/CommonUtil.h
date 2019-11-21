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
	/**********************************************************************
	 功能描述： long 转CString 
	 输入参数：
	 输出参数： 
	 返 回 值： 
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	static CString Long2CString(long lValue);
	/**********************************************************************
	 功能描述： Cstring 转long
	 输入参数：
	 输出参数： 
	 返 回 值： 
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	static long CString2Long(CString strValue);
	/**********************************************************************
	 功能描述： Cstring to int
	 输入参数：
	 输出参数： 
	 返 回 值： 
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	static int CString2Int(CString strValue);

};

