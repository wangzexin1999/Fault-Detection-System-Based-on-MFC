#ifndef _REDIS_H_
#define _REDIS_H_

#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>

#include "hiredis.h"

class Redis
{
public:

	Redis(){}
	~Redis()
	{
		this->connect = NULL;
		this->reply = NULL;
	}

	/*连接redis*/
	bool Connect(std::string strHost, int nPort)
	{
		//使用2.1版本的Socket
		WSADATA wsaData;
		WSAStartup(MAKEWORD(2, 1), &wsaData); 
		// 连接
		this->connect = redisConnect(strHost.c_str(), nPort);
		if (this->connect != NULL && this->connect->err)
		{
			AfxMessageBox("redis connect error\n");
			return false;
		}
		return true;
	}

	/*得到值*/
	std::string GetValue(std::string strKey)
	{
		this->reply = (redisReply*)redisCommand(this->connect, "GET %s", strKey.c_str());
		std::string str = this->reply->str;
		freeReplyObject(this->reply);
		return str;
	}

	/*使得值*/
	void SetValue(std::string strKey, std::string strValue)
	{
		redisCommand(this->connect, "SET %s %s", strKey.c_str(), strValue.c_str());
	}

private:

	redisContext* connect;
	redisReply* reply;

};

#endif  //_REDIS_H_