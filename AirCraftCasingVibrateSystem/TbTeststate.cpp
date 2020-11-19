#include "stdafx.h"
#include "TbTeststate.h"
TbTeststate::TbTeststate()
{

}
TbTeststate::TbTeststate(int stateId, CString stateName, double speed, double acceleration, TbProductType productType)
{
	SetStateId(stateId);
	SetStateName(stateName);
	SetSpeed(speed);
	SetAcceleration(acceleration);
	SetProductType(productType);

}
TbTeststate::~TbTeststate()
{

}
int TbTeststate::GetStateId()
{
	return m_stateId;
}
void TbTeststate::SetStateId(int stateId)
{
	this->m_stateId = stateId;
}

CString TbTeststate::GetStateName()
{
	return m_stateName;
}
void TbTeststate::SetStateName(CString stateName)
{
	this->m_stateName = stateName;
}

double TbTeststate::GetSpeed()
{
	return m_speed;
}
void TbTeststate::SetSpeed(double speed)
{
	this->m_speed = speed;
}

double TbTeststate::GetAcceleration()
{
	return m_acceleration;
}
void TbTeststate::SetAcceleration(double acceleration)
{
	this->m_acceleration = acceleration;
}

TbProductType & TbTeststate::GetProductType()
{
	return this->m_productType;
}
void TbTeststate::SetProductType(TbProductType productType)
{
	this->m_productType = productType;
}