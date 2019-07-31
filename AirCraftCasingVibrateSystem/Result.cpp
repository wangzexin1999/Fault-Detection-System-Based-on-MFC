#include "stdafx.h"
#include "Result.h"


Result::Result()
{

}
Result::Result(bool isSuccess, CString message)
{
	this->m_isSuccess = isSuccess;
	this->m_message = message;
}

bool Result::GetIsSuccess(){
	return this->m_isSuccess;
}
CString Result::GetMessages(){
	return this->m_message;
}
Result::~Result()
{

}
