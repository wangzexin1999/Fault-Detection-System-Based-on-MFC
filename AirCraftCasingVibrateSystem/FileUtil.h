/************************************************************************
Copyright (C), 2018-2020. 哈尔滨理工大学人工智能实验室
文件名称： FileController.h
内容摘要： 文件操作，包括文件的读写，数据处理。对应的实现类文件为FileController.cpp。
其它说明：飞机机匣振动检测系统
当前版本： 1.0
作 者： 刘望
创建日期： 2019-06-21
完成日期:
History:
1. Date:    2018-06-21         Author:刘望
Modification:
修改记录 1： // 修改历史记录，包括修改日期、修改者及修改内容
修改日期：
版 本 号：
修 改 人：
修改内容：
************************************************************************/
#pragma once
#include "Signal.h"
#include <vector>
#include <queue>
#include "AcquiredSignal.h"
#include "Result.h"
#include "ThreadSafeQueue.h"
using namespace std;


class CFileUtil
{

public:
	/**********************************************************************
	功能描述： 打开文件
	输入参数： sRootPath---要打开文件夹路径，默认D:  
	输出参数： sFilePath--文件路径
	返 回 值： false---获得失败  true---获得成功
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	 bool OpenFile(CString &sFilePath,  CString sRootPath = "D:");
	/**********************************************************************
	功能描述： 写文件
	输入参数： sFilePath---要写数据的目录，默认D:,dX[]--X数据，dY--Y数据
	输出参数： 
	返 回 值： false---写入失败  true---失败成功
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	bool WirteFile(CString sFilePath,double dX[],double dY[],int dataSize);
	/**********************************************************************
	功能描述： 保存文件
	输入参数： sRootPath---要打开文件夹路径，默认D:
	输出参数： sFilePath--文件路径
	返 回 值： false---获得失败  true---获得成功
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	bool SaveFile(CString &sFilePath, CString sRootPath = "D:");
	/**********************************************************************
	 功能描述： 
	 输入参数： 
	 输出参数： 
	 返 回 值： 
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	 ----------------------------------------------------------------------
	 ***********************************************************************/
	bool ReadFile(CString sFilePath, double (&outRead)[100][1000]);
	/**********************************************************************
	 功能描述： 保存采样数据
	 输入参数： queue的vector向量，文件保存路径，文件名字，保存数量 
	 输出参数： 
	 返 回 值： 
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	 ----------------------------------------------------------------------
	 ***********************************************************************/
	static Result SaveCollectionData(vector<ThreadSafeQueue<AcquiredSignal>> &collectData, CString path, CString fileName, int saveCount);
};

