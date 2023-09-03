#include "stdafx.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <stddef.h> 
#include <stdarg.h> 
#include <string> 
#include <assert.h> 
//#include <hiredis.h> 
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/hiredis.h"
#define NO_QFORKIMPL //这一行必须加才能正常使用

#pragma comment(lib, "Win32_Interop.lib")
#pragma comment(lib, "hiredis.lib")
#pragma once

using namespace std;

#define strcasecmp _stricmp

class RedisDataProcess
{
public:

	//函数声明
	redisContext* connectRedis();
	redisContext* connectToRedis();
	void testConnectRedis();
	boolean setExpire(string key, int expire);
	boolean setExpire(string key, int expire, redisContext* context);
	boolean setCacheValue(string key, string value);
	boolean setCacheValue(string key, string value, int expire);
	string getCacheValue(string key);
	int getCacheValueLength(string key);
	RedisDataProcess();
	~RedisDataProcess();
	int getCacheValueTLL(string key);
	void RedisTest();
	void RedisTest2();

	void redisSetCollectionData(std::string listName, float data);
	void redisGetCollectionData(std::string listName);

	void setContext(redisContext* con);
	void setReply(redisReply* reply);
	redisContext* getContext();
	redisReply* getReply();

private:
	redisContext* connect;
	redisReply* reply;
	
};

