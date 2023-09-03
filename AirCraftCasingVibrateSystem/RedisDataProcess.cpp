#include "stdafx.h"
#include "RedisDataProcess.h"



RedisDataProcess::RedisDataProcess()
{
	

}


RedisDataProcess::~RedisDataProcess()
{
	this->connect = NULL;
	this->reply = NULL;
}

redisContext* RedisDataProcess::connectRedis()
{
	//redisĬ�ϼ����˿�Ϊ6379 �����������ļ����޸�
	redisContext* c = redisConnect("127.0.0.1", 6379);
	if (c->err)
	{
		redisFree(c);
		printf("Connect to redisServer faile\n");
		//ǿ���˳�
		MessageBox(NULL, TEXT("redis����ʧ�ܣ�����˼����˳�����������redis!"), TEXT("��ʾ"), MB_ICONWARNING);
		exit(0);
		return NULL;
	}
	//printf("Connect to redisServer Success\n");
	MessageBox(NULL, TEXT("Connect to redisServer Success"), TEXT("��ʾ"), MB_ICONWARNING);
	//TRACE("Connect to redisServer Success\n");
	return c;
}

redisContext* RedisDataProcess::connectToRedis()
{
	//redisĬ�ϼ����˿�Ϊ6379 �����������ļ����޸�
	redisContext *connect = redisConnect("127.0.0.1", 6379);//222.27.192.75 127.0.0.1
	if (connect->err)
	{
		redisFree(connect);
		printf("Connect to redisServer faile\n");
		//ǿ���˳�
		MessageBox(NULL, TEXT("redis����ʧ�ܣ�����˼����˳�����������redis!"), TEXT("��ʾ"), MB_ICONWARNING);
		exit(0);
		return NULL;
	}
	//printf("Connect to redisServer Success\n");
	MessageBox(NULL, TEXT("Connect to redisServer Success"), TEXT("��ʾ"), MB_ICONWARNING);
	//TRACE("Connect to redisServer Success\n");
	return connect;
}

//��������redis
void RedisDataProcess::testConnectRedis()
{
	connectRedis();
}



//����key����������
boolean RedisDataProcess::setExpire(string key, int expire, redisContext* context)
{
	redisContext* c = context;
	if (c == nullptr)
	{
		c = connectRedis();
	}
	if (c == NULL)
	{
		return false;
	}
	char buf[10] = "";
	itoa(expire, buf, 10);
	string command = "expire " + key + " " + buf;
	redisReply* r = (redisReply*)redisCommand(c, command.c_str());
	if (r->type = REDIS_REPLY_INTEGER&&r->integer == 1)
	{
		return true;
	}
	return false;
}

//����key����������
boolean RedisDataProcess::setExpire(string key, int expire)
{
	return setExpire(key, expire, nullptr);
}

//����key��ֵ�Լ���������
boolean RedisDataProcess::setCacheValue(string key, string value, int expire)
{
	redisContext* c = connectRedis();
	if (c == NULL)
	{
		return false;
	}

	//const char* command1 = "set stest1 value1";
	string command = "set " + key + " " + value;
	redisReply* r = (redisReply*)redisCommand(c, command.c_str());

	if (NULL == r)
	{
		printf("Execut command1 failure\n");
		redisFree(c);
		return false;
	}
	if (!(r->type == REDIS_REPLY_STATUS && strcasecmp(r->str, "OK") == 0))
	{
		printf("Failed to execute command[%s]\n", command.c_str());
		freeReplyObject(r);
		redisFree(c);
		return false;
	}
	//������������
	if (expire != NULL)
	{
		if (!setExpire(key, expire, c))
		{
			freeReplyObject(r);
			redisFree(c);
			return false;
		}
	}
	freeReplyObject(r);
	redisFree(c);
	printf("Succeed to execute command[%s]\n", command.c_str());
	return true;
}

//����key��ֵ
boolean RedisDataProcess::setCacheValue(string key, string value)
{
	return setCacheValue(key, value, NULL);
}

//��ȡkey��ֵ
string RedisDataProcess::getCacheValue(string key)
{
	redisContext* c = connectRedis();
	if (c == NULL)
	{
		return "";
	}

	string command = "get " + key;
	//const char* command3 = "get stest1";
	redisReply* r = (redisReply*)redisCommand(c, command.c_str());
	//�ж��Ƿ�û��ѯ��
	if (r->type == REDIS_REPLY_NIL)
	{
		printf("Failed to execute command[%s]\n", command.c_str());
		freeReplyObject(r);
		redisFree(c);
		return "";
	}
	//�жϷ��ص��Ƿ����ַ�������
	if (r->type != REDIS_REPLY_STRING)
	{
		printf("Failed to execute command[%s]\n", command.c_str());
		freeReplyObject(r);
		redisFree(c);
		return "";
	}
	printf("The value of 'stest1' is %s\n", r->str);

	string value = r->str;
	freeReplyObject(r);
	redisFree(c);
	printf("Succeed to execute command[%s]\n", command.c_str());
	return value;
}

//��ȡkey��ֵ�ĳ���
int RedisDataProcess::getCacheValueLength(string key)
{
	redisContext* c = connectRedis();
	if (c == NULL)
	{
		return -1;
	}
	string command = "strlen " + key;
	//const char* command2 = "strlen stest1";
	redisReply* r = (redisReply*)redisCommand(c, command.c_str());
	//�жϷ��ص��Ƿ�������
	if (r->type != REDIS_REPLY_INTEGER)
	{
		printf("Failed to execute command[%s]\n", command.c_str());
		freeReplyObject(r);
		redisFree(c);
		return -1;
	}
	int length = r->integer;
	freeReplyObject(r);
	redisFree(c);
	printf("The length of 'stest1' is %d.\n", length);
	printf("Succeed to execute command[%s]\n", command.c_str());
	return length;
}

//����Ϊ��λ����key��ʣ��ʱ��
int RedisDataProcess::getCacheValueTLL(string key)
{
	redisContext* c = connectRedis();
	if (c == NULL)
	{
		return -1;
	}
	string command = "ttl " + key;
	redisReply* r = (redisReply*)redisCommand(c, command.c_str());
	//�жϷ��ص��Ƿ�������
	if (r->type != REDIS_REPLY_INTEGER)
	{
		printf("Failed to execute command[%s]\n", command.c_str());
		freeReplyObject(r);
		redisFree(c);
		return -1;
	}
	int ttl = r->integer;
	freeReplyObject(r);
	redisFree(c);
	printf("The ttl of 'stest1' is %d.\n", ttl);
	printf("Succeed to execute command[%s]\n", command.c_str());
	return ttl;
}

void RedisDataProcess::RedisTest(){

	unsigned int j;
	redisContext *c;
	redisReply *reply;

	struct timeval timeout = { 1, 500000 }; // 1.5 seconds
	c = redisConnectWithTimeout((char*)"127.0.0.1", 6379, timeout);
	if (c->err) {
		printf("Connection error: %s\n", c->errstr);
		exit(1);
	}
	//MessageBox(NULL, TEXT("Connect to redisServer Success1111"), TEXT("��ʾ"), MB_ICONWARNING);
	/* PING server */
	reply = (redisReply *)redisCommand(c, "PING");
	//printf("PING: %s\n", reply->str);
	TRACE("PING: %s\n", reply->str);
	freeReplyObject(reply);

	/* Set a key */
	reply = (redisReply *)redisCommand(c, "SET %s %s", "foo", "hello world 2022");
	//printf("SET: %s\n", reply->str);
	TRACE("SET: %s\n", reply->str);
	freeReplyObject(reply);

	/* Set a key using binary safe API */
	reply = (redisReply *)redisCommand(c, "SET %b %b", "bar", 3, "hello", 5);
	printf("SET (binary API): %s\n", reply->str);
	TRACE("SET (binary API): %s\n", reply->str);
	freeReplyObject(reply);

	/* Try a GET and two INCR */
	reply = (redisReply *)redisCommand(c, "GET foo");
	printf("GET foo: %s\n", reply->str);
	TRACE("GET foo: %s\n", reply->str);
	freeReplyObject(reply);

	reply = (redisReply *)redisCommand(c, "INCR counter");
	printf("INCR counter: %lld\n", reply->integer);
	TRACE("INCR counter: %lld\n", reply->integer);
	freeReplyObject(reply);
	/* again ... */
	reply = (redisReply *)redisCommand(c, "INCR counter");
	printf("INCR counter: %lld\n", reply->integer);
	TRACE("INCR counter: %lld\n", reply->integer);
	freeReplyObject(reply);

	/* Create a list of numbers, from 0 to 9 */
	reply = (redisReply *)redisCommand(c, "DEL mylist");
	freeReplyObject(reply);
	for (j = 0; j < 10; j++) {
		char buf[64];

		sprintf_s(buf, 64, "%d", j);
		reply = (redisReply *)redisCommand(c, "LPUSH mylist element-%s", buf);
		freeReplyObject(reply);
	}

	/* Let's check what we have inside the list */
	reply = (redisReply *)redisCommand(c, "LRANGE mylist 0 -1");
	if (reply->type == REDIS_REPLY_ARRAY) {
		for (j = 0; j < reply->elements; j++) {
			printf("%u) %s\n", j, reply->element[j]->str);
			getchar();
		}
	}
	freeReplyObject(reply);
	

}
void RedisDataProcess::RedisTest2(){





}


void RedisDataProcess::setContext(redisContext* con){
	this->connect = con;
}

void RedisDataProcess::setReply(redisReply* rep){
	this->reply = rep;
}

redisContext* RedisDataProcess::getContext(){
	return this->connect;
}

redisReply* RedisDataProcess::getReply(){
	return this->reply;
}
    

void RedisDataProcess::redisSetCollectionData(std::string listName, float data){
	
	
	//this->reply = (redisReply *)redisCommand(this->connect, "LPUSH %s %f", listName.c_str(), data);
	char buf[64];

	sprintf_s(buf, 64, "%f", data);
	this->reply = (redisReply *)redisCommand(this->connect, "LPUSH mylist element-%s", buf);
	freeReplyObject(this->reply);
}

void RedisDataProcess::redisGetCollectionData(std::string listName){
	this->reply = (redisReply*)redisCommand(this->connect, "LRANGE %s 0 -1", listName.c_str());
	if (reply->type == REDIS_REPLY_ARRAY) {
		for (int j = 0; j < reply->elements; j++) {
			TRACE("%u)------------ %s\n", j, reply->element[j]->str);
		}
	}
	std::string str = this->reply->str;
	freeReplyObject(this->reply);

}