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
#include "TbRecordSignal.h"
#include "TbRecordSignalDao.h"
class SignalService
{
public:
	SignalService();
	~SignalService();
	  
protected:
	TbSensorDao m_sensorParaDao;
	TbProductDao m_productDao;
	TbRecordSignalDao m_recordSignalDao;
public:

	/**********************************************************************
	功能描述：根据查询条件查询所有的记录数据
	输入参数：查询信号对象，信号采集时间，信号结束采集时间。信号的集合。
	输出参数：
	返 回 值：bool
	其它说明：
	修改日期	 版本号		修改人		修改内容
	2019-07-30   1.0		马善涛		初始化
	----------------------------------------------------------------------
	***********************************************************************/
	bool GetAllRecordedSignalBySearchCondition(TbRecordSignal signal, CString startTime, CString endTime, vector<TbRecordSignal> &signalVector);
	
};

