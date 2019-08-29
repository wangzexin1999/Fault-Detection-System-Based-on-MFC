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
class SignalController
{

private:
	SignalService m_signalService;
	ProjectService m_projectService;
public:
	SignalController();
	~SignalController();
	/**********************************************************************
	功能描述：根据查询条件查询所有的记录数据
	输入参数：项目名称 ，产品名称，转速，信号采集时间，信号结束采集时间。信号的集合。
	输出参数：
	返 回 值：Result对象
	其它说明：
	修改日期	 版本号		修改人		修改内容
	2019-07-30   1.0		马善涛		初始化	
	----------------------------------------------------------------------
	***********************************************************************/
	Result LoadAllRecordedSignalBySearchCondition(CString projectName, CString productName, CString rotatingSpeed, CString startTime, CString endTime, vector<TbSignal> &signalVector);
};

