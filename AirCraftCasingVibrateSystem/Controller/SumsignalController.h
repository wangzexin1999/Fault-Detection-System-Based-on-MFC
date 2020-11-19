#pragma once

#include "Result.h"
#include "TbSumsignal.h"
#include "SumsignalService.h"
#include "ProjectService.h"
#include "ProductService.h"
#include "TbRecordSignal.h"
#include "RecordSignalService.h"
#include "ThreadSafeQueue.h"
#include "AcquiredSignal.h"
#include <fstream>
#include <map>
using namespace std;
struct SignalInfoHeader{
	/*ͨ������*/
	int m_iChannelNums = 0;
	/*��ʼͨ��*/
	char m_cStartChannel[4];
	/*����ͨ��*/
	char m_cEndChannel[4];
	/*�ɼ�Ƶ��*/
	int m_iCollectFre = 0;
	/*�ɼ��ƻ�����*/
	char  m_cCollectPlanPara[500];
	/*�źŴ�С*/
	long long m_llSiganlSize = 0;
};



class SumsignalController
{

private:
	SumsignalService m_SumsignalService;
	ProjectService m_projectService;
	RecordSignalService m_recordSignalService;
	ProductService m_productService;


public:
	SumsignalController();
	~SumsignalController();

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
	Result SaveCollectionSignal(TbSumsignal m_collectionSignal);


	/**********************************************************************
	�������������ݲ�ѯ������ѯ���еĲɼ�����
	�� �� ֵ��Result����
	����˵������ѯ�ɼ�����
	***********************************************************************/
	Result FindAllSignalBySearchCondition(TbSumsignal searchEntity, vector<TbSumsignal> &sumsignalVector);

	/**********************************************************************
	��������������ɼ�������
	�����������ǰ���ڵ�id����������id
	***********************************************************************/
	Result SaveSignalData(map<CString, ThreadSafeQueue<double>> & acquireSignal, TbSumsignal &savesumsignal);

	/**********************************************************************
	���������� �����������Ϊ�������ļ�
	���������outputStream--�������acquireSigna--�ɼ��ź�
	***********************************************************************/
	bool SaveCollectionData2Binary(ofstream &outputStream, map<CString, ThreadSafeQueue<double>> & acquireSigna);

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
	void SaveCollectionDataHeadInfo(CString fileName, SignalInfoHeader  signalInfoHeader);

	/**********************************************************************
	 ������������òɼ����ݵĶ������ļ�ͷ����Ϣ
	 ���������fileName--�ļ�·��
	 ��������� signalInfoHeader--ͷ��Ϣ
	 �� �� ֵ�� ture--�ɹ��� false--���ļ�ʧ��
	***********************************************************************/
	bool GetCollectionDataHeadInfo(CString fileName, SignalInfoHeader& signalInfoHeader);



	bool SaveCollectionData2BinaryNEW(vector<ofstream>&voutputStream, map<CString, ThreadSafeQueue<double>> & acquireSignal);

};

