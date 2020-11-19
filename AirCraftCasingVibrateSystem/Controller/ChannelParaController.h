
#pragma once
#include "TbProject.h"
#include "Result.h"
#include "ChannelParaService.h"
#include "vector"
using namespace std;
class ChannelParaController
{

private:
	ChannelParaService channelParaService;

public:
	ChannelParaController();
	~ChannelParaController();

	/**********************************************************************
	功能描述：查询指定项目的传感器参数
	输入参数：
	输出参数：
	返 回 值：Result 对象
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	Result FindALLChannelParaByProjectId(TbProject &project);
};

