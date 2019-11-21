#pragma once

#include <stdio.h>  
#include <Winsock2.h>  
#pragma comment(lib,"ws2_32.lib")


class CNetConService
{
public:
	CNetConService();
	~CNetConService();




public:
	SOCKET sockClient;
	int openConnect(CString IP = _T("127.0.0.1"), int port = 9999);
	int sendData(CString CSbuffer);
	int closeScoket();
};

