#pragma once
/************************************************************************
�ļ����ƣ� SignalService.h
����ժҪ�� �ź���ص�ҵ���߼�.��Ӧ��ʵ�����ļ�ΪSignalService.cpp��
************************************************************************/

#include "TbSumsignal.h"
#include "TbSignalDao.h"
#include "TbSignal.h"
#include "TbSumsignal.h"
#include "TbChannel.h"
#include "TbChannelDao.h"
#include "CommonUtil.h"
#include "TbSumsignalDao.h"
#include "TbProductDao.h"
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
	TbProductDao m_productDao;
	
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
	bool SaveSignal(TbSignal saveSignal);

	bool saveSumSignal(TbSumsignal sumSignal);

	bool updateSumSignal(TbSumsignal sumSignal);

	/**********************************************************************
	�������������ݲ�Ʒ��Ż�ȡ���ź�
	���������productId--�ļ�·��
	��������� sumSignalVec--���źż���
	�� �� ֵ�� ture--�ɹ��� false--���ļ�ʧ��
	***********************************************************************/
	bool GetSumSignalByProductId(int productId, vector<TbSumsignal> &sumSignalVec);

	/**********************************************************************
	���������� �õ�ָ��SumSignalId�������źš�
	���������sumSignalId--���źű�ţ�signals--�źż���
	***********************************************************************/
	bool GetSignalsBySumSignalId(CString sumSignalId, vector<TbSignal> &signals);

	/**********************************************************************
	�������������ݲ�ѯ������ѯ���еļ�¼����
	��������� ��Ŀ���� ����Ʒ���ƣ�ת�٣��źŲɼ�ʱ�䣬�ź�
	�ɼ�ʱ�䣺�źŵļ��ϡ�
	�� �� ֵ��Result����
	����˵������ѯ���������ļ�����Ҫ��Բ�Ʒ���ͺź�ת�ٽ��в�ѯ
	***********************************************************************/
	bool FindAllSumSignalBySearchCondition(TbSumsignal searchEntity, vector<TbSumsignal> &signalVector);
};

