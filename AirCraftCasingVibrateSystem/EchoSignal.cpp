#include "stdafx.h"
#include "EchoSignal.h"


EchoSignal::EchoSignal()
{
}


EchoSignal::~EchoSignal()
{
}
EchoSignal::EchoSignal(SmartArray<double> xData, SmartArray<double> yData){
	SetXData(xData);
	SetYData(yData);
}

SmartArray<double> & EchoSignal::GetXData(){
	return m_x;
}
SmartArray<double> & EchoSignal::GetYData(){
	return m_y;
}

void EchoSignal::SetXData(SmartArray<double> x){
	m_x = x;
}
void EchoSignal::SetYData(SmartArray<double> y){
	m_y = y;
}