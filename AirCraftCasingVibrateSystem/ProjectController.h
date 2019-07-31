#pragma once
/************************************************************************
Copyright (C), 2018-2020. 哈尔滨理工大学人工智能实验室
文件名称： SignalController.h
内容摘要： 项目相关的业务逻辑.对应的实现类文件为ProjectController.cpp。
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
#include"TbTestingDeviceDao.h"
#include "DetectedDeviceService.h"
#include "TestingDeviceService.h"
#include "TbProject.h"
#include "ProjectService.h"
#include"Result.h"
class ProjectController
{
public:
	ProjectController();
	~ProjectController();

	TestingDeviceService m_testingDeviceService;

	DetectedDeviceService m_detectedDeviceService;

	ProjectService m_projectService;

	/**********************************************************************
	功能描述：加载所有的测试设备
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	Result LoadAllTestingDevice(vector<TbTestingDeviceDao> & tbTestingVec);

	/**********************************************************************
	功能描述：加载所有的被检测设备
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	Result LoadAllDetectedDevice(vector<TbDetectedDeviceDao> & TbDetectedDeviceDaoVec);

	/**********************************************************************
	功能描述：新建项目
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	Result AddProject(TbProject & project);

	/**********************************************************************
	功能描述：根据查询条件加载所有的项目
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	Result LoadAllProjectBySearchCondition(int testerId, CString projectName, CString startTime, CString endTime,vector<TbProject> &projectVector);
};

