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
#include <fstream>
#include <map>
using namespace std;




class SignalController
{

private:
	SignalService m_SignalService;
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
	//void SaveCollectionDataHeadInfo(CString fileName, SignalInfoHeader  signalInfoHeader);

	/**********************************************************************
	������������òɼ����ݵĶ������ļ�ͷ����Ϣ
	���������fileName--�ļ�·��
	��������� signalInfoHeader--ͷ��Ϣ
	�� �� ֵ�� ture--�ɹ��� false--���ļ�ʧ��
	***********************************************************************/
	//bool GetCollectionDataHeadInfo(CString fileName, SignalInfoHeader& signalInfoHeader);



	//bool SaveCollectionData2BinaryNEW(vector<ofstream>&voutputStream, map<CString, ThreadSafeQueue<double>> & acquireSignal);

};

