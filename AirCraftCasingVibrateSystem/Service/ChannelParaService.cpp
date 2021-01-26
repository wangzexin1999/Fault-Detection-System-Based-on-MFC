#include "stdafx.h"
#include "ChannelParaService.h"
#include "CommonUtil.h"
#include "TbDictionaryDao.h"
ChannelParaService::ChannelParaService(){}
ChannelParaService::~ChannelParaService(){}

////根据项目id得到所有的传感器参数
bool ChannelParaService::GetALLChannelParaByCollectionparasId(int collectionparasId, std::vector<TbChannel> &vchannelPara){
	m_channelDao.m_collectionparasId.SetValue(collectionparasId);
	vector<TbChannelDao> selectedValueVector;
	m_channelDao.SelectObjectsByCondition(selectedValueVector, "collectionparas_id='" + CommonUtil::Int2CString(collectionparasId) + "'");
	if (!selectedValueVector.empty()){
		////传感器参数不为空时
		for (auto tbsenorParaDao : selectedValueVector){
			////根据查询到的传感器参数封装TbChannel对象
			TbChannel channelPara;
			tbsenorParaDao.GetTableFieldValues(channelPara);
			////根据传感器各类参数的id去查字典表对应的字典值

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

			////存入到传感器参数集合
			vchannelPara.push_back(channelPara);
		}
	}
	return true;
}