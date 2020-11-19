/************************************************************************
�ļ����ƣ� SignalController.h
����ժҪ�� ������������صķ���ҵ���߼�.��Ӧ��ʵ�����ļ�ΪChannelParaService.cpp��
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
	����������������Ŀid�õ����еĴ���������
	***********************************************************************/
	bool GetALLChannelParaByCollectionparasId(int collectionparasId, std::vector<TbChannel> &vchannelPara);
};

