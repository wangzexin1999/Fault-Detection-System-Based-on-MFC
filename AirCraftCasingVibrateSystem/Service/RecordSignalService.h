#pragma once
#include"TbRecordSignal.h"
#include "TbProductDao.h"
#include"TbRecordSignalDao.h"
#include "TbCollectionparasDao.h"
#include "TbProjectDao.h"
class RecordSignalService
{

protected:
	TbRecordSignalDao m_recordSignalDao;
	TbProductDao	m_productDao;
	TbCollectionparasDao m_collectionparasDao;
	TbProjectDao m_projectDao;
public:
	RecordSignalService();
	~RecordSignalService();

	/**********************************************************************
	功能描述：添加记录信号数据
	输入参数：TbRecordSignal
	***********************************************************************/

	bool AddRecordSignal(TbRecordSignal recordSignal);
	/**********************************************************************
	功能描述：根据查询条件查询所有的记录数据
	输入参数： 项目名称 ，产品名称，转速，信号采集时间，信号
	采集时间：信号的集合。
	返 回 值：Result对象
	其它说明：查询采样数据文件，主要针对产品的型号和转速进行查询
	***********************************************************************/
	bool FindAllRecordSignalBySearchCondition(TbRecordSignal searchEntity, vector<TbRecordSignal> &signalVector);
};

