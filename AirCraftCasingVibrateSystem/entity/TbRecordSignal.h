/************************************************************************
文件名称： FileController.h
内容摘要： 记录实体类对象。对应的实现类文件为TbRecordSignal.cpp。
************************************************************************/
#pragma once
#include "TbCollectionparas.h"
#include "TbProduct.h"
#include "TbCollectionparas.h"
#include "TbProject.h"
#include <vector>
using namespace std;

class TbRecordSignal
{
public:

	TbRecordSignal(CString signalId, CString startTime, CString endTime, CString signalType, char SignalLabel, TbProject project, TbProduct product, TbCollectionparas collectionparas, CString collectionStatus, CString channelInfo);
	TbRecordSignal();
	~TbRecordSignal();

private:
	int m_id;
	CString m_signalId;
	CString m_startTime;
	CString m_endTime;
	long long m_startPos;
	long long m_endPos;
	CString m_signalType;
	TbProduct m_product;
	char m_SignalLabel;
	TbProject m_project;
	TbCollectionparas m_collectionparas;
	CString m_collectionStatus;
	CString m_channelInfo;

public:
	int GetId();
	void SetId(int id);
	CString GetSignalId();
	void SetSignalId(CString signalId);
	CString GetStartTime();
	void SetStartTime(CString startTime);
	CString GetEndTime();
	void SetEndTime(CString endTime);
	CString GetSignalType();

	long long   GetStartPos();
	void SetStartPos(long long startPos);

	long long  GetEndPos();
	void SetEndPos(long long endPos);


	void SetSignalType(CString signalType);
	TbProduct & GetProduct();
	void SetProduct(TbProduct product);
	char GetSignalLabel();
	void SetSignalLabel(char signal_status);
	void SetProject(TbProject project);
	TbProject & GetProject();
	TbCollectionparas & GetCollectionparas();
	void SetCollectionparas(TbCollectionparas  collectionparas);
	void SetCollectionStatus(CString collectionStatus);
	CString GetCollectionStatus();
	void SetChannelInfo(CString channelInfo);
	CString GetChannelInfo();
};

