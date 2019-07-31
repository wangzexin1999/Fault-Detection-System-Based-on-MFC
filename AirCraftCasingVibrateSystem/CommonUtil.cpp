#include "stdafx.h"
#include "CommonUtil.h"


CommonUtil::CommonUtil()
{
}


CommonUtil::~CommonUtil()
{
}
CString CommonUtil::int2CString(int num){
	CString str;
	str.Format("%d", num);
	return str;
}