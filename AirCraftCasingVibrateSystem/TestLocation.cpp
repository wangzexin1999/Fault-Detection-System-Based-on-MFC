#include "stdafx.h"
#include "TestLocation.h"


TestLocation::TestLocation()
{
}

TestLocation::~TestLocation()
{
}


int m_locationId;
CString m_locationName;
int m_productTypeId;

int TestLocation::GetLocationId(){
	return m_locationId;
}
void TestLocation::SetLocationId(int locationId){
	m_locationId = locationId;
}

CString TestLocation::GetLocationName(){
	return m_locationName;
}
void TestLocation::SetLocationName(CString locationName){
	m_locationName = locationName;
}

void TestLocation::SetProductTypeId(int productTypeId){
	m_productTypeId = productTypeId;
}
int TestLocation::GetProductTypeId(){
	return m_productTypeId;
}
