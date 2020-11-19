#pragma once
/************************************************************************
�ļ����ƣ� SignalService.h
����ժҪ�� �ź���ص�ҵ���߼�.��Ӧ��ʵ�����ļ�ΪSignalService.cpp��
************************************************************************/

#include "TbSumsignal.h"
#include "TbSignalDao.h"
#include "TbSignal.h"
#include "TbChannel.h"
#include "TbChannelDao.h"
#include "CommonUtil.h"
#include "TbSumsignalDao.h"
#include "ThreadSafeQueue.h"
#include "TbChannelDao.h"
#include <map>
class SignalService
{
public:
	SignalService();
	~SignalService();

protected:
	TbChannelDao m_channelParaDao;
	//TbProductDao m_productDao;
	TbSignalDao m_SignalDao;
	//TbSumsignalDao m_SumsignalDao;
	static HANDLE m_hMsqlMutex;
public:
	/**********************************************************************
	�������������ݲ�ѯ������ѯ���еĲɼ�����
	�� �� ֵ��Result����
	����˵������ѯ�ɼ�����
	***********************************************************************/
	bool GetAllSignalBySearchCondition(TbSignal searchEntity, vector<TbSignal> &sumsignalVector);

	/**********************************************************************
	���������������ź�����
	�����������װ�õ�signal������Ҫ������źŶ���
	***********************************************************************/
	//bool AddSignalData(map<CString, ThreadSafeQueue<double>> & acquireSignal, TbSignal &saveSumsignal);

	/**********************************************************************
	���������������ź�����
	�����������װ�õ�signal������Ҫ������źŶ���
	***********************************************************************/
	bool AddSignal(TbSignal saveSignal);

};

