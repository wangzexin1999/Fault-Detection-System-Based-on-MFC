/************************************************************************
Copyright (C), 2018-2020. 哈尔滨理工大学人工智能实验室
文件名称： DictionaryController.h
内容摘要： 字典表的相关逻辑操作，服务层，用于调dao 层
其它说明：飞机机匣振动检测系统
当前版本： 1.0
作 者： 马善涛
创建日期： 2019-09-09
完成日期:
History:
1. Date:    2018-09-09         Author:马善涛
Modification:
修改记录 1： // 修改历史记录，包括修改日期、修改者及修改内容
修改日期：
版 本 号：
修 改 人：
修改内容：
************************************************************************/
#pragma once
#include "TbDictionary.h"
#include "TbDictionaryDao.h"

#include <vector>
using namespace  std;
class DictionaryService
{

private:
	TbDictionaryDao m_dictionaryDao;

public:
	DictionaryService();
	~DictionaryService();
	/**********************************************************************
	功能描述：得到指定字典名的所有字典对象
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	bool GetAllBySearchCondition(vector<TbDictionary> & dictionaryVec, TbDictionary searchEntity);
};

