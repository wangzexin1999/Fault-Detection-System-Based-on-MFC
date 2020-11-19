#pragma once
#include"TbSumsignal.h"
#include"TbLabel.h"
#include <vector>
#include <atlstr.h>
using namespace std;
class TbSumsignalLabel
{
public:
	TbSumsignalLabel(int label=1);
	TbSumsignalLabel(int id, CString sumsignalId, CString startTime, CString endTime);
	~TbSumsignalLabel();

private:
	int m_id;
	CString m_sumsignalId;
	//TbLabel m_label;
	int m_label;
	CString m_startTime;
	CString m_endTime;
public:
	int GetId();
	void SetId(int id);

	CString  GetSumsignalId();
	void SetSumsignalId(CString sumsignal);

	//TbLabel & GetLabel();
	//void SetLabel(TbLabel label);
	int GetLabel();
	void SetLabel(int label);

	CString GetStartTime();
	void SetStartTime(CString startTime);

	CString GetEndTime();
	void SetEndTime(CString endTime);
};
