#pragma once
#include "TbProduct.h"
#include "TbChannel.h"
#include "TbCollectionparas.h"
#include <vector>
#include "TbProject.h"
#include "TbSignal.h"

class TbSumsignal
{
public:
	TbSumsignal(CString sumsignalId = "");
	~TbSumsignal();

private:

	CString m_sumsignalId;
	CString m_startTime;
	CString m_endTime;
	CString m_sumsignalType;
	int m_productId;
	char m_sumSignalLabel;
	CString m_dataUrl;
	int  m_projectId;
	int m_collectionparasId;
	CString m_collectionStatus;
	CString m_channelInfo;
	std::vector<TbSignal> m_vsignals;
	TbProduct m_product;

public:
	CString GetSumsignalId();
	void SetSumsignalId(CString sumsignalId);

	CString GetStartTime();
	void SetStartTime(CString startTime);
	CString GetEndTime();
	void SetEndTime(CString endTime);

	CString GetSumsignalType();
	void SetSumsignalType(CString sumsignalType);
	int   GetProductId();
	void SetProductId(int productId);
	char GetSumSignalLabel();
	void SetSumSignalLabel(char sumSignalLabel);
	CString GetDataUrl();
	void SetDataUrl(CString data_url);
	void SetProjectId(int projectId);
	int   GetProjectId();
	void SetCollectionStatus(CString para);
	CString GetCollectionStatus();
	CString GetChannelInfo();
	void SetChannelInfo(CString channelinfo);

	vector<TbSignal> & GetAllSignal();

	TbProduct & GetProduct();
};

