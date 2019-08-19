/************************************************************************
Copyright (C), 2018-2020. 哈尔滨理工大学人工智能实验室
文件名称： SignalController.h
内容摘要： 对字典表的数据库操作类.对应的实现类文件为TbDictionaryDao.cpp。
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
#include "PDDatabase.h"
#include "TbDictionary.h"
class TbDictionaryDao :
	public PDDatabase
{
public:
	TbDictionaryDao();
	TbDictionaryDao(const TbDictionaryDao  & dictionary);
	~TbDictionaryDao();
public:
	PDAttribute m_dictId;
	PDAttribute m_dictName;
	PDAttribute m_dictValue;

	/**********************************************************************
	功能描述：根据TbDictionaryDao的属性值，封装参数给TbDictionary
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void GetTableFieldValues(TbDictionary &dictionary);

	/**********************************************************************
	功能描述：根据主键查询字典数据
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void SelectByObject(TbDictionary &dictionary);
};

