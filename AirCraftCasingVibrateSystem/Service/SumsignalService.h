#pragma once
/************************************************************************
�ļ����ƣ� SignalService.h
����ժҪ�� �ź���ص�ҵ���߼�.��Ӧ��ʵ�����ļ�ΪSignalService.cpp��
************************************************************************/

#include "TbSumsignal.h"
#include "TbChannel.h"
#include "TbChannelDao.h"
#include "CommonUtil.h"
#include "TbProductDao.h"
#include "TbSumsignalDao.h"
#include "ThreadSafeQueue.h"
#include <map>
class SumsignalService
{
public:
	SumsignalService();
	~SumsignalService();
	  
protected:
	TbChannelDao m_channelParaDao;
	TbProductDao m_productDao;
	TbSumsignalDao m_SumsignalDao;
	static HANDLE m_hMsqlMutex;
public:
	/**********************************************************************
	�������������ݲ�ѯ������ѯ���еĲɼ�����
	�� �� ֵ��Result����
	����˵������ѯ�ɼ�����
	***********************************************************************/
	bool GetAllSignalBySearchCondition(TbSumsignal searchEntity, vector<TbSumsignal> &sumsignalVector);

	/**********************************************************************
	���������������ź�����
	�����������װ�õ�signal������Ҫ������źŶ���
	***********************************************************************/
	bool AddSignalData(map<CString, ThreadSafeQueue<double>> & acquireSignal, TbSumsignal &saveSumsignal);

	/**********************************************************************
	���������������ź�����
	�����������װ�õ�signal������Ҫ������źŶ���
	***********************************************************************/
	bool AddSignal(TbSumsignal saveSumsignal);

};

