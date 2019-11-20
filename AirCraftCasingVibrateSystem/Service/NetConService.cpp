#include "stdafx.h"
#include "NetConService.h"
#include <stdlib.h>

CNetConService::CNetConService()
{
}


CNetConService::~CNetConService()
{
}



int CNetConService::openConnect(CString IP, int port)
{

	WORD wVersionRequested;
	WSADATA wsaData;
	int temp;
	int err;

	wVersionRequested = MAKEWORD(1, 1);

	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) {
		temp = -1;
	}

	if (LOBYTE(wsaData.wVersion) != 1 ||
		HIBYTE(wsaData.wVersion) != 1) {
		WSACleanup();
		temp = -1;
	}
	sockClient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	SOCKADDR_IN addrSrv;
	//addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	addrSrv.sin_addr.S_un.S_addr = inet_addr(IP);
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(port); 
	if (connect(sockClient, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR)) == SOCKET_ERROR)
	{
		return false;
	}
	else
	{
		return true;
	}
}


int CNetConService::sendData(CString CSbuffer)
{
	/*char* baseCh = { "1123132" };
	CString temp22;
	int num = rand() % 20000;
	for (int clc = 0; clc < 5; clc++)
	{

		temp22.Format("%d", num);*/
		send(sockClient, CSbuffer, strlen(CSbuffer) + 1, 0);
		/*char recvBuf[50];
		recv(sockClient, recvBuf, 50, 0);
		printf("severRecv %s\n", recvBuf);
		char t[2];
	}*/
	return 0;

}

int CNetConService::closeScoket()
{
	closesocket(sockClient);
	WSACleanup();
	return 0;
}