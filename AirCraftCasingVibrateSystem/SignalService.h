#pragma once
/************************************************************************
文件名称： SignalService.h
内容摘要： 信号相关的业务逻辑.对应的实现类文件为SignalService.cpp。
************************************************************************/

#include "TbSumsignal.h"
#include "TbSignalDao.h"
#include "TbSignal.h"
#include "TbChannel.h"
#include "TbChannelDao.h"
#include "CommonUtil.h"
#include "TbSumsignalDao.h"
#include "ThreadSafeQueue.h"
#include "TbChannelDao.h"
#include <map>
class SignalService
{
public:
	SignalService();
	~SignalService();

protected:
	TbChannelDao m_channelParaDao;
	//TbProductDao m_productDao;
	TbSignalDao m_SignalDao;
	//TbSumsignalDao m_SumsignalDao;
	static HANDLE m_hMsqlMutex;
public:
	/**********************************************************************
	功能描述：根据查询条件查询所有的采集数据
	返 回 值：Result对象
	其它说明：查询采集数据
	***********************************************************************/
	bool GetAllSignalBySearchCondition(TbSignal searchEntity, vector<TbSignal> &sumsignalVector);

	/**********************************************************************
	功能描述：保存信号数据
	输入参数：封装好的signal对象，需要保存的信号队列
	***********************************************************************/
	//bool AddSignalData(map<CString, ThreadSafeQueue<double>> & acquireSignal, TbSignal &saveSumsignal);

	/**********************************************************************
	功能描述：保存信号数据
	输入参数：封装好的signal对象，需要保存的信号队列
	***********************************************************************/
	bool AddSignal(TbSignal saveSignal);

};

