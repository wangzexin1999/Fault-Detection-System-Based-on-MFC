#pragma once
#include <vector>
#include <atlstr.h>
class TbLabel
{
public:
	TbLabel();
	TbLabel(int labelId, CString labelName, CString mark);
	~TbLabel();
private:
	int m_labelId;
	CString m_labelName;
	CString m_mark;

public:
	int GetLabelId();
	void SetLabelId(int labelId);

	CString GetLabelName();
	void SetLabelName(CString labelName);

	CString GetMark();
	void SetMark(CString mark);
};