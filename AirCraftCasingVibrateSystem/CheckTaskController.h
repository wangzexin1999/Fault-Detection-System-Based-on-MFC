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

#include "SignalService.h"

//struct threadPara
//{
//	CCheckTaskController *checkController;
//	int  channelIndex;
//	
//};
class CCheckTaskController
{
public:
	CCheckTaskController();
	~CCheckTaskController();


public:
	// 读取数据线程一共16个线程
	HANDLE m_pReadDataThread[16];
	static unsigned int __stdcall ReadDataThreadProcing(PVOID pM);
	/**********************************************************************
	功能描述： 开启线程读取数据
	输入参数：通道的个数
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	int StartCaptureData(int nChannelNum);


public:
	static HANDLE m_hMutex;

};

