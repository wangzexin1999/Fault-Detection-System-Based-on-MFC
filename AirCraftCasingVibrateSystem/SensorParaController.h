/************************************************************************
Copyright (C), 2018-2020. 哈尔滨理工大学人工智能实验室
文件名称： SignalController.h
内容摘要： 传感器参数相关的业务逻辑.对应的实现类文件为SensorParaController.cpp。
其它说明：飞机机匣振动检测系统
当前版本： 1.0
作 者： 马善涛
创建日期： 2019-08-15
完成日期:
History:
1. Date:    2019-08-15         Author:马善涛
Modification:
修改记录 1： // 修改历史记录，包括修改日期、修改者及修改内容
修改日期：
版 本 号：
修 改 人：
修改内容：
************************************************************************/
#pragma once
#include "TbProject.h"
#include "Result.h"
#include "SensorParaService.h"
#include "vector"
using namespace std;
class SensorParaController
{

private:
	SensorParaService sensorParaService;

public:
	SensorParaController();
	~SensorParaController();

	/**********************************************************************
	功能描述：查询指定项目的传感器参数
	输入参数：
	输出参数：
	返 回 值：Result 对象
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	Result FindALLSensorParaByProjectId(TbProject &project);
};

