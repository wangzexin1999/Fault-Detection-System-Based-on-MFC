#pragma once
/************************************************************************
Copyright (C), 2018-2020. 哈尔滨理工大学人工智能实验室
文件名称： SignalController.h
内容摘要： 信号数据相关的业务逻辑.对应的实现类文件为SignalController.cpp。
其它说明：飞机机匣振动检测系统
当前版本： 1.0
作 者： 马善涛
创建日期： 2019-07-30
完成日期:
History:
1. Date:    2018-07-30         Author:马善涛
Modification:
修改记录 1： // 修改历史记录，包括修改日期、修改者及修改内容
修改日期：
版 本 号：
修 改 人：
修改内容：
************************************************************************/
#include "Result.h"
#include "TbSignal.h"
#include "SignalService.h"
#include "ProjectService.h"
#include "ProductService.h"
#include "TbRecordSignal.h"
#include "RecordSignalService.h"
#include "ThreadSafeQueue.h"
#include "AcquiredSignal.h"
#include <fstream>
#include <map>
using namespace std;
struct SignalInfoHeader{
	/*通道个数*/
	int m_iChannelNums = 0;
	/*开始通道*/
	char m_cStartChannel[4];
	/*结束通道*/
	char m_cEndChannel[4];
	/*采集频率*/
	int m_iCollectFre = 0;
	/*采集计划参数*/
	char  m_cCollectPlanPara[500];
	/*信号大小*/
	long long m_llSiganlSize = 0;
};



class SignalController
{

private:
	SignalService m_signalService;
	ProjectService m_projectService;
	RecordSignalService m_recordSignalService;
	ProductService m_productService;


public:
	SignalController();
	~SignalController();
	/**********************************************************************
	功能描述：根据查询条件查询所有的记录数据
	输入参数： 项目名称 ，产品名称，转速，信号采集时间，信号
	采集时间。信号的集合。
	输出参数：
	返 回 值：Result对象
	其它说明：查询采样数据文件，主要针对产品的型号和转速进行查询
	修改日期	 版本号		修改人		修改内容
	2019-07-30   1.0		马善涛		初始化	
	----------------------------------------------------------------------
	***********************************************************************/
	Result FindAllRecordSignalBySearchCondition(TbRecordSignal searchEntity, vector<TbRecordSignal> &signalVector);
	
	/**********************************************************************
	功能描述：保存采样的数据
	输入参数：当前窗口的id，传感器的id
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	Result SaveSampleSignal(TbRecordSignal m_recordSignal);

	/**********************************************************************
	功能描述：保存采集的数据
	输入参数：当前窗口的id，传感器的id
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	Result SaveCollectionSignal(TbSignal m_collectionSignal);
	/**********************************************************************
	功能描述：根据查询条件查询所有的采集数据
	输入参数：  
	输出参数：
	返 回 值：Result对象
	其它说明：查询采集数据
	修改日期	 版本号		修改人		修改内容
	2019-07-30   1.0		马善涛		初始化
	----------------------------------------------------------------------
	***********************************************************************/
	Result FindAllSignalBySearchCondition(TbSignal searchEntity, vector<TbSignal> &signalVector);

	/**********************************************************************
	功能描述：保存采集的数据
	输入参数：当前窗口的id，传感器的id
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	Result SaveSignalData(map<CString, ThreadSafeQueue<double>> & acquireSignal,TbSignal &saveSignal);
	/**********************************************************************
	功能描述： 保存采样数据为二进制文件
	输入参数：outputStream--输出流；acquireSigna--采集信号
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	bool SaveCollectionData2Binary(ofstream &outputStream, map<CString, ThreadSafeQueue<double>> & acquireSigna);
	/**********************************************************************
	 功能描述： 得到采集数据
	 输入参数：inputStream--输入流；
				llStart--开始位置，默认是从头开始；llend--结束位置，默认是文件结尾
	 输出参数：vSignal--信号； 
	 返 回 值： true--继续；false--读完了 
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	bool GetCollectionData(ifstream &inputStream, long long llfileSize,long long llStart, long long llReadSize, vector<double>& vSignal);
	/**********************************************************************
	功能描述： 保存采样数据的二进制文件头部信息
	输入参数：outputStream--输出流；signalInfoHeader--采集信号信息头
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void SaveCollectionDataHeadInfo(CString fileName, SignalInfoHeader  signalInfoHeader);
	/**********************************************************************
	 功能描述：获得采集数据的二进制文件头部信息
	 输入参数：fileName--文件路径
	 输出参数： signalInfoHeader--头信息
	 返 回 值： ture--成功； false--打开文件失败
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	bool GetCollectionDataHeadInfo(CString fileName, SignalInfoHeader& signalInfoHeader);

};

