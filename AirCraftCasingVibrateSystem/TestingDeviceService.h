/************************************************************************
Copyright (C), 2018-2020. 哈尔滨理工大学人工智能实验室
文件名称： GeneralParaView.h
内容摘要： 检测设备服务逻辑。对应的实现类文件为TestingDeviceService.cpp。
其它说明：飞机机匣振动检测系统
当前版本： 1.0
作 者： 马善涛
创建日期： 2019-08-16
完成日期:
History:
1. Date:    2018-08-16         Author:马善涛
Modification:
修改记录 1： // 修改历史记录，包括修改日期、修改者及修改内容
修改日期：
版 本 号：
修 改 人：
修改内容：
************************************************************************/
#pragma once
#include"TbTestingDeviceDao.h"
#include"TbDictionaryDao.h"

class TestingDeviceService
{

private:
	TbTestingDeviceDao m_testingDeviceDao;
	TbDictionaryDao m_dictionaryDao;
public:
	TestingDeviceService();

	~TestingDeviceService();
	/**********************************************************************
	功能描述： 加载所有的采集设备
	输入参数： 查询到的检测设备集合
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	bool GetAllTestingDevice(vector<TbTestingDeviceDao> & tbTestingVec);

	/**********************************************************************
	功能描述： 根据查询条件查询所有的采集设备
	输入参数： 检测设备名称，查询到的检测设备集合
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	bool GetAllTestingDeviceBySearchCondition(TbTestingDevice searchEntity, vector<TbTestingDevice> &testingDeviceVector);
	/**********************************************************************
	功能描述： 根据id查询采集设备
	输入参数：  
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	bool GetOneById(TbTestingDevice &searchEntity);

	/**********************************************************************
	功能描述： 根据检测设备id删除检测设备
	输入参数： 检测设备id
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	bool Update(TbTestingDevice testingDevice);
	/**********************************************************************
	功能描述： 保存检测设备
	输入参数： 检测设备
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	bool AddTestingDevice(TbTestingDevice testingDevice);
	/**********************************************************************
	功能描述： 根据条件删除检测设备及其参数
	输入参数： 检测设备
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	bool Delete(TbTestingDevice testingDevice);
};

