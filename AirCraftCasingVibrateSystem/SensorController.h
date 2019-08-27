/************************************************************************
Copyright (C), 2018-2020. 哈尔滨理工大学人工智能实验室
文件名称： SignalMainController.h
内容摘要： 信号主业务逻辑.主要实现信号的业务逻辑。对应的实现类文件为SignalMainController.cpp。
其它说明：飞机机匣振动检测系统
当前版本： 1.0
作 者： 刘望
创建日期： 2019-05-24
完成日期:
History:
1. Date:    2018-05-24         Author:刘望
Modification:
修改记录 1： // 修改历史记录，包括修改日期、修改者及修改内容
修改日期：
版 本 号：
修 改 人：
修改内容：
************************************************************************/
#define DELAY_TIME 10
#pragma once
#include "SensorService.h"
#include "Result.h"
class SensorController
{

private:
	CSensorService m_sensorService;
	static HANDLE m_popCollectDataQueueMutex;  ///弹出采集队列元素的线程锁
	static HANDLE m_popSampleDataQueueMutex;  ///弹出采样队列元素的线程锁
public:
	SensorController();
	~SensorController();


public:
	/**********************************************************************
	功能描述：保存采集的数据
	输入参数：当前窗口的id，传感器的id
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	Result SaveCollectionData(int sensorId, ThreadSafeQueue<AcquiredSignal> &collectionData);

	/**********************************************************************
	功能描述：保存采集的数据
	输入参数：当前窗口的id，传感器的id
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	Result SaveSampleData(int sensorId, ThreadSafeQueue<AcquiredSignal> &collectionData);

	/**********************************************************************
	功能描述：查询采集设备对应的所有传感器
	输入参数：采集设备id
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	Result FindAllSensorByTestingDeviceId(int testingDeviceId, vector<TbSensor> & sensorVector);
};

