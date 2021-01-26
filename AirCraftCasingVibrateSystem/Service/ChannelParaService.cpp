#include "stdafx.h"
#include "ChannelParaService.h"
#include "CommonUtil.h"
#include "TbDictionaryDao.h"
ChannelParaService::ChannelParaService(){}
ChannelParaService::~ChannelParaService(){}

////������Ŀid�õ����еĴ���������
bool ChannelParaService::GetALLChannelParaByCollectionparasId(int collectionparasId, std::vector<TbChannel> &vchannelPara){
	m_channelDao.m_collectionparasId.SetValue(collectionparasId);
	vector<TbChannelDao> selectedValueVector;
	m_channelDao.SelectObjectsByCondition(selectedValueVector, "collectionparas_id='" + CommonUtil::Int2CString(collectionparasId) + "'");
	if (!selectedValueVector.empty()){
		////������������Ϊ��ʱ
		for (auto tbsenorParaDao : selectedValueVector){
			////���ݲ�ѯ���Ĵ�����������װTbChannel����
			TbChannel channelPara;
			tbsenorParaDao.GetTableFieldValues(channelPara);
			////���ݴ��������������idȥ���ֵ���Ӧ���ֵ�ֵ

			TbDictionaryDao  dictionaryDao;
			dictionaryDao.SelectByObject(channelPara.GetWindowType());
			dictionaryDao.SelectByObject(channelPara.GetTriggerPolarity());
			dictionaryDao.SelectByObject(channelPara.GetCoordinateSystem());
			dictionaryDao.SelectByObject(channelPara.GetCoordinateSystemDirection());
			dictionaryDao.SelectByObject(channelPara.GetEngineeringUnits());
			dictionaryDao.SelectByObject(channelPara.GetIntegralType());
			dictionaryDao.SelectByObject(channelPara.GetIntegralUnits());
			//dictionaryDao.SelectByObject(channelPara.GetInputMode());
			dictionaryDao.SelectByObject(channelPara.GetChannelStatus());
			dictionaryDao.SelectByObject(channelPara.GetChannelStatus());

			////���뵽��������������
			vchannelPara.push_back(channelPara);
		}
	}
	return true;
}