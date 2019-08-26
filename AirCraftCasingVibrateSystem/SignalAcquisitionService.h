#pragma once
#include "AcquiredSignal.h"
#include "ThreadSafeQueue.h"
#include "EchoSignal.h"

class SignalAcquisitionService
{

private:

	ThreadSafeQueue<AcquiredSignal> m_sampleData; ///��������
	ThreadSafeQueue<AcquiredSignal> m_collectData; ///�ɼ�����
	ThreadSafeQueue<EchoSignal> m_echoData; ///��������
	EchoSignal m_signal; ///��Ҫ���Ե�����


public:
	double m_readFromCSVFile[100][1000];//�ļ��Ĳ����������飬������

	SignalAcquisitionService();
	~SignalAcquisitionService();

	/**********************************************************************
	���������� ��ȡ����
	���������
	���������
	�� �� ֵ�� -1---���ʧ��  0---��óɹ�
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	int ReadData();

	/**********************************************************************
	���������� �õ��ɼ����ݶ���
	���������
	���������
	�� �� ֵ�� -1---���ʧ��  0---��óɹ�
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	ThreadSafeQueue<AcquiredSignal> & GetCollectData();

	/**********************************************************************
	���������� �õ���������
	���������
	���������
	�� �� ֵ�� -1---���ʧ��  0---��óɹ�
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	ThreadSafeQueue<EchoSignal> & GetEchoData();
	/**********************************************************************
	���������� �õ��ɼ����ݵĸ���
	���������
	���������
	�� �� ֵ�� -1---���ʧ��  0---��óɹ�
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	int GetCollectDataSize();

};
