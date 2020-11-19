#include "stdafx.h"
#include "TbSumsignalLabel.h"
TbSumsignalLabel::TbSumsignalLabel(int label)
{
	m_label = label;
}
TbSumsignalLabel::TbSumsignalLabel(int id, CString sumsignalId,  CString startTime, CString endTime)
{
	SetId(id);
	SetSumsignalId(sumsignalId);
	//SetLabel(label);
	SetStartTime(startTime);
	SetEndTime(endTime);
}
TbSumsignalLabel::~TbSumsignalLabel()
{

}
int TbSumsignalLabel::GetId()
{
	return m_id;
}
void TbSumsignalLabel::SetId(int id)
{
	this->m_id = id;
}

CString TbSumsignalLabel::GetSumsignalId()
{
	return this->m_sumsignalId;
}
void TbSumsignalLabel::SetSumsignalId(CString sumsignal)
{
	this->m_sumsignalId = sumsignal;
}

//TbLabel & TbSumsignalLabel::GetLabel()
//{
//	return this->m_label;
//}
//void TbSumsignalLabel::SetLabel(TbLabel label)
//{
//	this->m_label = label;
//}



int TbSumsignalLabel::GetLabel()
{
	return  m_label;
}
void TbSumsignalLabel::SetLabel(int label)
{
	this->m_label = label;
}

CString TbSumsignalLabel::GetStartTime()
{
	return m_startTime;
}
void TbSumsignalLabel::SetStartTime(CString startTime)
{
	this->m_startTime = startTime;
}

CString TbSumsignalLabel::GetEndTime()
{
	return m_endTime;
}
void TbSumsignalLabel::SetEndTime(CString endTime)
{
	this->m_endTime = endTime;
}