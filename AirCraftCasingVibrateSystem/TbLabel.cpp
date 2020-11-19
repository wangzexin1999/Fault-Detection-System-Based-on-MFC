#include "stdafx.h"
#include "TbLabel.h"
TbLabel::TbLabel()
{

}
TbLabel::TbLabel(int labelId, CString labelName, CString mark)
{
	SetLabelId(labelId);
	SetLabelName(labelName);
	SetMark(mark);
}
TbLabel::~TbLabel()
{

}
int TbLabel::GetLabelId()
{
	return  m_labelId;
}
void TbLabel::SetLabelId(int labelId)
{
	this->m_labelId = labelId;
}

CString TbLabel::GetLabelName()
{
	return m_labelName;
}
void TbLabel::SetLabelName(CString labelName)
{
	this->m_labelName = labelName;
}

CString TbLabel::GetMark()
{
	return m_mark;
}
void TbLabel::SetMark(CString mark)
{
	this->m_mark = mark;
}