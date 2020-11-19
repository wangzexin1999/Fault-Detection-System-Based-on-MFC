#include "stdafx.h"
#include "ChannelService.h"
#include "FileUtil.h"
#include "CommonUtil.h"
#include "DateUtil.h"
#include "AirCraftCasingVibrateSystem.h"
#include "Constant.h"
CChannelService::CChannelService()
{
	//m_signalBuff.CreateBuffer(102400);
}

CChannelService::CChannelService(int nsignalBuff)
{
	//m_signalBuff.CreateBuffer(nsignalBuff);
}


CChannelService::~CChannelService()
{

}

HANDLE CChannelService::m_hMsqlMutex = CreateMutex(NULL, FALSE, NULL);

/*随机数组*/
void CChannelService::RandArray(double* ptr, size_t length)
{
	for (size_t i = 0; i<length; ++i)
	{
		ptr[i] = randf(-1, 1);
	}
}
/*随机*/
double CChannelService::randf(double min, double max)
{
	int minInteger = (int)(min * 10000);
	int maxInteger = (int)(max * 10000);
	int randInteger = rand()*rand();
	int diffInteger = maxInteger - minInteger;
	int resultInteger = randInteger % diffInteger + minInteger;
	return resultInteger / 10000.0;
}

Result CChannelService::AddCollectData(TbSumsignal &sumsignal, ThreadSafeQueue<AcquiredSignal> &collectionData){
	///1.拼装保存路径
	CString path = "C:/collectionData/";
	//CString escapePath = "C:\\\\collectionData\\\\";

	//2.拼装文件名 项目id_测试设备id_传感器id_产品id_时间戳
	CString fileName = CommonUtil::Int2CString(sumsignal.GetProjectId()) + "-"
		+ CommonUtil::Int2CString(sumsignal.GetCollectionparasId())
		//+ "-" + signal.GetChannels() + "-" + CommonUtil::Int2CString(signal.GetProductId())
		+ "-" + DateUtil::GetTimeStampCString()
		+ ".csv";

	CString startCollectTime = collectionData.front().GetAcquireTime();
	
	
	Result res;
	/*如果可以连接到远程服务器则发送数据到远程，否则保存到本地*/
	if ((strcmp(theApp.PDsql.m_mysql.host, "127.0.0.1") == 0) || (strcmp(theApp.PDsql.m_mysql.host, "localhost") == 0))
	{
		//调用FileUtil保存文件，保存成功返回采集的结束时间
		res = CFileUtil::SaveCollectionData(path, fileName, collectionData);

		if (res.GetIsSuccess()){
		///文件保存成功，将记录保存到数据库
		sumsignal.SetDataUrl(path + fileName);
		/*signal.SetStartTime(startCollectTime);
		signal.SetEndTime(res.GetMessages());*/
		sumsignal.SetStartTime(startCollectTime);


		//signal.GetTestingDevice().SetTestingdeviceId(project.GetTestingDevicePara().GetTestingdevice().GetId());
		m_sumsignalDao.SetTableFieldValues(sumsignal);

		/*加上数据库锁，防止多线程*/
		WaitForSingleObject(m_hMsqlMutex, INFINITE);
		m_sumsignalDao.Insert(false);
		ReleaseMutex(m_hMsqlMutex);
		}
	}
	else
	{
		CString separator = ",";////逗号分隔符
		CString endTime;
		CString allData = "";
		int saveCount = collectionData.size();
		for (int i = 0; i < saveCount; i++){
			////循环采集数据的队列去保存数据
			CString data = "";
			shared_ptr<AcquiredSignal>	acquireSignal = collectionData.wait_and_pop();
			data += acquireSignal->GetAcquireTime() + separator;
			data += CommonUtil::DoubleOrFloat2CString(acquireSignal->GetSignalData()) + "\n";
			if (i == saveCount - 1) endTime = acquireSignal->GetAcquireTime();
			allData = allData + data;
		}

		// 如果可以连接上服务器，传数据
		httplib::MultipartFormDataItems items = {
			{ "data", allData.GetBuffer(), "1.txt", "text/plain" },//数据
			{ "projectID", CommonUtil::Int2CString(sumsignal.GetProductId()).GetBuffer(), "", "" },
			//{ "checkDeviceID", CommonUtil::Int2CString(project.GetTestingDevicePara().GetTestingdevice().GetId()).GetBuffer(), "", "" },
			//{ "sensorID", signal.GetChannels().GetBuffer(), "", "" },
			{ "startTime", startCollectTime.GetBuffer(), "", "" },
			{ "endTime", endTime.GetBuffer(), "", "" },
			{ "productID", CommonUtil::Int2CString(sumsignal.GetProductId()).GetBuffer(), "", "" },
		};
		auto result = theApp.m_cli.Post("/collection", items);
		if (!result)//如果没有发送成功，则重新发送
		{
			httplib::Client cli(_T(ServerHttpAddress), ServerHttpPort);
			theApp.m_cli = cli;
			auto result = theApp.m_cli.Post("/collection", items);
		}
		sumsignal.SetEndTime(endTime);
	}
	return res;
}

bool  CChannelService::GetAllChannelByCollectionparasId(int collectionparasId, vector<TbChannel>& channelVector){
	vector<TbChannelDao> channelDaoVec;
	bool isSuccess = m_channelDao.SelectObjectsByCondition(channelDaoVec, "collectionparas_id='" + CommonUtil::Int2CString(collectionparasId) + "'");
	if (isSuccess){
		///查询成功之后
		for (auto channelDao : channelDaoVec){
			TbChannel tbChannel;
			channelDao.GetTableFieldValues(tbChannel);
			channelVector.push_back(tbChannel);
		}
	}
	return isSuccess;
}



////根据项目id得到所有的传感器参数
bool CChannelService::GetALLChannelByCollectionparasId(int collectionparasId, std::vector<TbChannel> &vchannelPara){
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
			dictionaryDao.SelectByObject(channelPara.GetInputMethod());
			dictionaryDao.SelectByObject(channelPara.GetChannelStatus());
			dictionaryDao.SelectByObject(channelPara.GetChannelStatus());
			dictionaryDao.SelectByObject(channelPara.GetMessureType());

			////存入到传感器参数集合
			vchannelPara.push_back(channelPara);
		}
	}
	return true;
}

////添加传感器
bool CChannelService::AddChannel(TbChannel &channel){
	m_channelDao.SetTableFieldValues(channel);
	bool isSuccess = m_channelDao.Insert(false);
	m_channelDao.GetTableFieldValues(channel);
	return isSuccess;
}
bool CChannelService::Delete(TbChannel channel){
	CString strSqlWhere = "1 = 1 ";
	if (channel.GetId() != 0)
		strSqlWhere += " and id ='" + CommonUtil::Int2CString(channel.GetId()) + "'";
	if (channel.GetChannelCode() != "")
		strSqlWhere += " and channel_code ='" + channel.GetChannelCode() + "'";
	if (channel.GetCollectionparasId() != 0)
		strSqlWhere += " and collectionparas_id ='" + CommonUtil::Int2CString(channel.GetCollectionparasId()) + "'";
	return m_channelDao.DeleteByCondition(strSqlWhere);
}
bool CChannelService::Update(TbChannel channel){
	m_channelDao.SetTableFieldValues(channel);
	bool isSuccess = m_channelDao.UpdateByKey();
	return isSuccess;
}