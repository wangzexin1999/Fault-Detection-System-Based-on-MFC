#pragma once

#include "Result.h"
#include "TbSignal.h"
#include "SignalService.h"
#include "ProjectService.h"
#include "ProductService.h"
#include "TbRecordSignal.h"
#include "RecordSignalService.h"
#include "ThreadSafeQueue.h"
#include "AcquiredSignal.h"
#include "TbSumsignal.h"
#include <fstream>
#include <map>
using namespace std;

struct SignalFileHeader{
	/*�ź�ID*/
	char m_signalId[50];
	/*ͨ��Id*/
	int m_iChannelId;
	/*ͨ��Code*/
	char m_cChannelCode[10];
	/*����Ƶ��*/
	int m_iSampleFre = 0;
	/*������ID*/
	int m_isensorId = 0;
	/*��������*/
	char m_cmessureType[20];
	/*��������*/
	int m_ifullvalue;
	/*����Ƶ��*/
	char m_cupFreq[20];
	/*���뷽ʽ*/
	char m_cinputMode[20];
	/*������*/
	float m_fsensitivity;
	/*��ѹ������Χ*/
	int m_ielcpressure; 
};

//struct SignalInfoHeader{
//
//	/*ͨ������*/
//	char m_cChannelCode[20];
//
//	/*����豸��ip*/
//	char m_cMachineIp[20];
//
//	/*ͨ������*/
//	char m_cChannelCode[20];
//
//	/*�ź�ID*/
//	int m_iSignalId = 0;
//
//	/*�ɼ�Ƶ��*/
//	int m_iCollectFre = 0;
//	/*�ɼ��ƻ�����*/
//	char  m_cCollectPlanPara[500];
//	/*�źŴ�С*/
//	long long m_llSiganlSize = 0;
//};

class SignalController
{

private:
	SignalService m_signalService;
	ProjectService m_projectService;
	RecordSignalService m_recordSignalService;
	ProductService m_productService;


public:
	SignalController();
	~SignalController();

	/**********************************************************************
	�������������ݲ�ѯ������ѯ���еļ�¼����
	��������� ��Ŀ���� ����Ʒ���ƣ�ת�٣��źŲɼ�ʱ�䣬�ź�
	�ɼ�ʱ�䣺�źŵļ��ϡ�
	�� �� ֵ��Result����
	����˵������ѯ���������ļ�����Ҫ��Բ�Ʒ���ͺź�ת�ٽ��в�ѯ
	***********************************************************************/
	Result FindAllRecordSignalBySearchCondition(TbRecordSignal searchEntity, vector<TbRecordSignal> &signalVector);

	/**********************************************************************
	�����������������������
	�����������ǰ���ڵ�id����������id
	***********************************************************************/
	Result SaveSampleSignal(TbRecordSignal m_recordSignal);

	/**********************************************************************
	��������������ɼ�������
	�����������ǰ���ڵ�id����������id
	***********************************************************************/
	Result SaveCollectionSignal(TbSignal m_collectionSignal);


	/**********************************************************************
	�������������ݲ�ѯ������ѯ���еĲɼ�����
	�� �� ֵ��Result����
	����˵������ѯ�ɼ�����
	***********************************************************************/
	Result FindAllSignalBySearchCondition(TbSignal searchEntity, vector<TbSignal> &sumsignalVector);

	/**********************************************************************
	��������������ɼ�������
	�����������ǰ���ڵ�id����������id
	***********************************************************************/
	Result SaveSignalData(map<CString, ThreadSafeQueue<double>> & acquireSignal, TbSignal &savesumsignal);

	/**********************************************************************
	���������� �����������Ϊ�������ļ�
	���������outputStream--�������acquireSigna--�ɼ��ź�
	***********************************************************************/
	//bool SaveCollectionData2Binary(ofstream &outputStream, map<CString, ThreadSafeQueue<double>> & acquireSigna);

	/**********************************************************************
	���������� �õ��ɼ�����
	���������inputStream--��������
	llStart--��ʼλ�ã�Ĭ���Ǵ�ͷ��ʼ��llend--����λ�ã�Ĭ�����ļ���β
	���������vSignal--�źţ�
	�� �� ֵ�� true--������false--������
	***********************************************************************/
	bool GetCollectionData(ifstream &inputStream, long long llfileSize, long long llStart, long long llReadSize, vector<double>& vSumsignal);

	/**********************************************************************
	���������� ����������ݵĶ������ļ�ͷ����Ϣ
	���������outputStream--�������signalInfoHeader--�ɼ��ź���Ϣͷ
	***********************************************************************/
	void SaveSignalFileHeader(CString fileName, SignalFileHeader  signalInfoHeader);

	/**********************************************************************
	������������òɼ����ݵĶ������ļ�ͷ����Ϣ
	���������fileName--�ļ�·��
	��������� signalInfoHeader--ͷ��Ϣ
	�� �� ֵ�� ture--�ɹ��� false--���ļ�ʧ��
	***********************************************************************/
	//bool GetCollectionDataHeadInfo(CString fileName, SignalInfoHeader& signalInfoHeader);


	Result saveSumSignal(TbSumsignal sumSignal);

	Result saveSignal( TbSignal sumSignal);

	Result updateSumSignal(TbSumsignal sumSignal);

	/**********************************************************************
	���������� �����������Ϊ�������ļ�
	���������outputStream--�������acquireSigna--�ɼ��ź�
	***********************************************************************/
	Result SaveCollectionData2Binary(ofstream &outputStream, ThreadSafeQueue<double> & acquireSignal);
};

