/************************************************************************
文件名称： SignalController.h
内容摘要： 传感器参数相关的服务业务逻辑.对应的实现类文件为ChannelParaService.cpp。
************************************************************************/
#pragma once
#include "TbChannelDao.h"
#include "TbChannel.h"
#include <vector>
using namespace std;
class ChannelParaService
{

private:
	TbChannelDao m_channelDao;
public:
	ChannelParaService();
	~ChannelParaService();

	/**********************************************************************
	功能描述：根据项目id得到所有的传感器参数
	***********************************************************************/
	bool GetALLChannelParaByCollectionparasId(int collectionparasId, std::vector<TbChannel> &vchannelPara);
};

