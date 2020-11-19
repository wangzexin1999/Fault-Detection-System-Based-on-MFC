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

/*�������*/
void CChannelService::RandArray(double* ptr, size_t length)
{
	for (size_t i = 0; i<length; ++i)
	{
		ptr[i] = randf(-1, 1);
	}
}
/*���*/
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
	///1.ƴװ����·��
	CString path = "C:/collectionData/";
	//CString escapePath = "C:\\\\collectionData\\\\";

	//2.ƴװ�ļ��� ��Ŀid_�����豸id_������id_��Ʒid_ʱ���
	CString fileName = CommonUtil::Int2CString(sumsignal.GetProjectId()) + "-"
		+ CommonUtil::Int2CString(sumsignal.GetCollectionparasId())
		//+ "-" + signal.GetChannels() + "-" + CommonUtil::Int2CString(signal.GetProductId())
		+ "-" + DateUtil::GetTimeStampCString()
		+ ".csv";

	CString startCollectTime = collectionData.front().GetAcquireTime();
	
	
	Result res;
	/*����������ӵ�Զ�̷������������ݵ�Զ�̣����򱣴浽����*/
	if ((strcmp(theApp.PDsql.m_mysql.host, "127.0.0.1") == 0) || (strcmp(theApp.PDsql.m_mysql.host, "localhost") == 0))
	{
		//����FileUtil�����ļ�������ɹ����زɼ��Ľ���ʱ��
		res = CFileUtil::SaveCollectionData(path, fileName, collectionData);

		if (res.GetIsSuccess()){
		///�ļ�����ɹ�������¼���浽���ݿ�
		sumsignal.SetDataUrl(path + fileName);
		/*signal.SetStartTime(startCollectTime);
		signal.SetEndTime(res.GetMessages());*/
		sumsignal.SetStartTime(startCollectTime);


		//signal.GetTestingDevice().SetTestingdeviceId(project.GetTestingDevicePara().GetTestingdevice().GetId());
		m_sumsignalDao.SetTableFieldValues(sumsignal);

		/*�������ݿ�������ֹ���߳�*/
		WaitForSingleObject(m_hMsqlMutex, INFINITE);
		m_sumsignalDao.Insert(false);
		ReleaseMutex(m_hMsqlMutex);
		}
	}
	else
	{
		CString separator = ",";////���ŷָ���
		CString endTime;
		CString allData = "";
		int saveCount = collectionData.size();
		for (int i = 0; i < saveCount; i++){
			////ѭ���ɼ����ݵĶ���ȥ��������
			CString data = "";
			shared_ptr<AcquiredSignal>	acquireSignal = collectionData.wait_and_pop();
			data += acquireSignal->GetAcquireTime() + separator;
			data += CommonUtil::DoubleOrFloat2CString(acquireSignal->GetSignalData()) + "\n";
			if (i == saveCount - 1) endTime = acquireSignal->GetAcquireTime();
			allData = allData + data;
		}

		// ������������Ϸ�������������
		httplib::MultipartFormDataItems items = {
			{ "data", allData.GetBuffer(), "1.txt", "text/plain" },//����
			{ "projectID", CommonUtil::Int2CString(sumsignal.GetProductId()).GetBuffer(), "", "" },
			//{ "checkDeviceID", CommonUtil::Int2CString(project.GetTestingDevicePara().GetTestingdevice().GetId()).GetBuffer(), "", "" },
			//{ "sensorID", signal.GetChannels().GetBuffer(), "", "" },
			{ "startTime", startCollectTime.GetBuffer(), "", "" },
			{ "endTime", endTime.GetBuffer(), "", "" },
			{ "productID", CommonUtil::Int2CString(sumsignal.GetProductId()).GetBuffer(), "", "" },
		};
		auto result = theApp.m_cli.Post("/collection", items);
		if (!result)//���û�з��ͳɹ��������·���
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
		///��ѯ�ɹ�֮��
		for (auto channelDao : channelDaoVec){
			TbChannel tbChannel;
			channelDao.GetTableFieldValues(tbChannel);
			channelVector.push_back(tbChannel);
		}
	}
	return isSuccess;
}



////������Ŀid�õ����еĴ���������
bool CChannelService::GetALLChannelByCollectionparasId(int collectionparasId, std::vector<TbChannel> &vchannelPara){
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
			dictionaryDao.SelectByObject(channelPara.GetInputMethod());
			dictionaryDao.SelectByObject(channelPara.GetChannelStatus());
			dictionaryDao.SelectByObject(channelPara.GetChannelStatus());
			dictionaryDao.SelectByObject(channelPara.GetMessureType());

			////���뵽��������������
			vchannelPara.push_back(channelPara);
		}
	}
	return true;
}

////��Ӵ�����
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