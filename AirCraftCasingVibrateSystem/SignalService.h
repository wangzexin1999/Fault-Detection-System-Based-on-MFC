#pragma once
/************************************************************************
文件名称： SignalService.h
内容摘要： 信号相关的业务逻辑.对应的实现类文件为SignalService.cpp。
************************************************************************/

#include "TbSumsignal.h"
#include "TbSignalDao.h"
#include "TbSignal.h"
#include "TbSumsignal.h"
#include "TbChannel.h"
#include "TbChannelDao.h"
#include "CommonUtil.h"
#include "TbSumsignalDao.h"
#include "TbProductDao.h"
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
	TbProductDao m_productDao;
	
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
	bool SaveSignal(TbSignal saveSignal);

	bool saveSumSignal(TbSumsignal sumSignal);

	bool updateSumSignal(TbSumsignal sumSignal);

	/**********************************************************************
	功能描述：根据产品编号获取总信号
	输入参数：productId--文件路径
	输出参数： sumSignalVec--总信号集合
	返 回 值： ture--成功； false--打开文件失败
	***********************************************************************/
	bool GetSumSignalByProductId(int productId, vector<TbSumsignal> &sumSignalVec);

	/**********************************************************************
	功能描述： 得到指定SumSignalId的所有信号。
	输入参数：sumSignalId--总信号编号；signals--信号集合
	***********************************************************************/
	bool GetSignalsBySumSignalId(CString sumSignalId, vector<TbSignal> &signals);

	/**********************************************************************
	功能描述：根据查询条件查询所有的记录数据
	输入参数： 项目名称 ，产品名称，转速，信号采集时间，信号
	采集时间：信号的集合。
	返 回 值：Result对象
	其它说明：查询采样数据文件，主要针对产品的型号和转速进行查询
	***********************************************************************/
	bool FindAllSumSignalBySearchCondition(TbSumsignal searchEntity, vector<TbSumsignal> &signalVector);
};

