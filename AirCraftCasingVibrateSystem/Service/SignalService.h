#pragma once
/************************************************************************
Copyright (C), 2018-2020. 哈尔滨理工大学人工智能实验室
文件名称： SignalService.h
内容摘要： 信号相关的业务逻辑.对应的实现类文件为SignalService.cpp。
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

#include"TbSignal.h"
#include "TbSensor.h"
#include "TbSensorDao.h"
#include "CommonUtil.h"
#include "TbProductDao.h"
#include "TbSignal.h"
#include "TbSignalDao.h"
#include "ThreadSafeQueue.h"
#include <map>
class SignalService
{
public:
	SignalService();
	~SignalService();
	  
protected:
	TbSensorDao m_sensorParaDao;
	TbProductDao m_productDao;
	TbSignalDao m_signalDao;
	static HANDLE m_hMsqlMutex;
public:
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
	bool GetAllSignalBySearchCondition(TbSignal searchEntity, vector<TbSignal> &signalVector);

	/**********************************************************************
	功能描述：保存信号数据
	输入参数：封装好的signal对象，需要保存的信号队列
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	bool AddSignalData(map<CString, ThreadSafeQueue<double>> & acquireSignal, TbSignal &saveSignal);

	/**********************************************************************
	功能描述：保存信号数据
	输入参数：封装好的signal对象，需要保存的信号队列
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	bool AddSignal(TbSignal saveSignal);

};

