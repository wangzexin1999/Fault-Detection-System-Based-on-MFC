
#pragma once
#include "TbCollectionparas.h"
#include "Result.h"
#include <vector>
#include "CollectionparasService.h"
using namespace  std;
class CollectionparasController
{

private:
	CollectionparasService m_collectionparasService;
public:
	CollectionparasController();
	~CollectionparasController();

	/**********************************************************************
	功能描述： 根据查询条件加载采集设备
	输入参数： 检测设备名称，查询到的检测设备集合 
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	Result FindAllCollectionparasBySearchCondition(CString collectionparasName, vector<TbCollectionparas> &collectionparasVector);

	/**********************************************************************
	功能描述： 根据检测设备id删除检测设备
	输入参数： 检测设备
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	Result DeleteByCollectionparasId(TbCollectionparas collectionparas);

	/**********************************************************************
	功能描述： 保存检测设备
	输入参数： 检测设备
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	Result AddCollectionparas(TbCollectionparas collectionparas);

	/**********************************************************************
	功能描述： 更新检测设备
	输入参数： 检测设备
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	Result UpdateCollectionparas(TbCollectionparas collectionparas);

};

