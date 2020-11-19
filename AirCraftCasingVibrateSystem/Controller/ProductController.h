
#pragma once
#include "ProductService.h"
#include "Result.h"
class ProductController
{

private:
	ProductService m_productService;
public:
	ProductController();
	~ProductController();

	/**********************************************************************
	功能描述：加载所有的产品
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	Result FindAllProduct(vector<TbProduct> & TbProductDaoVec);
	/**********************************************************************
	功能描述： 根据产品id删除产品
	输入参数： 检测设备
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	Result DeleteByProductId(TbProduct product);
	/**********************************************************************
	 功能描述： 更新产品
	 输入参数：
	 输出参数： 
	 返 回 值： 
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	Result UpdateProduct(TbProduct product);
	/**********************************************************************
	 功能描述： 添加产品
	 输入参数：
	 输出参数： 
	 返 回 值： 
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	Result AddProduct(TbProduct product);
	/**********************************************************************
	 功能描述： 搜索产品根据名
	 输入参数：
	 输出参数： 
	 返 回 值： 
	 其它说明：
	 修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	Result FindProductByProductName(TbProduct product,vector<TbProduct> &vProduct);

};

