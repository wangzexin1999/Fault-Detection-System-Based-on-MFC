#pragma once
/************************************************************************
文件名称： SignalService.h
内容摘要： 信号相关的业务逻辑.对应的实现类文件为SignalService.cpp。
************************************************************************/

#include "TbSumsignal.h"
#include "TbChannel.h"
#include "TbChannelDao.h"
#include "CommonUtil.h"
#include "TbProductDao.h"
#include "TbSumsignalDao.h"
#include "ThreadSafeQueue.h"
#include <map>
class SumsignalService
{
public:
	SumsignalService();
	~SumsignalService();
	  
protected:
	TbChannelDao m_channelParaDao;
	TbProductDao m_productDao;
	TbSumsignalDao m_SumsignalDao;
	static HANDLE m_hMsqlMutex;
public:
	/**********************************************************************
	功能描述：根据查询条件查询所有的采集数据
	返 回 值：Result对象
	其它说明：查询采集数据
	***********************************************************************/
	bool GetAllSignalBySearchCondition(TbSumsignal searchEntity, vector<TbSumsignal> &sumsignalVector);

	/**********************************************************************
	功能描述：保存信号数据
	输入参数：封装好的signal对象，需要保存的信号队列
	***********************************************************************/
	bool AddSignalData(map<CString, ThreadSafeQueue<double>> & acquireSignal, TbSumsignal &saveSumsignal);

	/**********************************************************************
	功能描述：保存信号数据
	输入参数：封装好的signal对象，需要保存的信号队列
	***********************************************************************/
	bool AddSignal(TbSumsignal saveSumsignal);

};

