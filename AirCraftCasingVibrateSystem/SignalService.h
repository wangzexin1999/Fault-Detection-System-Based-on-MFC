#pragma once
/************************************************************************
Copyright (C), 2018-2020. 哈尔滨理工大学人工智能实验室
文件名称： SignalController.h
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
#include "fftw3.h"
#include"TbRecordSignalDao.h"
#include"TbSignal.h"
#include "TbSensorPara.h"
#include "TbSensorParaDao.h"
#include "CommonUtil.h"
#include "TbDetectedDeviceDao.h"
class SignalService
{
public:
	SignalService();
	~SignalService();

protected:
	TbSensorParaDao m_sensorParaDao;
	TbRecordSignalDao m_recordSignalDao;
	TbDetectedDeviceDao m_detectedDeviceDao;
public:
	/**********************************************************************
	功能描述： FFT变换
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	bool FastFourierTransformation(int nCounts, fftw_complex *din, fftw_complex *out);

	/**********************************************************************
	功能描述：根据查询条件查询所有的记录数据
	输入参数：项目id ，信号名称，信号采集时间，信号结束采集时间。信号的集合。
	输出参数：
	返 回 值：bool
	其它说明：
	修改日期	 版本号		修改人		修改内容
	2019-07-30   1.0		马善涛		初始化
	----------------------------------------------------------------------
	***********************************************************************/
	bool GetAllRecordedSignalBySearchCondition(int projectId, CString signalName, CString startTime, CString endTime, vector<TbSignal> &signalVector);
	
};

