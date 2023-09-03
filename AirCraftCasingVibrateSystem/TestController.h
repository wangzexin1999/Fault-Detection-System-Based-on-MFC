#pragma once
#include "Result.h"
#include "TbTestlocationDao.h"
#include "TbTestlocation.h"
#include "ProductService.h"
#include "TestService.h"
class TestController
{

private:
	TestService m_testService;
	ProductService m_productService;
public:
	TestController();

	~TestController();

	/**********************************************************************
	功能描述：查询指定产品的所有测点位置
	输入参数：采集设备id
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	Result FindAllTestLocationByProductId(int productId, vector<TbTestlocation> & testLocationVec);


	/**********************************************************************
	功能描述：查询指定编号的测点位置
	输入参数：采集设备id
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	Result GetTestLocationById(int locationId, TbTestlocation &testLoation);
};

