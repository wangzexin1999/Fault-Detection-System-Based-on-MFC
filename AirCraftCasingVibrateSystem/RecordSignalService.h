#pragma once
#include"TbRecordSignal.h"
#include"TbRecordSignalDao.h"
class RecordSignalService
{

protected:
	TbRecordSignalDao m_recordSignalDao;

public:
	RecordSignalService();
	~RecordSignalService();

	/**********************************************************************
	功能描述：添加记录信号数据
	输入参数：TbRecordSignal
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	bool AddRecordSignal(TbRecordSignal recordSignal);
};

