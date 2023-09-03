#pragma once
#include "Result.h"
#include "TbTestlocation.h"
#include "TbTestlocationDao.h"
class TestService
{

private:
	TbTestlocationDao m_testLocationDao;

public:
	TestService();
	~TestService();
	/**********************************************************************
	功能描述：查询采集设备对应的所有传感器
	输入参数：采集设备id
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	bool FindAllTestLocationByProductTypeId(int productTypeId, vector<TbTestlocation> & testLocationVec);

	/**********************************************************************
	功能描述：查询采集设备对应的所有传感器
	输入参数：采集设备id
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	bool GetTestLocationById(int locationId, TbTestlocation &testLoation);


};

