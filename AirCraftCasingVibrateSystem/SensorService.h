#pragma once
#include "fftw3.h"
#include "EchoSignal.h"
#include "TbSignalDao.h"
#include "TbProject.h"
#include "AcquiredSignal.h"
#include "ThreadSafeQueue.h"
#include "Result.h"
class CSensorService 
{
public:
	CSensorService();
	CSensorService(int nsignalBuff);
	~CSensorService();
	
	/**********************************************************************
	功能描述： 随机数组
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void RandArray(double* ptr, size_t length);

	/**********************************************************************
	功能描述： 创造随机数
	输入参数：min -- 最小，max--最大
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	double randf(double min, double max);
	/**********************************************************************
	功能描述：从回显信号队列中弹出一个回显信号对像
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	EchoSignal FrontEchoSignalQueue();
	/**********************************************************************
	功能描述：保存采集数据
	输入参数：当前项目,需要保存的队列集合，需要保存的数量 
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	Result AddCollectData(TbProject project, int sensorId, ThreadSafeQueue<AcquiredSignal> &collectionData);

private:
	//queue<EchoSignal> m_echoSignalQueue; ///回显数据的队列
	EchoSignal m_signal; ///需要回显的数据
	TbSignalDao m_signalDao;
public:
	
	static double m_readFromCSVFile[100][1000];//文件的测试数据数组
	
};

