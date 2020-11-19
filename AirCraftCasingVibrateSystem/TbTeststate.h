#pragma once
#include"TbProductType.h"
#include <vector>
#include <atlstr.h>
using namespace std;
class TbTeststate
{
public:
	TbTeststate();
	TbTeststate(int stateId, CString stateName, double speed, double acceleration, TbProductType productType);
	~TbTeststate();
private:
	int m_stateId;
	CString  m_stateName;
	double  m_speed;
	double  m_acceleration;
	TbProductType m_productType;
public:
	int GetStateId();
	void SetStateId(int stateId);

	CString GetStateName();
	void SetStateName(CString stateName);

	double GetSpeed();
	void SetSpeed(double speed);

	double GetAcceleration();
	void SetAcceleration(double acceleration);

	TbProductType & GetProductType();
	void SetProductType(TbProductType productType);
};